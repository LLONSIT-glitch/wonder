#include "common.h"

typedef struct UnkStruct_8000DDE0_unk20C_s {
    char pad[0xC];
    UnkStruct_80099E2C* unkC;
    UnkStruct_80099E2C* unk10;
} UnkStruct_8000DDE0_unk20C;

typedef struct UnkStruct_80014C70_sp24_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    UnkStruct_8000DDE0* unkC;
    void* unk10;
    char pad[0x10];
    f32 unk24;
    f32 unk28;
} UnkStruct_80014C70_sp24;

/* Custom RSP macro? */
#define gSPCustomClipRatio(pkt, r)                           \
    {                                                        \
        gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RNX, FR_NEG_##r); \
        gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RNY, FR_NEG_##r); \
        gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RPX, FR_POS_##r); \
        gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RPY, FR_POS_##r); \
    }

s32 func_800AFB70(s32, s32, s32);

extern s32 D_800DA940[];
UnkStruct_80099E2C* func_8000D688(s32); /* extern */
void func_800B18C4(Gfx**, s32, s32);    /* extern */
extern Lights2 D_800DA8D0;
extern Gfx D_800DB808[];
extern f32 D_800ED590;
extern f64 D_800ED598;
extern f64 D_800ED5A0;
extern f64 D_800ED5A8;
extern LookAtParams D_801AA500[];
extern MtxF D_801AA530;
extern MtxF D_801AA570;

void func_80014F38(UnkStruct_8000DDE0* arg0);

void func_80014C70(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 sp2C;
    s32 sp28;
    UnkStruct_80014C70_sp24* sp24;
    UnkStruct_80014C70_sp24* sp20;
    UNUSED UnkStruct_8000DDE0* sp1C;
    s32* sp18;

    sp24 = arg0->unk20C;
    sp2C = arg0->unk1AC - 0x4000;
    sp24->unkC = arg0;
    sp1C = sp24->unkC;
    func_80099E2C(&arg0->unk0);
    sp24->unkC->unk0.unkCC = arg0->unk1B0;
    sp24->unkC->unk0.unkD0 = arg0->unk1B4;
    sp24->unkC->unk0.unkD4 = arg0->unk1B8;
    if ((arg0->unk1AC == 0x4001) || (arg0->unk1AC == 0x4000)) {
        arg0->unk1B0 = 990.0f;
        arg0->unk1B4 = 996.0f;
        arg0->unk0.unk118 = 0;
        arg0->unk0.unk11A = 0;
        arg0->unk0.unk11C = 0;
        arg0->unk0.unk11E = 0xFF;
    } else if (arg0->unk1AC < 0x6000) {
        sp24->unk10 = TempHeap_Alloc(0x10);
        sp20 = sp24->unk10;
        sp18 = *(D_800DA940 - 0x3E01 + arg0->unk1AC); // Why substract that by 0x3E01?
        sp20->unk0 = *sp18;
        sp20->unk4 = sp18;
        sp20->unk8 = func_800AFB70(sp20->unk0, 1, 1);
        sp20->unkC = NULL;
        sp18 += 9; // was 0x24
        if (*sp18 != -1) {
            do {
                sp20->unkC = SysMem_HeapAlloc(0x10);
                sp20 = (void*) sp20->unkC;
                sp20->unk0 = *sp18;
                sp20->unk4 = sp18;
                sp20->unk8 = func_800AFB70(sp20->unk0, 1, 1);
                sp20->unkC = NULL;
                sp18 += 9;
            } while (*sp18 != -1);
        }
    }
}

