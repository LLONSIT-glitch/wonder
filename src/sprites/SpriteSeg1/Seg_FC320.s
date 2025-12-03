.include "macro.inc"

.section .data, "wa"

nonmatching D_80409B40, 0xE60

dlabel D_80409B40
.incbin "bins/sprites/SpriteSeg1/Seg_FC320.databin.bin"
enddlabel D_80409B40
