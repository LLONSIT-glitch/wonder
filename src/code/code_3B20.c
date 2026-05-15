#include "common.h"

typedef s32 (*FuncPtr2)(void*);

typedef struct UnkStruct_800E114C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_800E114C;

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

typedef struct UnkStruct_sp84_s {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 pad8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} UnkStruct_sp84;

typedef struct UnkStruct_8000DDE0_unk20C_s {
    char pad[0x14];
    u16 unk14;
} UnkStruct_8000DDE0_unk20C;

extern UnkStruct_800E114C D_800E114C[];
extern UnkStruct_8000DDE0 D_80156DC0[0x20];
extern UnkStruct_8000DDE0 D_80156C20[];
extern s32 D_800E1148;
extern s16 D_801A7268;
extern s32 D_800F18EC;
extern f32 D_801561C4;
extern f32 D_801561D8[];
extern f32 D_8015BB2C;
extern f32 D_8015BB34;
extern f32 D_8015BB3C;
extern s16 D_80180664;
extern s16 gInteractionWaitTimer;
extern f32 D_80180EF0;
extern s16 D_801A7228;
extern f32 D_801A7230;
extern s32 D_801A7244;
extern f32 D_801A7264;
extern f32 D_801A7270;
extern f32 D_801A727C;
extern SpriteObj* D_801A8C30;
extern s32 D_801A8E44;
extern f32 D_801A8E38;

void func_800047C8(UnkStruct_801561A0* arg0);
s32 func_80004654(s32);                                                /* extern */
void func_80004ADC(void);                                              /* extern */
s32 func_80004CD4(u16**, s32);                                         /* extern */
void func_8000BB00(void);                                              /* extern */
void func_8000BC7C(void);                                              /* extern */
void func_8000BDDC(UnkStruct_8000DDE0*);                               /* extern */
void func_8000C3B0(UnkStruct_8000DDE0*);                               /* extern */
void func_80015E50(void);                                              /* extern */
void func_80015E94(s32);                                               /* extern */
void func_80015FB4(s32);                                               /* extern */
void func_800161E0(void);                                              /* extern */
void func_80016620(f32*);                                              /* extern */
void func_80017B80(s32, f32);                                          /* extern */
void func_80019F4C(UnkStruct_8000DDE0*);                               /* extern */
void func_8001A040(s32, s32, f32, f32, f32);                           /* extern */
void func_8002F5C4(s16);                                               /* extern */
void func_80043DC0(u16);                                               /* extern */
void func_8005D800(void);                                              /* extern */
void func_8005E19C(void);                                              /* extern */
void func_8005E474(void);                                              /* extern */
void func_800821A0(void);                                              /* extern */
s32 func_800A66EC(s32, UnkStruct_sp84*, s32, s32, s32, s32, f32, s32); /* extern */
s32 func_800BB578(void);                                               /* extern */

// File funcs
UnkStruct_800E114C* func_80004410(u16 arg0, u16 arg1);
UnkStruct_8000DDE0* func_800045AC(s32 arg0);
void func_80004510(void);

