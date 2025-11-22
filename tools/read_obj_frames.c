#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// More like FrameInfo?
typedef struct ObjDef_s {
    uint32_t frames_offset;
    uint16_t u1;
    uint16_t u2;
    uint16_t u3;
    uint16_t u4;
    uint32_t u5;
    uint8_t frame_count;
    uint8_t pad1;
    uint8_t pad2;
    uint8_t pad3;
    // uint8_t* frames; /
} ObjDef;

int getFileSize(FILE* fp) {
    fseek(fp, 0, SEEK_END);
    int fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

char* readFile(char* path, int* size) {
    FILE* fp = fopen(path, "rb");
    if (fp == NULL) {
        puts("Can't open file!\n");
        exit(EXIT_FAILURE);
    }

    int fileSize = getFileSize(fp);
    char* buf = malloc(fileSize);

    if (buf == NULL) {
        puts("Can't allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    fread(buf, fileSize, 1, fp);

    *size = fileSize;
    return buf;
}

void readObjsFrames() {
    int fileSize;
    char* buf = readFile("assets/FD180.bin", &fileSize);

    bool displayFramePhysicalPointer = true;
    int frames_base_offset = 0x00105220;

    for (ObjDef* def = (ObjDef*) &buf[0]; def < (ObjDef*) &buf[fileSize]; def++) {
        if (displayFramePhysicalPointer) {
            printf("Frames devAddr: 0x%08X\n", frames_base_offset + __builtin_bswap32(def->frames_offset));
        } else {
            printf("frames_offset: 0x%08X\n", __builtin_bswap32(def->frames_offset));
        }
        printf("u1: 0x%04X\n", __builtin_bswap16(def->u1));
        printf("u2: 0x%04X\n", __builtin_bswap16(def->u2));
        printf("u3: 0x%04X\n", __builtin_bswap16(def->u3));
        printf("u4: 0x%04X\n", __builtin_bswap16(def->u4));
        printf("u5: 0x%04X\n", __builtin_bswap32(def->u5));
        printf("frame_count: %u\n", def->frame_count);
        printf("pad1: 0x%02X\n", def->pad1);
        printf("pad2: 0x%02X\n", def->pad2);
        printf("pad3: 0x%02X\n", def->pad3);
        printf("----\n");
    }
}

void getSPIsOffsets(void) {
    int fileSize;
    long doubleWord;
    char* buf = readFile("assets/133AC0.bin", &fileSize);
    int spiBaseOffset = 0x133AC0;
    int spiDataOffset = 0x0013d2e0;

    
    int i = 0;

    for (i = 0; i < 0x1303; i++) {
        int off = 0;
        int spiOffset = 0;

        while (true) {
            int ind =  (i + off) * 8;

            spiOffset = __builtin_bswap32(*(long*)&buf[ind]);

            if ((spiOffset & 1) == 0) {
                break;
            }
            off++;
        }


        printf("spi offset %x: %x %x\n", i, spiOffset, spiDataOffset + spiOffset);
    }

    /*

        for i in 0..0x1303 {
        let mut off = 0;
        let mut spi_offset = 0;
        loop {
            let ind = spiBaseOffset + (i + off) * 8;
            spi_offset = BigEndian::read_u32(&buffer[ind..ind+8]);
            if spi_offset & 1 == 0 {
                //println!("Offset count: {}", other);
                other = other + 1;
                break
            }
            off += 1;
        }*/

    free(buf);
}

int main() {

    printf("Size of long is: %d\n", sizeof(long));
    getSPIsOffsets();
}