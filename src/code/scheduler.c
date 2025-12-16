/*
 * @file scheduler.c
 * @brief Seems to be a modified version of libultra's RSP scheduler implementation (sched.c)
 */
#include "common.h"

#define VIDEO_MSG 0x29A
#define RSP_DONE_MSG 0x29B
#define RDP_DONE_MSG 0x29C
#define PRE_NMI_MSG 0x29D

#define SCHEDULER_YIELD 0x10

extern s32 D_801A72BC;
extern s32 D_801A72CC;
extern s16 D_801A72F0;

static int sMaybePadding = 0;
s32 sDpBusy = 0;
s32 sDpCount = 0;

void Scheduler_AppendTask(Scheduler* arg0, SchedulerTask* arg1);

void Scheduler_CreateScheduler(Scheduler* scheduler, u8 arg1, s32 arg2) {
    scheduler->curRSPTask = 0;
    scheduler->curRDPTask = 0;
    scheduler->clientList = 0;
    scheduler->unk29C = 0;
    scheduler->unk2A0 = 0;
    scheduler->audioListHead = 0;
    scheduler->gfxListHead = 0;
    scheduler->audioListTail = 0;
    scheduler->gfxListTail = 0;
    scheduler->unk0.type = 1;
    scheduler->unk20.type = 4;
    scheduler->unk40.type = 5;
    D_801A72F0 = 6;
    D_801A72BC = 0;
    D_801A72CC = 0;
    D_801A72DC = 0;
    osCreateMesgQueue(&scheduler->interruptQ, &scheduler->unk78, 8);
    osCreateMesgQueue(&scheduler->cmdQ, &scheduler->unkB0, 8);
    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&osViModeTable[arg1]);
    osViBlack(TRUE);
    osSetEventMesg(OS_EVENT_SP, &scheduler->interruptQ, (void*) RSP_DONE_MSG);
    osSetEventMesg(OS_EVENT_DP, &scheduler->interruptQ, (void*) RDP_DONE_MSG);
    osSetEventMesg(OS_EVENT_PRENMI, &scheduler->interruptQ, (void*) PRE_NMI_MSG);
    osViSetEvent(&scheduler->interruptQ, (void*) VIDEO_MSG, (u32) (u8) arg2);
}

void Scheduler_CreateSchedulerThread(Scheduler* scheduler, void* sp, OSPri pri) {
    osCreateThread(&scheduler->thread, 4, (void (*)(void*)) Scheduler_Thread, scheduler, sp, pri);
    osStartThread(&scheduler->thread);
}

UNUSED void func_800970CC(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);

    arg1->mq = mq;
    arg1->next = arg0->clientList;
    arg1->unk8 = 0;
    arg0->clientList = arg1;
    osSetIntMask(imask);
}

void func_80097150(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);
    arg1->mq = mq;
    arg1->next = arg0->clientList;
    arg1->unk8 = 2;
    arg0->clientList = arg1;
    osSetIntMask(imask);
}

void func_800971D4(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);
    arg1->mq = mq;
    arg1->next = arg0->clientList;
    arg1->unk8 = 1;
    arg0->clientList = arg1;
    osSetIntMask(imask);
}

void func_80097258(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);
    arg1->mq = mq;
    arg1->next = arg0->clientList;
    arg1->unk8 = 8;
    arg0->clientList = arg1;
    osSetIntMask(imask);
}

void func_800972DC(SchedulerClient* arg0) {
    arg0->unk8 |= 4;
}

void func_800972FC(SchedulerClient* arg0) {
    arg0->unk8 &= ~4;
}

void Scheduler_RemoveClient(Scheduler* scheduler, SchedulerClient* client) {
    SchedulerClient* clientListHead;
    SchedulerClient* clientListPrev;
    u32 mask;

    clientListHead = scheduler->clientList;
    clientListPrev = NULL;
    mask = osSetIntMask(OS_IM_NONE);

    while (clientListHead != NULL) {
        if (clientListHead == client) {
            if (clientListPrev != NULL) {
                clientListPrev->next = client->next;
            } else {
                scheduler->clientList = client->next;
            }
            break;
        }
        clientListPrev = clientListHead;
        clientListHead = clientListHead->next;
    }
    osSetIntMask(mask);
}

