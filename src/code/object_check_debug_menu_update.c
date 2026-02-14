#include "common.h"

typedef enum ObjectCheckDebugMenu_Option_e {
    OPTION_SELECT,
    OPTION_ANIM_NUMBER,
    OPTION_PALETTE,
    OPTION_LOOP_FLAG
} ObjectCheckDebugMenu_Option;

typedef u32 Sp54[4];

void ObjectCheckDebugMenu_Update(void) {
    s32 selectedSprite;
    s32 sp68;
    s32 pad[2];
    s32 s0;
    u16 sp5A;
    Sp54* spriteAddress;
    SpriteObj* sp50;
    UnkStruct_800B23C4* sp4C;
    u8 sp4B;
    u16 sp48;

    if (gControllers->unk8 & gInputMask_DPadUp) {
        switch (gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION]) { /* irregular */
            case OPTION_SELECT:
                spriteAddress = (Sp54*) D_80182618->ptrs[0];
                spriteAddress += (selectedSprite = gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE]);
                sp5A = spriteAddress[0][0] >> 0x10;

                while (++selectedSprite, ++spriteAddress, selectedSprite < gSpriteObjCheckDebugMenuState[SPRDBG_SPRITE_COUNT] && ((spriteAddress[0][0] >> 0x10) == sp5A)) {}

                if (selectedSprite < gSpriteObjCheckDebugMenuState[SPRDBG_SPRITE_COUNT]) {
                    gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE] = selectedSprite;
                }
                break;
            case OPTION_ANIM_NUMBER:
                if (++gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE] >= gSpriteObjCheckDebugMenuState[SPRDBG_SPRITE_COUNT]) {
                    gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE] = gSpriteObjCheckDebugMenuState[SPRDBG_SPRITE_COUNT] - 1;
                }
                break;
            case OPTION_PALETTE:
                if (++gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE] >= gSpriteObjCheckDebugMenuState[SPRDBG_PALETTE_COUNT]) {
                    gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE] = gSpriteObjCheckDebugMenuState[SPRDBG_PALETTE_COUNT] - 1;
                }
                if (gSpriteObjCheckDebugMenuState[7] > 0) {
                    sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
                    sp50 = (SpriteObj*) D_80182618->ptrs[2];
                    func_800B3DBC(&sp50, &sp4C, gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE]);
                }
                break;
            case OPTION_LOOP_FLAG:
                gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] ^= 4;
        }
    }
    if (gControllers->unk8 & gInputMask_DPadDown) {
        switch (gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION]) { /* switch 1; irregular */
            case OPTION_SELECT:              /* switch 1 */
                spriteAddress = (Sp54*) D_80182618->ptrs[0];
                spriteAddress += (selectedSprite = gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE]);
                sp5A = spriteAddress[0][0] >> 0x10;

                while (--selectedSprite, --spriteAddress, selectedSprite >= 0 && ((spriteAddress[0][0] >> 0x10) == sp5A)) {}

                if (selectedSprite >= 0) {
                    gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE] = selectedSprite;
                }
                break;
            case OPTION_ANIM_NUMBER: /* switch 1 */
                if (--gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE] < 0) {
                    gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE] = 0;
                }
                break;
            case OPTION_PALETTE: /* switch 1 */
                if (--gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE] < 0) {
                    gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE] = 0;
                }
                if (gSpriteObjCheckDebugMenuState[7] > 0) {
                    sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
                    sp50 = (SpriteObj*) D_80182618->ptrs[2];
                    func_800B3DBC(&sp50, &sp4C, gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE]);
                }
                break;
            case OPTION_LOOP_FLAG: /* switch 1 */
                gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] ^= 4;
        }
    }
    if (gControllers->unk6 & gInputMask_DPadRight) {
        if (++gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION] > OPTION_LOOP_FLAG) {
            gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION] = OPTION_LOOP_FLAG;
        }
    }
    if (gControllers->unk6 & gInputMask_DPadLeft) {
        if (--gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION] < OPTION_SELECT) {
            gSpriteObjCheckDebugMenuState[SPRDBG_CURRENT_OPTION] = OPTION_SELECT;
        }
    }
    if (gControllers->unk6 & gInputMask_A) {
        spriteAddress = (Sp54*) D_80182618->ptrs[0];
        spriteAddress += gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE];
        sp5A = spriteAddress[0][0] >> 0x10;
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (SpriteObj*) D_80182618->ptrs[2];
        if (gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] & FLAGS_SPRITE_LOOP) {
            sp4B = 4;
        } else {
            sp4B = 0;
        }
        func_80022124();
        gSpriteObjCheckDebugMenuState[7] = func_800B202C(&sp50, &sp4C, spriteAddress[0][0], gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE], sp50->unkCC, sp50->unkD0, (s32) sp4B);
        gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] |= 2;
        gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] |= 1;
    } else if (gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] & 2) {
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (SpriteObj*) D_80182618->ptrs[2];
        selectedSprite = func_800B2748(&sp50, &sp4C);
        if (selectedSprite < 0) {
            gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] &= ~2;
            gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] &= ~1;
        } else {
            gSpriteObjCheckDebugMenuState[7] = selectedSprite;
        }
    }
    if (gControllers->unk6 & gInputMask_B) {
        gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] &= ~2;
        if (!(gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] & 1)) {
            spriteAddress = (Sp54*) D_80182618->ptrs[0];
            spriteAddress += gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_SPRITE];
            sp5A = spriteAddress[0][0] >> 0x10;
            sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
            sp50 = (SpriteObj*) D_80182618->ptrs[2];
            if (gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] & 4) {
                sp4B = 4;
            } else {
                sp4B = 0;
            }
            func_80022124();
            gSpriteObjCheckDebugMenuState[7] =
                func_800B202C(&sp50, &sp4C, spriteAddress[0][0], gSpriteObjCheckDebugMenuState[SPRDBG_SELECTED_PALETTE], sp50->unkCC, sp50->unkD0, (s32) sp4B);
            gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] |= 1;
        } else {
            sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
            sp50 = (SpriteObj*) D_80182618->ptrs[2];
            selectedSprite = func_800B2748(&sp50, &sp4C);
            if (selectedSprite < 0) {
                gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] &= ~1;
            } else {
                gSpriteObjCheckDebugMenuState[7] = selectedSprite;
            }
        }
    }
    if ((gControllers->unk6 & gInputMask_A) && (gControllers->unk6 & gInputMask_B)) {
        for (sp68 = 0, sp50 = (SpriteObj*) D_80182618->ptrs[2]; sp68 < 8; sp68++, sp50++) {
            sp50->unkD0 = 0.0f;
            sp50->unkCC = (f32) sp50->unkD0;
            sp50->unkF8 = 1.0f;
            sp50->unkF4 = (f32) sp50->unkF8;
        }
    }
    if (gControllers->unk6 & gInputMask_Z) {
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (SpriteObj*) D_80182618->ptrs[2];
        selectedSprite = func_800B2CBC(&sp50, &sp4C, 2);
        if (selectedSprite < 0) {
            gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] &= ~1;
        } else {
            gSpriteObjCheckDebugMenuState[7] = selectedSprite;
        }
    }
    if (gSpriteObjCheckDebugMenuState[SPRDBG_FLAGS] & 1) {
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (SpriteObj*) D_80182618->ptrs[2];
        sp48 = func_800B3434(&sp4C, 0);
        if (sp48 & 0x4000) {
            func_800B9000(func_800B32E4(&sp4C, 0));
        }
        if (sp48 & 0x8000) {
            func_800B9000(func_800B32E4(&sp4C, 1));
        }
        if (gControllers->button & (gInputMask_CUp | gInputMask_CDown | gInputMask_CRight | gInputMask_CLeft)) {
            func_800B2CBC(&sp50, &sp4C, 6);
        } else {
            func_800B2CBC(&sp50, &sp4C, 5);
        }
    }

    for (sp68 = 0, sp50 = (SpriteObj*) D_80182618->ptrs[2]; sp68 < 8; sp68++, sp50++) {
        if (FABS(gControllers->stickX) >= 10.0) {
            sp50->unkCC += gControllers->stickX * 0.1;
        }

        if (FABS(gControllers->stickY) >= 10.0) {
            sp50->unkD0 += gControllers->stickY * 0.1;
        }
        if (gControllers->unk8 & gInputMask_R) {
            sp50->unkF8 = (sp50->unkF4 += 0.2);
        }
        if (gControllers->unk8 & gInputMask_L) {
            sp50->unkF8 = (sp50->unkF4 -= 0.2);
            if (sp50->unkF8 <= 0.0) {
                sp50->unkF8 = sp50->unkF4 = 0.009999999776f;
            }
        }
        if ((gControllers->unk6 & gInputMask_R) && (gControllers->unk6 & gInputMask_L)) {
            sp50->unkF8 = sp50->unkF4 = 1.0f;
        }
        if (sp68 >= gSpriteObjCheckDebugMenuState[7]) {
            continue;
        }

        MtxUtil_PushIdentity();
        func_8009A14C(sp50);
        func_800997D8(sp50);
        MtxUtil_Pop();
    }
}
