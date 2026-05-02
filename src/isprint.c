#if 0
#include <ultra64.h>
#include <os/PRinternal/piint.h>
#include "PRinternal/macros.h"
#include "string.h"
#include "stdarg.h"
#include "xstdio.h"

#ifdef ISPRINT
#define isdigit(x) ((x >= '0' && x <= '9'))
#define LDSIGN(x) (((unsigned short*) &(x))[0] & 0x8000)

#define ATOI(dst, src)                    \
    for (dst = 0; isdigit(*src); ++src) { \
        if (dst < 999)                    \
            dst = dst * 10 + *src - '0';  \
    }

#define MAX_PAD ((sizeof(spaces) - 1))
#define PAD(s, n)                                               \
    if (0 < (n)) {                                              \
        int i, j = (n);                                         \
        for (; 0 < j; j -= i) {                                 \
            i = MAX_PAD < (unsigned int) j ? (int) MAX_PAD : j; \
            PUT(s, i);                                          \
        }                                                       \
    }
#define PUT(s, n)                              \
    if (0 < (n)) {                             \
        if ((arg = (*pfn)(arg, s, n)) != NULL) \
            x.nchar += (n);                    \
        else                                   \
            return x.nchar;                    \
    }
static char spaces[] = "                                ";
static char zeroes[] = "00000000000000000000000000000000";

#define LITOB_LDTOB_BUFF_LEN 0x18

static char ldigs[] = "0123456789abcdef";
static char udigs[] = "0123456789ABCDEF";

static const ldouble pows[] = { 10e0L, 10e1L, 10e3L, 10e7L, 10e15L, 10e31L, 10e63L, 10e127L, 10e255L };

// float properties
#define _D0 0
#define _DBIAS 0x3ff
#define _DLONG 1
#define _DOFF 4
#define _FBIAS 0x7e
#define _FOFF 7
#define _FRND 1
#define _LBIAS 0x3ffe
#define _LOFF 15
// integer properties
#define _C2 1
#define _CSIGN 1
#define _ILONG 0
#define _MBMAX 8
#define NAN 2
#define INF 1
#define FINITE -1
#define _DFRAC ((1 << _DOFF) - 1)
#define _DMASK (0x7fff & ~_DFRAC)
#define _DMAX ((1 << (15 - _DOFF)) - 1)
#define _DNAN (0x8000 | _DMAX << _DOFF | 1 << (_DOFF - 1))
#define _DSIGN 0x8000
#define _D1 1 // big-endian order
#define _D2 2
#define _D3 3

#define ALIGN(s, align) (((unsigned int) (s) + ((align) - 1)) & ~((align) - 1))

#define LDTOB_BUFF_LEN 0x20

static short _Ldunscale(short* pex, ldouble* px);
static void _Genld(_Pft* px, char code, unsigned char* p, short nsig, short xexp);

