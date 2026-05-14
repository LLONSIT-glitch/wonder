.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* Handwritten function */
glabel __osSetSR
    /* D5020 800D4420 40846000 */  mtc0       $a0, $12
    /* D5024 800D4424 00000000 */  nop
    /* D5028 800D4428 03E00008 */  jr         $ra
    /* D502C 800D442C 00000000 */   nop
endlabel __osSetSR
