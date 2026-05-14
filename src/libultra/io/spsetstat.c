#include "PR/rcp.h"
#include "PR/os_internal.h"

void __osSpSetStatus(u32 data) {
    IO_WRITE(SP_STATUS_REG, data);
}
