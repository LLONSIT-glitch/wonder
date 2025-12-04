#include "common.h"
#include "compiler/ido/stdarg.h"

typedef struct UnkStruct_8015C748_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_8015C748;

extern u16 D_8015BB38;
extern UnkStruct_8015C748 D_8015C748[];

int vsprintf( char* buffer, const char* format, va_list vlist);
void func_80090E58(char** buf);


void func_8008E5A0(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x100; sp4++) {
        D_8015C748[sp4].unk0 = 0;
        D_8015C748[sp4].unk4 = 0;
        D_8015C748[sp4].unk8 = 1;
        D_8015C748[sp4].unkC = 0;
    } 

    D_8015BB38 = 4;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008E630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008EAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008EC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008ECAC.s")

void Sys_SwapFrameBuffer(void* arg0) {
    gCurrentFrameBuffer = arg0;
}

void func_8008ECE4(char* format, ...) {
    va_list ap;
    char* s;
    char buf[0x400];
    s = buf;

    va_start(ap, format);
    vsprintf(s, format, ap);
    func_80090E58(&s);
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8008ED4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/vsprintf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_800906F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_800908A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80090E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80091A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80091E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8009230C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80093B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80094230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80095E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80095F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_8009600C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_800960E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_800961C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_800962B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_800967D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_8F1A0/func_80096EB0.s")
