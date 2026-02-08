#include "common.h"
#include "audio_driver.h"
#include "audio.h"

#define COMPRESSED_SEQ_MAX_SIZE 0x3000

// Because we can't use the original alHeapAlloc macro because of the filename and line numbers we will stick to this macros
#define AUDIO_HEAP_ALLOC(line, size)  alHeapDBAlloc("sound/sndprg.c", line, &gAudioHeap, 1, size); 

extern SoundDealloc gSoundDeallocRequests[32];
extern oscData* gFreeOscStateList;
extern oscData D_801AE278[40];

extern UnkStruct_801AE598 D_801AE598[8];
extern UnkStruct_801AE678 D_801AE678[8];

extern ALBank* gAudioTblBank;
extern ALBank* gAudioBankBank;
extern ALSeqFile* gSequenceFile; // Sequences file?
extern ALCSPlayer* gCompressedSeqPlayer;
extern void* gCompressedSequence; // Lib audio representation of the compressed sequence
extern void* gCompressedSequencePtr; // Raw pointer to the compressed sequence in seq file
extern s32 gSequenceCount;
extern s32 D_801AE834;
extern s32 gCurrentSequenceID;
extern s32 gSavedSequenceID;
extern s32 gCurrentSequenceVolume;
extern s32 gAppliedSequenceVolume;
extern s32 D_801AE848;
extern s32 gMaxSequenceVolume;
extern ALSndPlayer* gSoundPlayer;
extern s32 gAudioDriverTick;

// Probably defined in other place..
extern UnkStruct_800EA144 D_800EA144[];
extern UnkStruct_800EA5BC D_800EA5BC[];

#define AUDIO_SEQ_STATE_MUTED 1
#define AUDIO_SEQ_STATE_PLAYING 2
#define AUDIO_SEQ_STATE_STOPPED 4

#define VOLUME_STATE_NOT_ADJUSTED 0
#define VOLUME_STATE_ADJUSTED 0x10

#define SOUND_DEALLOC_REQUEST_STATE_FREE_SLOT 0
#define SOUND_DEALLOC_REQUEST_STATE_STOP 1
#define SOUND_DEALLOC_REQUEST_STATE_DEALLOCATE 2

// .data
s32 gSequencePlayerState = AUDIO_SEQ_STATE_MUTED;
s32 D_800E8CF4 = 0;
s32 D_800E8CF8 = 0;
s32 gVolumeState = VOLUME_STATE_NOT_ADJUSTED;

