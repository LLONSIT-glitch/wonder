#include "common.h"


void func_800ADC50(ThreadEntry* arg0);
void func_800AE40C(void); /* extern */
void ContPak_DeleteFile(void); /* extern */
void ContPak_OpenFile(void); /* extern */
void func_800AEB14(void); /* extern */
void ContPak_WriteFile(void);     /* extern */
void ContPak_ReadFile(void);      /* extern */

extern s32 D_80180DAC;
extern s32 D_80180DAE;
extern s32 D_80180DB0;
extern s32 D_80180DB4;
extern s32 D_80180DBC;
extern s32 D_80180DC0;
extern s32 D_80180DC4;
extern s32 D_8018128C;
extern s16 D_801816A0;
extern s16 D_801816C8;
extern s16 D_801819B0;
extern s32 D_801824D4;

// Might be part of UnkStruct_800F9C38?
typedef struct UnkStruct_800EF900_s {
    char pad[0x20];
} UnkStruct_800EF900;
extern UnkStruct_800EF900 D_800EF900;

void func_800AD800(void) {
    ThreadEntry* sp3C;
    UnkStruct_800F9C38* sp38;
    void* sp34;
    s32 sp30;

    gCurrentPakOperationFlags = 0;
    D_80180E68 = 0x800;
    D_80180E74 = 0x400;
    D_80180EC0 = 0x200;
    D_80180EEC = 0x100;
    D_80180FF4 = 0x8000;
    D_8018101C = 0x4000;
    D_80181038 = 0x20;
    D_80181042 = 0x10;
    D_801810F2 = 0x2000;
    D_801811A4 = 0x1000;
    D_801811AC = 8;
    D_80181258 = 4;
    D_80181260 = 2;
    D_8018126C = 1;
    D_80180E50 = 70.0f;
    D_80180E5C = 70.0f;
    for (sp30 = 0; sp30 < 4; sp30++) {
        D_80180DA8[sp30].state = 0;
        D_80180DA8[sp30].unk18 = D_80180E50;
        D_80180DA8[sp30].unk1C = D_80180E5C;

        D_80180DA8[sp30].button = D_80180DA8[sp30].unk6 = D_80180DA8[sp30].unk8 = D_80180DA8[sp30].unkA =
            D_80180DA8[sp30].unkC = 0;

        D_80180DA8[sp30].stickX = D_80180DA8[sp30].stickY = 0.0f;
    }
    D_801824D4 = 1;
    D_8018128C = 0;
    sp3C = Thread_CreateExtended((void (*)(void*)) func_800ADC50, 0x35);
    sp38 = sp3C->unk18;
    gSysThreadIds[3] = (s32) sp3C->threadId;
    D_801816A0 = 2;
    D_801816C8 = 1;
    D_801819B0 = 3;
    func_800C1154(sp3C->threadId, 8);
    osSetEventMesg(OS_EVENT_SI, (OSMesgQueue*) &sp38->mq, &D_801816A0);
    osContInit((OSMesgQueue*) &sp38->mq, &D_8018127C, D_80182540);

    // Check if the first conroll is a standard one
    if (D_80182540->status & CONT_ABSOLUTE) {
        D_801824D4 = 0;
        osContStartReadData((OSMesgQueue*) &sp38->mq);

        // Wait for completion message from osContStartReadData
        Thread_ReceiveMsgInThread(sp3C->threadId, &sp34, OS_MESG_BLOCK);
        osContGetReadData(D_80182558);
        func_800AE0EC(&sp38->mq);
        func_800AE40C();
        D_801824D4 = 1;
    }
    Thread_Start(sp3C->threadId);
}

void func_800ADC50(ThreadEntry* arg0) {
    ThreadEntry* sp60;
    UnkStruct_800F9C38* sp58;
    s16* sp54;
    s32 pad[3];
    UnkStruct_800EF900 sp28;

    sp28 = D_800EF900;

    sp60 = arg0;
    sp58 = sp60->unk18;

    while (TRUE) {
        if (D_801824D4 != 0) {
            D_801824D4 = 0;
            if (gCurrentPakOperationFlags & 2) {
                func_800AE0EC(&sp58->mq);
                func_800AE40C();
            } else if (gCurrentPakOperationFlags & 0x10) {
                ContPak_DeleteFile();
            } else if (gCurrentPakOperationFlags & 0x20) {
                ContPak_OpenFile();
            } else if (gCurrentPakOperationFlags & 0x100) {
                ContPak_FindFile();
            } else if (gCurrentPakOperationFlags & 0x80) {
                ContPak_WriteFile();
            } else if (gCurrentPakOperationFlags & 0x40) {
                ContPak_ReadFile();
            }
            D_801824D4 = 1;
        }
        Thread_ReceiveMsgInThread(sp60->threadId, (void**) &sp54, 1);
        switch (*sp54) { /* irregular */
            case 2:
                osContGetReadData(D_80182558);
                D_801824D4 = 1;
                continue;
            case 1:
                osContStartReadData(&sp58->mq);
                D_801824D4 = 0;
                continue;
            case 4:
                while (TRUE) {
                    Thread_ReceiveMsgInThread(sp60->threadId, (void**) &sp54, 1);
                }
                continue;
        }
        continue;
    }
}