s32 func_80097408(Scheduler* arg0) {
    return (s32) &arg0->cmdQ;
}

void func_80097420(Scheduler* scheduler) {
    SchedulerClient* client;

    for (client = scheduler->clientList; client != NULL; client = client->next) {
        if (!(client->unk8 & 1)) {
            client->mq->validCount = 0;
        }
    }
}

void func_80097498(void) {
    D_801A72DC &= ~8;
}

void func_800974C0(Scheduler* arg0) {
    s32 threadCount;
    SchedulerClient* client;

    for (threadCount = 0, client = arg0->clientList; client != NULL; client = client->next) {
        if (client->unk8 & 8) {
            osSendMesg((OSMesgQueue*) client->mq, arg0, OS_MESG_NOBLOCK);
            threadCount++;
        }
    }
    if (threadCount != 0) {
        osYieldThread();
    }
}

void Scheduler_Thread(void* arg) {
    OSMesg schedulerMesg;
    Scheduler* scheduler;
    SchedulerClient* client;

    scheduler = arg;
    while (TRUE) {
        osRecvMesg(&scheduler->interruptQ, &schedulerMesg, 1);
        switch ((s32) schedulerMesg) { /* irregular */
            case VIDEO_MSG:
                Scheduler_HandleVideoMesg(scheduler);
                guRandom();
                break;
            case RSP_DONE_MSG:
                Scheduler_HandleRspMesg(scheduler);
                guRandom();
                break;
            case RDP_DONE_MSG:
                Scheduler_HandleRdpMesg(scheduler);
                guRandom();
                break;
            case PRE_NMI_MSG:
                for (client = scheduler->clientList; client != NULL; client = client->next) {
                    osSendMesg((OSMesgQueue*) client->mq, &scheduler->unk20, 0);
                }
                break;
        }
    }
}

void Scheduler_HandleVideoMesg(Scheduler* scheduler) {
    SchedulerTask* rspTask;
    SchedulerClient* client;
    UNUSED s32 pad24;
    s32 avail;
    SchedulerTask* rspTask1 = NULL;
    SchedulerTask* rdpTask = NULL;

    while (osRecvMesg(&scheduler->cmdQ, (OSMesg*) &rspTask, OS_MESG_NOBLOCK) != -1) {
        Scheduler_AppendTask(scheduler, rspTask);
    }

    if ((scheduler->doAudio) && (scheduler->curRSPTask != NULL)) {
        Scheduler_RspTaskYield(scheduler);
    } else {
        avail = ((scheduler->curRSPTask == 0) << 1) | (scheduler->curRDPTask == 0);
        if (Scheduler_ScheduleTask(scheduler, &rspTask1, &rdpTask, avail) != avail) {
            Scheduler_ExecuteTask(scheduler, rspTask1, rdpTask);
        }
    }
    if (!(D_801A72DC & 1)) {
        for (client = scheduler->clientList; client != NULL; client = client->next) {
            if (!(client->unk8 & 8)) {
                osSendMesg(client->mq, scheduler, OS_MESG_NOBLOCK);
            }
        }
    } else if (!(D_801A72DC & 2)) {
        for (client = scheduler->clientList; client != NULL; client = client->next) {
            if (!(client->unk8 & 8)) {
                osSendMesg(client->mq, &scheduler->unk40, OS_MESG_NOBLOCK);
            }
        }
    } else {
        D_801A72DC &= ~2;
        for (client = scheduler->clientList; client != NULL; client = client->next) {
            if (!(client->unk8 & 8)) {
                osSendMesg(client->mq, scheduler, OS_MESG_NOBLOCK);
            }
        }
    }
    scheduler->unk29C++;
    scheduler->unk2A0++;
    D_801A72DC |= 8;
    D_801819A8 = osGetTime();
}

