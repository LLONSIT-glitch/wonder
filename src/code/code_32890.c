#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80031C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80031D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80031E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80031FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80032380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80032410.s")

void func_80032604(void) {
    s32 i;
    UNUSED char pad[0x6];

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (gControllerRaw[i].state != STATE_NOT_CONNECTED) {
            SysMem_Copy8(&gControllers[i], &gControllerRaw[i], sizeof(Controller));
        } else {
            gControllers[i].state = STATE_NOT_CONNECTED;
            gControllers[i].unk6 = gControllers[i].button = gControllers[i].unk8 = 0;
            gControllers[i].stickX = gControllers[i].stickY = 0.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_8003276C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80032844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_8003288C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80033614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_80033788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_32890/func_800338D0.s")
