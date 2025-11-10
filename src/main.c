#include <ultra64.h>
#include "functions.h"
#include "structs.h"
#include "macro.h"
#include "variables.h"
#include "segment.h"

extern f32 D_801825A0;
extern f32 D_801825A8;
extern f32 D_801825B0;
extern f32 D_801825B8;
extern f32 D_801825C0;
extern f32 D_801825C8;

#define STATE_CONNECTED 0
#define STATE_NOT_CONNECTED -1

#define MAX_CONTROLERS 4

void bootproc(void* arg0) {
    char pad[0x50];
    
    func_800CB170();
    gDebugger = 0;
    D_801816C4 = 0;
    osCreateThread(&D_80182650, 3, idleFunc, arg0, D_801849C8 + 0x2000, 0xA);
    osStartThread(&D_80182650);
}

void idleFunc(void* entry) {
    s32 sp1C;

    SysMem_Init();
    Thread_Init();
    func_800ABE54();
    D_80182584 = -1;
    D_8015F808 = 0;
    func_800CB410(0x96, &D_80187B30, &D_80187A18, 0x32);
    osCreateMesgQueue((OSMesgQueue*)&D_80187BC0, &D_80187B78, 0x10);
    
    for (sp1C = 0; sp1C < 128; sp1C++) {
        osCreateMesgQueue((OSMesgQueue *)&D_801887E8[sp1C], &D_801893F0[sp1C], 1);
    }
    D_801895F4 = 0;
    D_800F1918 = D_801A8E3C = Thread_CreateSimple(SysMain, &D_800F1918, 10);
    D_800F1930 = Thread_GetPtr(D_801A8E3C);
    D_800F191C = 10;
    
    if (!gDebugger) {
        Thread_Start(D_801A8E3C);
    }
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (TRUE);
}

void func_800BD8D4(s32 arg0, UNUSED s32 arg1) {
    char pad[20];
    int i;
    D_801A7200 = &D_803DA800;
    D_80181680 = arg0;
    D_8018168C = 74;
    D_8018960C = F24E0_ROM_END - F24E0_ROM_START;
    D_801895FC = (s32 *)&D_801B20A0;
    D_80189604 = &D_801B20A0[D_8018960C];
    osPiStartDma(&D_80187B58, OS_MESG_PRI_NORMAL, 0, F24E0_ROM_START, D_801895FC, D_8018960C, &D_80187BC0);
    osRecvMesg(&D_80187BC0, NULL, 1);
    D_80156BA4 = 0;
    D_801A1B14 = 0;
}

void func_800BD9D0(s32 arg0, s32 arg1) {
    if (arg0 != -1) {
        D_80181680 = arg0;
        osViSetMode(&D_800EBED0[arg0]);
    }
    if (arg1 != -1) {
        D_8018168C = arg1;
        func_800CB680(0x4A);
    }
}

void func_800BDA58(u32 arg0) {
    switch (arg0) { 
    case 0x1:
        D_8018168C &= ~2;
        D_8018168C |= 1;
        break;
    case 0x2:
        D_8018168C &= ~1;
        D_8018168C |= 2;
        break;
    case 0x4:
        D_8018168C &= ~8;
        D_8018168C |= 4;
        break;
    case 0x8:
        D_8018168C &= ~4;
        D_8018168C |= 8;
        break;
    case 0x10:
        D_8018168C &= ~0x20;
        D_8018168C |= 0x10;
        break;
    case 0x20:
        D_8018168C &= ~0x10;
        D_8018168C |= 0x20;
        break;
    case 0x40:
    case 0x80:
        D_8018168C &= ~0x80;
        D_8018168C |= 0x40;
        break;
    }
    func_800BD9D0(-1, D_8018168C);
}

