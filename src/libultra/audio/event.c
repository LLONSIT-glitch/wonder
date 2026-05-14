#include "synthInternals.h"
#include <os_internal.h>

void alSynStopVoice(ALSynth* synth, ALVoice* voice) {
    ALParam* update;
    ALFilter* filter;

    if (voice->pvoice) {
        update = __allocParam();
        if (!update) {
            return;
        }

        update->delta = synth->paramSamples + voice->pvoice->offset;
        update->type = AL_FILTER_STOP_VOICE;
        update->next = NULL;

        filter = voice->pvoice->channelKnob;
        (*filter->setParam)(filter, AL_FILTER_ADD_UPDATE, update);
    }
}

void alSynAddPlayer(ALSynth* synth, ALPlayer* client) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    client->samplesLeft = synth->curSamples;
    client->next = synth->head;
    synth->head = client;
    osSetIntMask(mask);
}

void alEvtqNew(ALEventQueue* evtq, ALEventListItem* items, s32 item_count) {
    s32 index;

    evtq->eventCount = 0;
    evtq->allocList.next = NULL;
    evtq->allocList.prev = NULL;
    evtq->freeList.next = NULL;
    evtq->freeList.prev = NULL;

    for (index = 0; index < item_count; index++) {
        alLink((ALLink*) &items[index], &evtq->freeList);
    }
}

ALMicroTime alEvtqNextEvent(ALEventQueue* evtq, ALEvent* evt) {
    ALEventListItem* item;
    ALMicroTime delta;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    item = (ALEventListItem*) evtq->allocList.next;

    if (item) {
        alUnlink((ALLink*) item);
        alCopy(&item->evt, evt, sizeof(*evt));
        alLink((ALLink*) item, &evtq->freeList);
        delta = item->delta;
    } else {
        evt->type = -1;
        delta = 0;
    }

    osSetIntMask(mask);
    return delta;
}

void alEvtqPostEvent(ALEventQueue* evtq, ALEvent* evt, ALMicroTime delta) {
    ALEventListItem* item;
    ALEventListItem* next_item;
    ALLink* node;
    s32 post_at_end;
    OSIntMask mask;

    post_at_end = 0;
    mask = osSetIntMask(OS_IM_NONE);
    item = (ALEventListItem*) evtq->freeList.next;

    if (!item) {
        osSetIntMask(mask);
        return;
    }

    alUnlink((ALLink*) item);
    alCopy(evt, &item->evt, sizeof(*evt));

    if (delta == AL_EVTQ_END) {
        post_at_end = -1;
    }

    for (node = &evtq->allocList; node != NULL; node = node->next) {
        if (!node->next) {
            if (post_at_end) {
                item->delta = 0;
            } else {
                item->delta = delta;
            }

            alLink((ALLink*) item, node);
            break;
        } else {
            next_item = (ALEventListItem*) node->next;

            if (delta < next_item->delta) {
                item->delta = delta;
                next_item->delta -= delta;
                alLink((ALLink*) item, node);
                break;
            }

            delta -= next_item->delta;
        }
    }

    osSetIntMask(mask);
}

void alEvtqFlush(ALEventQueue* evtq) {
    ALLink* this_node;
    ALLink* next_node;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    this_node = evtq->allocList.next;

    while (this_node != NULL) {
        next_node = this_node->next;
        alUnlink(this_node);
        alLink(this_node, &evtq->freeList);
        this_node = next_node;
    }

    osSetIntMask(mask);
}

void alEvtqFlushType(ALEventQueue* evtq, s16 type) {
    ALLink* this_node;
    ALLink* next_node;
    ALEventListItem* this_item;
    ALEventListItem* next_item;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    this_node = evtq->allocList.next;

    while (this_node != NULL) {
        this_item = (ALEventListItem*) this_node;
        next_node = this_node->next;

        if (this_item->evt.type == type) {
            next_item = (ALEventListItem*) next_node;
            if (next_item) {
                next_item->delta += this_item->delta;
            }

            alUnlink(this_node);
            alLink(this_node, &evtq->freeList);
        }

        this_node = next_node;
    }

    osSetIntMask(mask);
}
