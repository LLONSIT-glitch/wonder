#include "common.h"

void func_8000E3D4(UnkStruct_8000E3D4* arg0);
s32 func_8000DDE0(UnkStruct_8000DDE0* arg0);
void* TempHeap_Alloc(s32 size);          /* extern */
void func_8000D90C(UnkStruct_8000DDE0*); /* extern */
s32 func_8000DE84(UnkStruct_8000DDE0* arg0);
void func_80031728(void);                     /* extern */
s32 func_80031AC8(void);                      /* extern */
s32 func_8004A054(s32, s16*);                 /* extern */
void func_8000D74C(UnkStruct_8000DDE0*);      /* extern */
void func_8000F53C(UnkStruct_8000DDE0*);      /* extern */
void func_8000F598(UnkStruct_8000DDE0*);      /* extern */
void func_80015BD0(UnkStruct_8000DDE0*);      /* extern */
void func_8000F624(UnkStruct_8000DDE0*);      /* extern */
void func_8000FCD8(UnkStruct_8000DDE0*);      /* extern */
void func_80010150(UnkStruct_8000DDE0*);      /* extern */
void func_80010460(UnkStruct_8000DDE0*, s32); /* extern */
void func_80010734(UnkStruct_8000DDE0*);      /* extern */
void func_800108B8(UnkStruct_8000DDE0*);      /* extern */
void func_80010AC8(UnkStruct_8000DDE0*);      /* extern */
void func_80011040(UnkStruct_8000DDE0*);      /* extern */
void func_80014F38(UnkStruct_8000DDE0*);      /* extern */
void func_8000FE48(UnkStruct_8000DDE0*);      /* extern */

extern s32 D_8015F804;

s32 func_8000DDE0(UnkStruct_8000DDE0* arg0) {
    s32 temp_v0;

    arg0->unk1A8 = 0;
    arg0->unk1AC = D_8015F804;
    arg0->unk208 = -1;
    ; // Another heap allocator
    if ((arg0->unk210 = TempHeap_Alloc(0x100)) == NULL) {
        return -1;
    }
    arg0->unk20C = NULL;
    func_8000D90C(arg0);
    arg0->unk1F0 = 0.0f;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000DE84.s")

void func_8000E3D4(UnkStruct_8000E3D4* arg0) {
    arg0->unk0 = 0;
    arg0->unk2 = -1;
    arg0->unk4 = -1;
    arg0->unk6 = 0;
    arg0->unk8 = 0;
    arg0->unk14 = 0.0f;
    arg0->unk18 = 0.0f;
    arg0->unk1C = 0.0f;
    arg0->unk20 = 0.0f;
    arg0->unk24 = 255.0f;
    arg0->unk28 = 0.0f;
    arg0->unkC = NULL;
    arg0->unk10 = 0;
    arg0->unk5C = 0;
    arg0->unk60 = 0;
    arg0->unk62 = 0;
    arg0->unk64 = 0;
    arg0->unk66 = 0;
    arg0->unk68 = 0;
    arg0->unk6C = 0.0f;
    arg0->unk70 = 0.0f;
    arg0->unk74 = 0.0f;
    arg0->unk7C = 0;
    arg0->unk98 = 0.0f;
    arg0->unk9C = 0.0f;
    arg0->unkA0 = 0.0f;
    arg0->unkA4 = 0.0f;
    arg0->unkA8 = 0.0f;
    arg0->unkAC = 0.0f;
    arg0->unkB0 = 0.0f;
    arg0->unkB4 = 0.0f;
    arg0->unkB8 = 0.0f;
    arg0->unkBC = 0.0f;
    arg0->unkC0 = 0.0f;
    arg0->unkC4 = 0.0f;
}

s32 func_8000E524(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp24;
    UnkStruct_80099E2C* sp20;
    s32 sp1C;
    s16 sp1A;

    sp24 = arg0->unk20C;
    if (func_8004A054(sp24->unk7C, &sp1A) == 0) {
        return -1;
    }
    if (func_80031AC8() != -2) {
        func_800B2CBC(&sp24->unkC, &sp24->unk10, 2);
        func_80031728();
        sp24->unk62 = 0xe007;
        arg0->unk1A8 |= 0x100;
    }
    sp24->unk8 = (s32) sp1A;
    sp24->unk7C = 0;
    for (sp1C = 0, sp20 = sp24->unkC; sp1C < sp24->unk6; sp1C++, sp20++) {
        sp20->unkC8 = (s32) sp24->unk94;
    }
    sp24->unk0 = (u16) sp24->unk0 & ~1;
    return 0;
}

s32 func_8000E678(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp1C;

    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        if (arg0->unk1A8 & 4) {
            func_8000D74C(arg0);
            return -1;
        }
    } else if ((arg0->unk1AC >= 0x4000) && (arg0->unk1AC < 0x8000)) {
        sp1C = arg0->unk20C;
        if ((u16) sp1C->unk0 & 8) {
            func_80015BD0(arg0);
        }
    } else {
        sp1C = arg0->unk20C;
        if ((u16) sp1C->unk0 & 8) {
            func_8000F53C(arg0);
            return -1;
        }
        if ((u16) sp1C->unk0 & 2) {
            func_8000F598(arg0);
        }
    }
    return 0;
}

