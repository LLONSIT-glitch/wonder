#include "common.h"
#include "sys_matrix.h"

extern u8 D_80160448;
extern void* D_80181668[];
extern s32 D_801A307C;
void func_800B18C4(Gfx**, s32, s32);                     /* extern */

static Lights2 sModelLights = {
    { { { 0x70, 0x70, 0x70 }, 0, { 0x70, 0x70, 0x70 }, 0 } },
    {
        { { { 0xA0, 0xA0, 0xA0 }, 0, { 0xA0, 0xA0, 0xA0 }, 0, { 0x64, 0, 0x50 }, 0 } },
        { { { 0x40, 0x40, 0x40 }, 0, { 0x40, 0x40, 0x40 }, 0, { 0, 0x64, 0x50 }, 0 } },
    },
};

Gfx D_800DB808[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetColorDither(G_CD_NOISE),
    gsSPEndDisplayList(),
};


void func_8002C270(void* arg0) {
    u16 sp1E;

    if (D_80181668[(sp1E = (D_80160448 + 1) & 1)] != 0) {
        SysMem_Free(D_80181668[sp1E]);
    }
    D_80181668[sp1E] = arg0;
}

extern f32 D_801561C0;
extern f32 D_801561C4;
extern f32 D_801561C8;
extern f32 D_801561D0;
extern s8 D_801811AE;
extern f32 D_801812A0;
extern f32 D_80181354;
extern f32 D_801813C8;
extern f32 D_801815D0;
extern f32 D_80181618;
extern f32 D_80181624;
extern s16 D_80181630;
extern s16 D_8018163C;
extern s16 D_80181644;
extern f32 D_80181648;
extern f32 D_80181650;
extern s32 D_80181658;
extern f32 D_80189618;
extern f32 D_8018961C;
extern s32 D_801A307C;
extern f32 D_801A3088;
extern Gfx* D_801A3090;
extern f32 D_801A30A8;
extern f32 D_801A7224;
extern f32 D_801A7230;

