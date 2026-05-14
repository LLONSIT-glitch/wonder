#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"
#include "PRinternal/viint.h"

int osSetTimer(OSTimer* timer, OSTime countdown, OSTime interval, OSMesgQueue* message_queue, OSMesg message) {
    OSTime time;

    timer->next = NULL;
    timer->prev = NULL;
    timer->interval = interval;
    timer->value = (countdown != 0) ? countdown : interval;
    timer->mq = message_queue;
    timer->msg = message;

    time = __osInsertTimer(timer);
    if (__osTimerList->next == timer) {
        __osSetTimerIntr(time);
    }

    return 0;
}
