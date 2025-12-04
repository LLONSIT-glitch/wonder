#include <ultra64.h>
#ifndef STRUCTS_H
#define STRUCTS_H

struct UnkStruct_801887E8 {
    s32 unk0;
    char pad[0x14];
};

typedef struct ControllerStruct_80180DA8_s {
    /* 0x00 */ s32 state;  // Controller state
    /* 0x04 */ u16 button; // Pad button
    /* 0x06 */ u16 unk6;   /* inferred */
    /* 0x08 */ u16 unk8;   /* inferred */
    /* 0x0A */ u16 unkA;   /* inferred */
    /* 0x0C */ f32 unkC;   /* inferred */
    /* 0x10 */ f32 stickX; /* inferred */
    /* 0x14 */ f32 stickY; /* inferred */
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ char pad20[8]; /* maybe part of unk1C[3]? */
} ControllerStruct_80180DA8;  /* size = 0x28 */

typedef struct UnkStruct_8018255A_s {
    s8 unk0;
    s8 unk1;
    u8 unk2;
    char pad[3];
} UnkStruct_8018255A;

typedef struct UnkStruct_800F9C38 {
    /* 0x0000 */ u8 flags;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ char pad2[0x7FFE]; /* maybe part of unk1[0x7FFF]? */
    /* 0x8000 */ void* threadSp;
    /* 0x8004 */ char pad8004[0xB0]; /* maybe part of threadSp[0x2F]? */
    s32 unk80B0;
    char pad80B4[0x4];
    /* 0x80BC */ s16 unk80BC;        /* inferred */
    /* 0x80BE */ char pad80BE[0x1E]; /* maybe part of unk80BC[0x10]? */
    /* 0x80DC */ s16 unk80DC;        /* inferred */
    /* 0x80DE */ char pad80DE[0x22]; /* maybe part of unk80DC[0x12]? */
    /* 0x8100 */ OSThread thread;
    /* 0x82B0 */ OSMesg mesg;
    /* 0x82B4 */ char pad82B4[0x1C]; /* maybe part of unk82B0[8]? */
    /* 0x82D0 */ OSMesgQueue mq;
    /* 0x82E8 */ u8 unk82E8;
    /* 0x82E9 */ u8 unk82E9;
    /* 0x82EA */ char pad82EA[2];    /* maybe part of unk82E9[3]? */
    /* 0x82EC */ s32 unk82EC;        /* inferred */
    /* 0x82F0 */ char pad82F0[0x18]; /* maybe part of unk82EC[7]? */
} UnkStruct_800F9C38;                /* size = 0x8308 */

typedef struct ThreadEntry {
    u8 threadId;
    OSPri threadPri;
    char pad4[0x10];
    UnkStruct_800F9C38* unk18;
    char pad[0x8];
} ThreadEntry;

typedef struct UnkStruct_801A7340_unk144_s {
    /* 0x00 */ u16 unk0;                            /* inferred */
    /* 0x02 */ u16 unk2;                            /* inferred */
    /* 0x04 */ char pad4[4];                        /* maybe part of unk2[3]? */
    /* 0x08 */ u16 unk8;                            /* inferred */
    /* 0x0A */ char padA[2];
    /* 0x0C */ s16 unkC;                            /* inferred */
    /* 0x0E */ s16 unkE;                            /* inferred */
} UnkStruct_801A7340_unk144;                        /* size = 0x10 */


