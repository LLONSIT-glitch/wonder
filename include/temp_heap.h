#ifndef TEMP_HEAP_H
#define TEMP_HEAP_H
void TempHeap_Init(HeapBlock* heapStart, u32 heapSize);
void* TempHeap_Alloc(s32 size);
s32 TempHeap_Free(void* ptr);
void TempHeap_Mark(void* ptr, s32 arg1);
#endif /* TEMP_HEAP_H */
