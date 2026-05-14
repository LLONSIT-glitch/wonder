#include "PR/os_internal.h"

s32 (*__osHwIntTable[8])(void) = { 0 };

void __osSetHWIntrRoutine(OSHWIntr interrupt, s32 (*handler)(void)) {
    register u32 save_mask = __osDisableInt();

    __osHwIntTable[interrupt] = handler;
    __osRestoreInt(save_mask);
}
