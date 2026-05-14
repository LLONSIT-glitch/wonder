#include <PR/os.h>
#include "synthInternals.h"

#define RANGE 2.0
#define CONVERT 173123.404906676

#define INPUT_PARAM 0
#define OUTPUT_PARAM 1
#define FBCOEF_PARAM 2
#define FFCOEF_PARAM 3
#define GAIN_PARAM 4
#define CHORUSRATE_PARAM 5
#define CHORUSDEPTH_PARAM 6
#define LPFILT_PARAM 7

#define SWAP(in, out)   \
    {                   \
        s16 temp = out; \
        out = in;       \
        in = temp;      \
    }

extern ALGlobals* alGlobals;

void _init_lpfilter(ALLowPass* low_pass);
Acmd* _loadOutputBuffer(ALFx* fx, ALDelay* delay, s32 buffer, s32 input_count, Acmd* cmd);
Acmd* _loadBuffer(ALFx* fx, s16* current_ptr, s32 buffer, s32 count, Acmd* cmd);
Acmd* _saveBuffer(ALFx* fx, s16* current_ptr, s32 buffer, s32 count, Acmd* cmd);
Acmd* _filterBuffer(ALLowPass* low_pass, s32 buffer, s32 count, Acmd* cmd);
f32 _doModFunc(ALDelay* delay, s32 count);

Acmd* alFxPull(void* filter, s16* outp, s32 out_count, s32 sample_offset, Acmd* cmd) {
    Acmd* ptr = cmd;
    ALFx* fx = (ALFx*) filter;
    ALFilter* source = fx->filter.source;
    s16 section_index;
    s16 buffer1;
    s16 buffer2;
    s16 input;
    s16 output;
    s16* input_ptr;
    s16* output_ptr;
    s16 gain;
    s16* previous_output_ptr = 0;
    ALDelay* delay;
    ALDelay* previous_delay;

    ptr = (*source->handler)(source, outp, out_count, sample_offset, cmd);

    input = AL_AUX_L_OUT;
    output = AL_AUX_R_OUT;
    buffer1 = AL_TEMP_0;
    buffer2 = AL_TEMP_1;

    aSetBuffer(ptr++, 0, 0, 0, out_count << 1);
    aMix(ptr++, 0, 0xDA83, AL_AUX_L_OUT, input);
    aMix(ptr++, 0, 0x5A82, AL_AUX_R_OUT, input);
    ptr = _saveBuffer(fx, fx->input, input, out_count, ptr);

    aClearBuffer(ptr++, output, out_count << 1);

    for (section_index = 0; section_index < fx->section_count; section_index++) {
        delay = &fx->delay[section_index];
        input_ptr = &fx->input[-delay->input];
        output_ptr = &fx->input[-delay->output];

        if (input_ptr == previous_output_ptr) {
            SWAP(buffer1, buffer2);
        } else {
            ptr = _loadBuffer(fx, input_ptr, buffer1, out_count, ptr);
        }

        ptr = _loadOutputBuffer(fx, delay, buffer2, out_count, ptr);

        if (delay->ffcoef) {
            aMix(ptr++, 0, (u16) delay->ffcoef, buffer1, buffer2);
            if (!delay->rs && !delay->lp) {
                ptr = _saveBuffer(fx, output_ptr, buffer2, out_count, ptr);
            }
        }

        if (delay->fbcoef) {
            aMix(ptr++, 0, (u16) delay->fbcoef, buffer2, buffer1);
            ptr = _saveBuffer(fx, input_ptr, buffer1, out_count, ptr);
        }

        if (delay->lp) {
            ptr = _filterBuffer(delay->lp, buffer2, out_count, ptr);
        }

        if (!delay->rs) {
            ptr = _saveBuffer(fx, output_ptr, buffer2, out_count, ptr);
        }

        if (delay->gain) {
            aMix(ptr++, 0, (u16) delay->gain, buffer2, output);
        }

        previous_output_ptr = &fx->input[delay->output];
    }

    fx->input += out_count;
    if (fx->input > &fx->base[fx->length]) {
        fx->input -= fx->length;
    }

    aDMEMMove(ptr++, output, AL_AUX_L_OUT, out_count << 1);

    return ptr;
}

s32 alFxParam(void* filter, s32 param_id, void* param) {
    if (param_id == AL_FILTER_SET_SOURCE) {
        ((ALFilter*) filter)->source = (ALFilter*) param;
    }

    return 0;
}

s32 alFxParamHdl(void* filter, s32 param_id, void* param) {
    ALFx* fx = (ALFx*) filter;
    s32 param_slot = (param_id - 2) % 8;
    s32 section = (param_id - 2) / 8;
    s32 value = *(s32*) param;

    switch (param_slot) {
        case INPUT_PARAM:
            fx->delay[section].input = (u32) value & 0xFFFFFFF8;
            break;

        case OUTPUT_PARAM:
            fx->delay[section].output = (u32) value & 0xFFFFFFF8;
            break;

        case FFCOEF_PARAM:
            fx->delay[section].ffcoef = (s16) value;
            break;

        case FBCOEF_PARAM:
            fx->delay[section].fbcoef = (s16) value;
            break;

        case GAIN_PARAM:
            fx->delay[section].gain = (s16) value;
            break;

        case CHORUSRATE_PARAM:
            fx->delay[section].rsinc = ((((f32) value) / 1000) * RANGE) / alGlobals->drvr.outputRate;
            break;

        case CHORUSDEPTH_PARAM:
            fx->delay[section].rsgain =
                (((f32) value) / CONVERT) * (fx->delay[section].output - fx->delay[section].input);
            break;

        case LPFILT_PARAM:
            if (fx->delay[section].lp) {
                fx->delay[section].lp->fc = (s16) value;
                _init_lpfilter(fx->delay[section].lp);
            }
            break;
    }

    return 0;
}

