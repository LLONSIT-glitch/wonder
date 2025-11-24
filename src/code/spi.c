#include "common.h"


typedef enum {
    SPI_1,
    SPI_0,
    SPI_N
} SPI_TYPE;


typedef struct SpiHeader {
    u8 header[4];
    s32 decompressedSize;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} SpiHeader;

extern SpiHeader sSpiHeader;
extern u8* sSpiCompSrcPtr;
extern u8* D_8016043C;
extern u8* sSpiCompDataPtr;
extern u8* D_8016044C;
extern u8* D_80160454;
extern u8* sSpiCompSrcBase;
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

void Spi_Decompress(void);             /* extern */
void SysMem_Copy8(void*, void*, s32); /* extern */
void Spi_Compress(SPI_TYPE spiMode, s32 arg1);
void func_800C0108(s32);              /* extern */
void func_800C0194(void);             /* extern */
void func_800C0278(s32);              /* extern */
void func_800C03C8(void);             /* extern */
s32 func_800C0444(s32);               /* extern */
s32 func_800C01D4(void);              /* extern */
s32 func_800C0328(void);              /* extern */
s32 func_800C0534(s32);               /* extern */
void func_800C055C(s32);              /* extern */
static s32 Spi_Memcmp(u8* s1, u8* s2, s32 size);

#define ALIGN8(x) ((s32) (x + 7) / 8) * 8

