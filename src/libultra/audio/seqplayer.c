#include <PR/libaudio.h>
#include "seq.h"
#include "seqp.h"

static ALMicroTime __seqpVoiceHandler(void* node);
static void __handleMIDIMsg(ALSeqPlayer* seqp, ALEvent* event);
static void __handleMetaMsg(ALSeqPlayer* seqp, ALEvent* event);
static void __handleNextSeqEvent(ALSeqPlayer* seqp);
static void __setUsptFromTempo(ALSeqPlayer* seqp, f32 tempo);

void alSeqpNew(ALSeqPlayer* seqp, ALSeqpConfig* c) {
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
    seqp->debugFlags = c->debugFlags;
    seqp->frameTime = AL_USEC_PER_FRAME;
    seqp->curTime = 0;
    seqp->initOsc = c->initOsc;
    seqp->updateOsc = c->updateOsc;
    seqp->stopOsc = c->stopOsc;
    seqp->loopStart = 0;
    seqp->loopEnd = 0;
    seqp->loopCount = 0;

    seqp->nextEvent.type = AL_SEQP_API_EVT;

    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapAlloc(hp, c->maxChannels, sizeof(ALChanState));
    __initChanState(seqp);

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
    seqp->node.handler = __seqpVoiceHandler;
    seqp->node.clientData = seqp;
    alSynAddPlayer(&alGlobals->drvr, &seqp->node);
}

ALMicroTime __seqpVoiceHandler(void* node) {
    ALSeqPlayer* seqp = (ALSeqPlayer*) node;
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
                __handleNextSeqEvent(seqp);
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
                if (vs->flags)
                    __seqpStopOsc((ALSeqPlayer*) seqp, vs);
                __unmapVoice(seqp, voice);
                break;

            case (AL_SEQP_ENV_EVT):
                voice = seqp->nextEvent.msg.vol.voice;
                vs = (ALVoiceState*) voice->clientPrivate;

                if (vs->envPhase == AL_PHASE_ATTACK)
                    vs->envPhase = AL_PHASE_DECAY;

                delta = seqp->nextEvent.msg.vol.delta;
                vs->envGain = seqp->nextEvent.msg.vol.vol;
                vs->envEndTime = seqp->curTime + delta;
                alSynSetVol(seqp->drvr, voice, __vsVol(vs, seqp), delta);
                break;

            case (AL_TREM_OSC_EVT):
                vs = seqp->nextEvent.msg.osc.vs;
                oscState = seqp->nextEvent.msg.osc.oscState;
                delta = (*seqp->updateOsc)(oscState, &oscValue);
                vs->tremelo = (u8) oscValue;
                alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
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
                __handleMIDIMsg(seqp, &seqp->nextEvent);
                break;

            case (AL_SEQP_META_EVT):
                __handleMetaMsg(seqp, &seqp->nextEvent);
                break;

            case (AL_SEQP_PLAY_EVT):
                if (seqp->state != AL_PLAYING) {
                    seqp->state = AL_PLAYING;
                    __postNextSeqEvent(seqp);
                }
                break;

            case (AL_SEQP_STOP_EVT):
                if (seqp->state == AL_STOPPING) {
                    for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
                        alSynStopVoice(seqp->drvr, &vs->voice);
                        alSynFreeVoice(seqp->drvr, &vs->voice);
                        if (vs->flags)
                            __seqpStopOsc((ALSeqPlayer*) seqp, vs);
                        __unmapVoice((ALSeqPlayer*) seqp, &vs->voice);
                    }

                    seqp->curTime = 0;
                    seqp->state = AL_STOPPED;
                }
                break;

            case (AL_SEQP_STOPPING_EVT):
                if (seqp->state == AL_PLAYING) {

                    alEvtqFlushType(&seqp->evtq, AL_SEQ_REF_EVT);
                    alEvtqFlushType(&seqp->evtq, AL_SEQP_MIDI_EVT);

                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if (__voiceNeedsNoteKill(seqp, &vs->voice, KILL_TIME))
                            __seqpReleaseVoice(seqp, &vs->voice, KILL_TIME);
                    }

                    seqp->state = AL_STOPPING;
                    evt.type = AL_SEQP_STOP_EVT;
                    alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
                }
                break;

            case (AL_SEQP_VOL_EVT):
                seqp->vol = seqp->nextEvent.msg.spvol.vol;
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
                }
                break;

            case (AL_SEQP_LOOP_EVT):
                seqp->loopStart = seqp->nextEvent.msg.loop.start;
                seqp->loopEnd = seqp->nextEvent.msg.loop.end;
                seqp->loopCount = seqp->nextEvent.msg.loop.count;
                break;

            case (AL_SEQP_PRIORITY_EVT):
                chan = seqp->nextEvent.msg.sppriority.chan;
                seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.priority;
                break;
            case (AL_SEQP_SEQ_EVT):

                seqp->target = seqp->nextEvent.msg.spseq.seq;
                __setUsptFromTempo(seqp, 500000.0);
                if (seqp->bank)
                    __initFromBank(seqp, seqp->bank);
                break;
            case (AL_SEQP_BANK_EVT):

                seqp->bank = seqp->nextEvent.msg.spbank.bank;
                __initFromBank(seqp, seqp->bank);
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