Acmd* _loadOutputBuffer(ALFx* fx, ALDelay* delay, s32 buffer, s32 input_count, Acmd* cmd) {
    Acmd* ptr = cmd;
    s32 ratio;
    s32 count;
    s32 resample_buffer = AL_TEMP_2;
    s16* output_ptr;
    f32 float_input_count;
    f32 float_ratio;
    f32 delta;
    s32 ram_align = 0;
    s32 length;

    if (delay->rs) {
        length = delay->output - delay->input;
        delta = _doModFunc(delay, input_count);
        delta /= length;
        delta = (s32) (delta * UNITY_PITCH);
        delta = delta / UNITY_PITCH;
        float_ratio = 1.0 - delta;

        float_input_count = delay->rs->delta + (float_ratio * (f32) input_count);
        count = (s32) float_input_count;
        delay->rs->delta = float_input_count - (f32) count;

        output_ptr = &fx->input[-(delay->output - delay->rsdelta)];
        ram_align = ((s32) output_ptr & 0x7) >> 1;
        ptr = _loadBuffer(fx, output_ptr - ram_align, resample_buffer, count + ram_align, ptr);

        ratio = (s32) (float_ratio * UNITY_PITCH);
        aSetBuffer(ptr++, 0, resample_buffer + (ram_align << 1), buffer, input_count << 1);
        aResample(ptr++, delay->rs->first, ratio, osVirtualToPhysical(delay->rs->state));

        delay->rs->first = 0;
        delay->rsdelta += count - input_count;
    } else {
        output_ptr = &fx->input[-delay->output];
        ptr = _loadBuffer(fx, output_ptr, buffer, input_count, ptr);
    }

    return ptr;
}

Acmd* _loadBuffer(ALFx* fx, s16* current_ptr, s32 buffer, s32 count, Acmd* cmd) {
    Acmd* ptr = cmd;
    s32 after_end;
    s32 before_end;
    s16* updated_ptr;
    s16* delay_end;

    delay_end = &fx->base[fx->length];

    if (current_ptr < fx->base) {
        current_ptr += fx->length;
    }

    updated_ptr = current_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - current_ptr;

        aSetBuffer(ptr++, 0, buffer, 0, before_end << 1);
        aLoadBuffer(ptr++, osVirtualToPhysical(current_ptr));
        aSetBuffer(ptr++, 0, buffer + (before_end << 1), 0, after_end << 1);
        aLoadBuffer(ptr++, osVirtualToPhysical(fx->base));
    } else {
        aSetBuffer(ptr++, 0, buffer, 0, count << 1);
        aLoadBuffer(ptr++, osVirtualToPhysical(current_ptr));
    }

    aSetBuffer(ptr++, 0, 0, 0, count << 1);

    return ptr;
}

Acmd* _saveBuffer(ALFx* fx, s16* current_ptr, s32 buffer, s32 count, Acmd* cmd) {
    Acmd* ptr = cmd;
    s32 after_end;
    s32 before_end;
    s16* updated_ptr;
    s16* delay_end;

    delay_end = &fx->base[fx->length];

    if (current_ptr < fx->base) {
        current_ptr += fx->length;
    }

    updated_ptr = current_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - current_ptr;

        aSetBuffer(ptr++, 0, 0, buffer, before_end << 1);
        aSaveBuffer(ptr++, osVirtualToPhysical(current_ptr));
        aSetBuffer(ptr++, 0, 0, buffer + (before_end << 1), after_end << 1);
        aSaveBuffer(ptr++, osVirtualToPhysical(fx->base));
        aSetBuffer(ptr++, 0, 0, 0, count << 1);
    } else {
        aSetBuffer(ptr++, 0, 0, buffer, count << 1);
        aSaveBuffer(ptr++, osVirtualToPhysical(current_ptr));
    }

    return ptr;
}

Acmd* _filterBuffer(ALLowPass* low_pass, s32 buffer, s32 count, Acmd* cmd) {
    Acmd* ptr = cmd;

    aSetBuffer(ptr++, 0, buffer, buffer, count << 1);
    aLoadADPCM(ptr++, 32, osVirtualToPhysical(low_pass->fcvec.fccoef));
    aPoleFilter(ptr++, low_pass->first, low_pass->fgain, osVirtualToPhysical(low_pass->fstate));
    low_pass->first = 0;

    return ptr;
}

f32 _doModFunc(ALDelay* delay, s32 count) {
    f32 value;

    delay->rsval += delay->rsinc * count;
    delay->rsval = (delay->rsval > RANGE) ? delay->rsval - (RANGE * 2) : delay->rsval;

    value = delay->rsval;
    value = (value < 0) ? -value : value;
    value -= RANGE / 2;

    return delay->rsgain * value;
}
