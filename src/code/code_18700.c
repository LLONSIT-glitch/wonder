#include "common.h"

typedef struct UnkStruct_80017B80_s {
    char pad[0xF8];
    f32 unkF8;
    f32 unkFC;
    f32 unk100;
    f32 unk104;
    f32 unk108;
    f32 unk10C;
    f32 unk110;
    f32 unk114;
    f32 unk118;
    f32 unk11C;
} UnkStruct_80017B80;

typedef struct UnkStruct_801561D8_2_s {
    char pad[0x618];
    UnkStruct_801561D8 unk618;
    UnkStruct_801561D8 unk750;
} UnkStruct_801561D8_2;
extern UnkStruct_801561D8_2 D_801561D8[];

extern f32 D_801AA640[];
extern f32 D_801AA660;
extern f32 D_801AA664;
extern f32 D_801AA668;
extern f32 D_801AA66C;
extern f32 D_801AA670;
extern f32 D_801AA674;
extern f32 D_801AA678;
extern f32 D_801AA67C;

void func_800198F8(UnkStruct_8000DDE0*, s32); /* extern */

s32 func_80017B00(UnkStruct_8000DDE0* arg0) {
    UNUSED UnkStruct_8000DDE0* sp4;

    arg0->unk1A0 |= 8;
    arg0->unk1A8 = 0;
    arg0->unk1AC = 0;
    arg0->unk1EC = 0.0f;
    arg0->unk1E8 = arg0->unk1EC;
    arg0->unk1F4 = 0.0f;
    arg0->unk1F0 = arg0->unk1F4;
    arg0->unk20C = NULL;
    arg0->unk210 = NULL;
    *D_8015BAC8 = arg0;
    sp4 = arg0;
    return 0;
}

s32 func_80017B80(s32 arg0, f32 arg1) {
    UnkStruct_8000DDE0* sp3C;
    UnkStruct_8000DDE0* sp38;
    UnkStruct_801561D8* sp34;
    UnkStruct_801561D8* sp30;

    sp3C = func_80016074(0xC);
    if (sp3C == NULL) {
        return -1;
    }
    sp38 = sp3C;
    if (!(sp3C->unk1A8 & 7)) {
        func_800198F8(sp38, 1);
    }
    sp3C->unk1A8 |= 1;
    sp3C->unk1A8 &= ~6;
    sp3C->unk1AC = arg0;
    sp3C->unk1E8 = arg1;
    sp3C->unk1EC = 0.0f;
    if (*D_801A8D88 & 0x2000) {
        D_801AA660 = 20.0f;
        D_801AA664 = 2.0f;
        D_801AA668 = 300.0f;
        D_801AA66C = 225.0f;
        D_801AA670 = 20.0f;
        D_801AA674 = 2.0f;
        D_801AA678 = 300.0f;
        D_801AA67C = 225.0f;
    } else {
        D_801AA660 = 20.0f;
        D_801AA664 = 26.0f;
        D_801AA668 = 300.0f;
        D_801AA66C = 194.0f;
        D_801AA670 = 20.0f;
        D_801AA674 = 26.0f;
        D_801AA678 = 300.0f;
        D_801AA67C = 192.0f;
    }
    sp34 = &D_801561D8->unk618;
    sp30 = &D_801561D8->unk750;
    D_801AA640[0] = D_801AA640[1] = D_801AA640[2] = D_801AA640[3] = 0.0f;
    D_801AA640[4] = D_801AA640[5] = D_801AA640[6] = D_801AA640[7] = 0.0f;
    sp34->unkF8 = 320.0f;
    sp34->unk100 = 320.0f;
    sp34->unkFC = 240.0f;
    sp34->unk104 = 240.0f;
    sp30->unkF8 = 320.0f;
    sp30->unk100 = 320.0f;
    sp30->unkFC = 240.0f;
    sp30->unk104 = 240.0f;
    sp34->unk110 = (f32) D_801AA660;
    sp34->unk114 = (f32) D_801AA664;
    sp34->unk118 = (f32) D_801AA668;
    sp34->unk11C = (f32) D_801AA66C;
    sp30->unk110 = (f32) D_801AA660;
    sp30->unk114 = (f32) D_801AA664;
    sp30->unk118 = (f32) D_801AA668;
    sp30->unk11C = (f32) D_801AA66C;
    switch (sp3C->unk1AC) {
        case 9:
            sp30->unk114 = 0.0f;
            sp30->unk11C = 1.0f;
            break;
        case 8:
            D_801AA640[1] = (f32) (320.0f / arg1);
            D_801AA640[3] = (f32) (240.0f / arg1);
            D_801AA640[5] = (f32) (-320.0f / arg1);
            D_801AA640[7] = (f32) (-240.0f / arg1);
            sp34->unk100 = 1.0f;
            sp34->unk104 = 1.0f;
            break;
        case 1:
        case 2:
        case 3:
            D_801AA640[0] = (f32) (-320.0f / arg1);
            D_801AA640[1] = (f32) (320.0f / arg1);
            sp34->unkF8 = 640.0f;
            sp34->unk100 = 1.0f;
            D_801AA640[4] = (f32) (-320.0f / arg1);
            D_801AA640[5] = (f32) (-320.0f / arg1);
            if (sp3C->unk1AC == 1) {

            } else {
                if (sp3C->unk1AC == 3) {
                    goto case_5_6_7;
                }
                break;
                case 5:
                case 6:
                case 7:
                    D_801AA640[0] = (f32) (320.0f / arg1);
                    D_801AA640[1] = (f32) (320.0f / arg1);
                    sp34->unkF8 = 1.0f;
                    sp34->unk100 = 1.0f;
                    D_801AA640[4] = (f32) (320.0f / arg1);
                    D_801AA640[5] = (f32) (-320.0f / arg1);
                    if (sp3C->unk1AC == 7) {
                    } else {
                        if (sp3C->unk1AC == 5) {
                            goto case_5_6_7;
                        }
                        break;
                    }
            }

        case 0:
            D_801AA640[2] = (f32) (240.0f / arg1);
            D_801AA640[3] = (f32) (240.0f / arg1);
            sp34->unkFC = 1.0f;
            sp34->unk104 = 1.0f;
            D_801AA640[6] = (f32) (240.0f / arg1);
            D_801AA640[7] = (f32) (-240.0f / arg1);
            break;

        case 4:
        case_5_6_7:
            D_801AA640[2] = (f32) (-240.0f / arg1);
            D_801AA640[3] = (f32) (240.0f / arg1);
            sp34->unkFC = 480.0f;
            sp34->unk104 = 1.0f;
            D_801AA640[6] = (f32) (-240.0f / arg1);
            D_801AA640[7] = (f32) (-240.0f / arg1);
            break;
    }

    return 0;
}
void func_80019F4C(SpriteObj*); /* extern */