void __postNextSeqEvent(ALSeqPlayer* seqp) {
    ALEvent evt;
    s32 deltaTicks;
    ALSeq* seq = seqp->target;

    if ((seqp->state != AL_PLAYING) || (seq == NULL))
        return;

    if (!__alSeqNextDelta(seq, &deltaTicks))
        return;

    if (seqp->loopCount) {

        if (alSeqGetTicks(seq) + deltaTicks >= seqp->loopEnd->curTicks) {
            alSeqSetLoc(seq, seqp->loopStart);

            if (seqp->loopCount != -1)
                seqp->loopCount--;
        }
    }

    evt.type = AL_SEQ_REF_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
}

static void __handleNextSeqEvent(ALSeqPlayer* seqp) {
    ALEvent evt;

    if (seqp->target == NULL)
        return;

    alSeqNextEvent(seqp->target, &evt);

    switch (evt.type) {
        case AL_SEQ_MIDI_EVT:
            __handleMIDIMsg(seqp, &evt);
            __postNextSeqEvent(seqp);
            break;

        case AL_TEMPO_EVT:
            __handleMetaMsg(seqp, &evt);
            __postNextSeqEvent(seqp);
            break;

        case AL_SEQ_END_EVT:
            seqp->state = AL_STOPPING;
            evt.type = AL_SEQP_STOP_EVT;
            alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
            break;

        default:;
    }
}

