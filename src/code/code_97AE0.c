/*
* @file scheduler.c
* @brief Seems to be a modified version of libultra's RSP schedulere implementation (sched.c)
*/
#include "common.h"

extern s32 D_801A72BC;
extern s32 D_801A72CC;
extern s16 D_801A72F0;

void func_80097D44(Scheduler* arg0, Scheduler_unk284* arg1);

void func_80096EE0(Scheduler* arg0, u8 arg1, s32 arg2) {
    arg0->unk294 = 0;
    arg0->unk298 = 0;
    arg0->unk280 = 0;
    arg0->unk29C = 0;
    arg0->unk2A0 = 0;
    arg0->unk284 = 0;
    arg0->unk288 = 0;
    arg0->unk28C = 0;
    arg0->unk290 = 0;
    arg0->unk0 = 1;
    arg0->unk20 = 4;
    arg0->unk40 = 5;
    D_801A72F0 = 6;
    D_801A72BC = 0;
    D_801A72CC = 0;
    D_801A72DC = 0;
    osCreateMesgQueue(&arg0->unk60, &arg0->unk78, 8);
    osCreateMesgQueue(&arg0->unk98, &arg0->unkB0, 8);
    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&osViModeTable[arg1]);
    osViBlack(TRUE);
    osSetEventMesg(OS_EVENT_SP, &arg0->unk60, (void*) 0x29B);
    osSetEventMesg(OS_EVENT_DP, &arg0->unk60, (void*) 0x29C);
    osSetEventMesg(OS_EVENT_PRENMI, &arg0->unk60, (void*) 0x29D);
    osViSetEvent(&arg0->unk60, (void*) 0x29A, (u32) (u8) arg2);
}

void func_80097068(Scheduler* arg0, void* arg1, s32 arg2) {
    osCreateThread(&arg0->unkD0, 4, (void (*)(void*)) func_8009756C, arg0, arg1, arg2);
    osStartThread(&arg0->unkD0);
}

UNUSED void func_800970CC(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);

    arg1->mq = mq;
    arg1->next = arg0->unk280;
    arg1->unk8 = 0;
    arg0->unk280 = arg1;
    osSetIntMask(imask);
}

void func_80097150(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);
    arg1->mq = mq;
    arg1->next = arg0->unk280;
    arg1->unk8 = 2;
    arg0->unk280 = arg1;
    osSetIntMask(imask);
}

void func_800971D4(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);
    arg1->mq = mq;
    arg1->next = arg0->unk280;
    arg1->unk8 = 1;
    arg0->unk280 = arg1;
    osSetIntMask(imask);
}

void func_80097258(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq) {
    u32 imask = osSetIntMask(OS_IM_NONE);
    arg1->mq = mq;
    arg1->next = arg0->unk280;
    arg1->unk8 = 8;
    arg0->unk280 = arg1;
    osSetIntMask(imask);
}

void func_800972DC(SchedulerClient* arg0) {
    arg0->unk8 |= 4;
}

void func_800972FC(SchedulerClient* arg0) {
    arg0->unk8 &= ~4;
}

void func_8009731C(Scheduler* arg0, SchedulerClient* arg1) {
    SchedulerClient* sp24;
    SchedulerClient* sp20; /* compiler-managed */
    u32 mask;

    sp24 = arg0->unk280;
    sp20 = NULL;
    mask = osSetIntMask(OS_IM_NONE);

    while (sp24 != NULL) {
        if (sp24 == arg1) {
            if (sp20 != NULL) {
                sp20->next = arg1->next;
            } else {
                arg0->unk280 = arg1->next;
            }
            break;
        }
        sp20 = sp24;
        sp24 = sp24->next;
    }
    osSetIntMask(mask);
}

s32 func_80097408(Scheduler* arg0) {
    return (s32) &arg0->unk98;
}

void func_80097420(Scheduler* arg0) {
    SchedulerClient* sp4;

    for (sp4 = arg0->unk280; sp4 != NULL; sp4 = sp4->next) {
        if (!(sp4->unk8 & 1)) {
            sp4->mq->validCount = 0;
        }
    }
}

void func_80097498(void) {
    D_801A72DC &= ~8;
}

void func_800974C0(Scheduler* arg0) {
    s32 threadCount;
    SchedulerClient* sp18;

    for (threadCount = 0, sp18 = arg0->unk280; sp18 != NULL; sp18 = sp18->next) {
        if (sp18->unk8 & 8) {
            osSendMesg((OSMesgQueue*) sp18->mq, arg0, OS_MESG_NOBLOCK);
            threadCount++;
        }
    }
    if (threadCount != 0) {
        osYieldThread();
    }
}