s32 func_80018380(UnkStruct_8000DDE0* arg0) {
    UnkStruct_801561D8* sp24;
    UnkStruct_801561D8* sp20;
    SpriteObj* sp1C;

    sp1C = &arg0->unk0;
    if (arg0->unk1A8 & 1) {
        sp24 = &D_801561D8->unk618;
        sp20 = &D_801561D8->unk750;
        if (arg0->unk1A8 & 4) {

        } else if (arg0->unk1E8 > 0.0f) {
            arg0->unk1E8 = (f32) ((f64) arg0->unk1E8 - (1.0 * (f64) D_8018257C));
            sp24->unkF8 += D_801AA640[0] * D_8018257C;
            sp24->unk100 += D_801AA640[1] * D_8018257C;
            sp24->unkFC += D_801AA640[2] * D_8018257C;
            sp24->unk104 += D_801AA640[3] * D_8018257C;
            sp20->unkF8 += D_801AA640[4] * D_8018257C;
            sp20->unk100 += D_801AA640[5] * D_8018257C;
            sp20->unkFC += D_801AA640[6] * D_8018257C;
            sp20->unk104 += D_801AA640[7] * D_8018257C;
            switch (arg0->unk1AC) {
                case 9:
                    sp24->unkF8 = 320.0f;
                    sp24->unk100 = 320.0f;
                    sp24->unkFC = 240.0f;
                    sp24->unk104 = 240.0f;
                    sp24->unk110 = D_801AA660;
                    sp24->unk114 = D_801AA664;
                    sp24->unk118 = D_801AA668;
                    sp24->unk11C = D_801AA66C;
                    sp20->unk114 = 0.0f;
                    sp20->unk11C = 1.0f;
                    break;
                case 8:
                    if (sp24->unk100 > 320.0f) {
                        sp24->unk100 = 320.0f;
                    }
                    if (sp24->unk104 > 240.0f) {
                        sp24->unk104 = 240.0f;
                    }
                    if (sp20->unk100 < 1.0f) {
                        sp20->unk100 = 1.0f;
                    }
                    if (sp20->unk104 < 1.0f) {
                        sp20->unk104 = 1.0f;
                    }
                    sp24->unk110 = 160.0f - (((160.0f - D_801AA670) * sp24->unk100) / 320.0f);
                    sp24->unk118 = (((D_801AA678 - 160.0f) * sp24->unk100) / 320.0f) + 160.0f;
                    sp24->unk114 = 120.0f - (((120.0f - D_801AA674) * sp24->unk104) / 240.0f);
                    sp24->unk11C = (((D_801AA67C - 120.0f) * sp24->unk104) / 240.0f) + 120.0f;
                    sp20->unk110 = 160.0f - (((160.0f - D_801AA670) * sp20->unk100) / 320.0f);
                    sp20->unk118 = (((D_801AA678 - 160.0f) * sp20->unk100) / 320.0f) + 160.0f;
                    sp20->unk114 = 120.0f - (((120.0f - D_801AA674) * sp20->unk104) / 240.0f);
                    sp20->unk11C = (((D_801AA67C - 120.0f) * sp20->unk104) / 240.0f) + 120.0f;
                    if (sp24->unk110 >= sp24->unk118) {
                        sp24->unk110 = sp24->unk118 - 1.0f;
                    }
                    if (sp24->unk110 < D_801AA660) {
                        sp24->unk110 = D_801AA660;
                    }
                    if (sp24->unk118 > D_801AA668) {
                        sp24->unk118 = D_801AA668;
                    }
                    if (sp24->unk114 >= sp24->unk11C) {
                        sp24->unk114 = sp24->unk11C - 1.0f;
                    }
                    if (sp24->unk114 < D_801AA664) {
                        sp24->unk114 = D_801AA664;
                    }
                    if (sp24->unk11C > D_801AA66C) {
                        sp24->unk11C = D_801AA66C;
                    }
                    if (sp20->unk110 >= sp20->unk118) {
                        sp20->unk110 = sp20->unk118 - 1.0f;
                    }
                    if (sp20->unk110 < D_801AA660) {
                        sp20->unk110 = D_801AA660;
                    }
                    if (sp20->unk118 > D_801AA668) {
                        sp20->unk118 = D_801AA668;
                    }
                    if (sp20->unk114 >= sp20->unk11C) {
                        sp20->unk114 = sp20->unk11C - 1.0f;
                    }
                    if (sp20->unk114 < D_801AA664) {
                        sp20->unk114 = D_801AA664;
                    }
                    if (sp20->unk11C > D_801AA66C) {
                        sp20->unk11C = D_801AA66C;
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    if (sp24->unkF8 < 320.0f) {
                        sp24->unkF8 = 320.0f;
                    }
                    if (sp24->unk100 > 320.0f) {
                        sp24->unk100 = 320.0f;
                    }
                    if (sp20->unkF8 < 1.0f) {
                        sp20->unkF8 = 1.0f;
                    }
                    if (sp20->unk100 < 1.0f) {
                        sp20->unk100 = 1.0f;
                    }
                    sp24->unk110 = sp20->unk100 + ((D_801AA670 * sp24->unk100) / 320.0f);
                    sp24->unk118 = sp20->unk100 + ((D_801AA678 * sp24->unk100) / 320.0f);
                    sp20->unk110 = (sp20->unk100 * D_801AA670) / 320.0f;
                    sp20->unk118 = (sp20->unk100 * D_801AA678) / 320.0f;
                    if (sp24->unk110 > D_801AA668) {
                        sp24->unk110 = D_801AA668;
                    }
                    if (sp24->unk118 > (D_801AA668 + 1.0f)) {
                        sp24->unk118 = D_801AA668 + 1.0f;
                    }
                    if (sp20->unk110 < (D_801AA660 - 1.0f)) {
                        sp20->unk110 = D_801AA660 - 1.0f;
                    }
                    if (sp20->unk118 < D_801AA660) {
                        sp20->unk118 = D_801AA660;
                    }
                    if (arg0->unk1AC == 1) {

                    } else {
                        if (arg0->unk1AC == 3) {
                            goto case_5_6_7;
                        }
                        break;
                        case 5:
                        case 6:
                        case 7:
                            if (sp24->unkF8 > 320.0f) {
                                sp24->unkF8 = 320.0f;
                            }
                            if (sp24->unk100 > 320.0f) {
                                sp24->unk100 = 320.0f;
                            }
                            if (sp20->unk100 < 1.0f) {
                                sp20->unk100 = 1.0f;
                            }
                            sp24->unk110 = (sp24->unk100 * D_801AA670) / 320.0f;
                            sp24->unk118 = (sp24->unk100 * D_801AA678) / 320.0f;
                            sp20->unk110 = sp24->unk100 + ((D_801AA670 * sp20->unk100) / 320.0f);
                            sp20->unk118 = sp24->unk100 + ((D_801AA678 * sp20->unk100) / 320.0f);
                            if (sp24->unk110 < (D_801AA660 - 1.0f)) {
                                sp24->unk110 = D_801AA660 - 1.0f;
                            }
                            if (sp24->unk118 < D_801AA660) {
                                sp24->unk118 = D_801AA660;
                            }
                            if (sp20->unk110 > D_801AA668) {
                                sp20->unk110 = D_801AA668;
                            }
                            if (sp20->unk118 > (D_801AA668 + 1.0f)) {
                                sp20->unk118 = D_801AA668 + 1.0f;
                            }

                            if (arg0->unk1AC == 7) {

                            } else {
                                if (arg0->unk1AC == 5) {
                                    goto case_5_6_7;
                                }
                                break;
                            }
                    }

                case 0:
                    if (sp24->unkFC > 240.0f) {
                        sp24->unkFC = 240.0f;
                    }
                    if (sp24->unk104 > 240.0f) {
                        sp24->unk104 = 240.0f;
                    }
                    if (sp20->unk104 < 1.0f) {
                        sp20->unk104 = 1.0f;
                    }
                    sp24->unk114 = (sp24->unk104 * D_801AA674) / 240.0f;
                    sp24->unk11C = (sp24->unk104 * D_801AA67C) / 240.0f;
                    sp20->unk114 = sp24->unk104 + ((D_801AA674 * sp20->unk104) / 240.0f);
                    sp20->unk11C = sp24->unk104 + ((D_801AA67C * sp20->unk104) / 240.0f);
                    if (sp24->unk114 < (D_801AA664 - 1.0f)) {
                        sp24->unk114 = D_801AA664 - 1.0f;
                    }
                    if (sp24->unk11C < D_801AA664) {
                        sp24->unk11C = D_801AA664;
                    }
                    if (sp20->unk114 > D_801AA66C) {
                        sp20->unk114 = D_801AA66C;
                    }
                    if (sp20->unk11C > (D_801AA66C + 1.0f)) {
                        sp20->unk11C = D_801AA66C + 1.0f;
                    }
                    break;

                case 4:
                case_5_6_7:
                    if (sp24->unkFC < 240.0f) {
                        sp24->unkFC = 240.0f;
                    }
                    if (sp24->unk104 > 240.0f) {
                        sp24->unk104 = 240.0f;
                    }
                    if (sp20->unkFC < 1.0f) {
                        sp20->unkFC = 1.0f;
                    }
                    if (sp20->unk104 < 1.0f) {
                        sp20->unk104 = 1.0f;
                    }
                    sp24->unk114 = sp20->unk104 + ((D_801AA674 * sp24->unk104) / 240.0f);
                    sp24->unk11C = sp20->unk104 + ((D_801AA67C * sp24->unk104) / 240.0f);
                    sp20->unk114 = (f32) ((sp20->unk104 * D_801AA674) / 240.0f);
                    sp20->unk11C = (f32) ((sp20->unk104 * D_801AA67C) / 240.0f);
                    if (sp24->unk114 > D_801AA66C) {
                        sp24->unk114 = D_801AA66C;
                    }
                    if (sp24->unk11C > (D_801AA66C + 1.0f)) {
                        sp24->unk11C = D_801AA66C + 1.0f;
                    }
                    if (sp20->unk114 < (D_801AA664 - 1.0f)) {
                        sp20->unk114 = (f32) (D_801AA664 - 1.0f);
                    }
                    if (sp20->unk11C < D_801AA664) {
                        sp20->unk11C = (f32) D_801AA664;
                    }
                    break;
            }
            MtxUtil_PushIdentity();
            func_8009A14C(&arg0->unk0);
            func_800997D8(&arg0->unk0);
            MtxUtil_Pop();
        } else {
            arg0->unk1A8 &= ~1;
            arg0->unk1A8 |= 2;
            sp24->unkF8 = 320.0f;
            sp24->unk100 = 320.0f;
            sp20->unkF8 = 320.0f;
            sp20->unk100 = 320.0f;
            sp24->unkFC = 240.0f;
            sp24->unk104 = 240.0f;
            sp20->unkFC = 240.0f;
            sp20->unk104 = 240.0f;
            sp24->unk110 = D_801AA660;
            sp24->unk114 = D_801AA664;
            sp24->unk118 = D_801AA668;
            sp24->unk11C = D_801AA66C;
            sp20->unk110 = D_801AA660;
            sp20->unk114 = D_801AA664;
            sp20->unk118 = D_801AA668;
            sp20->unk11C = D_801AA66C;
        }
    } else if (arg0->unk1A8 & 2) {
        arg0->unk1A8 = (s32) (arg0->unk1A8 & ~7);
        func_80019F4C(sp1C);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_18700/func_800198F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_18700/func_80019C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_18700/func_80019F4C.s")