// Stubbed strings - .rodata
static const char sAudioStubbedPrintf[] = { "seqdata  :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf1[] = { "sfxbank  :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf2[] = { "sfxtable :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf3[] = { "midibank :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf4[] = { "miditable:%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf5[] = { "Loading sbk..." };

void AudioDriver_InitSoundPlayer(void);
void AudioDriver_StopSeqplayer(void);
void AudioDriver_SetupOsc(ALSeqpConfig* conf);

void AudioDriver_Init(void) {
    UNUSED s32 pad[10];
    gAudioDriverTick = 0;
    AudioDriver_LoadBanks();
    AudioDriver_LoadSequences();
    AudioDriver_InitSeqPlayer();
    AudioDriver_InitSoundPlayer();
    func_800B9CEC();
    PRINTF("Done\n");
}

void AudioDriver_LoadSequences(void) {
    u32 size;

    gSequenceFile = AUDIO_HEAP_ALLOC(154, sizeof(ALSeqFile*));
    AudioDmaCopy((u32) audioSequences_ROM_START, gSequenceFile,
                 8); // Only 8 because of what libaudio.h says: "sizeof won't be correct"?
    size = (gSequenceFile->seqCount * 8) + 4;
    gSequenceFile = AUDIO_HEAP_ALLOC(158, (gSequenceFile->seqCount * 8) + 4);
    AudioDmaCopy((u32) audioSequences_ROM_START, gSequenceFile, size);
    alSeqFileNew(gSequenceFile, audioSequences_ROM_START);
    gSequenceCount = gSequenceFile->seqCount;
}

void AudioDriver_LoadBanks(void) {
    s32 size;
    ALBankFile* bankFile;

    size = audioTblStart_ROM_END - audioTblStart_ROM_START;
    bankFile = AUDIO_HEAP_ALLOC(175, size);
    AudioDmaCopy((u32) audioTblStart_ROM_START, bankFile, size);
    alBnkfNew(bankFile, audioTblStart_ROM_END);
    gAudioTblBank = *bankFile->bankArray;
    size = audioBankStart_ROM_END - audioBankStart_ROM_START;
    bankFile = AUDIO_HEAP_ALLOC(181, size);
    AudioDmaCopy((u32) audioBankStart_ROM_START, bankFile, size);
    alBnkfNew(bankFile, audioBankStart_ROM_END);
    gAudioBankBank = *bankFile->bankArray;
}

/*
 * @brief Copy a compressed sequence from an offset from the seqArray into gCompressedSequencePtr
 *
 * @param seqIdx Sequence index to get copy the sequence from the seqArray
 * 
 */
s32 AudioDriver_GetSequence(s32 seqIdx) {
    s32 seqLen;
    u8* seqOffset;

    seqOffset = gSequenceFile->seqArray[seqIdx].offset;
    seqLen = gSequenceFile->seqArray[seqIdx].len;
    if (seqLen & 1) {
        seqLen++;
    }
    PRINTF("Seq Size = %d\n", seqLen);
    AudioDmaCopy((u32) seqOffset, gCompressedSequencePtr, (u32) seqLen);
    return seqLen;
}

void AudioDriver_InitSeqPlayer(void) {
    ALSeqpConfig config;

    config.maxVoices = 20;
    config.maxEvents = 128;
    config.maxChannels = AL_MAX_CHANNELS;
    config.heap = &gAudioHeap;
    config.initOsc = NULL;
    config.updateOsc = NULL;
    config.stopOsc = NULL;
    AudioDriver_SetupOsc(&config);
    config.debugFlags = NO_VOICE_ERR_MASK | NOTE_OFF_ERR_MASK | NO_SOUND_ERR_MASK;
    gCompressedSeqPlayer = AUDIO_HEAP_ALLOC(230, sizeof(ALCSPlayer));
    alCSPNew(gCompressedSeqPlayer, &config);
    gCompressedSequencePtr = AUDIO_HEAP_ALLOC(232, COMPRESSED_SEQ_MAX_SIZE);
    gCompressedSequence = AUDIO_HEAP_ALLOC(233, sizeof(ALCSeq));
    gCurrentSequenceID = -1;
    gSequencePlayerState = AUDIO_SEQ_STATE_MUTED;
    gCurrentSequenceVolume = 0x7FFF;
    gAppliedSequenceVolume = 0;
    gMaxSequenceVolume = 0x7FFF;
    D_801AE848 = 0;
    D_800E8CF8 = 0;
    gVolumeState = VOLUME_STATE_NOT_ADJUSTED;
}

void AudioDriver_InitSoundDeallocRequests(void) {
    int i;

    for (i = 0; i < 16; i++) {
        gSoundDeallocRequests[i].state = SOUND_DEALLOC_REQUEST_STATE_FREE_SLOT;
    }
}

void AudioDriver_ProcessSoundDeallocRequests(void) {
    s32 i;
    s32 sp28;

    for (sp28 = 0, i = 0; i < 16; i++) {
        switch (gSoundDeallocRequests[i].state) {
            case SOUND_DEALLOC_REQUEST_STATE_FREE_SLOT:
                break;
            case SOUND_DEALLOC_REQUEST_STATE_STOP:
                sp28++;
                alSndpSetSound(gSoundPlayer, gSoundDeallocRequests[i].sndId);
                alSndpStop(gSoundPlayer);
                gSoundDeallocRequests[i].state = SOUND_DEALLOC_REQUEST_STATE_DEALLOCATE;
                break;
            case SOUND_DEALLOC_REQUEST_STATE_DEALLOCATE:
                sp28++;
                alSndpSetSound(gSoundPlayer, gSoundDeallocRequests[i].sndId);
                if (alSndpGetState(gSoundPlayer) == AL_STOPPED) {
                    alSndpDeallocate(gSoundPlayer, gSoundDeallocRequests[i].sndId);
                    gSoundDeallocRequests[i].state = SOUND_DEALLOC_REQUEST_STATE_FREE_SLOT;
                }
                break;
                PRINTF("sndp Dealloc error!!\n");

        }
    }
    if (sp28 != 0) {
        D_800E8CF4 |= 0x100;
    } else {
        D_800E8CF4 &= ~0x100;
    }
}

void AudioDriver_RequestSoundDealloc(s16 sndId) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (gSoundDeallocRequests[i].state == SOUND_DEALLOC_REQUEST_STATE_FREE_SLOT) { // free slot
            break;
        }
    }

    if (i != 16) {
        gSoundDeallocRequests[i].sndId = sndId;
        gSoundDeallocRequests[i].state = SOUND_DEALLOC_REQUEST_STATE_STOP;
    } else {
        /* Maybe this is the place for sAudioStubbedPrintf5? */
    }
}

void AudioDriver_InitSoundPlayer(void) {
    ALSndpConfig sndpConfig;

    sndpConfig.maxSounds = 20;
    sndpConfig.maxEvents = 0x80;
    sndpConfig.heap = &gAudioHeap;
    gSoundPlayer = AUDIO_HEAP_ALLOC(345, sizeof(ALSndPlayer));
    alSndpNew(gSoundPlayer, &sndpConfig);
}

static const char sAudioStubbedPrintf7[] = { "Wave Done\n" };
static const char sAudioStubbedPrintf8[] = { "SndpAllocID = %d:%d\n" };
static const char sAudioStubbedPrintf9[] = { "Reqire Seqno = %d:%d\n" };
static const char sAudioStubbedPrintf10[] = { "StopReq %d\n" };
static const char sAudioStubbedPrintf11[] = { "Channel Over\n" };
static const char sAudioStubbedPrintf12[] = { "SE %d Ok!\n" };

void func_800B9CEC(void) {
    s32 sp1C;
    for (sp1C = 0; sp1C < 8; sp1C++) {
        D_801AE598[sp1C].unk4 = 0;
        D_801AE598[sp1C].unk0 = &D_801AE678[sp1C];
        D_801AE678[sp1C].unk0 = sp1C;
        D_801AE678[sp1C].sndId = -1;
    }
    AudioDriver_InitSoundDeallocRequests();
}

void func_800B9DD4(void) {
    s32 i;

    D_800E8CF4 &= ~0x200;
    for (i = 0; i < 8; i++) {
        if (D_801AE598[i].unk4 & 2) {
            D_800E8CF4 |= 0x200;
            func_800B9F48(&D_801AE598[i]);
        }
    }
}

void func_800B9E88(void) {
    s32 sp1C;

    for (sp1C = 0; sp1C < 8; sp1C++) {
        if (D_801AE598[sp1C].unk4 & 2) {
            func_800BA748(&D_801AE598[sp1C]);
        }
    }
}

void AudioDriver_UpdateSounds(void) {
    UNUSED s32 pad;
    AudioDriver_ProcessSoundDeallocRequests();
    func_800B9DD4();
    func_800B9E88();
}

void func_800B9F48(UnkStruct_801AE598* arg0) {
    s16 opcode;
    UnkStruct_801AE678* sp18;

    arg0->unk14++;
    sp18 = arg0->unk0;
    if (arg0->basePitch != sp18->basePitch) {
        sp18->basePitch = arg0->basePitch;
        sp18->unk1C |= 1;
    }
    if (arg0->unkC > arg0->unk10) {
        sp18->unk1C |= 2;
        arg0->unk10 += arg0->unk18;
        if (arg0->unkC < arg0->unk10) {
            arg0->unk10 = arg0->unkC;
        }
    }
    if (arg0->unkC < arg0->unk10) {
        sp18->unk1C |= 2;
        arg0->unk10 -= arg0->unk18;
        if (arg0->unkC > arg0->unk10) {
            arg0->unk10 = arg0->unkC;
        }
    }
    if (arg0->pan != sp18->pan) {
        sp18->pan = arg0->pan;
        sp18->unk1C |= 4;
    }
    sp18->unk4 -= 1;
    while (sp18->unk4 == 0) {
        opcode = *sp18->unkC;
        sp18->unkC++;
        if (opcode < 0x4000) {
            sp18->unk4 = (s32) opcode;
        } else {
            func_800BA244(arg0, opcode);
        }
    }
}

void AudioDriver_DeallocSound(UnkStruct_801AE678* arg0) {
    if (arg0->sndId != -1) {
        AudioDriver_RequestSoundDealloc(arg0->sndId);
        arg0->sndId = -1;
    }
}

void func_800BA244(UnkStruct_801AE598* arg0, s16 arg1) {
    UnkStruct_801AE678* sp1C;

    sp1C = arg0->unk0;
    switch (arg1) {
        case 0x4000:
            AudioDriver_DeallocSound(sp1C);
            sp1C->unk20 = (s32) *sp1C->unkC;
            sp1C->unk1C = 0xF;
            sp1C->unkC++;
            break;
        case 0x4001:
            sp1C->pitchMod = (s32) *sp1C->unkC;
            sp1C->unk1C |= 1;
            sp1C->unkC++;
            break;
        case 0x400A:
            sp1C->pitchMod += *sp1C->unkC;
            sp1C->unk1C |= 1;
            sp1C->unkC++;
            break;
        case 0x4002:
            sp1C->sndVol = *sp1C->unkC;
            sp1C->unk1C |= 2;
            sp1C->unkC++;
            break;
        case 0x400E:
            sp1C->sndVol += *sp1C->unkC;
            sp1C->unk1C |= 2;
            sp1C->unkC++;
            break;
        case 0x4003:
            sp1C->pan = (u8) *sp1C->unkC;
            arg0->pan = sp1C->pan;
            sp1C->unk1C |= 4;
            sp1C->unkC++;
            break;
        case 0x4004:
            sp1C->mix = *sp1C->unkC;
            sp1C->unk1C |= 8;
            sp1C->unkC++;
            break;
        case 0x4005:
            sp1C->unk1C |= 0x1F;
            break;
        case 0x400F:
            sp1C->unk32 = 0;
            func_800BB16C(*sp1C->unkC);
            sp1C->unk32 = *sp1C->unkC;
            break;
        case 0x4006:
            AudioDriver_DeallocSound(sp1C);
            break;
        case 0x4007:
            AudioDriver_DeallocSound(sp1C);
            if (arg0->unk4 & 4) {
                arg0->unk4 = 0;
            } else {
                arg0->unk4 &= ~2;
            }
            sp1C->unk4 = 0xFFFF;
            break;
        case 0x4008:
            sp1C->unk2E = *sp1C->unkC;
            sp1C->unkC++;
            sp1C->unk10 = sp1C->unkC;
            break;
        case 0x4009:
            sp1C->unk2E -= 1;
            if (sp1C->unk2E != 0) {
                sp1C->unkC = sp1C->unk10;
            }
            break;
        case 0x400C:
            sp1C->unk14 = sp1C->unkC;
            break;
        case 0x400D:
            sp1C->unkC = sp1C->unk14;
            break;
        case 0x400B:
            if (sp1C->sndId != -1) {
                alSndpSetSound(gSoundPlayer, sp1C->sndId);
                if (alSndpGetState(gSoundPlayer) != AL_STOPPED) {
                    sp1C->unkC--;
                    sp1C->unk4 = 1;
                } else {
                    /* Empty */
                }
            }
            break;
    }
}

void func_800BA748(UnkStruct_801AE598* arg0) {
    s64 vol;
    UnkStruct_801AE678* sp1C;
    s32 instrument;

    sp1C = arg0->unk0;
    if (sp1C->unk1C & 0x10) {
        instrument = (s32) sp1C->unk20 >> 8;
        sp1C->sndId = alSndpAllocate(gSoundPlayer, gAudioBankBank->instArray[instrument]->soundArray[sp1C->unk20 & 0xFF]);
    }
    if (sp1C->sndId != -1) {
        alSndpSetSound(gSoundPlayer, sp1C->sndId);
        if (sp1C->unk1C & 1) {
            alSndpSetPitch(gSoundPlayer, (((u32) sp1C->pitchMod) / 10000.0f) * (((u32) sp1C->basePitch) / 10000.0f));
        }
        if (sp1C->unk1C & 8) {
            alSndpSetFXMix(gSoundPlayer, sp1C->mix);
        }
        if (sp1C->unk1C & 4) {
            alSndpSetPan(gSoundPlayer, sp1C->pan);
        }
        if (sp1C->unk1C & 2) {
            vol = (s32) (sp1C->sndVol * arg0->unk10) / 32767;
            alSndpSetVol(gSoundPlayer, vol);
        }
        if (sp1C->unk1C & 0x10) {
            alSndpPlay(gSoundPlayer);
        }
    }
    sp1C->unk1C = 0;
}

void AudioDriver_UpdateSequence(void) {
    s32 seqSize;

    switch (gSequencePlayerState) { /* irregular */
        case AUDIO_SEQ_STATE_STOPPED:
            if (gCompressedSeqPlayer->state == 0) {
                D_801AE834 -= 1;
                if (D_801AE834 == 0) {
                    gSequencePlayerState = AUDIO_SEQ_STATE_MUTED;
                }
            }
            break;
        case AUDIO_SEQ_STATE_PLAYING:
            if (gCompressedSeqPlayer->state == 0) {
                AudioDriver_StopSeqplayer();
            }
            break;
    }
    if (gCurrentSequenceID != -1) {
        if (gSequencePlayerState == AUDIO_SEQ_STATE_PLAYING) {
            AudioDriver_StopSeqplayer();
        }
        if ((D_800EA5BC[gCurrentSequenceID].seqIdx < gSequenceCount) && (gSequencePlayerState == AUDIO_SEQ_STATE_MUTED)) {
            gSavedSequenceID = gCurrentSequenceID;
            gCurrentSequenceID = -1;
            seqSize = AudioDriver_GetSequence(D_800EA5BC[gSavedSequenceID].seqIdx);
            alCSeqNew(gCompressedSequence, gCompressedSequencePtr);
            alSeqpSetSeq((ALSeqPlayer*) gCompressedSeqPlayer, gCompressedSequence);
            alSeqpSetBank((ALSeqPlayer*) gCompressedSeqPlayer, gAudioTblBank);

            osSyncPrintf("Playing sequence!\n");
            alSeqpPlay((ALSeqPlayer*) gCompressedSeqPlayer);
            gSequencePlayerState = AUDIO_SEQ_STATE_PLAYING;
        }
    }
    gVolumeState = VOLUME_STATE_NOT_ADJUSTED;

    // Adjust volume
    if (gSequencePlayerState == AUDIO_SEQ_STATE_PLAYING) {
        if (gCurrentSequenceVolume < gMaxSequenceVolume) {
            gCurrentSequenceVolume += D_801AE848;
            if (gCurrentSequenceVolume >= gMaxSequenceVolume) {
                gCurrentSequenceVolume = gMaxSequenceVolume;
            } else {
                gVolumeState = VOLUME_STATE_ADJUSTED;
            }
        }
        if (gCurrentSequenceVolume > gMaxSequenceVolume) {
            gCurrentSequenceVolume -= D_801AE848;
            if (gCurrentSequenceVolume <= gMaxSequenceVolume) {
                gCurrentSequenceVolume = gMaxSequenceVolume;
                if ((gCurrentSequenceVolume == 0) && (D_800E8CF8 & 1)) {
                    AudioDriver_StopSeqplayer();
                }
            } else {
                gVolumeState = VOLUME_STATE_ADJUSTED;
            }
        }

        // If the volume is the same as the last sequence update it
        if (gCurrentSequenceVolume != gAppliedSequenceVolume) {
            gAppliedSequenceVolume = gCurrentSequenceVolume;
            alSeqpSetVol((ALSeqPlayer*) gCompressedSeqPlayer, gCurrentSequenceVolume);
        }
    }
}

void AudioDriver_Update(void) {
    gAudioDriverTick++;
    if (gAudioDriverTick & 1) {
        AudioDriver_UpdateSequence();
        AudioDriver_UpdateSounds(); // Update Sfx
    }
}

s32 func_800BADA8(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_801AE598[i].unk4 == 0) {
            break;
        }
    }

    if (i == 8) {
        return -1;
    }

    D_801AE598[i].unk4 = 1;
    D_801AE678[i].unk8 = arg0;
    D_801AE678[i].sndId = -1;
    D_801AE678[i].unkC = D_800EA144[arg0].unk0;
    D_801AE678[i].unk32 = D_800EA144[arg0].unk4;
    D_801AE678[i].unk14 = D_801AE678[i].unkC;
    D_801AE678[i].unk4 = 1;
    D_801AE678[i].sndVol = 0x7FFF;
    D_801AE678[i].pitchMod = 0x2710;
    D_801AE678[i].basePitch = 0x2710;
    D_801AE678[i].pan = 0x40;
    D_801AE678[i].mix = 0;
    D_801AE598[i].basePitch = 0x2710;
    D_801AE598[i].pan = 0x40;
    D_801AE598[i].unused_1B = 0;
    D_801AE598[i].unkC = 0x7FFF;
    D_801AE598[i].unk18 = 0x7FFF;
    D_801AE598[i].unk10 = 0x7FFF;
    D_801AE598[i].unk14 = 0;

    if (D_801AE678[i].unk32 != 0) {
        func_800BB16C((s16) D_801AE678[i].unk32);
    }
    return i;
}

