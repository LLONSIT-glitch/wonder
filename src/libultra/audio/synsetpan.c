#include "synthInternals.h"
#include <os_internal.h>
#include <ultraerror.h>

void alSynSetPan(ALSynth* synth, ALVoice* voice, ALPan pan) {
    ALParam* update;
    ALFilter* filter;

    if (voice->pvoice) {
        update = __allocParam();
        ALFailIf(update == NULL, ERR_ALSYN_NO_UPDATE);

        update->delta = synth->paramSamples + voice->pvoice->offset;
        update->type = AL_FILTER_SET_PAN;
        update->data.i = pan;
        update->next = NULL;

        filter = voice->pvoice->channelKnob;
        (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
    }
}