typedef struct UnkStruct_80099E2C_s {
    /* 0x000 */ s32 unk0;
    /* 0x001 */ char pad1[0x4]; /* maybe part of unk0[8]? */
    /* 0x008 */ s32 unk8;
    /* 0x00C */ char padC[0xC]; /* maybe part of unk8[4]? */
    /* 0x018 */ void* unk18;
    /* 0x01C */ char pad1C[0xA4]; /* maybe part of unk18[0x2A]? */
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ s16 unkC4;
    /* 0x0C6 */ char padC6[2];
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ f32 unkCC;
    /* 0x0D0 */ f32 unkD0;
    /* 0x0D4 */ f32 unkD4;
    /* 0x0D8 */ f32 unkD8;
    /* 0x0DC */ s32 unkDC;
    /* 0x0E0 */ s32 unkE0;
    /* 0x0E4 */ f32 unkE4; /* inferred */
    /* 0x0E8 */ f32 unkE8;
    /* 0x0EC */ f32 unkEC;
    /* 0x0F0 */ f32 unkF0;
    /* 0x0F4 */ f32 unkF4;
    /* 0x0F8 */ f32 unkF8;
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ s16 unk100;
    /* 0x102 */ s16 unk102;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10C */ s16 unk10C;
    /* 0x10E */ s16 unk10E;
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s16 unk114;
    /* 0x116 */ s16 unk116;
    /* 0x118 */ s16 unk118;
    /* 0x11A */ s16 unk11A;
    /* 0x11C */ s16 unk11C;
    /* 0x11E */ s16 unk11E;
    /* 0x120 */ char pad120[2];
    /* 0x122 */ s16 unk122;
    /* 0x124 */ s16 unk124;
    /* 0x126 */ s16 unk126;
    /* 0x128 */ u8* ptrs[4];
    /* 0x138 */ s16* currentPaletteColors;
    /* 0x13C */ u8* unk13C;
    /* 0x140 */ u8* unk140;
    /* 0x144 */ UnkStruct_801A7340_unk144* unk144;
    /* 0x148 */ s32 unk148;
    /* 0x14C */ s32 unk14C;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ char pad154[8]; /* maybe part of unk150[3]? */
    /* 0x15C */ s32 unk160;
} UnkStruct_80099E2C; /* size = 0x160 */

typedef struct UnkStruct_80020720_s {
    s32 unk0;
    char* unk4;
} UnkStruct_80020720;

typedef struct UnkStruct_801560F0_s {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u16 unk4;      /* inferred */
    /* 0x06 */ u16 unk6;      /* inferred */
    /* 0x08 */ u16 unk8;      /* inferred */
    /* 0x0A */ char padA[6];  /* maybe part of unk8[4]? */
    /* 0x10 */ f32 unk10;     /* inferred */
    /* 0x14 */ f32 unk14;     /* inferred */
    /* 0x18 */ char pad18[8]; /* maybe part of unk14[3]? */
} UnkStruct_801560F0;         /* size = 0x20 */

typedef struct UnkStruct_80182618_s {
    u8* ptrs[4];
} UnkStruct_80182618;

typedef struct UnkStruct_8000E3D4_s {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ UnkStruct_80099E2C* unkC;
    /* 0x10 */ UnkStruct_800B23C4* unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;    /* inferred */
    /* 0x50 */ u16 unk50;    /* inferred */
    /* 0x52 */ u16 unk52;    /* inferred */
    /* 0x54 */ s16 unk54[4]; /* maybe part of unk52[5]? */
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ u16 unk62;
    /* 0x64 */ s16 unk64;
    /* 0x66 */ s16 unk66;
    /* 0x68 */ s16 unk68;
    /* 0x6A */ char pad6A[2];
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ char pad78[4];
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ char pad80[0x14]; /* maybe part of unk7C[6]? */
    /* 0x94 */ s32 unk94;
    /* 0x98 */ f32 unk98;
    /* 0x9C */ f32 unk9C;
    /* 0xA0 */ f32 unkA0;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ f32 unkB0;
    /* 0xB4 */ f32 unkB4;
    /* 0xB8 */ f32 unkB8;
    /* 0xBC */ f32 unkBC;
    /* 0xC0 */ f32 unkC0;
    /* 0xC4 */ f32 unkC4;
} UnkStruct_8000E3D4; /* size = 0xC8 */

typedef struct UnkStruct_8000DDE0_s {
    UnkStruct_80099E2C unk0;
    char pad160[0x40];
    /* 0x1A0 */ s32 unk1A0;
    /* 0x1A4 */ s32 unk1A4;
    /* 0x1A8 */ s32 unk1A8;
    /* 0x1AC */ s32 unk1AC;
    /* 0x1B0 */ f32 unk1B0;        /* inferred */
    /* 0x1B4 */ f32 unk1B4;        /* inferred */
    /* 0x1B8 */ char pad1B8[0x30]; /* maybe part of unk1B4[0xD]? */
    /* 0x1E8 */ f32 unk1E8;
    /* 0x1EC */ f32 unk1EC;
    /* 0x1F0 */ f32 unk1F0;
    /* 0x1F4 */ f32 unk1F4;
    /* 0x1F8 */ f32 unk1F8;
    /* 0x1FC */ f32 unk1FC;
    /* 0x200 */ f32 unk200;
    /* 0x204 */ f32 unk204;
    /* 0x208 */ u16 unk208;
    /* 0x20A */ char pad20A[2];
    /* 0x20C */ void* unk20C;
    /* 0x210 */ u16* unk210;
    /* 0x214 */ char pad214[0x24]; /* maybe part of unk210[0xA]? */
} UnkStruct_8000DDE0;              /* size = 0x238 */

