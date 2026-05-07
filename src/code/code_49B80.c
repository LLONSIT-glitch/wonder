#include "common.h"

typedef struct UnkStruct_80180EF8_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char pad1[3]; /* maybe part of unk0[4]? */
    /* 0x04 */ s32 unk4;
    /* 0x08 */ char pad8[0x10]; /* maybe part of unk4[5]? */
    /* 0x18 */ UnkStruct_800F9C38* unk18;
    /* 0x1C */ struct UnkStruct_80180EF8_s* unk1C; // next?
    /* 0x20 */ u8 unk20;
    /* 0x21 */ char pad21[3]; /* maybe part of unk20[4]? */
} UnkStruct_80180EF8;         /* size = 0x24 */

typedef struct UnkStruct_800490C0_arg1_s {
    char pad[0x7E];
    u8 unk7E;
} UnkStruct_800490C0_arg1;

s32 func_8004975C(u8);     /* extern */
s32 func_8004984C(u8*);    /* extern */
s32 func_800498CC(u8);     /* extern */
void func_8004A0B4(void*); /* extern */
void func_80057E00(void*); /* extern */
void func_8005A9A0(void*); /* extern */
void func_8004D768(void*); /* extern */

extern s32 D_80180E64;
extern u8 D_80180EC8;
extern s32 D_80180ECC;
extern UnkStruct_800F9C38* D_80180EE0;
extern s8 D_80180EE8;
extern UnkStruct_80180EF8 D_80180EF8[];
extern u8 D_80180FF8;
extern s32 D_80180FFC;
extern UnkStruct_800F9C38* D_80181010;
extern s8 D_80181018;
extern UnkStruct_80180EF8* D_80181028[4];
extern u8 D_80181040;
extern OSMesgQueue D_801AC870;

void func_80048F80(void) {
    if ((D_801A7234 == 3) && (D_801A723C == 1)) {
        D_80180EC8 = Thread_CreateSimple(func_80057E00, &D_80180EC8, 0xD);
    } else if ((D_801A7234 == 3) && (D_801A723C == 0x18)) {
        D_80180EC8 = Thread_CreateSimple(func_8005A9A0, &D_80180EC8, 0xD);
    } else {
        D_80180EC8 = Thread_CreateSimple(func_8004A0B4, &D_80180EC8, 0xD);
    }
    func_800C0988(D_80180EC8);
    D_80180ECC = 0xD;
    D_80180EE0 = Thread_GetPtr(D_80180EC8);
    D_80180EE0->unk82F8 = D_80180E64;
    D_80180EE8 = 1;
    Thread_Start(D_80180EC8);
}

void func_800490C0(void (*arg0)(void*), UnkStruct_800490C0_arg1* arg1) {
    UnkStruct_80180EF8* sp1C;

    sp1C = &D_80180EF8[arg1->unk7E];
    sp1C->unk0 = Thread_CreateSimple(arg0, sp1C, 0xD);
    func_800C0988(sp1C->unk0);
    sp1C->unk4 = 0xD;
    sp1C->unk18 = Thread_GetPtr(sp1C->unk0);
    sp1C->unk18->unk82F8 = (s32) arg1;
    sp1C->unk20 = 1;
    Thread_Start(sp1C->unk0);
}

void func_800491A0(void) {
    D_80180FF8 = Thread_CreateSimple(func_8004D768, &D_80180FF8, 0xE);
    func_800C0988(D_80180FF8);
    D_80180FFC = 0xE;
    D_80181010 = Thread_GetPtr(D_80180FF8);
    D_80181018 = 1;
    Thread_Start(D_80180FF8);
}

s32 func_80049230(UnkStruct_80180EF8* arg0, void (*arg1)(void*), s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    UnkStruct_80180EF8* sp24;
    s32 sp20;
    u8 sp1F;
    UnkStruct_80180EF8* sp18;

    sp18 = arg0;
    for (sp1F = 1, sp20 = 0; sp20 < 4 && D_80181040 & sp1F; sp20++, sp1F <<= 1) {}

    if (sp20 == 4) {
        return 0;
    }
    D_80181040 |= sp1F;
    sp24 = SysMem_HeapAlloc(0x24);
    D_80181028[sp20] = sp24;
    sp24->unk0 = Thread_CreateSimple(arg1, sp24, sp18->unk4 - 1);
    func_800C0988(sp24->unk0);
    sp24->unk4 = (s32) (sp18->unk4 - 1);
    sp24->unk18 = Thread_GetPtr(sp24->unk0);
    sp24->unk1C = sp18;
    sp24->unk18->unk82F0 = (s16) arg2;
    sp24->unk18->unk82F2 = (s16) arg3;
    sp24->unk18->unk82F4 = (s16) arg4;
    sp24->unk18->unk82F6 = (s16) sp20;
    sp24->unk18->unk82F8 = arg5;
    sp18->unk1C = sp24;
    Thread_Start(sp24->unk0);
    return 1;
}

