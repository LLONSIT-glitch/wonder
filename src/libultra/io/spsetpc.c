#include "PR/rcp.h"
#include "PR/os_internal.h"

s32 __osSpSetPc(u32 program_counter) {
    register u32 status = IO_READ(SP_STATUS_REG);

    if (!(status & SP_STATUS_HALT)) {
        return -1;
    }

    IO_WRITE(SP_PC_REG, program_counter);

    return 0;
}
