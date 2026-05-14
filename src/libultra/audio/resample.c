#include <PR/os.h>

#include "synthInternals.h"

Acmd* alResamplePull(void* filter, s16* out, s32 out_count, s32 sample_offset, Acmd* commands) {
    ALResampler* resampler = (ALResampler*) filter;
    Acmd* ptr = commands;
    s16 input;
    s32 input_count;
    ALFilter* source = resampler->filter.source;
    s32 increment;
    f32 float_input_count;

    input = AL_DECODER_OUT;

    if (!out_count) {
        return ptr;
    }

    if (resampler->upitch) {
        ptr = (*source->handler)(source, &input, out_count, sample_offset, commands);
        aDMEMMove(ptr++, input, *out, out_count << 1);
    } else {
        if (resampler->ratio > MAX_RATIO) {
            resampler->ratio = MAX_RATIO;
        }

        resampler->ratio = (s32) (resampler->ratio * UNITY_PITCH);
        resampler->ratio = resampler->ratio / UNITY_PITCH;

        float_input_count = resampler->delta + (resampler->ratio * (f32) out_count);
        input_count = (s32) float_input_count;
        resampler->delta = float_input_count - (f32) input_count;

        ptr = (*source->handler)(source, &input, input_count, sample_offset, commands);

        increment = (s32) (resampler->ratio * UNITY_PITCH);
        aSetBuffer(ptr++, 0, input, *out, out_count << 1);
        aResample(ptr++, resampler->first, increment, osVirtualToPhysical(resampler->state));
        resampler->first = 0;
    }

    return ptr;
}

s32 alResampleParam(void* filter, s32 param_id, void* param) {
    ALFilter* filter_base = (ALFilter*) filter;
    ALResampler* resampler = (ALResampler*) filter;
    union {
        f32 float_value;
        s32 int_value;
    } data;

    switch (param_id) {
        case AL_FILTER_SET_SOURCE:
            filter_base->source = (ALFilter*) param;
            break;

        case AL_FILTER_RESET:
            resampler->delta = 0.0f;
            resampler->first = 1;
            resampler->motion = AL_STOPPED;
            resampler->upitch = 0;
            if (filter_base->source) {
                (*filter_base->source->setParam)(filter_base->source, AL_FILTER_RESET, 0);
            }
            break;

        case AL_FILTER_START:
            resampler->motion = AL_PLAYING;
            if (filter_base->source) {
                (*filter_base->source->setParam)(filter_base->source, AL_FILTER_START, 0);
            }
            break;

        case AL_FILTER_SET_PITCH:
            data.int_value = (s32) param;
            resampler->ratio = data.float_value;
            break;

        case AL_FILTER_SET_UNITY_PITCH:
            resampler->upitch = 1;
            break;

        default:
            if (filter_base->source) {
                (*filter_base->source->setParam)(filter_base->source, param_id, param);
            }
            break;
    }

    return 0;
}
