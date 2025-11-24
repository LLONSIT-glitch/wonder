#include "common.h"

typedef struct UnkStruct_801561D8_s {
    /* 0x000 */ char pad0[0xE8];
    /* 0x0E8 */ f32 unkE8;        /* inferred */
    /* 0x0EC */ f32 unkEC;        /* inferred */
    /* 0x0F0 */ char padF0[0x48]; /* maybe part of unkEC[0x13]? */
} UnkStruct_801561D8;             /* size = 0x138 */

typedef struct DebugMenuInfo_s {
    /* 0x00 */ s32 unk0;                                   /* inferred */
    /* 0x04 */ char* optionName;                           /* inferred */
    /* 0x08 */ s32 unk8;                                   /* inferred */
    /* 0x0C */ s32 unkC;                                   /* inferred */
    /* 0x10 */ s32 unk10;                                  /* inferred */
    /* 0x14 */ s32 (*unk14)(struct DebugMenuInfo_s*, s32); /* inferred */
    /* 0x18 */ s32 (*unk18)(struct DebugMenuInfo_s*);      /* inferred */
    /* 0x1C */ char pad1C[0xC];                            /* maybe part of unk18[3]? */
} DebugMenuInfo;                                           /* size = 0x28 */

void func_800198F8(void*, s32);
void func_80019F4C(UnkStruct_8000DDE0*); /* extern */
void func_8008EC8C(f32, f32);            /* extern */
void func_8008ECAC(f32, f32);            /* extern */
void func_80090728(s32);                 /* extern */
void func_80090754(s32);                 /* extern */
void func_80090A38(s32, s32);            /* extern */
void func_80096374(void*);               /* extern */
void func_80096474(void);                /* extern */
void func_800967D8(void);                /* extern */
s16 func_800AD774(s32);                  /* extern */
void func_800962B0(void*);               /* extern */
void func_800029BC(void);                /* extern */
void func_80005124(s32, s32);            /* extern */
void func_80005460(void);                /* extern */
void func_8001C1F4(UnkStruct_8000DDE0*); /* extern */
void func_80032604(void);                /* extern */
void func_80098D24(u8);                  /* extern */
void func_8009908C(void*, s32);          /* extern */
void func_80099450(void);                /* extern */
void func_80099520(void);                /* extern */
void func_80099768(void);                /* extern */
void func_8009A664(Gfx**);               /* extern */
void func_800A6670(s32, s32*);           /* extern */
void func_800AFB28(void);                /* extern */
void func_800BE510(f32, f32, f32);       /* extern */
void func_800BE610(void);                /* extern */

extern DebugMenuInfo D_800DB1A0[];
extern s16 D_801A7228;
extern UnkStruct_801561D8 D_801561D8[];
extern s32 D_800E4CA4;
extern u16 D_8015BB48[];
extern UnkStruct_80099E2C D_801AA680[8];
extern UnkStruct_80099E2C D_801AB180[];
extern s32 D_801AB240;
extern f32 D_801AB254;
extern f32 D_801AB250;
extern f32 D_801AB26C;
extern f32 D_801AB270;
extern f32 D_801AB274;
extern f32 D_801AB278;
extern s16 D_801AB280;
extern s16 D_801AB282;
extern s32 D_801AB284;
extern s32 D_801AB288;
extern s16 D_801AB294;
extern s16 D_801AB296;
extern s16 D_801AB29E;
extern void* D_801AB2A8;
extern void* D_801AB2B8;
extern void* D_801AB2BC;
extern void* D_801AB2C0;

extern char D_800ED89C;
extern char D_800ED8B0;
extern char D_800ED8B4;
extern char D_800ED8B8;
extern char D_800ED8CC;
extern char D_800ED8E0;
extern char D_800ED8F4;
extern char D_800ED908;
extern char D_800ED91C;
extern char D_800ED924;
extern char D_800ED92C;
extern char D_800ED934;
extern char D_800ED93C;
extern char D_800ED944;
extern char D_800ED94C;
extern char D_800ED954;
extern char D_800ED95C;
extern char D_800ED968;
extern char D_800ED97C;
extern char D_800ED9A0;
extern char D_800ED9AC;
extern char D_800ED9C0;
extern char D_800ED9CC;
extern char D_800ED9D8;
extern char D_800ED9E4;
extern char D_800EDA10;
extern char D_800EDA18;
extern char D_800EDA20;
extern char D_800EDA28;
extern char D_800EDA30;
extern char D_800EDA5C;
extern char D_800EDA64;
extern char D_800EDA6C;
extern char D_800EDA78;
extern char D_800EDA7C;
extern char D_800EDA80;
extern char D_800EDA84;
extern char D_800EDAA4;
extern char D_800EDAC4;
extern char D_800EDAE4;
extern char D_800EDB04;
extern char D_800EDB0C;
extern char D_800EDB14;
extern char D_800EDB1C;
extern char D_800EDB24;
extern char D_800EDB2C;
extern char D_800EDB34;
extern char D_800EDB3C;
extern char D_800EDB44;
extern char D_800EDB50;
extern char D_800EDB54;
extern char D_800EDB58;

extern s16 D_801A7248;
extern s16 D_801A7268;

s32 func_80019FA0(UnkStruct_8000DDE0* arg0) {
    arg0->unk1A0 |= 8;
    arg0->unk1A8 = 0;
    arg0->unk1AC = 0;
    arg0->unk1EC = 0.0f;
    arg0->unk1E8 = arg0->unk1EC;
    arg0->unk1F4 = 0.0f;
    arg0->unk1F0 = arg0->unk1F4;
    arg0->unk1FC = 0.0f;
    arg0->unk1F8 = arg0->unk1FC;
    arg0->unk204 = 0.0f;
    arg0->unk200 = arg0->unk204;
    *D_8015BAC8 = (UnkStruct_8000DDE0*) arg0;
    return 0;
}

s32 func_8001A040(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    UnkStruct_8000DDE0* sp24;
    UnkStruct_801561D8* sp20;
    UnkStruct_801561D8* sp1C;
    UnkStruct_801561D8* temp_t4;

    sp24 = func_80016074(0xB);
    if (sp24 == NULL) {
        return -1;
    }
    if (!(sp24->unk1A8 & 7)) {
        func_800198F8(sp24, 1);
    }
    sp24->unk1A8 = (s32) (sp24->unk1A8 | 1);
    sp24->unk1A8 = (s32) (sp24->unk1A8 & ~6);
    sp24->unk1E8 = (f32) arg0;
    sp24->unk1EC = (f32) arg1;
    sp20 = &D_801561D8[arg0];
    sp1C = &D_801561D8[arg1];
    sp20->unkE8 = 255.0f;
    sp1C->unkE8 = 0.0f;
    sp24->unk1F0 = arg2;
    sp24->unk1F4 = arg3;
    sp24->unk1F8 = arg4;
    sp20->unkEC = -255.0f / arg2;
    sp1C->unkEC = 255.0f / arg4;
    sp24->unk0.unkC4 = func_800AD774(arg0);
    return 0;
}