typedef struct UnkStruct_801A3068_s {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;                            /* inferred */
    /* 0x08 */ u16 unk8;                            /* inferred */
    /* 0x0A */ s16 unkA;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
} UnkStruct_801A3068;                               /* size = 0x10 */

typedef struct UnkStruct_8008250C_s {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;                            /* inferred */
    /* 0x04 */ s16 unk4;                            /* inferred */
    /* 0x06 */ char pad6[2];
    /* 0x08 */ UnkStruct_80099E2C* unk8;            /* inferred */
    /* 0x0C */ UnkStruct_800B23C4* unkC;            /* inferred */
    /* 0x10 */ u16 unk10;                           /* inferred */
    /* 0x12 */ char pad12[2];
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */    
               s32 unk1C;
} UnkStruct_8008250C;                               /* size = 0x1C */

typedef struct UnkStruct_8018165C_s {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char pad1[1];
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;                            /* inferred */
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ UnkStruct_80099E2C* unk24;
    /* 0x28 */ UnkStruct_800B23C4* unk28;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ char pad2E[2];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
} UnkStruct_8018165C;                               /* size = 0x48 */

typedef struct UnkStruct_801AE5A0_s {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ char pad10[0xA];                     /* maybe part of unkC[3]? */
    /* 0x1A */ u8 unk1A;                            /* inferred */
    /* 0x1B */ char pad1B[1];
} UnkStruct_801AE5A0;                               /* size = 0x1C */

typedef struct UnkStruct_800970CC_arg1_s {
    /* 0x0 */ struct UnkStruct_800970CC_arg1_s* unk0;                             /* inferred */
    /* 0x4 */ OSMesgQueue* unk4;                             /* inferred */
    /* 0x8 */ s32 unk8;                             /* inferred */
} UnkStruct_800970CC;                               /* size = 0xC */

typedef struct UnkStruct_801AC8A8_unk294_s {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ OSTask unk10;
} UnkStruct_801AC8A8_unk294;                        /* size = 0x50 */

typedef struct UnkStruct_801AC8A8_unk298_s {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ void *unkC;
    /* 0x10 */ OSTask unk10;
    /* 0x50 */ OSMesgQueue *unk50;
    /* 0x54 */ void *unk54;
} UnkStruct_801AC8A8_unk298;                        /* size = 0x58 */

typedef struct UnkStruct_801AC8A8_unk284_s {
    /* 0x0 */ struct UnkStruct_801AC8A8_unk284_s *unk0;      /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
    /* 0x8 */ s32 unk8;                             /* inferred */
             s32 padC;
            s32 unk10;
} UnkStruct_801AC8A8_unk284;                        /* size = 0xC */

typedef struct UnkStruct_801AC8A8_s {
    /* 0x000 */ s16 unk0;
    /* 0x002 */ char pad2[0x1E];                    /* maybe part of unk0[0x10]? */
    /* 0x020 */ s16 unk20;
    /* 0x022 */ char pad22[0x1E];                   /* maybe part of unk20[0x10]? */
    /* 0x040 */ s16 unk40;
    /* 0x042 */ char pad42[0x1E];                   /* maybe part of unk40[0x10]? */
    /* 0x060 */ OSMesgQueue unk60;
    /* 0x078 */ void* unk78;
    /* 0x07C */ char pad7C[0x1C];                   /* maybe part of unk78[8]? */
    /* 0x098 */ OSMesgQueue unk98;
    /* 0x0B0 */ void* unkB0;
    /* 0x0B4 */ char padB4[0x1C];                   /* maybe part of unkB0[8]? */
    /* 0x0D0 */ OSThread unkD0;
    /* 0x280 */ UnkStruct_800970CC* unk280;
    /* 0x284 */ UnkStruct_801AC8A8_unk284* unk284;
    /* 0x288 */ UnkStruct_801AC8A8_unk284* unk288;
    /* 0x28C */ UnkStruct_801AC8A8_unk284* unk28C;
    /* 0x290 */ UnkStruct_801AC8A8_unk284* unk290;
    
    /* 0x294 */ UnkStruct_801AC8A8_unk294* unk294;
    /* 0x298 */ UnkStruct_801AC8A8_unk298* unk298;
    /* 0x29C */ s32 unk29C;
    /* 0x2A0 */ s32 unk2A0;
    /* 0x2A4 */ s32 unk2A4;                         /* inferred */
} UnkStruct_801AC8A8;                               /* size = 0x2A8 */


#endif /* STRUCTS_H */

