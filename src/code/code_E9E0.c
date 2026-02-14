#include "common.h"

typedef struct UnkStruct_800108B8_sp24_s {
    char pad[0x6];
    u16 unk6;
    s32 pad8;
    SpriteObj* unkC;
    char pad10[0x70];
    f32 unk80;
    u16 unk84;
    u16 unk86;
    u16 unk88;
    u16 unk8A;
    u16 unk8C;
    u16 unk8E;
    s16 unk90;
} UnkStruct_800108B8_sp24;

typedef struct UnkStruct_80180648_s {
    char pad[0x42];
    s16 unk42;
} UnkStruct_80180648;

void func_8000E3D4(UnkStruct_8000E3D4* arg0);
s32 func_8000DDE0(UnkStruct_8000DDE0* arg0);
void* TempHeap_Alloc(s32 size);          /* extern */
void func_8000D90C(UnkStruct_8000DDE0*); /* extern */
s32 func_8000DE84(UnkStruct_8000DDE0* arg0);
void func_80031728(void);                            /* extern */
s32 func_80031AC8(void);                             /* extern */
s32 func_8004A054(s32, s16*);                        /* extern */
void func_8000D74C(UnkStruct_8000DDE0*);             /* extern */
void func_8000F53C(UnkStruct_8000DDE0*);             /* extern */
void func_8000F598(UnkStruct_8000DDE0*);             /* extern */
void func_80015BD0(UnkStruct_8000DDE0*);             /* extern */
void func_8000F624(UnkStruct_8000DDE0*);             /* extern */
void func_8000FCD8(UnkStruct_8000DDE0*);             /* extern */
void func_80010150(UnkStruct_8000DDE0*);             /* extern */
void func_80010460(UnkStruct_8000DDE0*, s32);        /* extern */
void func_80010734(UnkStruct_8000DDE0*);             /* extern */
void func_800108B8(UnkStruct_8000DDE0*);             /* extern */
void func_80010AC8(UnkStruct_8000DDE0*);             /* extern */
void func_80011040(UnkStruct_8000DDE0*);             /* extern */
void func_80014F38(UnkStruct_8000DDE0*);             /* extern */
void func_8000FE48(UnkStruct_8000DDE0*);             /* extern */
void func_8002206C(s32, s32, s32);                   /* extern */
s32 func_80031874(void);                             /* extern */
void func_80031B6C(void);                            /* extern */
s32* func_80096B38(u8*, u8*, s32*, s32*, s32*, s32); /* extern */
void func_80096C6C(s32*, s32);                       /* extern */
void func_8001A690(UnkStruct_8000DDE0*);             /* extern */
s32 func_80096D40(s32*, s32, u32*);                  /* extern */

extern f32 D_800D9E84[];
extern s32* D_801A3070;
extern s32* D_801A3078;
extern s32 D_8097F4D0;
extern s32 D_80981A00;
extern s32 D_809968B0;
extern s32 D_80996A20;
extern s32 D_8015F804;
extern u8 D_800D9DD0[];

extern UnkStruct_80180648* D_80180648;
extern f32 D_801A8E38;
u16 func_80056E88(u16, s32);                                                           /* extern */
s32 func_800B3230(s16*, s32, s32, s32);                                                /* extern */
u16 func_800B334C(UnkStruct_800B23C4**, s32);                                          /* extern */
s32 func_80049A00(SpriteObj*, UnkStruct_800B23C4*, u16, u16, s32, s32, s32, s32, s32); /* extern */
s32 func_80014B5C(UnkStruct_801A306C* arg0);
void func_8001AE90(UnkStruct_8000DDE0*); /* extern */

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

#ifdef NEEDS_RODATA

