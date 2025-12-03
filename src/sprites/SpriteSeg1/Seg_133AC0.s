.include "macro.inc"

.section .data, "wa"

nonmatching gMainSpritesSpiOffsets, 0x9820

dlabel gMainSpritesSpiOffsets
.incbin "bins/sprites/SpriteSeg1/Seg_133AC0.databin.bin"
enddlabel gMainSpritesSpiOffsets
