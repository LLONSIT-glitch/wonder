#include "PR/os.h"
#include "PR/rcp.h"
#include "PRinternal/viint.h"

OSViMode osViModeNtscLan1 = {
    OS_VI_NTSC_LAN1,
    {
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_DIVOT_ON | VI_CTRL_ANTIALIAS_MODE_1 |
            VI_CTRL_PIXEL_ADV_3,
        WIDTH(320),
        BURST(57, 34, 5, 62),
        VSYNC(525),
        HSYNC(3093, 0),
        LEAP(3093, 3093),
        HSTART(108, 748),
        SCALE(2, 0),
        VCURRENT(0),
    },
    {
        {
            ORIGIN(640),
            SCALE(1, 0),
            HSTART(37, 511),
            BURST(4, 2, 14, 0),
            VINTR(2),
        },
        {
            ORIGIN(640),
            SCALE(1, 0),
            HSTART(37, 511),
            BURST(4, 2, 14, 0),
            VINTR(2),
        },
    },
};
