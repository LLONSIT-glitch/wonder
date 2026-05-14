#include <libaudio.h>
#include <os_internal.h>
#include <ultraerror.h>
#include "seqp.h"
#include "cseq.h"

static ALMicroTime __CSPVoiceHandler(void* node);
void __CSPPostNextSeqEvent(ALCSPlayer* seqp);
static void __CSPHandleNextSeqEvent(ALCSPlayer* seqp);
static void __CSPHandleMIDIMsg(ALCSPlayer* seqp, ALEvent* event);
static void __CSPHandleMetaMsg(ALCSPlayer* seqp, ALEvent* event);
static void __CSPRepostEvent(ALEventQueue* evtq, ALEventListItem* item);
static void __setUsptFromTempo(ALCSPlayer* seqp, f32 tempo);

void alCSPNew(ALCSPlayer* seqp, ALSeqpConfig* c) {
    s32 i;
    ALEventListItem* items;
    ALVoiceState* vs;
    ALVoiceState* voices;

    ALHeap* hp = c->heap;

    seqp->bank = 0;
    seqp->target = NULL;
    seqp->drvr = &alGlobals->drvr;
    seqp->chanMask = 0xff;
    seqp->uspt = 488;
    seqp->nextDelta = 0;
    seqp->state = AL_STOPPED;
    seqp->vol = 0x7FFF;
    seqp->frameTime = AL_USEC_PER_FRAME;
    seqp->curTime = 0;
    seqp->initOsc = c->initOsc;
    seqp->updateOsc = c->updateOsc;
    seqp->stopOsc = c->stopOsc;

    seqp->nextEvent.type = AL_SEQP_API_EVT;

    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapAlloc(hp, c->maxChannels, sizeof(ALChanState));
    __initChanState((ALSeqPlayer*) seqp);

    voices = alHeapAlloc(hp, c->maxVoices, sizeof(ALVoiceState));
    seqp->vFreeList = 0;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;
    }

    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;

    items = alHeapAlloc(hp, c->maxEvents, sizeof(ALEventListItem));
    alEvtqNew(&seqp->evtq, items, c->maxEvents);

    seqp->node.next = NULL;
    seqp->node.handler = __CSPVoiceHandler;
    seqp->node.clientData = seqp;
    alSynAddPlayer(&alGlobals->drvr, &seqp->node);
}

