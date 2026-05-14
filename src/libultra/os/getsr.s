.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* Handwritten function */
glabel __osGetSR
    /* D5030 800D4430 40026000 */  mfc0       $v0, $12
    /* D5034 800D4434 03E00008 */  jr         $ra
    /* D5038 800D4438 00000000 */   nop
endlabel __osGetSR

    /* D503C 800D443C 00000000 */  nop
