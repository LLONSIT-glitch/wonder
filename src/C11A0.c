/*
* possible name: sys_thread.c
*/
#include "common.h"

extern struct UnkStruct_800F9C38 D_800F1950[];
extern struct UnkStruct_800F9C38  D_800F9C38[];
extern UnkStruct_80153DC0* D_80153DC0[];

#define MAX_THREADS 12

#define THREAD_ERROR -1 /* Generic error code */
#define THREAD_SUCCESS 0 /* Generic success code */

/* Thread flags */
#define THREAD_AVAILABLE 0
#define THREAD_CREATED 1 << 7

void Thread_Init(void) {
    u8 threadId;

    for (threadId = 0; threadId < MAX_THREADS; threadId++) {
        D_800F9C38[threadId].flags = THREAD_AVAILABLE;
        D_800F9C38[threadId].unk1 = 0; /* Unused field? */
        D_80153DC0[threadId] = NULL;
    }
}

/*
* @brief Creates a simple thread and asigns it a threadId that is not used
* @param entry Thread entry
* @param arg Thread argument
* @param pri Thread priority see os.h for reseved priorities
*/
u8 Thread_CreateSimple(void (*entry)(void *), void* arg, OSPri pri) {
    u8 threadId;

    for (threadId = 0; threadId < MAX_THREADS; threadId++) {
        if (D_800F9C38[threadId].flags == THREAD_AVAILABLE) {
           break;
        }
    }

    /* If we don't have more threads available in the list return error */
    if (threadId >= MAX_THREADS) {
        return THREAD_ERROR;
    }

    // Add 10 to each threadId
    osCreateThread(&D_800F1950[threadId].thread, threadId + 10, entry, arg, &D_800F1950[threadId].threadSp, pri);
    D_800F9C38[threadId].flags = THREAD_CREATED; // Some kind of flags?
    return threadId;
}

UnkStruct_80153DC0* Thread_CreateExtended(void (*entry)(void*), OSPri pri) {
    u8 threadId;
    UnkStruct_80153DC0* sp30;
    s32 temp_v0;

    for (threadId = 0; threadId < MAX_THREADS; threadId++) {
        if (D_800F9C38[threadId].flags == THREAD_AVAILABLE) {
           break;
        }
    }

    /* If we don't have more threads available in the list return error */
    if (threadId >= MAX_THREADS) {
        return NULL;
    }
    
    if (D_80153DC0[threadId] == NULL) {
        if ((D_80153DC0[threadId] = Mem_AllocMark(sizeof(UnkStruct_80153DC0))) == NULL) {
            return NULL;
        }
    }
    
    sp30 = D_80153DC0[threadId];
    osCreateThread(&D_800F1950[threadId].thread, threadId + 10, entry, (void* ) D_80153DC0[threadId], &D_800F1950[threadId].threadSp, pri);
    D_800F9C38[threadId].flags = THREAD_CREATED;
    sp30->threadId = threadId;
    sp30->unk18 = &D_800F1950[threadId];
    sp30->threadPri = pri;
    return sp30;
}

s32 func_800C0988(u8 arg0) {
    if (!(D_800F9C38[arg0].flags & THREAD_CREATED)) {
        return THREAD_ERROR;
    }
    D_800F1950[arg0].unk82E8 = D_800F1950[arg0].unk82E8 | 1;
    return 0;
}

void func_800C0A40(void) {
    s32 sp1C;

    for (sp1C = 0; sp1C < MAX_THREADS; sp1C++) {
        if ((D_800F9C38[sp1C].flags & 0x80) && (D_800F9C38[sp1C].flags & 1)) {
            if (D_800F9C38[sp1C].flags & 2) {
                func_800989BC(sp1C);
            }
            D_800F9C38[sp1C].flags = THREAD_AVAILABLE;
            func_800CB840(&D_800F1950[sp1C].thread);
        }
    } 
}

s32 func_800C0B70(u8 arg0) {
    if (!(D_800F9C38[arg0].flags & 0x80)) {
        return -1;
    }
    if (D_800F9C38[arg0].flags & 2) {
        func_800989BC((s32) arg0);
    }
    D_800F9C38[arg0].flags = 0;
    func_800CB840(&D_800F1950[arg0].thread);
    return 0;
}

