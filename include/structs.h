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
    /* 0x8000 */ OSTask *threadSp;
    /* 0x8004 */ char pad8004[0xAC];                /* maybe part of threadSp[0x2C]? */
    /* 0x80B0 */ s32 unk80B0;                         /* inferred */
    /* 0x80B0 */ char pad80B0[0x4C];
    /* 0x8100 */ OSThread thread;
    /* 0x82B0 */ void *unk82B0;
    /* 0x82B4 */ char pad82B4[0x1C];                /* maybe part of unk82B0[8]? */
    /* 0x82D0 */ OSMesgQueue mq;
                 
    /* 0x82E8 */ u8 unk82E8;
    /* 0x82E9 */ u8 unk82E9;
    /* 0x82EA */ char pad82EA[0x1E];                /* maybe part of unk82E9[0x1F]? */
} UnkStruct_800F9C38;                               /* size = 0x8308 */


typedef struct ThreadEntry {
    u8 threadId;
    OSPri threadPri;
    char pad4[0x10];
    UnkStruct_800F9C38* unk18;
    char pad[0x8];
} ThreadEntry;

#endif /* STRUCTS_H */
