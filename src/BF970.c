#include "common.h"

typedef struct UnkStruct_SpiFormat_80160490 {
    u8 header[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} UnkStruct_SpiFormat_80160490;

extern UnkStruct_SpiFormat_80160490 D_80160490;
extern s32 D_80160494;
extern s32 D_80160498;
extern s32 D_8016049C;
extern s32 D_801604A0;
extern u8* D_80160434;
extern u8* D_8016043C;
extern u8* D_80160444;
extern u8* D_8016044C;
extern u8* D_80160454;
extern u8* D_80160458;
extern u8* D_8016045C;
extern u8* D_80160460;
extern u8* D_80160464;
extern u8* D_8016046C;
extern u8 D_801604A8;
extern s32 D_80160228[];
extern s32 D_8016042C;
extern s32 D_80160474;
extern s32 D_8016047C;
extern s32 D_80160484;

void func_800BFB60(void);             /* extern */
void SysMem_Copy8(void*, void*, s32); /* extern */
void func_800BF6C8(s32, s32);         /* extern */
void func_800C0108(s32);              /* extern */
void func_800C0194(void);             /* extern */
void func_800C0278(s32);              /* extern */
void func_800C03C8(void);             /* extern */
s32 func_800C0444(s32);               /* extern */
s32 func_800C01D4(void);              /* extern */
s32 func_800C0328(void);              /* extern */
s32 func_800C0534(s32);               /* extern */
void func_800C055C(s32);              /* extern */
static s32 memcmp(u8* s1, u8* s2, s32 size);

#define ALIGN8(x) ((s32) (x + 7) / 8) * 8

s32 Sys_GetSPIHeaderInfoFromVaddr(s32 vAddr) {
    UNUSED s32 pad;

    SysMem_DmaCopy(vAddr, &D_80160490, sizeof(UnkStruct_SpiFormat_80160490));
    if (D_80160490.header[0] == 'S' && D_80160490.header[1] == 'P' && D_80160490.header[2] == 'I') {
        if (D_80160490.header[3] != 'N') {
            return D_80160490.unk8 + D_80160490.unkC + D_80160490.unk10 + 0x14;
        } else {
            return D_80160490.unk4 + 0x14;
        }
    } else {
        return -1;
    }
}

s32 func_800BEE48(u32 arg0, s32 arg1) {
    u32 sp24;
    u8* sp20; /* compiler-managed */
    u8* sp1C;
    u32 temp_t2;

    sp1C = SysMem_HeapAlloc(arg1 + 0x10);
    if (sp1C == NULL) {
        return -1;
    }
    SysMem_DmaCopy(arg0, sp1C, ((s32) (arg1 + 7) / 8) * 8);
    D_80160434 = sp1C;
    D_80160458 = D_80160434;
    sp20 = (u8*) &D_80160490;
    D_80160454 = (u8*) &D_801604A8;

    // Why just not use Mem_Copy8 for this?
    for (sp24 = 0; sp24 < 8; sp24++) {
        *sp20++ = *D_80160434++;
    }

    if (D_80160490.header[3] != 'N') {
        for (sp24 = 0; sp24 < 12; sp24++) {
            *sp20++ = *D_80160434++;
        }
        D_8016044C = D_80160434;
        D_80160434 = &D_80160434[D_80160498];
        D_8016043C = D_80160434;
        D_80160434 = &D_80160434[D_8016049C];
        D_80160444 = D_80160434;
        D_8016046C = D_80160454;
        D_8016045C = D_8016043C;
        D_80160460 = D_80160444;
        D_80160464 = D_8016044C;
    }
    if ((u32) D_80160494 < 0x10001U) {
        func_800BFB60();
        SysMem_Free(sp1C);
        return 0;
    } else {
        SysMem_Free(sp1C);
        return -1;
    }
}

s32 func_800BF0B4(u32 arg0, s32 size, u8* arg2) {
    u32 sp24;
    u8* sp20; /* compiler-managed */
    void* sp1C;

    sp1C = SysMem_HeapAlloc(size + 0x10);
    if (sp1C == NULL) {
        return -1;
    }
    SysMem_DmaCopy(arg0, sp1C, ALIGN8(size));
    D_80160434 = sp1C;
    D_80160458 = D_80160434;
    sp20 = (u8*) &D_80160490;
    D_80160454 = arg2;
    for (sp24 = 0; sp24 < 8; sp24++) {
        *sp20++ = *D_80160434++;
    }
    if (D_80160490.header[3] != 'N') {
        for (sp24 = 0; sp24 < 12; sp24++) {
            *sp20++ = *D_80160434++;
        }
        D_8016044C = D_80160434;
        D_80160434 = &D_80160434[D_80160498];
        D_8016043C = D_80160434;
        D_80160434 = &D_80160434[D_8016049C];
        D_80160444 = D_80160434;
        D_8016046C = D_80160454;
        D_8016045C = D_8016043C;
        D_80160460 = D_80160444;
        D_80160464 = D_8016044C;
    }
    func_800BFB60();
    SysMem_Free(sp1C);
    return 0;
}

UNUSED UnkStruct_SpiFormat_80160490* func_800BF2E8(u8* arg0, s32 arg1, s32 arg2) {
    UnkStruct_SpiFormat_80160490* sp24;
    UnkStruct_SpiFormat_80160490* sp20;
    s32 sp1C;

    D_80160434 = arg0;
    sp24 = NULL;
    D_8016043C = SysMem_HeapAlloc(arg1);
    if (D_8016043C == NULL) {
        return NULL;
    }
    D_80160444 = SysMem_HeapAlloc(arg1);
    if (D_80160444 == NULL) {
        SysMem_Free(D_8016043C);
        return NULL;
    }
    D_8016044C = SysMem_HeapAlloc(arg1);
    if (D_8016044C == NULL) {
        SysMem_Free(D_8016043C);
        SysMem_Free(D_80160444);
        return NULL;
    }
    D_80160458 = D_80160434;
    D_8016045C = D_8016043C;
    D_80160460 = D_80160444;
    D_80160464 = D_8016044C;
    func_800BF6C8(arg2, arg1);
    D_80160490.header[0] = 'S';
    D_80160490.header[1] = 'P';
    D_80160490.header[2] = 'I';
    if (arg2 == 1) {
        D_80160490.header[3] = '0';
    } else {
        D_80160490.header[3] = '1';
    }
    D_80160498 = D_8016044C - D_80160464;
    D_8016049C = D_8016043C - D_8016045C;
    D_801604A0 = D_80160444 - D_80160460;
    D_80160494 = arg1;
    sp1C = D_80160498 + D_8016049C + D_801604A0 + 0x14;
    sp24 = SysMem_HeapAlloc(sp1C);
    if (sp24 == NULL) {
        SysMem_Free(D_8016045C);
        SysMem_Free(D_80160460);
        SysMem_Free(D_80160464);
        return NULL;
    }
    sp20 = sp24;
    SysMem_Copy8(sp20, &D_80160490, 0x14);
    sp20++;
    SysMem_Copy8(sp20, (void*) D_80160464, D_80160498);
    sp20 = (void*) &sp20->header[D_80160498];
    SysMem_Copy8((void*) sp20, (void*) D_8016045C, D_8016049C);
    sp20 = (void*) &sp20->header[D_8016049C];
    SysMem_Copy8((void*) sp20, (void*) D_80160460, D_801604A0);
    sp20 = sp24;
    SysMem_Free(D_8016045C);
    SysMem_Free(D_80160460);
    SysMem_Free(D_80160464);
    sp24 = SysMem_HeapAlloc(sp1C);
    if (sp24 == NULL) {
        SysMem_Free(sp20);
        return NULL;
    }
    SysMem_Copy8(sp24, sp20, sp1C);
    SysMem_Free(sp20);
    return sp24;
}

void func_800BF6C8(s32 arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    s32 sp18;

    D_80160474 = 0;
    D_8016047C = 0;
    sp28 = arg1;
    sp24 = 0;
    sp20 = 0;
    D_80160484 = 0;

    for (sp1C = 0; sp1C < 16; sp1C++) {
        D_80160228[sp1C] = sp1C;
    }
    D_8016042C = 0x10;

    while (sp28 > 0) {
        if ((D_80160434 - D_80160458) >= 0x1001) {
            sp24 = 0x1000;
        } else {
            sp24 = D_80160434 - D_80160458;
        }
        sp18 = sp24;

        for (sp20 = 0, sp1C = 0; sp24 > 0; sp24--) {
            sp1C = memcmp(D_80160434, D_80160434 - sp24, sp28);
            if (sp1C > sp20) {
                sp18 = sp24;
                sp20 = sp1C;
            }
        }
        if (sp20 < 3) {
            func_800C0278(1);
            if (arg0 == 0) {
                sp1C = func_800C0444(*D_80160434 & 0xFF);
                if (sp1C == -1) {
                    func_800C0278(1);
                    *D_80160444++ = *D_80160434++;
                } else {
                    func_800C0278(0);
                    func_800C0108(sp1C);
                    D_80160434 += 1;
                }
            } else {
                *D_80160444++ = *D_80160434++;
            }
            sp28 -= 1;
        } else {
            func_800C0278(0);
            D_80160434 = &D_80160434[sp20];
            sp28 -= sp20;
            sp18 -= 1;
            sp20 -= 3;
            if (sp20 >= 0xF) {
                *D_80160444++ = ((sp18 / 256) & 0xFF & 0xF) | 0xF0;
                *D_80160444++ = sp18 & 0xFF;

                sp20 -= 15;

                while (TRUE) {
                    if (sp20 >= 0xFF) {
                        *D_80160444++ = 0xFF;
                        sp20 -= 0xFF;
                    } else {
                        *D_80160444++ = sp20;
                        break;
                    }
                }
            } else {
                *D_80160444++ = (((u8) sp20 & 15) * 0x10) | ((sp18 / 256) & 255 & 15);
                *D_80160444++ = sp18 & 255;
            }
        }
    }
    func_800C03C8();
    func_800C0194();
}

void func_800BFB60(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    D_8016047C = 0;
    sp28 = 0;
    sp2C = 0;
    D_80160484 = 0;

    for (sp24 = 0; sp24 < 16; sp24++) {
        D_80160228[sp24] = sp24;
    }
    D_8016042C = 0x10;

    // SPI0
    if (D_80160490.header[3] == '0') {
        while ((uintptr_t) ((uintptr_t) D_80160454 - (uintptr_t) D_8016046C) < (uintptr_t) D_80160494) {
            if (func_800C0328() != 0) {
                *D_80160454++ = *D_80160444++;
            } else {
                sp28 = ((s32) D_80160444[0] / 16) & 0xF;
                sp2C = ((D_80160444[0] & 0xF) << 8) + (D_80160444[1] & 0xFF) + 1;
                D_80160444 += 2;
                if (sp28 == 15) {
                    while (TRUE) {
                        if (D_80160444[0] == 0xFF) {
                            sp28 += 0xFF;
                            D_80160444 += 1;
                        } else {
                            sp28 += *D_80160444++ & 0xFF;
                            break;
                        }
                    }
                }
                sp28 += 3;
                for (; sp28 > 0; sp28--, D_80160454++) {
                    *D_80160454 = *(D_80160454 - sp2C);
                }
            }
        }

        // SPI1
    } else if (D_80160490.header[3] == '1') {
        while ((u32) ((u32) D_80160454 - (u32) D_8016046C) < (u32) D_80160494) {

            if (func_800C0328() != 0) {
                if (func_800C0328() != 0) {
                    func_800C055C(D_80160444[0] & 0xFF);
                    *D_80160454++ = *D_80160444++;
                } else {
                    *D_80160454++ = func_800C0534(func_800C01D4());
                }
            } else {
                sp28 = ((s32) D_80160444[0] / 16) & 0xF;

                sp2C = ((D_80160444[0] & 0xF) << 8) + (D_80160444[1] & 0xFF) + 1;

                D_80160444 += 2;

                if (sp28 == 0xF) {
                    while (TRUE) {
                        if (D_80160444[0] == 0xFF) {
                            sp28 += 0xFF;
                            D_80160444 += 1;
                        } else {
                            sp28 += *D_80160444++ & 0xFF;
                            break;
                        }
                    }
                }
                sp28 += 3;
                for (; sp28 > 0; sp28--, D_80160454++) {
                    *D_80160454 = *(D_80160454 - sp2C);
                }
            }
        }
    } else {
        SysMem_Copy8(D_80160454, D_80160434, D_80160494);
    }
}

// Another memcmp func..
static s32 memcmp(u8* s1, u8* s2, s32 size) {
    s32 i;

    for (i = 0; i < size; i++) {
        if (*s1++ != *s2++) {
            break;
        }
    }

    return i;
}

void func_800C0108(s32 arg0) {
    if (D_80160484 == 0) {
        *D_8016043C = ((arg0 & 255) * 0x10) & 0xF0;
        D_80160484 += 1;
    } else {
        *D_8016043C |= arg0 & 0xFF & 0xF;
        D_8016043C += 1;
        D_80160484 = 0;
    }
}

void func_800C0194(void) {
    if (D_80160484 != 0) {
        D_8016043C += 1;
        D_80160484 = 0;
    }
}

s32 func_800C01D4(void) {
    if (D_80160484 == 0) {
        D_80160484 += 1;
        return ((s32) D_8016043C[0] >> 4) & 0xF;
    } else {
        D_8016043C += 1;
        D_80160484 = 0;
        return D_8016043C[-1] & 0xF;
    }
}

void func_800C0278(s32 arg0) {
    if (D_8016047C == 8) {
        D_8016047C = 0;
        D_8016044C += 1;
    }
    *D_8016044C *= 2;
    *D_8016044C &= 0xFE;
    if (arg0 != 0) {
        *D_8016044C |= 1;
    }
    D_8016047C += 1;
}

s32 func_800C0328(void) {
    s32 sp4;

    if (D_8016047C == 8) {
        D_8016047C = 0;
        D_8016044C += 1;
    }
    sp4 = 0;
    if (*D_8016044C & (0x80 >> D_8016047C)) {
        sp4 += 1;
    }
    D_8016047C += 1;
    return sp4;
}

void func_800C03C8(void) {
    while (D_8016047C != 8) {
        *D_8016044C *= 2;
        D_8016047C += 1;
    }
    D_8016044C++;
}

s32 func_800C0444(s32 arg0) {
    s32 sp24;

    for (sp24 = 0; sp24 < (D_8016042C >= 16 ? 15 : D_8016042C); sp24++) {
        if (D_80160228[sp24] == arg0) {
            return sp24;
        }
    }

    func_800C055C(arg0);
    return -1;
}

s32 func_800C0534(s32 arg0) {
    return D_80160228[arg0];
}

void func_800C055C(s32 arg0) {
    D_80160228[D_8016042C & 15] = arg0;
    D_8016042C++;
}
