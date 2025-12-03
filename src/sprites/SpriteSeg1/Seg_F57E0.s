.include "macro.inc"

.section .data, "wa"

nonmatching D_80403000, 0x6B40

dlabel D_80403000
.incbin "bins/sprites/SpriteSeg1/Seg_F57E0.databin.bin"
enddlabel D_80403000
