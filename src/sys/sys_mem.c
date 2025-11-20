#include "common.h"

extern HeapBlock* sHeapHead;
extern HeapBlock* sHeapTail; // Heap end
extern s16 sHeapBlocksCount;
extern HeapBlock sMemBlock[];
extern s32 D_80182610;
extern s32 D_80182640;
extern u8 D_801604A8[];


#define HEAP_SIZE_ALIGN(size) ((u32) (size + 15) >> 4) + 1

void SysMem_MarkHeap(void* ptr);
void func_800BCCE4(void*); /* extern */

// Initialize the memory heap
void SysMem_HeapInit(void) {
    u32 mask;

    mask = osSetIntMask(OS_IM_NONE);
    sHeapHead = sMemBlock;
    sHeapHead->flags = FLAGS_FREE;
    sHeapHead->size = 0x1B4FF;
    sHeapHead->prev = sHeapHead;
    sHeapHead->next = &sMemBlock[sHeapHead->size];
    sHeapTail = sHeapHead->next;
    D_80182610 = 0;
    sHeapBlocksCount = 0;
    D_80182640 = 0;
    osSetIntMask(mask);
}

void* SysMem_HeapAlloc(s32 size) {
    HeapBlock* block;
    HeapBlock* blockPrev;
    HeapBlock* blockNext;
    u32 blockSize;
    char pad[0x4];

    blockSize = ((u32) (size + 15) >> 4) + 1; // Align size to 16
    for (block = sHeapHead; block != sHeapTail; block = block->next) {
        // If the block is not avaiable skip it
        if (block->flags & 1) {
            continue;
        }
        if ((u32) block->size >= blockSize) {
            blockNext = block->next;
            block->size = blockSize;
            block->next = &block[blockSize];
            block->flags |= FLAGS_USED;
            blockPrev = block;
            block = block->next;
            if (blockNext != block) {
                block->prev = blockPrev;
                block->next = blockNext;
                block->size = (u32) (blockNext - block);
                block->flags = FLAGS_FREE;
                blockNext = block->next;
                if (blockNext != sHeapTail) {
                    if (blockNext->flags & FLAGS_USED) {
                        blockNext->prev = block;
                    } else {
                        block->next = blockNext->next;
                        block->size += blockNext->size;
                        blockNext = block->next;
                        blockNext->prev = block;
                    }
                }
            }

            // Return pointer to user data (skip header)
            return blockPrev + 1;
        }
    }
    return NULL;
}

/*
 * @brief Allocate a block and marks it or locks it
 */
void* SysMem_HeapAllocMark(s32 size) {
    void* ptr;

    ptr = SysMem_HeapAlloc(size);

    if (ptr == NULL) {
        return ptr;
    }

    SysMem_MarkHeap(ptr);
    return ptr;
}

s32 SysMem_Free(void* ptr) {
    HeapBlock* block;
    HeapBlock* blockPrev;
    HeapBlock* blockNext;

    block = (HeapBlock*) ptr - 1;
    if (!(block->flags & FLAGS_USED)) {
        return -1;
    }

    block->flags &= ~FLAGS_USED;
    blockNext = block->next;
    if ((blockNext != sHeapTail) && !(blockNext->flags & FLAGS_USED)) {
        block->next = blockNext->next;
        block->size += blockNext->size;
        blockNext = block->next;
        blockNext->prev = block;
    }
    blockPrev = block->prev;
    if ((block != sHeapHead) && !(blockPrev->flags & 1)) {
        blockPrev->next = (void*) block->next;
        blockPrev->size += block->size;
        block = block->next;
        block->prev = blockPrev;
    }
    return 0;
}

s32 func_800BCB10(void* arg0) {
    func_800BCCE4(arg0);
    return SysMem_Free(arg0);
}

void func_800BCB54(void) {
    HeapBlock* sp1C;

    for (sp1C = sHeapHead; sp1C != sHeapTail; sp1C = sp1C->next) {
        if (!(sp1C->flags & 1)) {

        } else if (!(sp1C->flags & 2)) {
            SysMem_Free(sp1C + 1);
        }
    }
}