s32 func_80002F20(void) {
    s32 sp104;
    s32 sp100;
    s32 pad2;
    UnkStruct_800E114C* spF8;
    u16* spF4;
    char pad3[0x6C];
    UnkStruct_sp84* sp84;
    void* sp80;
    UnkStruct_sp84 sp60;
    UnkStruct_sp84 sp40;
    UnkStruct_8000DDE0* sp3C;
    void* sp38;

    D_801A8D88[0] |= 2;
    func_80098820();
    func_800C0A40();
    if ((D_801A8D88[0] & 0x80) || (D_801A8D88[3] & 0x4000)) {
        D_801A8D88[3] = (u16) (D_801A8D88[3] & ~0x4000);
        func_8000BB00();
    } else if ((D_801A8C58 != D_801A8C40) && (D_801A8C58 >= 0) && (D_801A8C40 >= 0)) {
        sp3C = func_800045AC(3);
        if (sp3C != NULL) {
            sp100 = (s32) D_801A8C40;
            func_8000C3B0(sp3C);
            D_801A8D88[3] &= ~0x4000;
            sp3C->unk1A8 |= 1;
            func_8000BB00();
            D_801A8C40 = (s16) sp100;
            sp3C = func_80016074(0xC);
            if ((sp3C != NULL)) {
                if (sp3C->unk1A8 & 7) {
                    func_80019F4C(sp3C);
                }
            }
            sp3C = func_80016074(0xB);
            if ((sp3C != NULL)) {
                if ((sp3C->unk1A8 & 7)) {
                    func_80019F4C(sp3C);
                }
            }
        }
    } else if ((D_801A8C58 == D_801A8C40) && (D_801A8C40 >= 0)) {
        sp3C = func_800045AC(3);
        if ((sp3C != NULL) && (sp3C->unk20C != NULL) && (((UnkStruct_8000DDE0_unk20C*) (sp3C->unk20C))->unk14 & 1)) {
            sp100 = (s32) D_801A8C40;
            func_8000C3B0(sp3C);
            D_801A8D88[3] = (u16) (D_801A8D88[3] & ~0x4000);
            sp3C->unk1A8 |= 1;
            func_8000BB00();
            D_801A8C40 = (s16) sp100;
            sp3C = func_80016074(0xC);
            if ((sp3C != NULL)) {
                if ((sp3C->unk1A8 & 7)) {
                    func_80019F4C(sp3C);
                }
            }
            sp3C = func_80016074(0xB);
            if ((sp3C != NULL)) {
                if ((sp3C->unk1A8 & 7)) {
                    func_80019F4C(sp3C);
                }
            }
        }
    }
    func_800BCB54();
    func_800BDC70(0, 0xC8, 0, 1);
    D_801A7238 = 0;
    D_801A7244 = -1;
    D_801A7264 = D_801A7270 = D_801A727C = 1.0f;
    D_801825D0 = 90.0f;
    D_8015B334 = 5;
    D_8015B33C = 0xC8;
    D_801A8D88[0] &= ~0x1200;
    if (D_801A8C40 >= 0) {
        D_801A8C58 = D_801A8C40;
    }
    if ((D_801A7234 == D_801A723C) && (D_801A7234 == 0)) {
        D_801A8C40 = 0x1F4;
        D_801A8C58 = D_801A8C40;
        D_801A7234 = 7;
        D_801A723C = 1;
    } else if ((D_801A7234 == D_801A723C) && (D_801A7234 == 0x100)) {
        D_801A7234 = D_801A723C = 1;
        D_801A8C40 = D_801A8C58;
    }
    func_80099F90(0.0f, -4.0f);
    func_80004510();
    if (!(D_801A8D88[0] & 0x80)) {
        func_80004654(3U);
        if (D_801A8D88[0] & 0x200) {
            Thread_ReceiveMsgInThread((u8) *gSysThreadIds, &sp38, 1);
            func_80015E50();
            func_80015E94(0xF);
            func_80015E94(0xE);
            func_80015E94(0xD);
            func_80015E94(0xC);
            func_80015E94(0xB);
            func_800161E0();
            if (D_801A8D88[1] & 2) {
                D_8015BB2C = 30.0f;
            } else if (D_801A8D88[1] & 4) {
                D_8015BB34 = 60.0f;
                D_8015BB3C = 15.0f;
                D_8015BB2C = 60.0f;
            }
            Thread_ReceiveMsgInThread((u8) *gSysThreadIds, &sp38, 1);
            sp3C = func_800045AC(3);
            func_8000BDDC(sp3C);
            Thread_ReceiveMsgInThread((u8) *gSysThreadIds, &sp38, 1);
            D_801A7234 = D_801A7254 & 0x7FFF;
            D_801A723C = D_801A725C & 0x7FFF;
            if (!(D_801A8D88[3] & 0x4000)) {
                func_8000BB00();
            } else {
                func_8000BC7C();
                func_80004510();
                D_801A8D88[1] |= 4;
                D_801A8D88[3] |= 0x800;
            }
            D_801A8D88[3] &= ~0x4000;
            D_801A8D88[0] &= ~0x200;
            D_80180664 = 0;
            Thread_ReceiveMsgInThread((u8) gSysThreadIds[0], &sp38, 1);
        }
    }
    if (D_801A8D88[3] & 0x2000) {
        D_801A8D88[2] |= 0x10;
    }
    spF8 = func_80004410((u16) D_801A7234, (u16) D_801A723C);
    if (spF8 == NULL) {
        return 1;
    }
    osWritebackDCacheAll();
    spF4 = spF8->unk8;
    D_801A721C = *spF4++;
    D_801A72D4 = *spF4++;
    if (D_801A72D4 == -1) {
        D_801A72D4 = 0;
    }
    D_801A8E44 = *spF4++;
    if (D_801A8E44 == -1) {
        D_801A8E44 = 0x3C;
    }
    D_800F18EC = gMusicSequenceId;
    sp100 = (s16) *spF4++;
    if (sp100 != -1) {
        gMusicSequenceId = sp100;
        sp104 = func_800BB578() & 7;
        if (sp104 != 2) {
            D_800F18EC = ~gMusicSequenceId;
        }
    }
    D_801A8D88[3] &= ~2;
    sp100 = (s16) *spF4++;
    if (sp100 != -1) {
        D_801A8D88[3] |= 2;
    }
    D_801A721C &= 0xFFFF7FFF;
    D_801A7228 = -0x8000;
    if (D_801A7228 != 0) {
        D_801A7238 |= 0x8000;
    }
    if (D_801A8D88[0] & 0x80) {
        D_801A721C += 2;
    }
    if ((D_801A721C == 1) || (D_801A721C == 3)) {
        D_801A7238 &= 0xFFFF7FFF;
    }
    if (func_80004CD4(&spF4, 0) == 1) {
        return 1;
    }
    func_80004ADC();
    sp84 = SysMem_HeapAlloc(((((uintptr_t) &D_809A8230 - (uintptr_t) &D_809A8190) + 7) >> 3) * 8);
    sp80 = sp84;
    SysMem_DmaCopy(
        SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_69A970_ROM_START, (s32) gSeg_69A970_VRAM, (s32) &D_809A8190),
        sp84, ((u32) (((uintptr_t) &D_809A8230 - (uintptr_t) &D_809A8190) + 7) >> 3) * 8);
    SysMem_Copy8(&sp60, sp84, 0x20);
    SysMem_Copy8(&sp40, sp84 + 1, 0x20);
    SysMem_Free(sp80);
    func_800A66EC(8, &sp60, 0x400, 1, 0x4000004C, 0xB4, -10.0f, 8);
    sp84 = SysMem_HeapAlloc(((u32) (((uintptr_t) &D_809A8230 - (uintptr_t) &D_809A8190) + 7) >> 3) * 8);
    sp80 = sp84;

    SysMem_DmaCopy(
        SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_69A970_ROM_START, (s32) gSeg_69A970_VRAM, (s32) &D_809A8190),
        sp84, ((u32) (((uintptr_t) &D_809A8230 - (uintptr_t) &D_809A8190) + 7) >> 3) * 8);

    for (;; sp84++) {
        if (sp84->unk4 == 0) {
            SysMem_Free(sp80);
            return 1;
        }
        if ((sp84->unk0 == 1) && (sp84->unk2 == 2)) {
            break;
        }
    }

    SysMem_Copy8(&sp60, sp84, 0x20);
    SysMem_Copy8(&sp40, sp84 + 1, 0x20);
    SysMem_Free(sp80);
    func_800A66EC(0xC, &sp60, 0x400, 1, 0x4000004C, 0xB4, -10.0f, 8);
    func_8002856C(1);
    func_8002F5C4(D_801A72D4);
    if (!(D_801A8D88[0] & 0x80)) {
        func_80015E50();
        func_80015E94(0xF);
        func_80015E94(0xE);
        func_80015E94(0xD);
        func_80015E94(0xC);
        func_80015E94(0xB);
        if (D_801A8D88[0] & 0x200) {
            func_800161E0();
        }
    }
    func_80015FB4(1);
    func_80015E94(1);
    if (D_801A721C == 0) {
        switch (D_801A72D4) {
            case 0:
            case 1:
                func_80004654(0x10U);
                /* fallthrough */
            case 2:
            case 3:
            case 4:
                break;
        }
    }
    D_80180EF0 = gInteractionWaitTimer = 0;
    D_801806C4 = 1;
    func_8005E19C();
    func_8005D800();
    func_8005E474();
    func_800821A0();
    while (*spF4 != 0xFFFF) {
        if ((*spF4 == 0x13) && (D_801A8C40 == -1)) {
            spF4 += 1;
            continue;
        }
        func_80004654(*spF4++);
    }
    spF4 += 1;
    if (D_801A721C == 1) {
        if (FALSE) {}
        if (*spF4 != 0xFFFF) {
            func_80043DC0(*spF4);
            D_801A7238 |= 0x08000000;
        } else if (!(D_801A8D88[0] & 0x200)) {
            func_800AF060(0x3C);
        } else {
            D_801A7228 = 0;
            func_800AF060(0x200);
            for (sp100 = 0; sp100 < 4; sp100++) {
                (D_801A8C30 + sp100)->unkC0 |= 0x200;
            }
            D_801A721C += 2;
        }
    } else {
        if (!(D_801A8D88[0] & 0x80)) {
            func_800AF060(0x3C);
        } else if (D_801A721C == 3) {
            D_801A7228 = 0;
            func_800AF060(0x200);
            for (sp100 = 0; sp100 < 4; sp100++) {
                (D_801A8C30 + sp100)->unkC0 |= 0x200;
            }
        } else {
            func_800AF060(0x3C);
        }
        if (FALSE) {}
    }
    if (!(D_801A8D88[0] & 0x2000)) {
        D_801561D8[459] = 26.0f;
        D_801561D8[461] = 194.0f;
        D_801561D8[537] = 26.0f;
        D_801561D8[539] = 194.0f;
        D_801561D8[381] = 26.0f;
        D_801561D8[383] = 194.0f;
    }
    if (D_801A8D88[0] & 0x200) {
        D_801561D8[459] = (f32) (D_801561C4 + D_801A7230);
        D_801561D8[461] = (f32) (D_801561C4 + D_801A7230 + 1.0f);
    }
    if (!(D_801A8D88[0] & 0x80)) {
        if (D_801A8D88[1] & 1) {
            D_801A8C34 = 0xE;
        } else if (D_801A8D88[1] & 2) {
            D_801A8C34 = 0xC;
        } else if (D_801A8D88[1] & 4) {
            D_801A8C34 = 0xB;
        } else if (D_801A8D88[1] & 8) {
            D_801A8C34 = -1;
        } else {
            D_801A8C34 = 0xF;
        }
    } else if (D_801A8D88[1] & 1) {
        D_801A8C34 = 0xE;
    } else if (D_801A8D88[1] & 2) {
        D_801A8C34 = 0xC;
    } else if (D_801A8D88[1] & 4) {
        D_801A8C34 = 0xB;
    } else if (D_801A8D88[1] & 8) {
        D_801A8C34 = -1;
    }
    D_801A8D88[1] = 0U;
    switch (D_801A8C34) { /* switch 1; irregular */
        case 15:          /* switch 1 */
            if (D_8015BAF8 == 0.0f) {
                D_8015BAF8 = 4.0f;
            } else {
                if (D_8015BAF8 < 0.0f) {
                    if (D_8015BAF8 > 0.0f) {
                    } else {
                        D_8015BAF8 = -D_8015BAF8;
                    }
                }
            }
            func_80016620(&D_8015BAF8);
            D_8015BAF8 = 4.0f;
            D_8015BAFC = 0;
            D_8015BB00 = 0;
            D_8015BB04 = 0;
            D_8015BB08 = 0x140;
            D_8015BB0C = 0xA8;
            D_8015BB10 = 0.0f;
            D_8015BB14 = 10.0f;
            D_8015BB18 = 0.0f;
            D_8015BB1C = 0x3E8;
            D_801A8D88[0] |= 0x400;
            break;
        case 12: /* switch 1 */
            if (!(D_801A8D88[0] & 0x80)) {
                D_8015BB2C = 30.0f;
            }
            func_80017B80(D_800F18E4, D_8015BB2C);
            D_801A8D88[0] |= 0x400;
            break;
        case 11: /* switch 1 */
            if (!(D_801A8D88[0] & 0x80)) {
                D_8015BB34 = 60.0f;
                D_8015BB3C = 15.0f;
                D_8015BB2C = 60.0f;
            }
            func_8001A040(6, 5, D_8015BB34, D_8015BB3C, D_8015BB2C);
            D_801A8D88[0] |= 0x400;
            break;
        default: /* switch 1 */
            D_801A8D88[0] |= 0x400;
            break;
    }
    D_801A7254 = D_801A7234;
    D_801A725C = D_801A723C;
    D_801A8D88[0] &= ~0x92;
    D_801806C4 = 1;

    return 0;
}

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

