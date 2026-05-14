#include <PR/R4300.h>
#include <PR/libaudio.h>
#include "synthInternals.h"

#define ADPCMFBYTES 9
#define LFSAMPLES 4

static Acmd* _decodeChunk(Acmd* ptr, ALLoadFilter* f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags);

Acmd* alAdpcmPull(void* filter, s16* outp, s32 outCount, s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;
    s16 inp;
    s32 tsam;
    s32 nframes;
    s32 nbytes;
    s32 overFlow;
    s32 startZero;
    s32 nOver;
    s32 nSam;
    s32 op;
    s32 nLeft;
    s32 bEnd;
    s32 decoded = 0;
    s32 looped = 0;
    ALLoadFilter* f = (ALLoadFilter*) filter;

    if (outCount == 0) {
        return ptr;
    }

    inp = AL_DECODER_IN;
    aLoadADPCM(ptr++, f->bookSize, K0_TO_PHYS(f->table->waveInfo.adpcmWave.book->book));

    looped = (outCount + f->sample > f->loop.end) && (f->loop.count != 0);
    if (looped) {
        nSam = f->loop.end - f->sample;
    } else {
        nSam = outCount;
    }

    if (f->lastsam) {
        nLeft = ADPCMFSIZE - f->lastsam;
    } else {
        nLeft = 0;
    }

    tsam = nSam - nLeft;
    if (tsam < 0) {
        tsam = 0;
    }

    nframes = (tsam + ADPCMFSIZE - 1) >> LFSAMPLES;
    nbytes = nframes * ADPCMFBYTES;

    if (looped) {
        ptr = _decodeChunk(ptr, f, tsam, nbytes, *outp, inp, f->first);

        if (f->lastsam) {
            *outp += f->lastsam << 1;
        } else {
            *outp += ADPCMFSIZE << 1;
        }

        f->lastsam = f->loop.start & 0xF;
        f->memin = (s32) f->table->base + ADPCMFBYTES * ((s32) (f->loop.start >> LFSAMPLES) + 1);
        f->sample = f->loop.start;

        bEnd = *outp;
        while (outCount > nSam) {
            outCount -= nSam;
            op = (bEnd + ((nframes + 1) << (LFSAMPLES + 1))) & ~0x1F;
            bEnd += nSam << 1;

            if ((f->loop.count != -1) && (f->loop.count != 0)) {
                f->loop.count--;
            }

            nSam = MIN(outCount, f->loop.end - f->loop.start);
            tsam = nSam - ADPCMFSIZE + f->lastsam;
            if (tsam < 0) {
                tsam = 0;
            }

            nframes = (tsam + ADPCMFSIZE - 1) >> LFSAMPLES;
            nbytes = nframes * ADPCMFBYTES;
            ptr = _decodeChunk(ptr, f, tsam, nbytes, op, inp, f->first | A_LOOP);
            aDMEMMove(ptr++, op + (f->lastsam << 1), bEnd, nSam << 1);
        }

        f->lastsam = (outCount + f->lastsam) & 0xF;
        f->sample += outCount;
        f->memin += ADPCMFBYTES * nframes;
        return ptr;
    }

    nSam = nframes << LFSAMPLES;
    overFlow = f->memin + nbytes - ((s32) f->table->base + f->table->len);
    if (overFlow < 0) {
        overFlow = 0;
    }

    nOver = (overFlow / ADPCMFBYTES) << LFSAMPLES;
    if (nOver > nSam + nLeft) {
        nOver = nSam + nLeft;
    }

    nbytes -= overFlow;

    if ((nOver - (nOver & 0xF)) < outCount) {
        decoded = 1;
        ptr = _decodeChunk(ptr, f, nSam - nOver, nbytes, *outp, inp, f->first);

        if (f->lastsam) {
            *outp += f->lastsam << 1;
        } else {
            *outp += ADPCMFSIZE << 1;
        }

        f->lastsam = (outCount + f->lastsam) & 0xF;
        f->sample += outCount;
        f->memin += ADPCMFBYTES * nframes;
    } else {
        f->lastsam = 0;
        f->memin += ADPCMFBYTES * nframes;
    }

    if (nOver) {
        f->lastsam = 0;
        if (decoded) {
            startZero = (nLeft + nSam - nOver) << 1;
        } else {
            startZero = 0;
        }

        aClearBuffer(ptr++, startZero + *outp, nOver << 1);
    }

    return ptr;
}

