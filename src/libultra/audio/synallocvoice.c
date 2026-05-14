#include "synthInternals.h"

s32 _allocatePVoice(ALSynth* synth, PVoice** pvoice, s16 priority);

s32 _allocatePVoice(ALSynth* synth, PVoice** pvoice, s16 priority) {
    ALLink* link;
    PVoice* physical_voice;
    s32 stolen = 0;

    if ((link = synth->pLameList.next) != 0) {
        *pvoice = (PVoice*) link;
        alUnlink(link);
        alLink(link, &synth->pAllocList);
    } else if ((link = synth->pFreeList.next) != 0) {
        *pvoice = (PVoice*) link;
        alUnlink(link);
        alLink(link, &synth->pAllocList);
    } else {
        for (link = synth->pAllocList.next; link != 0; link = link->next) {
            physical_voice = (PVoice*) link;

            if ((physical_voice->vvoice->priority <= priority) && (physical_voice->offset == 0)) {
                *pvoice = physical_voice;
                priority = physical_voice->vvoice->priority;
                stolen = 1;
            }
        }
    }

    return stolen;
}

s32 alSynAllocVoice(ALSynth* synth, ALVoice* voice, ALVoiceConfig* config) {
    PVoice* pvoice = 0;
    ALFilter* filter;
    ALParam* update;
    s32 stolen;

    voice->priority = config->priority;
    voice->unityPitch = config->unityPitch;
    voice->table = 0;
    voice->fxBus = config->fxBus;
    voice->state = AL_STOPPED;
    voice->pvoice = 0;

    stolen = _allocatePVoice(synth, &pvoice, config->priority);

    if (pvoice) {
        filter = pvoice->channelKnob;

        if (stolen) {
            pvoice->offset = 512;
            pvoice->vvoice->pvoice = 0;

            update = __allocParam();
            update->delta = synth->paramSamples;
            update->type = AL_FILTER_SET_VOLUME;
            update->data.i = 0;
            update->moredata.i = pvoice->offset - 64;
            (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);

            update = __allocParam();
            if (update) {
                update->delta = synth->paramSamples + pvoice->offset;
                update->type = AL_FILTER_STOP_VOICE;
                update->next = 0;
                (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
            }
        } else {
            pvoice->offset = 0;
        }

        pvoice->vvoice = voice;
        voice->pvoice = pvoice;
    }

    return pvoice != 0;
}
