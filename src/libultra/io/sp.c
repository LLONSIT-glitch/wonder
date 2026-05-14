#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/sptask.h"
#include "PRinternal/osint.h"

int __osSpDeviceBusy(void) {
    register u32 status = IO_READ(SP_STATUS_REG);

    if (status & (SP_STATUS_DMA_BUSY | SP_STATUS_DMA_FULL | SP_STATUS_IO_FULL)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
