#include "PR/os.h"
#include "PR/rcp.h"
#include "PRinternal/viint.h"

OSViMode osViModeMpalLan1 = {
    OS_VI_MPAL_LAN1,
    {
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_DIVOT_ON | VI_CTRL_ANTIALIAS_MODE_1 |
            VI_CTRL_PIXEL_ADV_3,
        WIDTH(320),
        BURST(57, 30, 5, 70),
        VSYNC(525),
        HSYNC(3089, 4),
        LEAP(3097, 3098),
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
