#include "common.h"

extern u16 D_8015F888;
extern f32 D_80160430;
extern f32 D_80160438;
extern f32 D_80160440;

f32 func_800C3650(f32);                             /* extern */


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF060.s")

// NEEDS RODATA
extern f64 D_800EF920;

void func_800AF184(f32 arg0, f32 arg1, f32 arg2) {
    D_80160430 = arg0;
    D_80160438 = arg1;
    D_80160440 = func_800C3650((f32) ((f64) arg2 * D_800EF920));
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AFAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AFB28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AFB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B08FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B0A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B0D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B0E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B0E88.s")

void func_800B1250(Gfx** arg0, LookAtParams* arg1, u16 arg2) {
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    MtxF sp28;
    Vec3f* sp24;                                    /* compiler-managed */
    Vec3f* sp20;
    Gfx* sp1C;

    sp24 = &arg1->unk18;
    sp70 = sp24->x;
    sp6C = sp24->y;
    sp68 = sp24->z;
    sp24 = &arg1->unk24;
    sp88 = sp24->x;
    sp84 = sp24->y;
    sp80 = sp24->z;
    sp24 = &arg1->unk0;
    sp20 = &arg1->unkC;
    
    spA0 = (sp24->x * sp70) - (sp7C = sp20->x * sp70);
    sp9C = (sp24->y * sp6C) - (sp78 =  sp20->y * sp6C);
    sp98 = (sp24->z * sp68) - (sp74 = sp20->z * sp68);
    spA4 = -1.0 / sqrtf((spA0 * spA0) + (sp9C * sp9C) + (sp98 * sp98));
    spA0 *= spA4;
    sp9C = sp9C * spA4;

    sp98 =  sp98 * spA4;
    sp94 = (sp84 * sp98) - (sp80 * sp9C);
    sp90 = (sp80 * spA0) - (sp88 * sp98);
    sp8C = (sp88 * sp9C) - (sp84 * spA0);
    spA4 = 1.0 / sqrtf((sp94 * sp94) + (sp90 * sp90) + (sp8C * sp8C));
    sp94 *= spA4;
    sp90 = sp90 * spA4;
    sp8C = sp8C * spA4;
    sp88 = (sp9C * sp8C) - (sp98 * sp90);
    sp84 = (sp98 * sp94) - (spA0 * sp8C);
    sp80 = (spA0 * sp90) - (sp9C * sp94);
    spA4 = 1.0 / sqrtf((sp88 * sp88) + (sp84 * sp84) + (sp80 * sp80));
    sp88 = sp88 * spA4;
    sp84 *= spA4;
    sp80 *= spA4;
    sp28.mf[0][0] = sp94;
    sp28.mf[1][0] = sp90;
    sp28.mf[2][0] = sp8C;
    sp28.mf[3][0] = -((sp7C * sp94) + (sp78 * sp90) + (sp74 * sp8C));
    sp28.mf[0][1] = sp88;
    sp28.mf[1][1] = sp84;
    sp28.mf[2][1] = sp80;
    sp28.mf[3][1] = -((sp7C * sp88) + (sp78 * sp84) + (sp74 * sp80));
    sp28.mf[0][2] = spA0;
    sp28.mf[1][2] = sp9C;
    sp28.mf[2][2] = sp98;
    sp28.mf[3][2] = -((sp7C * spA0) + (sp78 * sp9C) + (sp74 * sp98));
    sp28.mf[0][3] = 0.0f;
    sp28.mf[1][3] = 0.0f;
    sp28.mf[2][3] = 0.0f;
    sp28.mf[3][3] = 1.0f;
    if (arg2 == 0) {
        func_800C1850(0);
    }
    func_800C2948(sp70, sp6C, sp68);
    func_800C1D44(&sp28);
    func_800C2AE8(&D_8015F884[D_8015F888]);
    sp1C = *arg0;
    gSPMatrix(sp1C++, VIRTUAL_TO_PHYSICAL(&D_8015F884[D_8015F888++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    *arg0 = sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B1844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B18C4.s")
