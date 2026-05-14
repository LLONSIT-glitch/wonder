#include "synthInternals.h"
#include <os_internal.h>
#include <ultraerror.h>

void alSynSetPitch(ALSynth* synth, ALVoice* voice, f32 pitch) {
    ALParam* update;
    ALFilter* filter;

    if (voice->pvoice) {
        update = __allocParam();
        ALFailIf(update == NULL, ERR_ALSYN_NO_UPDATE);

        update->delta = synth->paramSamples + voice->pvoice->offset;
        update->type = AL_FILTER_SET_PITCH;
        update->data.f = pitch;
        update->next = NULL;

        filter = voice->pvoice->channelKnob;
        (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
    }
}
