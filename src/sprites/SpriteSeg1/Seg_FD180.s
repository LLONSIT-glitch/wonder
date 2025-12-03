.include "macro.inc"

.section .data, "wa"

nonmatching gSpriteObjDefs, 0x80A0

dlabel gSpriteObjDefs
.incbin "bins/sprites/SpriteSeg1/Seg_FD180.databin.bin"
enddlabel gSpriteObjDefs
