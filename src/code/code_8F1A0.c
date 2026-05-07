#include "common.h"
#include "compiler/ido/stdarg.h"

typedef struct UnkStruct_8015C748_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_8015C748;

typedef struct UnkStruct_8015C548_s {
    s16 unk0[1];
    char pad[0xFE];
    s16 unk100[7];
} UnkStruct_8015C548;

typedef struct UnkStruct_800962B0_arg0_s {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ s32 unk4;  /* inferred */
    /* 0x08 */ s32 unk8;  /* inferred */
    /* 0x0C */ s32 unkC;  /* inferred */
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ s32 unk18; /* inferred */
    /* 0x1C */ s32 unk1C; /* inferred */
    /* 0x20 */ s32 unk20; /* inferred */
    /* 0x24 */ s16 unk24; /* inferred */
    /* 0x26 */ char pad26[2];
    /* 0x28 */ f32 unk28;  /* inferred */
    /* 0x2C */ f32 unk2C;  /* inferred */
    /* 0x30 */ f32 unk30;  /* inferred */
    /* 0x34 */ f32 unk34;  /* inferred */
    /* 0x38 */ u16* fb;    /* inferred */
} UnkStruct_800962B0_arg0; /* size = 0x3C */

extern u16 D_8015BB40;
extern UnkStruct_8015C548 D_8015C548[];
extern u16 D_8015D790[];
extern u16* D_8015D7D4;
extern u16 D_8015BB38;
extern UnkStruct_8015C748 D_8015C748[];
extern u16 D_8015BB48[];
extern s32 D_8015B330;
extern s32 D_801561CC;
extern s32 D_801561D4;
extern s32 D_80156B98;
extern s32 D_80156BA0;
extern s32 D_80156C14;
extern u8* D_8015F810;
extern u8* D_8015F868;
extern u8* D_8015F870;
extern u8* D_8015F878;
extern u16 D_8015D748[];
extern u16* D_8015D788;
extern s32 D_8015C148[8];
extern s32 D_80156BA8;
extern u8 D_8015D7E0[];
extern u8* D_8015F800;
extern u8 D_800EF610[];
extern s32 D_800E4CA4;

int vsprintf(char* buffer, const char* format, va_list vlist);
void func_80090E58(char** buf);
void func_8008ED4C(u8*, u8*, s32); /* extern */

void func_8008E5A0(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x100; sp4++) {
        D_8015C748[sp4].unk0 = 0;
        D_8015C748[sp4].unk4 = 0;
        D_8015C748[sp4].unk8 = 1;
        D_8015C748[sp4].unkC = 0;
    }

    D_8015BB38 = 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008E630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008EAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008EC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008ECAC.s")

void Sys_SwapFrameBuffer(void* arg0) {
    gCurrentFrameBuffer = arg0;
}

