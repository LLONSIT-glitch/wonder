#include <PR/libaudio.h>

void alCopy(void* source, void* destination, s32 length) {
    s32 index;
    u8* source_byte = (u8*) source;
    u8* destination_byte = (u8*) destination;

    for (index = 0; index < length; index++) {
        *destination_byte++ = *source_byte++;
    }
}