void __handleMIDIMsg(ALSeqPlayer* seqp, ALEvent* event) {
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

                if (seqp->state != AL_PLAYING)
                    break;

                sound = __lookupSoundQuick(seqp, key, vel, chan);
                ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK, ERR_ALSEQP_NO_SOUND);

                config.priority = seqp->chanState[chan].priority;
                config.fxBus = 0;
                config.unityPitch = 0;

                vstate = __mapVoice(seqp, key, vel, chan);
                ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK, ERR_ALSEQP_NO_VOICE);

                voice = &vstate->voice;

                alSynAllocVoice(seqp->drvr, voice, &config);

                vstate->sound = sound;
                vstate->envPhase = AL_PHASE_ATTACK;
                if (seqp->chanState[chan].sustain > AL_SUSTAIN)
                    vstate->phase = AL_PHASE_SUSTAIN;
                else
                    vstate->phase = AL_PHASE_NOTEON;

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
                pan = __vsPan(vstate, seqp);
                vol = __vsVol(vstate, seqp);
                deltaTime = sound->envelope->attackTime;

                alSynStartVoiceParams(seqp->drvr, voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);

                evt.type = AL_SEQP_ENV_EVT;
                evt.msg.vol.voice = voice;
                evt.msg.vol.vol = sound->envelope->decayVolume;
                evt.msg.vol.delta = sound->envelope->decayTime;
                deltaTime = sound->envelope->attackTime;

                alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);

                break;
            }

        case (AL_MIDI_NoteOff):
            vstate = __lookupVoice(seqp, key, chan);
            ALFlagFailIf(!vstate, (seqp->debugFlags & NOTE_OFF_ERR_MASK), ERR_ALSEQP_OFF_VOICE);

            if (vstate->phase == AL_PHASE_SUSTAIN)
                vstate->phase = AL_PHASE_SUSTREL;
            else {
                vstate->phase = AL_PHASE_RELEASE;
                __seqpReleaseVoice(seqp, &vstate->voice, vstate->sound->envelope->releaseTime);
            }

            break;

        case (AL_MIDI_PolyKeyPressure):

            vstate = __lookupVoice(seqp, key, chan);
            ALFailIf(!vstate, ERR_ALSEQP_POLY_VOICE);

            vstate->velocity = byte2;
            alSynSetVol(seqp->drvr, &vstate->voice, __vsVol(vstate, seqp), __vsDelta(vstate, seqp->curTime));
            break;

        case (AL_MIDI_ChannelPressure):

            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    vs->velocity = byte1;
                    alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
                }
            }
            break;

        case (AL_MIDI_ControlChange):

            switch (byte1) {

                case (AL_MIDI_PAN_CTRL):
                    seqp->chanState[chan].pan = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if (vs->channel == chan) {
                            pan = __vsPan(vs, seqp);
                            alSynSetPan(seqp->drvr, &vs->voice, pan);
                        }
                    }
                    break;

                case (AL_MIDI_VOLUME_CTRL):
                    seqp->chanState[chan].vol = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                        if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE)) {
                            vol = __vsVol(vs, seqp);
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

                                if (vs->phase == AL_PHASE_NOTEON)
                                    vs->phase = AL_PHASE_SUSTAIN;
                            } else {

                                if (vs->phase == AL_PHASE_SUSTAIN)
                                    vs->phase = AL_PHASE_NOTEON;
                                else if (vs->phase == AL_PHASE_SUSTREL) {
                                    vs->phase = AL_PHASE_RELEASE;
                                    __seqpReleaseVoice(seqp, &vs->voice, vs->sound->envelope->releaseTime);
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

                case (AL_MIDI_FX_CTRL_0):
                case (AL_MIDI_FX_CTRL_1):
                case (AL_MIDI_FX_CTRL_2):
                case (AL_MIDI_FX_CTRL_3):
                case (AL_MIDI_FX_CTRL_4):
                case (AL_MIDI_FX_CTRL_5):
                case (AL_MIDI_FX_CTRL_6):
                case (AL_MIDI_FX_CTRL_7):
                case (AL_MIDI_FX3_CTRL):
                default:
                    break;
            }
            break;

        case (AL_MIDI_ProgramChange):

            if (key < seqp->bank->instCount) {
                ALInstrument* inst = seqp->bank->instArray[key];
                __setInstChanState(seqp, inst, chan);
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

            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * bendRatio * vs->vibrato);
                }
            }
        } break;

        default:
            break;
    }
}

void __handleMetaMsg(ALSeqPlayer* seqp, ALEvent* event) {
    ALTempoEvent* tevt = &event->msg.tempo;
    ALEvent evt;
    s32 tempo;

    if (event->msg.tempo.status == AL_MIDI_Meta) {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO) {
            tempo = (tevt->byte1 << 16) | (tevt->byte2 << 8) | (tevt->byte3 << 0);
            __setUsptFromTempo(seqp, (f32) tempo);
        }
    }
}

ALVoiceState* __mapVoice(ALSeqPlayer* seqp, u8 key, u8 vel, u8 channel) {
    ALVoiceState* vs = seqp->vFreeList;

    if (vs) {

        seqp->vFreeList = vs->next;

        vs->next = 0;

        if (!seqp->vAllocHead)
            seqp->vAllocHead = vs;
        else
            seqp->vAllocTail->next = vs;

        seqp->vAllocTail = vs;

        vs->channel = channel;
        vs->key = key;
        vs->velocity = vel;
        vs->voice.clientPrivate = vs;
    }

    return vs;
}