s32 func_80004CD4(u16** arg0, s32 arg1) {
    UnkStruct_sp84* sp8C;
    UnkStruct_sp84* sp88;
    UnkStruct_sp84 sp68;
    UnkStruct_sp84 sp48;
    s32 sp44;
    u16 sp42;
    u16 sp40;
    u16 sp3E;
    u16 sp3C;
    u16* sp38;

    sp38 = *arg0;
    for (sp44 = arg1; *sp38 != 0xFFFF;) {
        sp42 = *sp38++;
        sp40 = *sp38++;
        sp8C = SysMem_HeapAlloc(((u32) (((u8*) &D_807A1A20 - (u8*) &D_807A0080) + 7) >> 3) * 8);
        sp88 = sp8C;
        SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteSeg2RomStart, (s32) gSpriteSegVramStart,
                                                            (s32) &D_807A0080),
                       sp8C, ((u32) (((uintptr_t) &D_807A1A20 - (uintptr_t) &D_807A0080) + 7) >> 3) * 8);

        for (;; sp8C++) {
            if (sp8C->unk4 == 0) {
                SysMem_Free(sp88);
                return 1;
            }
            if ((sp8C->unk0 == sp42) && (sp8C->unk2 == sp40)) {
                break;
            }
        }

        SysMem_Copy8(&sp68, sp8C, 0x20);
        SysMem_Copy8(&sp48, (u8*) sp8C + 0x20, 0x20);
        SysMem_Free(sp88);
        sp44 += func_800A66EC(sp44, &sp68, sp48.unk10 - sp68.unk10, 1, 0xC, 0xA, 6.0f, 0x20);
    }
    sp38++;

    while (*sp38 != 0xFFFF) {
        sp42 = *sp38++;
        sp40 = *sp38++;
        sp3E = *sp38++;
        sp3C = *sp38++;
        if (sp3E == 0) {
            if (arg1 < 4) {
                D_801A8C18[sp42].unkC8 = (s32) sp40;
                D_801A8C18[sp42].unk124 = (s16) sp3C;
            } else {
                D_801A8C24[sp42].unkC8 = (s32) sp40;
                D_801A8C24[sp42].unk124 = (s16) sp3C;
            }
        } else if (arg1 < 4) {
            (D_801A8C18 + sp42)->unkC0 |= 0x80;
        } else {
            (D_801A8C24 + sp42)->unkC0 |= 0x80;
        }
    }

    sp38++;

    *arg0 = sp38;
    return 0;
}