static ALMicroTime __CSPVoiceHandler(void* node) {
    ALCSPlayer* seqp = (ALCSPlayer*) node;
    ALEvent evt;
    ALVoice* voice;
    ALMicroTime delta;
    ALVoiceState* vs;
    void* oscState;
    f32 oscValue;
    u8 chan;

    do {
        switch (seqp->nextEvent.type) {
            case (AL_SEQ_REF_EVT):
                __CSPHandleNextSeqEvent(seqp);
                break;

            case (AL_SEQP_API_EVT):
                evt.type = AL_SEQP_API_EVT;
                alEvtqPostEvent(&seqp->evtq, (ALEvent*) &evt, seqp->frameTime);
                break;

            case (AL_NOTE_END_EVT):
                voice = seqp->nextEvent.msg.note.voice;

                alSynStopVoice(seqp->drvr, voice);
                alSynFreeVoice(seqp->drvr, voice);
                vs = (ALVoiceState*) voice->clientPrivate;
                if (vs->flags) {
                    __seqpStopOsc((ALSeqPlayer*) seqp, vs);
                }
                __unmapVoice((ALSeqPlayer*) seqp, voice);
                break;

            case (AL_SEQP_ENV_EVT):
                voice = seqp->nextEvent.msg.vol.voice;
                vs = (ALVoiceState*) voice->clientPrivate;

                if (vs->envPhase == AL_PHASE_ATTACK) {
                    vs->envPhase = AL_PHASE_DECAY;
                }

                delta = seqp->nextEvent.msg.vol.delta;
                vs->envEndTime = seqp->curTime + delta;
                vs->envGain = seqp->nextEvent.msg.vol.vol;
                alSynSetVol(seqp->drvr, voice, __vsVol(vs, (ALSeqPlayer*) seqp), delta);
                break;

            case (AL_TREM_OSC_EVT):
                vs = seqp->nextEvent.msg.osc.vs;
                oscState = seqp->nextEvent.msg.osc.oscState;
                delta = (*seqp->updateOsc)(oscState, &oscValue);
                vs->tremelo = (u8) oscValue;
                alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, (ALSeqPlayer*) seqp), __vsDelta(vs, seqp->curTime));
                evt.type = AL_TREM_OSC_EVT;
                evt.msg.osc.vs = vs;
                evt.msg.osc.oscState = oscState;
                alEvtqPostEvent(&seqp->evtq, &evt, delta);
                break;

            case (AL_VIB_OSC_EVT):
                vs = seqp->nextEvent.msg.osc.vs;
                oscState = seqp->nextEvent.msg.osc.oscState;
                chan = seqp->nextEvent.msg.osc.chan;
                delta = (*seqp->updateOsc)(oscState, &oscValue);
                vs->vibrato = oscValue;
                alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * vs->vibrato * seqp->chanState[chan].pitchBend);
                evt.type = AL_VIB_OSC_EVT;
                evt.msg.osc.vs = vs;
                evt.msg.osc.oscState = oscState;
                evt.msg.osc.chan = chan;
                alEvtqPostEvent(&seqp->evtq, &evt, delta);
                break;

            case (AL_SEQP_MIDI_EVT):
            case (AL_CSP_NOTEOFF_EVT):
                __CSPHandleMIDIMsg(seqp, &seqp->nextEvent);
                break;

            case (AL_SEQP_META_EVT):
                __CSPHandleMetaMsg(seqp, &seqp->nextEvent);
                break;

            case (AL_SEQP_VOL_EVT):
                seqp->vol = seqp->nextEvent.msg.spvol.vol;
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, (ALSeqPlayer*) seqp), __vsDelta(vs, seqp->curTime));
                }
                break;

            case (AL_SEQP_PLAY_EVT):
                if (seqp->state != AL_PLAYING) {
                    seqp->state = AL_PLAYING;
                    __CSPPostNextSeqEvent(seqp);
                }
                break;

            case (AL_SEQP_STOP_EVT):
                if (seqp->state == AL_STOPPING) {
                    for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
                        alSynStopVoice(seqp->drvr, &vs->voice);
                        alSynFreeVoice(seqp->drvr, &vs->voice);
                        if (vs->flags) {
                            __seqpStopOsc((ALSeqPlayer*) seqp, vs);
                        }
                        __unmapVoice((ALSeqPlayer*) seqp, &vs->voice);
                    }
                    seqp->state = AL_STOPPED;
                }
                break;

            case (AL_SEQP_STOPPING_EVT):
                if (seqp->state == AL_PLAYING) {

                    alEvtqFlushType(&seqp->evtq, AL_SEQ_REF_EVT);
                    alEvtqFlushType(&seqp->evtq, AL_CSP_NOTEOFF_EVT);
                    alEvtqFlushType(&seqp->evtq, AL_SEQP_MIDI_EVT);

                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if (__voiceNeedsNoteKill((ALSeqPlayer*) seqp, &vs->voice, KILL_TIME)) {
                            __seqpReleaseVoice((ALSeqPlayer*) seqp, &vs->voice, KILL_TIME);
                        }
                    }

                    seqp->state = AL_STOPPING;
                    evt.type = AL_SEQP_STOP_EVT;
                    alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
                }
                break;

            case (AL_SEQP_PRIORITY_EVT):
                chan = seqp->nextEvent.msg.sppriority.chan;
                seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.priority;
                break;

            case (AL_SEQP_SEQ_EVT):

                seqp->target = seqp->nextEvent.msg.spseq.seq;
                __setUsptFromTempo(seqp, 500000.0);
                if (seqp->bank) {
                    __initFromBank((ALSeqPlayer*) seqp, seqp->bank);
                }
                break;

            case (AL_SEQP_BANK_EVT):

                seqp->bank = seqp->nextEvent.msg.spbank.bank;
                __initFromBank((ALSeqPlayer*) seqp, seqp->bank);
                break;

            case (AL_SEQ_END_EVT):
            case (AL_TEMPO_EVT):
            case (AL_SEQ_MIDI_EVT):

                break;
        }
        seqp->nextDelta = alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent);

    } while (seqp->nextDelta == 0);

    seqp->curTime += seqp->nextDelta;
    return seqp->nextDelta;
}

