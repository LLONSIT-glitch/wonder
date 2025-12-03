/**
 * @file temp_heap.c
 *
 * Temporary/secondary heap used by the game.
 *
 * This heap uses the same `HeapBlock` layout as the main system heap in
 * `sys_mem.c`, but it is backed by a caller-provided memory region instead of
 * the global `sMemBlock` array.
 */
#include "common.h"

static HeapBlock* sTempHeapHead;
static HeapBlock* sTempHeapTail;

/**
 * Initializes the temporary heap.
 *
 * @param heapStart   Pointer to the first `HeapBlock` in the backing buffer.
 * @param heapSize    Size of the backing buffer in bytes.
 */
void TempHeap_Init(HeapBlock* heapStart, u32 heapSize) {
    sTempHeapHead = heapStart;
    sTempHeapHead->flags = FLAGS_FREE;
    // Store the usable size in 16-byte units, excluding the header block.
    sTempHeapHead->size = (heapSize >> 4) - 1;
    sTempHeapHead->prev = sTempHeapHead;
    sTempHeapHead->next = (HeapBlock*) ((u8*) heapStart + (sTempHeapHead->size * 0x10));
    sTempHeapTail = sTempHeapHead->next;
}

/**
 * Allocates a block from the temporary heap.
 *
 * This mirrors the behaviour of `SysMem_HeapAlloc`, but operates on the
 * temporary heap managed by `TempHeap_Init`.
 *
 * @param size  Requested size in bytes.
 * @return      Pointer to a usable memory region of at least `size` bytes,
 *              or `NULL` if the allocation fails.
 */
void* TempHeap_Alloc(s32 size) {
    HeapBlock* block;
    HeapBlock* prevBlock;
    HeapBlock* nextBlock;
    u32 blockSize;

    // Convert requested size in bytes to HeapBlock units (16-byte multiples)
    // and account for the header block.
    blockSize = ((u32) (size + 15) >> 4) + 1; // Align size to 16
    for (block = sTempHeapHead; block != sTempHeapTail; block = block->next) {
        // If the block is not available skip it
        if (block->flags & FLAGS_USED) {
            continue;
        }
        if ((u32) block->size >= blockSize) {
            nextBlock = block->next;
            block->size = blockSize;
            block->next = &block[blockSize];
            block->flags |= FLAGS_USED;
            prevBlock = block;
            block = block->next;
            if (nextBlock != block) {
                // Split the free block into used + remaining-free part.
                block->prev = prevBlock;
                block->next = nextBlock;
                block->size = (u32) (nextBlock - block);
                block->flags = FLAGS_FREE;
                nextBlock = block->next;
                if (nextBlock != sTempHeapTail) {
                    if (nextBlock->flags & FLAGS_USED) {
                        nextBlock->prev = block;
                    } else {
                        // Merge with following free block.
                        block->next = nextBlock->next;
                        block->size += nextBlock->size;
                        nextBlock = block->next;
                        nextBlock->prev = block;
                    }
                }
            }

            // Return pointer to user data (skip header)
            return prevBlock + 1;
        }
    }
    return NULL;
}

/**
 * Frees a block previously allocated from the temporary heap.
 *
 * This mirrors the behaviour of `SysMem_Free`, coalescing adjacent free
 * blocks whenever possible.
 *
 * @param ptr  Pointer returned by `TempHeap_Alloc`.
 * @return     0 on success, -1 if `ptr` is invalid or was not allocated.
 */
s32 TempHeap_Free(void* ptr) {
    HeapBlock* block;
    HeapBlock* prevBlock;
    HeapBlock* nextBlock;

    block = ((HeapBlock*) ptr) - 1;
    if (!(block->flags & FLAGS_USED)) {
        return -1;
    }
    block->flags &= ~FLAGS_USED;

    // Try to merge with the following block.
    nextBlock = block->next;
    if ((nextBlock != sTempHeapTail) && !(nextBlock->flags & FLAGS_USED)) {
        block->next = nextBlock->next;
        block->size += nextBlock->size;
        nextBlock = block->next;
        nextBlock->prev = block;
    }

    // Try to merge with the previous block.
    prevBlock = block->prev;
    if ((block != sTempHeapHead) && !(prevBlock->flags & FLAGS_USED)) {
        prevBlock->next = block->next;
        prevBlock->size += block->size;
        block = block->next;
        block->prev = prevBlock;
    }
    return 0;
}

/**
 * Marks a temporary-heap block as "locked" for this subsystem.
 *
 * Unlike the main heap, this uses bit 0x4 in the flags field as an
 * implementation-specific "locked" marker.
 *
 * @param ptr   Pointer returned by `TempHeap_Alloc`.
 * @param arg1  Unused, kept for matching reasons.
 */
void TempHeap_Mark(void* ptr, UNUSED s32 arg1) {
    HeapBlock* block;

    block = ((HeapBlock*) ptr) - 1;
    if (!(block->flags & FLAGS_USED)) {
        return;
    }
    block->flags |= 0x4;
}