void _Ldtob(_Pft* px, char code) {
    char buff[LDTOB_BUFF_LEN];
    char* p;
    ldouble ldval;
    short err;
    short nsig;
    short xexp;

    p = buff;
    ldval = px->v.ld;

    if (px->prec < 0) {
        px->prec = 6;
    } else if (px->prec == 0 && (code == 'g' || code == 'G')) {
        px->prec = 1;
    }

    err = _Ldunscale(&xexp, &px->v.ld);
    if (err > 0) {
        memcpy(px->s, err == 2 ? "NaN" : "Inf", px->n1 = 3);
        return;
    } else if (err == 0) {
        nsig = 0;
        xexp = 0;
    } else {
        {
            int i;
            int n;

            if (ldval < 0) {
                ldval = -ldval;
            }

            // what
            if ((xexp = xexp * 30103 / 100000 - 4) < 0) {
                n = ALIGN(-xexp, 4), xexp = -n;

                for (i = 0; n > 0; n >>= 1, i++) {
                    if (n & 1) {
                        ldval *= pows[i];
                    }
                }
            } else if (xexp > 0) {
                ldouble factor = 1;

                xexp &= ~3;

                for (n = xexp, i = 0; n > 0; n >>= 1, i++) {
                    if (n & 1) {
                        factor *= pows[i];
                    }
                }

                ldval /= factor;
            }
        }
        {
            int gen = px->prec + ((code == 'f') ? 10 + xexp : 6);

            if (gen > 0x13) {
                gen = 0x13;
            }

            for (*p++ = '0'; gen > 0 && 0 < ldval; p += 8) {
                int j;
                long lo = ldval;

                if ((gen -= 8) > 0) {
                    ldval = (ldval - lo) * 1e8;
                }

                for (p += 8, j = 8; lo > 0 && --j >= 0;) {
                    ldiv_t qr;
                    qr = ldiv(lo, 10);
                    *--p = qr.rem + '0', lo = qr.quot;
                }

                while (--j >= 0) {
                    *--p = '0';
                }
            }

            gen = p - &buff[1];

            for (p = &buff[1], xexp += 7; *p == '0'; p++) {
                --gen, --xexp;
            }

            nsig = px->prec + ((code == 'f') ? xexp + 1 : ((code == 'e' || code == 'E') ? 1 : 0));

            if (gen < nsig) {
                nsig = gen;
            }

            if (nsig > 0) {
                const char drop = nsig < gen && '5' <= p[nsig] ? '9' : '0';
                int n;

                for (n = nsig; p[--n] == drop;) {
                    --nsig;
                }

                if (drop == '9') {
                    ++p[n];
                }

                if (n < 0) {
                    --p, ++nsig, ++xexp;
                }
            }
        }
    }

    _Genld(px, code, p, nsig, xexp);
}

short _Ldunscale(short* pex, ldouble* px) {
    unsigned short* ps = (unsigned short*) px;
    short xchar = (ps[_D0] & _DMASK) >> _DOFF;

    if (xchar == _DMAX) {
        *pex = 0;

        return (ps[_D0] & _DFRAC) || ps[_D1] || ps[_D2] || ps[_D3] ? 2 : 1;
    } else if (xchar > 0) {
        ps[_D0] = (ps[_D0] & ~_DMASK) | 0x3FF0;
        *pex = xchar - 0x3FE;
        return -1;
    } else if (xchar < 0) {
        return 2;
    } else {
        *pex = 0;
        return 0;
    }
}

void _Genld(_Pft* px, char code, unsigned char* p, short nsig, short xexp) {
    const unsigned char point = '.';

    if (nsig <= 0) {
        nsig = 1, p = "0";
    }

    if (code == 'f' || (code == 'g' || code == 'G') && xexp >= -4 && xexp < px->prec) {
        xexp++;
        if (code != 'f') {
            if (((px->flags & 8) == 0) && nsig < px->prec) {
                px->prec = nsig;
            }

            if ((px->prec -= xexp) < 0) {
                px->prec = 0;
            }
        }

        if (xexp <= 0) {
            px->s[px->n1++] = '0';

            if (px->prec > 0 || (px->flags & 8)) {
                px->s[px->n1++] = point;
            }

            if (px->prec < -xexp) {
                xexp = -px->prec;
            }

            px->nz1 = -xexp;
            px->prec += xexp;

            if (px->prec < nsig) {
                nsig = px->prec;
            }

            memcpy(&px->s[px->n1], p, px->n2 = nsig);
            px->nz2 = px->prec - nsig;
        } else if (nsig < xexp) {
            memcpy(&px->s[px->n1], p, nsig);
            px->n1 += nsig;
            px->nz1 = xexp - nsig;
            if (px->prec > 0 || (px->flags & 8)) {
                px->s[px->n1] = point;
                px->n2++;
            }

            px->nz2 = px->prec;
        } else {
            memcpy(&px->s[px->n1], p, xexp);
            px->n1 += xexp;
            nsig -= xexp;

            if (px->prec > 0 || (px->flags & 8)) {
                px->s[px->n1++] = point;
            }

            if (px->prec < nsig) {
                nsig = px->prec;
            }

            memcpy(&px->s[px->n1], &p[xexp], nsig);
            px->n1 += nsig;
            px->nz1 = px->prec - nsig;
        }
    } else {
        if (code == 'g' || code == 'G') {
            if (nsig < px->prec) {
                px->prec = nsig;
            }

            if (--px->prec < 0) {
                px->prec = 0;
            }

            code = (code == 'g') ? 'e' : 'E';
        }

        px->s[px->n1++] = *p++;

        if (px->prec > 0 || (px->flags & 8)) {
            px->s[px->n1++] = point;
        }

        if (px->prec > 0) {
            if (px->prec < --nsig) {
                nsig = px->prec;
            }

            memcpy(&px->s[px->n1], p, nsig);
            px->n1 += nsig;
            px->nz1 = px->prec - nsig;
        }

        p = &px->s[px->n1];
        *p++ = code;

        if (xexp >= 0) {
            *p++ = '+';
        } else {
            *p++ = '-';
            xexp = -xexp;
        }

        if (xexp >= 100) {
            if (xexp >= 1000) {
                *p++ = (xexp / 1000) + '0', xexp %= 1000;
            }
            *p++ = (xexp / 100) + '0', xexp %= 100;
        }
        *p++ = (xexp / 10) + '0', xexp %= 10;

        *p++ = xexp + '0';
        px->n2 = (size_t) p - ((size_t) px->s + px->n1);
    }

    if ((px->flags & 0x14) == 0x10) {
        int n = px->n0 + px->n1 + px->nz1 + px->n2 + px->nz2;

        if (n < px->width) {
            px->nz0 = px->width - n;
        }
    }
}