void func_80049438(UnkStruct_80180EF8* arg0) {
    s32 sp1C;
    u8 sp1B;

    Thread_DestroyThread(arg0->unk1C->unk0);
    SysMem_Free(D_80181028[arg0->unk1C->unk18->unk82F6]);
    D_80181028[arg0->unk1C->unk18->unk82F6] = NULL;

    for (sp1C = arg0->unk1C->unk18->unk82F6, sp1B = 1; sp1C != 0; sp1C--, sp1B <<= 1) {}
    D_80181040 &= ~sp1B;
}

s32 func_80049544(u8* arg0) {
    s32 pad;

    if (!(*D_801A8D88 & 2)) {
        if (*arg0 == D_80180FF8) {
            if ((u8) D_80180EE8 != 0) {
                return Thread_SendMesgNoBlock(D_80180EC8, &gScheduler, 0);
            }
            if (func_8004975C(0x64U) != 0) {
                return;
            }
            if (func_800498CC(0x64U) != 0) {
                return;
            }

            return Thread_SendMsg(&D_801AC870, &gScheduler, 0);
        } else if (*arg0 == D_80180EC8) {
            if (func_8004975C(0x64U) != 0) {
                return;
            }
            if (func_800498CC(0x64U) != 0) {
                return;
            }
            return Thread_SendMsg(&D_801AC870, &gScheduler, 0);
        } else if (func_8004984C(arg0) != 0) {
            if (func_8004975C(*arg0) != 0) {
                return;
            }
            if (func_800498CC(0x64U) != 0) {
                return;
            }
            return Thread_SendMsg(&D_801AC870, &gScheduler, 0);
        } else if (func_800498CC(*arg0) != 0) {
            return;
        }
    }
    return Thread_SendMsg(&D_801AC870, &gScheduler, 0);
}

s32 func_8004975C(u8 arg0) {
    s32 i;
    u8 sp1B;

    sp1B = arg0;
    for (i = 0; i < 7; i++) {
        if ((D_80180EF8[i].unk20 != 0) && (D_80180EF8[i].unk0 < sp1B)) {
            sp1B = D_80180EF8[i].unk0;
        }
    }
    if (sp1B < arg0) {
        Thread_SendMesgNoBlock(sp1B, &gScheduler, 0);
        return 1;
    }
    return 0;
}

s32 func_8004984C(u8* arg0) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if ((D_80180EF8[i].unk20 != 0) && (*arg0 == D_80180EF8[i].unk0)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_800498CC(u8 arg0) {
    s32 i;
    u8 sp1B;

    sp1B = arg0;
    for (i = 0; i < 4; i++) {
        if ((D_80181028[i] != NULL) && (D_80181028[i]->unk0 < sp1B)) {
            sp1B = D_80181028[i]->unk0;
        }
    }
    if (sp1B < arg0) {
        Thread_SendMesgNoBlock(sp1B, &gScheduler, 0);
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800499B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80049A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004A054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004A0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004B770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004BA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004BB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004D768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004DCE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004DEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004ECA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004EF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004F3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004F66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004F6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004F8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004FA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004FAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004FAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8004FE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005007C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005031C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800507AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005092C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80050A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80050AC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80051380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005151C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80051700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80051804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005218C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80052508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800526C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005274C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800527B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800527C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80053580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80054198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80054264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800543B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80054618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80054690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80055148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80055498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80055870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80055CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80055E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80055FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800560A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005618C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800561E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80056E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800574CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80057528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80057538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80057714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_800578E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80057960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80057AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80057E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80058824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80058B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80058E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80059BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80059C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80059D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80059D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80059E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_80059ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A2CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A7C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_49B80/func_8005A870.s")
