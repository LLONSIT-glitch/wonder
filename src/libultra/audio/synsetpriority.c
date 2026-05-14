#include <PR/libaudio.h>

void alSynSetPriority(ALSynth* synth, ALVoice* voice, s16 priority) {
    voice->priority = priority;
}