ldiv_t ldiv(long num, long denom) {
    ldiv_t ret;

    ret.quot = num / denom;
    ret.rem = num - denom * ret.quot;

    if (ret.quot < 0 && ret.rem > 0) {
        ret.quot += 1;
        ret.rem -= denom;
    }

    return ret;
}

lldiv_t lldiv(long long num, long long denom) {
    lldiv_t ret;

    ret.quot = num / denom;
    ret.rem = num - denom * ret.quot;

    if (ret.quot < 0 && ret.rem > 0) {
        ret.quot += 1;
        ret.rem -= denom;
    }

    return ret;
}

void _Litob(_Pft* px, char code) {
    char buff[LITOB_LDTOB_BUFF_LEN];
    const char* digs;
    int base;
    int i;
    unsigned long long ullval;

    digs = (code == 'X') ? udigs : ldigs;

    base = (code == 'o') ? 8 : ((code != 'x' && code != 'X') ? 10 : 16);
    i = LITOB_LDTOB_BUFF_LEN;
    ullval = px->v.ll;

    if ((code == 'd' || code == 'i') && px->v.ll < 0) {
        ullval = -ullval;
    }

    if (ullval != 0 || px->prec != 0) {
        buff[--i] = digs[ullval % base];
    }

    px->v.ll = ullval / base;

    while (px->v.ll > 0 && i > 0) {
        lldiv_t qr = lldiv(px->v.ll, base);

        px->v.ll = qr.quot;
        buff[--i] = digs[qr.rem];
    }

    px->n1 = LITOB_LDTOB_BUFF_LEN - i;

    memcpy(px->s, buff + i, px->n1);

    if (px->n1 < px->prec) {
        px->nz0 = px->prec - px->n1;
    }

    if (px->prec < 0 && (px->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO) {
        if ((i = px->width - px->n0 - px->nz0 - px->n1) > 0) {
            px->nz0 += i;
        }
    }
}

static void _Putfld(_Pft* px, va_list* pap, char code, char* ac);

char* strchr(const char* s, int c) {
    const char ch = c;
    while (*s != ch) {
        if (*s == 0) {
            return NULL;
        }
        s++;
    }
    return (char*) s;
}

size_t strlen(const char* s) {
    const char* sc = s;
    while (*sc != 0) {
        sc++;
    }
    return sc - s;
}

void* memcpy(void* s1, const void* s2, size_t n) {
    char* su1 = (char*) s1;
    const char* su2 = (const char*) s2;
    while (n > 0) {
        *su1 = *su2;
        su1++;
        su2++;
        n--;
    }
    return (void*) s1;
}

int _Printf(void* pfn(void*, const char*, size_t), void* arg, const char* fmt, va_list ap) {
    _Pft x;

    x.nchar = 0;

    while (1) {
        const char* s;
        char c;
        const char* t;
        static const char fchar[] = { ' ', '+', '-', '#', '0', '\0' };
        static const unsigned int fbit[] = { FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0 };
        char ac[32];
        s = fmt;

        for (c = *s; c != 0 && c != '%';) {
            c = *++s;
        }

        PUT(fmt, s - fmt);

        if (c == 0) {
            return x.nchar;
        }

        fmt = ++s;

        for (x.flags = 0; (t = strchr(fchar, *s)) != NULL; s++) {
            x.flags |= fbit[t - fchar];
        }

        if (*s == '*') {
            x.width = va_arg(ap, int);

            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= FLAGS_MINUS;
            }
            s++;
        } else
            ATOI(x.width, s);

        if (*s != '.') {
            x.prec = -1;
        } else if (*++s == '*') {
            x.prec = va_arg(ap, int);
            ++s;
        } else
            for (x.prec = 0; isdigit(*s); s++) {
                if (x.prec < 999)
                    x.prec = x.prec * 10 + *s - '0';
            }

        x.qual = strchr("hlL", *s) ? *s++ : '\0';

        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            ++s;
        }

        _Putfld(&x, &ap, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;

        {

            if (!(x.flags & FLAGS_MINUS)) {
                int i, j;
                if (0 < (x.width)) {
                    i, j = x.width;
                    for (; 0 < j; j -= i) {
                        i = MAX_PAD < (unsigned int) j ? (int) MAX_PAD : j;
                        PUT(spaces, i);
                    }
                }
            }

            PUT(ac, x.n0);
            PAD(zeroes, x.nz0)

            PUT(x.s, x.n1);
            PAD(zeroes, x.nz1);

            PUT(x.s + x.n1, x.n2);
            PAD(zeroes, x.nz2);

            if (x.flags & FLAGS_MINUS) {
                PAD(spaces, x.width);
            }
        }
        fmt = s + 1;
    }
    return 0;
}