void __CSPPostNextSeqEvent(ALCSPlayer* seqp) {
    ALEvent evt;
    s32 deltaTicks;

    if (seqp->state != AL_PLAYING || seqp->target == NULL) {
        return;
    }

    if (!__alCSeqNextDelta(seqp->target, &deltaTicks)) {
        return;
    }

    evt.type = AL_SEQ_REF_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
}

static void __CSPHandleNextSeqEvent(ALCSPlayer* seqp) {
    ALEvent evt;

    if (seqp->target == NULL) {
        return;
    }

    alCSeqNextEvent(seqp->target, &evt);

    switch (evt.type) {
        case AL_SEQ_MIDI_EVT:
            __CSPHandleMIDIMsg(seqp, &evt);
            __CSPPostNextSeqEvent(seqp);
            break;

        case AL_TEMPO_EVT:
            __CSPHandleMetaMsg(seqp, &evt);
            __CSPPostNextSeqEvent(seqp);
            break;

        case AL_SEQ_END_EVT:
            seqp->state = AL_STOPPING;
            evt.type = AL_SEQP_STOP_EVT;
            alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
            break;

        case AL_TRACK_END:
        case AL_CSP_LOOPSTART:
        case AL_CSP_LOOPEND:
            __CSPPostNextSeqEvent(seqp);
            break;

        default:
            break;
    }
}

