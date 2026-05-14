#include "synthInternals.h"

void alSynStartVoiceParams(ALSynth* synth, ALVoice* voice, ALWaveTable* wave, f32 pitch, s16 volume, ALPan pan,
                           u8 fx_mix, ALMicroTime delta) {
    ALStartParamAlt* update;
    ALFilter* filter;

    if (voice->pvoice) {
        update = (ALStartParamAlt*) __allocParam();
        if (update) {
            if (fx_mix < 0) {
                fx_mix = -fx_mix;
            }

            update->delta = synth->paramSamples + voice->pvoice->offset;
            update->next = 0;
            update->type = AL_FILTER_START_VOICE_ALT;
            update->unity = voice->unityPitch;
            update->pan = pan;
            update->volume = volume;
            update->fxMix = fx_mix;
            update->pitch = pitch;
            update->samples = _timeToSamples(synth, delta);
            update->wave = wave;

            filter = voice->pvoice->channelKnob;
            (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
        }
    }
}
