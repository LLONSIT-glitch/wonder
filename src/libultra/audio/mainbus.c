#include "synthInternals.h"

Acmd* alMainBusPull(void* filter, s16* out, s32 out_count, s32 sample_offset, Acmd* commands) {
    Acmd* ptr = commands;
    ALMainBus* bus = (ALMainBus*) filter;
    ALFilter** sources = bus->sources;
    s32 index;

    aClearBuffer(ptr++, AL_MAIN_L_OUT, out_count << 1);
    aClearBuffer(ptr++, AL_MAIN_R_OUT, out_count << 1);

    for (index = 0; index < bus->sourceCount; index++) {
        ptr = (*sources[index]->handler)(sources[index], out, out_count, sample_offset, ptr);
        aSetBuffer(ptr++, 0, 0, 0, out_count << 1);
        aMix(ptr++, 0, 0x7FFF, AL_AUX_L_OUT, AL_MAIN_L_OUT);
        aMix(ptr++, 0, 0x7FFF, AL_AUX_R_OUT, AL_MAIN_R_OUT);
    }

    return ptr;
}

s32 alMainBusParam(void* filter, s32 param_id, void* param) {
    ALMainBus* bus = (ALMainBus*) filter;
    ALFilter** sources = bus->sources;

    if (param_id == AL_FILTER_ADD_SOURCE) {
        sources[bus->sourceCount] = (ALFilter*) param;
        bus->sourceCount++;
    }

    return 0;
}