void func_8008ECE4(char* format, ...) {
    va_list ap;
    char* s;
    char buf[0x400];
    s = buf;

    va_start(ap, format);
    vsprintf(s, format, ap);
    func_80090E58(&s);
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008ED4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/vsprintf.s")

void func_800906F8(s32 arg0, u16 arg1) {
    D_8015BB48[arg0] = (arg1 * 2) | (arg1 >> 0xF);
}

void func_80090728(s16 arg0) {
    D_8015B338 |= arg0;
}

void func_80090754(s16 arg0) {
    D_8015B338 &= arg0 ^ 0xFFFF;
}

void func_80090784(s32 arg0, s32 arg1, void* arg2, s32 arg3) {
    u16 spE;
    s32 pad;
    s32 sp4;
    s32 sp0;

    if (!(D_8015B338 & 1)) {
        sp4 = D_8015B328;
    } else {
        sp4 = D_8015B320;
    }
    sp0 = arg0;
    if ((arg0 == sp4) && (D_8015B338 & 2)) {
        spE = D_8015BB48[D_8015B330 + arg1];
        sp0 = D_8015B330 + arg1;
        goto cond;
    }
    spE = D_8015BB48[arg0];
cond:
    if (spE & 1) {
        if (!(D_8015B338 & 0x400)) {
            *(s16*) ((s16*) arg2 + arg3) = spE;
        } else {
            *(s8*) ((s8*) arg2 + arg3) = sp0;
        }
    }
}

void func_800908A0(s32 arg0, s32 arg1, void* arg2, s32 arg3, u32 arg4) {
    u16 spE;
    s32 pad;
    s32 sp4;
    s32 sp0;

    if (!(D_8015B338 & 1)) {
        sp4 = D_8015B328;
    } else {
        sp4 = D_8015B320;
    }
    sp0 = arg0;
    if ((arg0 == sp4) && (D_8015B338 & 2)) {
        spE = D_8015BB48[D_8015B330 + arg1];
        sp0 = D_8015B330 + arg1;
        goto cond;
    }

    spE = D_8015BB48[arg0];
cond:
    if (spE & 1) {
        if (!(D_8015B338 & 0x400)) {
            *(s16*) ((s16*) arg2 + arg3) = spE;
            *((s16*) ((s16*) arg2 + arg3) + 1) = spE;
            *(s16*) ((s16*) arg2 + arg3 + arg4) = spE;
            *((s16*) ((s16*) arg2 + arg3 + arg4) + 1) = spE;
        } else {
            *(s8*) ((s8*) arg2 + arg3) = sp0;
            *((s8*) ((s8*) arg2 + arg3) + 1) = sp0;
            *(s8*) ((s8*) arg2 + arg3 + arg4) = sp0;
            *((s8*) ((s8*) arg2 + arg3 + arg4) + 1) = sp0;
        }
    }
}

void func_80090A38(void* arg0, s32 arg1) {
    s32 pad;

    SysMem_Copy8(arg0, D_8015BB48, arg1 * 2);
}

void func_80090A7C(void) {
    if (!(D_8015B338 & 0x800)) {
        if (!(D_8015B338 & 0x100)) {
            if (D_8015B338 & 0x40) {
                D_801561CC = 0x10;
                D_801561D4 = 0x10;
            } else {
                if (D_8015B338 & 0x10) {
                    D_801561CC = 0xA;
                    D_801561D4 = 10;
                } else if (D_8015B338 & 0x20) {
                    D_801561CC = 0xC;
                    D_801561D4 = 0xE;
                } else if (D_8015B338 & 0x200) {
                    D_801561CC = 6;
                    D_801561D4 = 0xC;
                } else {
                    D_801561CC = 8;
                    D_801561D4 = 8;
                }
            }
        } else if (D_8015B338 & 0x40) {
            D_801561CC = 0x10;
            D_801561D4 = 0x10;
        } else if (D_8015B338 & 0x10) {
            D_801561CC = 0xA;
            D_801561D4 = 10;
        } else if (D_8015B338 & 0x20) {
            D_801561CC = 0x18;
            D_801561D4 = 0x1C;
        } else if (D_8015B338 & 0x200) {
            D_801561CC = 6;
            D_801561D4 = 0xC;
        } else {
            D_801561CC = 8;
            D_801561D4 = 8;
        }
    }
}

void func_80090C94(u16 arg0) {
    D_8015C548->unk100[arg0] ^= 1;
    if (((s32) (D_8015D7D4 - D_8015D790)) < 0x1F) {
        D_8015D7D4++, D_8015D7D4[0] = D_8015BB40;
    } else {
        D_8015D7D4[0] = D_8015BB40;
    }
    D_8015BB40 = arg0;
}

void func_80090D34(u16 arg0) {
    D_8015C548->unk100[arg0] ^= 1;
    if (D_8015D790 != D_8015D7D4) {
        D_8015BB40 = *D_8015D7D4, D_8015D7D4--;
    } else {
        D_8015BB40 = *D_8015D7D4;
    }
}

extern f32 D_8015BB30;

void func_80090DC0(void) {
    D_8015C548->unk100[2] = 0;
    D_8015C548->unk100[3] = 0;
    D_8015C548->unk100[4] = 0;
    D_8015C548->unk100[5] = 0;
    D_8015C548->unk100[6] = 0;
    D_8015D7D4 = D_8015D790;
    D_8015BB40 = D_8015BB38;
    D_8015BB30 = D_8015C548->unk0[D_8015BB40];
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090E58.s")

void func_80091A04(s32 arg0, s32 arg1) {
    s32 i;
    s32 sp20;
    u8 sp1F;

    for (i = 0; i < 8; i++) {
        sp20 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) i * D_8015BAF0)) + (f32) D_80156C14);
        if (D_8015B338 & 8) {
            sp1F = *(arg0 * 8 + i + D_8015F868 - 0x100);
        } else {
            sp1F = *(arg0 * 8 + i + D_8015F810);
        }
        if (sp1F & 0x80) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20);
        }
        if (sp1F & 0x40) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 1);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 1);
        }
        if (sp1F & 0x20) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 2);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 2);
        }
        if (sp1F & 0x10) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 3);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 3);
        }
        if (sp1F & 8) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 4);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 4);
        }
        if (sp1F & 4) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 5);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 5);
        }
        if (sp1F & 2) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 6);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 6);
        }
        if (sp1F & 1) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 7);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 7);
        }
    }
    D_80156B98 += arg1;
}