void func_800BB16C(s16 arg0) {
    s32 sp1C;

    for (sp1C = 0; sp1C < 8; sp1C++) {
        if ((D_801AE598[sp1C].unk4 != 0)) {
            if ((D_801AE678[sp1C].unk32 == (u8) arg0)) {
                AudioDriver_DeallocSound(&D_801AE678[sp1C]);
                D_801AE598[sp1C].unk4 = 0;
            }
        }
    }
}

s32 func_800BB24C(s32 arg0) {
    s32 sp1C;

    if (arg0 == -1) {
        for (sp1C = 0; sp1C < 8; sp1C++) {
            if (D_801AE598[sp1C].unk4 != 0) {
                AudioDriver_DeallocSound(&D_801AE678[sp1C]);
                D_801AE598[sp1C].unk4 = 0;
            }
        }
    } else {
        for (sp1C = 0; sp1C < 8; sp1C++) {
            if ((D_801AE598[sp1C].unk4 != 0)) {
                if ((D_801AE678[sp1C].unk8 == arg0)) {
                    AudioDriver_DeallocSound(&D_801AE678[sp1C]);
                    D_801AE598[sp1C].unk4 = 0;
                }
            }
        }
    }
    return 0;
}

void AudioDriver_UpdateSeqID(s32 seqId) {
    osSyncPrintf("AudioDriver_UpdateSeqID: Sequence ID: %d\n", seqId);
    gCurrentSequenceID = seqId;
}

