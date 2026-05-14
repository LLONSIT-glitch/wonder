#include "synthInternals.h"

void alSynFreeVoice(ALSynth* synth, ALVoice* voice) {
    ALFilter* filter;
    ALFreeParam* update;

    if (voice->pvoice) {
        if (voice->pvoice->offset) {
            update = (ALFreeParam*) __allocParam();
            if (!update) {
                return;
            }

            update->delta = synth->paramSamples + voice->pvoice->offset;
            update->type = AL_FILTER_FREE_VOICE;
            update->pvoice = voice->pvoice;

            filter = voice->pvoice->channelKnob;
            (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
        } else {
            _freePVoice(synth, voice->pvoice);
        }

        voice->pvoice = 0;
    }
}
