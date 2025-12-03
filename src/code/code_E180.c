#include "common.h"

typedef struct UnkStruct_8000D74C_s {
    char pad[0xC];
    s32 unkC;
    s32 unk10;
} UnkStruct_8000D74C;

s32 func_80004654(s32);  /* extern */
s32 func_800B55B0(s32);  /* extern */
s32 func_800B56F0(void); /* extern */

extern s32 D_80156C10;
extern s32 D_8015F804;
extern UnkStruct_8000DDE0** D_8015F80C;
extern UnkStruct_8000DDE0* D_8015F818[];
extern s32 D_80949150;
extern s32 D_80993AE0;
extern s32 D_80993C00;

s32 func_8000D580(UnkStruct_8000DDE0* arg0) {
    s32 pad;

    arg0->unk1A0 = 3;
    arg0->unk1A8 = 0;
    return 0;
}

s32 func_8000D5A8(s32 arg0) {
    s32 sp1C;

    for (sp1C = 0; sp1C < 0x14; sp1C++) {
        if (D_8015F818[sp1C] == 0) {
            break;
        }
    }
    if (sp1C == 0x14) {
        return -1;
    }
    D_8015F80C = &D_8015F818[sp1C];
    D_8015F804 = arg0;
    if (func_80004654(0x11) < 0) {
        return -1;
    }
    *D_8015F80C = D_80156C10;
    return 0;
}

s32 func_8000D688(s32 arg0) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x14; sp4++) {
        if (D_8015F818[sp4] != 0) {
            D_8015F80C = &D_8015F818[sp4];
            if (((*D_8015F80C)->unk1AC == (arg0 & 0xFFFF)) && !((*D_8015F80C)->unk1A8 & 4)) {
                return *D_8015F80C;
            }
        }
    }
    return 0;
}

s32 func_8000D74C(UnkStruct_8000DDE0* arg0) {
    s32 sp1C;
    UnkStruct_8000D74C* sp18;

    for (sp1C = 0; sp1C < 0x14; sp1C++) {
        if (D_8015F818[sp1C] == arg0) {
            D_8015F818[sp1C] = NULL;
            arg0->unk1A0 = 0;
            arg0->unk1A8 = 0;
            if (arg0->unk20C != NULL) {
                sp18 = arg0->unk20C;
                if (((arg0->unk1AC < 0x4000) || (arg0->unk1AC >= 0x8010)) && (sp18->unkC != NULL)) {
                    TempHeap_Free(sp18->unkC);
                    sp18->unkC = NULL;
                }
                if (sp18->unk10 != NULL) {
                    TempHeap_Free(sp18->unk10);
                    sp18->unk10 = NULL;
                }
                TempHeap_Free(arg0->unk20C);
                arg0->unk20C = NULL;
            }
            if (arg0->unk210 != NULL) {
                TempHeap_Free(arg0->unk210);
                arg0->unk210 = NULL;
            }
            return 0;
        }
    }
    return -1;
}

void func_8000D90C(UnkStruct_8000DDE0* arg0) {
    arg0->unk1EC = 0.0f;
    arg0->unk1E8 = (f32) arg0->unk1EC;
}

s32 func_8000D934(s32 arg0, s32 arg1, u16* arg2) {
    s32 sp24;
    s32 sp20;
    UnkStruct_8000DDE0* sp1C;

    sp1C = func_8000D688(arg0);
    if (sp1C == NULL) {
        return -1;
    }
    for (sp24 = 0; sp24 < arg1; sp24++) {
        sp20 = (s32) sp1C->unk1EC % 128;
        sp1C->unk210[sp20] = *arg2++;
        sp1C->unk1EC = (f32) (sp1C->unk1EC + 1.0f);
    }
    return 0;
}

s32 func_8000DA44(UnkStruct_8000DDE0* arg0, s32 arg1, s16* arg2) {
    s32 sp4;
    s32 sp0;

    for (sp4 = 0; sp4 < arg1; sp4++) {
        if (arg0->unk1EC == arg0->unk1E8) {
            return -1;
        }
        sp0 = (s32) arg0->unk1E8 % 128;
        *arg2++ = arg0->unk210[sp0];
        arg0->unk1E8 += 1.0f;
    }
    return 0;
}

s32 func_8000DB14(UnkStruct_8000DDE0* arg0) {
    s32 sp34;
    union {
        s16 s;
        s32 w;
    } sp30;
    s16 sp2E;
    s16 sp2C;
    s32* sp28;
    s16* sp24;

    if (D_801A8C40 == -2) {
        return 0;
    }
    if (*D_801A8D88 & 0x80) {
        return 0;
    }
    if ((D_801A3068 != NULL) && (D_801A3068->unk4 & 2)) {
        arg0->unk1A0 = (s32) (arg0->unk1A0 | 8);
        return 0;
    }
    if (arg0->unk1A8 == 0) {
        if (D_801A8D70 < 0x1F4) {
            sp28 = &D_80947340;
            sp24 = (s16*) &D_80949150;
        } else {
            sp28 = &D_80993AE0;
            sp24 = (s16*) &D_80993C00;
        }

        do {
            SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) D_801829B8, (s32) D_801849C0, (s32) sp28), &sp2C,
                           0xC);
            if ((sp2C == D_801A8D70) && (sp2E == D_801A8D78) && (sp30.s == D_801A8D80)) {
                arg0->unk1A8 = (s32) (arg0->unk1A8 | 1);
                break;
            }
            sp28 += 3; // TODO: Might be a custom type!
        } while (sp2C != -1);
        if (arg0->unk1A8 == 0) {
            return -1;
        }
        if (func_800B55B0(
                SysMem_GetPhysicalAddressFromVirtual((u32) D_801829B8, (s32) D_801849C0, (s32) &sp24[sp34])) != 0) {
            arg0->unk1A8 = 0;
        }
        return 0;
    }
    if (func_800B56F0() != 0) {
        arg0->unk1A8 = 0;
        if (D_801A3068 != NULL) {
            D_801A3068->unk4 = 0;
        }
    }
    return 0;
}

s32 func_8000DD94(UnkStruct_8000DDE0* arg0) {
    arg0->unk1A8 = 0;
    if (D_801A3068 != NULL) {
        D_801A3068->unk4 = 0;
    }
    return 0;
}