void func_80091E34(s32 arg0, s32 arg1) {
    s32 i;
    s32 sp20;
    u8 sp1F;

    for (i = 0; i < 10; i++) {
        sp20 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) i * D_8015BAF0)) + (f32) D_80156C14);
        sp1F = *((arg0 * 0x20) + (i * 2) + D_8015F870 - 0x400);
        if (sp1F & 0x80) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20);
        }
        if (sp1F & 0x40) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 1);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 1);
        }
        if (sp1F & 0x20) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 2);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 2);
        }
        if (sp1F & 0x10) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 3);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 3);
        }
        if (sp1F & 8) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 4);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 4);
        }
        if (sp1F & 4) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 5);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 5);
        }
        if (sp1F & 2) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 6);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 6);
        }
        if (sp1F & 1) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 7);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 7);
        }
        sp1F = *((arg0 * 0x20) + (i * 2) + D_8015F870 - 0x3FF);
        if (sp1F & 0x80) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 8);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 8);
        }
        if (sp1F & 0x40) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 9);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 9);
        }
    }
    D_80156B98 += arg1;
}

void func_8009230C(s32 arg0, s32 arg1) {
    s32 i;
    s32 sp28;
    u8 sp27;

    if (!(D_8015B338 & 0x100)) {
        for (i = 0; i < 12; i++) {
            sp28 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) i * D_8015BAF0)) +
                          (f32) D_80156C14);
            sp27 = *(arg0 * 0x20 + i * 2 + D_8015F874 - 0x400);
            if (sp27 & 0x80) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28);
            }
            if (sp27 & 0x40) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 1);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 1);
            }
            if (sp27 & 0x20) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 2);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 2);
            }
            if (sp27 & 0x10) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 3);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 3);
            }
            if (sp27 & 8) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 4);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 4);
            }
            if (sp27 & 4) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 5);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 5);
            }
            if (sp27 & 2) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 6);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 6);
            }
            if (sp27 & 1) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 7);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 7);
            }
            sp27 = *(arg0 * 0x20 + i * 2 + D_8015F874 - 0x3FF);
            if (sp27 & 0x80) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 8);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 8);
            }
            if (sp27 & 0x40) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 9);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 9);
            }
            if (sp27 & 0x20) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xA);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xA);
            }
            if (sp27 & 0x10) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xB);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xB);
            }
        }
    } else {
        for (i = 0; i < 12; i++) {
            sp28 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) (i * 2) * D_8015BAF0)) +
                          (f32) D_80156C14);
            sp27 = *(arg0 * 0x20 + i * 2 + D_8015F874 - 0x400);
            if (sp27 & 0x80) {

                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28, D_8015B344);
            }
            if (sp27 & 0x40) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 2, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 2, D_8015B344);
            }
            if (sp27 & 0x20) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 4, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 4, D_8015B344);
            }
            if (sp27 & 0x10) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 6, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 6, D_8015B344);
            }
            if (sp27 & 8) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 8, D_8015B344);
            } else {

                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 8, D_8015B344);
            }
            if (sp27 & 4) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xA, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xA, D_8015B344);
            }
            if (sp27 & 2) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xC, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xC, D_8015B344);
            }
            if (sp27 & 1) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xE, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xE, D_8015B344);
            }
            sp27 = *(arg0 * 0x20 + i * 2 + D_8015F874 - 0x3FF);
            if (sp27 & 0x80) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x10, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x10, D_8015B344);
            }
            if (sp27 & 0x40) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x12, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x12, D_8015B344);
            }
            if (sp27 & 0x20) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x14, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x14, D_8015B344);
            }
            if (sp27 & 0x10) {
                func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x16, D_8015B344);
            } else {
                func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x16, D_8015B344);
            }
        }
    }
    D_80156B98 += arg1;
}

