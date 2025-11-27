#include "common.h"

extern s32 D_80180D30;
extern s32 D_80180D34;
extern s32 sObjDefsStart;
extern s32 sSpriteFrames;
extern s32 sMainSpritesSpiOffsets;
extern s32 sMainSpritesStart;
extern SpritePalette* sMainSpritesPalettes;
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

s32 func_800B23C4(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 objDefIdx, u16 arg3, f32 arg4, f32 arg5,
                  u8 arg6);
void func_800B4F68(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 arg2);
void LoadPalette(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 arg2);
s32 func_800B3EC0(ObjInfo*, s32);                             /* extern */
void func_800B4AB4(UnkStruct_80099E2C*, UnkStruct_800B23C4*); /* extern */
void func_800B5558(UnkStruct_80099E2C*, UnkStruct_800B23C4*); /* extern */
s32 func_800B2A34(UnkStruct_80099E2C*, UnkStruct_800B23C4*);
void func_800B4AB4(UnkStruct_80099E2C*, UnkStruct_800B23C4*); /* extern */
void func_800B5558(UnkStruct_80099E2C*, UnkStruct_800B23C4*); /* extern */
s32 func_800B2FB0(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, s32 arg2);
s32 func_800B351C(UnkStruct_800B23C4*);                                 /* extern */
void func_800B47A0(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4*, u16); /* extern */
s32 func_800B4680(UnkStruct_800B23C4* arg0, u8 arg1);
s32 func_800B5730(void);  /* extern */
s32 func_800B6A00(u16*);  /* extern */
u16 func_800B8398(void);  /* extern */
void func_80031728(void); /* extern */
void func_800B57B0(void); /* extern */
void func_800B5AA0(void); /* extern */
s32 func_800B5AF0(void);  /* extern */
s32 func_800B5FB4(void);  /* extern */

void func_800B1A50(s32 arg0, s32 arg1, s32 objDefsStart, s32 spriteFramesStart, s32 mainSpritesSpiOffsets,
                   s32 mainSprites, s32 mainSpritesPalettes, s32 arg7, s32 arg8, u16 arg9) {
    D_80180D30 = arg0;
    D_80180D34 = arg1;
    sObjDefsStart = objDefsStart;
    sSpriteFrames = spriteFramesStart;
    sMainSpritesSpiOffsets = mainSpritesSpiOffsets;
    sMainSpritesStart = mainSprites;
    sMainSpritesPalettes = (SpritePalette*) mainSpritesPalettes;
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

void func_800B1E58(UnkStruct_80099E2C*, UnkStruct_800B23C4*); /* extern */

void func_800B1B04(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    func_800B1E58(arg0, arg1);
}

void func_800B1B3C(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, s32 arg2) {
    for (arg2--; arg2 >= 0; arg2--) {
        func_800B1E58(*arg0 + arg2, *arg1 + arg2);
    }
}
void func_800B1CD4(UnkStruct_80099E2C*, UnkStruct_800B23C4*); /* extern */

void func_800B1BC8(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    func_800B1CD4(arg0, arg1);
    func_800B1E58(arg0, arg1);
}

void func_800B1C10(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, s32 arg2) {
    s32 pad[2];

    for (arg2--; arg2 >= 0; arg2--) {
        func_800B1CD4(*arg0 + arg2, *arg1 + arg2);
        func_800B1E58(*arg0 + arg2, *arg1 + arg2);
    }
}

void func_800B1CD4(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    s32 sp1C;

    if (arg0 != NULL) {
        for (sp1C = 0; sp1C < 3; sp1C++) {
            if (arg0->ptrs[sp1C + 1] != 0) {
                SysMem_Free(arg0->ptrs[sp1C + 1]);
            }
        }
    }
    if (arg1 == NULL) {
        return;
    }
    for (sp1C = 0; sp1C < 3; sp1C++) {
        if (arg1->spritePalette[sp1C] != NULL) {
            SysMem_Free(arg1->spritePalette[sp1C]);
        }
    }
    if (arg1->objInfo != NULL) {
        SysMem_Free(arg1->objInfo);
    }
    if (arg1->objDef != NULL) {
        SysMem_Free(arg1->objDef);
    }
    if (arg1->objFrame != NULL) {
        SysMem_Free(arg1->objFrame);
    }
}

void func_800B1E58(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    s32 sp4;

    if (arg0 != NULL) {
        for (sp4 = 0; sp4 < 3; sp4++) {
            arg0->ptrs[sp4 + 1] = NULL;
        }
    }
    if (arg1 == NULL) {
        return;
    }
    for (sp4 = 0; sp4 < 3; sp4++) {
        arg1->spritePalette[sp4] = NULL;
    }

    arg1->objInfo = NULL;
    arg1->objDef = NULL;
    arg1->objFrame = NULL;
    arg1->unk10 = -1;
    arg1->currentPaletteIndex = -1;
    arg1->unk3A = 0;
    arg1->unk3C = 0;
    arg1->paletteIndex = 0;
}

s32 func_800B1F0C(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, s32 arg2, u16 arg3, f32 arg4, f32 arg5, u8 arg6) {
    u16 sp36;

    if (arg1->objInfo == NULL) {
        arg1->objInfo = SysMem_HeapAlloc(0x10);
    }
    if (func_800B3EC0(arg1->objInfo, arg2) != 0) {
        return -1;
    }
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment, (s32) gSpriteSeg1VramStart,
                                                        arg1->objInfo->u1 + D_80180D34),
                   &sp36, 2);
    if (func_800B23C4(arg0, arg1, sp36, arg3, arg4, arg5, (u8) (s32) arg6) != 0) {
        arg1->unk3A = (u16) arg1->unk3A | 0x400;
        return -1;
    }
    return 1;
}