static void __CSPHandleMIDIMsg(ALCSPlayer* seqp, ALEvent* event) {
    ALVoice* voice;
    ALVoiceState* vs;
    s32 status;
    u8 chan;
    u8 key;
    u8 vel;
    u8 byte1;
    u8 byte2;
    ALMIDIEvent* midi = &event->msg.midi;
    s16 vol;
    ALEvent evt;
    ALMicroTime deltaTime;
    ALVoiceState* vstate;
    ALPan pan;
    ALFxRef fxref;

    status = midi->status & AL_MIDI_StatusMask;
    chan = midi->status & AL_MIDI_ChannelMask;
    byte1 = key = midi->byte1;
    byte2 = vel = midi->byte2;

    switch (status) {
        case (AL_MIDI_NoteOn):

            if (vel != 0) {
                ALVoiceConfig config;
                ALSound* sound;
                s16 cents;
                f32 pitch, oscValue;
                u8 fxmix;
                void* oscState;
                ALInstrument* inst;

                if (seqp->state != AL_PLAYING) {
                    break;
                }

                sound = __lookupSoundQuick((ALSeqPlayer*) seqp, key, vel, chan);
                ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK, ERR_ALSEQP_NO_SOUND);

                config.priority = seqp->chanState[chan].priority;
                config.fxBus = 0;
                config.unityPitch = 0;

                vstate = __mapVoice((ALSeqPlayer*) seqp, key, vel, chan);
                ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK, ERR_ALSEQP_NO_VOICE);

                voice = &vstate->voice;

                alSynAllocVoice(seqp->drvr, voice, &config);

                vstate->sound = sound;
                vstate->envPhase = AL_PHASE_ATTACK;
                if (seqp->chanState[chan].sustain > AL_SUSTAIN) {
                    vstate->phase = AL_PHASE_SUSTAIN;
                }
                else {
                    vstate->phase = AL_PHASE_NOTEON;
                }

                cents = (key - sound->keyMap->keyBase) * 100 + sound->keyMap->detune;

                vstate->pitch = alCents2Ratio(cents);
                vstate->envGain = sound->envelope->attackVolume;
                vstate->envEndTime = seqp->curTime + sound->envelope->attackTime;

                vstate->flags = 0;
                inst = seqp->chanState[chan].instrument;

                oscValue = (f32) AL_VOL_FULL;
                if (inst->tremType) {
                    if (seqp->initOsc) {
                        deltaTime = (*seqp->initOsc)(&oscState, &oscValue, inst->tremType, inst->tremRate,
                                                     inst->tremDepth, inst->tremDelay);

                        if (deltaTime) {
                            evt.type = AL_TREM_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x01;
                        }
                    }
                }
                vstate->tremelo = (u8) oscValue;

                oscValue = 1.0f;
                if (inst->vibType) {
                    if (seqp->initOsc) {
                        deltaTime = (*seqp->initOsc)(&oscState, &oscValue, inst->vibType, inst->vibRate, inst->vibDepth,
                                                     inst->vibDelay);

                        if (deltaTime) {
                            evt.type = AL_VIB_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            evt.msg.osc.chan = chan;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x02;
                        }
                    }
                }
                vstate->vibrato = oscValue;

                pitch = vstate->pitch * seqp->chanState[chan].pitchBend * vstate->vibrato;
                fxmix = seqp->chanState[chan].fxmix;
                pan = __vsPan(vstate, (ALSeqPlayer*) seqp);
                vol = __vsVol(vstate, (ALSeqPlayer*) seqp);
                deltaTime = sound->envelope->attackTime;

                alSynStartVoiceParams(seqp->drvr, voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);

                evt.type = AL_SEQP_ENV_EVT;
                evt.msg.vol.voice = voice;
                evt.msg.vol.vol = sound->envelope->decayVolume;
                evt.msg.vol.delta = sound->envelope->decayTime;

                alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);

                if (midi->duration) {

                    evt.type = AL_CSP_NOTEOFF_EVT;
                    evt.msg.midi.status = chan | AL_MIDI_NoteOff;
                    evt.msg.midi.byte1 = key;
                    evt.msg.midi.byte2 = 0;
                    deltaTime = seqp->uspt * midi->duration;

                    alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                }

                break;
            }

        case (AL_MIDI_NoteOff):
            vstate = __lookupVoice((ALSeqPlayer*) seqp, key, chan);
            ALFlagFailIf(!vstate, seqp->debugFlags & NOTE_OFF_ERR_MASK, ERR_ALSEQP_OFF_VOICE);

            if (vstate->phase == AL_PHASE_SUSTAIN) {
                vstate->phase = AL_PHASE_SUSTREL;
            }
            else {
                vstate->phase = AL_PHASE_RELEASE;
                __seqpReleaseVoice((ALSeqPlayer*) seqp, &vstate->voice, vstate->sound->envelope->releaseTime);
            }

            break;

        case (AL_MIDI_PolyKeyPressure):

            vstate = __lookupVoice((ALSeqPlayer*) seqp, key, chan);
            ALFailIf(!vstate, ERR_ALSEQP_POLY_VOICE);

            vstate->velocity = byte2;
            alSynSetVol(seqp->drvr, &vstate->voice, __vsVol(vstate, (ALSeqPlayer*) seqp),
                        __vsDelta(vstate, seqp->curTime));
            break;

        case (AL_MIDI_ChannelPressure):

            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    vs->velocity = byte1;
                    alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, (ALSeqPlayer*) seqp), __vsDelta(vs, seqp->curTime));
                }
            }
            break;

        case (AL_MIDI_ControlChange):
            switch (byte1) {
                case (AL_MIDI_PAN_CTRL):
                    seqp->chanState[chan].pan = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if (vs->channel == chan) {
                            pan = __vsPan(vs, (ALSeqPlayer*) seqp);
                            alSynSetPan(seqp->drvr, &vs->voice, pan);
                        }
                    }
                    break;
                case (AL_MIDI_VOLUME_CTRL):
                    seqp->chanState[chan].vol = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE)) {
                            vol = __vsVol(vs, (ALSeqPlayer*) seqp);
                            alSynSetVol(seqp->drvr, &vs->voice, vol, __vsDelta(vs, seqp->curTime));
                        }
                    }
                    break;
                case (AL_MIDI_PRIORITY_CTRL):

                    seqp->chanState[chan].priority = byte2;
                    break;
                case (AL_MIDI_SUSTAIN_CTRL):
                    seqp->chanState[chan].sustain = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if ((vs->channel == chan) && (vs->phase != AL_PHASE_RELEASE)) {
                            if (byte2 > AL_SUSTAIN) {

                                if (vs->phase == AL_PHASE_NOTEON) {
                                    vs->phase = AL_PHASE_SUSTAIN;
                                }
                            }
                            else {

                                if (vs->phase == AL_PHASE_SUSTAIN) {
                                    vs->phase = AL_PHASE_NOTEON;
                                }

                                else if (vs->phase == AL_PHASE_SUSTREL) {
                                    vs->phase = AL_PHASE_RELEASE;
                                    __seqpReleaseVoice((ALSeqPlayer*) seqp, &vs->voice,
                                                       vs->sound->envelope->releaseTime);
                                }
                            }
                        }
                    }
                    break;
                case (AL_MIDI_FX1_CTRL):
                    seqp->chanState[chan].fxmix = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if (vs->channel == chan) {
                            alSynSetFXMix(seqp->drvr, &vs->voice, byte2);
                        }
                    }
                    break;

                default:
                    break;
            }
            break;
        case (AL_MIDI_ProgramChange):

            if (key < seqp->bank->instCount) {
                ALInstrument* inst = seqp->bank->instArray[key];
                __setInstChanState((ALSeqPlayer*) seqp, inst, chan);
            }
            else {
            }
            break;
        case (AL_MIDI_PitchBendChange): {
            s32 bendVal;
            f32 bendRatio;
            s32 cents;

            bendVal = ((byte2 << 7) + byte1) - 8192;

            cents = (seqp->chanState[chan].bendRange * bendVal) / 8192;

            bendRatio = alCents2Ratio(cents);
            seqp->chanState[chan].pitchBend = bendRatio;

            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                if (vs->channel == chan) {
                    alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * bendRatio * vs->vibrato);
                }

        } break;

        default:
            break;
    }
}

