#include "PR/os.h"
#include "PR/rcp.h"
#include "PRinternal/viint.h"

OSViMode osViModePalLan1 = {
    OS_VI_PAL_LAN1,
    {
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_DIVOT_ON | VI_CTRL_ANTIALIAS_MODE_1 |
            VI_CTRL_PIXEL_ADV_3,
        WIDTH(320),
        0x0404233A,
        VSYNC(625),
        0x00150C69,
        0x0C6F0C6E,
        HSTART(128, 768),
        SCALE(2, 0),
        VCURRENT(0),
    },
    {
        {
            ORIGIN(640),
            SCALE(1, 0),
            HSTART(95, 569),
            BURST(107, 2, 9, 0),
            VINTR(2),
        },
        {
            ORIGIN(640),
            SCALE(1, 0),
            HSTART(95, 569),
            BURST(107, 2, 9, 0),
            VINTR(2),
        },
    },
};