void func_80093B30(s32 arg0, s32 arg1) {
    s32 i;
    s32 sp20;
    u8 sp1F;

    for (i = 0; i < 16; i++) {
        sp20 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) i * D_8015BAF0)) + (f32) D_80156C14);
        sp1F = *((arg0 * 0x20) + (i * 2) + D_8015F878 - 0x400);
        if (sp1F & 0x80) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20);
        }
        if (sp1F & 0x40) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 1);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 1);
        }
        if (sp1F & 0x20) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 2);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 2);
        }
        if (sp1F & 0x10) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 3);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 3);
        }
        if (sp1F & 8) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 4);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 4);
        }
        if (sp1F & 4) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 5);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 5);
        }
        if (sp1F & 2) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 6);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 6);
        }
        if (sp1F & 1) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 7);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 7);
        }
        sp1F = *((arg0 * 0x20) + (i * 2) + D_8015F878 - 0x3FF);
        if (sp1F & 0x80) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 8);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 8);
        }
        if (sp1F & 0x40) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 9);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 9);
        }
        if (sp1F & 0x20) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 0xA);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 0xA);
        }
        if (sp1F & 0x10) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 0xB);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 0xB);
        }
        if (sp1F & 8) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 0xC);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 0xC);
        }
        if (sp1F & 4) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 0xD);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 0xD);
        }
        if (sp1F & 2) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 0xE);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 0xE);
        }
        if (sp1F & 1) {
            func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp20 + 0xF);
        } else {
            func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp20 + 0xF);
        }
    }
    D_80156B98 += arg1;
}

