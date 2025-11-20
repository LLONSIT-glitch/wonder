#include "common.h"

void func_8000E3D4(UnkStruct_8000E3D4* arg0);
s32 func_8000DDE0(UnkStruct_8000DDE0* arg0);
void* TempHeap_Alloc(s32 size);           /* extern */
void func_8000D90C(UnkStruct_8000DDE0*); /* extern */
s32 func_8000DE84(UnkStruct_8000DDE0* arg0);
void func_80031728(void);                /* extern */
s32 func_80031AC8(void);                 /* extern */
s32 func_8004A054(s32, s16*);            /* extern */
void func_8000D74C(UnkStruct_8000DDE0*); /* extern */
void func_8000F53C(UnkStruct_8000DDE0*); /* extern */
void func_8000F598(UnkStruct_8000DDE0*); /* extern */
void func_80015BD0(UnkStruct_8000DDE0*); /* extern */
void func_8000F624(UnkStruct_8000DDE0 *);              /* extern */
void func_8000FCD8(UnkStruct_8000DDE0 *);              /* extern */
void func_80010150(UnkStruct_8000DDE0 *);              /* extern */
void func_80010460(UnkStruct_8000DDE0 *, s32);           /* extern */
void func_80010734(UnkStruct_8000DDE0 *);              /* extern */
void func_800108B8(UnkStruct_8000DDE0 *);              /* extern */
void func_80010AC8(UnkStruct_8000DDE0 *);              /* extern */
void func_80011040(UnkStruct_8000DDE0 *);              /* extern */
void func_80014F38(UnkStruct_8000DDE0 *);              /* extern */



extern s32 D_8015F804;

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000DE84.s")

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
    arg0->unk6C = 0.0f;
    arg0->unk70 = 0.0f;
    arg0->unk74 = 0.0f;
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
    UnkStruct_80099E2C* sp20;
    s32 sp1C;
    s16 sp1A;

    sp24 = arg0->unk20C;
    if (func_8004A054(sp24->unk7C, &sp1A) == 0) {
        return -1;
    }
    if (func_80031AC8() != -2) {
        func_800B2CBC((u8**) &sp24->unkC, (u8**) &sp24->unk10, 2);
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

s32 func_8000E7E4(UnkStruct_8000DDE0 *arg0) {
    UnkStruct_8000E3D4 *sp1C;

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000F4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000F53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000F598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000F624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000F9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000FCD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8000FE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80010150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80010460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80010734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800108B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80010AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800111E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8001173C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80011F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800123AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800124B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_8001292C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800129FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80012E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800131F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800139B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80013FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800140D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_800145D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_E9E0/func_80014BD4.s")