void AudioDriver_StopSeqplayer(void) {
    if (gSequencePlayerState == AUDIO_SEQ_STATE_PLAYING) {
        alSeqpStop((ALSeqPlayer*) gCompressedSeqPlayer);
        gSequencePlayerState = AUDIO_SEQ_STATE_STOPPED;
        D_801AE834 = 4;
    }
}

UnkStruct_801AE598* func_800BB448(s32 arg0) {
    s32 sp1C;

    sp1C = func_800BADA8(arg0);
    if (sp1C == -1) {
        return NULL;
    }
    return &D_801AE598[sp1C];
}

void func_800BB4B4(UnkStruct_801AE598* arg0, s32 arg1) {
    if (arg0 != NULL) {
        arg0->unk4 |= arg1 | 2;
    }
}

void func_800BB4DC(s32 arg0) {
    func_800BB24C(arg0);
}

// Immediately sets sequence volume and max volume
void AudioDriver_SetSeqVolumeImmediate(s32 vol) {
    gCurrentSequenceVolume = vol;
    gMaxSequenceVolume = vol;
}

void func_800BB52C(s32 seqVol, u16 arg1, s16 maxVol, u16 arg3) {
    if (seqVol != -1) {
        gCurrentSequenceVolume = seqVol;
    }
    D_801AE848 = arg1;
    gMaxSequenceVolume = maxVol;
    D_800E8CF8 = arg3;
}