void func_800BCBF8(void) {
    HeapBlock* sp1C;

    for (sp1C = sHeapHead; sp1C != sHeapTail; sp1C = sp1C->next) {
        if (!(sp1C->flags & 1)) {

        } else {
            func_800BCCE4(sp1C);
            SysMem_Free(sp1C + 1);
        }
    }
}

void SysMem_MarkHeap(void* ptr) {
    HeapBlock* block;

    block = (HeapBlock*) ptr - 1;
    if (!(block->flags & FLAGS_USED)) {
        return;
    }
    block->flags |= FLAGS_LOCK;
}

void func_800BCCE4(void* arg0) {
    HeapBlock* sp4;

    sp4 = (HeapBlock*) arg0 - 1;
    if (!(sp4->flags & 1)) {
        return;
    }
    sp4->flags = (s32) (sp4->flags & ~2);
}

/**
 *  Tells us how much memory is unlocked on the heap 
 */
s32 SysMem_GetUnlockedSize(void) {
    s32 sp4;
    HeapBlock* sp0;

    sp4 = 0;
    sHeapBlocksCount = 0;
    for (sp0 = sHeapHead; sp0 != sHeapTail; sp0 = sp0->next) {
        if ((sp0->flags & FLAGS_USED) && !(sp0->flags & FLAGS_LOCK)) {
            sp4 += sp0->size;
            sHeapBlocksCount += 1;
        }
    }
    return sp4 * 0x10;
}

s32 SysMem_GetLockedSize(void) {
    s32 sp4;
    HeapBlock* sp0;

    sp4 = 0;
    sHeapBlocksCount = 0;

    for (sp0 = sHeapHead; sp0 != sHeapTail; sp0 = sp0->next) {
        if ((sp0->flags & 1) && (sp0->flags & 2)) {
            sp4 += sp0->size;
            sHeapBlocksCount += 1;
        }
    }
    return sp4 * 0x10;
}

s32 SysMem_GetFreeSpace(void) {
    s32 free_space = 0;
    HeapBlock* block;

    sHeapBlocksCount = 0; // reset count of free blocks

    for (block = sHeapHead; block != sHeapTail; block = block->next) {
        // If block is free
        if (((!block->flags) & 1)) {
            free_space += block->size;
            sHeapBlocksCount++;
        }
    }

    // Convert from 16-byte units to bytes
    return free_space * 0x10;
}

void func_800BCF78(HeapBlock** arg0, s32 arg1) {
    u32 sp4;

    arg1 = arg1 * 2 - 2;

    for (sp4 = 0; sp4 < arg1; sp4++) {
        arg0[sp4] = NULL;
    }
}

/*
 * @brief Copy a memory region into another by bytes
 *
 */
void SysMem_Copy8(void* dest, void* src, s32 size) {
    u8* memSource;
    u8* memDest;

    if (size == 0) {
        return;
    }

    memSource = src;
    memDest = dest;

    while (size > 0) {
        *memDest++ = *memSource++;
        size--;
    }
}

void SysMem_Copy16(void* dest, void* src, s32 size) {
    u16* memSource;
    u16* memDest;

    if (size == 0) {
        return;
    }

    memSource = src;
    memDest = dest;

    while (size > 0) {
        *memDest++ = *memSource++;
        size--;
    }
}

// Unused function
UNUSED void SysMem_Copy32(void* dest, void* src, s32 size) {
    s32* memSource;
    s32* memDest;

    if (size == 0) {
        return;
    }

    memSource = src;
    memDest = dest;

    while (size > 0) {
        *memDest++ = *memSource++;
        size--;
    }
}

void SysMem_Copy64(void* dest, void* src, s32 size) {
    u64* memSource;
    u64* memDest;

    if (size == 0) {
        return;
    }

    memSource = src;
    memDest = dest;

    while (size > 0) {
        *memDest++ = *memSource++;
        size--;
    }
}

