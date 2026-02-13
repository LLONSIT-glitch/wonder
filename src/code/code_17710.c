#include "common.h"

extern f32 D_80156190;
extern f32 D_80156194;
extern f32 D_80156198;
extern f32 D_8015619C;
extern f32 D_801561C0;
extern f32 D_801561C4;
extern f32 D_801561C8;
extern f32 D_801561D0;
extern f32 D_801A7224;
extern f32 D_801A7230;

s32 func_80016B10(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 pad;

    arg0->unk1A0 |= 8;
    arg0->unk1A8 = 0;
    arg0->unk1AC = 0;
    arg0->unk1EC = 0.0f;
    arg0->unk1E8 = arg0->unk1EC;
    arg0->unk1F4 = 0.0f;
    arg0->unk1F0 = arg0->unk1F4;
    *D_8015BAC8 = arg0;
    D_80156190 = D_801561C0 + D_801A7224;
    D_80156198 = D_801561C8 + D_801A7224;
    D_80156194 = D_801561C4 - D_801A7230;
    D_8015619C = D_801561D0 - D_801A7230;
    return 0;
}

s32 func_80016BF4(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    UnkStruct_8000DDE0* sp1C;
    UnkStruct_8000DDE0* sp18;

    sp1C = func_80016074(0xE);
    if (sp1C == NULL) {
        return -1;
    }
    sp18 = sp1C;
    sp1C->unk1A8 |= 1;
    sp1C->unk1A8 &= ~6;
    sp1C->unk1EC = arg3;
    sp1C->unk1E8 = sp1C->unk1EC;
    sp1C->unk1F4 = 0.0f;
    sp1C->unk1F0 = sp1C->unk1F4;
    sp1C->unk1FC = 0.0f;
    sp1C->unk1F8 = sp1C->unk1FC;
    if (arg2 & 4) {
        sp18->unk0.unkD0 = -1.0f;
        sp18->unk0.unkCC = sp18->unk0.unkD0;
        if (arg2 & 1) {
            D_80156190 = D_80156198 = arg0;
            sp1C->unk1F0 = -arg0 / arg3;
            sp1C->unk1F4 = (320.0f - arg0) / arg3;
        } else {
            D_80156190 = D_801561C0 + D_801A7224;
            D_80156198 = D_801561C8 + D_801A7224;
        }
        if (arg2 & 2) {
            D_80156194 = D_8015619C = arg1;
            sp1C->unk1F8 = -arg1 / arg3;
            sp1C->unk1FC = (240.0f - arg1) / arg3;
        } else {
            D_80156194 = D_801561C4 - D_801A7230;
            D_8015619C = D_801561D0 - D_801A7230;
        }
    } else if (arg2 & 8) {
        sp18->unk0.unkCC = arg0;
        sp18->unk0.unkD0 = arg1;
        if (arg2 & 1) {
            sp1C->unk1F0 = (arg0 - D_80156190) / arg3;
            sp1C->unk1F4 = -(D_80156198 - arg0) / arg3;
        }
        if (arg2 & 2) {
            sp1C->unk1F8 = (arg1 - D_80156194) / arg3;
            sp1C->unk1FC = -(D_8015619C - arg1) / arg3;
        }
    } else {
        return 1;
    }
    return 0; // deaaad code
}

s32 func_80016F80(UnkStruct_8000DDE0* arg0) {
    UnkStruct_80099E2C* sp4;
    s32 sp0;

    sp4 = &arg0->unk0;
    sp0 = 0;
    if (arg0->unk1A8 & 1) {
        if (arg0->unk1A8 & 4) {

        } else if (arg0->unk1E8 > 0.0f) {
            arg0->unk1E8 = (f32) ((f64) arg0->unk1E8 - (1.0 * (f64) D_8018257C));
            D_80156190 += arg0->unk1F0 * D_8018257C;
            D_80156198 += arg0->unk1F4 * D_8018257C;
            D_80156194 += arg0->unk1F8 * D_8018257C;
            D_8015619C += arg0->unk1FC * D_8018257C;
        } else {
            arg0->unk1A8 = (s32) (arg0->unk1A8 & ~1);
            arg0->unk1A8 = (s32) (arg0->unk1A8 | 2);
            if (sp4->unkCC == -1.0f) {
                D_80156190 = D_801561C0 + D_801A7224;
                D_80156198 = D_801561C8 + D_801A7224;
                D_80156194 = D_801561C4 - D_801A7230;
                D_8015619C = D_801561D0 - D_801A7230;
            } else {
                D_80156190 = D_80156198 = sp4->unkCC;
                D_80156194 = D_8015619C = sp4->unkD0;
            }
        }
    } else if (arg0->unk1A8 & 2) {
        arg0->unk1A8 = (s32) (arg0->unk1A8 & ~2);
    }
    if (D_80156190 < (D_801561C0 + D_801A7224)) {
        D_80156190 = D_801561C0 + D_801A7224;
    }
    if (D_80156194 < (D_801561C4 - D_801A7230)) {
        D_80156194 = D_801561C4 - D_801A7230;
    }
    if (D_80156198 > (D_801561C8 + D_801A7224)) {
        D_80156198 = D_801561C8 + D_801A7224;
    }
    if (D_8015619C > (D_801561D0 - D_801A7230)) {
        D_8015619C = D_801561D0 - D_801A7230;
    }
    if (D_80156190 < 0.0f) {
        D_80156190 = 0.0f;
    }
    if (D_80156198 > 320.0f) {
        D_80156198 = 320.0f;
    }
    if (D_80156194 < 0.0f) {
        D_80156194 = 0.0f;
    }
    if (D_8015619C > 240.0f) {
        D_8015619C = 240.0f;
    }
    return 0;
}
