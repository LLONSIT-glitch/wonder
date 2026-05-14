#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PRinternal/osint.h"

int __osDpDeviceBusy(void) {
    register u32 status = IO_READ(DPC_STATUS_REG);

    if (status & DPC_STATUS_DMA_BUSY) {
        return TRUE;
    } else {
        return FALSE;
    }
}