void func_8009756C(Scheduler* arg0) {
    OSMesg sp2C;
    Scheduler* sp28;
    SchedulerClient* sp24;

    sp28 = arg0;
    while (TRUE) {
        osRecvMesg(&sp28->unk60, &sp2C, 1);
        switch ((s32) sp2C) { /* irregular */
            case 0x29A:
                func_8009769C(sp28);
                guRandom();
                break;
            case 0x29B:
                func_80097988(sp28);
                guRandom();
                break;
            case 0x29C:
                func_80097B0C(sp28);
                guRandom();
                break;
            case 0x29D:
                for (sp24 = sp28->unk280; sp24 != NULL; sp24 = sp24->next) {
                    osSendMesg((OSMesgQueue*) sp24->mq, &sp28->unk20, 0);
                }
                break;
        }
    }
}

void func_8009769C(Scheduler* arg0) {
    void* sp2C;
    SchedulerClient* sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = 0;
    if (osRecvMesg(&arg0->unk98, &sp2C, 0) != -1) {
        do {
            func_80097D44(arg0, sp2C);
        } while (osRecvMesg(&arg0->unk98, &sp2C, 0) != -1);
    }
    if ((arg0->unk2A4 != 0) && (arg0->unk294 != 0)) {
        func_80097F04(arg0);
    } else {
        sp20 = ((arg0->unk294 == 0) * 2) | (arg0->unk298 == 0);
        if (func_80097F78(arg0, &sp1C, &sp18, sp20) != sp20) {
            func_80097DDC(arg0, sp1C, sp18);
        }
    }
    if (!(D_801A72DC & 1)) {
        for (sp28 = arg0->unk280; sp28 != NULL; sp28 = sp28->next) {
            if (!(sp28->unk8 & 8)) {
                osSendMesg(sp28->mq, arg0, 0);
            }
        }
    } else if (!(D_801A72DC & 2)) {
        for (sp28 = arg0->unk280; sp28 != NULL; sp28 = sp28->next) {
            if (!(sp28->unk8 & 8)) {
                osSendMesg(sp28->mq, &arg0->unk40, 0);
            }
        }
    } else {
        D_801A72DC &= ~2;
        for (sp28 = arg0->unk280; sp28 != NULL; sp28 = sp28->next) {
            if (!(sp28->unk8 & 8)) {
                osSendMesg(sp28->mq, arg0, 0);
            }
        }
    }
    arg0->unk29C += 1;
    arg0->unk2A0 += 1;
    D_801A72DC |= 8;
    D_801819A8 = osGetTime();
}

void func_80097988(Scheduler* arg0) {
    Scheduler_unk298* sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = 0;
    sp1C = 0;
    sp24 = arg0->unk294;
    arg0->unk294 = NULL;
    if ((sp24->unk4 & 0x10) && (osSpTaskYielded(&sp24->unk10) != 0)) {
        sp24->unk4 |= 0x20;
        if ((sp24->unk8 & 7) == 3) {
            sp24->unk0 = arg0->unk288;
            arg0->unk288 = (s32) sp24;
            if (arg0->unk290 == 0) {
                arg0->unk290 = (s32) sp24;
            }
        }
    } else {
        sp24->unk4 &= ~2;
        func_80097C5C(arg0, (s32) sp24);
    }
    sp18 = ((arg0->unk294 == NULL) * 2) | (arg0->unk298 == 0);
    if (func_80097F78(arg0, &sp20, &sp1C, sp18) != sp18) {
        func_80097DDC(arg0, sp20, sp1C);
    }
}

void func_80097B0C(Scheduler* arg0) {
    Scheduler_unk298* sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = 0;
    sp1C = 0;
    sp24 = arg0->unk298;
    arg0->unk298 = NULL;
    sp24->unk4 &= ~1;
    func_80097C5C(arg0, sp24);
    sp18 = ((arg0->unk294 == NULL) * 2) | (arg0->unk298 == NULL);
    if (func_80097F78(arg0, &sp20, &sp1C, sp18) != sp18) {
        func_80097DDC(arg0, sp20, sp1C);
    }
}

/*
*
* Check if the framebuffer is changed
*
*/
s32 func_80097BDC(s32 changed) {
    UNUSED s32 unkVar;
    UNUSED void* unusedTemp;
    void* nextFrameBuf;
    register void* curFrameBuf;

    unkVar = 0;

    if (changed) {
        curFrameBuf = osViGetCurrentFramebuffer(),
        unusedTemp = curFrameBuf, // This looks super fake
            nextFrameBuf = osViGetNextFramebuffer();

        if (nextFrameBuf != curFrameBuf) {
            return FALSE;
        }

        return changed;
    }
    return FALSE;
}

extern s32 D_800E8CBC;