s32 func_800B202C(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, u32 arg2, u16 arg3, f32 arg4, f32 arg5,
                  u8 arg6) {
    u16 sp40[15];
    s32 sp3C;
    s32 sp38;
    s32 sp34;

    sp34 = 0;
    if ((*arg1)->objInfo == NULL) {
        (*arg1)->objInfo = SysMem_HeapAlloc(sizeof(ObjInfo));
    }
    if (func_800B3EC0((*arg1)->objInfo, (s32) arg2) != 0) {
        return -1;
    }
    sp3C = (s32) (*arg1)->objInfo->obj_count;
    if (arg6 & 4) {
        sp3C += (*arg1)->objInfo->extra_obj_count;
    }
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment, (s32) gSpriteSeg1VramStart,
                                                        (*arg1)->objInfo->u1 + D_80180D34),
                   &sp40, sp3C * 2);
    for (sp38 = 0; sp38 < sp3C; sp38++) {
        if (func_800B23C4(*arg0 + sp38, *arg1 + sp38, sp40[sp38], arg3, arg4, arg5, arg6) != 0) {
            (*arg1)[sp38].unk3A |= 0x400;
        }
    }

    for (sp38 = 0; sp38 < sp3C; sp38++) {
        if (!((*arg1)[sp38].unk3A & 0x400)) {
            break;
        }
    }

    if (sp38 >= sp3C) {
        return -1;
    }
    if (((*arg1)->unk0 & 4)) {
        if (((*arg1)->unk3A & 0x1000)) {
            FAKE_ACCESS(UnkStruct_80099E2C, *arg0, arg1[0]->objInfo->obj_count, unkC0) |= 0x80;
        }
    }

    for (sp38 = 0; sp38 < sp3C; sp38++) {
        if ((*arg1)[sp38].unk3A & 0x400) {
            (*arg0)[sp38].unkC0 |= 0x80;
        }
    }
    return sp3C;
}

s32 func_800B407C(UnkStruct_80099E2C*, UnkStruct_800B23C4*, u16); /* extern */

#ifdef NEEDS_RODATA
s32 func_800B23C4(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 objDefIdx, u16 arg3, f32 arg4, f32 arg5,
                  u8 arg6) {
    arg1->unk0 = arg6;
    if (arg1->objDef == NULL) {
        arg1->objDef = SysMem_HeapAlloc(0x14);
    }
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment, (s32) gSpriteSeg1VramStart,
                                                        (objDefIdx * 0x14) + sObjDefsStart),
                   arg1->objDef, 0x14);
    if (arg1->objFrame == NULL) {
        arg1->objFrame = SysMem_HeapAlloc(0x380);
    }
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment, (s32) gSpriteSeg1VramStart,
                                                        arg1->objDef->frames_offset + sSpriteFrames),
                   arg1->objFrame, arg1->objDef->pad2 * 0xE);
    arg1->unk30 = 0;
    arg1->unk20 = (f32) ((f64) (s16) arg1->objDef->u1 * 0.10);
    arg1->unk24 = (f32) ((f64) (s16) arg1->objDef->u2 * 0.10);
    arg1->unk28 = (f32) ((f64) (s16) arg1->objDef->u3 * 0.10);
    arg1->unk2C = (f32) ((f64) (s16) arg1->objDef->u4 * 0.10);
    if (arg6 & 1) {
        arg1->unk20 = -arg1->unk20;
        arg1->unk28 = -arg1->unk28;
    }
    if (arg6 & 2) {
        arg1->unk20 = -arg1->unk24;
        arg1->unk28 = -arg1->unk2C;
    }
    arg1->unk34 = 0.0f;
    arg1->unk38 = 0;
    arg1->unk3A = 0;
    arg0->unkCC = arg4;
    arg0->unkD0 = arg5;
    arg0->unkC0 &= ~0x80;
    if (func_800B407C(arg0, arg1, arg3) != 0) {
        return -1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B23C4.s")
#endif

s32 func_800B26E0(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    if (func_800B2A34(arg0, arg1) != 0) {
        arg1->unk3A = (u16) (arg1->unk3A | 0x400);
        return -1;
    }
    return 1;
}

s32 func_800B2748(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1) {
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) (*arg1)->objInfo->obj_count;
    if ((*arg1)->unk0 & 4) {
        sp1C += (*arg1)->objInfo->extra_obj_count;
    }
    for (sp18 = 0; sp18 < sp1C; sp18++) {
        if ((*arg1)[sp18].unk3A & 0x400) {
            continue;
        }

        if (func_800B2A34(&(*arg0)[sp18], &(*arg1)[sp18]) != 0) {
            (*arg1)[sp18].unk3A |= 0x400;
        }
    }

    for (sp18 = 0; sp18 < sp1C; sp18++) {
        if (!((*arg1)[sp18].unk3A & 0x400)) {
            break;
        }
    }
    if (sp18 >= sp1C) {
        return -1;
    }
    if (((*arg1)->unk0 & 4)) {
        if (((*arg1)->unk3A & 0x1000)) {
            FAKE_ACCESS(UnkStruct_80099E2C, *arg0, arg1[0]->objInfo->obj_count, unkC0) |= 0x80;
        }
    }

    for (sp18 = 0; sp18 < sp1C; sp18++) {
        if ((*arg1)[sp18].unk3A & 0x400) {
            (*arg0)[sp18].unkC0 |= 0x80;
        }
    }
    return sp1C;
}

s32 func_800B2A34(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    if ((s32) (u8) arg1->unk30 >= (s32) arg1->objDef->pad2) {
        return -1;
    }
    if (arg1->unk3A & 0x200) {
        return 0;
    }
    if ((f64) arg1->unk34 > 0.0) {
        if (!(arg1->unk3A & 0x8F)) {
            if (arg1->unk0 & 8) {
                arg1->unk34 = (f32) ((f64) arg1->unk34 - 0.5);
            } else {
                arg1->unk34 = (f32) ((f64) arg1->unk34 - ((f64) D_8018257C / 2.0));
            }
        }
        if ((f64) arg1->unk34 > 0.0) {
            func_800B4AB4(arg0, arg1);
            func_800B5558(arg0, arg1);
            return 0;
        }
    }
    arg1->unk30 = (u8) arg1->unk30 + 1;
    if ((s32) (u8) arg1->unk30 >= (s32) arg1->objDef->pad2) {
        arg1->unk30 = arg1->objDef->pad2 - 1;
        return -1;
    }
    if (func_800B407C(arg0, arg1, arg1->currentPaletteIndex) != 0) {
        return -1;
    }
    return 0;
}


s32 func_800B2C4C(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u8 arg2) {
    if (func_800B2FB0(arg0, arg1, arg2) != 0) {
        arg1->unk3A |= 0x400;
        return -1;
    }
    return 1;
}