s32 func_8000DE84(UnkStruct_8000DDE0* arg0) {
    s32 sp24;
    s32 sp20;
    UnkStruct_8000E3D4* sp1C;
    s32 sp18;

    sp18 = 1;
    sp20 = 0;
    sp24 = 0;

    if ((arg0->unk20C != NULL)) {
        sp1C = arg0->unk20C;
        if (((((sp1C->unk2 < 3))) || (sp1C->unk2 >= 0x2A) || (sp1C->unk7C == 0))) {
            if (((u16) sp1C->unk0 & 1) && (func_8000E524(arg0) < 0)) {
                return 0;
            }
            if (func_8000E678(arg0) < 0) {
                return 0;
            }
            sp18 = func_8000E9F8(arg0);
        }
    }

    while ((sp24 == 0) && (sp18 != 0)) {
        if (arg0->unk1EC == arg0->unk1E8) {
            break;
        }
        switch ((u16) arg0->unk210[(s32) arg0->unk1E8 % 128]) {

            case 0xC002:
                if (arg0->unk1A8 & 1) {
                    sp24++;
                    sp20 = -1;
                    break;
                }
                func_800111E8(arg0);
                sp1C = arg0->unk20C;
                break;

            case 0xC003:
                func_8001173C(arg0);
                break;

            case 0xC004:
                func_80011A0C(arg0);
                break;

            case 0xC005:
                func_800131F4(arg0);
                break;

            case 0xC00A:
                func_80011B88(arg0);
                sp24++;
                break;

            case 0xC015:
                func_80011F7C(arg0);
                break;

            case 0xC016:
                func_80012068(arg0);
                break;

            case 0xC012:
                func_800123AC(arg0);
                sp24++;
                break;

            case 0xC010:
                func_80012164(arg0);
                sp24++;
                break;

            case 0xC018:
                func_800124B8(arg0);
                break;

            case 0xC019:
                func_80012634(arg0);
                break;

            case 0xC01A:
                func_8001292C(arg0);
                break;

            case 0xC01B:
                func_80013474(arg0);
                break;

            case 0xC01C:
                func_80012798(arg0);
                break;

            case 0xC01D:
                func_800129FC(arg0);
                break;

            case 0xC01E:
                func_80012E7C(arg0);
                break;

            case 0xC01F:
                func_80013398(arg0);
                break;

            case 0xC020:
                func_80013624(arg0);
                break;

            case 0xC021:
                func_800139B8(arg0);
                sp24++;
                break;

            case 0xC022:
                func_80013AFC(arg0);
                break;

            case 0xC025:
                func_80013F04(arg0);
                break;

            case 0xC026:
                func_800140D8(arg0);
                break;

            case 0xC027:
                func_80014228(arg0);
                sp24++;
                break;

            case 0xC028:
                func_80015C30(arg0);
                break;

            case 0xC029:
                func_800145D4(arg0);
                break;

            case 0xC02C:
                func_80015D74(arg0);
                break;

            case 0xC02D:
                func_80014A80(arg0);
                break;

            case 0xC030:
                func_80013C90(arg0);
                break;

            case 0xC031:
                func_80013FEC(arg0);
                break;

            default:
                D_80153DF4++;
                break;
        }
    }
    if ((arg0->unk20C != NULL) && ((((sp1C->unk2 < 3))) || (sp1C->unk2 >= 0x2A) || (sp1C->unk7C == 0))) {
        func_8000E7E4(arg0);
    }
    return sp20;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000DE84.s")
#endif

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
    arg0->unk6C[0] = 0.0f;
    arg0->unk6C[1] = 0.0f;
    arg0->unk6C[2] = 0.0f;
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
    SpriteObj* sp20;
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
    SpriteObj* sp1C;

    func_8000F9D0(arg0);
    sp28 = arg0->unk20C;
    if ((arg0->unk1AC < 0x4000) || (arg0->unk1AC >= 0x8000)) {
        sp28->unk14 += sp28->unk6C[2];
        for (sp20 = 0, sp1C = sp28->unkC; sp20 < sp28->unk6; sp20++, sp1C++) {
            sp1C->unkCC += sp28->unk6C[0] * D_8018257C;
            sp1C->unkD0 += sp28->unk6C[1] * D_8018257C;
            sp1C->unkF4 += (sp28->unk6C[2] * D_800ED468 * D_8018257C);
            sp1C->unkF8 += (sp28->unk6C[2] * D_800ED470 * D_8018257C);
        }
    } else {
        for (sp20 = 0, sp1C = sp28->unkC; sp20 < sp28->unk6; sp20++, sp1C++) {
            sp1C->unkCC += sp28->unk6C[0] * D_8018257C;
            sp1C->unkD0 += sp28->unk6C[1] * D_8018257C;
            sp1C->unkD4 += sp28->unk6C[2] * D_8018257C;
        }
        if ((arg0->unk1AC == 0x4001) && (arg0->unk1A8 & 0x40)) {
            sp2C = func_8000D688(0x4000);
            sp24 = sp2C->unk20C;

            for (sp20 = 0, sp1C = sp24->unkC; sp20 < sp24->unk6; sp20++, sp1C++) {
                sp1C->unkCC += sp28->unk6C[0] * D_8018257C;
                sp1C->unkD0 += sp28->unk6C[1] * D_8018257C;
                sp1C->unkD4 += sp28->unk6C[2] * D_8018257C;
            }
        }
    }
}

void func_8000F9D0(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 pad;
    UnkStruct_8000E3D4* sp0;

    sp0 = arg0->unk20C;
    sp0->unk6C[0] += sp0->unkA4 * D_8018257C;
    if (sp0->unkA4 < 0.0f) {
        if (sp0->unk98 > sp0->unk6C[0]) {
            sp0->unk6C[0] = sp0->unk98;
            sp0->unkA4 = 0.0f;
        }
    } else if ((sp0->unkA4 > 0.0f)) {
        if ((sp0->unk98 < sp0->unk6C[0])) {
            sp0->unk6C[0] = sp0->unk98;
            sp0->unkA4 = 0.0f;
        }
    }
    sp0->unk6C[1] += sp0->unkA8 * D_8018257C;
    if (sp0->unkA8 < 0.0f) {
        if (sp0->unk9C > sp0->unk6C[1]) {
            sp0->unk6C[1] = sp0->unk9C;
            sp0->unkA8 = 0.0f;
        }
    } else if ((sp0->unkA8 > 0.0f)) {
        if ((sp0->unk9C < sp0->unk6C[1])) {
            sp0->unk6C[1] = sp0->unk9C;
            sp0->unkA8 = 0.0f;
        }
    }
    sp0->unk6C[2] += sp0->unkAC * D_8018257C;
    if (sp0->unkAC < 0.0f) {
        if (sp0->unkA0 > sp0->unk6C[2]) {
            sp0->unk6C[2] = sp0->unkA0;
            sp0->unkAC = 0.0f;
        }
    } else if ((sp0->unkAC > 0.0f)) {
        if ((sp0->unkA0 < sp0->unk6C[2])) {
            sp0->unk6C[2] = sp0->unkA0;
            sp0->unkAC = 0.0f;
        }
    }
}

