#include "common.h"

typedef struct UnkStruct_800E114C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_800E114C;
typedef s32 (*FuncPtr2)(void*);

typedef struct UnkStruct_800DDB70_s {
    FuncPtr2 routine;
    s32 unk4;
} UnkStruct_800DDB70;

extern UnkStruct_800DDB70 D_800DDB70[];

typedef struct UnkStruct_801561A0_s {
    /* 0x00 */ f32 unk0;  /* inferred */
    /* 0x04 */ f32 unk4;  /* inferred */
    /* 0x08 */ f32 unk8;  /* inferred */
    /* 0x0C */ f32 unkC;  /* inferred */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ f32 unk14; /* inferred */
    /* 0x18 */ s16 unk18; /* inferred */
    /* 0x1A */ u16 unk1A; /* inferred */
    s16 unk1C;
} UnkStruct_801561A0; /* size = 0x1C */

extern UnkStruct_800E114C D_800E114C[];
extern UnkStruct_8000DDE0 D_80156DC0[0x20];
extern UnkStruct_8000DDE0 D_80156C20[];
extern s32 D_800E1148;
extern s16 D_801A7268;

void func_800047C8(UnkStruct_801561A0* arg0);

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_80002F20.s")

UnkStruct_800E114C* func_80004410(u16 arg0, u16 arg1) {
    s32 sp4;

    for (sp4 = 0; sp4 < D_800E1148; sp4++) {
        if ((D_800E114C[sp4].unk0 == arg0)) {
            if ((D_800E114C[sp4].unk4 == arg1)) {
                return &D_800E114C[sp4];
            }
        }
    }

    return NULL;
}

void func_800044BC(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 32; sp4++) {
        D_80156DC0[sp4].unk0.unk0 = 0;
    }
}

void func_80004510(void) {
    s32 sp4;
    s32 sp0;

    for (sp0 = 0, sp4 = 0; sp4 < 32; sp4++) {
        if (!(D_80156DC0[sp4].unk0.unk0 & 2)) {
            D_80156DC0[sp4].unk0.unk0 = 0;
            sp0 += 1;
        }
    }
}

UnkStruct_8000DDE0* func_800045AC(s32 arg0) {
    s32 sp4;

    for (sp4 = 0; sp4 < 32; sp4++) {
        if ((D_80156C20[sp4].unk1A0 & 1) && (D_80156C20[sp4].unk1A4 == arg0)) {
            return &D_80156C20[sp4];
        }
    }
    return NULL;
}

extern UnkStruct_8000DDE0* D_80156C10;

s32 func_80004654(s32 arg0) {
    UnkStruct_8000DDE0* sp1C;
    s32 sp18;

    for (sp18 = 0; sp18 < 32; sp18++) {
        if (!(D_80156DC0[sp18].unk0.unk0 & 1) && !(D_80156DC0[sp18].unk0.unk0 & 4)) {
            break;
        }
    }
    if (sp18 == 32) {
        return -1;
    }

    sp1C = &D_80156C20[sp18];
    sp1C->unk1A0 = 1;
    sp1C->unk1A4 = arg0;
    if (D_800DDB70[sp1C->unk1A4].routine == NULL) {
        sp1C->unk1A0 = 0;
        return 1;
    }
    if (D_800DDB70[sp1C->unk1A4].routine(sp1C) < 0) {
        sp1C->unk1A0 = 0;
    }
    D_80156C10 = sp1C;
    return 0;
}

void func_800047C8(UnkStruct_801561A0* arg0) {
    union {
        UnkStruct_801A7340_unk144* structptr;
        u16* sptr;
    } sp14;
    u16 spC[4];
    u16 sp4[4];

    arg0->unk0 = 0.0f;
    arg0->unk4 = 0.0f;
    arg0->unk8 = 0.0f;
    arg0->unkC = 0.0f;
    arg0->unk10 = 0.0f;
    arg0->unk14 = 0.0f;
    arg0->unk1A = 0xFFFF;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    if ((sp14.structptr = D_801A8C18->unk144) == NULL) {
        return;
    }

    while (TRUE) {
        if ((sp14.structptr->unk0 == 0x8000) && (sp14.structptr->unk2 == 0x8000)) {
            break;
        }
        *sp4 = sp14.structptr->unk0;
        sp14.sptr = &sp14.structptr->unk2;
        sp4[1] = *(u16*) sp14.sptr++;
        sp4[2] = *(u16*) sp14.sptr++;
        sp4[3] = *(u16*) sp14.sptr++;
        spC[0] = *(u16*) sp14.sptr++;
        spC[1] = *(u16*) sp14.sptr++;
        spC[2] = *(u16*) sp14.sptr++;
        spC[3] = *(u16*) sp14.sptr++;
        if (((spC[0] & 0x7F00) == 0x4000) && ((((s32) spC[0] >> 2) & 0xF) == D_801A7268)) {
            arg0->unk0 = (f32) ((s16) sp4[0] + (s16) sp4[2]) / 2.0f;
            arg0->unk4 = (f32) (s16) sp4[1];
            arg0->unk8 = (f32) (s16) sp4[0];
            arg0->unkC = (f32) (s16) sp4[1];
            arg0->unk10 = (f32) (s16) sp4[2];
            arg0->unk14 = (f32) (s16) sp4[3];
            arg0->unk1A = spC[1];
            arg0->unk18 = spC[2] & 0xFF;
            arg0->unk1C = (s16) (((s32) spC[2] >> 8) & 0xFF);
            break;
        }
    }
}

extern f32 D_801A8E38;

void func_80004ADC(void) {
    union {
        UnkStruct_801A7340_unk144* structptr;
        u16* sptr;
    } sp14;
    u16 spC[4];
    u16 sp4[4];

    D_801A8E38 = 0.0f;
    if ((sp14.structptr = D_801A8C18->unk144) == NULL) {
        return;
    }

    while (TRUE) {
        if ((sp14.structptr->unk0 == 0x8000) && (sp14.structptr->unk2 == 0x8000)) {
            break;
        }

        *sp4 = sp14.structptr->unk0;

        sp14.sptr = &sp14.structptr->unk2;

        sp4[1] = *(u16*) sp14.sptr++;

        sp4[2] = *(u16*) sp14.sptr++;

        sp4[3] = *(u16*) sp14.sptr++;
        spC[0] = *(u16*) sp14.sptr++;
        spC[1] = *(u16*) sp14.sptr++;
        spC[2] = *(u16*) sp14.sptr++;
        spC[3] = *(u16*) sp14.sptr++;

        if ((spC[0] & 0x7F00) != 0x300) {
            continue;
        }
        D_801A8E38 = (f32) ((s16) sp4[1] + (s16) sp4[3]) / 2.0f;
        break;
    }
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_80004CD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_80005124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_800051D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_80005284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_80005460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_800055DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_3B20/func_80005758.s")

s32 func_800057E8(void) {
    s32 sp4;
    s32 sp0;

    for (sp4 = 0, sp0 = 0; sp0 < 4; sp0++) {
        sp4 |= D_801A8C24[sp0].unkC0;
    }

    if (!(sp4 & 0x10000000)) {
        return -1;
    }
    return 0;
}