s32 Thread_Start(u8 threadId) {
    if (!(D_800F9C38[threadId].flags & THREAD_CREATED)) {
        return THREAD_ERROR;
    }
    osStartThread(&D_800F1950[threadId].thread);
    return 0;
}

s32 func_800C0D34(u8 arg0) {
    if (!(D_800F9C38[arg0].flags & 0x80)) {
        return -1;
    }
    func_800CB940(&D_800F1950[arg0].thread);
    return 0;
}

/* Unused function */
void Thread_Yield(void) {
    osYieldThread();
}

UnkStruct_800F9C38* Thread_GetPtr(u8 threadId) {
    if (!(D_800F9C38[threadId].flags & THREAD_CREATED)) {
        return NULL;
    }
    return &D_800F1950[threadId];
}

s32 func_800C0E84(void) {
    s32 threadId;
    s32 sp0;

    for (threadId = 0, sp0 = 0; threadId < MAX_THREADS; threadId++) {
        if (D_800F9C38[threadId].flags & 0x80) {
            sp0++;
        }
    } 

    return sp0;
}

/* Unused function */
s32 func_800C0F10(u8 threadId, u8 threadId2) {
    if (!(D_800F9C38[threadId].flags & 0x80)) {
        return THREAD_ERROR;
    }
    if (Thread_SetPriority(threadId, OS_PRIORITY_IDLE) != THREAD_SUCCESS) {
        return THREAD_ERROR;
    }
    Thread_Start(threadId2);

    func_800C0D34(threadId);
    // @bug no return value
}

void func_800C0FB0(u8 arg0, u8 arg1) {
    Thread_Start(arg1);
    func_800C0D34(arg0);
    func_800C0B70(arg1);
}

s32 Thread_SetPriority(u8 threadId, OSPri pri) {
    if (!(D_800F9C38[threadId].flags & 0x80)) {
        return THREAD_ERROR;
    }
    osSetThreadPri(&D_800F1950[threadId].thread, pri);
    return THREAD_SUCCESS;
}

s32 Thread_GetPriority(u8 arg0) {
    if (!(D_800F9C38[arg0].flags & 0x80)) {
        return THREAD_ERROR;
    }
    return osGetThreadPri(&D_800F1950[arg0].thread);
}

s32 func_800C1154(u8 threadId, s32 arg1) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[threadId];
    if (!(sp1C->unk82E8 & THREAD_CREATED)) {
        return -1;
    }
    if (arg1 >= 9) {
        return -2;
    }
    if (sp1C->unk82E9 & 1) {
        func_800C13B8(threadId);
        return 0;
    }
    osCreateMesgQueue(&sp1C->mq, &sp1C->unk82B0, arg1);
    sp1C->unk82E9 |= 1;
    return 0;
}

s32 func_800C1264(u8 arg0, void *arg1, /* unused */ s32 arg2) {
    if (!(D_800F9C38[arg0].flags & 0x80)) {
        return -1;
    }
    osSendMesg((OSMesgQueue *) &D_800F1950[arg0].mq, arg1, 0);
    /* @bug no return */
}

s32 func_800C1314(u8 arg0, s32 arg1) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    osRecvMesg((OSMesgQueue *) &sp1C->mq, (void **) &sp1C->unk82B0, arg1);
    return 0;
}

s32 func_800C13B8(u8 arg0) {
    UnkStruct_800F9C38 *sp4;

    sp4 = &D_800F1950[arg0];
    if (!(sp4->unk82E8 & 0x80)) {
        return -1;
    }
    sp4->mq.validCount = 0;
    return 0;
}

s32 func_800C143C(u8 threadId, void **mesg, s32 flag) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[threadId];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    osRecvMesg((OSMesgQueue *) &sp1C->mq, mesg, flag);
    return 0;
}

s32 func_800C14E0(OSMesgQueue *arg0, s32 *arg1, s32 arg2) {
    osCreateMesgQueue(arg0, arg1, arg2);
    return 0;
}

s32 Thread_SendMsg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    return osSendMesg(mq, msg, flag);
}

s32 Thread_ReceiveMsg(OSMesgQueue *mq, OSMesg *msg, s32 flag) {
    return osRecvMesg(mq, msg, flag);
}

