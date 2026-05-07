#include "common.h"

s32 func_80031AC8(void);      /* extern */
void func_8007A488(s16, s16); /* extern */
u16 func_8007A8B8(void);      /* extern */
s32 func_8007B710(s32);       /* extern */
s32 func_8007C54C(s32);       /* extern */
void func_8007D538(void);     /* extern */
s32 func_8007DF3C(s32);       /* extern */
void func_8007ECB0(u16);      /* extern */
void func_8007F878(u16);      /* extern */
void func_8007FA64(void);     /* extern */
void func_80080948(void*);    /* extern */

extern f32 D_80182530;
extern s32 D_801A70F0;
extern s32 D_801A70F8;
extern s16 D_801A7130;
extern s16 D_801A7136;
extern s16 D_801A7138;
extern s16 D_801A713A;

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_80079910.s")

s32 func_80079CCC(void) {
    u16 sp26;
    s32 sp20;
    s32 sp1C;

    sp20 = 0;
    if (D_801A713A & 1) {
        return 0;
    }
    if (func_8007C54C(0) != 0) {
        return 0;
    }
    func_8007D538();
    sp20 = func_8007B710(0);
    if (func_8007DF3C(0) != 0) {
        return 0;
    }
    if (sp20 != 0) {
        return 0;
    }
    if ((D_801A713A & 4) && !(D_801A713A & 0x10)) {
        func_8007A488(D_801A7136, D_801A7138);
        return 0;
    }
    if (D_801A7130 != 0) {
        func_8007FA64();
        return 0;
    }
    if (!(D_801A713A & 0x200) && (func_80031AC8() == 1)) {
        D_80182530 = 0.0f;
    }
    if (D_801A713A & 0x10) {
        sp1C = func_80031AC8();
        if (!(D_801A713A & 0x200) || (sp1C == 0) || (sp1C == -2)) {
            D_801A713A &= ~0x210;
            if (D_801A713A & 0x104) {
                return 0;
            }
            func_8007B710(1);
        }
        return 0;
    }
    func_80080948(&D_801A70F0);
    sp26 = func_8007A8B8();
    if (sp26 != 0) {
        if ((D_801A70F8 == 0) || (D_801A70F8 == 1)) {
            func_8007ECB0(sp26);
        }
        if ((D_801A70F8 == 2) || (D_801A70F8 == 3)) {
            func_8007F878(sp26);
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_80079F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007A0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007A488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007A514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007A8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007AA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007B12C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007B3DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007B710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007C54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007D538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007DF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007E94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007EB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007ECB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007F878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007F930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_8007FA64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_800805C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_80080698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_80080738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_800808A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_80080910.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_7A510/func_80080948.s")
