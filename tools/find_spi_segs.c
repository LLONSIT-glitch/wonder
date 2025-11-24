#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <linux/swab.h>

typedef struct SpiHeader {
    __uint8_t header[4];
    __int32_t unk4;
    __int32_t u2;
    __int32_t u3;
    __int32_t u4;
} SpiHeader;

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

#define CHECK_SPI_HEADER(x)                                               \
    (x->header[0] == 'S' && x->header[1] == 'P' && x->header[2] == 'I' && \
     (x->header[3] == '0' || x->header[3] == '1' || x->header[3] == 'N'))

int getFileSize(FILE* fp) {
    fseek(fp, 0, SEEK_END);
    int fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

bool isValidSPIHeader(SpiHeader* spi) {

    if (CHECK_SPI_HEADER(spi)) {
    }

}

int main() {
    FILE* romFile = fopen("baserom.jp.z64", "rb");
    char* buf;

    if (romFile == NULL) {
        puts("Couldn't open romFile ensure that it exists on the current directory!");
        exit(EXIT_FAILURE);
    }

    int romSize = getFileSize(romFile);
    buf = malloc(romSize);

    if (buf == NULL) {
        puts("Can't allocate a lot of memory!");
        exit(EXIT_FAILURE);
    }

    fread(buf, romSize, 1, romFile);

    char* ptr = &buf[0];

    printf("Got SPI segments in the following offsets:\n");

    for (int pos = 0; ptr < &buf[romSize]; ptr++, pos++) {
        SpiHeader* header = (SpiHeader*) ptr;

        if (CHECK_SPI_HEADER(header)) {
            int seg = pos;
            printf("- [0x%x]\n", seg);
        }
    }

    printf("Did this take a lot to complete?\n");
}
