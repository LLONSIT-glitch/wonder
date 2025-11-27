#ifndef OBJ_H
#define OBJ_H

#define CI8_PALETTE_COLORS 0x100

typedef enum {
    OBJINFO_EMPTY = 0x0000,
    OBJINFO_HASEXTRA = 0x0001,
    OBJINFO_LOOP = 0x0002,
    OBJINFO_UNK3 = 0x0004,
    OBJINFO_UNK4 = 0x0008,
    OBJINFO_BG2FG = 0x0010,
    OBJINFO_UNK6 = 0x0020,
    OBJINFO_UNK8 = 0x0040,
    OBJINFO_FG2BG = 0x0080,
    OBJINFO_UNK10 = 0x0100,
    OBJINFO_UNK12 = 0x0200,
    OBJINFO_UNK13 = 0x0400,
    OBJINFO_UNK14 = 0x0800,
    OBJINFO_UNK15 = 0x1000,
    OBJINFO_UNK16 = 0x2000,
    OBJINFO_UNK17 = 0x4000,
    OBJINFO_UNK18 = 0x8000
} ObjInfoFlags;

typedef struct SpritePalette_s {
    s16 colors[CI8_PALETTE_COLORS];
} SpritePalette;

typedef struct ObjInfo_s {
    u16 offset1;
    u16 offset2;
    u32 u1;
    u16 flags; /* See ObjFlags */
    s16 u2;
    s16 u3;
    u8 obj_count;
    u8 extra_obj_count;
} ObjInfo;

typedef struct ObjDef_s {
    u32 frames_offset;
    u16 u1;
    u16 u2;
    u16 u3;
    u16 u4;
    u16 u5;
    u8 frame_count;
    u8 pad1;
    u8 pad2;
    u8 pad3;
} ObjDef;

typedef struct ObjFrame_s {
    u16 spi_idx;
    u8 kind;
    u8 id;
    u8 delay;
    u8 u2;
    s16 x;
    s16 y;
    u16 u5;
    u8 u6;
    u8 u7;
} ObjFrame;

// Object struct?
typedef struct UnkStruct_800B23C4_s {
    u8 unk0;
    char pad1[3];
    ObjInfo* objInfo;
    ObjDef* objDef;
    ObjFrame* objFrame;
    u16 unk10;
    u16 currentPaletteIndex;
    SpritePalette* spritePalette[1];
    char pad18[8];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 unk30;
    char pad31[3];
    f32 unk34;
    u8 unk38;
    char pad39[1];
    u16 unk3A;
    s8 unk3C;
    u8 paletteIndex;
    char pad3E[2];
} UnkStruct_800B23C4;
#endif /* OBJ_H */
