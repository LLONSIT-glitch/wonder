#include "common.h"

typedef struct UnkStruct_8015FB90_s {
    s32 unk0;
    s32 unk4;
} UnkStruct_8015FB90;

typedef struct UnkStruct_800AFAB0_s {
    char pad[0x6];
    u16 unk6;
    char pad8[0x4];
    s8 unkC[1];
} UnkStruct_800AFAB0;

typedef struct UnkStruct_800B0D30_s {
    void* unk0;
    void* unk4;
} UnkStruct_800B0D30;

typedef struct UnkStruct_800B0A3C_s {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
} UnkStruct_800B0A3C;


typedef struct UnkStruct_800E8CD0_s {
    s16 unk0;
    s32 unk0_1;
} UnkStruct_800E8CD0;

extern UnkStruct_800E8CD0 D_800E8CD0[]; // An array with matrix info?
extern f64 D_800EF930;
extern u8* D_8015FBA8;
extern u8 D_80A225B0[];

extern u16 D_8015F888;
extern f32 D_80160430;
extern f32 D_80160438;
extern f32 D_80160440;

extern Mtx* D_8015F87C;
extern s16 D_8015FB70;
extern UnkStruct_8015FB90 D_8015FB90[2];
extern UnkStruct_8015FB90 D_8015FBB0[2];
extern UnkStruct_8015FB90* D_8015FBA4;
extern UnkStruct_8015FB90* D_8015FBC0;
extern s8 D_80160448;
extern void** D_801601D4;
extern u16 D_801601D8;
extern u8 D_801604A8;
extern s32* D_801601C8;
extern u16 D_801601D0;
extern u8* D_8015FB88;
extern s32 D_801705B0;
extern u8 gAssetsTable[];
extern f64 D_800EF938;
extern u16 D_8015F890[];
extern Mtx D_8015FAA8[];
extern MtxF D_801601E0;
extern f32 D_80160220;
extern f32 D_80160428;

f32 func_800C3650(f32);           /* extern */
s32 func_800AFB70(u16, s32, s32); /* extern */
void func_800AF330(Gfx** gdl, void* arg1, f32 arg2, f32 arg3, f32 arg4);
void func_800B18C4(Gfx **gdl, Gfx* arg1, s16 arg2);


#ifdef __GNUC__
// Because of some ugly assignments we will have to use this to avoid gcc always complaining about them..
#pragma GCC diagnostic ignored "-Wsequence-point"
#endif

s32 func_800AF060(s16 arg0) {
    u16 sp2E;

    D_8015FB70 = (s16) arg0;
    D_8015F87C = SysMem_HeapAlloc((arg0 + arg0) * 0x40);
    if (D_8015F87C == NULL) {
        return -1;
    }
    D_80160448 = 0;
    for (sp2E = 0; sp2E < 2; sp2E++) {
        D_8015FB90[sp2E].unk0 = D_8015FB90[sp2E].unk4 = D_8015FBB0[sp2E].unk0 = D_8015FBB0[sp2E].unk4 = 0;
    }
    D_8015FBA4 = D_8015FB90;
    D_8015FBC0 = D_8015FBB0;
    return 0;
}

// NEEDS RODATA
extern f64 D_800EF920;

void func_800AF184(f32 arg0, f32 arg1, f32 arg2) {
    D_80160430 = arg0;
    D_80160438 = arg1;
    D_80160440 = func_800C3650((f32) ((f64) arg2 * D_800EF920));
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AF330.s")

void func_800AF72C(s32* fileAddr) {
    s32 sp2C;
    s32 sp28;
    void** sp24;
    s32* sp20;
    s32 sp1C;
    u8* sp18;

    sp1C = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, fileAddr);
    sp20 = (s32*) &D_801604A8;
    SysMem_DmaCopy((u32) sp1C, sp20, 4);
    sp2C = *sp20;
    sp1C = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, fileAddr + 1);
    sp20 = SysMem_HeapAlloc(sp2C * 4);
    fileAddr = (s32*) (sp18 = (u8*) sp20);
    SysMem_DmaCopy((u32) sp1C, sp20, sp2C * 4);
    D_801601D8 = sp2C - 1;
    D_801601D4 = SysMem_HeapAlloc(D_801601D8 * 4);
    sp24 = D_801601D4;
    for (sp2C = 0; sp2C < D_801601D8; sp2C++) {
        sp1C = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, *fileAddr);
        sp28 = Sys_GetSPIHeaderInfoFromVaddr(sp1C);
        sp20 = (s32*) &D_801604A8;
        Spi_DecompressAsset((u32) sp1C, sp28, (u8*) sp20);
        *sp24 = SysMem_HeapAlloc((sp28 = D_80160494));
        SysMem_DmaCopy((u32) sp20, *sp24, sp28);
        sp24++;
        fileAddr++;
    }
    SysMem_Free(sp18);
}

