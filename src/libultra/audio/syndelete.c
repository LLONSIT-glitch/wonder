#include "PR/libaudio.h"

void alSynDelete(ALSynth* driver) {
    driver->head = NULL;
}
