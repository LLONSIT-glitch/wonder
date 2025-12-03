.include "macro.inc"

.section .data, "wa"

nonmatching gMainSprites, 0x34E4C0

dlabel gMainSprites
.incbin "bins/sprites/SpriteSeg1/MainSprites.databin.bin"
enddlabel gMainSprites