void func_800AF92C(u16* arg0) {
    s32 sp24;
    s32* sp20;
    u16* sp1C;
    s32 sp18;

    sp18 = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, arg0);
    sp1C = (u16*) &D_801604A8;
    SysMem_DmaCopy((u32) sp18, sp1C, 2);
    D_801601D0 = *sp1C;
    sp18 = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, arg0 + 1);
    sp1C = SysMem_HeapAlloc(D_801601D0 * 4);
    arg0 = (s32) sp1C;
    SysMem_DmaCopy((u32) sp18, sp1C, D_801601D0 * 2);
    D_801601C8 = SysMem_HeapAlloc(D_801601D0 * 4);
    sp20 = D_801601C8;
    for (sp24 = 0; sp24 < D_801601D0; sp24++) {
        *sp20 = func_800AFB70(*arg0, 1, 0);
        sp20++;
        arg0++;
    }
    SysMem_Free(sp1C);
}

void func_800AFAB0(Vtx_tn* arg0, u16 arg1, s8 arg2) {
    u8 pad5;
    s8 sp6;
    sp6 = arg0->n[arg1];
    if (arg0->flag != 0) {
        sp6 = arg2;
        arg0->flag = 0U;
    } else {
        sp6 = (s8) ((s32) (sp6 + arg2) / 2);
    }
    arg0->n[arg1] = sp6;
}

void func_800AFB28(void) {
    D_8015F888 = 0;
    D_8015F884 = &D_8015F87C[D_801824FC * D_8015FB70];
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800AFB70.s")

u8* func_800B08FC(s16 arg0, s16 arg1) {
    s32 sp34;
    u8* sp30;
    s32* sp2C;
    s32 sp28;
    s32 temp_v0;

    D_8015FB88 = gAssetsTable;
    sp2C = &D_801705B0;
    sp28 = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM,
                                                (s32) ((arg0 * 4) + D_8015FB88));
    SysMem_DmaCopy((u32) sp28, sp2C, 4);
    sp28 = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, *sp2C);
    sp34 = Sys_GetSPIHeaderInfoFromVaddr(sp28);
    sp30 = SysMem_HeapAlloc(D_80160494);
    Spi_DecompressAsset((u32) sp28, sp34, sp30);
    if (arg1 != 0) {
        D_8015FBA4 = D_8015FBA4->unk4 = SysMem_HeapAlloc(8);
        D_8015FBA4->unk0 = (s32) sp30;
        D_8015FBA4->unk4 = 0;
    }
    return sp30;
}