void __unmapVoice(ALSeqPlayer* seqp, ALVoice* voice) {
    ALVoiceState* prev = 0;
    ALVoiceState* vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if (&vs->voice == voice) {

            if (prev)
                prev->next = vs->next;
            else
                seqp->vAllocHead = vs->next;

            if (vs == seqp->vAllocTail) {
                seqp->vAllocTail = prev;
            }

            vs->next = seqp->vFreeList;
            seqp->vFreeList = vs;
            return;
        }
        prev = vs;
    }
}

ALVoiceState* __lookupVoice(ALSeqPlayer* seqp, u8 key, u8 channel) {
    ALVoiceState* vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if ((vs->key == key) && (vs->channel == channel) && (vs->phase != AL_PHASE_RELEASE) &&
            (vs->phase != AL_PHASE_SUSTREL))
            return vs;
    }

    return 0;
}

ALSound* __lookupSoundQuick(ALSeqPlayer* seqp, u8 key, u8 vel, u8 chan) {
    ALInstrument* inst = seqp->chanState[chan].instrument;
    s32 l = 1;
    s32 r = inst->soundCount;
    s32 i;
    ALKeyMap* keymap;

    while (r >= l) {
        i = (l + r) / 2;

        keymap = inst->soundArray[i - 1]->keyMap;

        if ((key >= keymap->keyMin) && (key <= keymap->keyMax) && (vel >= keymap->velocityMin) &&
            (vel <= keymap->velocityMax)) {
            return inst->soundArray[i - 1];
        } else if ((key < keymap->keyMin) || ((vel < keymap->velocityMin) && (key <= keymap->keyMax))) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }

    return 0;
}

s16 __vsVol(ALVoiceState* vs, ALSeqPlayer* seqp) {

    u32 t1, t2;

    t1 = (vs->tremelo * vs->velocity * vs->envGain) >> 6;
    t2 = (vs->sound->sampleVolume * seqp->vol * seqp->chanState[vs->channel].vol) >> 14;

    t1 *= t2;
    t1 >>= 15;

    return ((s16) t1);
}

ALMicroTime __vsDelta(ALVoiceState* vs, ALMicroTime t) {

    s32 delta = vs->envEndTime - t;

    if (delta >= 0) {
        return delta;
    } else {
        return AL_GAIN_CHANGE_TIME;
    }
}

ALPan __vsPan(ALVoiceState* vs, ALSeqPlayer* seqp) {
    s32 tmp;

    tmp = seqp->chanState[vs->channel].pan - AL_PAN_CENTER + vs->sound->samplePan;
    tmp = MAX(tmp, AL_PAN_LEFT);
    tmp = MIN(tmp, AL_PAN_RIGHT);

    return (ALPan) tmp;
}

void __seqpReleaseVoice(ALSeqPlayer* seqp, ALVoice* voice, ALMicroTime deltaTime) {
    ALEvent evt;
    ALVoiceState* vs = (ALVoiceState*) voice->clientPrivate;

    if (vs->envPhase == AL_PHASE_ATTACK) {
        ALLink* thisNode;
        ALLink* nextNode;
        ALEventListItem *thisItem, *nextItem;

        thisNode = seqp->evtq.allocList.next;
        while (thisNode != 0) {
            nextNode = thisNode->next;
            thisItem = (ALEventListItem*) thisNode;
            nextItem = (ALEventListItem*) nextNode;
            if (thisItem->evt.type == AL_SEQP_ENV_EVT) {
                if (thisItem->evt.msg.vol.voice == voice) {
                    if (nextItem)
                        nextItem->delta += thisItem->delta;
                    alUnlink(thisNode);
                    alLink(thisNode, &seqp->evtq.freeList);
                }
            }
            thisNode = nextNode;
        }
    }

    vs->velocity = 0;
    vs->envPhase = AL_PHASE_RELEASE;
    vs->envGain = 0;
    vs->envEndTime = seqp->curTime + deltaTime;

    alSynSetPriority(seqp->drvr, voice, 0);
    alSynSetVol(seqp->drvr, voice, 0, deltaTime);
    evt.type = AL_NOTE_END_EVT;
    evt.msg.note.voice = voice;

    alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
}

#define VOICENEEDSNOTEKILL_DEBUG _DEBUG_INTERNAL && 0

