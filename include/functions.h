#include "structs.h"
#include "macro.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void idleFunc(void*);         
void func_800CB170(void);   
s32 func_800ABE54(void);                                  /* extern */
void SysMem_HeapInit(void);                                  /* extern */
void Thread_Init(void);                                  /* extern */
u8 Thread_CreateSimple(void (*entry)(void *), void* arg, OSPri pri);
ThreadEntry* Thread_CreateExtended(void (*entry)(void*), OSPri pri);
s32 Thread_SetPriority(u8 threadId, OSPri pri);
s32 Thread_Start(u8);                                /* extern */
UnkStruct_800F9C38* Thread_GetPtr(u8);                              /* extern */
s32 func_800CB410(s32, s32 *, s32 *, s32);                    /* extern */
void func_800CB680(s32);
s32 Sys_SwapFrameBuffer(s32*);                          /* extern */
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
void* SysMem_HeapAllocMark(s32);                               /* extern */
void* SysMain(ThreadEntry* entry);
s32 func_800989BC(s32);                               /* extern */
void func_800CB840(OSThread *);                        /* extern */
void func_800CB940(OSThread *);                        /* extern */
s32 func_800C0FFC(u8, s32);          
s32 osGetThreadPri(OSThread *); 
s32 func_800C13B8(u8);                                /* extern */
s32 Thread_SendMsg(OSMesgQueue *mq, OSMesg msg, s32 flag);
s32 Thread_ReceiveMsg(OSMesgQueue *mq, OSMesg *msg, s32 flag);
s32 Thread_CreateMesgQueue(OSMesgQueue *arg0, OSMesg *arg1, s32 arg2);
s32 func_800C1154(u8 threadId, s32 arg1);
s32 func_800AE0EC(OSMesgQueue*); 
s32 func_800C143C(u8 threadId, void **mesg, s32 arg2);
void func_800CAFD0(void*, s32);                        /* extern */
s32 func_800CB080();                                /* extern */
void func_800CB090(s32, u32, void*, s32);                /* extern */
s32 func_800CB080(void);
s32 Sys_GetSPIHeaderInfoFromVaddr(s32);          /* extern */
void func_80002F20(void);
void func_800044BC(void);
void func_8000A2C0(void*);
void func_8001AFA0(void*);
void func_8002856C(UNK_TYPE);
void func_8005D150(void);
void func_8005F01C(void);
void func_80083EAC(void);
void func_8008E5A0(void);
void func_800983B0(UNK_TYPE, UNK_TYPE);
void func_800984B4(void);
void func_800985BC(u8);
void func_80098820(void);
void func_80098868(void);
void func_800AD800(void);
void func_800B1A50(UNK_TYPE*, UNK_TYPE*, UNK_TYPE*, UNK_TYPE*, UNK_TYPE*, UNK_TYPE*, UNK_TYPE*, UNK_TYPE*,
                       UNK_TYPE*, s32);
void func_800B8A2C(void);
void func_800BCB54(void);
s32 func_800BD620(UNK_TYPE);
void func_800BDC70(UNK_TYPE, UNK_TYPE, UNK_TYPE, UNK_TYPE);
int func_800BECCC(s32, f32, f32);
s32 func_800BF0B4(u32 arg0, s32 size, u8* arg2);
void func_800C0A40(void);
void *func_80016074(s32);                           /* extern */
void func_80021ED0(s32);                               /* extern */
void func_800997D8(void*);                             /* extern */
void func_800A7230(void*);                             /* extern */
void func_800C1754(void);                                  /* extern */
void func_800C1A28(void);                                  /* extern */
void func_800C23E8(f32);                               /* extern */
void func_800C25B8(f32);                               /* extern */
void func_800C2780(f32);                               /* extern */
#endif /* FUNCTIONS_H */
