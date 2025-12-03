/*
 * @file code_22AD0.c
 * @brief This file seems to be a wrapper of the sound manager located in code_BA180s
 */
#include "common.h"

extern UnkStruct_801AE5A0* func_800BB448(s32 arg0);
extern void func_800BB4B4(UnkStruct_801AE5A0* arg0, s32 arg1);
extern void func_800BB3D4(s32);                /* extern */
extern void func_800BB52C(s32, s32, s32, s32); /* extern */
extern void func_800BB4DC(s32);                /* extern */

void func_80021ED0(s32 arg0) {
    D_801ACC44 = arg0;
    func_800BB52C(0, 0x7FFF, 0x7FFF, 0);
    func_800BB3D4(arg0);
}

void func_80021F20(u16 arg0) {
    func_800BB52C(-1, 0x7FFF / (s32) arg0, 0, 1);
}

void func_80021F8C(u16 arg0) {
    func_800BB52C(0, 0x7FFF / (s32) arg0, 0x7FFF, 0);
}

void func_80021FF8(s32 arg0, u16 arg1, s32 arg2) {
    func_800BB52C(arg0, 0x7FFF / (s32) arg1, arg2, 0);
}

s32 func_8002206C(s32 arg0, s32 arg1, u8 arg2) {
    UnkStruct_801AE5A0* sp1C;

    sp1C = func_800BB448(arg0);
    if (sp1C == NULL) {
        return -1;
    }
    sp1C->unkC = arg1;
    sp1C->unk1A = arg2;
    func_800BB4B4(sp1C, 4);
    return 0;
}

void func_800220F4(s32 arg0) {
    func_800BB4DC(arg0);
}

void func_80022124(void) {
    func_800BB4DC(-1);
}
