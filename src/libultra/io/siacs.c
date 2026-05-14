#include "PR/os_internal.h"
#include "PRinternal/macros.h"

#define SI_Q_BUF_LEN 1

u32 __osSiAccessQueueEnabled = 0;
static OSMesg siAccessBuf[SI_Q_BUF_LEN] ALIGNED(0x8);
OSMesgQueue __osSiAccessQueue ALIGNED(0x8);

void __osSiCreateAccessQueue(void) {
    __osSiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osSiAccessQueue, siAccessBuf, SI_Q_BUF_LEN);
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
    OSMesg dummy_mesg;

    if (!__osSiAccessQueueEnabled) {
        __osSiCreateAccessQueue();
    }

    osRecvMesg(&__osSiAccessQueue, &dummy_mesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