static void _Putfld(_Pft* px, va_list* pap, char code, char* ac) {
    px->n0 = px->nz0 = px->n1 = px->nz1 = px->n2 = px->nz2 = 0;

    switch (code) {
        case 'c':
            ac[px->n0++] = va_arg(*pap, int);
            break;
        case 'd':
        case 'i':
            if (px->qual == 'l') {
                px->v.ll = va_arg(*pap, long);
            } else if (px->qual == 'L') {
                px->v.ll = va_arg(*pap, long long);
            } else {
                px->v.ll = va_arg(*pap, int);
            }

            if (px->qual == 'h') {
                px->v.ll = (short) px->v.ll;
            }

            if (px->v.ll < 0) {
                ac[px->n0++] = '-';
            } else if (px->flags & FLAGS_PLUS) {
                ac[px->n0++] = '+';
            } else if (px->flags & FLAGS_SPACE) {
                ac[px->n0++] = ' ';
            }

            px->s = (char*) &ac[px->n0];

            _Litob(px, code);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            if (px->qual == 'l') {
                px->v.ll = va_arg(*pap, long);
            } else if (px->qual == 'L') {
                px->v.ll = va_arg(*pap, long long);
            } else {
                px->v.ll = va_arg(*pap, int);
            }

            if (px->qual == 'h') {
                px->v.ll = (unsigned short) px->v.ll;
            } else if (px->qual == 0) {
                px->v.ll = (unsigned int) px->v.ll;
            }

            if (px->flags & FLAGS_HASH) {
                ac[px->n0++] = '0';

                if (code == 'x' || code == 'X') {
                    ac[px->n0++] = code;
                }
            }

            px->s = (char*) &ac[px->n0];
            _Litob(px, code);
            break;
        case 'e':
        case 'f':
        case 'g':
        case 'E':
        case 'G':
            px->v.ld = px->qual == 'L' ? va_arg(*pap, ldouble) : va_arg(*pap, double);

            if (LDSIGN(px->v.ld))
                ac[px->n0++] = '-';
            else if (px->flags & FLAGS_PLUS)
                ac[px->n0++] = '+';
            else if (px->flags & FLAGS_SPACE)
                ac[px->n0++] = ' ';

            px->s = (char*) &ac[px->n0];
            _Ldtob(px, code);
            break;

        case 'n':
            if (px->qual == 'h') {
                *va_arg(*pap, unsigned short*) = px->nchar;
            } else if (px->qual == 'l') {
                *va_arg(*pap, unsigned long*) = px->nchar;
            } else if (px->qual == 'L') {
                *va_arg(*pap, unsigned long long*) = px->nchar;
            } else {
                *va_arg(*pap, unsigned int*) = px->nchar;
            }

            break;
        case 'p':
            px->v.ll = (long) va_arg(*pap, void*);
            px->s = (char*) &ac[px->n0];
            _Litob(px, 'x');
            break;
        case 's':
            px->s = va_arg(*pap, char*);
            px->n1 = strlen(px->s);

            if (px->prec >= 0 && px->prec < px->n1) {
                px->n1 = px->prec;
            }

            break;
        case '%':
            ac[px->n0++] = '%';
            break;
        default:
            ac[px->n0++] = code;
            break;
    }
}

