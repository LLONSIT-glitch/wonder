#include "common.h"

typedef struct UnkStruct_801AC8A8_s {
    /* 0x000 */ s16 unk0;                           /* inferred */
    /* 0x002 */ char pad2[0x1E];                    /* maybe part of unk0[0x10]? */
    /* 0x020 */ s16 unk20;                          /* inferred */
    /* 0x022 */ char pad22[0x1E];                   /* maybe part of unk20[0x10]? */
    /* 0x040 */ s16 unk40;                          /* inferred */
    /* 0x042 */ char pad42[0x23E];                  /* maybe part of unk40[0x120]? */
    /* 0x280 */ s32 unk280;                         /* inferred */
    /* 0x284 */ s32 unk284;                         /* inferred */
    /* 0x288 */ s32 unk288;                         /* inferred */
    /* 0x28C */ s32 unk28C;                         /* inferred */
    /* 0x290 */ s32 unk290;                         /* inferred */
    /* 0x294 */ s32 unk294;                         /* inferred */
    /* 0x298 */ s32 unk298;                         /* inferred */
    /* 0x29C */ s32 unk29C;                         /* inferred */
    /* 0x2A0 */ s32 unk2A0;                         /* inferred */
} UnkStruct_801AC8A8;                               /* size = 0x2A4 */

void func_80096EE0(s32*, s32, s32);                      /* extern */
void func_80097068(s32 *, void *, s32);                  /* extern */
void func_80097258(s32 *, s32 *, OSMesgQueue *);       /* extern */
void func_80097150(s32 *, s32 *, OSMesgQueue *);       /* extern */
void func_800971D4(s32 *, s32 *, OSMesgQueue *);       /* extern */
void func_80097420(s32 *);                             /* extern */
void func_800972DC(s32 *);                             /* extern */
void func_800972FC(s32 *);                             /* extern */
void func_8009731C(s32 *, s32 *);                      /* extern */
void func_800C1264(s32, s32*, s32);                       /* extern */


extern s32 D_80153E30;
extern s32 D_801560E4;
extern void* D_801AC850;
extern OSMesgQueue D_801AC870;
extern s16 D_801AC888;
extern UnkStruct_801AC8A8 D_801AC8A8[];
extern s32 D_801540E0;
extern s32 D_801540CC;
extern s32 D_801540D0;
extern s32 D_801A72BC;
extern s32 D_801A72CC;
extern s32 D_801A72DC;
extern s32 D_801824D4;
extern s32 D_80153DF8[];
extern s32 D_801816C8;

void func_800983B0(s32 arg0, s32 arg1) {
    UnkStruct_801AC8A8* sp1C;

    func_80096EE0(&D_80153E30, arg0, arg1);
    Thread_CreateMesgQueue(&D_801AC870, &D_801AC850, 8);
    D_801AC888 = 2;
    sp1C = D_801AC8A8;
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

// Probably calling some createThread function..
void func_800984B4(void) {
    // This probably uses the STACK macro from libultra
    func_80097068(&D_80153E30, &D_801540E0 + 0x800, 0x40);
}

s32 func_800984F0(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_80097258(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

s32 func_800985BC(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_80097150(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

s32 func_80098688(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_800971D4(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

s32 func_80098754(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800C1154(arg0, 8);
    func_80097258(&D_80153E30, &sp1C->unk80B0, &sp1C->mq);
    sp1C->unk82E8 |= 2;
    return 0;
}

void func_80098820(void) {
    D_801A72CC = 0;
    D_801A72BC = 0;
    D_801540CC = 0;
    D_801540D0 = 0;
    D_801A72DC &= ~0x18;
}


void func_80098868(void) {
    func_80097420(&D_80153E30);
}

s32 func_80098894(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800972DC(&sp1C->unk80B0);
    return 0;
}

s32 func_80098928(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

    sp1C = &D_800F1950[arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    func_800972FC(&sp1C->unk80B0);
    return 0;
}


s32 func_800989BC(s32 arg0) {
    UnkStruct_800F9C38 *sp1C;
    s32 *sp18;

    sp1C = &D_800F1950[(u8) arg0];
    if (!(sp1C->unk82E8 & 0x80)) {
        return -1;
    }
    if (!(sp1C->unk82E8 & 2)) {
        return -1;
    }
    sp18 = &sp1C->unk80B0;
    if (sp18[2] & 8) {
        func_8009731C(&D_80153E30, sp18);
    } else {
        func_8009731C(&D_80153E30, sp18);
    }
    sp1C->unk82E8 &= 0xFD;
    return 0;
}

s32 func_80098AD8(u8 arg0) {
    UnkStruct_800F9C38 *sp1C;

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


s32 func_80098D24(s32 arg0) {
    s32 i;
    s32 prevButton;
    ControllerStruct_80180DA8 *sp2C;
    char pad[0x4];


    if (D_801824D4 != 0) {
        func_800C1264(D_80153DF8[3], &D_801816C8, 1);
    }

    
    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (!D_80182558[i].errno) {
            sp2C = &D_80180DA8[i];
            if (sp2C->state != STATE_CONNECTED) {
                sp2C->unk18 = D_80180E50;
                sp2C->unk1C = D_80180E5C;
            }
            sp2C->state = STATE_CONNECTED;
            sp2C->stickX = (f32) D_80182558[i].stick_x * (sp2C->unk18 / 80.0f);
            sp2C->stickY = (f32)  D_80182558[i].stick_y * (sp2C->unk1C / 80.0f);
            prevButton = sp2C->button;
            sp2C->button = D_80182558[i].button;
            sp2C->unk6 = (sp2C->button ^ prevButton) & sp2C->button; // Always 1
            sp2C->unkC -= D_8018257C;
            if (sp2C->button != sp2C->unkA) {
                sp2C->unkA = sp2C->button;
                sp2C->unk8 = sp2C->button;
                sp2C->unkC = 10.0f;
            } else if (sp2C->unkC < 0.0f) {
                sp2C->unk8 = sp2C->unkA;
                sp2C->unkC = 5.0f;
            } else {
                sp2C->unk8 = 0;
            }
        } else {
            sp2C = &D_80180DA8[i];
            sp2C->state = STATE_NOT_CONNECTED;
            sp2C->button = sp2C->unk6 = sp2C->unk8 = sp2C->unkA = 0;
            sp2C->stickX = sp2C->stickY = 0.0f;
            sp2C->unkC = 0.0f;
        }
    } 
    return 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009908C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800993AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800997D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_80099FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A14C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A22C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009A664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009B530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009DB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_8009FC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A19B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A3918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A39C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A3FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A4074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A4104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A41B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A424C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A42C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A4638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A4BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A4ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A5624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A57C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A5844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A5854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A6440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A6514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A6670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A66DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A66EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A6F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A7050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A70D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A7160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A7230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A72BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A735C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800A9564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ABAC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ABB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ABC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ABE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ABEDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC0A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AC978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ACB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ACC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ACD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800ACE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AD1E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AD5EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AD680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AD70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AD774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98FB0/func_800AD7E4.s")