s32 func_8001A210(UnkStruct_8000DDE0* arg0) {
    UnkStruct_801561D8* sp24;
    UnkStruct_801561D8* sp20;
    UnkStruct_8000DDE0* sp1C;

    sp1C = arg0;
    if (arg0->unk1A8 & 1) {
        sp24 = &D_801561D8[(s32) arg0->unk1E8];
        sp20 = &D_801561D8[(s32) arg0->unk1EC];
        if (arg0->unk1A8 & 4) {

        } else {
            if (arg0->unk1F0 > 0.0f) {
                sp24->unkE8 += sp24->unkEC * D_8018257C;
                if (sp24->unkE8 < 0.0f) {
                    sp24->unkE8 = 0.0f;
                }
                arg0->unk1F0 = (f32) ((f64) arg0->unk1F0 - (1.0 * (f64) D_8018257C));
            } else {
                arg0->unk1F0 = 0.0f;
                sp24->unkE8 = 0.0f;
            }
            if (arg0->unk1F4 > 0.0f) {
                arg0->unk1F4 = (f32) ((f64) arg0->unk1F4 - (1.0 * (f64) D_8018257C));
            } else {
                arg0->unk1F4 = 0.0f;
                if (arg0->unk1F8 > 0.0f) {
                    sp20->unkE8 += sp20->unkEC * D_8018257C;
                    if (sp20->unkE8 > 255.0f) {
                        sp20->unkE8 = 255.0f;
                    }
                    arg0->unk1F8 = (f32) ((f64) arg0->unk1F8 - (1.0 * (f64) D_8018257C));
                } else {
                    arg0->unk1F8 = 0.0f;
                    sp20->unkE8 = 255.0f;
                }
            }

            if ((arg0->unk1F8 == arg0->unk1F0) && (arg0->unk1F0 == 0.0f)) {
                arg0->unk1A8 = (s32) (arg0->unk1A8 & ~1);
                arg0->unk1A8 = (s32) (arg0->unk1A8 | 2);
                sp24->unkE8 = 0.0f;
                sp20->unkE8 = 255.0f;
            } else {
                func_800C1754();
                func_8009A14C(arg0);
                func_800997D8(arg0);
                func_800C1A28();
                D_801A7238 |= 0x8000;
            }
        }
    } else if (arg0->unk1A8 & 2) {
        arg0->unk1A8 = (s32) (arg0->unk1A8 & ~7);
        func_80019F4C(sp1C);
        if (D_801A7228 == 0) {
            D_801A7238 &= 0xFFFF7FFF;
        } else {
            D_801A7238 |= 0x8000;
        }
    }
    return 0;
}

s32 func_8001A690(UnkStruct_8000DDE0* arg0) {
    s32 sp2C;
    UnkStruct_8000DDE0* sp28;

    arg0->unk1A8 = 0;
    arg0->unk1AC = 0;
    arg0->unk1EC = 0.0f;
    arg0->unk1E8 = arg0->unk1EC;
    arg0->unk20C = SysMem_HeapAlloc(0x3C);
    sp28 = arg0;
    func_80099E2C(&sp28->unk0);
    sp28->unk0.unkD4 = 0.0f;
    sp28->unk0.unkCC = sp28->unk0.unkD0 = sp28->unk0.unkD4;
    sp28->unk0.unk108 = 0;
    sp28->unk0.unk104 = sp28->unk0.unk108;
    sp28->unk0.unkF0 = 0.0f;
    sp28->unk0.unkE8 = sp28->unk0.unkEC = sp28->unk0.unkF0;
    sp28->unk0.unkF8 = 1.0f;
    sp28->unk0.unkF4 = sp28->unk0.unkF8;
    sp28->unk0.unk11E = 0xFF;
    sp28->unk0.unk116 = 1;
    sp28->unk0.unkC8 = 0x7FFFFFFF;
    sp28->unk0.unkC0 = 0x84C;
    sp28->unk0.unk114 = 4;
    if (*D_801A8D88 & 0x800) {
        arg0->unk1A8 |= 1;
        sp28->unk0.unk100 = 0x100;
        sp28->unk0.unk102 = 0xE0;
        sp28->unk0.ptrs[0] = SysMem_HeapAlloc(sp28->unk0.unk100 * sp28->unk0.unk102);
        for (sp2C = 0; sp2C < (sp28->unk0.unk100 * sp28->unk0.unk102); sp2C++) {
            sp28->unk0.ptrs[0][sp2C] = 0;
        }
    } else {
        sp28->unk0.unk100 = (s16) (s32) arg0->unk1B0;
        sp28->unk0.unk102 = (s16) (s32) arg0->unk1B4;
        sp28->unk0.ptrs[1] = SysMem_HeapAlloc(sp28->unk0.unk100 * sp28->unk0.unk102);
        sp28->unk0.ptrs[2] = SysMem_HeapAlloc(sp28->unk0.unk100 * sp28->unk0.unk102);

        for (sp2C = 0; sp2C < (sp28->unk0.unk100 * sp28->unk0.unk102); sp2C++) {
            sp28->unk0.ptrs[1][sp2C] = 0;
            sp28->unk0.ptrs[2][sp2C] = 0;
        }
    }
    sp28->unk0.unk138 = SysMem_HeapAlloc(0x200);
    func_80090A38(sp28->unk0.unk138, 0x100);
    func_80096474();
    Sys_SwapFrameBuffer((s32*) sp28->unk0.ptrs[0]);
    func_8008EC8C((f32) sp28->unk0.unk100, (f32) sp28->unk0.unk102);
    func_8008ECAC((f32) sp28->unk0.unk100, (f32) sp28->unk0.unk102);
    D_8015B320 = 0x10;
    D_8015B328 = 0xFF;
    func_80090754(0xE8);
    if (*D_801A8D88 & 0x800) {
        func_80090728(0x600);
    } else {
        func_80090728(0x420);
    }
    func_8008EAA8(0, 0);
    func_80096374(arg0->unk20C);
    func_800967D8();
    if (*D_801A8D88 & 0x800) {
        *D_8015BAC8 = arg0;
    }
    return 0;
}

s32 func_8001AB84(void) {
    UnkStruct_8000DDE0* sp1C;

    sp1C = func_80016074(1);
    if (sp1C == NULL) {
        return -1;
    }
    func_80096474();
    func_800962B0(sp1C->unk20C);
    return 0;
}

s32 func_8001ABEC(UnkStruct_8000DDE0* arg0) {
    func_80096474();
    func_800962B0(arg0->unk20C);
    Sys_SwapFrameBuffer(arg0->unk0.ptrs[D_801824FC + 1]);
    arg0->unk0.ptrs[0] = arg0->unk0.ptrs[D_801824FC + 1];
    return 0;
}

s32 func_8001AC74(void) {
    UnkStruct_8000DDE0* sp1C;

    sp1C = func_80016074(1);
    if (sp1C == NULL) {
        return -1;
    }
    func_80096374(sp1C->unk20C);
    func_800967D8();
    return 0;
}

s32 func_8001ACDC(UnkStruct_8000DDE0* arg0) {
    func_80096374(arg0->unk20C);
    func_800967D8();
    return 0;
}

void* func_8001AD24(u16 arg0, s32 arg1) {
    UnkStruct_8000DDE0* sp1C;

    if ((sp1C = func_80016074(1)) == NULL) {
        return (void*) -1;
    }
    sp1C->unk0.unk138[arg1] = (arg0 * 2) | (arg0 >> 0xF);

    /* @bug No return here */
}

void func_8001AD98(UnkStruct_8000DDE0* arg0, u16 arg1, s32 arg2) {
    arg0->unk0.unk138[arg2] = arg1;
}