s32 func_800BB578(void) {
    return gSequencePlayerState | gVolumeState | D_800E8CF4;
}

f32 AudioDriver_DepthToCents(u8 depth) {
    f32 x = 1.03099303;
    f32 cents = 1.0;

    while (depth) {
        if (depth & 1) {
            cents *= x;
        }
        x *= x;
        depth >>= 1;
    }

    return cents;
}

// Original name: initOsc
ALMicroTime AudioDriver_InitOsc(void** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay) {
    oscData* statePtr;
    ALMicroTime deltaTime = 0;

    if (gFreeOscStateList) /* yes there are oscStates available */
    {
        statePtr = gFreeOscStateList;
        gFreeOscStateList = gFreeOscStateList->next;
        statePtr->type = oscType;
        *oscState = statePtr;

        /*
         * Convert delay into usec's, In this example, multiply by
         * 0x4000, but could easily use another conversion method.
         */
        deltaTime = oscDelay * 0x4000;

        switch (oscType) /* set the initVal */
        {
            case TREMELO_SIN:
                statePtr->curCount = 0;
                statePtr->maxCount = 259 - oscRate; /* gives values 4-259 */
                statePtr->data.tsin.halfdepth = oscDepth >> 1;
                statePtr->data.tsin.baseVol = AL_VOL_FULL - statePtr->data.tsin.halfdepth;
                *initVal = (f32) statePtr->data.tsin.baseVol;
                break;

            case TREMELO_SQR:
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                statePtr->data.tsqr.loVal = AL_VOL_FULL - oscDepth;
                statePtr->data.tsqr.hiVal = AL_VOL_FULL;
                statePtr->data.tsqr.curVal = AL_VOL_FULL;
                *initVal = (f32) AL_VOL_FULL;
                break;

            case TREMELO_DSC_SAW:
                statePtr->maxCount = 256 - oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL;
                *initVal = (f32) statePtr->data.tsaw.baseVol;
                break;

            case TREMELO_ASC_SAW:
                statePtr->maxCount = 256 - oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL - oscDepth;
                *initVal = (f32) statePtr->data.tsaw.baseVol;
                break;

            case VIBRATO_SIN:
                statePtr->data.vsin.depthcents = AudioDriver_DepthToCents(oscDepth);
                statePtr->curCount = 0;
                statePtr->maxCount = 259 - oscRate; /* gives values 4-259 */
                *initVal = 1.0f;                    /* start at unity pitch */
                break;

            case VIBRATO_SQR: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                cents = AudioDriver_DepthToCents(oscDepth);
                statePtr->data.vsqr.loRatio = alCents2Ratio(-cents);
                statePtr->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = statePtr->data.vsqr.hiRatio;
            } break;

            case VIBRATO_DSC_SAW: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                cents = AudioDriver_DepthToCents(oscDepth);
                statePtr->data.vdsaw.hicents = cents;
                statePtr->data.vdsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(statePtr->data.vdsaw.hicents);
            } break;

            case VIBRATO_ASC_SAW: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                cents = AudioDriver_DepthToCents(oscDepth);
                statePtr->data.vasaw.locents = -cents;
                statePtr->data.vasaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(statePtr->data.vasaw.locents);
            } break;
        }
    }
    return deltaTime; /* if there are no oscStates, return zero, but if
                           oscState was available, return delay in usecs */
}