void Scheduler_HandleRspMesg(Scheduler* scheduler) {
    SchedulerTask* curRspTask;
    SchedulerTask* rspTask = NULL;
    SchedulerTask* rdpTask = NULL;
    s32 avail;

    curRspTask = scheduler->curRSPTask;
    scheduler->curRSPTask = NULL;

    if ((curRspTask->state & 0x10) && (osSpTaskYielded(&curRspTask->list) != 0)) {
        curRspTask->state |= 0x20;
        if ((curRspTask->flags & 7) == 3) {
            curRspTask->next = scheduler->gfxListHead;
            scheduler->gfxListHead = curRspTask;
            if (scheduler->gfxListTail == 0) {
                scheduler->gfxListTail = curRspTask;
            }
        }
    } else {
        curRspTask->state &= ~2;
        Scheduler_IsTaskComplete(scheduler, curRspTask);
    }
    avail = ((scheduler->curRSPTask == NULL) * 2) | (scheduler->curRDPTask == 0);
    if (Scheduler_ScheduleTask(scheduler, &rspTask, &rdpTask, avail) != avail) {
        Scheduler_ExecuteTask(scheduler, rspTask, rdpTask);
    }
}

void Scheduler_HandleRdpMesg(Scheduler* arg0) {
    SchedulerTask* rspTask;
    SchedulerTask* sp20;
    SchedulerTask* sp1C;
    s32 taskState;

    sp20 = NULL;
    sp1C = NULL;
    rspTask = arg0->curRDPTask;
    arg0->curRDPTask = NULL;
    rspTask->state &= ~1;
    Scheduler_IsTaskComplete(arg0, rspTask);

    taskState = ((arg0->curRSPTask == NULL) << 1) | (arg0->curRDPTask == NULL);
    if (Scheduler_ScheduleTask(arg0, &sp20, &sp1C, taskState) != taskState) {
        Scheduler_ExecuteTask(arg0, sp20, sp1C);
    }
}

/*
 * Checks to see if the graphics task is able to run
 * based on the current state of the RCP.
 *
 */
SchedulerTask* Scheduler_IsTaskReady(SchedulerTask* task) {
    s32 rv = 0;
    void* currentFrameBuf;
    void* nextFrameBuf;

    if (task) {
        /*
         * If there is a pending swap bail out until later (next retrace).
         */
        if ((currentFrameBuf = osViGetCurrentFramebuffer()) != (nextFrameBuf = osViGetNextFramebuffer())) {
            return NULL;
        }
        return task;
    }

    return NULL;
}

s32 Scheduler_IsTaskComplete(UNUSED Scheduler* scheduler, SchedulerTask* task) {
    UNUSED s32 ret;
    static int firstTime = TRUE;

    if (!(task->state & 3)) {
        ret = osSendMesg(task->msgQ, task->msg, OS_MESG_BLOCK);
        if (task->list.t.type == M_GFXTASK) {
            if ((task->flags & 0x40) && (task->flags & 0x20)) {
                if (firstTime) {
                    osViBlack(FALSE);
                    firstTime = FALSE;
                }
                osViSwapBuffer(task->framebuffer);
            }
        }
        return TRUE;
    }
    return FALSE;
}

void Scheduler_AppendTask(Scheduler* scheduler, SchedulerTask* task) {
    s32 taskType;

    taskType = task->list.t.type;
    if (taskType == M_AUDTASK) {
        if (scheduler->audioListTail != NULL) {
            scheduler->audioListTail->next = task;
        } else {
            scheduler->audioListHead = task;
        }
        scheduler->audioListTail = task;
        scheduler->doAudio = TRUE;
    } else {
        if (scheduler->gfxListTail != NULL) {
            scheduler->gfxListTail->next = task;
        } else {
            scheduler->gfxListHead = task;
        }
        scheduler->gfxListTail = task;
    }
    task->next = NULL;
    task->state = task->flags & OS_SC_RCP_MASK;
}