s32 SysMem_Compare(u8* s1, u8* s2, s32 size) {
    u8* p2;
    u8* p1;

    p2 = s2;
    p1 = s1;

    while (size > 0) {
        if (*p1 != *p2) {
            break;
        }

        p1++;
        p2++;
        size--;
    }

    return size;
}

/*
 * @brief Convert a virtual address inside a segment into its corresponding
 * physical address using offset translation.
 *
 * The function uses the formula:
 *
 *     physical = segBase + (vAddr - vStart)
 *
 * Where:
 *   - segBase is the physical base of the segment,
 *   - vStart is the virtual base of the same segment,
 *   - vEnd is the virtual address to translate.
 *
 * @param segBase Physical base address of the segment.
 * @param vStart  Virtual start address of the segment.
 * @param vAddr   Virtual address to translate.
 *
 * @return Physical address corresponding to the given virtual address.
 */
s32 SysMem_GetPhysicalAddressFromVirtual(u32 segBase, s32 vStart, s32 vEnd) {
    return (u32) segBase + (vEnd - vStart);
}

s32 SysMem_DmaCopy(u32 src, void* dest, s32 size) {
    s32 sp34;
    s32 sp30;
    u32 sp2C;

    if (size == 0) {
        return -1;
    }
    osWritebackDCacheAll();
    if ((src >= 0x80000000U) && (src < 0x80400000U)) {
        SysMem_Copy8(dest, (void*) src, size);
        return 0;
    }
    if (src & 1) {
        return -1;
    }
    if (src >= 0x80400000U) {
        return -1;
    }
    if (((u32) dest < 0x80000000U) || ((u32) dest >= 0x80400000U)) {
        return -1;
    }
    if (D_80182640 & 1) {
        if (!(D_80182640 & 2)) {
            sp2C = osSetIntMask(1U);
        }
        if ((((u32) ((u32) dest + 0xF) >> 4) * 0x10) == (u32) dest) {
            func_800CAFD0(dest, size);

            if (func_800CB080() & 7) {
                do { 

                } while (func_800CB080() & 7); 
            }
            func_800CB090(0, src, dest, size);
            if (func_800CB080() & 7) {
                do { } while (func_800CB080() & 7); }
            goto block_28;
        }
        if (size >= 0x10001) {
            return -1;
        }
        sp30 = ((u32) (D_801604A8 + 0xF) >> 4) * 0x10;
        func_800CAFD0((void*) sp30, size);
        if (func_800CB080() & 7) {
            do { } while (func_800CB080() & 7); }
        func_800CB090(0, src, (void*) sp30, size);
        if (func_800CB080() & 7) {
            do { } while (func_800CB080() & 7); }
        SysMem_Copy8(dest, (void*) sp30, size);
    block_28:
        if (!(D_80182640 & 2)) {
            osSetIntMask(sp2C);
        }
        return 0;
    }
    sp34 = D_801895F4 & 0x7F;
    D_801895F4++;

    if (!((s32) dest % 8)) {
        func_800CAFD0(dest, size);
        osPiStartDma(&D_80187B58, 0, 0, src, dest, (u32) size, &D_80187BC0);
        osRecvMesg(&D_80187BC0, NULL, 1);
        goto exit;
    }

    if (size >= 0x10001) {
        return -1;
    }
    sp30 = ((u32) (D_801604A8 + 0xF) >> 4) * 0x10;
    func_800CAFD0((void*) sp30, size);
    osPiStartDma(&D_80187B58, 0, 0, src, (void*) sp30, (u32) size, &D_80187BC0);
    osRecvMesg(&D_80187BC0, NULL, 1);
    SysMem_Copy8(dest, (void*) sp30, size);
exit:
    return 0;
}

s32 func_800BD620(s32 arg0) {
    s32 sp4;

    sp4 = D_80182640;
    D_80182640 |= arg0;
    return sp4;
}

s32 func_800BD664(s32 arg0) {
    s32 sp4;

    sp4 = D_80182640;
    D_80182640 &= arg0 ^ -1;
    return sp4;
}

void func_800BD6B0(s32 arg0) {
    D_80182640 = arg0;
}

s32 func_800BD6C8(void) {
    return D_80182640;
}