s32 func_80097C5C(Scheduler* arg0, Scheduler_unk298* arg1) {
    UNUSED s32 sp1C;

    if (!(arg1->unk4 & 3)) {
        sp1C = osSendMesg(arg1->unk50, arg1->unk54, 1);
        if (arg1->unk10.t.type == 1) {
            if ((arg1->unk8 & 0x40) && (arg1->unk8 & 0x20)) {
                if (D_800E8CBC != 0) {
                    osViBlack(0U);
                    D_800E8CBC = 0;
                }
                osViSwapBuffer(arg1->unkC);
            }
        }
        return 1;
    }
    return 0;
}

void func_80097D44(Scheduler* arg0, Scheduler_unk284* arg1) {
    s32 sp4;

    sp4 = arg1->unk10;
    if (sp4 == 2) {
        if (arg0->unk28C != NULL) {
            arg0->unk28C->unk0 = arg1;
        } else {
            arg0->unk284 = arg1;
        }
        arg0->unk28C = arg1;
        arg0->unk2A4 = 1;
    } else {
        if (arg0->unk290 != NULL) {
            arg0->unk290->unk0 = arg1;
        } else {
            arg0->unk288 = arg1;
        }
        arg0->unk290 = arg1;
    }
    arg1->unk0 = NULL;
    arg1->unk4 = arg1->unk8 & 3;
}

extern s32 D_800E8CB4;
extern s32 D_800E8CB8;

void func_80097DDC(Scheduler* arg0, Scheduler_unk298* arg1, Scheduler_unk298* arg2) {
    s32 sp1C;
    void* temp_t9;

    if (arg1 != NULL) {
        if (arg1->unk10.t.type == 2) {
            osWritebackDCacheAll();
        }
        arg1->unk4 &= ~0x30;
        osSpTaskLoad(&arg1->unk10);
        osSpTaskStartGo(&arg1->unk10);
        arg0->unk294 = (void*)arg1; // TODO: Scheduler_unk298 and Scheduler_unk294 are probably the same thing
        if (arg1 == arg2) {
            arg0->unk298 = (Scheduler_unk298*) arg2;
        }
    }
    if ((arg2 != NULL) && (arg2 != arg1)) {
        sp1C = osDpSetNextBuffer(arg2->unk10.t.output_buff, *arg2->unk10.t.output_buff_size);
        D_800E8CB4 = 1;
        D_800E8CB8 = 0;
        arg0->unk298 = (Scheduler_unk298*) arg2;
    }
}

void func_80097F04(Scheduler* arg0) {
    if (arg0->unk294->unk10.t.type == 1) {
        arg0->unk294->unk4 |= 0x10;
        osSpTaskYield();
    } else {
    }
}

s32 func_80097F78(Scheduler* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 sp24;
    Scheduler_unk284* sp20;
    Scheduler_unk284* sp1C;
    s32 temp_t5;

    sp24 = arg3;
    sp20 = arg0->unk288;
    sp1C = arg0->unk284;
    if ((arg0->unk2A4 != 0) && (sp24 & 2)) {
        if ((sp20 != NULL) && (sp20->unk8 & 0x10)) {
            *arg1 = (s32) sp20;
            sp24 &= ~2;
        } else {
            *arg1 = (s32) sp1C;
            sp24 &= ~2;
            arg0->unk2A4 = 0;
            arg0->unk284 = arg0->unk284->unk0;
            if (arg0->unk284 == NULL) {
                arg0->unk28C = NULL;
            }
        }
    } else if (func_80097BDC((s32) sp20) != 0) {
        switch (sp20->unk8 & 7) {
        case 3:
            if (sp20->unk4 & 0x20) {
                if (sp24 & 2) {
                    *arg1 = (s32) sp20;
                    sp24 &= ~2;
                    if (sp20->unk4 & 1) {
                        *arg2 = (s32) sp20;
                        sp24 &= ~1;
                    }
                    arg0->unk288 = arg0->unk288->unk0;
                    if (arg0->unk288 == NULL) {
                        arg0->unk290 = NULL;
                    }
                }
            } else if (sp24 == 3) {
                *arg2 = (s32) sp20;
                *arg1 = *arg2;
                sp24 &= ~3;
                arg0->unk288 = arg0->unk288->unk0;
                if (arg0->unk288 == NULL) {
                    arg0->unk290 = NULL;
                }
            }
            break;
        case 2:
        case 6:
        case 7:
            if (sp20->unk4 & 2) {
                if (sp24 & 2) {
                    *arg1 = (s32) sp20;
                    sp24 &= ~2;
                }
            } else if ((sp20->unk4 & 1) && (sp24 & 1)) {
                *arg2 = (s32) sp20;
                sp24 &= ~1;
                arg0->unk288 = arg0->unk288->unk0;
                if (arg0->unk288 == NULL) {
                    arg0->unk290 = NULL;
                }
            }
            break;
        case 1:
        case 5:
        default:
            break;
        }
    }
    if (sp24 != arg3) {
        sp24 = func_80097F78(arg0, arg1, arg2, sp24);
    }
    return sp24;
}