void func_8002C2F8(void) {
    u16 spAE;    
    s32 pad1;
    s32 pad2;
    f32 spA0;
    
    LookAtParams sp70[1];
    s32 pad[3];
    

    if (D_80181630 == 0) {
        return;
    }
    spAE = 1;

    // SysMatrix_BuildModel?
    func_800B0E88(&gDisplayListHead, 45.0f, 5.0f, 800.0f, 1.0f, 320.0f, 240.0f);
    sp70->unk18.x = sp70->unk18.y = sp70->unk18.z = 1.0f;
    sp70->unk24.y = sp70->unkC.z = 1.0f;
    
    sp70->unk24.x = 
    sp70->unk24.z = 
    sp70->unkC.x = 
    sp70->unkC.y = 
    sp70->unk0.x = 
    sp70->unk0.y = sp70->unk0.z = 0.0f;
    func_800B1250(&gDisplayListHead, sp70, 0U);
    func_800C1850(0);
    func_800C2304((f32) ((f64) D_80181618 * 0.208), (f32) ((f64) D_80181624 * 0.25), -60.0f);
    if (D_8018163C >= 10) {
        func_800AD1E4(&gDisplayListHead, 3);
    }
    switch (D_8018163C) {
    case 1:
        func_800AD1E4(&gDisplayListHead, 3);
        D_80181618 += D_80189618 * D_8018257C;
        if ((D_80181624 += (D_8018961C * D_8018257C)) > 150.0f) {
            func_800298A4(D_801A7234, D_801A723C, D_80181644, D_80181618, 120.0f);
            D_801811AE = 0;
            D_80181630 = 0;
            func_8002C270(D_801A307C);
            func_800B0E08();
            D_801A307C = 0;
        }
        ;
        if ((D_8018961C -= 0.18 * D_8018257C) < 1.2) {
            D_8018961C = 1.2f;
        }
        ;
        func_800C25B8((D_80181354 += 10.0 * D_8018257C));
        func_800C23E8((D_801812A0 -= 14.0 * D_8018257C));
        break;
    case 2:
        func_800AD1E4(&gDisplayListHead, 5);
        if ((D_80181650 -= D_8018257C) <= 0.0) {
            D_8018163C = 3;
            func_800299C4(D_80181658);
        }
        spAE = 0;
        break;
    case 3:
        D_801815D0 = (f32) ((f64) D_801815D0 + (0.01 * (f64) D_8018257C));
        func_800C25B8(( D_80181354 += 10.0 * D_8018257C));
        func_800C23E8((D_801812A0 -= 15.0 * D_8018257C));
        D_80181618 += D_80189618 * D_8018257C;
        D_80181624 += D_8018961C * D_8018257C;
        if ((f64) D_8018961C > 0.0) {
            func_800AD1E4(&gDisplayListHead, 5);
        } else {
            func_800AD1E4(&gDisplayListHead, 3);
        }
        if ((D_8018961C -= 0.4 * D_8018257C ) < -8.0) {
            D_8018961C = -8.0f;
        }
        if (((f64) D_80181624 < -80.0) && (D_80181644 != 0)) {
            func_80029C8C(D_80181644);
            func_80029ED8();
            D_80181644 = 0;
            func_8002C270(D_801A307C);
            func_800B0E08();
            D_801A307C = 0;
        }
        if ((f64) D_80181624 < -120.0) {
            D_80181630 = 0;
        }
        break;
    case 10:
        D_801815D0 = (f32) ((f64) D_801815D0 + (0.06 * (f64) D_8018257C));
        func_800C25B8((D_80181354 += (15.0 * D_8018257C)));
        func_800C23E8((D_801812A0 -= (20.0 * D_8018257C)));
        func_800C3F2C((f32* ) &D_801A3090, &D_80181618, &D_80181624, &D_80189618, D_801A3088);
        if ((f64) D_801A30A8 == 0.0) {
            func_800B9000(0x14U);
            D_8018163C += 1;
            D_80181650 = 10.0f;
            func_8002BD8C(D_80181644, &D_801812A0, &D_801813C8);
        }
        break;
    case 11:
        D_801A7224 = (f32) ((f64) (guRandom() % 16) - 8.0);
        D_801A7230 = (f32) ((f64) (guRandom() % 16) - 8.0);
        func_800AC0A4((s32) D_801561C0, (s32) D_801561C4, (s32) D_801561C8, (s32) D_801561D0);
        func_800C2780(D_801813C8);
        func_800C23E8(D_801812A0);
       
        if (( D_80181650 -= D_8018257C) <= 0) {
            if (FALSE) {
                // Scrapped code
                func_800C3D70(4.0f, -84.0f, 0.0f, D_80181618, D_80181624, 0.0f, &D_801A3090);
                D_80181648 = D_801815D0 - (func_8002BB04(D_80181644));
                spA0 = D_80181648 / 0.05;
                D_801A3088 = D_801A30A8 / spA0 ;
                D_80181648 /= spA0;
                func_80099F90(0.0f, -4.0f);
                func_800AC0A4((s32) D_801561C0, (s32) D_801561C4, (s32) D_801561C8, (s32) D_801561D0);
                D_8018163C++;
            } else {
                func_800C3D70(4.0f, -300.0f, 0.0f, D_80181618, D_80181624, 0.0f, &D_801A3090);
                D_801A3088 = 0.0f;
                D_8018163C += 2;
            }
        } 
            
        break;
        
    case 12:
        func_800C2780(D_801813C8);
        func_800C23E8(D_801812A0);
        D_801815D0 -= D_80181648 * D_8018257C;
        func_800C3F2C((f32* ) &D_801A3090, &D_80181618, &D_80181624, &D_80189618, D_801A3088 * D_8018257C);
        if ((f64) D_801A30A8 == 0.0) {
            func_8002C270(D_801A307C);
            func_800B0E08();
            D_80181630 = 0;
            D_801A307C = 0;
            func_80029C8C(D_80181644);
            func_80029ED8();
            D_80181644 = 0;
        }
        break;
    case 13:
        func_80099F90(0.0f, -4.0f);
        func_800AC0A4((s32) D_801561C0, (s32) D_801561C4, (s32) D_801561C8, (s32) D_801561D0);
        func_800C2780(D_801813C8);
        func_800C23E8(D_801812A0);
        if ((D_801A3088 += 1.0) > 8.0) {
            D_801A3088 = 12.0f;
        }
        if ((D_80181644 != 0) && ((f64) D_80181624 < -74.0)) {
            func_80029C8C(D_80181644);
            func_80029ED8();
            D_80181644 = 0;
        }
        func_800C3F2C((f32* ) &D_801A3090, &D_80181618, &D_80181624, &D_80189618, D_801A3088 * D_8018257C);
        if ((f64) D_801A30A8 == 0.0) {
            func_8002C270(D_801A307C);
            func_800B0E08();
            D_80181630 = 0;
            D_801A307C = 0;
        }
        break;
    }
    if (spAE != 0) {
        func_800C2948(D_801815D0, D_801815D0, D_801815D0);
        func_8002D200();
    }
}


void func_8002D200(void) {
    if (D_801A307C != 0) {
        gSPDisplayList(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(D_800DB808));
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gSPSetLights2(gDisplayListHead++, sModelLights);
        func_800B18C4(&gDisplayListHead, D_801A307C, 2);
    }
}
