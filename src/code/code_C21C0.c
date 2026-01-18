#include "common.h"

extern UnkStruct_80180CE4* D_80180CE4;

extern UnkStruct_80180CE4 D_801806D0;
extern s32 D_80180CD8;

void func_800C15C0(void) {
    s32 spC;
    f32* sp8;                        /* compiler-managed */

    D_80180CE4 = &D_801806D0;
    D_80180CD8 = 0x14;
    sp8 = (f32*)D_80180CE4;
    for (spC = 16; spC > 0; spC--) {
        *sp8++ = 0.0f;
    } 
    D_80180CE4->unk0.x = D_80180CE4->unk10.y = D_80180CE4->unk20.z = D_80180CE4->unk3C = 1.0f;
}

s32 func_800C1680(void) {
    s32 spC;
    f32* sp8;                        /* compiler-managed */
    f32* sp4;                        /* compiler-managed */

    if (D_80180CD8 <= 0) {
        return -1;
    }
    sp8 = (f32*)D_80180CE4;
    D_80180CE4++;
    sp4 = (f32*)D_80180CE4;
    for (spC = 16; spC > 0; spC--) {
        *sp4++ = *sp8++;
    } 
    D_80180CD8 -= 1;
    return 0x14 - D_80180CD8;
}

s32 func_800C1754(void) {
    s32 spC;
    f32* sp8;                        /* compiler-managed */

    if (D_80180CD8 <= 0) {
        return -1;
    }
    D_80180CE4++;
    sp8 = (f32*)D_80180CE4;
    for (spC = 16; spC > 0; spC--) {
        *sp8++ = 0.0f;
    } 
    D_80180CE4->unk0.x =   D_80180CE4->unk10.y = D_80180CE4->unk20.z = D_80180CE4->unk3C = 1.0f;
    D_80180CD8 -= 1;
    return 0x14 - D_80180CD8;
}

void func_800C1850(UnkStruct_80180CE4* arg0) {
    s32 sp14;
    f32* sp10;                                       /* compiler-managed */
    UnkStruct_80180CE4* spC;

    sp10 = (f32*)arg0;
    if (arg0 == 0) {
        sp10 = (f32*)D_80180CE4;
    }
    spC = (UnkStruct_80180CE4*)sp10;
    for (sp14 = 16; sp14 > 0; sp14--) {
        *sp10++ = 0.0f;
    } 
    spC->unk0.x = spC->unk10.y = spC->unk20.z = spC->unk3C = 1.0f;
}

void func_800C1908(UnkStruct_80180CE4 *arg0) {
    UNUSED s32 pad;
    UnkStruct_80180CE4 *sp8;

    if (arg0 == NULL) {
        sp8 = D_80180CE4;
    } else {
        sp8 = arg0;
    }
    sp8->unk30.x = sp8->unk30.y = sp8->unk30.z = 0.0f;
    sp8->unk3C = 1.0f;
}

void func_800C197C(UnkStruct_80180CE4 *arg0) {
    s32 spC;
    f32 *sp8;                        /* compiler-managed */
    UnkStruct_80180CE4 *sp4;

    sp8 = (f32*)arg0;
    if (arg0 == NULL) {
        sp8 = (f32*)D_80180CE4;
    }
    sp4 = (UnkStruct_80180CE4*)sp8;
    for (spC = 0xC; spC > 0; spC--) {
        *sp8++ = 0.0f;
    } 
    sp4->unk0.x = sp4->unk10.y = sp4->unk20.z = 1.0f;
}

s32 func_800C1A28(void) {
    if (D_80180CD8 == 0x14) {
        return -1;
    }
    D_80180CD8 += 1;
    D_80180CE4--;
    return 0;
}

void func_800C1A84(f32 *arg0) {
    s32 spC;
    f32 *sp8;                        /* compiler-managed */
    f32 *sp4;

    sp8 = (f32*)D_80180CE4;
    sp4 = (f32*)arg0;

    for (spC = 16; spC > 0; spC--) {
        *sp4++ = *sp8++;
    } 
}

void func_800C1AF4(f32 *arg0) {
    s32 spC;
    f32 *sp8;                        /* compiler-managed */
    f32 *sp4;

    sp8 = (f32*)arg0;
    sp4 = (f32*)D_80180CE4;

    for (spC = 16; spC > 0; spC--) {
        *sp4++ = *sp8++;
    } 
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C1B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C1D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C1D44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2070.s")

void func_800C2304(f32 x, f32 y, f32 z) {
    Vec3f* sp4;
    UnkStruct_80180CE4* sp0;

    sp4 = &(sp0 = D_80180CE4)->unk30; // why?
    sp4->x += (sp0->unk0.x * x) + (sp0->unk10.x * y) + (sp0->unk20.x * z);
    sp4->y += (sp0->unk0.y * x) + (sp0->unk10.y * y) + (sp0->unk20.y * z);
    sp4->z += (sp0->unk0.z * x) + (sp0->unk10.z * y) + (sp0->unk20.z * z);
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C23E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C25B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/MtxFToMtx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C21C0/func_800C2F1C.s")
