#include "common.h"

extern HeapBlock* sHeapHead;
extern HeapBlock* sHeapTail; // Heap end
extern s16 sHeapBlocksCount;
extern HeapBlock sMemBlock[];
extern s32 D_80182610;
extern s32 D_80182640;
extern u8 D_801604A8[];

#define BLOCK_FREE 0x0
#define BLOCK_USED 0x1
#define BLOCK_MARK 0x2

void Mem_MarkHeap(void* ptr);
void func_800BCCE4(void*); /* extern */

// Initialize the memory heap
void Mem_Init(void) {
    u32 mask;

    mask = osSetIntMask(OS_IM_NONE);
    sHeapHead = sMemBlock;
    sHeapHead->flags = BLOCK_FREE;
    sHeapHead->size = 0x1B4FF;
    sHeapHead->self = sHeapHead;
    sHeapHead->next = &sMemBlock[sHeapHead->size];
    sHeapTail = sHeapHead->next;
    D_80182610 = 0;
    sHeapBlocksCount = 0;
    D_80182640 = 0;
    osSetIntMask(mask);
}

void* Mem_Alloc(s32 size) {
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
            block->flags |= BLOCK_USED;
            blockPrev = block;
            block = block->next;
            if (blockNext != block) {
                block->self = blockPrev;
                block->next = blockNext;
                block->size = (u32) (blockNext - block);
                block->flags = BLOCK_FREE;
                blockNext = block->next;
                if (blockNext != sHeapTail) {
                    if (blockNext->flags & BLOCK_USED) {
                        blockNext->self = block;
                    } else {
                        block->next = blockNext->next;
                        block->size += blockNext->size;
                        blockNext = block->next;
                        blockNext->self = block;
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
 * @brief Allocate a block and marks it
 */
void* Mem_AllocMark(s32 size) {
    void* ptr;

    ptr = Mem_Alloc(size);

    if (ptr == NULL) {
        return ptr;
    }

    Mem_MarkHeap(ptr);
    return ptr;
}

s32 func_800BC980(void* arg0) {
    HeapBlock* spC;
    HeapBlock* sp8;
    HeapBlock* sp4;

    spC = (HeapBlock*) arg0 - 1;
    if (!(spC->flags & BLOCK_USED)) {
        return -1;
    }
    spC->flags = (s32) (spC->flags & ~1);
    sp4 = spC->next;
    if ((sp4 != sHeapTail) && !(sp4->flags & 1)) {
        spC->next = (void*) sp4->next;
        spC->size = (s32) (spC->size + sp4->size);
        sp4 = spC->next;
        sp4->self = spC;
    }
    sp8 = spC->self;
    if ((spC != sHeapHead) && !(sp8->flags & 1)) {
        sp8->next = (void*) spC->next;
        sp8->size = (s32) (sp8->size + spC->size);
        spC = spC->next;
        spC->self = sp8;
    }
    return 0;
}

s32 func_800BCB10(void* arg0) {
    func_800BCCE4(arg0);
    return func_800BC980(arg0);
}

void func_800BCB54(void) {
    HeapBlock* sp1C;

    for (sp1C = sHeapHead; sp1C != sHeapTail; sp1C = sp1C->next) {
        if (!(sp1C->flags & 1)) {

        } else if (!(sp1C->flags & 2)) {
            func_800BC980(sp1C + 1);
        }
    }
}

void func_800BCBF8(void) {
    HeapBlock* sp1C;

    for (sp1C = sHeapHead; sp1C != sHeapTail; sp1C = sp1C->next) {
        if (!(sp1C->flags & 1)) {

        } else {
            func_800BCCE4(sp1C);
            func_800BC980(sp1C + 1);
        }
    }
}

void Mem_MarkHeap(void* ptr) {
    HeapBlock* block;

    block = (HeapBlock*) ptr - 1;
    if (!(block->flags & BLOCK_USED)) {
        return;
    }
    block->flags |= BLOCK_MARK;
}

void func_800BCCE4(void* arg0) {
    HeapBlock* sp4;

    sp4 = (HeapBlock*) arg0 - 1;
    if (!(sp4->flags & 1)) {
        return;
    }
    sp4->flags = (s32) (sp4->flags & ~2);
}

s32 func_800BCD3C(void) {
    s32 sp4;
    HeapBlock* sp0;

    sp4 = 0;
    sHeapBlocksCount = 0;
    for (sp0 = sHeapHead; sp0 != sHeapTail; sp0 = sp0->next) {
        if ((sp0->flags & 1) && !(sp0->flags & 2)) {
            sp4 += sp0->size;
            sHeapBlocksCount += 1;
        }
    }
    return sp4 * 0x10;
}

s32 func_800BCDFC(void) {
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

s32 Mem_GetFreeSpace(void) {
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
 * @brief Copy a memory regin into another by bytes
 *
 */
void Mem_Copy8(void* dest, void* src, s32 size) {
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

void Mem_Copy16(void* dest, void* src, s32 size) {
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
UNUSED void Mem_Copy32(void* dest, void* src, s32 size) {
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

void Mem_Copy64(void* dest, void* src, s32 size) {
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

s32 Mem_Compare(u8* s1, u8* s2, s32 size) {
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

s32 func_800BD1FC(s32 arg0, s32 arg1, s32 arg2) {
    return (u32) arg0 + (arg2 - arg1);
}

s32 func_800BD218(u32 arg0, void* arg1, s32 arg2) {
    s32 sp34;
    s32 sp30;
    u32 sp2C;

    if (arg2 == 0) {
        return -1;
    }
    osWritebackDCacheAll();
    if ((arg0 >= 0x80000000U) && (arg0 < 0x80400000U)) {
        Mem_Copy8(arg1, (void*) arg0, arg2);
        return 0;
    }
    if (arg0 & 1) {
        return -1;
    }
    if (arg0 >= 0x80400000U) {
        return -1;
    }
    if (((u32) arg1 < 0x80000000U) || ((u32) arg1 >= 0x80400000U)) {
        return -1;
    }
    if (D_80182640 & 1) {
        if (!(D_80182640 & 2)) {
            sp2C = osSetIntMask(1U);
        }
        if ((((u32) ((u32) arg1 + 0xF) >> 4) * 0x10) == (u32) arg1) {
            func_800CAFD0(arg1, arg2);
            if (func_800CB080() & 7) {
                do { } while (func_800CB080() & 7); }
            func_800CB090(0, arg0, arg1, arg2);
            if (func_800CB080() & 7) {
                do { } while (func_800CB080() & 7); }
            goto block_28;
        }
        if (arg2 >= 0x10001) {
            return -1;
        }
        sp30 = ((u32) (D_801604A8 + 0xF) >> 4) * 0x10;
        func_800CAFD0((void*) sp30, arg2);
        if (func_800CB080() & 7) {
            do { } while (func_800CB080() & 7); }
        func_800CB090(0, arg0, (void*) sp30, arg2);
        if (func_800CB080() & 7) {
            do { } while (func_800CB080() & 7); }
        Mem_Copy8(arg1, (void*) sp30, arg2);
    block_28:
        if (!(D_80182640 & 2)) {
            osSetIntMask(sp2C);
        }
        return 0;
    }
    sp34 = D_801895F4 & 0x7F;
    D_801895F4 += 1;
    if (!((s32) arg1 % 8)) {
        func_800CAFD0(arg1, arg2);
        osPiStartDma(&D_80187B58, 0, 0, arg0, arg1, (u32) arg2, &D_80187BC0);
        osRecvMesg(&D_80187BC0, NULL, 1);
        goto block_36;
    }
    if (arg2 >= 0x10001) {
        return -1;
    }
    sp30 = ((u32) (D_801604A8 + 0xF) >> 4) * 0x10;
    func_800CAFD0((void*) sp30, arg2);
    osPiStartDma(&D_80187B58, 0, 0, arg0, (void*) sp30, (u32) arg2, &D_80187BC0);
    osRecvMesg(&D_80187BC0, NULL, 1);
    Mem_Copy8(arg1, (void*) sp30, arg2);
block_36:
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
