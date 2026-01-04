#include "common.h"

extern u64* D_801869C8;
extern s16 D_80182518;
extern f32 D_80182530;
extern s16 D_80182570;
extern s32 D_801879D0[];

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002D3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002D598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002D798.s")



void func_8002DA1C(void) {
    s16 sp6;
    u64* sp0;

    sp0 = D_801869C8;

    for (sp6 = 0; sp6 < 0x41; sp6++) {
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
        *sp0++ = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002DC14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002E414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002EAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002EC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002ED14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8002F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80030438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_800305A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_8003168C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_800317E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_800319B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031AB8.s")


s32 func_80031AC8(void) {
    if (D_80182518 < 0x1F) {
        return -2;
    }
    if ((D_80182518 == 0x28) && (D_801879D0[D_80182570] == 0)) {
        return 0;
    }
    if (D_80182530 != 0.0) {
        return 1;
    }
    
    return -1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_2DFB0/func_80031C6C.s")
