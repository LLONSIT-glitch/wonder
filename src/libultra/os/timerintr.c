#include "common.h"
#include <PRinternal/osint.h>

OSTimer __osBaseTimer;
OSTime __osCurrentTime;
u32 __osBaseCounter;
u32 __osViIntrCount;
u32 __osTimerCounter;
OSTimer* __osTimerList = &__osBaseTimer;

void __osTimerServicesInit(void) {
    __osCurrentTime = 0;
    __osBaseCounter = 0;
    __osViIntrCount = 0;
    __osTimerList->next = __osTimerList->prev = __osTimerList;
    __osTimerList->interval = __osTimerList->value = 0;
    __osTimerList->mq = NULL;
    __osTimerList->msg = 0;
}

void __osTimerInterrupt(void) {
    OSTimer* timer;
    u32 count;
    u32 elapsed_cycles;

    if (__osTimerList->next == __osTimerList) {
        return;
    }

    for (;;) {
        timer = __osTimerList->next;

        if (timer == __osTimerList) {
            __osSetCompare(0);
            __osTimerCounter = 0;
            break;
        }

        count = osGetCount();
        elapsed_cycles = count - __osTimerCounter;
        __osTimerCounter = count;

        if (elapsed_cycles < timer->value) {
            timer->value -= elapsed_cycles;
            __osSetTimerIntr(timer->value);
            break;
        }

        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        timer->next = NULL;
        timer->prev = NULL;

        if (timer->mq != NULL) {
            osSendMesg(timer->mq, timer->msg, OS_MESG_NOBLOCK);
        }

        if (timer->interval != 0) {
            timer->value = timer->interval;
            __osInsertTimer(timer);
        }
    }
}

void __osSetTimerIntr(OSTime time) {
    OSTime new_time;
    u32 saved_mask;

    saved_mask = __osDisableInt();
    __osTimerCounter = osGetCount();
    new_time = __osTimerCounter + time;
    __osSetCompare(new_time);
    __osRestoreInt(saved_mask);
}

OSTime __osInsertTimer(OSTimer* timer) {
    OSTimer* timep;
    OSTime time;
    u32 saved_mask;

    saved_mask = __osDisableInt();
    timep = __osTimerList->next;
    time = timer->value;

    for (; timep != __osTimerList && time > timep->value; timep = timep->next) {
        time -= timep->value;
    }

    timer->value = time;

    if (timep != __osTimerList) {
        timep->value -= time;
    }

    timer->next = timep;
    timer->prev = timep->prev;
    timep->prev->next = timer;
    timep->prev = timer;
    __osRestoreInt(saved_mask);
    return time;
}
