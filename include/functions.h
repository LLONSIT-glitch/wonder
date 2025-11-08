#include "structs.h"
#include "macro.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void idleFunc(void*);         
void func_800CB170(void);   
s32 func_800ABE54(void);                                  /* extern */
void Mem_Init(void);                                  /* extern */
void Thread_Init(void);                                  /* extern */
u8 Thread_CreateSimple(void (*entry)(void *), void* arg, OSPri pri);
UnkStruct_80153DC0* Thread_CreateExtended(void (*entry)(void*), OSPri pri);
s32 Thread_SetPriority(u8 threadId, OSPri pri);
s32 Thread_Start(u8);                                /* extern */
UnkStruct_800F9C38* Thread_GetPtr(u8);                              /* extern */
s32 func_800CB410(s32, s32 *, s32 *, s32);                    /* extern */
void func_800CB680(s32);
s32 MusFxBankSetCurrent(s32*);                          /* extern */
s32 func_8008E630(void);                                  /* extern */
s32 func_80099660(s32);                               /* extern */
s32 func_800A6440(void);                                  /* extern */
s32 func_800ABAC8(void);                                  /* extern */
s32 func_800AC890(void);                                  /* extern */
s32 func_800ACE50(void);                                  /* extern */
s32 func_800AF060(s32);                               /* extern */
s32 func_800C15C0(void);                                  /* extern */
void func_80099FB0(f32);                               /* extern */
void func_800ABC30(Gfx**);                            /* extern */
void func_800AC524(Gfx**);                            /* extern */
void func_800B0E88(Gfx**, f32, f32, f32, f32, f32, f32); /* extern */
void func_800BE068(void);                                  /* extern */
void func_800BE08C(void);                                  /* extern */
void osWritebackDCacheAll(void);                                  /* extern */
void* Mem_AllocMark(s32);                               /* extern */
void* func_80000450(void* entry);
void func_800989BC(s32);                               /* extern */
void func_800CB840(OSThread *);                        /* extern */
void func_800CB940(OSThread *);                        /* extern */
s32 func_800C0FFC(u8, s32);          
s32 osGetThreadPri(OSThread *); 
s32 func_800C13B8(u8);                                /* extern */
s32 Thread_SendMsg(OSMesgQueue *mq, OSMesg msg, s32 flag);
s32 Thread_ReceiveMsg(OSMesgQueue *mq, OSMesg *msg, s32 flag);
s32 func_800C1154(u8 threadId, s32 arg1);
void func_800AE0EC(OSMesgQueue*); 
s32 func_800C143C(u8 threadId, void **mesg, s32 arg2);
void func_800CAFD0(void*, s32);                        /* extern */
s32 func_800CB080();                                /* extern */
void func_800CB090(s32, u32, void*, s32);                /* extern */
s32 func_800CB080(void);
#endif /* FUNCTIONS_H */
