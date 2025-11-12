#include <ultra64.h>
#ifndef STRUCTS_H
#define STRUCTS_H

struct UnkStruct_801887E8 {
    s32 unk0;
    char pad[0x14];
};

typedef struct ControllerStruct_80180DA8_s {
    /* 0x00 */ s32 state; // Controller state
    /* 0x04 */ u16 button;  // Pad button
    /* 0x06 */ u16 unk6;                            /* inferred */
    /* 0x08 */ u16 unk8;                            /* inferred */
    /* 0x0A */ u16 unkA;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 stickX;                           /* inferred */
    /* 0x14 */ f32 stickY;                           /* inferred */
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ char pad20[8];                       /* maybe part of unk1C[3]? */
} ControllerStruct_80180DA8;                               /* size = 0x28 */

typedef struct UnkStruct_8018255A_s {
    s8 unk0;
    s8 unk1;
    u8 unk2;
    char pad[3];
} UnkStruct_8018255A;

typedef struct UnkStruct_800F9C38 {
    /* 0x0000 */ u8 flags;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ char pad2[0x7FFE];                 /* maybe part of unk1[0x7FFF]? */
    /* 0x8000 */ void* threadSp;
    /* 0x8004 */ char pad8004[0xB0];                /* maybe part of threadSp[0x2F]? */
                 s32 unk80B0;
                 char pad80B4[0x4];
    /* 0x80BC */ s16 unk80BC;                       /* inferred */
    /* 0x80BE */ char pad80BE[0x1E];                /* maybe part of unk80BC[0x10]? */
    /* 0x80DC */ s16 unk80DC;                       /* inferred */
    /* 0x80DE */ char pad80DE[0x22];                /* maybe part of unk80DC[0x12]? */
    /* 0x8100 */ OSThread thread;
    /* 0x82B0 */ s32 unk82B0;
    /* 0x82B4 */ char pad82B4[0x1C];                /* maybe part of unk82B0[8]? */
    /* 0x82D0 */ OSMesgQueue mq;
    /* 0x82E8 */ u8 unk82E8;
    /* 0x82E9 */ u8 unk82E9;
    /* 0x82EA */ char pad82EA[2];                   /* maybe part of unk82E9[3]? */
    /* 0x82EC */ s32 unk82EC;                       /* inferred */
    /* 0x82F0 */ char pad82F0[0x18];                /* maybe part of unk82EC[7]? */
} UnkStruct_800F9C38;                               /* size = 0x8308 */

typedef struct ThreadEntry {
    u8 threadId;
    OSPri threadPri;
    char pad4[0x10];
    UnkStruct_800F9C38* unk18;
    char pad[0x8];
} ThreadEntry;

typedef struct UnkStruct_80099E2C_s {
    /* 0x00 */  char pad[0xC0];
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ s16 unkC4;
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ f32 unkCC;
    /* 0x0D0 */ f32 unkD0;                          /* inferred */
    /* 0x0D4 */ f32 unkD4;                          /* inferred */
    /* 0x0D8 */ f32 unkD8;                          /* inferred */
    /* 0x0DC */ s32 unkDC;                          /* inferred */
    /* 0x0E0 */ s32 unkE0;                          /* inferred */
    /* 0x0E4 */ char padE4[4];
    /* 0x0E8 */ f32 unkE8;                          /* inferred */
    /* 0x0EC */ f32 unkEC;                          /* inferred */
    /* 0x0F0 */ f32 unkF0;                          /* inferred */
    /* 0x0F4 */ f32 unkF4;                          /* inferred */
    /* 0x0F8 */ f32 unkF8;                          /* inferred */
    /* 0x0FC */ f32 unkFC;                          /* inferred */
    /* 0x100 */ s16 unk100;                         /* inferred */
    /* 0x102 */ s16 unk102;                         /* inferred */
    /* 0x104 */ s32 unk104;                         /* inferred */
    /* 0x108 */ s32 unk108;                         /* inferred */
    /* 0x10C */ s16 unk10C;                         /* inferred */
    /* 0x10E */ s16 unk10E;                         /* inferred */
    /* 0x110 */ s32 unk110;                         /* inferred */
    /* 0x114 */ s16 unk114;                         /* inferred */
    /* 0x116 */ s16 unk116;                         /* inferred */
    /* 0x118 */ s16 unk118;                         /* inferred */
    /* 0x11A */ s16 unk11A;                         /* inferred */
    /* 0x11C */ s16 unk11C;                         /* inferred */
    /* 0x11E */ s16 unk11E;                         /* inferred */
    /* 0x120 */ char pad120[2];
    /* 0x122 */ s16 unk122;                         /* inferred */
    /* 0x124 */ s16 unk124;                         /* inferred */
    /* 0x126 */ s16 unk126;                         /* inferred */
    /* 0x128 */ s32 unk128;                         /* inferred */
    /* 0x12C */ s32 unk12C[3];                /* maybe part of unk128[4]? */
    /* 0x138 */ s32 unk138;                         /* inferred */
    /* 0x13C */ s32 unk13C;                         /* inferred */
    /* 0x140 */ s32 unk140;                         /* inferred */
    /* 0x144 */ s32 unk144;                         /* inferred */
    /* 0x148 */ s32 unk148;                         /* inferred */
    /* 0x14C */ s32 unk14C;                         /* inferred */
    /* 0x150 */ s32 unk150;                         /* inferred */
                char pad154[0x8];
                s32 unk160;
} UnkStruct_80099E2C;                               /* size = 0x154 */

typedef struct UnkStruct_80156DC0_s {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ char pad4[0x1A0];                   /* maybe part of unk0[0x69]? */
    /* 0x1A4 */ s32 unk1A4;                         /* inferred */
                s32 unk1A8;
    /* 0x1A8 */ char pad1A8[0x8C];                  /* maybe part of unk1A4[0x25]? */
} UnkStruct_80156DC0;                               /* size = 0x238 */


#endif /* STRUCTS_H */
