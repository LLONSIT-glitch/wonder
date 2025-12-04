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
void Sys_SwapFrameBuffer(void*);                          /* extern */
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
s32 Thread_ResetMqValidCount(u8);                                /* extern */
s32 Thread_SendMsg(OSMesgQueue *mq, OSMesg msg, s32 flag);
s32 Thread_ReceiveMsg(OSMesgQueue *mq, OSMesg *msg, s32 flag);
s32 Thread_CreateMesgQueue(OSMesgQueue *arg0, OSMesg *arg1, s32 arg2);
s32 func_800C1154(u8 threadId, s32 arg1);
s32 func_800AE0EC(OSMesgQueue*); 
s32 func_800C143C(u8 threadId, void **mesg, s32 arg2);
s32 osPiGetStatus();                                /* extern */
s32 osPiGetStatus(void);
s32 Sys_GetSPIHeaderInfoFromVaddr(s32);          /* extern */
void func_80002F20(void);
void func_800044BC(void);
void func_8000A2C0(void*);
void func_8001AFA0(UnkStruct_8000DDE0 *arg0);
void func_8002856C(UNK_TYPE);
void func_8005D150(void);
void func_8005F01C(void);
void func_80083EAC(void);
void func_8008E5A0(void);
void func_800983B0(UnkStruct_801AC8A8*, UNK_TYPE);
void func_800984B4(void);
void func_800985BC(u8);
void func_80098820(void);
void func_80098868(void);
void func_800AD800(void);
void func_800B1A50(u8*, u8*, u8*, u8*, u8*, u8*, u8*, u8*, u8*, u16);
void AudioMgr_InitThread(void);
void func_800BCB54(void);
s32 func_800BD620(UNK_TYPE);
void func_800BDC70(UNK_TYPE, UNK_TYPE, UNK_TYPE, UNK_TYPE);
int func_800BECCC(s32, f32, f32);
s32 Spi_DecompressAsset(u32 arg0, s32 size, u8* arg2);
void func_800C0A40(void);
UnkStruct_8000DDE0 *func_80016074(s32);                           /* extern */
void func_80021ED0(s32);                               /* extern */
void func_800997D8(void*);                             /* extern */
void func_800A7230(void*);                             /* extern */
void func_800C1754(void);                                  /* extern */
void func_800C1A28(void);                                  /* extern */
void func_800C23E8(f32);                               /* extern */
void func_800C25B8(f32);                               /* extern */
void func_800C2780(f32);                               /* extern */

void func_8008EAA8(s32, s32);
void func_8008ECE4(char* fmt, ...);
void func_800AE348(s32);
s32 func_800AE5F0(s32);
s32 func_800AE7FC(void);
s32 func_800AE880(u8*, u8*, s32);
s32 func_800AEA0C(void);
s32 func_800AEA98(u8*, u8*);
s32 func_800AEBF4(void);
s32 func_800AEDE8(void);
s32 func_800AEFD4(void);
void* func_8001F60C(u8**);
void func_80099E2C(void*);
void func_800B1B3C(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, s32 arg2);
void func_800B1C10(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, s32 arg2);
s32 func_8001F390(UnkStruct_80020720* arg0);
void func_8001F6B8(void);
void func_8001F800(void);
void func_80022124(void);                                  /* extern */
void func_8009A14C(void*);                               /* extern */
s32 func_800B202C(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, u32 arg2, u16 arg3, f32 arg4, f32 arg5, u8 arg6);
s32 func_800B2748(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1);
s32 func_800B2CBC(UnkStruct_80099E2C**, UnkStruct_800B23C4**, s32);                   /* extern */
u16 func_800B32E4(UnkStruct_800B23C4**, s32);                         /* extern */
s32 func_800B3434(UnkStruct_800B23C4 **arg0, u8 arg1);
void func_800B3DBC(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, u16 paletteIndex) ;             /* extern */
void func_800B9000(u16);                               /* extern */
s32 func_8001F390(UnkStruct_80020720* arg0);
void func_8001F6B8(void);
void func_8001F800(void);
s32 func_8000E524(UnkStruct_8000DDE0*);             /* extern */
s32 func_8000E678(UnkStruct_8000DDE0*);             /* extern */
s32 func_8000E7E4(UnkStruct_8000DDE0*);               /* extern */
s32 func_8000E9F8(UnkStruct_8000DDE0*);             /* extern */
void func_800111E8(UnkStruct_8000DDE0*);               /* extern */
void func_8001173C(UnkStruct_8000DDE0*);               /* extern */
void func_80011A0C(UnkStruct_8000DDE0*);               /* extern */
void func_80011B88(UnkStruct_8000DDE0*);               /* extern */
void func_80011F7C(UnkStruct_8000DDE0*);               /* extern */
void func_80012068(UnkStruct_8000DDE0*);               /* extern */
void func_80012164(UnkStruct_8000DDE0*);               /* extern */
void func_800123AC(UnkStruct_8000DDE0*);               /* extern */
void func_800124B8(UnkStruct_8000DDE0*);               /* extern */
void func_80012634(UnkStruct_8000DDE0*);               /* extern */
void func_80012798(UnkStruct_8000DDE0*);               /* extern */
void func_8001292C(UnkStruct_8000DDE0*);               /* extern */
void func_800129FC(UnkStruct_8000DDE0*);               /* extern */
void func_80012E7C(UnkStruct_8000DDE0*);               /* extern */
void func_800131F4(UnkStruct_8000DDE0*);               /* extern */
void func_80013398(UnkStruct_8000DDE0*);               /* extern */
void func_80013474(UnkStruct_8000DDE0*);               /* extern */
void func_80013624(UnkStruct_8000DDE0*);               /* extern */
void func_800139B8(UnkStruct_8000DDE0*);               /* extern */
void func_80013AFC(UnkStruct_8000DDE0*);               /* extern */
void func_80013C90(UnkStruct_8000DDE0*);               /* extern */
void func_80013F04(UnkStruct_8000DDE0*);               /* extern */
void func_80013FEC(UnkStruct_8000DDE0*);               /* extern */
void func_800140D8(UnkStruct_8000DDE0*);               /* extern */
void func_80014228(UnkStruct_8000DDE0*);               /* extern */
void func_800145D4(UnkStruct_8000DDE0*);               /* extern */
void func_80014A80(UnkStruct_8000DDE0*);               /* extern */
void func_80015C30(UnkStruct_8000DDE0*);               /* extern */
void func_80015D74(UnkStruct_8000DDE0*);               /* extern */
void func_800298A4(s16, s16, s16, f32, f32);           /* extern */
void func_800299C4(s32);                               /* extern */
void func_80029C8C(s16);                               /* extern */
void func_80029ED8(void);                                  /* extern */
void func_8002BD8C(s16, f32*, f32*);                   /* extern */
void func_8002C270(void*);                               /* extern */
void func_8002D200(void);                                  /* extern */
void func_80099F90(f32, f32);                              /* extern */
void func_800AC0A4(s32, s32, s32, s32);                /* extern */
void func_800AD1E4(Gfx**, s32);                          /* extern */
void func_800B0E08(void);                                  /* extern */
void func_800C2304(f32 arg0, f32 arg1, f32 arg2) ;
void func_800C3D70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void *arg6);
s32 func_800C3F2C(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4) ;
void func_800C1850(s32);                                 /* extern */
void func_800C1D44(MtxF*);                                /* extern */
void func_800C2948(f32, f32, f32);                     /* extern */
void func_800C2AE8(MtxF*);                             /* extern */
f32 func_8002BB04(s16 arg0);
#endif /* FUNCTIONS_H */
