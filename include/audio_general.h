#ifndef AUDIO_GENERAL_H
#define AUDIO_GENERAL_H

void AudioGeneral_PlayBGM(s32 bgmId);
void AudioGeneral_BGMFadeOut(u16 arg0);
void AudioGeneral_BGMFadeIn(u16 arg0);
void func_80021FF8(s32 arg0, u16 arg1, s32 arg2);
s32 func_8002206C(s32 arg0, s32 arg1, u8 arg2);
void func_800220F4(s32 arg0);
void func_80022124(void);

#endif /* AUDIO_GENERAL_H */