// Original name: updateOsc
ALMicroTime AudioDriver_UpdateOsc(void* oscState, f32* updateVal) {
    f32 tmpFlt;
    oscData* statePtr = (oscData*) oscState;
    ALMicroTime deltaTime = AL_USEC_PER_FRAME; /* in this example callback every */
                                               /* frame, but could be at any interval */

    switch (statePtr->type) /* perform update calculations */
    {
        case TREMELO_SIN:
            statePtr->curCount++;
            if (statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32) statePtr->curCount / (f32) statePtr->maxCount;
            tmpFlt = sinf(tmpFlt * TWO_PI);
            tmpFlt = tmpFlt * (f32) statePtr->data.tsin.halfdepth;
            *updateVal = (f32) statePtr->data.tsin.baseVol + tmpFlt;
            break;

        case TREMELO_SQR:
            if (statePtr->stateFlags == OSC_HIGH) {
                *updateVal = (f32) statePtr->data.tsqr.loVal;
                statePtr->stateFlags = OSC_LOW;
            } else {
                *updateVal = (f32) statePtr->data.tsqr.hiVal;
                statePtr->stateFlags = OSC_HIGH;
            }
            deltaTime *= statePtr->maxCount;
            break;

        case TREMELO_DSC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;

            tmpFlt = (f32) statePtr->curCount / (f32) statePtr->maxCount;
            tmpFlt *= (f32) statePtr->data.tsaw.depth;
            *updateVal = (f32) statePtr->data.tsaw.baseVol - tmpFlt;
            break;

        case TREMELO_ASC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32) statePtr->curCount / (f32) statePtr->maxCount;
            tmpFlt *= (f32) statePtr->data.tsaw.depth;
            *updateVal = (f32) statePtr->data.tsaw.baseVol + tmpFlt;
            break;

        case VIBRATO_SIN:
            /* calculate a sin value (from -1 to 1) and multiply it by depthcents.
               Then convert cents to ratio. */

            statePtr->curCount++;
            if (statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32) statePtr->curCount / (f32) statePtr->maxCount;
            tmpFlt = sinf(tmpFlt * TWO_PI) * statePtr->data.vsin.depthcents;
            *updateVal = alCents2Ratio((s32) tmpFlt);
            break;

        case VIBRATO_SQR:
            if (statePtr->stateFlags == OSC_HIGH) {
                statePtr->stateFlags = OSC_LOW;
                *updateVal = statePtr->data.vsqr.loRatio;
            } else {
                statePtr->stateFlags = OSC_HIGH;
                *updateVal = statePtr->data.vsqr.hiRatio;
            }
            deltaTime *= statePtr->maxCount;
            break;

        case VIBRATO_DSC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32) statePtr->curCount / (f32) statePtr->maxCount;
            tmpFlt *= (f32) statePtr->data.vdsaw.centsrange;
            tmpFlt = (f32) statePtr->data.vdsaw.hicents - tmpFlt;
            *updateVal = alCents2Ratio((s32) tmpFlt);
            break;

        case VIBRATO_ASC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32) statePtr->curCount / (f32) statePtr->maxCount;
            tmpFlt *= (f32) statePtr->data.vasaw.centsrange;
            tmpFlt += (f32) statePtr->data.vasaw.locents;
            *updateVal = alCents2Ratio((s32) tmpFlt);
            break;
    }
    return (deltaTime);
}

void AudioDriver_StopOsc(oscData* osc) {
    osc->next = gFreeOscStateList;
    gFreeOscStateList = osc;
}

void AudioDriver_SetupOsc(ALSeqpConfig* conf) {
    s32 sp4;
    oscData* data;

    gFreeOscStateList = D_801AE278;
    for (data = D_801AE278, sp4 = 0; sp4 < 39; sp4++) {
        data->next = &D_801AE278[sp4 + 1];
        data = data->next;
    }

    data->next = NULL;
    conf->initOsc = AudioDriver_InitOsc;
    conf->updateOsc = AudioDriver_UpdateOsc;
    conf->stopOsc = AudioDriver_StopOsc;
}