void func_80094230(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 sp28;
    s32 pad;
    u8 sp23;

    if (arg0 < 0xFF) {
        for (i = 0; i < 12; i++) {
            sp28 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) i * D_8015BAF0)) +
                          (f32) D_80156C14);
            sp23 = *((arg0 * 6 * 2) + i + D_8015F880);
            if (sp23 & 0x80) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28);
            }
            if (sp23 & 0x40) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 1);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 1);
            }
            if (sp23 & 0x20) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 2);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 2);
            }
            if (sp23 & 0x10) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 3);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 3);
            }
            if (sp23 & 8) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 4);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 4);
            }
            if (sp23 & 4) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 5);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 5);
            }
            if (sp23 & 2) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 6);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 6);
            }
            if (sp23 & 1) {
                func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 7);
            } else {
                func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 7);
            }
        }
        D_80156B98 += arg1;
    } else {
        if (!(D_8015B338 & 0x100)) {
            for (i = 0; i < 12; i++) {
                sp28 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) i * D_8015BAF0)) +
                              (f32) D_80156C14);
                sp23 = *((arg0 * 12 * 2) + (i * 2) + D_8015F880 - 0x1200);
                if (sp23 & 0x80) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28);
                }
                if (sp23 & 0x40) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 1);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 1);
                }
                if (sp23 & 0x20) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 2);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 2);
                }
                if (sp23 & 0x10) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 3);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 3);
                }
                if (sp23 & 8) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 4);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 4);
                }
                if (sp23 & 4) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 5);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 5);
                }
                if (sp23 & 2) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 6);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 6);
                }
                if (sp23 & 1) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 7);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 7);
                }
                sp23 = *((arg0 * 12 * 2) + (i * 2) + D_8015F880 - 0x11FF);
                if (sp23 & 0x80) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 8);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 8);
                }
                if (sp23 & 0x40) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 9);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 9);
                }
                if (sp23 & 0x20) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xA);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xA);
                }
                if (sp23 & 0x10) {
                    func_80090784(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xB);
                } else {
                    func_80090784(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xB);
                }
            }
        } else {
            for (i = 0; i < 12; i++) {
                sp28 = (s32) ((f32) D_80156B98 + (((f32) D_80156BA0 * D_8015B344) + ((f32) (i * 2) * D_8015BAF0)) +
                              (f32) D_80156C14);
                sp23 = *((arg0 * 12 * 2) + (i * 2) + D_8015F880 - 0x1200);
                if (sp23 & 0x80) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28, (u32) D_8015B344);
                }
                if (sp23 & 0x40) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 2, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 2, (u32) D_8015B344);
                }

                if (sp23 & 0x20) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 4, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 4, (u32) D_8015B344);
                }
                if (sp23 & 0x10) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 6, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 6, (u32) D_8015B344);
                }
                if (sp23 & 8) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 8, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 8, (u32) D_8015B344);
                }
                if (sp23 & 4) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xA, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xA, (u32) D_8015B344);
                }
                if (sp23 & 2) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xC, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xC, (u32) D_8015B344);
                }
                if (sp23 & 1) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0xE, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0xE, (u32) D_8015B344);
                }
                sp23 = *((arg0 * 12 * 2) + (i * 2) + D_8015F880 - 0x11FF);
                if (sp23 & 0x80) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x10, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x10, (u32) D_8015B344);
                }
                if (sp23 & 0x40) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x12, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x12, (u32) D_8015B344);
                }
                if (sp23 & 0x20) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x14, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x14, (u32) D_8015B344);
                }
                if (sp23 & 0x10) {
                    func_800908A0(D_8015B328, i, gCurrentFrameBuffer, sp28 + 0x16, (u32) D_8015B344);
                } else {
                    func_800908A0(D_8015B320, i, gCurrentFrameBuffer, sp28 + 0x16, (u32) D_8015B344);
                }
            }
        }

        D_80156B98 += arg1 * 2;
    }
}

s32 func_80095E78(u8* arg0, u8* arg1) {
    u8 sp7;
    u8 sp6;

    sp7 = arg1[0] & 0x7F;
    sp6 = arg1[1] & 0x7F;
    if (((s32) sp7 % 2) == 1) {
        sp6 += 0x1F;
        if ((s32) sp6 >= 0x7F) {
            sp6 += 1;
        }
    } else {
        sp6 += 0x7E;
    }
    sp7 = ((s32) (sp7 - 0x21) >> 1) + 0x81;
    if ((s32) sp7 >= 0xA0) {
        sp7 += 0x40;
    }
    if (arg0 != NULL) {
        arg0[0] = sp7;
        arg0[1] = sp6;
        return 0;
    } else {
        return (sp7 << 8) | sp6;
    }
}