s32 func_800B2CBC(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, s32 arg2) {
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) (*arg1)->objInfo->obj_count;
    if ((*arg1)->unk0 & 4) {
        sp1C += (*arg1)->objInfo->extra_obj_count;
    }
    for (sp18 = 0; sp18 < sp1C; sp18++) {
        if ((*arg1)[sp18].unk3A & 0x400) {
            continue;
        }
        if (func_800B2FB0(&(*arg0)[sp18], &(*arg1)[sp18], (u8) arg2) != 0) {
            (*arg1)[sp18].unk3A |= 0x400;
        }
    }
    for (sp18 = 0; sp18 < sp1C; sp18++) {
        if (!((*arg1)[sp18].unk3A & 0x400)) {
            break;
        }
    }

    if (sp18 >= sp1C) {
        return -1;
    }
    if (((*arg1)->unk0 & 4)) {
        if (((*arg1)->unk3A & 0x1000)) {
            FAKE_ACCESS(UnkStruct_80099E2C, *arg0, arg1[0]->objInfo->obj_count, unkC0) |= 0x80;
        }
    }

    for (sp18 = 0; sp18 < sp1C; sp18++) {
        if ((*arg1)[sp18].unk3A & 0x400) {
            (*arg0)[sp18].unkC0 |= 0x80;
        }
    }
    return sp1C;
}

