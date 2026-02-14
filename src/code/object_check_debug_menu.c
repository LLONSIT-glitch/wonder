#include "common.h"
#include "macro.h"

s16 sDebugCursorBracketPositions[4][2] = { { 7, 13 }, { 16, 22 }, { 27, 32 }, { 37, 40 } };

void* ObjectCheckDebugMenu_LoadSpriteHeader(u32** size);
void ObjectCheckDebugMenu_DrawUI(void);

s32 ObjectCheckDebugMenu(DebugMenuInfo* info) {
    s32 i;
    UnkStruct_800B23C4* sp28;
    SpriteObj* sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4("== %s ==", info->debugMenuTitle);
    switch (gDebugMenuState) { /* irregular */
        case DEBUG_MENU_STATE_INITIALIZE:
            for (i = 0; i < 8; i++) {
                gSpriteObjCheckDebugMenuState[i] = 0;
                D_80182618->ptrs[i] = NULL;
            }
            D_80182618->ptrs[0] = ObjectCheckDebugMenu_LoadSpriteHeader((u8**) &gSpriteObjCheckDebugMenuState[SPRDBG_SPRITE_COUNT]);
            gSpriteObjCheckDebugMenuState[SPRDBG_PALETTE_COUNT] = ((gSpritePalettesEnd - gSpritePalettes) / 512);
            D_80182618->ptrs[1] = SysMem_HeapAlloc(512);
            D_80182618->ptrs[2] = SysMem_HeapAlloc(0xB00);
            sp28 = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
            sp24 = (SpriteObj*) D_80182618->ptrs[2];
            func_800B1B3C(&sp24, &sp28, 8);
            for (i = 0, sp24 = (SpriteObj*) D_80182618->ptrs[2]; i < 8; i++, sp24++) {
                func_80099E2C(sp24);
                sp24->unkC0 |= 12;
            }
            break;
        case DEBUG_MENU_STATE_UPDATE:
            ObjectCheckDebugMenu_Update();
            ObjectCheckDebugMenu_DrawUI();
    }
    if (gControllers->unk6 & (u16) gInputMask_Start) {
        SysMem_Free(D_80182618->ptrs[0]);
        sp28 = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp24 = (SpriteObj*) D_80182618->ptrs[2];
        func_800B1C10(&sp24, &sp28, 8);
        SysMem_Free(D_80182618->ptrs[1]);
        SysMem_Free(D_80182618->ptrs[2]);
        return -1;
    }
    return 0;
}

void* ObjectCheckDebugMenu_LoadSpriteHeader(u32** spritesCount) {
    void* spritesHeader;
    /* end - start */
    spritesHeader = SysMem_HeapAlloc(*spritesCount = D_80409B40 - SpriteSeg1_VRAM);
    SysMem_DmaCopy(SysMem_GetPhysicalAddressFromVirtual(gSpriteObjHeaderSegment, gSpriteSeg1VramStart, D_80180D30),
                   spritesHeader, *spritesCount);
    *spritesCount = ((uintptr_t) *spritesCount / 16);
    return spritesHeader;
}

void ObjectCheckDebugMenu_DrawUI(void) {
    u8* sp24;
    s32 spriteLoopFlag;

    sp24 = D_80182618->ptrs[0]; // Access to F27E0 - ObjHeader
    sp24 += gSpriteObjCheckDebugMenuState[1] * 0x10;
    if ((s32) gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] & 4) {
        spriteLoopFlag = TRUE;
    } else {
        spriteLoopFlag = FALSE;
    }
    func_8008EAA8(1, 2);

    func_8008ECE4("SELECT  %4d  -  %4d  PAL  %3d  OPT  %1d  ", (*(u32*) sp24) >> 0x10, (*(u32*) sp24) & 0xFFFF,
                  gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE], spriteLoopFlag);
    func_8008EAA8(sDebugCursorBracketPositions[gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION]][0], 2);
    func_8008ECE4("[");
    func_8008EAA8(sDebugCursorBracketPositions[gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION]][1], 2);
    func_8008ECE4("]");
    func_8008EAA8(0, 15);
    func_8008ECE4("+:PARAMS A:START   B:STOP/FRAME\n");
    func_8008ECE4("3D:MOVE  L:ZOOM UP R:ZOOM DOWN  A+B:RESET\n");
    func_8008ECE4("Z:OPT STOP   START:EXIT   C-UNIT:OPT OFF");
}
