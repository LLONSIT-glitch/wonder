#ifndef SCHEDULER_H
#define SCHEDULER_H

/* types */

// A linked list of thread message queues?
typedef struct SchedulerClient {
    /* 0x0 */ struct SchedulerClient* next; /* inferred */
    /* 0x4 */ OSMesgQueue* mq;              /* inferred */
    /* 0x8 */ s32 unk8;                     /* inferred */
} SchedulerClient;                          /* size = 0xC */

typedef struct SchedulerTask_s {
    struct SchedulerTask_s* next; /* note: this must be first */
    u32 state;
    u32 flags;
    void* framebuffer; /* used by graphics tasks */
    OSTask list;
    OSMesgQueue* msgQ;
    OSMesg msg;
#ifndef _FINALROM     /* all #ifdef items should    */
    OSTime startTime; /* remain at the end!!, or    */
    OSTime totalTime; /* possible conflict if       */
#endif                /* FINALROM library used with */
} SchedulerTask;      /* non FINALROM code          */

typedef struct {
    short type;
    char  misc[30];
} SchedulerMesg;

typedef struct Scheduler_s {
    /* 0x000 */ SchedulerMesg unk0;
    /* 0x020 */ SchedulerMesg unk20;
    /* 0x040 */ SchedulerMesg unk40;
    /* 0x060 */ OSMesgQueue interruptQ;
    /* 0x078 */ void* unk78;
    /* 0x07C */ char pad7C[0x1C]; /* maybe part of unk78[8]? */
    /* 0x098 */ OSMesgQueue cmdQ;
    /* 0x0B0 */ void* unkB0;
    /* 0x0B4 */ char padB4[0x1C]; /* maybe part of unkB0[8]? */
    /* 0x0D0 */ OSThread thread;
    /* 0x280 */ SchedulerClient* clientList;
    /* 0x284 */ SchedulerTask* audioListHead;
    /* 0x288 */ SchedulerTask* gfxListHead;
    /* 0x28C */ SchedulerTask* audioListTail;
    /* 0x290 */ SchedulerTask* gfxListTail;
    /* 0x294 */ SchedulerTask* curRSPTask;
    /* 0x298 */ SchedulerTask* curRDPTask;
    /* 0x29C */ s32 unk29C;
    /* 0x2A0 */ s32 unk2A0;
    /* 0x2A4 */ s32 doAudio; /* inferred */
} Scheduler;                /* size = 0x2A8 */

/* TODO: Classify private and public functions */
void Scheduler_AppendTask(Scheduler* scheduler, SchedulerTask* task);
void Scheduler_CreateScheduler(Scheduler* scheduler, u8 arg1, s32 arg2);
void Scheduler_CreateSchedulerThread(Scheduler* scheduler, void* sp, OSPri pri);
void Scheduler_ExecuteTask(Scheduler* scheduler, SchedulerTask* rspTask, SchedulerTask* rdpTask);
void Scheduler_HandleRdpMesg(Scheduler* arg0);
void Scheduler_HandleRspMesg(Scheduler* scheduler);
void Scheduler_HandleVideoMesg(Scheduler* scheduler);
s32 Scheduler_IsTaskComplete(UNUSED Scheduler* scheduler, SchedulerTask* task);
SchedulerTask* Scheduler_IsTaskReady(SchedulerTask* task);
void Scheduler_RemoveClient(Scheduler* scheduler, SchedulerClient* client);
void Scheduler_RspTaskYield(Scheduler* scheduler);
s32 Scheduler_ScheduleTask(Scheduler* scheduler, SchedulerTask** spTask, SchedulerTask** dpTask, s32 availRcp);
void Scheduler_Thread(void* arg);
UNUSED void func_800970CC(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq);
void func_80097150(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq);
void func_800971D4(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq);
void func_80097258(Scheduler* arg0, SchedulerClient* arg1, OSMesgQueue* mq);
void func_800972DC(SchedulerClient* arg0);
void func_800972FC(SchedulerClient* arg0);
s32 func_80097408(Scheduler* arg0);
void func_80097420(Scheduler* scheduler);
void func_80097498(void);
void func_800974C0(Scheduler* arg0);
#endif /* SCHEDULER_H */
