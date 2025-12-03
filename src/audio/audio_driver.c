#include "common.h"
#include "audio_driver.h"
#include "audio.h"

extern UnkStruct_801AE1F0 D_801AE1F0[32];
extern oscData* D_801AE270;
extern oscData D_801AE278[40];

extern UnkStruct_801AE598 D_801AE598[8];
extern UnkStruct_801AE678 D_801AE678[8];

extern ALBank* D_801AE818;
extern ALBank* D_801AE81C;
extern ALSeqFile* D_801AE820;
extern ALCSPlayer* D_801AE824;
extern void* D_801AE828;
extern void* D_801AE82C;
extern s32 D_801AE830;
extern s32 D_801AE834;
extern s32 D_801AE838;
extern s32 D_801AE83C;
extern s32 D_801AE840;
extern s32 D_801AE844;
extern s32 D_801AE848;
extern s32 D_801AE84C;
extern ALSndPlayer* D_801AE850;
extern s32 D_801AE854;

// Probably defined in other place..
extern UnkStruct_800EA144 D_800EA144[];
extern UnkStruct_800EA5BC D_800EA5BC[];

// .data
s32 D_800E8CF0 = 1;
s32 D_800E8CF4 = 0;
s32 D_800E8CF8 = 0;
s32 D_800E8CFC = 0;

