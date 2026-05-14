#include "synthInternals.h"

s32 alFxParam(void* filter, s32 param_id, void* param);

ALFxRef* alSynAllocFX(ALSynth* synth, s16 bus, ALSynConfig* config, ALHeap* heap) {
    alFxNew(&synth->auxBus[bus].fx[0], config, heap);
    alFxParam(&synth->auxBus[bus].fx[0], AL_FILTER_SET_SOURCE, &synth->auxBus[bus]);
    alMainBusParam(synth->mainBus, AL_FILTER_ADD_SOURCE, &synth->auxBus[bus].fx[0]);

    return (ALFxRef*) &synth->auxBus[bus].fx[0];
}
