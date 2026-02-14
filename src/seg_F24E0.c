#include <ultra64.h>

Vp viewpoint1 = {
    640, 480, 511, 0, 640, 480, 511, 0,
};

Lights4 lights0 = gdSPDefLights4(128, 128, 128, 32, 16, 16, -90, -25, 90, 32, 16, 32, 90, -25, 90, 16, 32, 128, 0, 127,
                                 0, 16, 96, 32, 0, -127, 0);

Gfx D_1000058[] = {
    gsSPViewport(&viewpoint1),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_1000080[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_NOISE),
    gsDPPipeSync(),
    gsSPSetLights4(lights0),
    gsSPEndDisplayList(),
};

Gfx Gfx_unused[] = {
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPFillRectangle(0, 0, 319, 239),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_1000158[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPClearGeometryMode(G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_SHADING_SMOOTH | 0x0000CDF8),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetColorDither(G_CD_NOISE),
    gsSPEndDisplayList(),
};

Vtx D_1000198[] = {
    { { { -64, 70, 0 }, 0, { 0, 512 }, { 0, 32, 255, 255 } } },
    { { { -64, 28, 0 }, 0, { 0, 0 }, { 0, 64, 255, 255 } } },
    { { { 64, 28, 0 }, 0, { 512, 0 }, { 0, 64, 255, 255 } } },
    { { { 64, 70, 0 }, 0, { 512, 512 }, { 0, 32, 255, 255 } } },
    { { { -64, 28, 0 }, 0, { 0, 512 }, { 0, 64, 255, 255 } } },
    { { { -64, -20, 0 }, 0, { 0, 0 }, { 0, 255, 255, 255 } } },
    { { { 64, -20, 0 }, 0, { 512, 0 }, { 0, 255, 255, 255 } } },
    { { { 64, 28, 0 }, 0, { 512, 512 }, { 0, 64, 255, 255 } } },
    { { { -64, -20, 0 }, 0, { 0, 512 }, { 0, 255, 255, 255 } } },
    { { { -64, -40, 0 }, 0, { 0, 0 }, { 192, 255, 255, 255 } } },
    { { { 64, -40, 0 }, 0, { 512, 0 }, { 192, 255, 255, 255 } } },
    { { { 64, -20, 0 }, 0, { 512, 512 }, { 0, 255, 255, 255 } } },
};

Gfx D_1000258[] = {
    gsSPVertex(D_1000198, 12, 0), gsSP1Triangle(0, 1, 2, 0),  gsSP1Triangle(0, 2, 3, 0),   gsSP1Triangle(4, 5, 6, 0),
    gsSP1Triangle(4, 6, 7, 0),    gsSP1Triangle(8, 9, 10, 0), gsSP1Triangle(8, 10, 11, 0), gsSPEndDisplayList(),
};

Vtx D_1000298[] = {
    { { { -64, 4, 0 }, 0, { 0, 512 }, { 0, 0, 127, 255 } } },
    { { { -64, -3, 0 }, 0, { 0, 0 }, { 0, 0, 127, 255 } } },
    { { { 64, -3, 0 }, 0, { 512, 0 }, { 0, 0, 127, 255 } } },
    { { { 64, 4, 0 }, 0, { 512, 512 }, { 0, 0, 127, 255 } } },
};

Gfx D_10002D8[] = {
    gsSPVertex(D_1000298, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsSPEndDisplayList(),
};
