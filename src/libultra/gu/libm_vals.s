.include "macro.inc"

.section .rodata, "a"

dlabel __libm_qnan_f
    .word 0x7F810000
    .word 0
    .word 0
    .word 0
enddlabel __libm_qnan_f
