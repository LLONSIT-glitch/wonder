#include "common.h"

extern Scheduler D_801AC8A8;

extern void func_80096EE0(Scheduler* arg0, u8 arg1, s32 arg2);
s32 func_8009A084(Gfx**, f32); /* extern */
void func_800C1680(void);      /* extern */
void func_800C1A84(MtxF*);     /* extern */
void func_800C1AF4(MtxF*);     /* extern */
void func_800C1B64(s32);       /* extern */

extern f32 D_800EF84C;
extern f32 D_800EF850;
extern f64 D_800EF858;
extern f64 D_800EF860;
extern f32 D_80156BC8[];
extern s16 D_8015B324;
extern s32 D_801601E0;
extern f32 D_801A7218;
extern s32 D_801A7250;
extern s32 D_801A7258;
extern s16* D_801A72D0;
extern s16* D_801A72E0;
extern Scheduler D_80153E30;
extern void* D_801AC850;
extern OSMesgQueue D_801AC870;
extern s16 D_801AC888;

void func_800983B0(Scheduler* arg0, s32 arg1) {
    Scheduler* sp1C;

    func_80096EE0(&D_80153E30, arg0, arg1);
    Thread_CreateMesgQueue(&D_801AC870, &D_801AC850, 8);
    D_801AC888 = 2;
    sp1C = &D_801AC8A8;
    sp1C->unk294 = 0;
    sp1C->unk298 = 0;
    sp1C->unk280 = 0;
    sp1C->unk29C = 0;
    sp1C->unk2A0 = 0;
    sp1C->unk284 = 0;
    sp1C->unk288 = 0;
    sp1C->unk28C = 0;
    sp1C->unk290 = 0;
    sp1C->unk0 = 1;
    sp1C->unk20 = 4;
    sp1C->unk40 = 5;
    D_801560E4 = 0;
}

extern s32 D_801540E0;

void func_800984B4(void) {
    func_80097068(&D_80153E30, &D_801540E0 + 0x800, 0x40);
}

extern Scheduler D_80153E30;

