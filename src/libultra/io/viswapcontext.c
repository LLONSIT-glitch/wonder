#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PRinternal/viint.h"

void __osViSwapContext(void) {
    register OSViMode* mode;
    register __OSViContext* context;
    u32 origin;
    u32 h_start;
    u32 y_scale;
    u32 field;

    field = 0;
    context = __osViNext;
    mode = context->modep;

    field = IO_READ(VI_CURRENT_REG) & 1;

    origin = osVirtualToPhysical(context->framep) + mode->fldRegs[field].origin;
    if (context->state & VI_STATE_XSCALE_UPDATED) {
        context->x.scale |= mode->comRegs.xScale & ~VI_SCALE_MASK;
    } else {
        context->x.scale = mode->comRegs.xScale;
    }

    if (context->state & VI_STATE_YSCALE_UPDATED) {
        y_scale = mode->fldRegs[field].yScale & VI_SCALE_MASK;
        context->y.scale = context->y.factor * y_scale;
        context->y.scale |= mode->fldRegs[field].yScale & ~VI_SCALE_MASK;
    } else {
        context->y.scale = mode->fldRegs[field].yScale;
    }

    h_start = mode->comRegs.hStart;
    if (context->state & VI_STATE_BLACK) {
        h_start = 0;
    }

    if (context->state & VI_STATE_REPEATLINE) {
        context->y.scale = 0;
        origin = osVirtualToPhysical(context->framep);
    }

    if (context->state & VI_STATE_FADE) {
        context->y.scale = (context->y.offset << VI_SUBPIXEL_SH) & (VI_2_10_FPART_MASK << VI_SUBPIXEL_SH);
        origin = osVirtualToPhysical(context->framep);
    }

    IO_WRITE(VI_ORIGIN_REG, origin);
    IO_WRITE(VI_WIDTH_REG, mode->comRegs.width);
    IO_WRITE(VI_BURST_REG, mode->comRegs.burst);
    IO_WRITE(VI_V_SYNC_REG, mode->comRegs.vSync);
    IO_WRITE(VI_H_SYNC_REG, mode->comRegs.hSync);
    IO_WRITE(VI_LEAP_REG, mode->comRegs.leap);
    IO_WRITE(VI_H_START_REG, h_start);
    IO_WRITE(VI_V_START_REG, mode->fldRegs[field].vStart);
    IO_WRITE(VI_V_BURST_REG, mode->fldRegs[field].vBurst);
    IO_WRITE(VI_INTR_REG, mode->fldRegs[field].vIntr);
    IO_WRITE(VI_X_SCALE_REG, context->x.scale);
    IO_WRITE(VI_Y_SCALE_REG, context->y.scale);
    IO_WRITE(VI_CONTROL_REG, context->control);

    __osViNext = __osViCurr;
    __osViCurr = context;
    *__osViNext = *__osViCurr;
}
