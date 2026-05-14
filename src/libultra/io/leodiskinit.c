#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/os_libc.h"
#include "PR/rcp.h"

typedef struct Leo_Disk_Handle {
    OSPiHandle* next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 padding[3];
    u32 baseAddress;
    u32 speed;
    u8 transferInfo[0x5C];
} Leo_Disk_Handle;

Leo_Disk_Handle LeoDiskHandle ALIGNED(0x8);
OSPiHandle* __osCurrentHandle;

OSPiHandle* osLeoDiskInit(void) {
    u32 savedMask;

    LeoDiskHandle.type = DEVICE_TYPE_64DD;
    LeoDiskHandle.baseAddress = PHYS_TO_K1(PI_DOM2_ADDR1);
    LeoDiskHandle.latency = 3;
    LeoDiskHandle.pulse = 6;
    LeoDiskHandle.pageSize = 6;
    LeoDiskHandle.relDuration = 2;

    IO_WRITE(PI_BSD_DOM2_LAT_REG, LeoDiskHandle.latency);
    IO_WRITE(PI_BSD_DOM2_PWD_REG, LeoDiskHandle.pulse);
    IO_WRITE(PI_BSD_DOM2_PGS_REG, LeoDiskHandle.pageSize);
    IO_WRITE(PI_BSD_DOM2_RLS_REG, LeoDiskHandle.relDuration);

    bzero(&LeoDiskHandle.transferInfo, sizeof(LeoDiskHandle.transferInfo));

    savedMask = __osDisableInt();
    LeoDiskHandle.next = __osPiTable;
    __osPiTable = (OSPiHandle*) &LeoDiskHandle;
    __osCurrentHandle = (OSPiHandle*) &LeoDiskHandle;
    __osRestoreInt(savedMask);

    return (OSPiHandle*) &LeoDiskHandle;
}