Acmd* alRaw16Pull(void* filter, s16* outp, s32 outCount, s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;
    s32 nbytes;
    s32 dramLoc;
    s32 dramAlign;
    s32 dmemAlign;
    s32 overFlow;
    s32 startZero;
    s32 nSam;
    s32 op;
    ALLoadFilter* f = (ALLoadFilter*) filter;

    if (outCount == 0) {
        return ptr;
    }

    if ((outCount + f->sample > f->loop.end) && (f->loop.count != 0)) {
        nSam = f->loop.end - f->sample;
        nbytes = nSam << 1;

        if (nSam > 0) {
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
        } else {
            dramAlign = 0;
        }

        *outp += dramAlign;
        f->memin = (s32) f->table->base + (f->loop.start << 1);
        f->sample = f->loop.start;
        op = *outp;

        while (outCount > nSam) {
            op += nSam << 1;
            outCount -= nSam;

            if ((f->loop.count != -1) && (f->loop.count != 0)) {
                f->loop.count--;
            }

            nSam = MIN(outCount, f->loop.end - f->loop.start);
            nbytes = nSam << 1;
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;

            if (op & 0x7) {
                dmemAlign = 8 - (op & 0x7);
            } else {
                dmemAlign = 0;
            }

            aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);

            if (dramAlign || dmemAlign) {
                aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
            }
        }

        f->sample += outCount;
        f->memin += outCount << 1;
        return ptr;
    }

    nbytes = outCount << 1;
    overFlow = f->memin + nbytes - ((s32) f->table->base + f->table->len);
    if (overFlow < 0) {
        overFlow = 0;
    }

    if (overFlow > nbytes) {
        overFlow = nbytes;
    }

    if (overFlow < nbytes) {
        if (outCount > 0) {
            nbytes -= overFlow;
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
        } else {
            dramAlign = 0;
        }

        *outp += dramAlign;
        f->sample += outCount;
        f->memin += outCount << 1;
    } else {
        f->memin += outCount << 1;
    }

    if (overFlow) {
        startZero = (outCount << 1) - overFlow;
        if (startZero < 0) {
            startZero = 0;
        }

        aClearBuffer(ptr++, startZero + *outp, overFlow);
    }

    return ptr;
}

s32 alLoadParam(void* filter, s32 paramID, void* param) {
    ALLoadFilter* load = (ALLoadFilter*) filter;
    ALFilter* base = (ALFilter*) filter;

    switch (paramID) {
        case AL_FILTER_SET_WAVETABLE:
            load->table = (ALWaveTable*) param;
            load->memin = (s32) load->table->base;
            load->sample = 0;

            switch (load->table->type) {
                case AL_ADPCM_WAVE:
                    base->handler = alAdpcmPull;
                    load->table->len = ADPCMFBYTES * ((s32) (load->table->len / ADPCMFBYTES));
                    load->bookSize = 2 * load->table->waveInfo.adpcmWave.book->order *
                                     load->table->waveInfo.adpcmWave.book->npredictors * ADPCMVSIZE;

                    if (load->table->waveInfo.adpcmWave.loop) {
                        load->loop.start = load->table->waveInfo.adpcmWave.loop->start;
                        load->loop.end = load->table->waveInfo.adpcmWave.loop->end;
                        load->loop.count = load->table->waveInfo.adpcmWave.loop->count;
                        alCopy(load->table->waveInfo.adpcmWave.loop->state, load->lstate, sizeof(ADPCM_STATE));
                    } else {
                        load->loop.start = load->loop.end = load->loop.count = 0;
                    }
                    break;

                case AL_RAW16_WAVE:
                    base->handler = alRaw16Pull;
                    if (load->table->waveInfo.rawWave.loop) {
                        load->loop.start = load->table->waveInfo.rawWave.loop->start;
                        load->loop.end = load->table->waveInfo.rawWave.loop->end;
                        load->loop.count = load->table->waveInfo.rawWave.loop->count;
                    } else {
                        load->loop.start = load->loop.end = load->loop.count = 0;
                    }
                    break;

                default:
                    break;
            }
            break;

        case AL_FILTER_RESET:
            load->lastsam = 0;
            load->first = 1;
            load->sample = 0;

            if (load->table) {
                load->memin = (s32) load->table->base;
                if (load->table->type == AL_ADPCM_WAVE) {
                    if (load->table->waveInfo.adpcmWave.loop) {
                        load->loop.count = load->table->waveInfo.adpcmWave.loop->count;
                    }
                } else if (load->table->type == AL_RAW16_WAVE) {
                    if (load->table->waveInfo.rawWave.loop) {
                        load->loop.count = load->table->waveInfo.rawWave.loop->count;
                    }
                }
            }
            break;

        default:
            break;
    }
}

static Acmd* _decodeChunk(Acmd* ptr, ALLoadFilter* f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags) {
    s32 dramAlign;
    s32 dramLoc;

    if (nbytes > 0) {
        dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
        dramAlign = dramLoc & 0x7;
        nbytes += dramAlign;
        aSetBuffer(ptr++, 0, inp, 0, nbytes + 8 - (nbytes & 0x7));
        aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else {
        dramAlign = 0;
    }

    if (flags & A_LOOP) {
        aSetLoop(ptr++, K0_TO_PHYS(f->lstate));
    }

    aSetBuffer(ptr++, 0, inp + dramAlign, outp, tsam << 1);
    aADPCMdec(ptr++, flags, K0_TO_PHYS(f->state));
    f->first = 0;

    return ptr;
}
