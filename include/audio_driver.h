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

#define AUDIO_SEQ_STATE_MUTED 1
#define AUDIO_SEQ_STATE_PLAYING 2
#define AUDIO_SEQ_STATE_STOPPED 4

#define VOLUME_STATE_NOT_ADJUSTED 0
#define VOLUME_STATE_ADJUSTED 0x10

#define SOUND_DEALLOC_REQUEST_STATE_FREE_SLOT 0
#define SOUND_DEALLOC_REQUEST_STATE_STOP 1
#define SOUND_DEALLOC_REQUEST_STATE_DEALLOCATE 2

#define SEQ_PLAYER_CONTINUE 0 // Continue even if the current volume is zero
#define SEQ_PLAYER_STOP 1 // Used to stop the seqplayer if current volume is zero

#define MAX_VOLUME 32767

typedef struct SoundDealloc_s {
    s16 sndId;
    s32 state;
} SoundDealloc;

typedef struct UnkStruct_801AE678_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s16* unkC;
    /* 0x10 */ s16* unk10; /* inferred */
    /* 0x14 */ s16* unk14; /* inferred */
    /* 0x18 */ s16 sndId;
    /* 0x1A */ char pad1A[2];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20; /* inferred */
    /* 0x24 */ s32 pitchMod; /* inferred */
    /* 0x28 */ s32 basePitch;
    /* 0x2C */ s16 sndVol; /* inferred */
    /* 0x2E */ s16 unk2E; /* inferred */
    /* 0x30 */ u8 mix;  /* inferred */
    /* 0x31 */ u8 pan;
    /* 0x32 */ u8 unk32; /* inferred */
    /* 0x33 */ char pad33[1];
} UnkStruct_801AE678; /* size = 0x34 */

typedef struct UnkStruct_801AE598_s {
    /* 0x00 */ UnkStruct_801AE678* unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 basePitch;  /* inferred */
    /* 0x0C */ s32 unkC;  /* inferred */
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ u16 unk18; /* inferred */
    /* 0x1A */ u8 pan;  /* inferred */
    /* 0x1B */ u8 unused_1B;
} UnkStruct_801AE598; /* size = 0x1C */

typedef struct UnkStruct_800EA5BC_s {
    /* 0x00 */ s32 seqIdx;       /* inferred */
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

void AudioDriver_ConfigSeqPlayerVolume(s32 seqVol, u16 volAdj, s16 maxVol, u16 stopFlags);
void AudioDriver_DeallocSound(UnkStruct_801AE678* arg0);
f32 AudioDriver_DepthToCents(u8 depth);
s32 AudioDriver_GetSequence(s32 seqIdx);
void AudioDriver_Init(void);
ALMicroTime AudioDriver_InitOsc(void** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);
void AudioDriver_InitSeqPlayer(void);
void AudioDriver_InitSoundDeallocRequests(void);
void AudioDriver_InitSoundPlayer(void);
void AudioDriver_LoadBanks(void);
void AudioDriver_LoadSequences(void);
void AudioDriver_ProcessSoundDeallocRequests(void);
void AudioDriver_RequestSoundDealloc(s16 sndId);
void AudioDriver_SetSeqVolume(s32 vol);
void AudioDriver_SetupOsc(ALSeqpConfig* conf);
void AudioDriver_StopOsc(oscData* osc);
void AudioDriver_StopSeqplayer(void);
void AudioDriver_Update(void);
ALMicroTime AudioDriver_UpdateOsc(void* oscState, f32* updateVal);
void AudioDriver_UpdateSeqID(s32 seqId);
void AudioDriver_UpdateSequence(void);
void AudioDriver_UpdateSounds(void);
void func_800B9CEC(void);
void func_800B9DD4(void);
void func_800B9E88(void);
void func_800B9F48(UnkStruct_801AE598* arg0);
void func_800BA244(UnkStruct_801AE598* arg0, s16 arg1);
void func_800BA748(UnkStruct_801AE598* arg0);
s32 func_800BADA8(s32 arg0);
void func_800BB16C(s16 arg0);
s32 func_800BB24C(s32 arg0);
UnkStruct_801AE598* func_800BB448(s32 arg0);
void func_800BB4B4(UnkStruct_801AE598* arg0, s32 arg1);
void func_800BB4DC(s32 arg0);
s32 func_800BB578(void);
#endif /* AUDIO_DRIVER_H */