void func_800BDC70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp1C;

    if (D_80182584 != 0) {
        func_800BD8D4(arg0, arg3);
    }
    func_800BD9D0(arg0, D_8018168C);
    if (D_80182584 != 0) {
        D_801824FC = 0;
        D_801819A8 = 0;
        D_8018251C = 0;
        D_80182528 = 1;
        if (D_801824FC != 0) {
            D_801824D0 = &D_801DA800;
        } else {
            D_801824D0 = &gFrameBuffer1;
        }
        if (D_801824FC != 0) {
            D_801824DC = &gFrameBuffer1;
        } else {
            D_801824DC = &D_801DA800;
        }
        D_801A7238 = 0;
    }
    func_8008E630();
    MusFxBankSetCurrent(D_801824D0);
    func_800C15C0();
    for (sp1C = 0; sp1C < 2; sp1C++) {
        D_80182538[sp1C] = 1.0f;
    } 
    D_8018257C = 1.0f;
    D_80182554 = 0;
    D_80182574 = arg3;
    D_8018258C = 0;
    func_80099660(arg1 + 0x5E8);
    if (arg2 != 0) {
        func_800AF060(arg2);
    }
    func_800A6440();
    func_800AC890();
    func_800ABAC8();
    func_800ACE50();
    D_80182584 = 0;
}

void func_800BDE6C(s32 arg0) {
    s32 sp24;
    s32 sp20;
    f32 sp1C;

    sp20 = 0;
    osWritebackDCacheAll();
    if (arg0 & 4) {
        func_800BE068();
    }
    if (arg0 & 2) {
        func_800BE08C();
    }
    sp20 += 1;
    D_80182528 = 0;
    D_8018251C =  osGetTime() - D_801819A8;
    D_801824FC ^= 1;
    if (D_801824FC != 0) {
        D_801824D0 = &D_801DA800;
    } else {
        D_801824D0 = &gFrameBuffer1;
    }
    if (D_801824FC != 0) {
        D_801824DC = &gFrameBuffer1;
    } else {
        D_801824DC = &D_801DA800;
    }
    MusFxBankSetCurrent(D_801824D0);
    D_801819A8 = osGetTime();
    D_80182538[D_80182554] = (f32) sp20;
    D_80182554 = D_80182554 + 1 < 2 ? D_80182554 + 1 : 0;    

    for (sp1C = 0.0f, sp24 = 0; sp24 < 2; sp24++) {
        sp1C += D_80182538[sp24];
    }
}

void func_800BE068(void) {
    if (D_80182528 == 0) {

    }
}

void func_800BE08C(void) {
    osWritebackDCacheAll();
    osViSwapBuffer(D_801824D0);
}


void func_800BE0C4(void) {
    osWritebackDCacheAll();
    osViSwapBuffer(D_801824DC);
}

void func_800BE0FC(void) {
    D_801A1B14 = (s32) (D_801A1B14 + 1) % 3;
    D_80189AF8 = D_80189B08[(D_801824FC ? 0 : 1) << 0xf];
    D_801A1B4C = D_80189AF8;
    D_801A1B44 = D_801A1B4C;
}

void func_800BE18C(Gfx** arg0) {
    Gfx* gdl;

    gdl = *arg0;
    gSPSegment(gdl++, 0x00, 0x00000000);
    gSPSegment(gdl++, 0x01, OS_PHYSICAL_TO_K0(D_801895FC));
    gSPSegment(gdl++, 0x02, OS_PHYSICAL_TO_K0(D_80189AF8));
    gSPSegment(gdl++, 0x03, OS_PHYSICAL_TO_K0(D_801824DC));
    gSPDisplayList(gdl++, &D_1000058);
    gSPDisplayList(gdl++, &D_1000080);
    gDPPipeSync(gdl++);

    *arg0 = gdl;
}

void func_800BE328(Gfx** arg0) {
    Gfx* gdl;

    gdl = *arg0;
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, VIRTUAL_TO_PHYSICAL(D_801A7200));
    gDPSetFillColor(gdl++, 0xFFFCFFFC);
    gDPFillRectangle(gdl++, 0, 0, 319, 239);
    gDPPipeSync(gdl++);
    gDPSetDepthImage(gdl++, VIRTUAL_TO_PHYSICAL(D_801A7200));
    gDPPipeSync(gdl++);

    *arg0 = gdl;
}

void func_800BE4EC(void) {
    if (D_80182528 == 0) {

    }
}

