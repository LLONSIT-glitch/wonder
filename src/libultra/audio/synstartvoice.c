#include "synthInternals.h"

void alSynStartVoice(ALSynth* synth, ALVoice* voice, ALWaveTable* wave) {
    ALStartParam* update;
    ALFilter* filter;

    if (voice->pvoice) {
        update = (ALStartParam*) __allocParam();
        if (update) {
            update->delta = synth->paramSamples + voice->pvoice->offset;
            update->type = AL_FILTER_START_VOICE;
            update->wave = wave;
            update->next = 0;
            update->unity = voice->unityPitch;

            filter = voice->pvoice->channelKnob;
            (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
        }
    }
}
