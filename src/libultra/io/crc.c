#include "common.h"

u8 __osContAddressCrc(u16 address) {
    u8 temp = 0;
    u8 temp2;
    s32 index;

    for (index = 0; index < 16; index++) {
        temp2 = (temp & 0x10) ? 0x15 : 0;

        temp <<= 1;
        temp |= (u8) ((address & 0x400) ? 1 : 0);
        address <<= 1;
        temp ^= temp2;
    }

    return temp & 0x1f;
}

u8 __osContDataCrc(u8* data) {
    u8 temp = 0;
    u8 temp2;
    s32 index;
    s32 jndex;

    for (index = 0; index <= 32; index++) {
        for (jndex = 7; jndex > -1; jndex--) {
            temp2 = (temp & 0x80) ? 0x85 : 0;

            temp <<= 1;

            if (index == 32) {
                temp &= -1;
            } else {
                temp |= ((*data & (1 << jndex)) ? 1 : 0);
            }

            temp ^= temp2;
        }
        data++;
    }
    return temp;
}
