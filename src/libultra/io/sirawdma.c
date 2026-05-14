#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PRinternal/siint.h"

s32 __osSiRawStartDma(s32 direction, void* dram_address) {
    if (__osSiDeviceBusy()) {
        return -1;
    }

    if (direction == OS_WRITE) {
        osWritebackDCache(dram_address, 64);
    }

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dram_address));

    if (direction == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, PIF_RAM_START);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, PIF_RAM_START);
    }

    if (direction == OS_READ) {
        osInvalDCache(dram_address, 64);
    }

    return 0;
}