// Stubbed strings - .rodata
static const char sAudioStubbedPrintf[] = { "seqdata  :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf1[] = { "sfxbank  :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf2[] = { "sfxtable :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf3[] = { "midibank :%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf4[] = { "miditable:%08X-%08X(%08X:%10d bytes)\n" };
static const char sAudioStubbedPrintf5[] = { "Loading sbk..." };

void func_800B9580(void) {
    UNUSED s32 pad[10];
    D_801AE854 = 0;
    func_800B96D4();
    func_800B95D0();
    func_800B9890();
    func_800B9C74();
    func_800B9CEC();
}

// NEEDS RODATA
void func_800B95D0(void) {
    u32 sp24;

    D_801AE820 = alHeapDBAlloc("sound/sndprg.c", 154, &gAudioHeap, 1, 4);
    DmaCopy((u32) &audioSequences_ROM_START, D_801AE820,
            8U); // Only 8 because of what libaudio.h says "sizeof won't be correct"?
    sp24 = (D_801AE820->seqCount * 8) + 4;
    D_801AE820 = alHeapDBAlloc("sound/sndprg.c", 158, &gAudioHeap, 1, (D_801AE820->seqCount * 8) + 4);
    DmaCopy((u32) &audioSequences_ROM_START, D_801AE820, sp24);
    alSeqFileNew(D_801AE820, audioSequences_ROM_START);
    D_801AE830 = D_801AE820->seqCount;
    PRINTF("Done\n");
}

// NEEDS RODATA
void func_800B96D4(void) {
    s32 sp24;
    ALBankFile* sp20;

    sp24 = audioTblStart_ROM_END - audioTblStart_ROM_START;
    sp20 = alHeapDBAlloc("sound/sndprg.c", 175, &gAudioHeap, 1, sp24);
    DmaCopy((u32) audioTblStart_ROM_START, sp20, (u32) sp24);
    alBnkfNew(sp20, audioTblStart_ROM_END);
    D_801AE818 = sp20->bankArray[0];
    sp24 = audioBankStart_ROM_END - audioBankStart_ROM_START;
    sp20 = alHeapDBAlloc("sound/sndprg.c", 181, &gAudioHeap, 1, sp24);
    DmaCopy((u32) audioBankStart_ROM_START, sp20, (u32) sp24);
    alBnkfNew(sp20, audioBankStart_ROM_END);
    D_801AE81C = sp20->bankArray[0];
}

/*
 * Copy a sequence from offset into D_801AE82C
 */
s32 func_800B97E4(s32 seqIdx) {
    s32 seqLen;
    u8* seqOffset;

    seqOffset = D_801AE820->seqArray[seqIdx].offset;
    seqLen = D_801AE820->seqArray[seqIdx].len;
    if (seqLen & 1) {
        seqLen++;
    }
    PRINTF("Seq Size = %d\n", seqLen);
    DmaCopy((u32) seqOffset, D_801AE82C, (u32) seqLen);
    return seqLen;
}

// NEEDS RODATA
void func_800B9890(void) {
    ALSeqpConfig config;

    config.maxVoices = 20;
    config.maxEvents = 128;
    config.maxChannels = 16;
    config.heap = &gAudioHeap;
    config.initOsc = 0;
    config.updateOsc = 0;
    config.stopOsc = 0;
    func_800BC4CC((ALSeqpConfig*) &config);
    config.debugFlags = 7;
    D_801AE824 = alHeapDBAlloc("sound/sndprg.c", 230, &gAudioHeap, 1, 0x7C);
    alCSPNew(D_801AE824, (ALSeqpConfig*) &config);
    D_801AE82C = alHeapDBAlloc("sound/sndprg.c", 232, &gAudioHeap, 1, 0x3000);
    D_801AE828 = alHeapDBAlloc("sound/sndprg.c", 233, &gAudioHeap, 1, 0xF8);
    D_801AE838 = -1;
    D_800E8CF0 = 1;
    D_801AE840 = 0x7FFF;
    D_801AE844 = 0;
    D_801AE84C = 0x7FFF;
    D_801AE848 = 0;
    D_800E8CF8 = 0;
    D_800E8CFC = 0;
}

static const char sAudioStubbedPrintf6[] = { "sndp Dealloc error!!\n" };

void func_800B99D4(void) {
    int i;

    for (i = 0; i < 16; i++) {
        D_801AE1F0[i].unk4 = 0;
    }
}

void func_800B9A18(void) {
    s32 sp2C;
    s32 sp28;

    for (sp28 = 0, sp2C = 0; sp2C < 16; sp2C++) {
        switch (D_801AE1F0[sp2C].unk4) { /* irregular */
            case 0:
                break;
            case 1:
                sp28 += 1;
                alSndpSetSound(D_801AE850, D_801AE1F0[sp2C].sndId);
                alSndpStop(D_801AE850);
                D_801AE1F0[sp2C].unk4 = 2;
                break;
            case 2:
                sp28 += 1;
                alSndpSetSound(D_801AE850, D_801AE1F0[sp2C].sndId);
                if (alSndpGetState(D_801AE850) == AL_STOPPED) {
                    alSndpDeallocate(D_801AE850, D_801AE1F0[sp2C].sndId);
                    D_801AE1F0[sp2C].unk4 = 0;
                }
                break;
        }
    }
    if (sp28 != 0) {
        D_800E8CF4 |= 0x100;
    } else {
        D_800E8CF4 &= ~0x100;
    }
}

void func_800B9BD4(s16 arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_801AE1F0[i].unk4 == 0) { // free slot
            break;
        }
    }

    if (i != 0x10) {
        D_801AE1F0[i].sndId = arg0;
        D_801AE1F0[i].unk4 = 1;
    } else {
        /* Maybe this is the place for sAudioStubbedPrintf5? */
    }
}

// NEEDS RODATA
void func_800B9C74(void) {
    ALSndpConfig sndpConfig;

    sndpConfig.maxSounds = 0x14;
    sndpConfig.maxEvents = 0x80;
    sndpConfig.heap = &gAudioHeap;
    D_801AE850 = alHeapDBAlloc("sound/sndprg.c", 345, &gAudioHeap, 1, 0x54);
    alSndpNew(D_801AE850, (ALSndpConfig*) &sndpConfig);
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
        D_801AE678[sp1C].unk18 = -1;
    }
    func_800B99D4();
}

