#include "common.h"

// TODO: Get the real size of these buffers!
typedef struct UnkStruct_801A72B8_s {
    char unk0[10];
    char pad[0x6];
    char unk10[1];
    char pad11[0x15F];
    char unk170[1];
} UnkStruct_801A72B8;

extern UnkStruct_801A72B8* D_801A72B8;
extern u8 D_801705B0[];
extern FuncPtr D_800DD438[];
extern u16 D_801A30C0;

void func_80043DC0(s32 arg0) {
    void (*sp1C)();

    D_801A30C0 = arg0;
    sp1C = D_800DD438[D_801A30C0];
    sp1C();
}

void func_80043E20(void) {
    u16 sp1E;
    SpriteObj* sp18;

    D_801A72B8 = SysMem_HeapAlloc(0x1050);
    for (sp1E = 0; sp1E < 10; sp1E++) {
        func_80099E2C(sp18 = (SpriteObj*) &D_801A72B8->unk10[sp1E * 0x1A0]);
        func_800B1B04(sp18, (UnkStruct_800B23C4*) &D_801A72B8->unk170[sp1E * 0x1A0]);
        sp18->unkC0 = 0x40004;
        sp18->unkC8 = 0x5A;
        sp18->unkC4 = 0x20;
        D_801A72B8->unk0[sp1E] = 0;
    }
}

void func_80043F14(u16 arg0, u16 arg1, u8** arg2, u8** arg3) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    u8 sp3B;
    u8 sp3A;
    u8* sp34;
    u8* sp30;
    u8* sp2C;
    u8* sp28;

    sp28 = arg3[0];
    sp30 = (arg3[1] = SysMem_HeapAlloc((sp3C = arg0 * 0xC8 * arg1)));
    for (sp4C = 0; sp4C < sp3C; sp4C++) {
        *sp30++ = 0;
    }
    sp30 = arg3[1];
    for (sp4C = 0; sp4C < arg1; sp4C++) {
        for (sp48 = 0; sp48 < arg0; sp48++) {
            if ((sp3A = *((arg1 * sp4C) + sp28 + sp48)) != 0xFF) {
                if ((sp34 = arg2[sp3A]) != 0) {
                    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((uintptr_t) gSeg_6E3A40_ROM_START,
                                                                        (uintptr_t) gSeg_6E3A40_VRAM, sp34),
                                   &D_801705B0, 0x3C);
                    sp34 = (arg0 * sp4C * 0xC8) + sp30 + (sp48 * 0xA);
                    sp2C = D_801705B0;
                    for (sp40 = 0; sp40 < 0x14; sp40++) {
                        sp3B = 0x80;
                        for (sp44 = 0; sp44 < 10; sp44++) {
                            sp3A = 0;
                            if (*sp2C & sp3B) {
                                sp3A = 0xF0;
                            }
                            sp3B = (u32) sp3B >> 1;
                            if (*sp2C & sp3B) {
                                sp3A |= 0xF;
                            }
                            *sp34 = sp3A;
                            sp34 += 1;
                            sp3B = (u32) sp3B >> 1;
                            if (sp3B == 0) {
                                sp2C += 1;
                                sp3B = 0x80;
                            }
                        }
                        sp2C++;
                        sp34 += (arg0 * 0xA) - 0xA;
                    }
                }
            }
        }
    }
}

void func_80044248(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u8 arg4, u16 arg5) {
    u16 spE;
    u16 spC;
    u16 spA;
    u8* sp4;
    s32 sp0;

    sp0 = D_801A71FC->unk4;

    spA = (u16) (u32) (arg0 * 0.5);
    for (spC = arg1; spC <= arg3; spC++) {
        sp4 = spA + sp0 + (spC * arg5);
        for (spE = arg0; spE <= arg2; spE++) {
            if (spE % 2) {
                *sp4++ |= arg4;
            } else {
                *sp4 |= arg4 * 0x10;
            }
        }
    }
}

void func_80044444(void) {
    SpriteObj* sp34;
    SpriteObj* sp30;
    SpriteObj* sp2C;

    sp34 = SysMem_HeapAlloc(0x1A0);
    D_80182618->ptrs[7] = (u8*) sp34;
    func_80099E2C((sp30 = sp34));
    func_800B1B04(sp30, (UnkStruct_800B23C4*) (sp2C = sp34 + 1));
    sp30->unkC0 = 0x8214;
    func_800B1F0C(sp30, (UnkStruct_800B23C4*) sp2C, 0xAE0250, 0x8000U, 0.0f, 0.0f, 0U);
    sp30->unkC8 = 0x7FFF;
    sp30->unkC4 = 0x10;
    sp30->unk11E = 0xFF;
    sp30->unkCC = -109.0f;
    sp30->unkD0 = -61.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_80044530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_800451C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_80045318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_8004629C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_80046980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_80047734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_80047808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_449C0/func_80048764.s")
