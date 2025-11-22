#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include <linux/swab.h>

#define UNUSED

typedef enum {
    OPTION_COMPRESS = 'c',
    OPTION_DECOMPRESS = 'd',
    OPTION_INPUT_FILE = 'i',
    OPTION_OUTPUT_FILE = 'o',
    OPTION_HELP = 'h'
} OPTIONS;

typedef enum { COMPRESS, DECOMPRESS } PROGRAM_ACTION;

typedef enum { SPI_1, SPI_0 } SPI_TYPE;

typedef struct SpiHeader {
    uint8_t header[4];
    int32_t fileSize;
    int32_t unk8;
    int32_t unkC;
    int32_t unk10;
} SpiHeader;

int D_80160228[16];

int D_8016042C;
int D_80160474;
int D_8016047C;
int D_80160484;

uint8_t* D_8016043C;
uint8_t* D_8016044C;
uint8_t* sSpiCompDataPtr;
uint8_t* sSpiCompSrcPtr;
uint8_t* sSpiCompSrcBase;

uint8_t* D_8016045C;
uint8_t* sSpiCompDataPtrBase;
uint8_t* D_80160464;

extern int optind;
extern char* optarg;

void func_800C055C(int arg0);

static int customMemCmp(uint8_t* s1, uint8_t* s2, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (*s1++ != *s2++) {
            break;
        }
    }
    return i;
}

