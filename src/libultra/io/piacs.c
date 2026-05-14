#include "PRinternal/macros.h"
#include "PR/os_internal.h"

#define PI_Q_BUF_LEN 1

u32 __osPiAccessQueueEnabled = 0;
static OSMesg piAccessBuf[PI_Q_BUF_LEN] ALIGNED(0x8);
OSMesgQueue __osPiAccessQueue ALIGNED(0x8);

void __osPiCreateAccessQueue(void) {
    __osPiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osPiAccessQueue, piAccessBuf, PI_Q_BUF_LEN);
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osPiGetAccess(void) {
    OSMesg dummy_mesg;

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }

    osRecvMesg(&__osPiAccessQueue, &dummy_mesg, OS_MESG_BLOCK);
}

void __osPiRelAccess(void) {
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