s32 func_8001ADBC(UnkStruct_8000DDE0* arg0);

s32 func_8001ADBC(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000DDE0* sp1C;

    sp1C = arg0;
    if ((*D_801A8D88 & 8) || !(arg0->unk1A8 & 1)) {
        func_800C1754();
        func_8009A14C(sp1C);
        func_800C2780(sp1C->unk0.unkF0);
        func_800C25B8(sp1C->unk0.unkEC);
        func_800C23E8(sp1C->unk0.unkE8);
        func_800997D8(sp1C);
        func_800C1A28();
    }
    return 0;
}

void func_8001AE90(UnkStruct_8000DDE0* arg0);

void func_8001AE90(UnkStruct_8000DDE0* arg0) {
    UnkStruct_8000DDE0* sp1C;

    sp1C = arg0;
    if (arg0->unk20C != NULL) {
        SysMem_Free(arg0->unk20C);
        arg0->unk20C = NULL;
    }
    if (sp1C->unk0.ptrs[1] != NULL) {
        SysMem_Free(sp1C->unk0.ptrs[1]);
        sp1C->unk0.ptrs[1] = NULL;
    }
    if (sp1C->unk0.ptrs[2] != NULL) {
        SysMem_Free(sp1C->unk0.ptrs[2]);
        sp1C->unk0.ptrs[2] = NULL;
    }
    if (sp1C->unk0.unk138 != NULL) {
        SysMem_Free(sp1C->unk0.unk138);
        sp1C->unk0.unk138 = NULL;
    }
}