void func_80014F38(UnkStruct_8000DDE0* arg0) {
    UnkStruct_80099E2C* sp7C;
    UNUSED s32 sp78;
    UnkStruct_8000DDE0_unk20C* sp74;
    UnkStruct_80099E2C* sp70;
    UnkStruct_80099E2C* sp6C;
    UnkStruct_80099E2C* sp68;

    // osSyncPrintf("Calling fog function?\n");
    sp74 = arg0->unk20C;
    sp70 = sp74->unk10;
    sp6C = sp74->unkC;
    sp78 = arg0->unk1AC - 0x4000;
    if (arg0->unk1AC == 0x4000) {

    } else if (arg0->unk1AC == 0x4001) {
        sp7C = func_8000D688(0x4000);
        sp68 = sp7C;
        MtxUtil_PushIdentity();
        MtxUtil_TranslateLocal(sp68->unkCC, sp68->unkD0, sp68->unkD4);
        MtxUtil_RotateZ(sp68->unkF0);
        MtxUtil_RotateY(sp68->unkEC);
        MtxUtil_RotateX(sp68->unkE8);
        MtxUtil_TranslateLocal(sp6C->unkCC, sp6C->unkD0, sp6C->unkD4);
        MtxUtil_RotateZ(sp6C->unkF0);
        MtxUtil_RotateY(sp6C->unkEC);
        MtxUtil_RotateX(sp6C->unkE8);
        MtxUtil_CopyCurrent(&D_801AA530);
        MtxUtil_TranslateLocal(-sp6C->unkCC, -sp6C->unkD0, -sp6C->unkD4);
        MtxUtil_CopyCurrent(&D_801AA570);
        MtxUtil_Pop();
        if (D_801AA530.mf[3][0] == D_801AA570.mf[3][0]) {
            sp6C->unkA0[1][0] = (f32) ((f64) sp6C->unkA0[1][0] + 0.100000000000000006);
        }
        if (D_801AA530.mf[3][1] == D_801AA570.mf[3][1]) {
            sp6C->unkA0[1][1] = (f32) ((f64) sp6C->unkA0[1][1] + 0.100000000000000006);
        }
        if (D_801AA530.mf[3][2] == D_801AA570.mf[3][2]) {
            sp6C->unkA0[1][2] = (f32) ((f64) sp6C->unkA0[1][2] + 0.100000000000000006);
        }
        D_801AA500->unkC.x = D_801AA530.mf[3][0];
        D_801AA500->unkC.y = D_801AA530.mf[3][1];
        D_801AA500->unkC.z = D_801AA530.mf[3][2];
        D_801AA500->unk0.x = D_801AA570.mf[3][0];
        D_801AA500->unk0.y = D_801AA570.mf[3][1];
        D_801AA500->unk0.z = D_801AA570.mf[3][2];
        MtxUtil_PushIdentity();
        MtxUtil_SetCurrent(&D_801AA530);
        MtxUtil_ClearTranslation(0);
        MtxUtil_TranslateLocal(0.0f, 1.0f, 0.0f);
        MtxUtil_CopyCurrent(&D_801AA530);
        MtxUtil_Pop();
        D_801AA500->unk24.x = D_801AA530.mf[3][0];
        D_801AA500->unk24.y = D_801AA530.mf[3][1];
        D_801AA500->unk24.z = D_801AA530.mf[3][2];
        D_801AA500->unk18.x = sp6C->unkF4;
        D_801AA500->unk18.y = sp6C->unkF4;
        D_801AA500->unk18.z = sp6C->unkF4;
        MtxUtil_PushCopy();
        func_800B1250(&gDisplayListHead, D_801AA500, 0U);
        MtxUtil_CopyCurrent(&D_801AA530);
        MtxUtil_Pop();
        gSPDisplayList(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(D_800DB808));
        gSPSetLights2(gDisplayListHead++, D_800DA8D0);
        gSPCustomClipRatio(gDisplayListHead++, FRUSTRATIO_2);
        if (arg0->unk1B0 > arg0->unk1B4) {
            gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
            gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gSPClearGeometryMode(gDisplayListHead++, G_FOG);
            gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
            gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        } else {
            gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
            gDPSetRenderMode(gDisplayListHead++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
            gSPSetGeometryMode(gDisplayListHead++,
                               G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
            gSPFogFactor(gDisplayListHead++, 0x1F400 / ((s32) arg0->unk1B4 - (s32) arg0->unk1B0),
                         (((0x1F4 - (s32) arg0->unk1B0) * 256) / ((s32) arg0->unk1B4 - (s32) arg0->unk1B0)));
            gDPSetFogColor(gDisplayListHead++, sp6C->unk118, sp6C->unk11A, sp6C->unk11C, sp6C->unk11E);
            gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_PASS2);
        }
        func_800AD1E4(&gDisplayListHead, 5);
    } else if ((arg0->unk1AC < 0x6000) && (sp6C->unk11E != 0)) {
        MtxUtil_PushIdentity();
        MtxUtil_ScaleAxes(D_801AA500->unk18.x, D_801AA500->unk18.y, D_801AA500->unk18.z);
        MtxUtil_TranslateLocal(sp6C->unkCC, sp6C->unkD0, sp6C->unkD4);
        MtxUtil_RotateZ(sp6C->unkF0);
        MtxUtil_RotateY(sp6C->unkEC);
        MtxUtil_RotateX(sp6C->unkE8);
        do {
            MtxUtil_PushCopy();
            MtxUtil_ScaleAxes(sp6C->unkF4, sp6C->unkF4, sp6C->unkF4);
            MtxUtil_TranslateLocal(sp70->unk4->unk8, sp70->unk4->unkC, sp70->unk4->unk10);
            MtxUtil_RotateZ(sp70->unk4->unk1C);
            MtxUtil_RotateY(sp70->unk4->unk18);
            MtxUtil_RotateX(sp70->unk4->unk14);
            if (sp70->unk4->unk4 != -1) {
                sp7C = func_8000D688(sp70->unk4->unk4);
                if (sp7C != NULL) {
                    MtxUtil_TranslateLocal(sp7C->unkCC, sp7C->unkD0, sp7C->unkD4);
                    MtxUtil_RotateZ(sp7C->unkF0);
                    MtxUtil_RotateY(sp7C->unkEC);
                    MtxUtil_RotateX(sp7C->unkE8);
                }
            }
            MtxUtil_ScaleAxes(sp70->unk4->unk20, sp70->unk4->unk20, sp70->unk4->unk20);
            func_800B18C4(&gDisplayListHead, sp70->unk8, 0);
            sp70 = sp70->unkC;
            MtxUtil_Pop();
        } while (sp70 != NULL);
        MtxUtil_Pop();
    }
}

// TODO: maybe UnkStruct_80014C70_sp24 is UnkStruct_8000DDE0?
void func_80015B6C(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 padC;
    UnkStruct_80014C70_sp24* sp8;
    UNUSED s32 pad4;
    UnkStruct_80099E2C* sp0;

    sp8 = (void*) arg0->unk20C;
    sp0 = (void*) sp8->unkC;
    sp8->unk24 = 255.0f;
    sp8->unk28 = 0.0f;
    sp0->unk11E = 0xFF;
}

void func_80015BD0(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 padC;
    UnkStruct_80014C70_sp24* sp8;
    UNUSED s32 pad4;
    UnkStruct_80099E2C* sp0;

    sp8 = (void*) arg0->unk20C;
    sp0 = (void*) sp8->unkC;
    sp8->unk24 = 0.0f;
    sp8->unk28 = 0.0f;
    sp0->unk11E = 0;
}

s32 func_80015C30(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 pad;
    s16 sp1C[7];

    if (func_8000DA44(arg0, 7, (u16*) sp1C) < 0) {
        return -1;
    }
    arg0->unk1B0 = (f32) sp1C[1];
    arg0->unk1B4 = (f32) sp1C[2];
    arg0->unk0.unk118 = (u16) sp1C[3];
    arg0->unk0.unk11A = (u16) sp1C[4];
    arg0->unk0.unk11C = (u16) sp1C[5];
    arg0->unk0.unk11E = (u16) sp1C[6];
    if (arg0->unk1B0 >= 1000.0f) {
        arg0->unk1B0 = 999.0f;
    }
    if (arg0->unk1B4 >= 1000.0f) {
        arg0->unk1B4 = 999.0f;
    }
    return 0;
}

s32 func_80015D74(UnkStruct_8000DDE0* arg0) {
    UNUSED s32 pad;
    s16 sp1C[3];

    if (func_8000DA44(arg0, 3, (u16*) sp1C) < 0) {
        return -1;
    }
    D_8015B334 = (s32) (f32) sp1C[1];
    D_8015B33C = (s32) (f32) sp1C[2];
    return 0;
}
