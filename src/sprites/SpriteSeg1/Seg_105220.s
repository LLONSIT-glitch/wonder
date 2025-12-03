.include "macro.inc"

.section .data, "wa"

nonmatching gSpriteFramesStart, 0x2E8A0

dlabel gSpriteFramesStart
.incbin "bins/sprites/SpriteSeg1/Seg_105220.databin.bin"
enddlabel gSpriteFramesStart
