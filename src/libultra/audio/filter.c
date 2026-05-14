#include "synthInternals.h"

void alFilterNew(ALFilter* filter, ALCmdHandler handler, ALSetParam set_param, s32 type) {
    filter->source = 0;
    filter->handler = handler;
    filter->setParam = set_param;
    filter->inp = 0;
    filter->outp = 0;
    filter->type = type;
}
