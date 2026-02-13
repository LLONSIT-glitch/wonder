/*
 * @file audio_general.c
 * @brief Audio game specific functions
 */
#include "common.h"
#include "audio_driver.h"

/*
 * Plays a music track with max volume
 */
void AudioGeneral_PlayBGM(s32 bgmId) {
    gMusicSequenceId = bgmId;
    AudioDriver_ConfigSeqPlayerVolume(0, MAX_VOLUME, MAX_VOLUME, SEQ_PLAYER_CONTINUE);
    AudioDriver_UpdateSeqID(bgmId);
}

void AudioGeneral_BGMFadeOut(u16 fadeVol) {
    AudioDriver_ConfigSeqPlayerVolume(-1, MAX_VOLUME / fadeVol, 0, SEQ_PLAYER_STOP);
}

void AudioGeneral_BGMFadeIn(u16 fadeVol) {
    AudioDriver_ConfigSeqPlayerVolume(0, MAX_VOLUME / fadeVol, MAX_VOLUME, SEQ_PLAYER_CONTINUE);
}

void func_80021FF8(s32 vol, u16 adjVol, s32 maxVol) {
    AudioDriver_ConfigSeqPlayerVolume(vol, MAX_VOLUME / adjVol, maxVol, SEQ_PLAYER_CONTINUE);
}

s32 func_8002206C(s32 arg0, s32 arg1, u8 pan) {
    UnkStruct_801AE598* sp1C;

    sp1C = func_800BB448(arg0);
    if (sp1C == NULL) {
        return -1;
    }
    sp1C->unkC = arg1;
    sp1C->pan = pan;
    func_800BB4B4(sp1C, 4);
    return 0;
}

void func_800220F4(s32 arg0) {
    func_800BB4DC(arg0);
}

void func_80022124(void) {
    func_800BB4DC(-1);
}