s32 func_800984F0(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_80097258(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

extern Scheduler D_80153E30;

s32 func_800985BC(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_80097150(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

extern Scheduler D_80153E30;

s32 func_80098688(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_800971D4(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

extern Scheduler D_80153E30;

s32 func_80098754(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_80097258(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

extern s32 D_801A72BC;
extern s32 D_801A72CC;
extern s32 D_801540CC;
extern s32 D_801540D0;

void func_80098820(void) {
    D_801A72CC = 0;
    D_801A72BC = 0;
    D_801540CC = 0;
    D_801540D0 = 0;
    D_801A72DC &= ~0x18;
}

extern Scheduler D_80153E30;

void func_80098868(void) {
    func_80097420(&D_80153E30);
}

s32 func_80098894(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800972DC(&sp1C->unk80B0);
    return 0;
}

s32 func_80098928(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800972FC(&sp1C->unk80B0);
    return 0;
}

extern Scheduler D_80153E30;

s32 func_800989BC(s32 arg0) {
    UnkStruct_800F9C38* sp1C;
    SchedulerClient* sp18;

    sp1C = &D_800F1950[(u8) arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    if (!(sp1C->unk82E8 & 2)) {
        return -1;
    }
    sp18 = &sp1C->unk80B0;
    if (sp18->unk8 & 8) {
        func_8009731C(&D_80153E30, sp18);
    } else {
        func_8009731C(&D_80153E30, sp18);
    }
    sp1C->unk82E8 &= 0xFD;
    return 0;
}

extern Scheduler D_80153E30;

s32 func_80098AD8(u8 arg0) {
    UnkStruct_800F9C38* sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    if (!(sp1C->unk82E8 & 2)) {
        return -1;
    }
    func_8009731C(&D_80153E30, &sp1C->unk80B0);
    sp1C->unk82E8 &= 0xFD;
    return 0;
}

void func_80098BB8(void) {
    D_801A72DC |= 1;
    D_801A72DC &= ~2;
}

void func_80098BF4(void) {
    D_801A72DC &= ~3;
}

void func_80098C1C(void) {
    D_801A72DC |= 2;
}

void func_80098C40(void) {
    D_801A72DC |= 8;
}

void func_80098C64(void) {
    D_801A72DC &= ~0x18;
}

void func_80098C8C(void) {
    D_801A72DC |= 0x20;
}

void func_80098CB0(void) {
    D_801A72DC &= ~0x20;
}

void func_80098CD8(void) {
    D_801A72DC |= 4;
}

void func_80098CFC(void) {
    D_801A72DC &= ~4;
}

extern OSMesg D_801816C8;
extern s32 D_801824D4;

s32 func_80098D24(s32 arg0) {
    s32 i;
    s32 prevButton;
    ControllerStruct_80180DA8* sp24;
    UNUSED s32 pad[2];

    if (D_801824D4) {
        Thread_SendMesgNoBlock(gSysThreadIds[THREAD_4], &D_801816C8, OS_MESG_BLOCK);
    }

    for (i = 0; i < 4; i++) {
        if (!D_80182558[i].errno) {
            sp24 = &D_80180DA8[i];
            if (sp24->state != STATE_CONNECTED) {
                sp24->unk18 = D_80180E50;
                sp24->unk1C = D_80180E5C;
            }
            sp24->state = STATE_CONNECTED;
            sp24->stickX = (f32) D_80182558[i].stick_x * (sp24->unk18 / 80.0f);
            sp24->stickY = (f32) D_80182558[i].stick_y * (sp24->unk1C / 80.0f);
            prevButton = sp24->button;
            sp24->button = D_80182558[i].button;
            sp24->unk6 = (sp24->button ^ prevButton) & sp24->button;
            sp24->unkC -= D_8018257C;
            if (sp24->button != sp24->unkA) {
                sp24->unkA = sp24->button;
                sp24->unk8 = sp24->button;
                sp24->unkC = 10.0f;
            } else if (sp24->unkC < 0.0f) {
                sp24->unk8 = sp24->unkA;
                sp24->unkC = 5.0f;
            } else {
                sp24->unk8 = 0;
            }
        } else {
            sp24 = &D_80180DA8[i];
            sp24->state = STATE_NOT_CONNECTED;
            sp24->button = sp24->unk6 = sp24->unk8 = sp24->unkA = 0;
            sp24->stickX = sp24->stickY = 0.0f;
            sp24->unkC = 0.0f;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/CreateGfxTask.s")

void func_800993AC(SchedulerClient* arg0) {
    UnkStruct_800F9C38* sp1C;
    s32 sp18;

    for (sp18 = 0; sp18 < 0xC; sp18++) {
        sp1C = &D_800F1950[sp18];
        if (&sp1C->unk80B0 == arg0) {
            break;
        }
    }
        
    Thread_GetPriority((u8) sp18);
    return;
}

extern u16 D_801DA800;

void func_80099450(void) {
    s32 pad;

    D_80182528 = 0;
    D_801824FC ^= 1;
    if (D_801824FC != 0) {
        D_801824D0 = &D_801DA800;
    } else {
        D_801824D0 = gFrameBuffer2;
    }
    if (D_801824FC != 0) {
        D_801824DC = gFrameBuffer2;
    } else {
        D_801824DC = &D_801DA800;
    }
    Sys_SwapFrameBuffer(D_801824D0);
    D_8018258C += 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_80099520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_80099660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_80099768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800997D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_80099E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_80099F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_80099FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A14C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A22C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009A664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009B530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009DB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_8009FC68.s")

s32 func_800A19B0(Gfx** gdlh, UnkStruct_80099E2C* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                  UnkStruct_80099E2C* arg6) {
    Gfx* gdl;
    s32 texWidth;
    s32 texHeight;
    s32 sp180;
    s32 texMasks;
    s32 texMaskt;
    s32 sp174;
    u32 sp170;
    u32 sp16C;
    u32 sp168;
    u32 sp164;
    s16 sp162;
    s16 sp160;
    s16 sp15E;
    s16 sp15C;
    s16 sp15A;
    s16 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    UNUSED f32 sp134;
    UNUSED f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    s16* imgPtr;

    func_800C1680();
    func_800C1AF4((MtxF*) &D_801601E0);
    func_800C1B64(0);
    func_800C1D44((MtxF*) (&arg6->unkA0));
    func_800C1D44((MtxF*) &arg1->unk80);
    func_800C1A84((MtxF*) &D_80156BC8);
    func_800C1A28();
    sp180 = (arg1->unkC0 | D_801A7250) & D_801A7258;
    if (!(sp180 & 0x20200)) {
        if (func_8009A084(gdlh, -D_80156BC8[14]) < 0) {
            return -1;
        }
    } else if (sp180 & 0x20000) {
        if (func_8009A084(gdlh, -D_80156BC8[14]) < 0) {
            return -1;
        }
    } else if ((sp180 & 0x200) && (func_8009A084(gdlh, (D_801825A8 * 65536.0f) / 2.0f) < 0)) {
        return -1;
    }

    D_8015B324 = (s16) (s32) (((f32) arg1->unk11E * arg6->unkE8) / 255.0f);
    func_800C1680();
    func_800C1AF4((MtxF*) &arg6->unkA0);
    func_800C1D44((MtxF*) &arg1->unk80);
    func_800C1A84((MtxF*) &D_80156BC8);
    func_800C1A28();
    gdl = *gdlh;
    if (arg4 == 0.0f) {
        arg4 = D_800EF84C;
    }
    if (arg5 == 0.0f) {
        arg5 = D_800EF850;
    }
    sp13C = (arg1->unkF4 * arg1->unkFC * D_801A7218) / D_80156BC8[14];
    sp138 = (arg1->unkF8 * arg1->unkFC * D_801A7218) / D_80156BC8[14];
    sp124 = D_801A7218 / D_80156BC8[14];
    if ((sp124 > D_800EF858) && (sp124 < D_800EF860)) {
        sp124 = 1.0f;
    }
    sp134 = sp124;
    sp130 = sp124;
    sp12C = (f32) (s32) (D_80156BC8[12] * sp124 * arg4);
    sp128 = (f32) (s32) (D_80156BC8[13] * sp124 * arg5);
    if (sp180 & 0x40) {
        sp13C = arg1->unkF4 * arg1->unkFC;
        sp138 = arg1->unkF8 * arg1->unkFC;
        sp134 = arg1->unkF4 * arg1->unkFC;
        sp130 = arg1->unkF8 * arg1->unkFC;
    }
    sp13C *= arg4;
    sp138 *= arg5;
    sp15E = (s16) (s32) ((1.0 / (f64) sp13C) * 1024.0);
    sp15C = (s16) (s32) ((1.0 / (f64) sp138) * 1024.0);
    if (arg1->unk116 == 3) {
        return -1;
    }
    D_801A72D0 = (s16*) arg1->ptrs[0];

    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    if (sp180 & 0x20) {
        gDPSetPrimColor(gdl++, 0, 0, 0, 0, 0, D_8015B324);
        gDPSetCombineLERP(gdl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetRenderMode(gdl++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
    } else if (sp180 & 0x8000) {
        gDPSetPrimColor(gdl++, 0, 0, 0, 0, 0, D_8015B324);
        gDPSetCombineLERP(gdl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    } else {
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetRenderMode(gdl++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
    }
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    gDPSetTextureDetail(gdl++, G_TD_CLAMP);
    gDPSetTextureLOD(gdl++, G_TL_TILE);

    // Setup sprite palettes?
    if (arg1->unk116 != 2) {
        if (arg1->unk116 == 1) {
            gDPLoadTLUT_pal256(gdl++, arg1->currentPaletteColors);
        } else {
            gDPLoadTLUT_pal16(gdl++, 16, arg1->currentPaletteColors);
        }
        gDPSetTextureLUT(gdl++, G_TT_RGBA16);
    } else {
        gDPSetTextureLUT(gdl++, G_TT_NONE);
    }

    gDPPipeSync(gdl++);

    gDPSetTextureConvert(gdl++, G_TC_FILT); // yuv to rgba

    if (!(sp180 & 4)) {
        gDPSetTextureFilter(gdl++, G_TF_POINT);
    } else {
        gDPSetTextureFilter(gdl++, G_TF_BILERP);
    }
    while (TRUE) {
        sp15A = *D_801A72D0++;
        if (sp15A == -0x8000) {
            break;
        }
        sp158 = *D_801A72D0++;
        texWidth = (s32) *D_801A72D0++;
        texHeight = (s32) *D_801A72D0++;
        if (!(sp180 & 0x1000)) {
            imgPtr = D_801A72D0;
            D_801A72E0 = D_801A72D0;
            if (arg1->unk116 == 1) {
                D_801A72E0 = (s16*) ((u8*) D_801A72E0 + (texWidth * texHeight));
            } else {
                D_801A72E0 = (s16*) D_801A72E0 + (texWidth * texHeight);
            }
            D_801A72D0 = D_801A72E0;
        } else {
            imgPtr = *(s32*) D_801A72D0;
            D_801A72D0 += 2;
        }
        sp174 = (texWidth / 2) & 0xFF;

        for (texMasks = 8; texMasks > 0; texMasks--) {
            if (sp174 & 0x80) {
                if (sp174 & 0x7F) {
                    texMasks = 0;
                }
                break;
            }
            sp174 *= 2;
        }

        sp174 = (texHeight / 2) & 0xFF;
        for (texMaskt = 8; texMaskt > 0; texMaskt--) {
            if (sp174 & 0x80) {
                if (sp174 & 0x7F) {
                    texMaskt = 0;
                }
                break;
            }
            sp174 *= 2;
        }

        if (!(sp180 & 1)) {
            sp154 = (((f32) sp15A + (f32) arg1->unk104) * sp13C) + sp12C + (arg2 + 160.0f);
            sp144 = 0.0f;
        } else {
            sp154 = (((f32) -sp15A + (f32) (-arg1->unk104 - texWidth)) * sp13C) + sp12C + (arg2 + 160.0f);
            sp144 = (f32) texWidth;
        }
        sp14C = ((f32) texWidth * sp13C) + sp154;
        if ((f64) sp154 < 0.0) {
            sp144 -= sp154 / sp13C;
            sp154 = 0.0f;
        } else if ((f64) sp154 > 320.0) {
            sp144 = (320.0f - sp154) / sp13C;
            sp154 = 320.0f;
        }
        if (sp14C < 0.0f) {
            sp14C = 0.0f;
        } else if (sp14C > 320.0f) {
            sp14C = 320.0f;
        }
        sp170 = (u32) (sp154 * 4.0f);
        sp168 = (u32) (sp14C * 4.0f);
        sp162 = (s16) (s32) (sp144 * 32.0f);
        if (sp170 < sp168) {
            if (!(sp180 & 2)) {
                sp150 = ((((f32) sp158 - (f32) arg1->unk108) * sp138) - sp128) + (120.0f - arg3);
                sp140 = 0.0f;
            } else {
                sp150 =
                    ((((f32) -sp158 * sp138) - sp128) - ((f32) - (arg1->unk108 - texHeight) * sp138)) + (120.0f - arg3);
                sp140 = (f32) texHeight;
            }
            sp148 = ((f32) texHeight * sp138) + sp150;
            if (sp150 < 0.0f) {
                sp140 -= sp150 / sp138;
                sp150 = 0.0f;
            } else if (sp150 > 240.0f) {
                sp140 = (240.0f - sp150) / sp138;
                sp150 = 240.0f;
            }
            if (sp148 < 0.0f) {
                sp148 = 0.0f;
            } else if (sp148 > 240.0f) {
                sp148 = 240.0f;
            }
            sp16C = (u32) (sp150 * 4.0f);
            sp164 = (u32) (sp148 * 4.0f);
            sp160 = (s16) (s32) (sp140 * 32.0f);
            if (sp16C < sp164) {
                if (arg1->unk116 == 1) {
                    gDPLoadTextureBlock(/* pkt */ gdl++, /* timg */ imgPtr,
                                        /* fmt */ G_IM_FMT_CI, /* siz */ G_IM_SIZ_8b,
                                        /* width */ texWidth, /* height*/ texHeight,
                                        /* pal */ 0, /* cms */ G_TX_MIRROR | G_TX_WRAP,
                                        /* cmt */ G_TX_MIRROR | G_TX_WRAP, /* masks */ texMasks,
                                        /* maskt */ texMaskt, G_TX_NOLOD,
                                        /* shift */ G_TX_NOLOD);

                } else if (arg1->unk116 == 2) {
                    gDPLoadTextureBlock(gdl++, imgPtr, G_IM_FMT_RGBA, G_IM_SIZ_16b, texWidth, texHeight, 0,
                                        G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, texMasks, texMaskt,
                                        G_TX_NOLOD, G_TX_NOLOD);
                } else {
                    gDPLoadTextureBlock(gdl++, imgPtr, G_IM_FMT_CI, G_IM_SIZ_4b, texWidth, texHeight, 0,
                                        G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, texMasks, texMaskt,
                                        G_TX_NOLOD, G_TX_NOLOD);
                }

                gDPLoadSync(gdl++);
                gSPTextureRectangle(gdl++, sp170, sp16C, sp168, sp164, 0, sp162, sp160, sp15E, sp15C);
                gDPPipeSync(gdl++);
            }
        }
    }
    gDPPipeSync(gdl++);

    *gdlh = gdl;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A3918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A39C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A3FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A4074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A4104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A41B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A424C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A42C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A4638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A4BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A4ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A5624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A57C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A5844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A5854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A6440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A6514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A6670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A66DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A66EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A6F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A7050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A70D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A7160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A7230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A72BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A735C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800A9564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ABAC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ABB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ABC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ABE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ABEDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC0A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AC978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ACB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ACC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ACD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800ACE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AD1E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AD5EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AD680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AD70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AD774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_98FB0/func_800AD7E4.s")
