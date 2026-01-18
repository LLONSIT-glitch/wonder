#include "common.h"


void func_800ADC50(ThreadEntry* arg0);
void func_800AEB14(void); /* extern */

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
    gInputMask_DPadUp = U_JPAD;
    gInputMask_DPadDown = D_JPAD;
    gInputMask_DPadLeft = L_JPAD;
    gInputMask_DPadRight = R_JPAD;
    gInputMask_A = A_BUTTON;
    gInputMask_B = B_BUTTON;
    gInputMask_L = L_TRIG;
    gInputMask_R = R_TRIG;
    gInputMask_Z = Z_TRIG;
    gInputMask_Start = START_BUTTON;
    gInputMask_CUp = U_CBUTTONS;
    gInputMask_CDown = D_CBUTTONS;
    gInputMask_CLeft = L_CBUTTONS;
    gInputMask_CRight = R_CBUTTONS;
    gControllerStickXScale = 70.0f;
    gControllerStickYScale = 70.0f;
    for (sp30 = 0; sp30 < 4; sp30++) {
        gControllerRaw[sp30].state = 0;
        gControllerRaw[sp30].stickScaleX = gControllerStickXScale;
        gControllerRaw[sp30].stickScaleY = gControllerStickYScale;

        gControllerRaw[sp30].button = gControllerRaw[sp30].unk6 = gControllerRaw[sp30].unk8 = gControllerRaw[sp30].unkA =
            gControllerRaw[sp30].unkC = 0;

        gControllerRaw[sp30].stickX = gControllerRaw[sp30].stickY = 0.0f;
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
    osContInit((OSMesgQueue*) &sp38->mq, &gContPakBitPattern, gContStatus);

    // Check if the first conroll is a standard one
    if (gContStatus->status & CONT_ABSOLUTE) {
        D_801824D4 = 0;
        osContStartReadData((OSMesgQueue*) &sp38->mq);

        // Wait for completion message from osContStartReadData
        Thread_ReceiveMsgInThread(sp3C->threadId, &sp34, OS_MESG_BLOCK);
        osContGetReadData(gContPad);
        ContPak_InitializePak(&sp38->mq);
        ContPak_UpdateFilesState();
        D_801824D4 = 1;
    }
    Thread_Start(sp3C->threadId);
}

void func_800ADC50(ThreadEntry* entry) {
    ThreadEntry* threadEntry;
    UnkStruct_800F9C38* sp58;
    s16* mesg;
    s32 pad[3];
    UnkStruct_800EF900 sp28;

    sp28 = D_800EF900;

    threadEntry = entry;
    sp58 = threadEntry->unk18;

    while (TRUE) {
        if (D_801824D4 != 0) {
            D_801824D4 = 0;
            if (gCurrentPakOperationFlags & 2) {
                ContPak_InitializePak(&sp58->mq);
                ContPak_UpdateFilesState();
            } else if (gCurrentPakOperationFlags & FLAGS_PAK_DELETE_FILE) {
                ContPak_DeleteFile();
            } else if (gCurrentPakOperationFlags & FLAGS_PAK_OPEN_FILE) {
                ContPak_OpenFile();
            } else if (gCurrentPakOperationFlags & FLAGS_PAK_FIND_FILE) {
                ContPak_FindFile();
            } else if (gCurrentPakOperationFlags & FLAGS_PAK_WRITE_FILE) {
                ContPak_WriteFile();
            } else if (gCurrentPakOperationFlags & FLAGS_PAK_READ_FILE) {
                ContPak_ReadFile();
            }
            D_801824D4 = 1;
        }
        Thread_ReceiveMsgInThread(threadEntry->threadId, (void**) &mesg, OS_MESG_BLOCK);
        switch (*mesg) { /* irregular */
            case 2:
                osContGetReadData(gContPad);
                D_801824D4 = 1;
                continue;
            case 1:
                osContStartReadData(&sp58->mq);
                D_801824D4 = 0;
                continue;
            case 4:
                while (TRUE) {
                    Thread_ReceiveMsgInThread(threadEntry->threadId, (void**) &mesg, OS_MESG_BLOCK);
                }
                continue;
        }
        continue;
    }
}
