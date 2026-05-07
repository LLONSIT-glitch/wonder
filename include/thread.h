#ifndef THREAD_H
#define THREAD_H

typedef struct ThreadEntry {
    /* 0x00 */ u8 threadId;
    /* 0x01 */ char pad1[3]; /* maybe part of threadId[4]? */
    /* 0x04 */ s32 threadPri;
    /* 0x08 */ s32 unk8;       /* inferred */
    /* 0x0C */ char padC[0xC]; /* maybe part of unk8[4]? */
    /* 0x18 */ UnkStruct_800F9C38* unk18;
    /* 0x1C */ char pad1C[8]; /* maybe part of unk18[3]? */
} ThreadEntry;                /* size = 0x24 */

typedef enum { THREAD_ID_SYS_MAIN, THREAD_ID_AUDIO_MGR, THREAD_ID_3, THREAD_ID_IDLE } ThreadIds;

extern ThreadIds gSysThreadIds[];

ThreadEntry* Thread_CreateExtended(void (*entry)(void*), OSPri pri);
s32 Thread_CreateMesgQueue(OSMesgQueue* arg0, OSMesg* arg1, s32 arg2);
u8 Thread_CreateSimple(void (*entry)(void*), void* arg, OSPri pri);
s32 Thread_DestroyThread(u8 threadId);
UNUSED s32 Thread_GetCreatedThreadsCount(void);
s32 Thread_GetPriority(u8 arg0);
UnkStruct_800F9C38* Thread_GetPtr(u8 threadId);
void Thread_Init(void);
s32 Thread_ReceiveMsg(OSMesgQueue* mq, OSMesg* msg, s32 flag);
s32 Thread_ReceiveMsgInThread(u8 threadId, void** mesg, s32 flag);
s32 Thread_ResetMqValidCount(u8 threadId);
s32 Thread_SendMesgNoBlock(u8 arg0, void* arg1, /* unused */ s32 arg2);
s32 Thread_SendMsg(OSMesgQueue* mq, OSMesg msg, s32 flag);
s32 Thread_SetPriority(u8 threadId, OSPri pri);
s32 Thread_Start(u8 threadId);
s32 Thread_StopThread(u8 threadId);
UNUSED s32 Thread_UnkDbgFunc0(u8 threadId, u8 threadId2);
UNUSED void Thread_UnkDbgFunc1(u8 stopThreadId, u8 startThreadId);
void Thread_Yield(void);
s32 func_800C0988(u8 arg0);
void func_800C0A40(void);
s32 func_800C1154(u8 threadId, s32 arg1);
s32 func_800C1314(u8 arg0, s32 arg1);

#endif /* THREAD_H */
