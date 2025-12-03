#include "common.h"

extern OSMesgQueue D_801AE1B8;
extern OSIoMesg D_801AE1D8;

void DmaCopy(u32 devAddr, void* vAddr, u32 nBytes) {
    osInvalDCache(vAddr, nBytes);
    osPiStartDma(&D_801AE1D8, 0, 0, devAddr, vAddr, nBytes, &D_801AE1B8);
    osRecvMesg(&D_801AE1B8, NULL, 1);
}
