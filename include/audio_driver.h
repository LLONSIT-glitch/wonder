#ifndef AUDIO_DRIVER_H
#define AUDIO_DRIVER_H

#define TREMELO_SIN 1
#define TREMELO_SQR 2
#define TREMELO_DSC_SAW 3
#define TREMELO_ASC_SAW 4
#define VIBRATO_SIN 128
#define VIBRATO_SQR 129
#define VIBRATO_DSC_SAW 130
#define VIBRATO_ASC_SAW 131
#define OSC_HIGH 0
#define OSC_LOW 1
#define TWO_PI 6.2831853

typedef struct UnkStruct_801AE1F0_s {
    s16 sndId;
    s32 unk4;
} UnkStruct_801AE1F0;

typedef struct UnkStruct_801AE678_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s16* unkC;
    /* 0x10 */ s16* unk10; /* inferred */
    /* 0x14 */ s16* unk14; /* inferred */
    /* 0x18 */ s16 unk18;
    /* 0x1A */ char pad1A[2];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20; /* inferred */
    /* 0x24 */ s32 unk24; /* inferred */
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s16 unk2C; /* inferred */
    /* 0x2E */ s16 unk2E; /* inferred */
    /* 0x30 */ u8 unk30;  /* inferred */
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32; /* inferred */
    /* 0x33 */ char pad33[1];
} UnkStruct_801AE678; /* size = 0x34 */

typedef struct UnkStruct_801AE598_s {
    /* 0x00 */ UnkStruct_801AE678* unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;  /* inferred */
    /* 0x0C */ s32 unkC;  /* inferred */
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ u16 unk18; /* inferred */
    /* 0x1A */ u8 unk1A;  /* inferred */
    /* 0x1B */ u8 unk1B;
} UnkStruct_801AE598; /* size = 0x1C */

typedef struct UnkStruct_800EA5BC_s {
    /* 0x00 */ s32 unk0;       /* inferred */
    /* 0x04 */ char pad4[0xC]; /* maybe part of unk0[4]? */
} UnkStruct_800EA5BC;          /* size = 0x10 */

typedef struct UnkStruct_800EA144_s {
    s32 unk0;
    u8 unk4;
} UnkStruct_800EA144; /* size = 0x8 */

typedef struct {
    u8 rate;
    u8 depth;
    u8 oscCount;
} defData;

typedef struct {
    u8 halfdepth;
    u8 baseVol;
} tremSinData;

typedef struct {
    u8 curVal;
    u8 hiVal;
    u8 loVal;
} tremSqrData;

typedef struct {
    u8 baseVol;
    u8 depth;
} tremSawData;

typedef struct {
    f32 depthcents;
} vibSinData;

typedef struct {
    f32 loRatio;
    f32 hiRatio;
} vibSqrData;

typedef struct {
    s32 hicents;
    s32 centsrange;
} vibDSawData;

typedef struct {
    s32 locents;
    s32 centsrange;
} vibASawData;

typedef struct oscData_s {
    struct oscData_s* next;
    u8 type;
    u8 stateFlags;
    u16 maxCount;
    u16 curCount;
    union {
        defData def;
        tremSinData tsin;
        tremSqrData tsqr;
        tremSawData tsaw;
        vibSinData vsin;
        vibSqrData vsqr;
        vibDSawData vdsaw;
        vibASawData vasaw;
    } data;
} oscData;

void func_800B95D0(void);                     /* extern */
void func_800B96D4(void);                     /* extern */
void func_800B9890(void);                     /* extern */
void func_800B9C74(void);                     /* extern */
void func_800B9CEC(void);                     /* extern */
void func_800BC4CC(ALSeqpConfig*);            /* extern */
void func_800B9F48(UnkStruct_801AE598*);      /* extern */
void func_800BA748(UnkStruct_801AE598*);      /* extern */
void func_800BA244(UnkStruct_801AE598*, s16); /* extern */
void func_800BB16C(s16);                      /* extern */
void func_800BB3EC(void);                     /* extern */

#endif /* AUDIO_DRIVER_H */