#ifdef NEEDS_RODATA
s32 func_800B2FB0(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u8 arg2) {
    switch (arg2) {
        case 1:
            if (arg1->unk3A & 4) {
                arg1->unk3A &= ~4;
                arg1->unk24 = 0.0f;
                arg1->unk2C = 0.0f;
            }
            if (arg1->unk3A & 0x10) {
                arg1->unk3A &= ~0x10;
                if (func_800B4448(arg0, arg1, 2U) != 0) {
                    return -1;
                }
                func_800B47A0(arg0, arg1, arg1->currentPaletteIndex);
            }
            break;
        case 2:
            if (arg1->unk3A & 8) {
                arg1->unk3A &= ~8;
            }
            if (arg1->unk3A & 0x80) {
                arg1->unk3A &= ~0x80;
            }
            if (func_800B4680(arg1, 3) != 0) {
                arg1->unk3A &= ~0x20;
                if (func_800B4448(arg0, arg1, 3U) != 0) {
                    return -1;
                }
            }
            arg1->unk3A |= 0x100;
            break;
        case 3:
            arg1->unk3A |= 0x200;
            break;
        case 4:
            arg1->unk3A &= ~0x200;
            break;
        case 5:
            arg1->unk3A &= ~0x1000;
            break;
        case 6:
            arg1->unk3A |= 0x1000;
            break;
        default:
            break;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B2FB0.s")
#endif

s32 func_800B3230(u16* arg0, s16* arg1, s16* arg2, s32 arg3) {
    ObjInfo sp18;

    if (func_800B3EC0(&sp18, arg3) != 0) {
        return -1;
    }
    if (arg0 != NULL) {
        *arg0 = sp18.flags;
    }
    if (arg1 != NULL) {
        *arg1 = sp18.u2;
    }
    if (arg2 != NULL) {
        *arg2 = sp18.u3;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B32E4.s")

s32 func_800B3590(UnkStruct_800B23C4*); /* extern */

s32 func_800B3314(UnkStruct_800B23C4* arg0) {
    return func_800B3590(arg0);
}

s32 func_800B334C(UnkStruct_800B23C4** arg0, u8 arg1) {
    UnkStruct_800B23C4* temp_t8;

    if (!(arg1 & 4)) {
        return func_800B3590(*arg0);
    }
    if (!((*arg0)->unk0 & 4)) {
        return 0;
    }
    if ((*arg0)->objInfo->extra_obj_count == 0) {
        return 0x1000;
    }
    return func_800B3590(&(*arg0)[(*arg0)->objInfo->obj_count]);
}

s32 func_800B3434(UnkStruct_800B23C4** arg0, u8 arg1) {

    if (!(arg1 & 4)) {
        return func_800B351C(*arg0);
    }
    if (!((*arg0)->unk0 & 4)) {
        return 0;
    }
    if ((*arg0)->objInfo->extra_obj_count == 0) {
        return 0x1000;
    }
    return func_800B351C(&(*arg0)[(*arg0)->objInfo->obj_count]);
}

s32 func_800B351C(UnkStruct_800B23C4* arg0) {
    UNUSED s32 pad;
    if (arg0->unk3A & 0x2000) {
        return 0;
    }
    arg0->unk3A = (u16) (arg0->unk3A | 0x2000);
    return func_800B3590(arg0);
}

s32 func_800B3590(UnkStruct_800B23C4* arg0) {
    ObjFrame* sp4;

    sp4 = &arg0->objFrame[(u8) arg0->unk30];
    return (s32) sp4->u5;
}

// Believe it or not this is a matrix manipulation function
#ifdef NEEDS_RODATA
extern u8* D_80180D4C;

u8 func_800B35D4(f32* arg0, UnkStruct_80099E2C* arg1, UnkStruct_800B23C4* arg2, s32 arg3) {
    u8 sp3C[4];
    s32 sp38;
    ObjFrame* sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s16* sp24;

    if ((arg3 < 0) || (arg3 >= 4)) {
        return 0U;
    }
    sp34 = &arg2->objFrame[(u8) arg2->unk30];
    if (sp34->unk2 == 0xFFFF) {
        return 0U;
    }
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual(gSpriteObjHeaderSegment, gSpriteSeg1VramStart,
                                                        &D_80180D4C[sp34->unk2 * 8]),
                   &sp38, 8);
    if (sp3C[arg3] == 0) {
        return 0U;
    }
    sp2C = 0;

    for (sp30 = 0; sp30 < arg3; sp30++) {
        sp2C += sp3C[sp30] * 8;
    }
    sp28 = sp3C[arg3] * 8;
    sp24 = SysMem_HeapAlloc(sp28);
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment, (s32) gSpriteSeg1VramStart,
                                                        D_80180D50 + sp38 + sp2C),
                   sp24, sp28);

    for (sp30 = 0; sp30 < sp3C[arg3]; sp30++) {
        if (((sp34->u5 & 1) ^ (arg2->unk0 & 1)) == 0) {
            arg0[sp30] = sp24[sp30 * 4] + arg1->unkCC;

            arg0[sp30 + 2] = sp24[sp30 * 4 + 2] + arg1->unkCC;
        } else {
            arg0[sp30] = arg1->unkCC - sp24[sp30 * 4 + 2];
            arg0[sp30 + 2] = arg1->unkCC - sp24[sp30 * 4];
        }
        if (((sp34->u5 & 2) ^ (arg2->unk0 & 2)) == 0) {
            arg0[sp30 + 1] = sp24[sp30 * 4 + 1] + arg1->unkD0;
            arg0[sp30 + 2] = sp24[sp30 * 4 + 3] + arg1->unkD0;
        } else {
            arg0[sp30] = arg1->unkD0 - sp24[sp30 * 4];
            arg0[sp30 + 3] = arg1->unkD0 - sp24[sp30 * 4 + 1];
        }
    }
    SysMem_Free(sp24);
    return sp3C[arg3];
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B35D4.s")
#endif

s32 func_800B3A24(f32* arg0, UnkStruct_80099E2C** arg1, UnkStruct_800B23C4** arg2);

#ifdef NON_MATCHING
extern f32 D_800EF978;

s32 func_800B3A24(f32* arg0, UnkStruct_80099E2C** arg1, UnkStruct_800B23C4** arg2) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    s32 pad18;
    s32 pad14;
    UnkStruct_80099E2C* sp10;
    UnkStruct_80099E2C* spC;
    s32 sp8;
    s32 sp4;

    sp2C = sp28 = 32767.0f;
    sp24 = sp20 = -32768.0f;
    sp10 = *arg1;
    sp4 = (s32) (*arg2)->objInfo->obj_count;
    if ((*arg2)->unk0 & 4) {
        sp4 += (*arg2)->objInfo->extra_obj_count;
    }
    for (sp8 = 0, spC = sp10; sp8 < sp4; sp8++, spC++) {
        if (!(spC->unkC0 & 1)) {
            if ((sp1C = spC->unkCC + (spC->unk104 * spC->unkF4)) < sp2C) {
                sp2C = sp1C;
            }
            if (sp24 < (sp1C = spC->unkCC + ((spC->unk104 + spC->unk100) * spC->unkF4))) {
                sp24 = sp1C;
            }
        } else {
            if (sp24 < (sp1C = (spC->unk104 * spC->unkF4) - spC->unkCC)) {
                sp24 = sp1C;
            }
            if ((sp1C = ((spC->unk104 + spC->unk100) * spC->unkF4) - spC->unkCC) < sp2C) {
                sp2C = sp1C;
            }
        }
        if (!(spC->unkC0 & 2)) {
            if ((sp1C = spC->unkD0 + ((spC->unk108 - spC->unk102) * spC->unkF8)) < sp28) {
                sp28 = sp1C;
            }
            if (sp20 < (sp1C = spC->unkD0 + (spC->unk108 * spC->unkF8))) {
                sp20 = sp1C;
            }
        } else {
            if (sp20 < (sp1C = ((spC->unk108 - spC->unk102) * spC->unkF8) - spC->unkD0)) {
                sp20 = sp1C;
            }
            if ((sp1C = (spC->unk108 * spC->unkF8) - spC->unkD0) < sp28) {
                sp28 = sp1C;
            }
        }
    }
    arg0[0] = sp2C;
    arg0[1] = sp28;
    arg0[2] = sp24;
    arg0[3] = sp20;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B3A24.s")
#endif

void func_800B3DBC(UnkStruct_80099E2C** arg0, UnkStruct_800B23C4** arg1, u16 paletteIndex) {
    s32 objCount;
    s32 i;
    UnkStruct_80099E2C* sp1C;
    UnkStruct_800B23C4* sp18;

    objCount = (*arg1)->objInfo->obj_count;
    if ((*arg1)->unk0 & 4) {
        objCount += (*arg1)->objInfo->extra_obj_count;
    }

    for (i = 0, sp1C = *arg0, sp18 = *arg1; i < objCount; i++, sp1C++, sp18++) {
        LoadPalette(sp1C, sp18, paletteIndex);
    }
}

s32 func_800B3EC0(ObjInfo* arg0, s32 arg1) {
    u32 sp34;
    u32* sp30;
    u32* sp2C;
    s32 sp28;
    s32 sp24;

    if (D_80180D60 == arg1) {
        SysMem_Copy8(arg0, &D_80180D60, 0x10);
        return 0;
    }
    sp34 = D_80180D34 - D_80180D30;
    sp28 = sp34 >> 4;
    sp30 = SysMem_HeapAlloc((s32) sp34);
    SysMem_DmaCopy(
        SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment, (s32) gSpriteSeg1VramStart, D_80180D30),
        sp30, (s32) sp34);

    for (sp24 = 0, sp2C = sp30; (arg1 > *sp2C) && (sp24 < sp28); sp2C += 4, sp24++) {}

    if (*sp2C == arg1) {
        SysMem_Copy8(arg0, sp2C, 0x10);
        SysMem_Copy8(&D_80180D60, sp2C, 0x10);
    }
    SysMem_Free(sp30);
    if ((u32) arg1 < (u32) *sp2C) {
        return -1;
    }
    return 0;
}

#ifdef NEEDS_RODATA
void func_800B4448(UnkStruct_80099E2C*, UnkStruct_800B23C4*, s32); /* extern */
void func_800B47A0(UnkStruct_80099E2C*, UnkStruct_800B23C4*, u16); /* extern */

s32 func_800B407C(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 arg2) {
    ObjFrame* sp1C;
    u8 sp1B;

    sp1B = arg1->unk30;
    for (; arg1->unk30 < arg1->objDef->pad2;) {
        sp1C = &arg1->objFrame[arg1->unk30];
        if (!(sp1C->spi_idx & 0x8000)) {
            if ((arg1->unk34 + (f32) sp1C->delay) > 0.0) {
                break;
            }
            arg1->unk34 += (f32) sp1C->delay;
        }
        switch (sp1C->spi_idx & 0x7FFF) {
            case 0:
                arg1->unk30 = sp1C->kind;
                break;
            case 1:
                if (arg1->unk38 > 0) {
                    arg1->unk38--;
                    if (arg1->unk38 > 0) {
                        arg1->unk30 = sp1C->kind;
                    } else {
                        sp1B = arg1->unk30 - 1;
                        goto increment;
                    }
                    break;
                }

                arg1->unk30 = sp1C->kind;
                arg1->unk38 = sp1C->id;
                break;
            case 2:
                arg1->unk3A |= 0x10;
                arg1->unk30 = sp1C->kind;
                break;
            case 3:
                arg1->unk3A |= 0x20;
                arg1->unk30 = sp1C->kind;
                break;
            case 4:
                if (arg1->unk3A & 0x100) {
                    func_800B4448(arg0, arg1, 4);
                    arg1->unk3A &= ~0x100;
                    arg1->unk3A &= ~0x40;
                    goto increment;
                }
                arg1->unk3A |= 0x40;
                arg1->unk30 = sp1C->kind;
                break;
            default:
            increment:
                arg1->unk30++;
        }
    }
    if (arg1->unk30 >= arg1->objDef->pad2) {
        arg1->unk30 = sp1B;
        return -1;
    }
    func_800B47A0(arg0, arg1, arg2);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B407C.s")
#endif

s32 func_800B4448(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u8 arg2) {
    ObjFrame* sp1C;

    if (arg1->unk30 >= (s32) arg1->objDef->pad2) {
        return -1;
    }
    for (; arg1->unk30 < arg1->objDef->pad2; arg1->unk30++) {
        sp1C = &arg1->objFrame[(u8) arg1->unk30];
        if (!(sp1C->spi_idx & 0x8000)) {
            continue;
        }
        if ((sp1C->spi_idx & 0x7FFF) == arg2) {
            break;
        }
    }
    arg1->unk30++;
    if (arg1->unk30 >= arg1->objDef->pad2) {
        for (arg1->unk30 = arg1->objDef->pad2 - 1; arg1->unk30 > 0;) {
            sp1C = &arg1->objFrame[(u8) arg1->unk30];
            if (sp1C->spi_idx & 0x8000) {
                arg1->unk30--;
            } else {
                break;
            }
        }

        return -1;
    }
    func_800B47A0(arg0, arg1, arg1->currentPaletteIndex);
    return 0;
}

s32 func_800B4680(UnkStruct_800B23C4* arg0, u8 arg1) {
    ObjFrame* sp4;
    s32 sp0;

    if ((s32) arg0->unk30 >= (s32) arg0->objDef->pad2) {
        return -1;
    }

    for (sp0 = (s32) arg0->unk30; sp0 < arg0->objDef->pad2; sp0++) {
        sp4 = &arg0->objFrame[sp0];
        if (!(sp4->spi_idx & 0x8000)) {
            continue;
        }
        if ((sp4->spi_idx & 0x7FFF) == arg1) {
            break;
        }
    }
    if (sp0 < (s32) arg0->objDef->pad2) {
        return 1;
    }
    return 0;
}

void func_800B47A0(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 arg2) {
    ObjFrame* sp1C;

    sp1C = &arg1->objFrame[arg1->unk30];
    if (sp1C->u5 & 0x40) {
        arg1->unk3A |= 1;
    }
    if (sp1C->u5 & 0x80) {
        arg1->unk3A |= 2;
    }
    if (sp1C->u5 & 0x100) {
        arg1->unk3A |= 4;
    }
    if ((sp1C->u5 & 0x200) && !(arg1->unk0 & 0x10)) {
        arg1->unk3A |= 8;
    }
    if ((sp1C->u5 & 0x800) && (arg1->unk0 & 4)) {
        arg1->unk3A |= 0x80;
    }
    if (!(sp1C->u5 & 4)) {
        if (!(arg1->unk0 & 1)) {
            arg0->unkCC += (f32) (s8) sp1C->u6 * arg0->unkF4;
        } else {
            arg0->unkCC -= (f32) (s8) sp1C->u6 * arg0->unkF4;
        }
    }
    if (!(sp1C->u5 & 8)) {
        if (!(arg1->unk0 & 2)) {
            arg0->unkD0 += (f32) (s8) sp1C->u7 * arg0->unkF8;
        } else {
            arg0->unkD0 -= (f32) (s8) sp1C->u7 * arg0->unkF8;
        }
    }
    arg1->unk34 += (f32) sp1C->delay;
    func_800B4AB4(arg0, arg1);
    func_800B4F68(arg0, arg1, arg2);
    arg1->unk3A &= ~0x2000;
}

void func_800B4AB4(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    ObjFrame* sp4;
    f32 sp0;

    sp4 = &arg1->objFrame[arg1->unk30];
    if (arg1->unk0 & 8) {
        sp0 = 0.5f;
    } else {
        sp0 = (f32) ((f64) D_8018257C / 2.0);
    }
    if (sp4->u5 & 0x10) {
        arg1->unk20 += arg1->unk28 * sp0;
    }
    if ((f64) arg1->unk20 > 50.0) {
        arg1->unk20 = 50.0f;
    }
    if ((f64) arg1->unk20 < -50.0) {
        arg1->unk20 = -50.0f;
    }
    if (sp4->u5 & 0x20) {
        arg1->unk24 += arg1->unk2C * sp0;
    }
    if ((f64) arg1->unk24 > 50.0) {
        arg1->unk24 = 50.0f;
    }
    if ((f64) arg1->unk24 < -50.0) {
        arg1->unk24 = -50.0f;
    }
    if (sp4->u5 & 4) {
        arg0->unkCC += arg1->unk20 * sp0 * arg0->unkF4;
    }
    if (sp4->u5 & 8) {
        arg0->unkD0 += arg1->unk24 * sp0 * arg0->unkF8;
    }
    if (sp4->u5 & 0x10) {
        if (((!(arg1->unk0 & 1) && ((s16) arg1->objDef->u1 > 0)) ||
             ((arg1->unk0 & 1) && ((s16) arg1->objDef->u1 < 0))) &&
            ((f64) arg1->unk20 <= 0.0)) {
            arg1->unk3A &= ~1;
            arg1->unk28 = 0.0f;
            arg1->unk20 = 0.0f;
        }
        if (((!(arg1->unk0 & 1) && ((s16) arg1->objDef->u1 < 0)) ||
             ((arg1->unk0 & 1) && ((s16) arg1->objDef->u1 > 0))) &&
            ((f64) arg1->unk20 >= 0.0)) {
            arg1->unk3A &= ~1;
            arg1->unk28 = 0.0f;
            arg1->unk20 = 0.0f;
        }
    }
    if (sp4->u5 & 0x20) {
        if (((!(arg1->unk0 & 2) && ((s16) arg1->objDef->u2 > 0)) ||
             ((arg1->unk0 & 2) && ((s16) arg1->objDef->u2 < 0))) &&
            ((f64) arg1->unk24 <= 0.0)) {
            arg1->unk3A &= ~2;
        }
        if (((!(arg1->unk0 & 2) && ((s16) arg1->objDef->u2 < 0)) ||
             ((arg1->unk0 & 2) && ((s16) arg1->objDef->u2 > 0))) &&
            ((f64) arg1->unk24 >= 0.0)) {
            arg1->unk3A &= ~2;
        }
    }
}

// Stack differences
#ifdef NON_MATCHING
void func_800B4F68(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 arg2) {
    ObjFrame* sp3C;
    u8 sp38;
    u8 sp39;
    s32 spiOffset;
    s32 size;
    u8** decompressedData;
    s32 spriteSpiOffset;
    s32 sp24;

    func_800B5558(arg0, arg1);
    sp3C = &arg1->objFrame[arg1->unk30];
    sp24 = SysMem_GetPhysicalAddressFromVirtual(gSpriteObjHeaderSegment, gSpriteSeg1VramStart,
                                                (sp3C->spi_idx * 8) + sMainSpritesSpiOffsets);

    while (TRUE) {
        SysMem_DmaCopy(sp24, &spiOffset, 8);

        // The SPI offset must be odd
        if ((spiOffset & 1) == 0) {
            break;
        }
    }
    arg0->unk114 = 0;
    arg0->unk100 = (s16) sp38;
    arg0->unk102 = (s16) sp39;
    if (((sp3C->u5 & 1) ^ (arg1->unk0 & 1)) != 0) {
        arg0->unkC0 |= 1;
    } else {
        arg0->unkC0 &= ~1;
    }
    if (((sp3C->u5 & 2) ^ (arg1->unk0 & 2)) != 0) {
        arg0->unkC0 |= 2;
    } else {
        arg0->unkC0 &= ~2;
    }
    if (sp3C->u5 & 0x400) {
        arg0->unkC0 |= 0x80;
    } else {
        arg0->unkC0 &= ~0x80;
    }
    arg0->unk116 = 1;
    if (D_80180D54 & 1) {
        arg0->unkC0 |= 0x100;
    } else {
        arg0->unkC0 &= ~0x100;
    }
    if (sp3C->spi_idx != arg1->unk10) {
        decompressedData = &arg0->ptrs[arg1->unk3C + 1];
        if (*decompressedData != NULL) {
            SysMem_Free(*decompressedData);
        }
        if (D_80180D54 & 2) {
            spriteSpiOffset = SysMem_GetPhysicalAddressFromVirtual(gSpriteObjHeaderSegment, gSpriteSeg1VramStart,
                                                                   sMainSpritesStart + spiOffset);
            size = Sys_GetSPIHeaderInfoFromVaddr(spriteSpiOffset); // Compressed size
            *decompressedData = SysMem_HeapAlloc(D_80160494);
            Spi_DecompressAsset(spriteSpiOffset, size, *decompressedData);
            arg0->ptrs[0] = *decompressedData;
            arg1->unk3C++, arg1->unk3C %= 3;
        } else {
            *decompressedData = SysMem_HeapAlloc(sp38 * sp39);
            SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual((u32) gSpriteObjHeaderSegment,
                                                                (s32) gSpriteSeg1VramStart,
                                                                sMainSpritesStart + spiOffset),
                           *decompressedData, sp38 * sp39);
            arg0->ptrs[0] = *decompressedData;
        }
        arg1->unk10 = sp3C->spi_idx;
    }
    LoadPalette(arg0, arg1, arg2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B4F68.s")
#endif

void LoadPalette(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1, u16 paletteIndex) {
    if (arg1->currentPaletteIndex != paletteIndex) {
        if (!(paletteIndex & 0x8000)) {
            if (arg1->spritePalette[arg1->paletteIndex] != NULL) {
                SysMem_Free(arg1->spritePalette[arg1->paletteIndex]);
            }
            arg1->spritePalette[arg1->paletteIndex] = SysMem_HeapAlloc(sizeof(SpritePalette));

            // Copy the specific palette into spritePalette
            SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual(gSpriteObjHeaderSegment, gSpriteSeg1VramStart,
                                                                &sMainSpritesPalettes[paletteIndex]),
                           arg1->spritePalette[arg1->paletteIndex], sizeof(SpritePalette));

            arg0->currentPaletteColors = arg1->spritePalette[arg1->paletteIndex]->colors;
            arg1->paletteIndex++, arg1->paletteIndex %= 3;
        } else {
            arg0->currentPaletteColors = &D_801A8C18->currentPaletteColors[(paletteIndex & 0xFFFF7FFF) << 8];
        }
        arg1->currentPaletteIndex = paletteIndex;
    }
}

void func_800B5558(UnkStruct_80099E2C* arg0, UnkStruct_800B23C4* arg1) {
    ObjFrame* sp4;

    sp4 = &arg1->objFrame[arg1->unk30];
    arg0->unk104 = (s32) sp4->x;
    arg0->unk108 = (s32) sp4->y;
}

s32 func_800B55B0(s32 arg0) {
    u16 sp28[8];

    if (D_801A3068 == NULL) {
        D_801A3068 = TempHeap_Alloc(0x10);
    }
    sp28[0] = 0xC002;
    sp28[1] = 0xFFFF;
    sp28[2] = sp28[3] = sp28[4] = sp28[5] = 0;
    if (func_800B6A00(sp28) < 6) {
        return -1;
    }
    D_801A3068->unk0 = arg0;
    D_801A3068->unk4 = func_800B8398();
    D_801A3068->unk6 = 0;
    D_801A3068->unk8 = 0;
    D_801A3068->unkA = 0;
    D_801A3068->unkC = 0.0f;
    if (func_800B5730() != 0) {
        return -1;
    }
    return 0;
}

s32 func_800B56F0(void) {
    s32 pad;
    if (func_800B5730() != 0) {
        return -1;
    }
    return 0;
}

s32 func_800B5730(void) {
    if (D_801A3068->unk4 & 2) {
        func_80031728();
        return -1;
    }
    func_800B57B0();
    func_800B5AA0();
    if (func_800B5AF0() != 0) {
        func_800B5FB4();
    }
    return 0;
}

void func_800B57B0(void) {
    UnkStruct_8000DDE0* sp24;
    s32 sp20;
    s32 pad[2];

    if (D_801A3068->unk4 & 0x10) {
        sp20 = 1;
        sp24 = func_80016074(0xF);
        if ((sp24 != NULL)) {
            if (!(sp24->unk1A8 & 2)) {
                sp20 = 0;
            }
        }
        if (sp20 != 0) {
            D_801A3068->unk4 &= ~0x10;
            D_801A8C34 = -1;
            D_801A8D88[1] = (u16) (D_801A8D88[1] | 8);
        }
    }
    if (D_801A3068->unk4 & 0x20) {
        sp20 = 1;
        sp24 = func_80016074(0xE);
        if ((sp24 != NULL)) {
            if (!(sp24->unk1A8 & 2)) {
                sp20 = 0;
            }
        }
        if (sp20 != 0) {
            D_801A3068->unk4 &= ~0x20;
            D_801A8C34 = -1;
            D_801A8D88[1] = (u16) (D_801A8D88[1] | 8);
        }
    }
    if (D_801A3068->unk4 & 0x40) {
        sp20 = 1;
        sp24 = func_80016074(0xB);
        if ((sp24 != NULL)) {
            if (!(sp24->unk1A8 & 2)) {
                sp20 = 0;
            }
        }
        if (sp20 != 0) {
            D_801A3068->unk4 &= ~0x40;
            D_801A8C34 = -1;
            D_801A8D88[1] = (u16) (D_801A8D88[1] | 8);
        }
    }
    if (D_801A3068->unk4 & 0x80) {
        sp20 = 1;
        sp24 = func_80016074(0xC);
        if ((sp24 != NULL)) {
            if (!(sp24->unk1A8 & 2)) {
                sp20 = 0;
            }
        }
        if (sp20 != 0) {
            D_801A3068->unk4 &= ~0x80;
            D_801A8C34 = -1;
            D_801A8D88[1] = (u16) (D_801A8D88[1] | 8);
        }
    }
}

void func_800B5AA0(void) {
    if (D_801A3068->unk4 & 0x200) {
        D_801560F0->unk6 &= ~D_801810F2;
    }
}

s32 func_80031AC8(void); /* extern */
s32 func_800B5E90(u16);  /* extern */
s32 func_800B8104(void); /* extern */
extern f32 D_80182530;

s32 func_800B5AF0(void) {

    if (func_800B8104() != 0) {
        return 0;
    }
    switch (D_801A3068->unk6) { /* irregular */
        case 0xE000:
            if (D_801A3068->unk4 & 0x400) {
                if (func_80031AC8() == 1) {
                    D_80182530 = 0.0f;
                    D_801560F0->unk6 &= ~D_801810F2;
                }
                break;
            }
            if (D_801A3068->unkC >= D_801A3068->unk8) {
                D_801A3068->unk6 = 0;
                D_801A3068->unk4 &= ~0x100;
            } else {
                D_801A3068->unkC = (f32) ((f64) D_801A3068->unkC + ((f64) D_8018257C * 0.5));
            }
            break;
        case 0xE011:
            if (D_801A3068->unk4 & 0x400) {
                if (func_80031AC8() == 1) {
                    D_80182530 = 0.0f;
                    D_801560F0->unk6 &= ~D_801810F2;
                }
                break;
            }
            if (D_801560F0->unk6 & D_801810F2) {
                D_801A3068->unk6 = 0;
                D_801A3068->unk4 &= ~0x100;
                break;
            }
            if (D_801A3068->unkC >= D_801A3068->unk8) {
                D_801A3068->unk6 = 0;
                D_801A3068->unk4 &= ~0x100;
            } else {
                D_801A3068->unkC = (f32) ((f64) D_801A3068->unkC + ((f64) D_8018257C * 0.5));
            }
            break;
        case 0xE006:
            if (func_800B5E90((u16) D_801A3068->unk8) != 0) {
                D_801A3068->unk6 = 0;
                D_801A3068->unk4 &= ~0x100;
            }
            break;
        default:
            D_801A3068->unk6 = 0;
    }
    if (D_801A3068->unk6 == 0) {
        return 1;
    }
    return 0;
}

s32 func_800B5E90(u16 arg0) {
    s32 sp4;

    sp4 = 0;
    switch (arg0) { /* irregular */
        case 0xE100:
            if (!(D_801A3068->unk4 & 0x10)) {
                sp4 = 1;
            }
            break;
        case 0xE101:
            if (!(D_801A3068->unk4 & 0x20)) {
                sp4 = 1;
            }
            break;
        case 0xE102:
            if (!(D_801A3068->unk4 & 0x40)) {
                sp4 = 1;
            }
            break;
        case 0xE103:
            if (!(D_801A3068->unk4 & 0x80)) {
                sp4 = 1;
            }
            break;
    }
    return sp4;
}

// Stack issues
#ifdef NON_MATCHING
s32 func_800B69C4(u16*);           /* extern */
s32 func_800B6B18(u16*);           /* extern */
s32 func_800B7510(u16*);           /* extern */
s32 func_800B75EC(u16*);           /* extern */
s32 func_800B7678(u16*);           /* extern */
s32 func_800B7788(u16*);           /* extern */
s32 func_800B77D8(u16*);           /* extern */
s32 func_800B79FC(u16*);           /* extern */
s32 func_800B7B94(u16*);           /* extern */
s32 func_800B7C4C(u16*);           /* extern */
s32 func_800B7D20(u16*);           /* extern */
s32 func_800B7DCC(u16*);           /* extern */
s32 func_800B7EA4(u16*);           /* extern */
s32 func_800B7F2C(u16*);           /* extern */
s32 func_800B7FCC(u16*);           /* extern */
s32 func_800B8038(u16*);           /* extern */
s32 func_800B80A4(u16*, s32, u16); /* extern */

s32 func_800B5FB4(void) {
    u16 sp30;
    u16* sp2C;
    u16 sp2A;
    s32 sp24 = 0;

    do {
        SysMem_DmaCopy((u32)D_801A3068->unk0, &sp30, 0x10);
        sp2C = &sp30;
        sp2A = sp2C[0];

        switch (sp2A) {
            case 0xF050:
                D_801A3068->unk0 += func_800B69C4(sp2C) * 2;
                break;
            case 0xF051:
                if (!(D_801A3068->unk4 & 1)) {
                    D_801A3068->unk4 |= 1;
                } else {
                    D_801A3068->unk4 |= 2;
                }
                break;
            case 0xF052:
                D_801A3068->unk0 += func_800B6A00(sp2C) * 2;
                break;
            case 0xF053:
                D_801A3068->unk0 += func_800B80A4(sp2C, 5, sp2C[1]) * 2;
                break;
            case 0xF054:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, sp2C[1]) * 2;
                break;
            case 0xF055:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, sp2C[1]) * 2;
                break;
            case 0xF056:
                D_801A3068->unk0 += func_800B6B18(sp2C) * 2;
                break;
            case 0xF057:
                D_801A3068->unk0 += func_800B7510(sp2C) * 2;
                break;
            case 0xF058:
                D_801A3068->unk0 += func_800B7678(sp2C) * 2;
                break;
            case 0xF059:
                D_801A3068->unk0 += func_800B7788(sp2C) * 2;
                break;
            case 0xF05A:
                D_801A3068->unk0 += func_800B77D8(sp2C) * 2;
                break;
            case 0xF05B:
                D_801A3068->unk0 += 2;
                sp24 = 1;
                break;
            case 0xF05C:
                D_801A3068->unk0 += 2;
                sp24 = 0;
                break;
            case 0xF062:
                D_801A3068->unk0 += func_800B7B94(sp2C) * 2;
                break;
            case 0xF065:
                D_801A3068->unk0 += func_800B80A4(sp2C, 4, sp2C[1]) * 2;
                break;
            case 0xF066:
                D_801A3068->unk0 += func_800B80A4(sp2C, 3, sp2C[1]) * 2;
                break;
            case 0xF060:
                D_801A3068->unk0 += func_800B80A4(sp2C, 3, sp2C[1]) * 2;
                break;
            case 0xF067:
                D_801A3068->unk0 += func_800B7D20(sp2C) * 2;
                break;
            case 0xF068:
                D_801A3068->unk0 += func_800B7C4C(sp2C) * 2;
                break;
            case 0xF069:
                D_801A3068->unk0 += func_800B80A4(sp2C, 4, sp2C[1]) * 2;
                break;
            case 0xF06A:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, sp2C[1]) * 2;
                break;
            case 0xF06B:
                D_801A3068->unk0 += func_800B80A4(sp2C, 3, sp2C[1]) * 2;
                break;
            case 0xF06C:
                D_801A3068->unk0 += func_800B80A4(sp2C, 4, sp2C[1]) * 2;
                break;
            case 0xF06D:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, sp2C[1]) * 2;
                break;
            case 0xF06E:
                D_801A3068->unk0 += func_800B80A4(sp2C, 5, sp2C[1]) * 2;
                break;
            case 0xF06F:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, sp2C[1]) * 2;
                break;
            case 0xF070:
                D_801A3068->unk0 += func_800B80A4(sp2C, 3, 0xFFFF) * 2;
                break;
            case 0xF071:
                D_801A3068->unk0 += func_800B80A4(sp2C, 0, 0xFFFF) * 2;
                break;
            case 0xF072:
                D_801A3068->unk0 += func_800B80A4(sp2C, 6, sp2C[1]) * 2;
                break;
            case 0xF073:
                D_801A3068->unk0 += func_800B7DCC(sp2C) * 2;
                break;
            case 0xF074:
                D_801A3068->unk0 += func_800B7EA4(sp2C) * 2;
                break;
            case 0xF075:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, sp2C[1]) * 2;
                break;
            case 0xF076:
                D_801A3068->unk0 += func_800B80A4(sp2C, 4, sp2C[1]) * 2;
                break;
            case 0xF077:
                D_801A3068->unk0 += func_800B79FC(sp2C) * 2;
                break;
            case 0xF078:
                D_801A3068->unk0 += func_800B80A4(sp2C, 6, 0x4001) * 2;
                break;
            case 0xF079:
                D_801A3068->unk0 += func_800B80A4(sp2C, 4, sp2C[1]) * 2;
                break;
            case 0xF07A:
                D_801A3068->unk0 += func_800B7F2C(sp2C) * 2;
                break;
            case 0xF07B:
                D_801A3068->unk0 += func_800B7FCC(sp2C) * 2;
                break;
            case 0xF07C:
                D_801A3068->unk0 += func_800B80A4(sp2C, 2, 0x4001) * 2;
                break;
            case 0xF07D:
                D_801A3068->unk0 += func_800B80A4(sp2C, 3, sp2C[1]) * 2;
                break;
            case 0xF07E:
                D_801A3068->unk0 += func_800B8038(sp2C) * 2;
                break;
            case 0xF07F:
                D_801A3068->unk0 += func_800B75EC(sp2C) * 2;
                break;
            case 0xF080:
                D_801A3068->unk0 += func_800B80A4(sp2C, 7, sp2C[1]) * 2;
                break;
            case 0xF081:
                D_801A3068->unk0 += func_800B80A4(sp2C, 3, sp2C[1]) * 2;
                break;
                D_801A3068->unk0  += 2;
                break;
        }

        if (D_801A3068->unk4 & 2) {
            return -1;
        }

    } while (sp24 != 0);

    return 0;
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_B2650/func_800B5FB4.s")
#endif

s32 func_800B69C4(u16* arg0) {
    s32 pad[3];

    arg0++;
    D_801A8C10 = *arg0++;
    D_801A8C1C = *arg0;
    return 3;
}

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