#ifdef NEEDS_BSS
// float D_801AB24C;
void func_8001AFA0(UnkStruct_8000DDE0* arg0) {
    s32 sp94; // sp94
    s32 sp90;
    s32 sp8C;                 // sp8C
    s32 sp88;                 // sp88
    s32 sp84;                 // sp84
    s32 sp80;                 // sp80
    f32 sp7C;                 // sp7C
    s32 sp78;                 // sp78
    s32 sp74;                 // sp74
    s32 sp70;                 // sp60
    UnkStruct_8000DDE0* sp6C; // sp68
    UnkStruct_800F9C38* sp68; // sp64
    s16* sp64;                // sp60
    UnkStruct_8000DDE0* sp60; // sp5C
    UnkStruct_80099E2C* sp5C; // sp58
    u8* sp58;                 // sp54
    u16 sp56;                 // sp52?
    DebugMenuInfo* sp50;
    s32* sp4C;
    s32 (*sp48)(s32*);
    f32 sp44;
    s32 pad5;
    s32 pad1;
    static Vec3f D_801AB24C;
    static Vec3f D_801AB268;

    sp6C = arg0;
    sp68 = sp6C->unk0.unk18;
    if (*D_801A8D88 & 4) {
        sp60 = &D_801A7340[12];
        sp60->unk0.unkF8 = 1.0f;
        sp60->unk0.unkF4 = sp60->unk0.unkF8;
        sp60->unk0.unkC0 &= ~8;
        sp60->unk0.unkC0 |= 0x810;
        sp60->unk0.unkE8 = sp60->unk0.unkEC = sp60->unk0.unkF0 = 0.0f;
    }
    sp8C = 0;
    sp7C = 0.0f;

    for (sp94 = 0; sp94 < 8; sp94++) {
        func_80099E2C(&D_801AA680[sp94]);
    }

    func_800A6670(0, &D_801AA680[0]);
    func_800A6670(4, &D_801AA680[4]);
    sp5C = D_801AB180;
    func_80099E2C(sp5C);

    D_801AB24C.z = D_801AB24C.x = D_801AB24C.y = 0.0f;
    D_801AB288 = 0;
    D_801AB284 = 0;
    D_801AB268.x = D_801AB268.y = D_801AB268.z = 0.0f;

    D_801AB274 = D_801AB278 = 1.0f;
    D_801AB29E = 0xFF;
    D_801AB296 = 1;
    D_801AB240 = 0x854;
    D_801AB294 = 4;
    D_801AB280 = 0x100;
    D_801AB282 = 0xF0;
    D_801AB2BC = SysMem_HeapAlloc(0xF000);
    D_801AB2C0 = SysMem_HeapAlloc(0xF000);
    D_801AB2B8 = SysMem_HeapAlloc(0x200);
    func_80090A38((s32) D_801AB2B8, 0x100);
    sp56 = D_8015BB48[0];
    D_8015BB48[0] = 1;
    sp58 = D_801AB2BC;

    for (sp94 = 0; sp94 < (D_801AB280 * D_801AB282); sp94++) {
        sp58[sp94] = 1;
    }

    SysMem_Copy8(D_801AB2C0, D_801AB2BC, 0xF000);
    sp78 = 0;
    sp74 = 0;
    if (*D_801A8D88 & 4) {
        sp44 = 10.0f;
    } else {
        sp44 = 180.0f;
    }
    D_801A7320 = D_801A7234;
    D_801A7338 = D_801A723C;
    sp48 = NULL;
    if (!(*D_801A8D88 & 4)) {
        func_80098820();
        func_80098868();
    }
    while (sp78 == 0) {
        func_800C143C(sp6C->unk0.unk0, &sp64, 1);
        switch (*sp64) { /* irregular */
            case 1:
                if (sp68->unk82EC < 2) {
                    func_80099768();
                    func_800AFB28();
                    func_800BE510(D_801825D0, (f32) D_8015B334, (f32) D_8015B33C);
                    func_80032604();
                    if (D_801824FC != 0) {
                        D_801AB2A8 = D_801AB2BC;
                    } else {
                        D_801AB2A8 = D_801AB2C0;
                    }
                    func_80096474();
                    Sys_SwapFrameBuffer(D_801AB2A8);
                    func_8008EC8C(256.0f, 240.0f);
                    func_8008ECAC(256.0f, 240.0f);
                    D_8015B320 = 1;
                    D_8015B328 = 0xFF;
                    func_80090754(0xE8);
                    func_80090728(0x600);
                    if (sp48 == NULL) {
                        sp5C->unk138[1] = 0x3F;
                        sp50 = D_800DB1A0;
                        sp70 = 0;
                        sp94 = 0;
                        sp88 = 0;

                        for (;; sp94++, sp50++) {
                            if (sp50->unk0 == -1) {
                                break;
                            }

                            if (sp50->unkC != -1) {
                                func_8008EAA8(sp50->unk8, sp50->unkC);
                                sp84 = sp50->unkC + 1;
                            } else {
                                func_8008EAA8(sp50->unk8, sp84++);
                            }
                            if (sp50->unk10 != 0) {
                                if (sp8C == sp88) {
                                    func_8008ECE4(">%s", sp50->optionName);
                                    if (sp50->unk14 != NULL) {
                                        sp70 = sp50->unk14(sp50, 0);
                                    }
                                    if (sp70 != 0) {
                                        sp4C = sp50;
                                        sp48 = sp50->unk18;
                                        D_801825E4 = 0;
                                    }
                                } else {
                                    func_8008ECE4(" %s", sp50->optionName);
                                    if (sp50->unk14 != NULL) {
                                        sp50->unk14(sp50, -1);
                                    }
                                }
                                sp88 += 1;
                            } else {
                                func_8008ECE4(" %s", sp50->optionName);
                            }
                        }

                        if (D_801560F0->unk8 & D_80180E68) {
                            sp8C -= 1;
                        }
                        if (D_801560F0->unk8 & D_80180E74) {
                            sp8C += 1;
                        }
                        if (sp8C < 0) {
                            sp8C = sp88 - 1;
                        }
                        if (sp8C >= sp88) {
                            sp8C = 0;
                        }
                        if (sp80 != 0) {
                            if (*D_801A8D88 & 4) {
                                func_8008EAA8(0, 0x11);
                                func_8008ECE4("   frame : %d.    %f vinc:%08x\n", (s32) ((f32) D_8018251C / 50.223f),
                                              (f64) D_8018257C, D_8018258C);
                                func_8008ECE4(" Mem free:$%08x    max:$%08x\n", SysMem_GetFreeSpace(), SYS_HEAP_SIZE);
                            } else {
                                func_8008EAA8(0, 0x10);
                                if (sp7C < 40.0f) {
                                    // Press L to start the game.
                                    func_8008ECE4("  == Ｌを押すとゲームが始まります ==  \n");
                                    // It starts with the opening score of 0-0.
                                    func_8008ECE4("  ０ー０でオープニングから始まります ");
                                } else if (sp7C < 80.0f) {
                                    func_8008ECE4("                                      \n");
                                    // It starts with the opening score of 0-0.
                                    func_8008ECE4("  ０ー０でオープニングから始まります ");
                                } else {
                                    sp7C = 0.0f;
                                }
                                sp7C += 1.0 * D_8018257C;
                            }
                            if (D_800E4CA4 != 0) {
                                func_8008EAA8(4, 0x10);
                                func_8008ECE4(" error rmonPrintf\n");
                            }
                            func_8008EAA8(0, 2);
                            func_8008ECE4("  Last update %s %s\n", "19:30:20", "Oct 11 1996");
                        }
                        if (sp48 != NULL) {
                            func_8001C1F4(sp5C);
                        }
                    } else {
                        sp5C->unk138[1] = 0;
                        if (sp48(sp4C) < 0) {
                            sp48 = NULL;
                            func_8001C1F4(sp5C);
                        }
                        if (D_801825E4 == 0) {
                            D_801825E4 += 1;
                        }
                        func_8008EAA8(0, 0x12);
                        func_8008ECE4("   frame : %d.    %f\n", (s32) ((f32) D_8018251C / 50.223f), (f64) D_8018257C);
                    }
                    func_800967D8();
                    if ((sp44 == 0.0f) || (sp44 == 180.0f)) {
                        sp5C->unkC0 &= ~0x10;
                        sp5C->unkC0 |= 8;
                    } else {
                        if (*D_801A8D88 & 4) {
                            sp60->unk0.unkC0 = (s32) (sp60->unk0.unkC0 & ~8);
                            sp60->unk0.unkC0 = (s32) (sp60->unk0.unkC0 | 0x10);
                        }
                        sp5C->unkC0 &= ~8;
                        sp5C->unkC0 |= 0x10;
                    }
                    if (sp74 == 0) {
                        if (sp44 < 180.0f) {
                            sp44 += 10.0;
                        } else {
                            sp44 = 180.0f;
                        }
                    } else if ((sp44 >= 180.0f) && (sp44 < 360.0f)) {
                        sp44 += 10.0;
                    } else {
                        sp44 = 0.0f;
                    }
                    if (*D_801A8D88 & 4) {
                        sp60->unk0.unkE8 = sp44;
                        func_800C1754();
                        func_8009A14C(sp60);
                        func_800C2780(sp60->unk0.unkF0);
                        func_800C25B8(sp60->unk0.unkEC);
                        func_800C23E8(sp60->unk0.unkE8);
                        func_800997D8(sp60);
                    }
                    sp5C->unkE8 = sp44 - 180.0f;
                    func_800C1850(0);
                    func_8009A14C(sp5C);
                    func_800C2780(sp5C->unkF0);
                    func_800C25B8(sp5C->unkEC);
                    func_800C23E8(sp5C->unkE8);
                    func_800997D8(sp5C);
                    func_800C1A28();
                    func_8009A664(&gDisplayListHead);
                    func_800BE610();
                    func_8009908C(D_801A1B4C, (uintptr_t) gDisplayListHead - (uintptr_t) D_801A1B4C);
                    func_80098D24(sp6C->unk0.unk0);
                    func_80099450();
                    sp68->unk82EC++;
                }
                break;
            case 2:
                func_80099520();
                sp68->unk82EC = (s32) (sp68->unk82EC - 1);
                if ((D_801560F0->unk6 & D_80181038) && (sp48 == NULL) && (sp74 == 0) && (sp44 == 180.0f)) {
                    sp74 += 1;
                    sp44 = (f32) ((f64) sp44 + 10.0);
                }
                if ((sp74 != 0) && ((sp44 == 0.0f) || (sp44 == 180.0f))) {
                    if (*D_801A8D88 & 4) {
                        sp60->unk0.unkC0 &= ~16;
                        sp60->unk0.unkC0 |= 8;
                        sp60->unk0.unkE8 = sp60->unk0.unkEC = sp60->unk0.unkF0 = 0.0f;
                    }
                    sp78 = 1;
                    sp6C->unk0.unk8 = 1;
                }
                break;
            case 33:
                while (sp68->unk82EC > 0) {
                    func_800C143C(sp6C->unk0.unk0, &sp64, 1);
                    if (*sp64 == 2) {
                        if (FALSE)
                            ;
                        func_80099520();
                        sp68->unk82EC--;
                        continue;
                    }
                }
                func_80098820();
                func_80098868();
                func_80005460();
                func_80005124(D_801825F0[0], D_801825F0[1]);
                sp68->unk82EC = 0;
                func_800C13B8(sp6C->unk0.unk0);
                func_80098820();
                break;
            case 4:
                func_800029BC();
                while (TRUE)
                    ;
                break; // Dead code
            default:
                continue;
        }
    }
    if (!(*D_801A8D88 & 4)) {
        while (sp68->unk82EC > 0) {
            func_800C143C(sp6C->unk0.unk0, &sp64, 1);
            if (*sp64 == 2) {
                if (FALSE)
                    ;
                func_80099520();
                sp68->unk82EC--;
                continue;
            }
        }
        func_80098820();
        func_80098868();
    }
    func_800A6670(0, &D_801AA680);
    func_800A6670(4, &D_801AA680[4]);
    func_80005460();
    func_800A6670(0, &D_801A7340);
    func_800A6670(4, &D_801A7340[4]);
    SysMem_Free(D_801AB2B8);
    SysMem_Free(D_801AB2C0);
    SysMem_Free(D_801AB2BC);
    D_8015BB48[0] = sp56;
    if (!(*D_801A8D88 & 4)) {
        D_801A7234 = D_801A7320;
        D_801A723C = D_801A7338;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_1ABA0/func_8001AFA0.s")
#endif

void func_8001C1F4(UnkStruct_8000DDE0* arg0) {
    s32 sp1C;
    u8* sp18;

    sp18 = arg0->unk0.unk13C;
    for (sp1C = 0; sp1C < (arg0->unk0.unk100 * arg0->unk0.unk102); sp1C++) {
        sp18[sp1C] = 1;
    }
    SysMem_Copy64(arg0->unk0.unk140, arg0->unk0.unk13C, 0x1E00);
}

s32 func_8001C2AC(s32 arg0, s32 arg1) {
    if (arg1 >= 0) {
        if (D_801560F0->unk8 & D_80180FF4) {
            D_801A7320 += 1;
        }
        if (D_801560F0->unk8 & D_8018101C) {
            D_801A7320 -= 1;
        }
        if (D_801560F0->unk8 & D_80181258) {
            D_801A7338 += 1;
        }
        if (D_801560F0->unk8 & D_80181260) {
            D_801A7338 -= 1;
        }
        if (D_801560F0->unk8 & D_8018126C) {
            D_801A7338 += 0xA;
        }
        if (D_801560F0->unk8 & D_801811AC) {
            D_801A7338 -= 0xA;
        }
        if (D_801560F0->unk6 & D_801810F2) {
            D_801A7248 = 0;
            D_801A7268 = 0;
        }
        if (D_801560F0->unk6 & D_80180EC0) {
            D_801A72DC &= ~0x40;
        }
        if (D_801560F0->unk6 & D_80180EEC) {
            D_801A72DC |= 0x40;
        }
        if (D_801560F0->unk6 & D_80181042) {
            D_801A7320 = 0xC;
            D_801A7338 = 1;
        }
    }
    if (*D_801A8D88 & 4) {
        if (D_801A7320 <= 0) {
            D_801A7320 = 1;
        }
        if (D_801A7338 <= 0) {
            D_801A7338 = 1;
        }
    } else {
        if (D_801A7320 <= 0) {
            D_801A7320 = 0;
        }
        if (D_801A7338 <= 0) {
            D_801A7338 = 0;
        }
    }
    func_8008ECE4(&D_800ED89C, D_801A7320, D_801A7338, D_801A7268);
    return 0;
}

s32 func_8001C5E0(s32 arg0, s32 arg1) {
    if (arg1 >= 0) {
        if (D_801560F0->unk8 & D_80180FF4) {
            D_801A8C40 += 1;
        }
        if (D_801560F0->unk8 & D_8018101C) {
            D_801A8C40 -= 1;
        }
        if (D_801560F0->unk8 & D_80181258) {
            D_801A8C40 += 0xA;
        }
        if (D_801560F0->unk8 & D_80181260) {
            D_801A8C40 -= 0xA;
        }
        if (D_801560F0->unk8 & D_8018126C) {
            D_801A8C40 += 0x64;
        }
        if (D_801560F0->unk8 & D_801811AC) {
            D_801A8C40 -= 0x64;
        }
        if (D_801560F0->unk8 & D_80181042) {
            if (D_801A8C40 != 0x1F4) {
                D_801A8C40 = 0x1F4;
            } else {
                D_801A8C40 = -2;
            }
        }
        if (D_801560F0->unk6 & D_801810F2) {
            D_801A8D88[3] = (u16) (D_801A8D88[3] ^ 0x1000);
        }
        if (D_801560F0->unk6 & D_80180EEC) {
            D_801A8D88[3] = (u16) (D_801A8D88[3] ^ 0x2000);
        }
    }
    if (D_801A8C40 < -2) {
        D_801A8C40 = -2;
    }
    if (D_801A8D88[3] & 0x2000) {
        func_8008ECE4(&D_800ED8B0);
    } else {
        func_8008ECE4(&D_800ED8B4);
    }
    if (D_801A8D88[3] & 0x1000) {
        func_8008ECE4(&D_800ED8B8, D_801A8C40);
    } else if (D_801A8C40 >= 0) {
        func_8008ECE4(&D_800ED8CC, D_801A8C40);
    } else if (D_801A8C40 == -1) {
        func_8008ECE4(&D_800ED8E0);
    } else if (D_801A8C40 == -2) {
        func_8008ECE4(&D_800ED8F4);
    }
    return 0;
}

s32 func_8001C94C(s32 arg0, s32 arg1) {
    if (arg1 >= 0) {
        if (D_801560F0->unk8 & D_80180FF4) {
            D_801A8D70 += 1;
        }
        if (D_801560F0->unk8 & D_8018101C) {
            D_801A8D70 -= 1;
        }
        if (D_801560F0->unk8 & D_80181258) {
            D_801A8D78 += 1;
        }
        if (D_801560F0->unk8 & D_80181260) {
            D_801A8D78 -= 1;
        }
        if (D_801560F0->unk8 & D_8018126C) {
            D_801A8D80 += 1;
        }
        if (D_801560F0->unk8 & D_801811AC) {
            D_801A8D80 -= 1;
        }
        if (D_801560F0->unk6 & D_80181042) {
            if (D_801A8D70 < 0x1F4) {
                D_801A8D70 = 0x1F4;
            } else {
                D_801A8D70 = 1;
            }
        }
    }
    if (D_801A8D70 < 0) {
        D_801A8D70 = 0;
    }
    if (D_801A8D78 < 0) {
        D_801A8D78 = 0;
    }
    if (D_801A8D80 < 0) {
        D_801A8D80 = 0;
    }
    func_8008ECE4(&D_800ED908, D_801A8D70, D_801A8D78, D_801A8D80);
    return 0;
}

s32 func_8001CBAC(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && ((D_801560F0->unk8 & D_80180FF4) || (D_801560F0->unk8 & D_8018101C))) {
        *D_801A8D88 ^= 8;
    }
    if (*D_801A8D88 & 8) {
        func_8008ECE4(&D_800ED91C);
    } else {
        func_8008ECE4(&D_800ED924);
    }
    return 0;
}

s32 func_8001CC7C(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && ((D_801560F0->unk8 & D_80180FF4) || (D_801560F0->unk8 & D_8018101C))) {
        *D_801A8D88 ^= 0x4000;
    }
    if (*D_801A8D88 & 0x4000) {
        func_8008ECE4(&D_800ED92C);
    } else {
        func_8008ECE4(&D_800ED934);
    }
    return 0;
}

