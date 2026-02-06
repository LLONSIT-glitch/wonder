#include "common.h"

UnkStruct_8000DDE0* func_800045AC(s32);               /* extern */
void func_8000BB00(void);                                  /* extern */
void func_8000C3B0(UnkStruct_8000DDE0*);               /* extern */
void func_800198F8(UnkStruct_80099E2C*, s32);            /* extern */
void func_80021F20(s32);                                 /* extern */
extern UnkStruct_801561D8 D_801561D8[];

s32 func_80009FA4(UnkStruct_8000DDE0* arg0);

s32 func_80009F70(UnkStruct_8000DDE0 *arg0) {
    *D_801A8D88 |= 0x1000;
    arg0->unk1A8 = 0;
    return 0;
}

s32 func_80009FA4(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000DDE0* sp24;

    sp24 = NULL;
    if (D_801A8C34 != -1) {
        sp24 = func_80016074(D_801A8C34);
    }
    switch (D_801A8C58) {                           /* irregular */
    case 0x32:
    case 0x33:
    case 0x1F6:
        break;
    case 0x1F4:
        if ((sp24 == NULL) || !(sp24->unk1A8 & 1)) {
            if (!(arg0->unk1A8 & 1) && (gControllers->unk6 & (u16) gInputMask_Start)) {
                func_800198F8(&arg0->unk0, 0);
                sp24 = func_800045AC(3);
                if (sp24 != NULL) {
                    sp24->unk1A8 |= 1;
                    func_8000BB00();
                    func_8000C3B0(sp24);
                }
                D_801A7254 = 0xB;
                D_801A725C = 0x18;
                arg0->unk1A8 |= 1;
                D_801A8C34 = 0xF;
                D_801A8D88[1] = 0;
                D_8015BAF8 = -4.0f;
                D_8015BB08 = 0x140;
                D_8015BB0C = 0xF0;
                D_8015BB10 = 0.0f;
                D_8015BB14 = 10.0f;
                D_8015BB18 = 0.0f;
                func_80022124();
                func_80021F20(0x40);
                arg0->unk0.unkC8 = 0x7FFFFFFF;
                arg0->unk0.unkC0 |= 0x48;
                arg0->unk0.unkC4 = 0x10;
                sp24 = func_80016074(0xF);
                if (sp24 != NULL) {
                    sp24->unk0.unkC4 = 0x10;
                }
                D_801561D8[4].unk114 = 2.0f;
                D_801561D8[4].unk11C = 225.0f;
                D_801561D8[5].unk114  = 0.0f;
                D_801561D8[5].unk11C = 1.0f;
                D_801561D8[3].unk114 = 0.0f;
                D_801561D8[3].unk11C = 1.0f;
            }
            break;
        }
    }
    if (arg0->unk1A8 & 1) {
        MtxUtil_PushIdentity();
        func_8009A14C(&arg0->unk0);
        func_800997D8(arg0);
        MtxUtil_Pop();
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AB70/func_8000A2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AB70/func_8000B194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AB70/func_8000B260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AB70/func_8000B2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AB70/func_8000B340.s")