char __voiceNeedsNoteKill(ALSeqPlayer* seqp, ALVoice* voice, ALMicroTime killTime) {
    ALLink* thisNode;
    ALLink* nextNode;
    ALEventListItem* thisItem;
    ALMicroTime itemTime = 0;
    char needsNoteKill = TRUE;

    thisNode = seqp->evtq.allocList.next;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        thisItem = (ALEventListItem*) thisNode;
        itemTime += thisItem->delta;

        if (thisItem->evt.type == AL_NOTE_END_EVT) {
            if (thisItem->evt.msg.note.voice == voice) {
                if (itemTime > killTime) {
                    if ((ALEventListItem*) nextNode)
                        ((ALEventListItem*) nextNode)->delta += thisItem->delta;
                    alUnlink(thisNode);
                    alLink(thisNode, &seqp->evtq.freeList);
                } else
                    needsNoteKill = FALSE;
                break;
            }
        }
        thisNode = nextNode;
    }

    return needsNoteKill;
}

void __initFromBank(ALSeqPlayer* seqp, ALBank* b) {

    s32 i;
    ALInstrument* inst = 0;

    for (i = 0; !inst; i++)
        inst = b->instArray[i];

    for (i = 0; i < seqp->maxChannels; i++) {
        __resetPerfChanState(seqp, i);
        __setInstChanState(seqp, inst, i);
    }

    if (b->percussion) {
        __resetPerfChanState(seqp, i);
        __setInstChanState(seqp, b->percussion, 9);
    }
}

void __setInstChanState(ALSeqPlayer* seqp, ALInstrument* inst, s32 chan) {
    seqp->chanState[chan].instrument = inst;
    seqp->chanState[chan].pan = inst->pan;
    seqp->chanState[chan].vol = inst->volume;
    seqp->chanState[chan].priority = inst->priority;
    seqp->chanState[chan].bendRange = inst->bendRange;
}

void __resetPerfChanState(ALSeqPlayer* seqp, s32 chan) {
    seqp->chanState[chan].fxId = AL_FX_NONE;
    seqp->chanState[chan].fxmix = AL_DEFAULT_FXMIX;
    seqp->chanState[chan].pan = AL_PAN_CENTER;
    seqp->chanState[chan].vol = AL_VOL_FULL;
    seqp->chanState[chan].priority = AL_DEFAULT_PRIORITY;
    seqp->chanState[chan].sustain = 0;
    seqp->chanState[chan].bendRange = 200;
    seqp->chanState[chan].pitchBend = 1.0f;
}

void __initChanState(ALSeqPlayer* seqp) {
    int i;

    for (i = 0; i < seqp->maxChannels; i++) {
        seqp->chanState[i].instrument = 0;
        __resetPerfChanState(seqp, i);
    }
}

void __seqpStopOsc(ALSeqPlayer* seqp, ALVoiceState* vs) {
    ALEventListItem *thisNode, *nextNode;
    s16 evtType;

    thisNode = (ALEventListItem*) seqp->evtq.allocList.next;
    while (thisNode) {
        nextNode = (ALEventListItem*) thisNode->node.next;
        evtType = thisNode->evt.type;
        if (evtType == AL_TREM_OSC_EVT || evtType == AL_VIB_OSC_EVT) {
            if (thisNode->evt.msg.osc.vs == vs) {
                (*seqp->stopOsc)(thisNode->evt.msg.osc.oscState);
                alUnlink((ALLink*) thisNode);
                if (nextNode)
                    nextNode->delta += thisNode->delta;
                alLink((ALLink*) thisNode, &seqp->evtq.freeList);
                if (evtType == AL_TREM_OSC_EVT)
                    vs->flags = vs->flags & 0xFE;
                else
                    vs->flags = vs->flags & 0xFD;
                if (!vs->flags)
                    return;
            }
        }

        thisNode = nextNode;
    }
}

static void __setUsptFromTempo(ALSeqPlayer* seqp, f32 tempo) {
    if (seqp->target)
        seqp->uspt = (s32) ((f32) tempo * seqp->target->qnpt);
    else
        seqp->uspt = 488;
}