s32 func_80005124(u16 arg0, u16 arg1) {
    UnkStruct_800E114C* sp24;
    s32 pad20;
    s32 sp1C;

    if ((sp24 = func_80004410(arg0, arg1)) == NULL) {
        return -1;
    }
    sp1C = sp24->unk8;
    sp1C += 0xA;
    osWritebackDCacheAll();
    if (func_80004CD4((u16**) &sp1C, 0) == 1) {
        func_80005460();
        return -1;
    }
    return 0;
}

s32 func_800051D4(u16 arg0, u16 arg1) {
    UnkStruct_800E114C* sp24;
    s32 pad20;
    s32 sp1C;

    if ((sp24 = func_80004410(arg0, arg1)) == NULL) {
        return -1;
    }
    sp1C = sp24->unk8;
    sp1C += 0xA;
    osWritebackDCacheAll();
    if (func_80004CD4((u16**) &sp1C, 4) == 1) {
        func_800055DC();
        return -1;
    }
    return 0;
}

s32 func_80005284(void) {
    s32 sp17C;
    s32 sp178;
    char buf[sizeof(SpriteObj)];

    for (sp17C = 0, sp178 = 0; sp178 < 4; sp178++) {
        sp17C |= D_801A8C18[sp178].unkC0;
    }
    if (!(sp17C & 0x10000000)) {
        return -1;
    }
    for (sp17C = 0, sp178 = 0; sp178 < 4; sp178++) {
        sp17C |= D_801A8C24[sp178].unkC0;
    }
    if (!(sp17C & 0x10000000)) {
        return -2;
    }
    for (sp178 = 0; sp178 < 4; sp178++) {
        SysMem_Copy8(buf, &D_801A8C18[sp178], 0x160);
        osWritebackDCacheAll();
        SysMem_Copy8(&D_801A8C18[sp178], &D_801A8C24[sp178], 0x160);
        osWritebackDCacheAll();
        SysMem_Copy8(&D_801A8C24[sp178], buf, 0x160);
        osWritebackDCacheAll();
    }
    return 0;
}