s32 func_80095F9C(s32 arg0) {
    u32 sp4;
    u32 sp0;

    sp4 = (u32) (arg0 & 0xFF00) >> 8;
    sp0 = arg0 & 0xFF;
    if ((sp0 >= 0x80U) && (sp0 < 0xFFU)) {
        arg0 -= 1;
    }
    arg0 = (arg0 - (sp4 * 0x44)) + 0x2244;
    return arg0;
}

void func_8009600C(void) {
    D_8015D788 = &D_8015D748;
    D_8015D7D4 = D_8015D790;
    D_8015B328 = 0xFF;
    D_8015BB40 = D_8015BB38;
    *D_8015D788 = D_8015B328;
    *D_8015D7D4 = D_8015BB40;
    D_8015BB30 = 0.0f;
    D_8015C548->unk100[2] = 0;
    D_8015C548->unk100[3] = 0;
    D_8015C548->unk100[4] = 0;
    D_8015C548->unk100[5] = 0;
    D_8015C548->unk100[6] = 0;
    D_8015B338 &= ~0x100;
}

extern s32 D_8015BD48[];

void func_800960E8(u16 arg0) {
    D_8015BD48[arg0 + 0x100] ^= 1;
    if (((s32) (D_8015D788 - D_8015D748)) < 0x1F) {
        D_8015D788++, D_8015D788[0] = D_8015B328;
    } else {
        D_8015D788[0] = D_8015B328;
    }
    D_8015B328 = D_8015BD48[arg0];
}

void func_80096198(u16 arg0) {
    D_8015B328 = D_8015BD48[arg0];
}

void func_800961C4(u16 arg0) {
    D_8015BD48[arg0 + 0x100] ^= 1;
    if (D_8015D748 != D_8015D788) {
        D_8015B328 = *D_8015D788, D_8015D788--;
    } else {
        D_8015B328 = *D_8015D788;
    }
}

void func_80096250(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_8015C148[i] = 0;
    }
    D_8015D788 = D_8015D748;
    D_8015B328 = 0xFF;
}

void func_800962B0(UnkStruct_800962B0_arg0* arg0) {
    D_80156B98 = arg0->unk0;
    D_80156BA0 = arg0->unk4;
    D_80156BA8 = arg0->unk8;
    D_80156BC0 = arg0->unkC;
    D_80156C08 = arg0->unk10;
    D_80156C14 = arg0->unk14;
    D_8015B320 = arg0->unk18;
    D_8015B328 = arg0->unk1C;
    D_8015B330 = arg0->unk20;
    D_8015B338 = arg0->unk24;
    D_8015B344 = arg0->unk28;
    D_8015BACC = arg0->unk2C;
    D_8015BAF0 = arg0->unk30;
    D_8015BB28 = arg0->unk34;
    gCurrentFrameBuffer = arg0->fb;
}

void func_80096374(UnkStruct_800962B0_arg0* arg0) {
    arg0->unk0 = D_80156B98;
    arg0->unk4 = D_80156BA0;
    arg0->unk8 = D_80156BA8;
    arg0->unkC = D_80156BC0;
    arg0->unk10 = D_80156C08;
    arg0->unk14 = D_80156C14;
    arg0->unk18 = D_8015B320;
    arg0->unk1C = D_8015B328;
    arg0->unk20 = D_8015B330;
    arg0->unk24 = D_8015B338;
    arg0->unk28 = D_8015B344;
    arg0->unk2C = D_8015BACC;
    arg0->unk30 = D_8015BAF0;
    arg0->unk34 = D_8015BB28;
    arg0->fb = gCurrentFrameBuffer;
}

