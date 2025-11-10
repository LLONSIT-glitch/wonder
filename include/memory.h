#ifndef MEMORY_H
#define MEMORY_H
typedef struct HeapBlock_s {
    struct HeapBlock_s* prev;
    struct HeapBlock_s* next;  // unk4
    s32 size;          // unk8 — size, but in 16-byte units
    s32 flags;               // unkC — probably 0 = free, 1 = used
} HeapBlock;

s32 SysMem_GetFreeSpace(void);
void* SysMem_HeapAlloc(s32 size);
s32 SysMem_Compare(u8* s1, u8* s2, s32 size);
s32 SysMem_DmaCopy(u32 src, void* dest, s32 size);
s32 SysMem_Free(void* ptr);
#endif /* MEMORY_H */