void Scheduler_ExecuteTask(Scheduler* scheduler, SchedulerTask* rspTask, SchedulerTask* rdpTask) {
    s32 ret;

    if (rspTask != NULL) {
        if (rspTask->list.t.type == M_AUDTASK) {
            osWritebackDCacheAll();
        }
        rspTask->state &= ~0x30;
        osSpTaskLoad(&rspTask->list);
        osSpTaskStartGo(&rspTask->list);
        scheduler->curRSPTask = rspTask;
        if (rspTask == rdpTask) {
            scheduler->curRDPTask = rdpTask;
        }
    }
    if ((rdpTask != NULL) && (rdpTask != rspTask)) {
        ret = osDpSetNextBuffer(rdpTask->list.t.output_buff, *rdpTask->list.t.output_buff_size);
        sDpBusy = 1;
        sDpCount = 0;
        scheduler->curRDPTask = rdpTask;
    }
}

void Scheduler_RspTaskYield(Scheduler* scheduler) {
    if (scheduler->curRSPTask->list.t.type == M_GFXTASK) {
        scheduler->curRSPTask->state |= SCHEDULER_YIELD;
        osSpTaskYield();
    } else {
        /* osLogEvent */
    }
}

/*
 * Schedules tasks to be run on the RCP
 */
s32 Scheduler_ScheduleTask(Scheduler* scheduler, SchedulerTask** spTask, SchedulerTask** dpTask, s32 availRcp) {
    s32 avail;
    SchedulerTask* gfx;
    SchedulerTask* audio;

    avail = availRcp;
    gfx = scheduler->gfxListHead;
    audio = scheduler->audioListHead;
    if ((scheduler->doAudio != 0) && (avail & 2)) {
        if ((gfx != NULL) && (gfx->flags & 0x10)) {
            *spTask = (s32) gfx;
            avail &= ~2;
        } else {
            *spTask = (s32) audio;
            avail &= ~2;
            scheduler->doAudio = 0;
            scheduler->audioListHead = scheduler->audioListHead->next;
            if (scheduler->audioListHead == NULL) {
                scheduler->audioListTail = NULL;
            }
        }
    } else if (Scheduler_IsTaskReady((s32) gfx) != 0) {
        switch (gfx->flags & 7) {
            case 3:
                if (gfx->state & 0x20) {
                    if (avail & 2) {
                        *spTask = (s32) gfx;
                        avail &= ~2;
                        if (gfx->state & 1) {
                            *dpTask = (s32) gfx;
                            avail &= ~1;
                        }
                        scheduler->gfxListHead = scheduler->gfxListHead->next;
                        if (scheduler->gfxListHead == NULL) {
                            scheduler->gfxListTail = NULL;
                        }
                    }
                } else if (avail == 3) {
                    *dpTask = (s32) gfx;
                    *spTask = *dpTask;
                    avail &= ~3;
                    scheduler->gfxListHead = scheduler->gfxListHead->next;
                    if (scheduler->gfxListHead == NULL) {
                        scheduler->gfxListTail = NULL;
                    }
                }
                break;
            case 2:
            case 6:
            case 7:
                if (gfx->state & 2) {
                    if (avail & 2) {
                        *spTask = (s32) gfx;
                        avail &= ~2;
                    }
                } else if ((gfx->state & 1) && (avail & 1)) {
                    *dpTask = (s32) gfx;
                    avail &= ~1;
                    scheduler->gfxListHead = scheduler->gfxListHead->next;
                    if (scheduler->gfxListHead == NULL) {
                        scheduler->gfxListTail = NULL;
                    }
                }
                break;
            case 1:
            case 5:
            default:
                break;
        }
    }
    if (avail != availRcp) {
        avail = Scheduler_ScheduleTask(scheduler, spTask, dpTask, avail);
    }
    return avail;
}

static int sMoreDataPadding = 0;