s32 func_80005460(void) {
    s32 sp1C;
    SpriteObj* sp18;

    sp18 = D_801A8C18;
    for (sp1C = 0; sp1C < 4; sp1C++) {
        if ((sp18->unkC0 & 0x10000000) && (sp18->unkC0 & 0x20000000)) {
            if (sp18->currentPaletteColors != NULL) {
                SysMem_Free(sp18->currentPaletteColors);
            }
            if (sp18->spritePtrs.ptrs[1] != NULL) {
                SysMem_Free(sp18->spritePtrs.ptrs[1]);
            }
            if (sp18->spritePtrs.ptrs[2] != NULL) {
                SysMem_Free(sp18->spritePtrs.ptrs[2]);
            }
            if (sp18->unk144 != NULL) {
                SysMem_Free(sp18->unk144);
            }
        }
        sp18->unkC0 = 0;
        sp18->currentPaletteColors = NULL;
        sp18->spritePtrs.ptrs[1] = NULL;
        sp18->spritePtrs.ptrs[2] = NULL;
        sp18->unk144 = NULL;
        sp18++;
    }
    return 0;
}

s32 func_800055DC(void) {
    s32 sp1C;
    SpriteObj* sp18;

    sp18 = D_801A8C24;
    for (sp1C = 0; sp1C < 4; sp1C++) {
        if ((sp18->unkC0 & 0x10000000) && (sp18->unkC0 & 0x20000000)) {
            if (sp18->currentPaletteColors != NULL) {
                SysMem_Free(sp18->currentPaletteColors);
            }
            if (sp18->spritePtrs.ptrs[1] != NULL) {
                SysMem_Free(sp18->spritePtrs.ptrs[1]);
            }
            if (sp18->spritePtrs.ptrs[2] != NULL) {
                SysMem_Free(sp18->spritePtrs.ptrs[2]);
            }
            if (sp18->unk144 != NULL) {
                SysMem_Free(sp18->unk144);
            }
        }
        sp18->unkC0 = 0;
        sp18->currentPaletteColors = NULL;
        sp18->spritePtrs.ptrs[1] = NULL;
        sp18->spritePtrs.ptrs[2] = NULL;
        sp18->unk144 = NULL;
        sp18++;
    }
    return 0;
}

s32 func_80005758(void) {
    s32 sp4;
    s32 sp0;

    for (sp4 = 0, sp0 = 0; sp0 < 4; sp0++) {
        sp4 |= D_801A8C18[sp0].unkC0;
    }
    if (!(sp4 & 0x10000000)) {
        return -1;
    }
    return 0;
}

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