s32 func_8000E7E4(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp1C;

    sp1C = arg0->unk20C;
    if ((u16) sp1C->unk0 & 1) {
        return 0;
    }
    if ((u16) sp1C->unk0 & 0x20) {
        func_8000FCD8(arg0);
    }
    if ((u16) sp1C->unk0 & 0x40) {
        func_80010150(arg0);
    }
    if ((u16) sp1C->unk0 & 0x80) {
        func_80010460(arg0, 0);
    }
    if ((u16) sp1C->unk0 & 0x100) {
        func_80010460(arg0, 1);
    }
    if ((u16) sp1C->unk0 & 0x400) {
        func_80010734(arg0);
    }
    if ((u16) sp1C->unk0 & 0x1000) {
        func_800108B8(arg0);
    }
    if ((u16) sp1C->unk0 & 0x200) {
        func_80011040(arg0);
    }
    if ((u16) sp1C->unk0 & 4) {
        func_8000F624(arg0);
        if ((arg0->unk1AC >= 0x4000) && (arg0->unk1AC < 0x8000)) {
            func_80014F38(arg0);
        } else {
            if ((arg0->unk1AC < 0x8000) || (arg0->unk1AC >= 0x8010)) {
                func_80010AC8(arg0);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000E9F8.s")

void func_8000F4B0(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 sp4 = arg0->unk20C;

    if (arg0->unk1A8 & 0x80) {
        arg0->unk1F0 = (f32) (arg0->unk1F0 - 1.0f);
    }
    if (arg0->unk1A8 & 0x100) {
        D_801A3068->unk4 &= ~0x100;
    }
    arg0->unk1A8 = (s32) (arg0->unk1A8 & ~0x180);
}

void func_8000F53C(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp1C;

    sp1C = arg0->unk20C;
    func_800B1C10(&sp1C->unkC, &sp1C->unk10, (s32) sp1C->unk6);
    func_8000D74C(arg0);
}

void func_8000F598(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp1C;
    s32 sp18;

    sp1C = arg0->unk20C;
    sp18 = func_800B2748(&sp1C->unkC, &sp1C->unk10);
    if (sp18 < 0) {
        sp1C->unk0 &= ~2;
    } else {
        sp1C->unk8 = sp18;
    }
}

void* func_8000D688(s32);                /* extern */
void func_8000F9D0(UnkStruct_8000DDE0*); /* extern */
extern f64 D_800ED468;
extern f64 D_800ED470;

void func_8000F624(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000DDE0* sp2C;
    UnkStruct_8000E3D4* sp28;
    UnkStruct_8000E3D4* sp24;
    s32 sp20;
    UnkStruct_80099E2C* sp1C;

    func_8000F9D0(arg0);
    sp28 = arg0->unk20C;
    if ((arg0->unk1AC < 0x4000) || (arg0->unk1AC >= 0x8000)) {
        sp28->unk14 += sp28->unk74;
        for (sp20 = 0, sp1C = sp28->unkC; sp20 < sp28->unk6; sp20++, sp1C++) {
            sp1C->unkCC += sp28->unk6C * D_8018257C;
            sp1C->unkD0 += sp28->unk70 * D_8018257C;
            sp1C->unkF4 = (f32) ((f64) sp1C->unkF4 + ((f64) sp28->unk74 * D_800ED468 * (f64) D_8018257C));
            sp1C->unkF8 = (f32) ((f64) sp1C->unkF8 + ((f64) sp28->unk74 * D_800ED470 * (f64) D_8018257C));
        }
    } else {
        for (sp20 = 0, sp1C = sp28->unkC; sp20 < sp28->unk6; sp20++, sp1C++) {
            sp1C->unkCC += sp28->unk6C * D_8018257C;
            sp1C->unkD0 += sp28->unk70 * D_8018257C;
            sp1C->unkD4 += sp28->unk74 * D_8018257C;
        }
        if ((arg0->unk1AC == 0x4001) && (arg0->unk1A8 & 0x40)) {
            sp2C = func_8000D688(0x4000);
            sp24 = sp2C->unk20C;

            for (sp20 = 0, sp1C = sp24->unkC; sp20 < sp24->unk6; sp20++, sp1C++) {
                sp1C->unkCC += sp28->unk6C * D_8018257C;
                sp1C->unkD0 += sp28->unk70 * D_8018257C;
                sp1C->unkD4 += sp28->unk74 * D_8018257C;
            }
        }
    }
}

void func_8000F9D0(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 pad;
    UnkStruct_8000E3D4* sp0;

    sp0 = arg0->unk20C;
    sp0->unk6C += sp0->unkA4 * D_8018257C;
    if (sp0->unkA4 < 0.0f) {
        if (sp0->unk98 > sp0->unk6C) {
            sp0->unk6C = sp0->unk98;
            sp0->unkA4 = 0.0f;
        }
    } else if ((sp0->unkA4 > 0.0f)) {
        if ((sp0->unk98 < sp0->unk6C)) {
            sp0->unk6C = sp0->unk98;
            sp0->unkA4 = 0.0f;
        }
    }
    sp0->unk70 += sp0->unkA8 * D_8018257C;
    if (sp0->unkA8 < 0.0f) {
        if (sp0->unk9C > sp0->unk70) {
            sp0->unk70 = sp0->unk9C;
            sp0->unkA8 = 0.0f;
        }
    } else if ((sp0->unkA8 > 0.0f)) {
        if ((sp0->unk9C < sp0->unk70)) {
            sp0->unk70 = sp0->unk9C;
            sp0->unkA8 = 0.0f;
        }
    }
    sp0->unk74 += sp0->unkAC * D_8018257C;
    if (sp0->unkAC < 0.0f) {
        if (sp0->unkA0 > sp0->unk74) {
            sp0->unk74 = sp0->unkA0;
            sp0->unkAC = 0.0f;
        }
    } else if ((sp0->unkAC > 0.0f)) {
        if ((sp0->unkA0 < sp0->unk74)) {
            sp0->unk74 = sp0->unkA0;
            sp0->unkAC = 0.0f;
        }
    }
}

void func_8000FCD8(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp24;
    s32 sp20;
    UnkStruct_80099E2C* sp1C;

    func_8000FE48(arg0);
    sp24 = arg0->unk20C;

    for (sp20 = 0, sp1C = sp24->unkC; sp20 < sp24->unk6; sp20++, sp1C++) {
        sp1C->unkE8 = (f32) ((f64) sp1C->unkE8 + ((f64) sp24->unk18 * 0.5 * (f64) D_8018257C));
        sp1C->unkEC = (f32) ((f64) sp1C->unkEC + ((f64) sp24->unk1C * 0.5 * (f64) D_8018257C));
        sp1C->unkF0 = (f32) ((f64) sp1C->unkF0 + ((f64) sp24->unk20 * 0.5 * (f64) D_8018257C));
    }
}

void func_8000FE48(UnkStruct_8000DDE0* arg0) {
    s32 pad;
    UnkStruct_8000E3D4* sp0;

    sp0 = arg0->unk20C;
    sp0->unk18 += sp0->unkBC * D_8018257C;
    if (sp0->unkBC < 0.0f) {
        if (sp0->unkB0 > sp0->unk18) {
            sp0->unk18 = sp0->unkB0;
            sp0->unkBC = 0.0f;
        }
    } else if ((sp0->unkBC > 0.0f)) {
        if (sp0->unkB0 < sp0->unk18) {
            sp0->unk18 = sp0->unkB0;
            sp0->unkBC = 0.0f;
        }
    }
    sp0->unk1C += sp0->unkC0 * D_8018257C;
    if (sp0->unkC0 < 0.0f) {
        if (sp0->unkB4 > sp0->unk1C) {
            sp0->unk1C = sp0->unkB4;
            sp0->unkC0 = 0.0f;
        }
    } else if ((sp0->unkC0 > 0.0f)) {
        if ((sp0->unkB4 < sp0->unk1C)) {
            sp0->unk1C = sp0->unkB4;
            sp0->unkC0 = 0.0f;
        }
    }
    sp0->unk20 += sp0->unkC4 * D_8018257C;
    if (sp0->unkC4 < 0.0f) {
        if (sp0->unkB8 > sp0->unk20) {
            sp0->unk20 = sp0->unkB8;
            sp0->unkC4 = 0.0f;
        }
    } else if ((sp0->unkC4 > 0.0f)) {
        if ((sp0->unkB8 < sp0->unk20)) {
            sp0->unk20 = sp0->unkB8;
            sp0->unkC4 = 0.0f;
        }
    }
}

// .rodata
extern f64 D_800ED478;

void func_80010150(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* spC;
    s32 sp8;
    UnkStruct_80099E2C* sp4;

    spC = arg0->unk20C;
    spC->unk24 += spC->unk28 * D_8018257C;
    if ((f64) spC->unk28 > 0.0) {
        if (spC->unk24 > D_800ED478) {
            spC->unk24 = 255.0f;
            spC->unk0 &= ~0x40;
        }
    } else if ((f64) spC->unk24 < 0.0) {
        spC->unk24 = 0.0f;
        spC->unk0 &= ~0x40;
    }
    if (D_801A721C == 3) {
        if (spC->unk24 == 255.0f) {
            for (sp8 = 0, sp4 = spC->unkC; sp8 < spC->unk6; sp8++, sp4++) {
                sp4->unk11E = (s16) (s32) spC->unk24;
                sp4->unkC0 &= 0xFFFF7FFF;
            }
        } else {
            for (sp8 = 0, sp4 = spC->unkC; sp8 < spC->unk6; sp8++, sp4++) {
                sp4->unk11E = (s16) (s32) spC->unk24;
                sp4->unkC0 |= 0x8000;
            }
        }
    } else {
        for (sp8 = 0, sp4 = spC->unkC; sp8 < spC->unk6; sp8++, sp4++) {
            sp4->unk11E = (s16) (s32) spC->unk24;
        }
    }
}
extern f64 D_800ED484;
extern f64 D_800ED488;
extern f64 D_800ED490;
extern f64 D_800ED49C;
extern f64 D_800ED498;
extern f64 D_800ED4A0;
extern f64 D_800ED4A8;
extern f64 D_800ED480;

void func_80010460(UnkStruct_8000DDE0* arg0, s32 arg1) {
    UnkStruct_8000E3D4* sp2C;

    s32 sp28;
    UnkStruct_80099E2C* sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;

    sp2C = arg0->unk20C;
    if (arg1 == 0) {
        if ((sp2C->unk2C += sp2C->unk30 * D_8018257C) > D_800ED480) {
            sp2C->unk2C = (f32) ((f64) sp2C->unk2C - D_800ED488);
        }
        sp18 = sp2C->unk38;
        sp2C->unk38 = MathUtil_Sinf((f32) ((f64) sp2C->unk2C * D_800ED490)) * sp2C->unk34;
        sp1C = sp2C->unk38 - sp18;

        for (sp28 = 0, sp24 = sp2C->unkC; sp28 < sp2C->unk6; sp28++, sp24++) {
            sp24->unkCC += sp1C;
        }
        return;
    }

    if ((sp2C->unk3C += sp2C->unk40 * D_8018257C) > D_800ED498) {
        sp2C->unk3C = (f32) ((f64) sp2C->unk3C - D_800ED4A0);
    }
    sp18 = sp2C->unk48;
    sp2C->unk48 = MathUtil_Sinf((f32) ((f64) sp2C->unk3C * D_800ED4A8)) * sp2C->unk44;
    sp1C = sp2C->unk48 - sp18;

    for (sp28 = 0, sp24 = sp2C->unkC; sp28 < sp2C->unk6; sp28++, sp24++) {
        sp24->unkD0 += sp1C;
    }
}

void func_80010734(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp1C;

    sp1C = arg0->unk20C;
    sp1C->unk4C = (f32) ((f64) sp1C->unk4C - ((f64) D_8018257C * 0.5));

    while (sp1C->unk4C < 0.0) {
        func_800B3DBC(&sp1C->unkC, &sp1C->unk10, (s32) (u16) sp1C->unk54[sp1C->unk52]);
        sp1C->unk4C += (f32) sp1C->unk50;
        sp1C->unk52 += 1;

        if (((s32) sp1C->unk52 < 4)) {
            if ((u16) sp1C->unk54[sp1C->unk52] != 0xFFFF) {
                continue;
            }
        }

        sp1C->unk52 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800108B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80010AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800111E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8001173C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800123AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800124B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8001292C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800129FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800131F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800139B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800140D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800145D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014BD4.s")