s32 Sys_GetSPIHeaderInfoFromVaddr(s32 vAddr) {
    UNUSED s32 pad;

    SysMem_DmaCopy(vAddr, &sSpiHeader, sizeof(SpiHeader));
    if (sSpiHeader.header[0] == 'S' && sSpiHeader.header[1] == 'P' && sSpiHeader.header[2] == 'I') {
        if (sSpiHeader.header[3] != 'N') {
            return sSpiHeader.unk8 + sSpiHeader.unkC + sSpiHeader.unk10 + sizeof(SpiHeader);
        } else {
            return sSpiHeader.decompressedSize + sizeof(SpiHeader);
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
    sSpiCompSrcPtr = sp1C;
    sSpiCompSrcBase = sSpiCompSrcPtr;
    sp20 = (u8*) &sSpiHeader;
    D_80160454 = (u8*) &D_801604A8;

    // Why just not use Mem_Copy8 for this?
    for (sp24 = 0; sp24 < 8; sp24++) {
        *sp20++ = *sSpiCompSrcPtr++;
    }

    if (sSpiHeader.header[3] != 'N') {
        for (sp24 = 0; sp24 < 12; sp24++) {
            *sp20++ = *sSpiCompSrcPtr++;
        }
        D_8016044C = sSpiCompSrcPtr;
        sSpiCompSrcPtr = &sSpiCompSrcPtr[sSpiHeader.unk8];
        D_8016043C = sSpiCompSrcPtr;
        sSpiCompSrcPtr = &sSpiCompSrcPtr[sSpiHeader.unkC];
        sSpiCompDataPtr = sSpiCompSrcPtr;
        D_8016046C = D_80160454;
        D_8016045C = D_8016043C;
        D_80160460 = sSpiCompDataPtr;
        D_80160464 = D_8016044C;
    }
    if ((u32) sSpiHeader.decompressedSize < 0x10001U) {
        Spi_Decompress();
        SysMem_Free(sp1C);
        return 0;
    } else {
        SysMem_Free(sp1C);
        return -1;
    }
}

s32 Spi_DecompressAsset(u32 fileAddr, s32 size, u8* filePtr) {
    u32 i;
    u8* spiHeader; /* compiler-managed */
    void* spiFile;

    spiFile = SysMem_HeapAlloc(size + 0x10);
    if (spiFile == NULL) {
        return -1;
    }
    SysMem_DmaCopy(fileAddr, spiFile, ALIGN8(size));
    sSpiCompSrcPtr = spiFile;
    sSpiCompSrcBase = sSpiCompSrcPtr;
    spiHeader = (u8*) &sSpiHeader;
    D_80160454 = filePtr;

    // Start copying the SPI header
    for (i = 0; i < 8; i++) {
        *spiHeader++ = *sSpiCompSrcPtr++;
    }

    if (sSpiHeader.header[3] != 'N') {

        // Finish doing it
        for (i = 0; i < 12; i++) {
            *spiHeader++ = *sSpiCompSrcPtr++;
        }

        D_8016044C = sSpiCompSrcPtr;
        sSpiCompSrcPtr = &sSpiCompSrcPtr[sSpiHeader.unk8];
        D_8016043C = sSpiCompSrcPtr;
        sSpiCompSrcPtr = &sSpiCompSrcPtr[sSpiHeader.unkC];
        sSpiCompDataPtr = sSpiCompSrcPtr;
        D_8016046C = D_80160454;
        D_8016045C = D_8016043C;
        D_80160460 = sSpiCompDataPtr;
        D_80160464 = D_8016044C;
    }
    Spi_Decompress();
    SysMem_Free(spiFile);
    return 0;
}

// Compress_SPI
UNUSED u8* Spi_TestSpi_Compression(u8* arg0, s32 arg1, SPI_TYPE spiType) {
    u8* compressedPtr;
    u8* compressedOutput;
    s32 compressedSize;

    sSpiCompSrcPtr = arg0;
    compressedPtr = NULL;
    D_8016043C = SysMem_HeapAlloc(arg1);
    if (D_8016043C == NULL) {
        return NULL;
    }

    sSpiCompDataPtr = SysMem_HeapAlloc(arg1);
    if (sSpiCompDataPtr == NULL) {
        SysMem_Free(D_8016043C);
        return NULL;
    }
    D_8016044C = SysMem_HeapAlloc(arg1);
    if (D_8016044C == NULL) {
        SysMem_Free(D_8016043C);
        SysMem_Free(sSpiCompDataPtr);
        return NULL;
    }
    sSpiCompSrcBase = sSpiCompSrcPtr;
    D_8016045C = D_8016043C;
    D_80160460 = sSpiCompDataPtr;
    D_80160464 = D_8016044C;

    Spi_Compress(spiType, arg1);
    sSpiHeader.header[0] = 'S';
    sSpiHeader.header[1] = 'P';
    sSpiHeader.header[2] = 'I';
    if (spiType == SPI_0) {
        sSpiHeader.header[3] = '0';
    } else {
        sSpiHeader.header[3] = '1';
    }
    sSpiHeader.unk8 = D_8016044C - D_80160464;
    sSpiHeader.unkC = D_8016043C - D_8016045C;
    sSpiHeader.unk10 = sSpiCompDataPtr - D_80160460;
    sSpiHeader.decompressedSize = arg1;

    compressedSize = sSpiHeader.unk8 + sSpiHeader.unkC + sSpiHeader.unk10 + 0x14;
    compressedPtr = SysMem_HeapAlloc(compressedSize);
    if (compressedPtr == NULL) {
        SysMem_Free(D_8016045C);
        SysMem_Free(D_80160460);
        SysMem_Free(D_80160464);
        return NULL;
    }

    compressedOutput = compressedPtr;

    // First copy the SPI header
    SysMem_Copy8(compressedOutput, &sSpiHeader, sizeof(SpiHeader));
    
    compressedOutput += sizeof(SpiHeader);

    SysMem_Copy8(compressedOutput, D_80160464, sSpiHeader.unk8);

    compressedOutput += sSpiHeader.unk8;
    SysMem_Copy8(compressedOutput, D_8016045C, sSpiHeader.unkC);
    compressedOutput += sSpiHeader.unkC;
    SysMem_Copy8(compressedOutput, D_80160460, sSpiHeader.unk10);

    compressedOutput = compressedPtr;

    SysMem_Free(D_8016045C);
    SysMem_Free(D_80160460);
    SysMem_Free(D_80160464);
    compressedPtr = SysMem_HeapAlloc(compressedSize);
    if (compressedPtr == NULL) {
        SysMem_Free(compressedOutput);
        return NULL;
    }
    // !< Copy everything again to the compressedPtr?
    SysMem_Copy8(compressedPtr, compressedOutput, compressedSize);
    SysMem_Free(compressedOutput);
    return compressedPtr;
}

// SPI_Compress?
void Spi_Compress(SPI_TYPE spiType, s32 size) {
    UNUSED s32 pad;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    s32 sp18;

    D_80160474 = 0;
    D_8016047C = 0;
    sp28 = size;
    sp24 = 0;
    sp20 = 0;
    D_80160484 = 0;

    for (sp1C = 0; sp1C < 16; sp1C++) {
        D_80160228[sp1C] = sp1C;
    }
    D_8016042C = 0x10;

    while (sp28 > 0) {
        if ((sSpiCompSrcPtr - sSpiCompSrcBase) >= 0x1001) {
            sp24 = 0x1000;
        } else {
            sp24 = sSpiCompSrcPtr - sSpiCompSrcBase;
        }
        sp18 = sp24;


        // Sliding window?
        for (sp20 = 0, sp1C = 0; sp24 > 0; sp24--) {
            sp1C = Spi_Memcmp(sSpiCompSrcPtr, sSpiCompSrcPtr - sp24, sp28);
            if (sp1C > sp20) {
                sp18 = sp24;
                sp20 = sp1C;
            }
        }

        if (sp20 < 3) {
            func_800C0278(1);
            if (spiType == SPI_1) {
                sp1C = func_800C0444(*sSpiCompSrcPtr & 0xFF);
                if (sp1C == -1) {
                    func_800C0278(1);
                    *sSpiCompDataPtr++ = *sSpiCompSrcPtr++;
                } else {
                    func_800C0278(0);
                    func_800C0108(sp1C);
                    sSpiCompSrcPtr += 1;
                }
            } else { // SPI1 and SPIN?
                *sSpiCompDataPtr++ = *sSpiCompSrcPtr++;
            }
            sp28 -= 1;
        } else {
            func_800C0278(0);
            sSpiCompSrcPtr = &sSpiCompSrcPtr[sp20];
            sp28 -= sp20;
            sp18 -= 1;
            sp20 -= 3;
            if (sp20 >= 15) {
                *sSpiCompDataPtr++ = ((sp18 / 256) & 0xFF & 0xF) | 0xF0;
                *sSpiCompDataPtr++ = sp18 & 0xFF;

                sp20 -= 15;

                while (TRUE) {
                    if (sp20 >= 0xFF) {
                        *sSpiCompDataPtr++ = 0xFF;
                        sp20 -= 0xFF;
                    } else {
                        *sSpiCompDataPtr++ = sp20;
                        break;
                    }
                }
            } else {
                *sSpiCompDataPtr++ = (((u8) sp20 & 15) * 0x10) | ((sp18 / 256) & 255 & 15);
                *sSpiCompDataPtr++ = sp18 & 255;
            }
        }
    }
    func_800C03C8();
    func_800C0194();
}

void Spi_Decompress(void) {
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
    if (sSpiHeader.header[3] == '0') {
        while ((uintptr_t) ((uintptr_t) D_80160454 - (uintptr_t) D_8016046C) < (uintptr_t) sSpiHeader.decompressedSize) {
            if (func_800C0328() != 0) {
                *D_80160454++ = *sSpiCompDataPtr++;
            } else {
                sp28 = ((s32) sSpiCompDataPtr[0] / 16) & 0xF;
                sp2C = ((sSpiCompDataPtr[0] & 0xF) << 8) + (sSpiCompDataPtr[1] & 0xFF) + 1;
                sSpiCompDataPtr += 2;
                if (sp28 == 15) {
                    while (TRUE) {
                        if (sSpiCompDataPtr[0] == 0xFF) {
                            sp28 += 0xFF;
                            sSpiCompDataPtr += 1;
                        } else {
                            sp28 += *sSpiCompDataPtr++ & 0xFF;
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
    } else if (sSpiHeader.header[3] == '1') {
        while ((u32) ((u32) D_80160454 - (u32) D_8016046C) < (u32) sSpiHeader.decompressedSize) {

            if (func_800C0328() != 0) {
                if (func_800C0328() != 0) {
                    func_800C055C(*sSpiCompDataPtr & 255);
                    *D_80160454++ = *sSpiCompDataPtr++;
                } else {
                    *D_80160454++ = func_800C0534(func_800C01D4());
                }
            } else {
                sp28 = ((s32) *sSpiCompDataPtr / 16) & 0xF;

                sp2C = ((*sSpiCompDataPtr & 0xF) << 8) + (*(sSpiCompDataPtr + 1) & 0xFF) + 1;

                sSpiCompDataPtr += 2;

                if (sp28 == 0xF) {
                    while (TRUE) {
                        if (*sSpiCompDataPtr == 0xFF) {
                            sp28 += 0xFF;
                            sSpiCompDataPtr += 1;
                        } else {
                            sp28 += *sSpiCompDataPtr++ & 0xFF;
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
        SysMem_Copy8(D_80160454, sSpiCompSrcPtr, sSpiHeader.decompressedSize);
    }
}

// Another Spi_Memcmp func..
static s32 Spi_Memcmp(u8* s1, u8* s2, s32 size) {
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
        return *(D_8016043C - 1) & 0xF;
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