s32 func_8001CD4C(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (D_801560F0->unk6 & D_80180FF4)) {
        return 1;
    }
    return 0;
}

s32 func_8001CD9C(s32 arg0, s32 arg1) {
    s32 pad;
    if ((arg1 >= 0) && (D_801560F0->unk8 & D_80180FF4)) {
        *D_801A8D88 ^= 0x10;
    }
    if (*D_801A8D88 & 0x10) {
        func_8008ECE4(&D_800ED93C);
    } else {
        func_8008ECE4(&D_800ED944);
    }
    return 0;
}

s32 func_8001CE54(s32 arg0, s32 arg1) {
    s32 pad;
    if ((arg1 >= 0) && (D_801560F0->unk8 & D_80180FF4)) {
        *D_801A8D88 ^= 0x20;
    }
    if (*D_801A8D88 & 0x20) {
        func_8008ECE4(&D_800ED94C);
    } else {
        func_8008ECE4(&D_800ED954);
    }
    return 0;
}

s32 func_8001CF0C(s32 arg0, s32 arg1) {
    if ((D_801560F0->unk6 & (u16) D_801811A4) || (D_801560F0->unk6 & D_80180FF4)) {
        return 1;
    }
    return 0;
}

void func_8009A22C(void); /* extern */
void func_800C1680(void); /* extern */
extern u8 D_800DB4E8;

extern f64 D_800EDB70;
extern f64 D_800EDB78;