// Most of the code here is from libdragon https://github.com/DragonMinded/libdragon/blob/trunk/src/debug.c
// with small changes to make it work with libultra

/** ISViewer register for magic value (to check ISViewer presence) */
#define ISVIEWER_MAGIC 0x13FF0000
/** ISViewer register for circular buffer write pointer */
#define ISVIEWER_WRITE_POINTER 0x13FF0014
/** ISViewer buffer */
#define ISVIEWER_BUFFER 0x13FF0020
/** ISViewer buffer length */
#define ISVIEWER_BUFFER_LEN 0x00000200 // Buffer size is configurable on real ISViewer, it's usually 64kB - 0x20

static u8 sISViewerInitialized = 0;

void ISViewer_Init(void) {
    // To check whether an ISViewer is present (probably emulated),
    // write some data to the "magic" register. If we can read it
    // back, it means that there's some memory there and we can
    // hopefully use it.

    // Magic value is different than what official ISViewer code used, but since
    // libdragon doesn't implement correct access pattern (circular buffer)
    // we want to differentiate our implementation from the real thing
    const u32 magic = 0x12345678;

    // Write inverted magic value to check if the memory is truly writable,
    // and to make sure there's no residual value that's equal to our magic value
    IO_WRITE(ISVIEWER_MAGIC, ~magic);
    if (IO_READ(ISVIEWER_MAGIC) != ~magic) {
        sISViewerInitialized = 0;
        return;
    }

    IO_WRITE(ISVIEWER_MAGIC, magic);
    sISViewerInitialized = IO_READ(ISVIEWER_MAGIC) == magic;
}

static void ISViewer_Write(const u8* data, int len) {
    int i;
    while (len > 0) {
        u32 l = len < ISVIEWER_BUFFER_LEN ? len : ISVIEWER_BUFFER_LEN;

        // Write 32-bit aligned words to copy the buffer. Notice that
        // we might overflow the input buffer if it's not a multiple
        // of 4 bytes but it doesn't matter because we are going to
        // write the exact number of bytes later.
        for (i = 0; i < l; i += 4) {
            u32 value = ((u32) data[0] << 24) | ((u32) data[1] << 16) | ((u32) data[2] << 8) | ((u32) data[3] << 0);
            IO_WRITE(ISVIEWER_BUFFER + i, value);
            data += 4;
        }

        // Flush the data into the ISViewer
        // We use write pointer register as length register,
        // but that's fine for emulators that usually doesn't
        // update the read and write pointers anyways.
        IO_WRITE(ISVIEWER_WRITE_POINTER, l);
        len -= l;
    }
}

static char* ISViwer_ProutPrintf(char* arg, const char* str, size_t count) {
    ISViewer_Write(str, count);
    return 1;
}

void osSyncPrintf(const char* fmt, ...) {
    va_list args;

    if (!sISViewerInitialized) {
        return;
    }

    va_start(args, fmt);
    _Printf(ISViwer_ProutPrintf, NULL, fmt, args);
    va_end(args);
}
#endif
#endif
