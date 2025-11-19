#ifndef SEGMENT_H
#define SEGMENT_H
extern u8 Unk_bin_ROM_START[];

extern u8 audioTblStart_ROM_START[];
extern u8 audioTblStart_ROM_END[];
extern u8 audioBankStart_ROM_START[];
extern u8 audioBankStart_ROM_END[];

extern u8 F24E0_ROM_START[]; // Main segment bss start
extern u8 F24E0_ROM_END[];
extern u8 SpriteSeg1_ROM_START[];

extern u8 SpriteSeg1_VRAM[];
extern u8 SpriteSeg1_VRAM_END[];
extern u8 F27E0_ROM_END[];


// Unknown linker symbols
extern u8 SpriteSeg1_VRAM[];
extern u8 D_80409B40[];

void dma_copy(char* src, void *dest, const int len);
#endif /* SEGMENT_H */