void func_800BE510(f32 arg0, f32 arg1, f32 arg2) {
    func_800BE0FC();
    func_800BE18C((Gfx** ) &D_801A1B44);
    func_800BE328((Gfx** ) &D_801A1B44);
    func_800ABC30(&D_801A1B44);
    func_800AC524(&D_801A1B44);
    func_800B0E88(&D_801A1B44, arg0, arg1, arg2, 1.0f, 320.0f, 240.0f);
    D_801825A0 = arg0;
    D_801825A8 = arg1;
    D_801825B0 = arg2;
    D_801825B8 = 1.0f;
    D_801825C0 = 320.0f;
    D_801825C8 = 240.0f;
    func_80099FB0(arg0);
}

void func_800BE610(void) {
    gDPFullSync(D_801A1B44++);
    gSPEndDisplayList(D_801A1B44++);
}


void func_800BE684(void) {
    gSPDisplayList(D_801A1B44++, D_1000080);
    gSPDisplayList(D_801A1B44++, D_1000058);
    gDPPipeSync(D_801A1B44++);
    func_800BE328((Gfx **) &D_801A1B44);
    gDPSetColorImage(D_801A1B44++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, VIRTUAL_TO_PHYSICAL2(D_801824DC));
}


void alSynFreeFX(ALSynth *s, void **fx) {

}

s32 func_800BE7A0(s32 arg0) {
    s32 sp1C;

    D_80180E68 = 0x800;
    D_80180E74 = 0x400;
    D_80180EC0 = 0x200;
    D_80180EEC = 0x100;
    D_80180FF4 = 0x8000;
    D_8018101C = 0x4000;
    D_80181038 = 0x20;
    D_80181042 = 0x10;
    D_801810F2 = 0x2000;
    D_801811A4 = 0x1000;
    D_801811AC = 8;
    D_80181258 = 4;
    D_80181260 = 2;
    D_8018126C = 1;
    D_80180E50 = 70.0f;
    D_80180E5C = 70.0f;
    osCreateMesgQueue((OSMesgQueue*)&D_80182500, &D_8018252C, 1);
    osSetEventMesg(OS_EVENT_SI, (OSMesgQueue* ) &D_80182500, (void* )1);
    sp1C = osContInit((OSMesgQueue* ) &D_80182500, &D_8018127C, D_80182540);
    
    for (sp1C = 0; sp1C < 4; sp1C++) {
        D_80180DA8[sp1C].state = STATE_CONNECTED;
        D_80180DA8[sp1C].unk18 = D_80180E50;
        D_80180DA8[sp1C].unk1C = D_80180E5C;
    } 
    
    return 0;
}

void func_800BE960(s32 contInitialized) {
    s32 i;
    s32 prevButton;
    ControllerStruct_80180DA8* sp24;

    if (!contInitialized) {
        osContStartReadData(&D_801824E0);
        osRecvMesg(&D_801824E0, NULL, 1);
    }

    osContGetReadData(D_80182558);
    
    for (i = 0; i < MAX_CONTROLERS; i++) {
        if (!D_80182558[i].errno) {
            sp24 = &D_80180DA8[i];
            if (sp24->state != STATE_CONNECTED) {
                sp24->unk18 = D_80180E50;
                sp24->unk1C = D_80180E5C;
            }
            sp24->state = STATE_CONNECTED;
            sp24->stickX = (f32) D_80182558[i].stick_x * (sp24->unk18 / 80.0f);
            sp24->stickY = (f32)  D_80182558[i].stick_y * (sp24->unk1C / 80.0f);
            prevButton = sp24->button;
            sp24->button = D_80182558[i].button;
            sp24->unk6 = (sp24->button ^ prevButton) & sp24->button; // Always 1
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
}

int func_800BECCC(s32 arg0, f32 arg1, f32 arg2) {
    if (D_80180DA8[arg0].state != STATE_CONNECTED) {
        return -1;
    }
    D_80180DA8[arg0].unk18 = arg1;
    D_80180DA8[arg0].unk1C = arg2;
}

void func_800BED48(f32 arg0, f32 arg1) {
    D_80180E50 = arg0;
    D_80180E5C = arg1;
}