s32 func_80096474(void) {
    if ((D_8015F800 - D_8015D7E0) >= 0x1F01) {
        return -1;
    }
    SysMem_Copy8(D_8015F800, &D_8015BB48[D_8015B328], 2);
    D_8015F800 += 2;
    SysMem_Copy8(D_8015F800, &D_8015BB48[D_8015B320], 2);
    D_8015F800 += 2;
    SysMem_Copy8(D_8015F800, &D_80156B98, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_80156BA0, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_80156BA8, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_80156BC0, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_80156C08, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_80156C14, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015B320, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015B328, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015B330, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015B338, 2);
    D_8015F800 += 2;
    SysMem_Copy8(D_8015F800, &D_8015B344, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015BACC, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015BAF0, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &D_8015BB28, 4);
    D_8015F800 += 4;
    SysMem_Copy8(D_8015F800, &gCurrentFrameBuffer, 4);
    D_8015F800 += 4;
    osWritebackDCacheAll();
    return 0;
}

s32 func_800967D8(void) {
    if ((D_8015F800 - D_8015D7E0) <= 0) {
        return -1;
    }
    D_8015F800 -= 4;
    SysMem_Copy8(&gCurrentFrameBuffer, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015BB28, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015BAF0, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015BACC, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015B344, D_8015F800, 4);
    D_8015F800 -= 2;
    SysMem_Copy8(&D_8015B338, D_8015F800, 2);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015B330, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015B328, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_8015B320, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_80156C14, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_80156C08, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_80156BC0, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_80156BA8, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_80156BA0, D_8015F800, 4);
    D_8015F800 -= 4;
    SysMem_Copy8(&D_80156B98, D_8015F800, 4);
    D_8015F800 -= 2;
    SysMem_Copy8(&D_8015BB48[D_8015B320], D_8015F800, 2);
    D_8015F800 -= 2;
    SysMem_Copy8(&D_8015BB48[D_8015B328], D_8015F800, 2);
    osWritebackDCacheAll();
    return 0;
}

s32 func_80096B38(u32 arg0, s32 arg1, s32 arg2, u32 arg3, void** arg4, s32 arg5) {
    s32 sp30[2];
    void* sp2C;
    void* sp28;

    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual(arg0, arg1, (arg5 * 4) + arg2), &sp30, 8);
    sp28 = SysMem_HeapAlloc(sp30[1] - sp30[0]);
    if ((arg3 >= 0x80000000U) && (arg3 < 0x80400000U)) {
        sp2C = sp30[0] + arg3;
        SysMem_Copy8(sp28, sp2C, sp30[1] - sp30[0]);
    } else {
        sp2C = SysMem_GetPhysicalAddressFromVirtual(arg0, arg1, sp30[0] + arg3);
        SysMem_DmaCopy((u32) sp2C, sp28, sp30[1] - sp30[0]);
    }
    *arg4 = sp28;
    return sp2C;
}

void func_80096C6C(s32 arg0, u8* arg1) {
    u8* sp1C;

    sp1C = arg1;
    do {
        func_800319B0(arg0);
        do {
            arg0++;
            arg1++;
        } while (*arg1 != 0);

        do {
            arg0++;
            arg1++;
        } while (*arg1 == 0);

    } while (*arg1 != 1);
    SysMem_Free(sp1C);
}

s32 func_80096D40(s32 arg0, u8* arg1, s32* arg2) {
    s32 sp1C;
    u8* sp18;

    sp18 = arg1;
    sp1C = 0;
    do {
        arg2[sp1C] = arg0;
        sp1C += 1;
        arg2[sp1C] = 0;
        do {
            arg0++;
            arg1++;
        } while (*arg1 != 0);

        do {
            arg0++;
            arg1++;
        } while (*arg1 == 0);

    } while (*arg1 != 1);
    SysMem_Free(sp18);
    return sp1C;
}

void* func_80096E58(va_list arg0, s32 arg1) {
    void* sp1C;
    void* temp_v0;

    sp1C = SysMem_HeapAlloc(arg1 + 1);
    func_8008ED4C(sp1C, D_800EF610, arg0);
    return sp1C;
}

void func_80096EB0(s32 arg0, ...) {
    D_800E4CA4 = 1;
}
