#ifndef MEMORY_H
#define MEMORY_H
typedef struct HeapBlock_s {
    struct HeapBlock_s* self;
    struct HeapBlock_s* next;  // unk4
    s32 size;          // unk8 — size, but in 16-byte units
    s32 flags;               // unkC — probably 0 = free, 1 = used
} HeapBlock;

s32 Mem_GetFreeSpace(void);
void* Mem_Alloc(s32 size);
s32 Mem_Compare(u8* s1, u8* s2, s32 size);
#endif /* MEMORY_H */
