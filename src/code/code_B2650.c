#include "common.h"

typedef struct ObjDef_s {
    u32 frames_offset;
    u16 u1;
    u16 u2;
    u16 u3;
    u16 u4;
    u16 u5;
    u8 frame_count;
    u8 pad1;
    u8 pad2;
    u8 pad3;
} ObjDef;

typedef struct ObjFrame_s {
    u16 spi_idx;
    u8 kind;
    u8 id;
    u8 delay;
    u8 u2;
    s16 x;
    s16 y;
    u16 u5;
    u8 u6;
    u8 u7;
} ObjFrame;

typedef struct UnkStruct_800B23C4_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char pad1[7];                        /* maybe part of unk0[8]? */
    /* 0x08 */ ObjDef* objDef;
    /* 0x0C */ ObjFrame* objFrame;
    /* 0x10 */ char pad10[0x10];                    /* maybe part of unkC[5]? */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ s8 unk30;
    /* 0x31 */ char pad31[3];                       /* maybe part of unk30[4]? */
    /* 0x34 */ f32 unk34;
    /* 0x38 */ s8 unk38;
    /* 0x39 */ char pad39[1];
    /* 0x3A */ s16 unk3A;                           /* inferred */
} UnkStruct_800B23C4;                               /* size = 0x3C */

extern s32 D_80180D30;
extern s32 D_80180D34;
extern s32 sObjDefsStart;
extern s32 sSpriteFrames;
extern s32 sMainSpritesSpiOffsets;
extern s32 sMainSpritesStart;
extern s32 D_80180D48;
extern s32 D_80180D4C;
extern s32 D_80180D50;
extern u16 D_80180D54;
extern s32 D_80180D60;
extern s32 D_80180D64;
extern s16 D_80180D68;
extern s16 D_80180D6A;
extern s16 D_80180D6C;
extern s8 D_80180D6E;
extern s8 D_80180D6F;

s32 func_800B23C4(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 objDefIdx, u16 arg3, f32 arg4, f32 arg5, u8 arg6);
void func_800B4F68(UnkStruct_80099E2C *arg0, UnkStruct_800B23C4 *arg1, u16 arg2);

void func_800B1A50(s32 arg0, s32 arg1, s32 objDefsStart, s32 spriteFramesStart, s32 mainSpritesSpiOffsets, s32 mainSprites, s32 arg6, s32 arg7, s32 arg8, u16 arg9) {
    D_80180D30 = arg0;
    D_80180D34 = arg1;
    sObjDefsStart = objDefsStart;
    sSpriteFrames = spriteFramesStart;
    sMainSpritesSpiOffsets = mainSpritesSpiOffsets;
    sMainSpritesStart = mainSprites;
    D_80180D48 = arg6;
    D_80180D4C = arg7;
    D_80180D50 = arg8;
    D_80180D54 = arg9;
    D_80180D60 = -1;
    D_80180D64 = 0;
    D_80180D68 = 0;
    D_80180D6A = 0;
    D_80180D6C = 0;
    D_80180D6E = 0;
    D_80180D6F = 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1CD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B1F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B202C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B23C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B26E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B2748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B2A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B2C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B2CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B2FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B32E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B334C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B351C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B35D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B407C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B4448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B4680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B47A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B4AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B4F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B53A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B55B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B56F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B57B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B69C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B6A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B6B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B6CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B6E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B73DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B748C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B749C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B75EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B77D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B79FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B7FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B8038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B80A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B8104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B81B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B82D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B8398.s")
