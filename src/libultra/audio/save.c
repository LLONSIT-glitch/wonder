#include "synthInternals.h"

Acmd* alSavePull(void* filter, s16* out, s32 out_count, s32 sample_offset, Acmd* commands) {
    ALSave* save = (ALSave*) filter;
    ALFilter* source = save->filter.source;

    commands = (*source->handler)(source, out, out_count, sample_offset, commands);

    aSetBuffer(commands++, 0, 0, 0, out_count << 1);
    aInterleave(commands++, AL_MAIN_L_OUT, AL_MAIN_R_OUT);
    aSetBuffer(commands++, 0, 0, 0, out_count << 2);
    aSaveBuffer(commands++, save->dramout);

    return commands;
}

s32 alSaveParam(void* filter, s32 param_id, void* param) {
    ALSave* save = (ALSave*) filter;
    ALFilter* filter_base = (ALFilter*) filter;

    switch (param_id) {
        case AL_FILTER_SET_SOURCE:
            filter_base->source = (ALFilter*) param;
            break;

        case AL_FILTER_SET_DRAM:
            save->dramout = (s32) param;
            break;

        default:
            break;
    }

    return 0;
}
