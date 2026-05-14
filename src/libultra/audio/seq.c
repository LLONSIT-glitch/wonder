#include <PR/libaudio.h>

#define IFF_FILE_HDR 0x4d546864
#define IFF_TRACK_HDR 0x4d54726b

static s32 readVarLen(ALSeq* s);
static u8 read8(ALSeq* s);
static s16 read16(ALSeq* s);
static s32 read32(ALSeq* s);

void alSeqNew(ALSeq* seq, u8* ptr, s32 len) {

    seq->base = ptr;
    seq->len = len;
    seq->lastStatus = 0;
    seq->lastTicks = 0;
    seq->curPtr = ptr;

    if (read32(seq) != IFF_FILE_HDR) {
        return;
    }

    read32(seq);

    if (read16(seq) != 0) {
        return;
    }

    if (read16(seq) != 1) {
        return;
    }

    seq->division = read16(seq);
    if (seq->division & 0x8000) {
        return;
    }

    seq->qnpt = 1.0 / (f32) seq->division;

    if (read32(seq) != IFF_TRACK_HDR) {
        return;
    }

    read32(seq);

    seq->trackStart = seq->curPtr;
}

void alSeqNextEvent(ALSeq* seq, ALEvent* event) {
    u8 status;
    s16 delta;
    s32 len;
    s32 deltaTicks;
    s32 i;

    deltaTicks = readVarLen(seq);
    seq->lastTicks += deltaTicks;
    status = read8(seq);

    if (status == AL_MIDI_Meta) {
        u8 type = read8(seq);

        if (type == AL_MIDI_META_TEMPO) {
            event->type = AL_TEMPO_EVT;
            event->msg.tempo.ticks = deltaTicks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len = read8(seq);
            event->msg.tempo.byte1 = read8(seq);
            event->msg.tempo.byte2 = read8(seq);
            event->msg.tempo.byte3 = read8(seq);
        } else if (type == AL_MIDI_META_EOT) {
            event->type = AL_SEQ_END_EVT;
            event->msg.end.ticks = deltaTicks;
            event->msg.end.status = status;
            event->msg.end.type = type;
            event->msg.end.len = read8(seq);
        } else {
        }

        seq->lastStatus = 0;

    } else {
        event->type = AL_SEQ_MIDI_EVT;
        event->msg.midi.ticks = deltaTicks;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = read8(seq);
            seq->lastStatus = status;
        } else {

            event->msg.midi.status = seq->lastStatus;
            event->msg.midi.byte1 = status;
        }

        if (((event->msg.midi.status & 0xf0) != AL_MIDI_ProgramChange) &&
            ((event->msg.midi.status & 0xf0) != AL_MIDI_ChannelPressure)) {
            event->msg.midi.byte2 = read8(seq);
        } else {
            event->msg.midi.byte2 = 0;
        }
    }
}

char __alSeqNextDelta(ALSeq* seq, s32* pDeltaTicks) {
    u8* savedPtr;

    if (seq->curPtr >= seq->base + seq->len)
        return FALSE;

    savedPtr = seq->curPtr;
    *pDeltaTicks = readVarLen(seq);
    seq->curPtr = savedPtr;

    return TRUE;
}

f32 alSeqTicksToSec(ALSeq* seq, s32 ticks, u32 tempo) {
    return ((f32) (((f32) (ticks) * (f32) (tempo)) / ((f32) (seq->division) * 1000000.0)));
}

u32 alSeqSecToTicks(ALSeq* seq, f32 sec, u32 tempo) {
    return (u32) (((sec * 1000000.0) * seq->division) / tempo);
}

void alSeqNewMarker(ALSeq* seq, ALSeqMarker* m, u32 ticks) {
    ALEvent evt;
    u8 *savePtr, *lastPtr;
    s32 saveTicks, lastTicks;
    s16 saveStatus, lastStatus;

    if (ticks == 0) {
        m->curPtr = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks = 0;
        m->curTicks = 0;
        return;
    } else {
        savePtr = seq->curPtr;
        saveStatus = seq->lastStatus;
        saveTicks = seq->lastTicks;

        seq->curPtr = seq->trackStart;
        seq->lastStatus = 0;
        seq->lastTicks = 0;

        do {
            lastPtr = seq->curPtr;
            lastStatus = seq->lastStatus;
            lastTicks = seq->lastTicks;

            alSeqNextEvent(seq, &evt);

            if (evt.type == AL_SEQ_END_EVT) {
                lastPtr = seq->curPtr;
                lastStatus = seq->lastStatus;
                lastTicks = seq->lastTicks;
                break;
            }

        } while (seq->lastTicks < ticks);

        m->curPtr = lastPtr;
        m->lastStatus = lastStatus;
        m->lastTicks = lastTicks;
        m->curTicks = seq->lastTicks;

        seq->curPtr = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks = saveTicks;
    }
}

s32 alSeqGetTicks(ALSeq* seq) {
    return seq->lastTicks;
}

void alSeqSetLoc(ALSeq* seq, ALSeqMarker* m) {
    seq->curPtr = m->curPtr;
    seq->lastStatus = m->lastStatus;
    seq->lastTicks = m->lastTicks;
}

void alSeqGetLoc(ALSeq* seq, ALSeqMarker* m) {
    m->curPtr = seq->curPtr;
    m->lastStatus = seq->lastStatus;
    m->lastTicks = seq->lastTicks;
}

static u8 read8(ALSeq* seq) {
    return *seq->curPtr++;
}

static s16 read16(ALSeq* seq) {
    s16 tmp;

    tmp = *seq->curPtr++ << 8;
    tmp |= *seq->curPtr++;

    return tmp;
}

static s32 read32(ALSeq* seq) {
    s32 tmp;

    tmp = *seq->curPtr++ << 24;
    tmp |= *seq->curPtr++ << 16;
    tmp |= *seq->curPtr++ << 8;
    tmp |= *seq->curPtr++;

    return tmp;
}

static s32 readVarLen(ALSeq* seq) {
    s32 value;
    s32 c;

    c = *seq->curPtr++;
    value = c;
    if (c & 0x80) {
        value &= 0x7f;
        do {
            c = *seq->curPtr++;
            value = (value << 7) + (c & 0x7f);
        } while (c & 0x80);
    }
    return (value);
}
