#ifndef MEMORY_H
#define MEMORY_H

typedef struct HeapBlock_s {
    struct HeapBlock_s* prev;
    struct HeapBlock_s* next;  // unk4
    s32 size;          // unk8 — size, but in 16-byte units
    s32 flags;               // unkC — probably 0 = free, 1 = used
} HeapBlock;

#define SYS_HEAP_SIZE 0x1B5000

#define FLAGS_FREE 0x0
#define FLAGS_USED 0x1
#define FLAGS_LOCK 0x2

s32 SysMem_GetFreeSpace(void);
void* SysMem_HeapAlloc(s32 size);
s32 SysMem_Compare(u8* s1, u8* s2, s32 size);
s32 SysMem_DmaCopy(u32 src, void* dest, s32 size);
void SysMem_Copy64(void* dest, void* src, s32 size);
void SysMem_Copy8(void* dest, void* src, s32 size);
void SysMem_Copy16(void* dest, void* src, s32 size);
void SysMem_Copy32(void* dest, void* src, s32 size);
s32 SysMem_Free(void* ptr);
s32 SysMem_GetPhysicalAddressFromVirtual(u32 segBase, s32 vStart, s32 vEnd);
/* From dma_copy.c */
void DmaCopy(u32 devAddr, void *vAddr, u32 nBytes);
#endif /* MEMORY_H */