static void __CSPHandleMetaMsg(ALCSPlayer* seqp, ALEvent* event) {
    ALTempoEvent* tevt = &event->msg.tempo;
    ALEvent evt;
    s32 tempo;
    s32 oldUspt;
    u32 ticks;
    ALMicroTime tempDelta, curDelta = 0;
    ALEventListItem *thisNode, *nextNode, *firstTemp = 0;

    if (event->msg.tempo.status == AL_MIDI_Meta) {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO) {
            oldUspt = seqp->uspt;
            tempo = (tevt->byte1 << 16) | (tevt->byte2 << 8) | (tevt->byte3 << 0);
            __setUsptFromTempo(seqp, (f32) tempo);

            thisNode = (ALEventListItem*) seqp->evtq.allocList.next;
            while (thisNode) {
                curDelta += thisNode->delta;
                nextNode = (ALEventListItem*) thisNode->node.next;
                if (thisNode->evt.type == AL_CSP_NOTEOFF_EVT) {
                    alUnlink((ALLink*) thisNode);

                    if (firstTemp) {
                        alLink((ALLink*) thisNode, (ALLink*) firstTemp);
                    }
                    else {
                        thisNode->node.next = 0;
                        thisNode->node.prev = 0;
                        firstTemp = thisNode;
                    }
                    tempDelta = curDelta;
                    if (nextNode) {
                        curDelta -= thisNode->delta;
                        nextNode->delta += thisNode->delta;
                    }
                    thisNode->delta = tempDelta;
                }
                thisNode = nextNode;
            }

            thisNode = firstTemp;
            while (thisNode) {
                nextNode = (ALEventListItem*) thisNode->node.next;
                ticks = thisNode->delta / oldUspt;
                thisNode->delta = ticks * seqp->uspt;
                __CSPRepostEvent(&seqp->evtq, thisNode);
                thisNode = nextNode;
            }
        }
    }
}

static void __CSPRepostEvent(ALEventQueue* evtq, ALEventListItem* item) {
    OSIntMask mask;
    ALLink* node;
    ALEventListItem* nextItem;

    mask = osSetIntMask(OS_IM_NONE);

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            alLink((ALLink*) item, node);
            break;
        }
        else {
            nextItem = (ALEventListItem*) node->next;
            if (item->delta < nextItem->delta) {
                nextItem->delta -= item->delta;
                alLink((ALLink*) item, node);
                break;
            }
            item->delta -= nextItem->delta;
        }
    }
    osSetIntMask(mask);
}

static void __setUsptFromTempo(ALCSPlayer* seqp, f32 tempo) {
    if (seqp->target) {
        seqp->uspt = (s32) ((f32) tempo * seqp->target->qnpt);
    }
    else {
        seqp->uspt = 488;
    }
}