void func_800B9DD4(void) {
    s32 sp1C;

    D_800E8CF4 &= ~0x200;
    for (sp1C = 0; sp1C < 8; sp1C++) {
        if (D_801AE598[sp1C].unk4 & 2) {
            D_800E8CF4 |= 0x200;
            func_800B9F48(&D_801AE598[sp1C]);
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

void func_800B9F10(void) {
    UNUSED s32 pad;
    func_800B9A18();
    func_800B9DD4();
    func_800B9E88();
}

void func_800B9F48(UnkStruct_801AE598* arg0) {
    s16 sp1E;
    UnkStruct_801AE678* sp18;

    arg0->unk14 += 1;
    sp18 = arg0->unk0;
    if (arg0->unk8 != sp18->unk28) {
        sp18->unk28 = arg0->unk8;
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
    if (arg0->unk1A != sp18->unk31) {
        sp18->unk31 = arg0->unk1A;
        sp18->unk1C |= 4;
    }
    sp18->unk4 -= 1;
    while (sp18->unk4 == 0) {
        sp1E = *sp18->unkC;
        sp18->unkC++;
        if (sp1E < 0x4000) {
            sp18->unk4 = (s32) sp1E;
        } else {
            func_800BA244(arg0, sp1E);
        }
    }
}

void func_800BA1E8(UnkStruct_801AE678* arg0) {
    if (arg0->unk18 != -1) {
        func_800B9BD4(arg0->unk18);
        arg0->unk18 = -1;
    }
}

void func_800BA244(UnkStruct_801AE598* arg0, s16 arg1) {
    UnkStruct_801AE678* sp1C;

    sp1C = arg0->unk0;
    switch (arg1) {
        case 0x4000:
            func_800BA1E8(sp1C);
            sp1C->unk20 = (s32) *sp1C->unkC;
            sp1C->unk1C = 0xF;
            sp1C->unkC++;
            break;
        case 0x4001:
            sp1C->unk24 = (s32) *sp1C->unkC;
            sp1C->unk1C |= 1;
            sp1C->unkC++;
            break;
        case 0x400A:
            sp1C->unk24 += *sp1C->unkC;
            sp1C->unk1C |= 1;
            sp1C->unkC++;
            break;
        case 0x4002:
            sp1C->unk2C = *sp1C->unkC;
            sp1C->unk1C |= 2;
            sp1C->unkC++;
            break;
        case 0x400E:
            sp1C->unk2C += *sp1C->unkC;
            sp1C->unk1C |= 2;
            sp1C->unkC++;
            break;
        case 0x4003:
            sp1C->unk31 = (u8) *sp1C->unkC;
            arg0->unk1A = sp1C->unk31;
            sp1C->unk1C |= 4;
            sp1C->unkC++;
            break;
        case 0x4004:
            sp1C->unk30 = *sp1C->unkC;
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
            func_800BA1E8(sp1C);
            break;
        case 0x4007:
            func_800BA1E8(sp1C);
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
            if (sp1C->unk18 != -1) {
                alSndpSetSound(D_801AE850, sp1C->unk18);
                if (alSndpGetState(D_801AE850) != 0) {
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
    s64 sp24;
    UnkStruct_801AE678* sp1C;
    s32 sp18;

    sp1C = arg0->unk0;
    if (sp1C->unk1C & 0x10) {
        sp18 = (s32) sp1C->unk20 >> 8;
        sp1C->unk18 = alSndpAllocate(D_801AE850, D_801AE81C->instArray[sp18]->soundArray[sp1C->unk20 & 0xFF]);
    }
    if (sp1C->unk18 != -1) {
        alSndpSetSound(D_801AE850, sp1C->unk18);
        if (sp1C->unk1C & 1) {
            alSndpSetPitch(D_801AE850, (((u32) sp1C->unk24) / 10000.0f) * (((u32) sp1C->unk28) / 10000.0f));
        }
        if (sp1C->unk1C & 8) {
            alSndpSetFXMix(D_801AE850, sp1C->unk30);
        }
        if (sp1C->unk1C & 4) {
            alSndpSetPan(D_801AE850, sp1C->unk31);
        }
        if (sp1C->unk1C & 2) {
            sp24 = (s32) (sp1C->unk2C * arg0->unk10) / 32767;
            alSndpSetVol(D_801AE850, (s16) sp24);
        }
        if (sp1C->unk1C & 0x10) {
            alSndpPlay(D_801AE850);
        }
    }
    sp1C->unk1C = 0;
}

void func_800BA9D4(void) {
    s32 sp24;

    switch (D_800E8CF0) { /* irregular */
        case 4:
            if (D_801AE824->state == 0) {
                D_801AE834 -= 1;
                if (D_801AE834 == 0) {
                    D_800E8CF0 = 1;
                }
            }
            break;
        case 2:
            if (D_801AE824->state == 0) {
                func_800BB3EC();
            }
            break;
    }
    if (D_801AE838 != -1) {
        if (D_800E8CF0 == 2) {
            func_800BB3EC();
        }
        if ((D_800EA5BC[D_801AE838].unk0 < D_801AE830) && (D_800E8CF0 == 1)) {
            D_801AE83C = D_801AE838;
            D_801AE838 = -1;
            sp24 = func_800B97E4(D_800EA5BC[D_801AE83C].unk0);
            alCSeqNew((ALCSeq*) D_801AE828, (u8*) D_801AE82C);
            alSeqpSetSeq((ALSeqPlayer*) D_801AE824, (ALSeq*) D_801AE828);
            alSeqpSetBank((ALSeqPlayer*) D_801AE824, D_801AE818);
            alSeqpPlay((ALSeqPlayer*) D_801AE824);
            D_800E8CF0 = 2;
        }
    }
    D_800E8CFC = 0;
    if (D_800E8CF0 == 2) {
        if (D_801AE840 < D_801AE84C) {
            D_801AE840 += D_801AE848;
            if (D_801AE840 >= D_801AE84C) {
                D_801AE840 = D_801AE84C;
            } else {
                D_800E8CFC = 0x10;
            }
        }
        if (D_801AE840 > D_801AE84C) {
            D_801AE840 -= D_801AE848;
            if (D_801AE840 <= D_801AE84C) {
                D_801AE840 = D_801AE84C;
                if ((D_801AE840 == 0) && (D_800E8CF8 & 1)) {
                    func_800BB3EC();
                }
            } else {
                D_800E8CFC = 0x10;
            }
        }
        if (D_801AE840 != D_801AE844) {
            D_801AE844 = D_801AE840;
            alSeqpSetVol((ALSeqPlayer*) D_801AE824, (s16) D_801AE840);
        }
    }
}

void func_800BAD4C(void) {
    D_801AE854 += 1;
    if (D_801AE854 & 1) {
        func_800BA9D4();
        func_800B9F10();
    }
}

s32 func_800BADA8(s32 arg0) {
    s32 sp1C;

    for (sp1C = 0; sp1C < 8; sp1C++) {
        if (D_801AE598[sp1C].unk4 == 0) {
            break;
        }
    }

    if (sp1C == 8) {
        return -1;
    }

    D_801AE598[sp1C].unk4 = 1;
    D_801AE678[sp1C].unk8 = arg0;
    D_801AE678[sp1C].unk18 = -1;
    D_801AE678[sp1C].unkC = D_800EA144[arg0].unk0;
    D_801AE678[sp1C].unk32 = D_800EA144[arg0].unk4;
    D_801AE678[sp1C].unk14 = D_801AE678[sp1C].unkC;
    D_801AE678[sp1C].unk4 = 1;
    D_801AE678[sp1C].unk2C = 0x7FFF;
    D_801AE678[sp1C].unk24 = 0x2710;
    D_801AE678[sp1C].unk28 = 0x2710;
    D_801AE678[sp1C].unk31 = 0x40;
    D_801AE678[sp1C].unk30 = 0;
    D_801AE598[sp1C].unk8 = 0x2710;
    D_801AE598[sp1C].unk1A = 0x40;
    D_801AE598[sp1C].unk1B = 0;
    D_801AE598[sp1C].unkC = 0x7FFF;
    D_801AE598[sp1C].unk18 = 0x7FFF;
    D_801AE598[sp1C].unk10 = 0x7FFF;
    D_801AE598[sp1C].unk14 = 0;

    if (D_801AE678[sp1C].unk32 != 0) {
        func_800BB16C((s16) D_801AE678[sp1C].unk32);
    }
    return sp1C;
}

void func_800BB16C(s16 arg0) {
    s32 sp1C;

    for (sp1C = 0; sp1C < 8; sp1C++) {
        if ((D_801AE598[sp1C].unk4 != 0)) {
            if ((D_801AE678[sp1C].unk32 == (u8) arg0)) {
                func_800BA1E8(&D_801AE678[sp1C]);
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
                func_800BA1E8(&D_801AE678[sp1C]);
                D_801AE598[sp1C].unk4 = 0;
            }
        }
    } else {
        for (sp1C = 0; sp1C < 8; sp1C++) {
            if ((D_801AE598[sp1C].unk4 != 0)) {
                if ((D_801AE678[sp1C].unk8 == arg0)) {
                    func_800BA1E8(&D_801AE678[sp1C]);
                    D_801AE598[sp1C].unk4 = 0;
                }
            }
        }
    }
    return 0;
}

void func_800BB3D4(s32 arg0) {
    D_801AE838 = arg0;
}

void func_800BB3EC(void) {
    if (D_800E8CF0 == 2) {
        alSeqpStop((ALSeqPlayer*) D_801AE824);
        D_800E8CF0 = 4;
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
        arg0->unk4 = (s32) (arg0->unk4 | (arg1 | 2));
    }
}

void func_800BB4DC(s32 arg0) {
    func_800BB24C(arg0);
}

void func_800BB50C(s32 arg0) {
    D_801AE840 = arg0;
    D_801AE84C = arg0;
}

void func_800BB52C(s32 arg0, u16 arg1, s16 arg2, u16 arg3) {
    if (arg0 != -1) {
        D_801AE840 = arg0;
    }
    D_801AE848 = arg1;
    D_801AE84C = (s32) arg2;
    D_800E8CF8 = arg3;
}

s32 func_800BB578(void) {
    return D_800E8CF0 | D_800E8CFC | D_800E8CF4;
}

// NEEDS RODATA
extern float D_800EFDC4;

// _depth2Cents
f32 func_800BB5AC(u8 depth) {
    f32 x = 1.03099303;
    f32 cents = 1.0;

    while (depth) {
        if (depth & 1)
            cents *= x;
        x *= x;
        depth >>= 1;
    }

    return (cents);
}

// Original name: initOsc
ALMicroTime AudioDriver_InitOsc(void** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay) {
    oscData* statePtr;
    ALMicroTime deltaTime = 0;

    if (D_801AE270) /* yes there are oscStates available */
    {
        statePtr = D_801AE270;
        D_801AE270 = D_801AE270->next;
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
                statePtr->data.vsin.depthcents = func_800BB5AC(oscDepth);
                statePtr->curCount = 0;
                statePtr->maxCount = 259 - oscRate; /* gives values 4-259 */
                *initVal = 1.0f;                    /* start at unity pitch */
                break;

            case VIBRATO_SQR: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                cents = func_800BB5AC(oscDepth);
                statePtr->data.vsqr.loRatio = alCents2Ratio(-cents);
                statePtr->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = statePtr->data.vsqr.hiRatio;
            } break;

            case VIBRATO_DSC_SAW: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                cents = func_800BB5AC(oscDepth);
                statePtr->data.vdsaw.hicents = cents;
                statePtr->data.vdsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(statePtr->data.vdsaw.hicents);
            } break;

            case VIBRATO_ASC_SAW: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                cents = func_800BB5AC(oscDepth);
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
    osc->next = D_801AE270;
    D_801AE270 = osc;
}

void func_800BC4CC(ALSeqpConfig* conf) {
    s32 sp4;
    oscData* sp0;

    D_801AE270 = D_801AE278;
    for (sp0 = D_801AE278, sp4 = 0; sp4 < 0x27; sp4++) {
        sp0->next = &D_801AE278[sp4 + 1];
        sp0 = sp0->next;
    }

    sp0->next = NULL;
    conf->initOsc = AudioDriver_InitOsc;
    conf->updateOsc = AudioDriver_UpdateOsc;
    conf->stopOsc = AudioDriver_StopOsc;
}
