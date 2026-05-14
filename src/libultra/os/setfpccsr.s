.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel __osSetFpcCsr
    /* D5040 800D4440 4442F800 */  cfc1       $v0, $31
    /* D5044 800D4444 44C4F800 */  ctc1       $a0, $31
    /* D5048 800D4448 03E00008 */  jr         $ra
    /* D504C 800D444C 00000000 */   nop
endlabel __osSetFpcCsr