s32 func_8001CF70(UnkStruct_80020720* arg0) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    UnkStruct_80099E2C* sp38;
    UnkStruct_80099E2C* sp34;
    s32 sp30;
    s32 sp2C;
    f32* sp28;
    u8* sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4(&D_800ED95C, arg0->unk4);
    switch (D_801825E4) { /* irregular */
        case 0:
            D_80182618->ptrs[0] = SysMem_HeapAlloc(0xB00);
            D_801825F0[0] = 1;
            D_801825F0[1] = 0;
            D_801825F0[2] = 0xF;
            D_801825F0[3] = 1;
            D_801825F0[4] = 0;
            for (sp44 = 0; sp44 < 8; sp44++) {
                sp38 = (UnkStruct_80099E2C*) (D_80182618->ptrs[0] + (sp44 * 0x160));
                func_80099E2C(sp38);
                sp38->unkC0 |= 0x10C;
                sp38->unk116 = 1;
                sp38->unk138 = (s16*) D_801AB2B8;
                sp38->ptrs[0] = &D_800DB4E8;
                sp38->unkC8 = 0x1000;
                sp38->ptrs[1] = SysMem_HeapAlloc(0x40);

                for (sp40 = 0, sp28 = (f32*) sp38->ptrs[1]; sp40 < 16; sp40++) {
                    sp28[sp40] = 0.0f;
                }
                if (sp44 == 0) {
                    sp38->unkD0 = 0.0f;
                    sp38->unkF0 = 0.0f;
                    sp38->unkEC = 1.0f;
                    sp38->unkE4 = 8.0f;
                } else {
                    sp38->unkD0 = 8.0f;
                    sp38->unkF0 = 180.0f;
                    sp38->unkEC = -1.0f;
                    sp38->unkE4 = 8.0f;
                }
            }
            break;
        case 1:
            func_8008EAA8(2, 2);
            func_8008ECE4(&D_800ED968, D_801825F0[4]);
            func_8008ECE4(&D_800ED97C, D_801825F0[3], D_801825F0[2]);
            if (D_801560F0->unk6 & D_80181042) {
                for (sp44 = 0; sp44 < 8; sp44++) {
                    sp38 = (UnkStruct_80099E2C*) (D_80182618->ptrs[0] + (sp44 * 0x160));
                    sp24 = sp38->ptrs[1];
                    func_80099E2C(sp38);
                    sp38->unkC0 |= 0x10C;
                    sp38->unk116 = 1;
                    sp38->unk138 = (s16*) D_801AB2B8;
                    sp38->ptrs[0] = &D_800DB4E8;
                    sp38->unkC8 = 0x1000;
                    sp38->ptrs[1] = sp24;

                    for (sp40 = 0, sp28 = (f32*) sp38->ptrs[1]; sp40 < 16; sp40++) {
                        sp28[sp40] = 0.0f;
                    }
                    if (D_801825F0[4] == 0) {
                        if (sp44 == 0) {
                            sp38->unkD0 = 0.0f;
                            sp38->unkF0 = 0.0f;
                            sp38->unkEC = 1.0f;
                            sp38->unkE4 = 8.0f;
                        } else {
                            sp38->unkD0 = 8.0f;
                            sp38->unkF0 = 180.0f;
                            sp38->unkEC = -1.0f;
                            sp38->unkE4 = 8.0f;
                        }
                    } else if (sp44 == 0) {
                        sp38->unkD0 = 0.0f;
                        sp38->unkF0 = 0.0f;
                        sp38->unkEC = 1.0f;
                        sp38->unkE4 = 0.0f;
                    } else {
                        sp38->unkD0 = 0.0f;
                        sp38->unkF0 = 0.0f;
                        sp38->unkEC = -1.0f;
                        sp38->unkE4 = 0.0f;
                    }
                }
                D_801825F0[0] = 1;
                D_801825F0[2] = 0xF;
                D_801825F0[3] = 1;
            }
            if (D_801560F0->unk6 & D_80180FF4) {
                D_801825F0[1] ^= 1;
            }
            if (D_801560F0->unk6 & D_8018126C) {
                D_801825F0[2] += 1;
            }
            if (D_801560F0->unk6 & D_801811AC) {
                D_801825F0[2] -= 1;
            }
            if (D_801560F0->unk6 & D_80181258) {
                D_801825F0[3] += 1;
            }
            if (D_801560F0->unk6 & D_80181260) {
                D_801825F0[3] -= 1;
            }
            if (D_801825F0[2] < 0) {
                D_801825F0[2] = 0;
            }
            if (D_801825F0[2] >= 0x10) {
                D_801825F0[2] = 0xF;
            }
            if (D_801825F0[3] <= 0) {
                D_801825F0[3] = 1;
            }
            if (D_801825F0[3] >= 9) {
                D_801825F0[3] = 8;
            }
            if (D_801560F0->unk6 & D_8018101C) {
                D_801825F0[4] ^= 1;
            }
            func_800C1680();
            func_8009A22C();
            if (!(D_801560F0->unk4 & D_801810F2)) {
                if (D_801825F0[1] != 0) {
                    func_800C25B8(90.0f);
                    func_800C23E8(90.0f);
                }
            } else {
                func_800C25B8(D_801560F0->unk14);
                func_800C23E8(D_801560F0->unk10);
            }
            for (sp44 = 0; sp44 < 8; sp44++) {
                sp38 = (UnkStruct_80099E2C*) (D_80182618->ptrs[0] + (sp44 * 0x160));
                if (sp38->unkF0 != 0.0f) {
                    sp38->unkF0 += sp38->unkEC;
                } else {
                    sp38->unkEC = 0.0f;
                }
                sp28 = (f32*) sp38->ptrs[1];
                sp38->unkE8 = *sp28;
                SysMem_Copy8(sp28, sp28 + 1, D_801825F0[2] * 4);
                if (sp44 == 0) {
                    sp28[D_801825F0[2]] += (f32) D_801825F0[0];
                    if (sp28[D_801825F0[2]] > 60.0f) {
                        D_801825F0[0] = -D_801825F0[3];
                    }
                    if (sp28[D_801825F0[2]] < -60.0f) {
                        D_801825F0[0] = D_801825F0[3];
                    }
                } else {
                    sp28[D_801825F0[2]] = sp34->unkE8;
                }
                if (sp44 != 0) {
                    if ((f64) sp38->unkD0 < 8.0) {
                        sp38->unkD0 = (f32) ((f64) sp38->unkD0 + D_800EDB70);
                    }
                    if ((f64) sp38->unkD0 > 8.0) {
                        sp38->unkD0 = 8.0f;
                    }
                }
                if ((f64) sp38->unkE4 < 8.0) {
                    sp38->unkE4 = (f32) ((f64) sp38->unkE4 + D_800EDB78);
                }
                if ((f64) sp38->unkE4 > 8.0) {
                    sp38->unkE4 = 8.0f;
                }
                func_800C1680();
                func_800C2780(sp38->unkF0);
                func_800C2304(0.0f, sp38->unkD0, 0.0f);
                func_800997D8(sp38);
                func_800C2780(sp38->unkE8);
                func_800C2304(0.0f, sp38->unkE4, 0.0f);
                sp34 = sp38;
            }

            for (; sp44 > 0; sp44--) {
                func_800C1A28();
            }
            func_800C1A28();
            break;

        default:
            break;
    }
    if (D_801560F0->unk6 & (u16) D_801811A4) {
        for (sp44 = 0; sp44 < 8; sp44++) {
            sp38 = (UnkStruct_80099E2C*) (D_80182618->ptrs[0] + (sp44 * 0x160));
            SysMem_Free(sp38->ptrs[1]);
        }
        SysMem_Free(D_80182618->ptrs[0]);
        return -1;
    }
    return 0;
}