void* func_800B0A3C(s16 arg0, s16 arg1) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    UnkStruct_800B0A3C* sp40;
    UnkStruct_800B0A3C* sp3C;
    s16* sp38;
    s32* sp34;
    s32 sp30;

    D_8015FBA8 = D_80A225B0;
    sp34 = &D_801705B0;
    sp30 = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, (s32) ((arg0 * 4) + D_8015FBA8));
    SysMem_DmaCopy((u32) sp30, sp34, 4);
    sp30 = SysMem_GetPhysicalAddressFromVirtual((u32) gSeg_6E3A40_ROM_START, (s32) gSeg_6E3A40_VRAM, *sp34);
    sp4C = Sys_GetSPIHeaderInfoFromVaddr(sp30);
    ;
    sp3C = SysMem_HeapAlloc((sp48 = (u32)(D_80160494) * D_800EF930) * 0x10);
    sp40 = sp3C;
    Spi_LimitedDecompress((u32) sp30, sp4C);
    sp38 = (s16*)&D_801604A8;
    for (sp44 = 0; sp44 < sp48; sp44++) {
        sp3C->unk0 = (s16) *sp38++;
        sp3C->unk2 = (s16) *sp38++;
        sp3C->unk4 = (s16) *sp38++;
        sp3C->unk6 = 1;
        sp3C->unk8 = (s16) *sp38++;
        sp3C->unkA = (s16) *sp38++;
        sp3C->unkC =  sp3C->unkD = sp3C->unkE = sp3C->unkF = 0xFF;
        sp3C++;
    }
    if (arg1 != 0) {
        D_8015FBC0 = D_8015FBC0->unk4 = SysMem_HeapAlloc(8);
        D_8015FBC0->unk0 = (s32) sp40;
        D_8015FBC0->unk4 = 0;
    }
    return sp40;
}


void* func_800B0D30(UnkStruct_800B0D30* arg0) {
    void* sp24;
    void* sp20;
    UnkStruct_800B0D30* sp1C;

    if ((sp20 = arg0->unk4) != NULL) {
        sp1C = sp20;

        while (TRUE) {
            sp20 = sp1C->unk4;
            if ((sp24 = sp1C->unk0) != NULL) {
                SysMem_Free(sp24);
            }
            SysMem_Free(sp1C);
            if ((sp1C = sp20) == NULL) {
                break;
            }
        }
        arg0->unk4 = NULL;
        arg0->unk0 = (void* ) arg0->unk4;
    }
    return arg0;
}

void func_800B0E08(void) {
    D_80160448 = ((u8) D_80160448 + 1) & 1;
    D_8015FBA4 = func_800B0D30((UnkStruct_800B0D30 *) &D_8015FB90[(u8) D_80160448]);
    D_8015FBC0 = func_800B0D30((UnkStruct_800B0D30 *) &D_8015FBB0[(u8) D_80160448]);
}