void func_800C0278(int arg0) {
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

void func_800C0108(int arg0) {
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

int func_800C01D4(void) {
    if (D_80160484 == 0) {
        D_80160484 += 1;
        return ((int) D_8016043C[0] >> 4) & 0xF;
    } else {
        D_8016043C += 1;
        D_80160484 = 0;
        return *(D_8016043C - 1) & 0xF;
    }
}


int func_800C0328(void) {
    int sp4;
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

int func_800C0444(int arg0) {
    int sp24;
    for (sp24 = 0; sp24 < (D_8016042C >= 16 ? 15 : D_8016042C); sp24++) {
        if (D_80160228[sp24] == arg0) {
            return sp24;
        }
    }
    func_800C055C(arg0);
    return -1;
}

int func_800C0534(int arg0) {
    return D_80160228[arg0];
}

void func_800C055C(int arg0) {
    D_80160228[D_8016042C & 15] = arg0;
    D_8016042C++;
}

void CompressSPI(SPI_TYPE spiType, int size) {
    UNUSED int pad;
    int compressSize; // maybe?
    int sp24;
    int sp20;
    int sp1C;
    int sp18;

    D_80160474 = 0;
    D_8016047C = 0;
    compressSize = size;
    sp24 = 0;
    sp20 = 0;
    D_80160484 = 0;

    for (sp1C = 0; sp1C < 16; sp1C++) {
        D_80160228[sp1C] = sp1C;
    }
    D_8016042C = 0x10;

    while (compressSize > 0) {
        if ((sSpiCompSrcPtr - sSpiCompSrcBase) >= 0x1001) {
            sp24 = 0x1000;
        } else {
            sp24 = sSpiCompSrcPtr - sSpiCompSrcBase;
        }
        sp18 = sp24;

        // Sliding window search — customMemCmp returns match length
        for (sp20 = 0, sp1C = 0; sp24 > 0; sp24--) {
            sp1C = customMemCmp(sSpiCompSrcPtr, sSpiCompSrcPtr - sp24, compressSize);
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
            } else {
                *sSpiCompDataPtr++ = *sSpiCompSrcPtr++;
            }
            compressSize -= 1;
        } else {
            func_800C0278(0);
            sSpiCompSrcPtr = &sSpiCompSrcPtr[sp20];
            compressSize -= sp20;
            sp18 -= 1;
            sp20 -= 3;
            if (sp20 >= 15) {
                *sSpiCompDataPtr++ = ((sp18 / 256) & 0xFF & 0xF) | 0xF0;
                *sSpiCompDataPtr++ = sp18 & 0xFF;
                sp20 -= 15;
                while (true) {
                    if (sp20 >= 0xFF) {
                        *sSpiCompDataPtr++ = 0xFF;
                        sp20 -= 0xFF;
                    } else {
                        *sSpiCompDataPtr++ = sp20;
                        break;
                    }
                }
            } else {
                *sSpiCompDataPtr++ = (((uint8_t) sp20 & 15) * 0x10) | ((sp18 / 256) & 255 & 15);
                *sSpiCompDataPtr++ = sp18 & 255;
            }
        }
    }
    func_800C03C8();
    func_800C0194();
}

uint8_t* Compress(uint8_t* buf, int buffersSize, SPI_TYPE spiType, int* outCompressedSize) {
    uint8_t* compressedPtr = NULL;
    uint8_t* tempBits = NULL;
    uint8_t* tempNibbles = NULL;
    uint8_t* tempData = NULL;
    int compressedSize;

    static SpiHeader sSpiHeader;

    sSpiCompSrcPtr = buf;

    tempNibbles = (uint8_t*) malloc(buffersSize);
    tempData = (uint8_t*) malloc(buffersSize);
    tempBits = (uint8_t*) malloc(buffersSize);
    if (tempNibbles == NULL || tempData == NULL || tempBits == NULL) {
        free(tempNibbles);
        free(tempData);
        free(tempBits);
        return NULL;
    }

    /* setup write pointers */
    D_8016043C = tempNibbles;
    sSpiCompDataPtr = tempData;
    D_8016044C = tempBits;

    sSpiCompSrcBase = sSpiCompSrcPtr;
    D_8016045C = D_8016043C;
    sSpiCompDataPtrBase = sSpiCompDataPtr;
    D_80160464 = D_8016044C;

    /* do compression into working buffers */
    CompressSPI(spiType, buffersSize);

    /* fill header */
    sSpiHeader.header[0] = 'S';
    sSpiHeader.header[1] = 'P';
    sSpiHeader.header[2] = 'I';
    sSpiHeader.header[3] = (spiType == SPI_0) ? '0' : '1';

    sSpiHeader.unk8 = (int) (D_8016044C - D_80160464);
    sSpiHeader.unkC = (int) (D_8016043C - D_8016045C);
    sSpiHeader.unk10 = (int) (sSpiCompDataPtr - sSpiCompDataPtrBase);
    sSpiHeader.fileSize = buffersSize;

    compressedSize = sSpiHeader.unk8 + sSpiHeader.unkC + sSpiHeader.unk10 + (int) sizeof(SpiHeader);

    /* allocate final buffer once and copy into it */
    compressedPtr = (uint8_t*) malloc(compressedSize);
    if (!compressedPtr) {
        free(tempNibbles);
        free(tempData);
        free(tempBits);
        return NULL;
    }

    uint8_t* p = compressedPtr;
    memcpy(p, &sSpiHeader, sizeof(SpiHeader));
    p += sizeof(SpiHeader);

    if (sSpiHeader.unk8 > 0) {
        memcpy(p, D_80160464, sSpiHeader.unk8);
    }

    p += sSpiHeader.unk8;

    if (sSpiHeader.unkC > 0) {
        memcpy(p, D_8016045C, sSpiHeader.unkC);
    }

    p += sSpiHeader.unkC;

    if (sSpiHeader.unk10 > 0) {
        memcpy(p, sSpiCompDataPtrBase, sSpiHeader.unk10);
    }

    /* free temporaries */
    free(tempNibbles);
    free(tempData);
    free(tempBits);

    if (outCompressedSize) {
        *outCompressedSize = compressedSize;
    }
    return compressedPtr;
}

uint8_t* Decompress(SPI_TYPE spiType, uint8_t* compressedPtr, int outSize, int unk8, int unkC) {
    int sp2C;
    int sp28;
    int sp24;

    uint8_t* out;
    uint8_t* outPtr;

    // Reset SPI bit reader / dictionary globals
    D_8016047C = 0;
    D_80160484 = 0;

    for (sp24 = 0; sp24 < 16; sp24++)
        D_80160228[sp24] = sp24;

    D_8016042C = 0x10;

    // Allocate output buffer
    out = malloc(outSize);
    if (!out) {
        printf("Error: cannot allocate %d bytes for decompression\n", outSize);
        return NULL;
    }

    outPtr = out;

    // Set read pointer

    sSpiCompSrcPtr = compressedPtr;
    D_8016044C = sSpiCompSrcPtr;
    sSpiCompSrcPtr = &sSpiCompSrcPtr[unk8];
    D_8016043C = sSpiCompSrcPtr;
    sSpiCompSrcPtr = &sSpiCompSrcPtr[unkC];
    sSpiCompDataPtr = sSpiCompSrcPtr;
    sSpiCompSrcBase = sSpiCompSrcPtr;
    D_8016045C = D_8016043C;
    D_80160464 = D_8016044C;

    // SPI0
    if (spiType == SPI_0) {
        while ((uintptr_t) ((uintptr_t) outPtr - (uintptr_t) out) < (uintptr_t) outSize) {
            if (func_800C0328() != 0) {
                *outPtr++ = *sSpiCompDataPtr++;
            } else {
                sp28 = ((int) sSpiCompDataPtr[0] / 16) & 0xF;
                sp2C = ((sSpiCompDataPtr[0] & 0xF) << 8) + (sSpiCompDataPtr[1] & 0xFF) + 1;
                sSpiCompDataPtr += 2;
                if (sp28 == 15) {
                    while (true) {
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
                for (; sp28 > 0; sp28--, outPtr++) {
                    *outPtr = *(outPtr - sp2C);
                }
            }
        }

        // SPI1
    } else if (spiType == SPI_1) {
        while ((uintptr_t) ((uintptr_t) outPtr - (uintptr_t) out) < (uintptr_t) outSize) {

            if (func_800C0328() != 0) {
                if (func_800C0328() != 0) {
                    func_800C055C(sSpiCompDataPtr[0] & 0xFF);
                    *outPtr++ = *sSpiCompDataPtr++;
                } else {
                    *outPtr++ = func_800C0534(func_800C01D4());
                }
            } else {
                sp28 = ((int) sSpiCompDataPtr[0] / 16) & 0xF;

                sp2C = ((sSpiCompDataPtr[0] & 0xF) << 8) + (sSpiCompDataPtr[1] & 0xFF) + 1;

                sSpiCompDataPtr += 2;

                if (sp28 == 0xF) {
                    while (true) {
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
                for (; sp28 > 0; sp28--, outPtr++) {
                    *outPtr = *(outPtr - sp2C);
                }
            }
        }
    } else {
        memcpy(outPtr, sSpiCompSrcPtr, outSize);
    }

    return out;
}

int getFileSize(FILE* fp) {
    fseek(fp, 0, SEEK_END);
    int fSize = (int) ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

FILE* createOutputFile(const char* fileName) {
    FILE* fp = fopen(fileName, "wb");
    return fp;
}

void printInfo(void) {
    printf("The ultimate SPI files tools: \n -c Compress (Disables Decompress)\n  -d Decompress (Default)\n -i Input "
           "file\n -o Output file\n -h Help\n");
}

void printOptionWarning(char* s) {
    printf("Option %s requires an argument\n", s);
}

int handleCompression(char* inputFileName, char* outputFileName) {

    FILE* fp = fopen(inputFileName, "rb");
    if (fp == NULL) {
        printf("Can't open input file: %s\n", inputFileName);
        return EXIT_FAILURE;
    }

    int fileSize = getFileSize(fp);
    if (fileSize <= 0) {
        puts("Empty or invalid file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    uint8_t* buf = (uint8_t*) malloc(fileSize);
    if (buf == NULL) {
        puts("Can't allocate buffer!");
        fclose(fp);
        return EXIT_FAILURE;
    }

    size_t read = fread(buf, 1, fileSize, fp);
    fclose(fp);
    if ((int) read != fileSize) {
        puts("Failed to read entire file");
        free(buf);
        return EXIT_FAILURE;
    }

    int compressedSize = 0;
    uint8_t* compressedOutput = Compress(buf, fileSize, SPI_1, &compressedSize);
    free(buf);

    if (!compressedOutput || compressedSize <= 0) {
        puts("Compression failed");
        free(compressedOutput);
        return EXIT_FAILURE;
    }

    FILE* outputFile = createOutputFile(outputFileName);
    if (!outputFile) {
        puts("Couldn't create output file!");
        free(compressedOutput);
        return EXIT_FAILURE;
    }

    /* write compressed data into the output file */
    size_t written = fwrite(compressedOutput, 1, (size_t) compressedSize, outputFile);
    fclose(outputFile);
    if ((int) written != compressedSize) {
        printf("Write error: wrote %zu of %d\n", written, compressedSize);
        free(compressedOutput);
        return EXIT_FAILURE;
    }

    printf("Wrote compressed file: %d bytes\n", compressedSize);
    free(compressedOutput);
}

int handleDecompression(char* inputFileName, char* outputFileName) {
    FILE* fp;
    int fileSize;
    uint8_t* buf;
    size_t read;
    SpiHeader header;

    fp = fopen(inputFileName, "rb");
    if (fp == NULL) {
        printf("Can't open input file: %s\n", inputFileName);
        return EXIT_FAILURE;
    }

    fileSize = getFileSize(fp);
    if (fileSize <= 0) {
        puts("Empty or invalid file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    read = fread(&header, sizeof(SpiHeader), 1, fp);

    printf("SPI Header:\n");
    printf("  header: %c%c%c%c\n", header.header[0], header.header[1], header.header[2], header.header[3]);

    header.fileSize = __swab32(header.fileSize);
    header.unk8 = __swab32(header.unk8);
    header.unkC = __swab32(header.unkC);
    header.unk10 = __swab32(header.unk10);

    printf("  fileSize: %d\n", header.fileSize);
    printf("  unk8: %d\n", header.unk8);
    printf("  unkC: %d\n", header.unkC);
    printf("  unk10: %d\n", header.unk10);

    int compressedDataSize = fileSize - sizeof(SpiHeader);

    buf = (uint8_t*) malloc(compressedDataSize);
    if (buf == NULL) {
        puts("Can't allocate buffer!");
        fclose(fp);
        return EXIT_FAILURE;
    }

    read = fread(buf, 1, compressedDataSize, fp);
    if ((int)read != (int)compressedDataSize) {
       puts("Failed to read the entire file");
       free(buf);
       return EXIT_FAILURE;
    }

    FILE* outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        puts("Can't open output decompression file!");
        exit(EXIT_FAILURE);
    }
    
    uint8_t* decompressedOutput = Decompress(SPI_1, buf, header.fileSize, header.unk8, header.unkC);

    size_t written = fwrite(decompressedOutput, 1, (size_t) header.fileSize, outputFile);
    fclose(outputFile);
    if ((int) written != header.fileSize) {
        printf("Write error: wrote %zu of %d\n", written, header.fileSize);
        free(decompressedOutput);
        return EXIT_FAILURE;
    }

    printf("Wrote decompressed file: %d bytes\n", header.fileSize);
    free(decompressedOutput);
}

int parseArgs(int argc, char* argv[]) {
    int opt;
    static char* outputFileName;
    static char* inputFileName;
    // extern int optind; // Declaration is often implicit or in unistd.h
    PROGRAM_ACTION action = DECOMPRESS;

    if (argc < 2) {
        printInfo();
        exit(EXIT_SUCCESS);
    }

    while ((opt = getopt(argc, argv, "ho:i:dc")) != -1) {
        switch (opt) {
            case OPTION_COMPRESS:
                action = COMPRESS;
                break;
            case OPTION_DECOMPRESS:
                action = DECOMPRESS;
                break;
            case OPTION_OUTPUT_FILE:
                outputFileName = optarg;
                break;
            case OPTION_INPUT_FILE:
                inputFileName = optarg;
                break;
            case OPTION_HELP:
                printInfo();
                break;
            default:
                break;
        }
    }

    if (opt < 0 && argv[optind] != NULL) {
        printf("Warning: Option not recognized: %s\n", argv[optind]);
    }

    if (inputFileName == NULL || outputFileName == NULL) {
        fprintf(stderr, "Please specify the inputFile and outPutFile\n");
        exit(EXIT_FAILURE);
    }

    int status;
    if (action == COMPRESS) {
        status = handleCompression(inputFileName, outputFileName);
    } else {
        status = handleDecompression(inputFileName, outputFileName);
    }

    return status;
}

int main(int argc, char** argv) {
    return parseArgs(argc, argv);
}
