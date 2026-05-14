#include "synthInternals.h"
#include <os_internal.h>
#include <ultraerror.h>

void alSynSetFXMix(ALSynth* synth, ALVoice* voice, u8 fxmix) {
    ALParam* update;
    ALFilter* filter;

    if (voice->pvoice) {
        update = __allocParam();
        ALFailIf(update == NULL, ERR_ALSYN_NO_UPDATE);

        update->delta = synth->paramSamples + voice->pvoice->offset;
        update->type = AL_FILTER_SET_FXAMT;

        if (fxmix < 0) {
            update->data.i = -fxmix;
        } else {
            update->data.i = fxmix;
        }

        update->next = NULL;

        filter = voice->pvoice->channelKnob;
        (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
    }
}
