#include "PR/os_internal.h"
#include "PRinternal/osint.h"

struct __osThreadTail __osThreadTail = { NULL, -1 };
OSThread* __osRunQueue = (OSThread*) &__osThreadTail;
OSThread* __osActiveQueue = (OSThread*) &__osThreadTail;
OSThread* __osRunningThread = NULL;
OSThread* __osFaultedThread = NULL;
static u64 sThreadDataPadding = 0;

OSThread __osThreadSave;

void __osDequeueThread(register OSThread** queue, register OSThread* thread) {
    register OSThread* pred;
    register OSThread* succ;

    pred = (OSThread*) queue;
    succ = pred->next;

    while (succ != NULL) {
        if (succ == thread) {
            pred->next = thread->next;
            return;
        }
        pred = succ;
        succ = pred->next;
    }
}