void func_8000FCD8(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp24;
    s32 sp20;
    SpriteObj* sp1C;

    func_8000FE48(arg0);
    sp24 = arg0->unk20C;

    for (sp20 = 0, sp1C = sp24->unkC; sp20 < sp24->unk6; sp20++, sp1C++) {
        sp1C->rotateX = (f32) ((f64) sp1C->rotateX + ((f64) sp24->unk18 * 0.5 * (f64) D_8018257C));
        sp1C->rotateY = (f32) ((f64) sp1C->rotateY + ((f64) sp24->unk1C * 0.5 * (f64) D_8018257C));
        sp1C->rotateZ = (f32) ((f64) sp1C->rotateZ + ((f64) sp24->unk20 * 0.5 * (f64) D_8018257C));
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
    SpriteObj* sp4;

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

// NEEDS RODATA
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
    SpriteObj* sp24;
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

void func_800108B8(UnkStruct_8000DDE0* arg0) {
    UnkStruct_800108B8_sp24* sp24;
    SpriteObj* sp20;
    s32 sp1C;
    s32 sp18;

    sp24 = arg0->unk20C;
    sp18 = 0;
    sp24->unk80 -= D_8018257C * 0.5;
    while (sp24->unk80 <= 0.0) {
        sp24->unk8E++;
        if ((s32) sp24->unk8E >= (s32) sp24->unk8C) {
            sp24->unk8E = 0;
        }
        sp24->unk80 += sp24->unk84;
        sp18 = 1;
    }
    if (sp18 != 0) {
        for (sp1C = 0, sp20 = sp24->unkC; sp1C < sp24->unk6; sp1C++, sp20++) {
            if (sp20->currentPaletteColors == NULL) {
                continue;
            }
            SysMem_Copy8(&sp20->currentPaletteColors[sp24->unk86],
                         &sp20->currentPaletteColors[sp24->unk88] + (sp24->unk90 * sp24->unk8E), sp24->unk8A * 2);
        }
    }
}

// .rodata
extern f64 D_800ED4B0;
extern f64 D_800ED4B8;
extern f64 D_800ED4C0;

void func_80010AC8(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp54;
    SpriteObj* sp50;
    s32 sp4C;
    u16 sp4A;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    s32 sp38;
    s32 other;
    s32 pad48;

    sp54 = arg0->unk20C;
    if (sp54->unk0 & 8) {
        return;
    }
    if (!(sp54->unk0 & 0x800)) {
        if ((sp54->unk0 & 2)) {
            sp4A = func_800B3434(&sp54->unk10, 0U);
            if (sp4A & 0xC000) {
                sp40 = sp3C = 0.0f;

                if ((sp44 = FABS(sp54->unkC->unkCC)) > 160.0) {
                    sp40 = sp44 - 160.0;
                }

                if ((sp44 = FABS(sp54->unkC->unkD0)) > D_800ED4B0) {
                    sp3C = sp44 - D_800ED4B8;
                }

                sp44 = sp40 > sp3C ? sp40 : sp3C;

                sp38 = 0x7FFF - (s32) ((sp44 / D_800ED4C0) * 32768.0);
                if (sp38 > 0) {
                    if (sp4A & 0x4000) {
                        func_8002206C(func_800B32E4(&sp54->unk10, 0), sp38, 0x3F);
                    }
                    if (sp4A & 0x8000) {
                        func_8002206C(func_800B32E4(&sp54->unk10, 1), sp38, 0x3F);
                    }
                }
            }
        }
    }
    for (sp4C = 0, sp50 = sp54->unkC; sp4C < sp54->unk8; sp4C++, sp50++) {
        if (((f64) sp50->unkF4 <= 0.0) || ((f64) sp50->unkF8 <= 0.0)) {
            continue;
        }
        if (((f64) sp50->unkF4 != 1.0) || ((f64) sp50->unkF8 != 1.0)) {
            if (D_801A721C != 3) {
                sp50->unkC0 &= ~8;
            } else {
                sp50->unkC0 |= 8;
            }
        }
        MtxUtil_PushIdentity();
        func_8009A14C(sp50);
        if (sp50->unkC0 & 0x10) {
            MtxUtil_RotateZ(sp50->rotateZ);
            MtxUtil_RotateY(sp50->rotateY);
            MtxUtil_RotateX(sp50->rotateX);
            if (!(sp54->unk0 & 0x20) && ((f64) sp50->rotateX == 0.0) && ((f64) sp50->rotateY == 0.0) &&
                ((f64) sp50->rotateZ == 0.0)) {
                sp50->unkC0 |= 8;
                sp50->unkC0 &= ~0x10;
            }
        }
        func_800997D8(sp50);
        MtxUtil_Pop();
    }
}

void func_8001ABEC(UnkStruct_8000DDE0*); /* extern */
void func_8001ACDC(UnkStruct_8000DDE0*); /* extern */
void func_8001ADBC(UnkStruct_8000DDE0*); /* extern */
extern u8 D_801A7208;

void func_80011040(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000E3D4* sp2C;
    UnkStruct_8000E3D4_unk5C* sp28;
    UnkStruct_8000DDE0* sp24;
    u32* sp20;
    u8* sp1C;

    sp2C = arg0->unk20C;
    sp28 = sp2C->unk5C;
    sp24 = sp28->unk0;
    func_8001ABEC(sp24);
    func_8008EAA8(0, 0);

    for (sp20 = sp28->unk4; *sp20 != 0; sp20++) {
        SysMem_DmaCopy(*sp20, sp28->unk8, 0x60);

        for (sp1C = sp28->unk8; *sp1C != '\0' && *sp1C != '%'; sp1C++) {}

        if (sp1C[0] == '%') {
            func_8008ECE4((char*) sp28->unk8, D_801A7208);
        } else {
            func_8008ECE4((char*) sp28->unk8);
        }
    }
    sp24->unk0.currentPaletteColors[16] = 0;
    func_8001ACDC(sp24);
    func_8001ADBC(sp24);
}

s32 func_800111E8(UnkStruct_8000DDE0* arg0) {
    s32 sp3C;
    u16 sp30[6];
    UnkStruct_8000E3D4* sp2C;
    SpriteObj* sp28;

    if (func_8000DA44(arg0, 6, sp30) < 0) {
        return -1;
    }
    arg0->unk208 = sp30[0];
    arg0->unk1B0 = (s16) sp30[2];
    arg0->unk1B4 = (s16) sp30[3];
    arg0->unk1B8 = (s16) sp30[4];
    arg0->unk20A = sp30[5];
    if (arg0->unk20C == NULL) {
        arg0->unk20C = TempHeap_Alloc(0xC8);
    }
    sp2C = arg0->unk20C;
    func_8000E3D4(sp2C);
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        sp2C->unk2 = sp30[1];
        sp2C->unk6 = 1;
        sp2C->unkC = NULL;
        sp2C->unk10 = NULL;
        sp2C->unk0 = 4;
        sp28 = sp2C->unkC = (u32) &D_801A8C18[arg0->unk1AC] + 0xFF500000;
        if (!(sp28->unkC0 & 0x10000000)) {
            return -1;
        }
        sp28->unkCC = arg0->unk1B0;
        sp28->unkD0 = arg0->unk1B4;
        sp28->unkD4 = arg0->unk1B8;
        if (arg0->unk20A != 0xFFFF) {
            sp28->unk124 = (s16) arg0->unk20A;
        }
    } else if ((arg0->unk1AC >= 0x4000) && (arg0->unk1AC < 0x8000)) {
        sp2C->unk2 = sp30[1];
        sp2C->unk6 = 1;
        sp2C->unkC = NULL;
        sp2C->unk10 = NULL;
        sp2C->unk0 = 4;
        func_80014C70(arg0);
    } else {
        sp2C->unk0 = 0;

        if ((sp2C->unk2 = sp30[1]) != 0xFFFF) {
            sp2C->unk6 = (u16) D_800D9DD0[arg0->unk1AC];
            sp2C->unkC = TempHeap_Alloc(sp2C->unk6 * 0x160);
            sp2C->unk10 = TempHeap_Alloc(sp2C->unk6 << 6);
            func_800B1B3C(&sp2C->unkC, &sp2C->unk10, (s32) sp2C->unk6);
            for (sp3C = 0, sp28 = sp2C->unkC; sp3C < sp2C->unk6; sp3C++, sp28++) {
                func_80099E2C(sp28);
                sp28->unkCC = arg0->unk1B0;
                sp28->unkD0 = (f32) ((f64) (arg0->unk1B4 + D_801A8E38) + ((f64) arg0->unk1B8 * 4.0));
                sp28->unkC8 = (s32) (60.0f - arg0->unk1B8);
                sp28->unkD4 = 0.0f;
                sp28->unkC0 = 0xC;
                sp28->unkC4 = 0x20;
            }
            if (arg0->unk20A == 0xFFFF) {
                sp2C->unk4 = (u16) D_80180648->unk42;
            } else {
                sp2C->unk4 = arg0->unk20A;
            }
        } else {
            sp2C->unk6 = 1;
            sp2C->unk8 = 0;
            sp2C->unkC = NULL;
            sp2C->unk10 = NULL;
        }
    }
    arg0->unk1A8 |= 1;
    return 0;
}

s32 func_8001173C(UnkStruct_8000DDE0* arg0) {
    u16 sp40[7];
    UnkStruct_8000E3D4* sp3C;
    u16 sp3A;
    u8 sp39;
    register u16 ret;

    sp39 = 0;
    if (func_8000DA44(arg0, 6, sp40) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    sp3C = arg0->unk20C;
    if (sp40[5] == 0xFFFF) {
        sp3A = sp40[2];
    } else {
        sp3A = func_80056E88(sp40[2], 1);
    }
    if (sp40[3] == 1) {
        sp39 |= 1;
    }
    if (func_800B3230(&sp3C->unk60, 0, 0, (sp3C->unk2 << 0x10) | (s16) sp3A) < 0) {
        sp3C->unk0 &= ~2;
        sp3C->unk0 &= ~4;
        return -1;
    }
    sp3C->unk0 &= ~0x10;
    if ((sp40[4] == 1) && ((u16) sp3C->unk60 & 1)) {
        sp39 |= 4;
        sp3C->unk0 |= 0x10;
        sp3C->unk62 = 0x2000;
        sp3C->unk64 = (s16) sp40[1];
        sp3C->unk66 = 0x1000;
        arg0->unk1A8 |= 0x100;
    }
    sp3C->unk8 = func_800B202C(&sp3C->unkC, &sp3C->unk10, (sp3C->unk2 << 0x10) | (s16) sp3A, sp3C->unk4,
                               sp3C->unkC->unkCC, sp3C->unkC->unkD0, (u8) (s32) sp39);

    if (ret = func_800B334C(&sp3C->unk10, 4), sp3C->unk66 & ret) {
        sp3C->unk62 = 0;
        func_8000F4B0(arg0);
    }
    sp3C->unk0 |= 2;
    sp3C->unk0 |= 4;
    return 0;
}

s32 func_80011A0C(UnkStruct_8000DDE0* arg0) {
    u16 pad40[1]; // sp30
    u16 sp3C[3];
    s32 pad38[3];
    s32* sp2C;
    s32* sp28;
    s32 sp24;

    if (func_8000DA44(arg0, 3, sp3C) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    if (D_801A8D70 < 0x1F4) {
        sp2C = &D_8097F4D0;
        if (D_801A3070 == NULL) {
            sp28 = &D_80981A00;
        } else {
            sp28 = D_801A3070;
        }
    } else {
        sp2C = &D_809968B0;
        if (D_801A3078 == NULL) {
            sp28 = &D_80996A20;
        } else {
            sp28 = D_801A3078;
        }
    }
    sp28 = func_80096B38(gSeg_639B20_ROM_START, gSeg_639B20_VRAM, sp2C, sp28, &sp24, (s32) sp3C[2]);
    if (func_80031874() != 0) {}
    func_80096C6C(sp28, sp24);
    func_80031B6C();
    return 0;
}

#ifdef NEEDS_RODATA
f32 func_80014BD4(u16); /* extern */

s32 func_80011B88(UnkStruct_8000DDE0* arg0) {
    s32 pad28;
    u16 sp24[4];
    UnkStruct_8000E3D4* sp20;
    s32 pad[2];

    if (func_8000DA44(arg0, 4, sp24) < 0) {
        return -1;
    }
    arg0->unk1A8 |= 0x100;
    sp20 = arg0->unk20C;
    sp20->unk62 = sp24[1];
    sp20->unk64 = (s16) sp24[2];
    sp20->unk66 = sp24[3];
    switch (sp20->unk62) {
        case 0xE002:
        case 0xE00E:
            if (sp20->unkC->unkCC > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE003:
        case 0xE00F:
            if (sp20->unkC->unkD0 > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE008:
        case 0xE010:
            if ((arg0->unk1AC < 0x4000) || (arg0->unk1AC >= 0x8000)) {
                if (sp20->unk14 > (f32) (s16) sp20->unk66) {
                    sp20->unk68 = 1;
                } else {
                    sp20->unk68 = 0;
                }
            } else if (sp20->unkC->unkD4 > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE009:
            if ((s32) (u16) sp20->unkC->unk11E > (s32) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE00A:
            if (sp20->unkC->rotateX > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE00B:
            if (sp20->unkC->rotateY > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE00C:
            if (sp20->unkC->rotateZ > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xE00D:
            if (func_80014BD4(sp20->unk66) < sp20->unkC->unkF4) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011B88.s")
#endif

f32 func_80014BD4(u16); /* extern */

s32 func_80011F7C(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp20[5];
    UnkStruct_8000E3D4* sp1C;

    if (func_8000DA44(arg0, 5, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    for (sp2C = 0; sp2C < 3; sp2C++) {
        sp1C->unk6C[sp2C] = func_80014BD4(sp20[sp2C + 2]);
    }
    sp1C->unk14 = 0.0f;
    if (arg0->unk1AC == 0x4001) {
        arg0->unk1A8 &= ~0x40;
    }
    return 0;
}

s32 func_80012068(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp24[4];
    UnkStruct_8000E3D4* sp20;
    SpriteObj* sp1C;

    if (func_8000DA44(arg0, 4, sp24) < 0) {
        return -1;
    }
    sp20 = arg0->unk20C;
    for (sp2C = 0, sp1C = sp20->unkC; sp2C < sp20->unk6; sp2C++, sp1C++) {
        sp1C->unkF4 = D_800D9E84[sp24[2]];
        sp1C->unkF8 = D_800D9E84[sp24[2]];
    }
    return 0;
}

s32 func_80012164(UnkStruct_8000DDE0* arg0) {
    s32 pad;
    u16 sp4C[4];
    UnkStruct_8000E3D4* sp48;
    s32 sp44;

    if (func_8000DA44(arg0, 4, sp4C) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    sp48 = arg0->unk20C;
    sp44 = 0;
    if ((((u16) sp48->unk60 & 0x10) >> 4) == 1) {
        sp44 = 3;
    } else {
        if ((((u16) sp48->unk60 & 0x60) >> 5) == 0) {
            sp44 = 1;
        }
        if ((((u16) sp48->unk60 & 0x60) >> 5) == 1) {
            sp44 = 2;
        }
    }

    if ((sp4C[2] == 0) && (sp4C[3] == 0)) {
        sp48->unkC->unkCC -= D_801A8C18->unkCC;
        sp48->unkC->unkD0 -= D_801A8C18->unkD0;
    }
    sp48->unk94 = sp48->unkC->unkC8;

    ;
    if ((sp48->unk7C = func_80049A00(sp48->unkC, sp48->unk10, sp4C[1], sp4C[2], (s32) sp4C[3], sp48->unk8,
                                     sp48->unk10->unk0 & 1 ? 0 : 1, sp44, (s32) sp48->unk4)) == 0) {
        return -1;
    }
    sp48->unk0 |= 1;
    return 0;
}

s32 func_800123AC(UnkStruct_8000DDE0* arg0) {
    s32 pad20;
    u16 sp1C[3];
    UnkStruct_8000E3D4* sp18;

    if (func_8000DA44(arg0, 3, sp1C) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    sp18 = arg0->unk20C;
    sp18->unk0 |= 8;
    if (((s32) sp18->unk2 < 3) || ((s32) sp18->unk2 >= 0x2A)) {
        return 0;
    }
    if (func_80014B5C(sp18->unk7C) != 0) {
        func_800299C4(sp18->unk7C);
    }
    return 0;
}

s32 func_800124B8(UnkStruct_8000DDE0* arg0) {
    u16 pad[1];
    u16 sp2C[4];
    UnkStruct_8000E3D4* sp28;
    s32 p;

    if (func_8000DA44(arg0, 4, sp2C) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    arg0->unk208 = (u16) sp2C[0];
    arg0->unk1B0 = (s16) sp2C[2];
    arg0->unk1B4 = (s16) sp2C[3] + D_801A8E38;
    if (arg0->unk20C == NULL) {
        arg0->unk20C = TempHeap_Alloc(0xC8);
    }
    sp28 = arg0->unk20C;
    func_8000E3D4(sp28);
    sp28->unk0 = 0;
    sp28->unk2 = sp2C[1];
    sp28->unk7C = func_800298A4(D_801A7234, D_801A723C, sp2C[1] - 2, arg0->unk1B0, arg0->unk1B4);
    return 0;
}

s32 func_80012634(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp20[5];
    UnkStruct_8000E3D4* sp1C;
    SpriteObj* sp18;

    if (func_8000DA44(arg0, 5, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    arg0->unk208 = (u16) sp20[0];
    sp1C->unk18 = func_80014BD4(sp20[2]);
    sp1C->unk1C = func_80014BD4(sp20[3]);
    sp1C->unk20 = func_80014BD4(sp20[4]);
    sp1C->unk0 |= 0x20;
    for (sp2C = 0, sp18 = sp1C->unkC; sp2C < sp1C->unk6; sp2C++, sp18++) {
        sp18->unkC0 &= ~8;
        sp18->unkC0 |= 0x10;
    }
    return 0;
}

s32 func_80012798(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp20[5];
    UnkStruct_8000E3D4* sp1C;
    SpriteObj* sp18;

    if (func_8000DA44(arg0, 5, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    arg0->unk208 = (u16) sp20[0];
    sp1C->unk18 = 0.0f;
    sp1C->unk1C = 0.0f;
    sp1C->unk20 = 0.0f;
    sp1C->unk0 &= ~0x20;
    for (sp2C = 0, sp18 = sp1C->unkC; sp2C < sp1C->unk6; sp2C++, sp18++) {
        sp18->rotateX = (s16) sp20[2];
        sp18->rotateY = (s16) sp20[3];
        sp18->rotateZ = (s16) sp20[4];
        sp18->unkC0 &= ~8;
        sp18->unkC0 |= 0x10;
    }
    return 0;
}

s32 func_8001292C(UnkStruct_8000DDE0* arg0) {
    s32 pad20;
    u16 sp1C[3];
    UnkStruct_8000E3D4* sp18;

    if (func_8000DA44(arg0, 3, sp1C) < 0) {
        return -1;
    }
    sp18 = arg0->unk20C;
    arg0->unk208 = (u16) sp1C[0];
    sp18->unk24 = (f32) sp18->unkC->unk11E;
    sp18->unk28 = func_80014BD4(sp1C[2]);
    sp18->unk0 |= 0x40;
    return 0;
}

s32 func_800129FC(UnkStruct_8000DDE0* arg0) {
    s32 sp34;
    u16 sp2C[3];
    UnkStruct_8000E3D4* sp28;
    SpriteObj* sp24;

    if (func_8000DA44(arg0, 3, sp2C) < 0) {
        return -1;
    }
    sp28 = arg0->unk20C;
    arg0->unk208 = (u16) sp2C[0];
    sp28->unk28 = 0.0f;
    sp28->unk0 &= ~0x40;
    switch ((s16) sp2C[2]) { /* irregular */
        case -1:
            for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
                sp24->unkC0 &= 0xFFFDFFFF;
                sp24->unkC0 |= 0x200;
            }
            break;
        case 256:
            for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
                sp24->unkC0 &= 0xFFFDFDFF;
            }
            break;
        case 257:
            for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
                sp24->unkC0 &= ~0x200;
                sp24->unkC0 |= 0x20000;
            }
            break;
        default:
            sp28->unk24 = (s16) sp2C[2];
            if (D_801A721C == 3) {
                if (sp28->unk24 == 255.0f) {
                    for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
                        sp24->unk11E = (s16) (s32) sp28->unk24;
                        sp24->unkC0 &= 0xFFFF7FFF;
                    }
                } else {
                    for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
                        sp24->unk11E = (s16) (s32) sp28->unk24;
                        sp24->unkC0 |= 0x8000;
                    }
                }
            } else {
                for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
                    sp24->unk11E = (s16) (s32) sp28->unk24;
                }
            }
    }
    return 0;
}

// needs rodata
extern f64 D_800ED508;
extern f64 D_800ED510;
extern f64 D_800ED518;
extern f64 D_800ED520;

s32 func_80012E7C(UnkStruct_8000DDE0* arg0) {
    s32 pad;
    u16 sp20[6];
    UnkStruct_8000E3D4* sp1C;

    if (func_8000DA44(arg0, 6, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    arg0->unk208 = (u16) sp20[0];
    if ((sp20[3] == 0) || (sp20[4] == 0)) {
        if ((sp20[2] == 1) || (sp20[2] == 0)) {
            sp1C->unk0 &= ~0x80;
        }
        if ((sp20[2] == 2) || (sp20[2] == 0)) {
            sp1C->unk0 &= ~0x100;
        }
        return 0;
    }
    if ((sp20[2] == 1) || (sp20[2] == 0)) {
        sp1C->unk2C = (f32) ((s16) sp20[5] % 360);
        sp1C->unk30 = (f32) (D_800ED508 / (f64) ((f32) sp20[4] * 2.0f));
        sp1C->unk34 = (f32) (sp20[3] * 0.5);
        sp1C->unk38 = MathUtil_Sinf((f32) ((f64) sp1C->unk2C * D_800ED510)) * sp1C->unk34;
        sp1C->unk0 |= 0x80;
    }
    if ((sp20[2] == 2) || (sp20[2] == 0)) {
        sp1C->unk3C = (f32) ((s16) sp20[5] % 360);
        sp1C->unk40 = (f32) (D_800ED518 / ((f64) (f32) sp20[4] * 2.0));

        sp1C->unk44 = (f32) (sp20[3] * 0.5);
        sp1C->unk48 = MathUtil_Sinf((f32) ((f64) sp1C->unk3C * D_800ED520)) * sp1C->unk44;
        sp1C->unk0 |= 0x100;
    }
    return 0;
}

s32 func_800131F4(UnkStruct_8000DDE0* arg0) {
    s32 sp34;
    u16 sp2C[3];
    UnkStruct_8000E3D4* sp28;
    UnkStruct_8000E3D4* sp24;
    UnkStruct_8000DDE0* sp20;
    SpriteObj* sp1C;
    s32 sp18;

    if (func_8000DA44(arg0, 3, sp2C) < 0) {
        return -1;
    }
    sp28 = arg0->unk20C;
    sp20 = func_8000D688((s32) sp2C[2]);
    if (sp20 == NULL) {
        return -1;
    }
    sp24 = sp20->unk20C;
    sp18 = sp28->unkC->unkC8;
    for (sp34 = 0, sp1C = sp28->unkC; sp34 < sp28->unk6; sp34++, sp1C++) {
        sp1C->unkC8 = sp24->unkC->unkC8;
    }
    sp1C = sp24->unkC;
    for (sp34 = 0, sp1C = sp24->unkC; sp34 < sp24->unk6; sp34++, sp1C++) {
        sp1C->unkC8 = sp18;
    }

    return 0;
}

s32 func_80013398(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp24[3];
    UnkStruct_8000E3D4* sp20;
    SpriteObj* sp1C;

    if (func_8000DA44(arg0, 3, sp24) < 0) {
        return -1;
    }
    sp20 = arg0->unk20C;
    arg0->unk208 = sp24[0];
    for (sp2C = 0, sp1C = sp20->unkC; sp2C < sp20->unk6; sp2C++, sp1C++) {
        sp1C->unkC8 = (s32) sp24[2];
    }
    return 0;
}

s32 func_80013474(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp24[4];
    UnkStruct_8000E3D4* sp20;
    SpriteObj* sp1C;

    if (func_8000DA44(arg0, 4, sp24) < 0) {
        return -1;
    }
    sp20 = arg0->unk20C;
    for (sp2C = 0; sp2C < 3; sp2C++) {
        sp20->unk6C[sp2C] = 0.0f;
    }
    sp1C = sp20->unkC;
    for (sp2C = 0, sp1C = sp20->unkC; sp2C < sp20->unk6; sp2C++, sp1C++) {
        sp1C->unkCC = (s16) sp24[2];
        sp1C->unkD0 = (s16) sp24[3];
        if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
            continue;
        }
        sp1C->unkD0 = (f32) ((f64) sp1C->unkD0 + ((f64) D_801A8E38 + ((f64) arg0->unk1B8 * 4.0)));
    }
    return 0;
}

s32 func_80013624(UnkStruct_8000DDE0* arg0) {
    s32 sp5C;
    s32 sp58;
    u16 sp50[4];
    UnkStruct_8000E3D4* sp4C;
    UnkStruct_8000E3D4_unk5C* sp48;
    UnkStruct_8000DDE0* sp44;
    s32 pad40;
    s32* sp3C;
    s32* sp38;
    s32 sp34;
    u8* sp30;

    if (func_8000DA44(arg0, 4, sp50) < 0) {
        return -1;
    }
    sp4C = arg0->unk20C;
    if (arg0->unk1AC != 0xFFFF) {
        return -1;
    }
    if (sp4C->unk5C == NULL) {
        sp4C->unk5C = TempHeap_Alloc(sizeof(UnkStruct_8000E3D4_unk5C));
        sp44 = sp4C->unk5C->unk0 = TempHeap_Alloc(sizeof(UnkStruct_8000DDE0));
        sp44->unk1B0 = 256.0f;
        sp44->unk1B4 = 168.0f;
        sp44->unk0.unkC4 = 0x20;
        sp44->unk0.unkC8 = 0x7FFFFFFF;
        sp4C->unkC = &sp44->unk0;
        sp4C->unk5C->unk4 = NULL;
        sp4C->unk5C->unk8 = NULL;
        func_8001A690(sp44);
    } else {
        sp44 = sp4C->unk5C->unk0;
    }
    sp48 = sp4C->unk5C;
    for (sp5C = 0; sp5C < 2; sp5C++) {
        sp30 = sp44->unk0.ptrs[sp5C + 1];
        for (sp58 = 0; sp58 < 0xA800; sp58++, sp30++) {
            *sp30 = 0;
        }
    }
    sp44->unk0.unkCC = (s16) sp50[1];
    sp44->unk0.unkD0 = (s16) sp50[2];
    if (D_801A8D70 < 0x1F4) {
        sp3C = &D_8097F4D0;
        if (D_801A3070 == NULL) {
            sp38 = &D_80981A00;
        } else {
            sp38 = D_801A3070;
        }
    } else {
        sp3C = &D_809968B0;
        if (D_801A3078 == NULL) {
            sp38 = &D_80996A20;
        } else {
            sp38 = D_801A3078;
        }
    }
    sp38 = func_80096B38(gSeg_639B20_ROM_START, gSeg_639B20_VRAM, sp3C, sp38, &sp34, (s32) sp50[3]);
    if (sp48->unk4 == NULL) {
        sp48->unk4 = TempHeap_Alloc(0x40);
    }
    sp58 = func_80096D40(sp38, sp34, sp48->unk4);
    if (sp48->unk8 == NULL) {
        sp48->unk8 = TempHeap_Alloc(0x60);
    }
    sp4C->unk0 |= 0x200;
    return 0;
}

s32 func_800139B8(UnkStruct_8000DDE0* arg0) {
    s32 pad24;
    u16 sp20[1];
    UnkStruct_8000E3D4* sp1C;
    UnkStruct_8000E3D4_unk5C* sp18;

    if (func_8000DA44(arg0, 1, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    if (arg0->unk1AC != 0xFFFF) {
        return -1;
    }
    if (!(sp1C->unk0 & 0x200)) {
        return -1;
    }
    sp18 = sp1C->unk5C;
    func_8001AE90(sp18->unk0);
    TempHeap_Free(sp18->unk0);
    sp1C->unkC = NULL;
    TempHeap_Free(sp18->unk4);
    TempHeap_Free(sp18->unk8);
    TempHeap_Free(sp18);
    sp1C->unk5C = NULL;
    sp1C->unk0 &= ~0x200;
    return 0;
}

s32 func_80013AFC(UnkStruct_8000DDE0* arg0) {
    s32 sp34;
    u16 sp24[7];
    UnkStruct_8000E3D4* sp20;
    s32 pad[2];

    if (func_8000DA44(arg0, 7, sp24) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    sp20 = arg0->unk20C;
    if (sp24[4] == 0xFFFF) {
        func_800B3DBC(&sp20->unkC, &sp20->unk10, sp24[3]);
        sp20->unk4 = sp24[3];
        sp20->unk0 &= ~0x400;
        return 0;
    }
    sp20->unk50 = sp24[2];
    sp20->unk4C = (f32) sp20->unk50;
    sp20->unk52 = 0;
    for (sp34 = 0; sp34 < 4; sp34++) {
        sp20->unk54[sp34] = sp24[sp34 + 3];
    }
    sp20->unk0 |= 0x400;
    return 0;
}

s32 func_80013C90(UnkStruct_8000DDE0* arg0) {
    s32 i;
    s32 sp38;
    u16 sp28[8];
    UnkStruct_8000E3D4* sp24;
    SpriteObj* sp20;
    s16* colorPalette;

    if (func_8000DA44(arg0, 8, sp28) < 0) {
        return -1;
    }
    sp24 = arg0->unk20C;
    if (sp28[2] != 0) {
        sp24->unk84 = sp28[2];
        sp24->unk86 = sp28[3];
        sp24->unk88 = sp28[4];
        sp24->unk8A = sp28[5];
        sp24->unk90 = sp28[6];
        sp24->unk8C = sp28[7];
        sp24->unk80 = (f32) sp24->unk84;
        sp24->unk8E = 0;
        for (sp38 = 0, sp20 = sp24->unkC; sp38 < sp24->unk6; sp38++, sp20++) {
            if ((colorPalette = sp20->currentPaletteColors) == NULL) {
                continue;
            }
            for (i = 0; i < 256; i++, colorPalette++) {
                if (!((u16) *colorPalette & 0xFFFE)) {
                    *colorPalette = (u16) *colorPalette & 0xFFFE;
                }
            }
            SysMem_Copy8(&sp20->currentPaletteColors[sp24->unk86],
                         &(&sp20->currentPaletteColors[sp24->unk88])[(s16) sp24->unk90 * sp24->unk8E], sp24->unk8A * 2);
        }
        sp24->unk0 |= 0x1000;
    } else {
        sp24->unk0 &= ~0x1000;
    }
    return 0;
}

s32 func_80013F04(UnkStruct_8000DDE0* arg0) {
    s32 sp34;
    u16 sp2C[3];
    UnkStruct_8000E3D4* sp28;
    SpriteObj* sp24;

    if (func_8000DA44(arg0, 3, sp2C) < 0) {
        return -1;
    }
    sp28 = arg0->unk20C;
    for (sp34 = 0, sp24 = sp28->unkC; sp34 < sp28->unk6; sp34++, sp24++) {
        sp24->unkF4 = sp24->unkF8 = func_80014BD4(sp2C[2]);
    }
    return 0;
}

s32 func_80013FEC(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp24[4];
    UnkStruct_8000E3D4* sp20;
    SpriteObj* sp1C;

    if (func_8000DA44(arg0, 4, sp24) < 0) {
        return -1;
    }
    sp20 = arg0->unk20C;
    for (sp2C = 0, sp1C = sp20->unkC; sp2C < sp20->unk6; sp2C++, sp1C++) {
        sp1C->unkF4 = func_80014BD4(sp24[2]);
        sp1C->unkF8 = func_80014BD4(sp24[3]);
    }
    return 0;
}

s32 func_800140D8(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp20[5];
    UnkStruct_8000E3D4* sp1C;
    SpriteObj* sp18;

    if (func_8000DA44(arg0, 5, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    for (sp2C = 0; sp2C < 3; sp2C++) {
        sp1C->unk6C[sp2C] = 0.0f;
    }
    sp18 = sp1C->unkC;
    for (sp2C = 0, sp18 = sp1C->unkC; sp2C < sp1C->unk6; sp2C++, sp18++) {
        sp18->unkCC = func_80014BD4(sp20[2]);
        sp18->unkD0 = func_80014BD4(sp20[3]);
        sp18->unkD4 = func_80014BD4(sp20[4]);
    }
    return 0;
}

#ifdef NEEDS_RODATA
s32 func_80014228(UnkStruct_8000DDE0* arg0) {
    s32 pad28;
    u16 sp24[4];
    UnkStruct_8000E3D4* sp20;
    s32 pad1C;

    if (func_8000DA44(arg0, 4, sp24) < 0) {
        return -1;
    }
    sp20 = arg0->unk20C;
    sp20->unk62 = sp24[1];
    sp20->unk64 = (s16) sp24[2];
    sp20->unk66 = sp24[3];
    switch (sp20->unk62) {
        case 0xe000:
            sp20->unk78 = 0.0f;
            break;
        case 0xe002:
            if (sp20->unkC->unkCC > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xe003:
            if (sp20->unkC->unkD0 > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xe008:
            if ((arg0->unk1AC < 0x4000) || (arg0->unk1AC >= 0x8000)) {
                if (sp20->unk14 > (f32) (s16) sp20->unk66) {
                    sp20->unk68 = 1;
                } else {
                    sp20->unk68 = 0;
                }
            } else if (sp20->unkC->unkD4 > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xe009:
            if ((s32) (u16) sp20->unkC->unk11E > (s32) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xe00a:
            if (sp20->unkC->rotateX > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xe00b:
            if (sp20->unkC->rotateY > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
        case 0xe00c:
            if (sp20->unkC->rotateZ > (f32) (s16) sp20->unk66) {
                sp20->unk68 = 1;
            } else {
                sp20->unk68 = 0;
            }
            break;
    }
    arg0->unk1A8 |= 0x80;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014228.s")
#endif

#ifdef NEEDS_RODATA
s32 func_800145D4(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    u16 sp20[5];
    UnkStruct_8000E3D4* sp1C;
    SpriteObj* sp18;

    if (func_8000DA44(arg0, 5, sp20) < 0) {
        return -1;
    }
    sp1C = arg0->unk20C;
    if (sp20[4] == 0) {
        sp20[4] = 1U;
    }
    switch (sp20[2]) {
        case 0xe002:
            sp1C->unk98 = func_80014BD4(sp20[3]);
            sp1C->unkA4 = (f32) ((f64) ((sp1C->unk98 - sp1C->unk6C[0]) / (f32) (s16) sp20[4]) * 0.5);
            break;
        case 0xe003:
            sp1C->unk9C = func_80014BD4(sp20[3]);
            sp1C->unkA8 = (f32) ((f64) ((sp1C->unk9C - sp1C->unk6C[1]) / (f32) (s16) sp20[4]) * 0.5);
            break;
        case 0xe008:
            sp1C->unkA0 = func_80014BD4(sp20[3]);
            sp1C->unkAC = (f32) ((f64) ((sp1C->unkA0 - sp1C->unk6C[2]) / (f32) (s16) sp20[4]) * 0.5);
            break;
        case 0xe00a:
            sp1C->unkB0 = func_80014BD4(sp20[3]);
            sp1C->unkBC = (sp1C->unkB0 - sp1C->unk18) / (f32) (s16) sp20[4];
            sp1C->unk0 |= 0x20;
            for (sp2C = 0, sp18 = sp1C->unkC; sp2C < sp1C->unk6; sp2C++, sp18++) {
                sp18->unkC0 &= ~8;
                sp18->unkC0 |= 0x10;
            }
            break;
        case 0xe00b:
            sp1C->unkB4 = func_80014BD4(sp20[3]);
            sp1C->unkC0 = (sp1C->unkB4 - sp1C->unk1C) / (f32) (s16) sp20[4];
            sp1C->unk0 |= 0x20;
            for (sp2C = 0, sp18 = sp1C->unkC; sp2C < sp1C->unk6; sp2C++, sp18++) {
                sp18->unkC0 &= ~8;
                sp18->unkC0 |= 0x10;
            }
            break;
        case 0xe00c:
            sp1C->unkB8 = func_80014BD4(sp20[3]);
            sp1C->unkC4 = (sp1C->unkB8 - sp1C->unk20) / (f32) (s16) sp20[4];
            sp1C->unk0 |= 0x20;
            for (sp2C = 0, sp18 = sp1C->unkC; sp2C < sp1C->unk6; sp2C++, sp18++) {
                sp18->unkC0 &= ~8;
                sp18->unkC0 |= 0x10;
            }
            break;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800145D4.s")
#endif

s32 func_80014A80(UnkStruct_8000DDE0* arg0) {
    s32 pad28;
    u16 sp24[4];
    UnkStruct_8000E3D4* sp20;
    s32 pad1C;

    if (func_8000DA44(arg0, 4, sp24) < 0) {
        return -1;
    }
    if ((arg0->unk1AC >= 0x8000) && (arg0->unk1AC < 0x8010)) {
        return -1;
    }
    sp20 = arg0->unk20C;
    if (sp24[2] == 0) {
        sp20->unk0 |= 0x800;
    } else {
        sp20->unk0 &= ~0x800;
    }
    return 0;
}

s32 func_80014B5C(UnkStruct_801A306C* arg0) {
    UnkStruct_801A306C* sp4;
    s32 sp0;

    for (sp0 = 0, sp4 = D_801A306C; sp0 < D_801A1B48; sp0++, sp4++) {
        if (sp4 == arg0) {
            return TRUE;
        }
    }
    return FALSE;
}

f32 func_80014BD4(u16 arg0) {
    s32 sp4;
    s32 sp0;

    sp4 = (s16) arg0 / 256;
    if ((arg0 & 0x8000) >= 0x8000) {
        sp0 = (arg0 & 0xFF) | ~0xFF;
    } else {
        sp0 = arg0 & 0xFF;
    }
    return (f32) sp4 + ((f32) sp0 / 256.0f);
}