void func_800C1264(u8, s16*, s32); /* extern */

extern s32 D_80156B98;
extern s32 D_801AB248;

s32 func_8001DC00(UnkStruct_80020720* arg0) {
    s32 sp2C;
    UnkStruct_80099E2C* sp28;
    s32 temp_t7;

    func_8008EAA8(2, 0x10);
    func_8008ECE4(&D_800ED9A0, arg0->unk4);
    D_801825F0[5] = D_80156B98;
    switch (D_801825E4) { /* irregular */
        case 0:
            D_801825F0[0] = 1;
            D_801825F0[1] = 1;
            D_801825F0[2] = 0;
            D_801825F0[3] = 0;
            D_801825F0[4] = D_801AB248;
            D_801AB248 = 0x7FFFFFFF;
            /* fallthrough */
        case 1:
            func_8008EAA8(2, 0x10);
            D_80156B98 = D_801825F0[5];
            func_8008ECE4(&D_800ED9AC, D_801825F0[0], D_801825F0[1], D_801825F0[2]);
            if (D_801560F0->unk8 & D_8018101C) {
                D_801825F0[3] ^= 1;
            }
            func_8008EAA8(2, 0x11);
            D_80156B98 = D_801825F0[5];
            if (D_801825F0[3] == 0) {
                func_8008ECE4(&D_800ED9C0);
                if (D_801560F0->unk8 & D_80181260) {
                    D_801825F0[0] -= 1;
                }
                if (D_801560F0->unk8 & D_80181258) {
                    D_801825F0[0] += 1;
                }
            } else {
                func_8008ECE4(&D_800ED9CC);
                if (D_801560F0->unk8 & D_80181260) {
                    D_801825F0[1] -= 1;
                }
                if (D_801560F0->unk8 & D_80181258) {
                    D_801825F0[1] += 1;
                }
            }
            if (D_801825F0[0] <= 0) {
                D_801825F0[0] = 1;
            }
            if (D_801825F0[1] <= 0) {
                D_801825F0[1] = 1;
            }
            if (D_801560F0->unk8 & D_80180FF4) {
                func_800C1264(D_800F1918, &D_8015F7E0, 1);
            }
            if (D_801560F0->unk6 & D_801810F2) {
                D_801825F0[2] += 1;
            }
            D_801825F0[2] = (s32) D_801825F0[2] % 4;
            sp28 = D_801A8C18;
            for (sp2C = 0; sp2C < 4; sp2C++) {
                if (sp28->unkC0 & 0x10000000) {
                    func_800C1754();
                    if (D_801825F0[2] == sp2C) {
                        if (D_801560F0->unk6 & D_8018126C) {
                            sp28->unkC0 ^= 8;
                        }
                        if (D_801560F0->unk4 & D_80180EC0) {
                            sp28->unkCC = (f32) ((f64) sp28->unkCC - (1.0 * (f64) D_8018257C));
                        }
                        if (D_801560F0->unk4 & D_80180EEC) {
                            sp28->unkCC = (f32) ((f64) sp28->unkCC + (1.0 * (f64) D_8018257C));
                        }
                        if (D_801560F0->unk4 & D_80180E68) {
                            sp28->unkD0 = (f32) ((f64) sp28->unkD0 + (1.0 * (f64) D_8018257C));
                        }
                        if (D_801560F0->unk4 & D_80180E74) {
                            sp28->unkD0 = (f32) ((f64) sp28->unkD0 - (1.0 * (f64) D_8018257C));
                        }
                        if (D_801560F0->unk4 & D_80181038) {
                            sp28->unkD4 = (f32) ((f64) sp28->unkD4 - (1.0 * (f64) D_8018257C));
                        }
                        if (D_801560F0->unk4 & D_80181042) {
                            sp28->unkD4 = (f32) ((f64) sp28->unkD4 + (1.0 * (f64) D_8018257C));
                        }
                        if (sp28->unk11E < 0) {
                            sp28->unk11E = 0;
                        }
                        if (sp28->unk11E >= 0x100) {
                            sp28->unk11E = 0xFF;
                        }
                    }
                    func_800A7230(sp28);
                    func_800997D8(sp28);
                    func_800C1A28();
                    sp28++;
                }
            }
            break;
    }
    if (D_801560F0->unk6 & (u16) D_801811A4) {
        D_801AB248 = D_801825F0[4];
        return -1;
    }
    return 0;
}

s32 func_8005D2B0(void); /* extern */
void func_800BCB10(s32); /* extern */

extern s32 D_80180648;

s32 func_8001E348(UnkStruct_80020720* arg0) {
    s32 pad[2];
    func_8008EAA8(2, 1);
    func_8008ECE4(&D_800ED9D8, arg0->unk4);
    switch (D_801825E4) { /* irregular */
        case 0:
            D_801825F0[0] = 0;
            goto skip_dead_code;
        case 1:
            func_8008EAA8(2, 4);
            func_8008ECE4(&D_800ED9E4);
            if (D_801825F0[0] == 0) {
                func_8008EAA8(8, 6);
                func_8008ECE4(&D_800EDA10);
                func_8008EAA8(8, 7);
                func_8008ECE4(&D_800EDA18);
            } else {
                func_8008EAA8(8, 6);
                func_8008ECE4(&D_800EDA20);
                func_8008EAA8(8, 7);
                func_8008ECE4(&D_800EDA28);
            }
            if ((D_801560F0->unk8 & D_80180E68) || (D_801560F0->unk8 & D_80180E74)) {
                D_801825F0[0] ^= 1;
            }
            if ((D_801560F0->unk6 & D_80180FF4) && (D_801825F0[0] == 0)) {
                func_800BCB10(D_80180648);
                D_80180648 = func_8005D2B0();
                D_801825F0[1] = 0;
                D_801825E4 += 1;
            }
            if ((D_801560F0->unk6 & D_80180FF4) && (D_801825F0[0] != 0)) {
                return -1;
            }
            goto skip_dead_code;
        case 2:
            func_8008EAA8(2, 4);
            func_8008ECE4(&D_800EDA30);
            func_8008EAA8(8, 6);
            func_8008ECE4(&D_800EDA5C);
            func_8008EAA8(8, 7);
            func_8008ECE4(&D_800EDA64);
            D_801825F0[1] += 1;
            if (D_801825F0[1] >= 0x79) {
                return -1;
            }
            goto skip_dead_code;
        default:
            if (FALSE)
                ;
        skip_dead_code:
            if (D_801560F0->unk6 & (u16) D_801811A4) {
                return -1;
            }
            return 0;
    }
}

extern DebugMenuInfo D_800DB3F8[];