void func_800B0E88(Gfx** gdl, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    s16 sp56;
    Gfx* gdlh;
    MtxF* sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    u16* sp3C;
    Mtx* sp38;

    D_80160220 = arg2;
    D_80160428 = arg3;
    gdlh = *gdl;
    sp4C = &D_801601E0;
    sp3C = &D_8015F890[D_801A1B14];
    sp38 = &D_8015FAA8[D_801A1B14];
    for (sp56 = 0; sp56 < 16; sp56++) {
        sp4C->mf[0][sp56] = 0.0f;
    } 
    ;
    sp4C->mf[0][0] = (sp48 =  MathUtil_Cosf((arg1 *= D_800EF938)) / MathUtil_Sinf(arg1)) * arg4 / (arg5 / arg6);
    sp4C->mf[1][1] = sp48 * arg4;
    sp4C->mf[2][2] = ((sp44 = arg2 + arg3) * arg4) / (sp40 = arg2 - arg3);
    sp4C->mf[2][3] = -arg4;
    sp4C->mf[3][2] = (f32) (((f64) arg2 * 2.0 * (f64) arg3 * (f64) arg4) / (f64) sp40);
    if ((f64) sp44 <= 2.0) {
        *sp3C = -1;
    } else {
        ;
        if ((*sp3C = (u32) (131072.0f / sp44) ) <= 0) {
            *sp3C = 1;
        }
    }
    MtxUtil_MtxFToMtx(&D_801601E0, sp38);
    MtxUtil_MtxFToMtx(&D_801601E0, &D_8015F884[D_8015F888]);
    gSPPerspNormalize(gdlh++, *sp3C);
    gSPMatrix(gdlh++, VIRTUAL_TO_PHYSICAL(&D_8015F884[D_8015F888++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    *gdl = gdlh;
}


void func_800B1250(Gfx** arg0, LookAtParams* arg1, u16 arg2) {
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    MtxF sp28;
    Vec3f* sp24; /* compiler-managed */
    Vec3f* sp20;
    Gfx* sp1C;

    sp24 = &arg1->unk18;
    sp70 = sp24->x;
    sp6C = sp24->y;
    sp68 = sp24->z;
    sp24 = &arg1->unk24;
    sp88 = sp24->x;
    sp84 = sp24->y;
    sp80 = sp24->z;
    sp24 = &arg1->unk0;
    sp20 = &arg1->unkC;

    spA0 = (sp24->x * sp70) - (sp7C = sp20->x * sp70);
    sp9C = (sp24->y * sp6C) - (sp78 = sp20->y * sp6C);
    sp98 = (sp24->z * sp68) - (sp74 = sp20->z * sp68);
    spA4 = -1.0 / sqrtf((spA0 * spA0) + (sp9C * sp9C) + (sp98 * sp98));
    spA0 *= spA4;
    sp9C = sp9C * spA4;

    sp98 = sp98 * spA4;
    sp94 = (sp84 * sp98) - (sp80 * sp9C);
    sp90 = (sp80 * spA0) - (sp88 * sp98);
    sp8C = (sp88 * sp9C) - (sp84 * spA0);
    spA4 = 1.0 / sqrtf((sp94 * sp94) + (sp90 * sp90) + (sp8C * sp8C));
    sp94 *= spA4;
    sp90 = sp90 * spA4;
    sp8C = sp8C * spA4;
    sp88 = (sp9C * sp8C) - (sp98 * sp90);
    sp84 = (sp98 * sp94) - (spA0 * sp8C);
    sp80 = (spA0 * sp90) - (sp9C * sp94);
    spA4 = 1.0 / sqrtf((sp88 * sp88) + (sp84 * sp84) + (sp80 * sp80));
    sp88 = sp88 * spA4;
    sp84 *= spA4;
    sp80 *= spA4;
    sp28.mf[0][0] = sp94;
    sp28.mf[1][0] = sp90;
    sp28.mf[2][0] = sp8C;
    sp28.mf[3][0] = -((sp7C * sp94) + (sp78 * sp90) + (sp74 * sp8C));
    sp28.mf[0][1] = sp88;
    sp28.mf[1][1] = sp84;
    sp28.mf[2][1] = sp80;
    sp28.mf[3][1] = -((sp7C * sp88) + (sp78 * sp84) + (sp74 * sp80));
    sp28.mf[0][2] = spA0;
    sp28.mf[1][2] = sp9C;
    sp28.mf[2][2] = sp98;
    sp28.mf[3][2] = -((sp7C * spA0) + (sp78 * sp9C) + (sp74 * sp98));
    sp28.mf[0][3] = 0.0f;
    sp28.mf[1][3] = 0.0f;
    sp28.mf[2][3] = 0.0f;
    sp28.mf[3][3] = 1.0f;
    if (arg2 == 0) {
        MtxUtil_Identity(0);
    }
    MtxUtil_ScaleAxes(sp70, sp6C, sp68);
    func_800C1D44(&sp28);
    MtxUtil_GetCurrentFromMtxF(&D_8015F884[D_8015F888]);
    sp1C = *arg0;
    gSPMatrix(sp1C++, VIRTUAL_TO_PHYSICAL(&D_8015F884[D_8015F888++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    *arg0 = sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_AFC60/func_800B1844.s")

void func_800B18C4(Gfx **gdl, Gfx* arg1, s16 arg2) {
    Gfx *gdlh;
    UnkStruct_800E8CD0 sp24[1];

    sp24[0] = D_800E8CD0[0];

    gdlh = *gdl;
    MtxUtil_GetCurrentFromMtxF(&D_8015F884[D_8015F888]);
    MtxUtil_Identity(NULL);
    gSPMatrix(gdlh++, VIRTUAL_TO_PHYSICAL(&D_8015F884[D_8015F888++]),*(s16*)((s16*)sp24 + arg2))
    gSPDisplayList(gdlh++, VIRTUAL_TO_PHYSICAL(arg1));
    if (arg2 < 2) {
        gSPPopMatrix(gdlh++, G_MTX_MODELVIEW);
    }
    *gdl = gdlh;
}
