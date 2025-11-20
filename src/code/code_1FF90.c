#include "common.h"
#include "macro.h"

s16 D_800DB600[4][2] = { { 7, 13 }, { 16, 22 }, { 27, 32 }, { 37, 40 } };


s32 func_8001F390(UnkStruct_80020720* arg0) {
    s32 sp2C;
    u8* sp28;
    UnkStruct_80099E2C* sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4("== %s ==", arg0->unk4);
    switch (D_801825E4) {                           /* irregular */
    case 0:
        for (sp2C = 0; sp2C < 8; sp2C++) {
            D_801825F0[sp2C] = 0;
            D_80182618->ptrs[sp2C] = NULL;
        } 
        D_80182618->ptrs[0] = func_8001F60C((u8**)&D_801825F0[3]);
        D_801825F0[4] = (s32) ((s32) (D_807991C0 - D_8078D1C0) / 512);
        D_80182618->ptrs[1] = SysMem_HeapAlloc(0x200);
        D_80182618->ptrs[2] = SysMem_HeapAlloc(0xB00);
        sp28 = D_80182618->ptrs[1];
        sp24 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
        func_800B1B3C(&sp24, &sp28, 8);
        for (sp2C = 0, sp24 = (UnkStruct_80099E2C*)D_80182618->ptrs[2]; sp2C < 8; sp2C++, sp24++) {
            func_80099E2C(sp24);
            sp24->unkC0 |= 12;
        } 
        break;
    case 1:
        func_8001F800();
        func_8001F6B8();
    }
    if (D_801560F0->unk6 & (u16) D_801811A4) {
        SysMem_Free(D_80182618->ptrs[0]);
        sp28 = D_80182618->ptrs[1];
        sp24 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
        func_800B1C10(&sp24, &sp28, 8);
        SysMem_Free(D_80182618->ptrs[1]);
        SysMem_Free(D_80182618->ptrs[2]);
        return -1;
    }
    return 0;
}

void* func_8001F60C(u8** arg0) {
    void* sp24;
                                    /* end - start */
    sp24 = SysMem_HeapAlloc(*arg0 = D_80409B40 - SpriteSeg1_VRAM);
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual(gSpriteObjHeaderSegment, gSpriteSeg1VramStart, D_80180D30), sp24, *arg0);
    *arg0 = ((uintptr_t) *arg0 / 16);
    return sp24;
}

void func_8001F6B8(void) {
    u8* sp24;
    s32 spriteLoopFlag;

    sp24 = D_80182618->ptrs[0];
    sp24 += D_801825F0[1] * 0x10;
    if ((s32) D_801825F0[0] & 4) {
        spriteLoopFlag = TRUE;
    } else {
        spriteLoopFlag = FALSE;
    }
    func_8008EAA8(1, 2);
    
    func_8008ECE4("SELECT  %4d  -  %4d  PAL  %3d  OPT  %1d  ", (*(u32*)sp24) >> 0x10, (*(u32*)sp24) & 0xFFFF, 
                  D_801825F0[2], 
                  spriteLoopFlag);
    func_8008EAA8(D_800DB600[D_801825F0[5]][0], 2);
    func_8008ECE4("[");
    func_8008EAA8(D_800DB600[D_801825F0[5]][1], 2);
    func_8008ECE4("]");
    func_8008EAA8(0, 0xF);
    func_8008ECE4("+:PARAMS A:START   B:STOP/FRAME\n");
    func_8008ECE4("3D:MOVE  L:ZOOM UP R:ZOOM DOWN  A+B:RESET\n");
    func_8008ECE4("Z:OPT STOP   START:EXIT   C-UNIT:OPT OFF"); // !< This sugests a file split
}