s32 func_8001E654(UnkStruct_80020720* arg0) {
    DebugMenuInfo* sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4(&D_800EDA6C, arg0->unk4);
    switch (D_801825E4) { /* irregular */
        case 0:
            *D_801825F0 = 0;
            /* fallthrough */
        case 1:
            func_8008EAA8(2, 4);
            sp24 = *D_801825F0;

            for (sp30 = 0, sp2C = 0, sp34 = D_800DB3F8; /* Empty */; sp30++, sp34++) {
                if (sp34->unk0 == -1) {
                    break;
                }

                if (sp34->unkC != -1) {
                    func_8008EAA8(sp34->unk8, sp34->unkC);
                    sp28 = sp34->unkC + 1;
                } else {
                    func_8008EAA8(sp34->unk8, sp28++);
                }
                if (sp34->unk10 != 0) {
                    if (sp24 == sp2C) {
                        func_8008ECE4(&D_800EDA78, sp34->optionName);
                        if (sp34->unk14 != NULL) {
                            sp34->unk14(sp34, 0);
                        }
                    } else {
                        func_8008ECE4(&D_800EDA7C, sp34->optionName);
                        if (sp34->unk14 != NULL) {
                            sp34->unk14(sp34, -1);
                        }
                    }
                    sp2C += 1;
                } else {
                    func_8008ECE4(&D_800EDA80, sp34->optionName);
                }
            }
            if (D_801560F0->unk8 & D_80180E68) {
                sp24 -= 1;
            }
            if (D_801560F0->unk8 & D_80180E74) {
                sp24 += 1;
            }
            if (sp24 < 0) {
                sp24 = sp2C - 1;
            }
            if (sp24 >= sp2C) {
                sp24 = 0;
            }
            *D_801825F0 = sp24;
            break;
    }
    if (D_801560F0->unk6 & (u16) D_801811A4) {
        return -1;
    }
    return 0;
}

void func_800BD9D0(s32, s32); /* extern */

s32 func_8001E980(s32 arg0, s32 arg1) {
    if (arg1 >= 0) {
        if (D_801560F0->unk8 & D_80180EC0) {
            D_80181680 -= 1;
        }
        if (D_801560F0->unk8 & D_80180EEC) {
            D_80181680 += 1;
        }
        if (D_80181680 < 0) {
            D_80181680 = 0;
        }
        if ((u32) D_80181680 >= 4U) {
            D_80181680 = 3;
        }
        func_800BD9D0(D_80181680, -1);
    }
    switch (D_80181680) { /* irregular */
        case 0:
            func_8008ECE4(&D_800EDA84);
            break;
        case 1:
            func_8008ECE4(&D_800EDAA4);
            break;
        case 2:
            func_8008ECE4(&D_800EDAC4);
            break;
        case 3:
            func_8008ECE4(&D_800EDAE4);
            break;
    }
    return 0;
}

void func_800BDA58(s32); /* extern */

s32 func_8001EB14(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && ((D_801560F0->unk8 & D_80180FF4) || (D_801560F0->unk8 & D_8018101C))) {
        if (D_8018168C & 1) {
            func_800BDA58(2);
        } else {
            func_800BDA58(1);
        }
    }
    if (D_8018168C & 1) {
        func_8008ECE4(&D_800EDB04);
    } else {
        func_8008ECE4(&D_800EDB0C);
    }
    return 0;
}

void func_800BDA58(s32); /* extern */

s32 func_8001EBF8(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && ((D_801560F0->unk8 & D_80180FF4) || (D_801560F0->unk8 & D_8018101C))) {
        if (D_8018168C & 4) {
            func_800BDA58(8);
        } else {
            func_800BDA58(4);
        }
    }
    if (D_8018168C & 4) {
        func_8008ECE4(&D_800EDB14);
    } else {
        func_8008ECE4(&D_800EDB1C);
    }
    return 0;
}

void func_800BDA58(s32); /* extern */

s32 func_8001ECDC(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && ((D_801560F0->unk8 & D_80180FF4) || (D_801560F0->unk8 & D_8018101C))) {
        if (D_8018168C & 0x10) {
            func_800BDA58(0x20);
        } else {
            func_800BDA58(0x10);
        }
    }
    if (D_8018168C & 0x10) {
        func_8008ECE4(&D_800EDB24);
    } else {
        func_8008ECE4(&D_800EDB2C);
    }
    return 0;
}

void func_800BDA58(s32); /* extern */

s32 func_8001EDC0(s32 arg0, s32 arg1) {
    func_800BDA58(0x40);
    if (D_8018168C & 0x40) {
        func_8008ECE4(&D_800EDB34);
    } else {
        func_8008ECE4(&D_800EDB3C);
    }
    return 0;
}

s32 func_8005F064(s32);  /* extern */
void func_8005F0DC(s32); /* extern */
void func_8005F268(s32); /* extern */
extern s32 D_800DB5F4;

s32 func_8001EE30(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 temp_t7;

    if (arg1 >= 0) {
        if (D_801560F0->unk8 & D_80180FF4) {
            D_800DB5F4 += 1;
        }
        if (D_801560F0->unk8 & D_8018101C) {
            D_800DB5F4 -= 1;
        }
        if (D_801560F0->unk8 & D_80181258) {
            D_800DB5F4 += 0xA;
        }
        if (D_801560F0->unk8 & D_80181260) {
            D_800DB5F4 -= 0xA;
        }
        if (D_801560F0->unk8 & D_8018126C) {
            D_800DB5F4 += 0x64;
        }
        if (D_801560F0->unk8 & D_801811AC) {
            D_800DB5F4 -= 0x64;
        }
        if (D_800DB5F4 <= 0) {
            D_800DB5F4 = 1;
        }
        if (D_800DB5F4 >= 0x201) {
            D_800DB5F4 = 0x200;
        }
        if (D_801560F0->unk6 & D_801810F2) {
            if (func_8005F064(D_800DB5F4) != 0) {
                func_8005F268(D_800DB5F4);
            } else {
                func_8005F0DC(D_800DB5F4);
            }
        }
        if (D_801560F0->unk8 & D_80181042) {
            for (sp1C = 1; sp1C < 0x201; sp1C++) {
                func_8005F268(sp1C);
            }
        }
    }
    func_8008ECE4(&D_800EDB44, D_800DB5F4);
    if (func_8005F064(D_800DB5F4) != 0) {
        func_8008ECE4(&D_800EDB50);
    } else {
        func_8008ECE4(&D_800EDB54);
    }
    return 0;
}

extern s16* D_80160480;
extern s32 D_801815D4;

s32 func_8001F104(s32 arg0, s32 arg1) {
    s32 pad[2];
    if (arg1 >= 0) {
        if (D_801560F0->unk8 & D_80180FF4) {
            D_801815D4 += 1;
        }
        if (D_801560F0->unk8 & D_8018101C) {
            D_801815D4 -= 1;
        }
        if (D_801560F0->unk8 & D_80181258) {
            D_801815D4 += 0xA;
        }
        if (D_801560F0->unk8 & D_80181260) {
            D_801815D4 -= 0xA;
        }
        if (D_801560F0->unk8 & D_8018126C) {
            D_801815D4 += 0x64;
        }
        if (D_801560F0->unk8 & D_801811AC) {
            D_801815D4 -= 0x64;
        }
        if (D_801560F0->unk8 & D_80180EC0) {
            D_801A70E8 += 0x1388;
        }
        if (D_801560F0->unk8 & D_80180EEC) {
            D_801A70E8 += 0x1388;
        }
        if (D_801815D4 < 0) {
            D_801815D4 = 0;
        }
        if (D_801815D4 >= 0x1388) {
            D_801815D4 = 0x1387;
        }
        if (D_801815D4 != 0) {
            *D_80160480 = (s16) D_801815D4;
        }
    }
    func_8008ECE4(&D_800EDB58, D_801815D4, D_801A70E8);
    return 0;
}
