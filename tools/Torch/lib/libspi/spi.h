#ifndef SPI_H
#define SPI_H
typedef enum { SPI_1, SPI_0, SPI_N } SPI_TYPE;

typedef struct SpiHeader {
    uint8_t header[4];
    int32_t fileSize;
    int32_t unk8;
    int32_t unkC;
    int32_t unk10;
} SpiHeader;

#define SPI_HEADER_LENGTH 0x14

uint8_t* spi_decompress(SPI_TYPE spiType, uint8_t* compressedPtr, int outSize, int unk8, int unkC);
uint8_t* spi_compress(uint8_t* buf, int buffersSize, SPI_TYPE spiType, int* outCompressedSize);
void spi_swap_header(SpiHeader* header);
#endif /* SPI_H */
