#include "common.h"

typedef enum SoundDebugMenuEntry_e {
    ENTRY_DUMMY = -1,
    ENTRY_SOUND_TEST,
    ENTRY_SE_1_SHOT_TEST, // Sound effect test
    ENTRY_SE_TEST,
    ENTRY_3,
    ENTRY_4,
    ENTRY_5,
    ENTRY_6
} SoundDebugMenuEntry;

void func_8002206C(s32, s16, s16); /* extern */
void func_800220F4(s32);           /* extern */
void func_80021F20(s16);           /* extern */
void AudioMgr_StopMusic(void);     /* extern */
extern DebugMenuOption D_800DB610[];
extern s16 D_800DB750;
extern s16 D_800DB754;
extern s16 D_800DB758;
extern s32 D_801ACC48;

s32 SoundDebugMenu_BGMTest(DebugMenuOption* option, SelectionState selectionState);
s32 SoundDebugMenu_SfxTest(DebugMenuOption* option, SelectionState selectionState);
s32 SoundDebugMenu_SfxOneShotTest(DebugMenuOption* option, SelectionState selectionState);

DebugMenuOption D_800DB610[8] = {
    {
        ENTRY_SOUND_TEST,
        "SOUND TEST       ",
        2,
        4,
        1,
        SoundDebugMenu_BGMTest,
        NULL,
    },
    {
        ENTRY_SE_1_SHOT_TEST,
        "S.E.  TEST(1SHOT)",
        2,
        -1,
        1,
        SoundDebugMenu_SfxOneShotTest,
        NULL,
    },
    {
        ENTRY_SE_TEST,
        "S.E.  TEST       ",
        2,
        -1,
        1,
        SoundDebugMenu_SfxTest,
        NULL,
    },
    { ENTRY_3, "  ", 0, -1, 0, NULL, NULL },
    { ENTRY_4, "PAD LEFT/RIGHT:Number Dec/Inc", 0, -1, 0, NULL, NULL },
    { ENTRY_5, "PAD A         :Sound on", 0, -1, 0, NULL, NULL },
    { ENTRY_6, "PAD B         :Sound off", 0, -1, 0, NULL, NULL },
    { ENTRY_DUMMY, NULL, 0, 0, 0, NULL, NULL },
}; /* const */

s32 SoundDebugMenu(DebugMenuInfo* info) {
    DebugMenuOption* debugMenuItem;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4("== %s ==", info->debugMenuTitle);
    switch (D_801825E4) { /* irregular */
        case 0:
            *D_801825F0 = 0;
            /* fallthrough */
        case 1:
            func_8008EAA8(2, 4);
            sp24 = *D_801825F0;
            debugMenuItem = D_800DB610;
            sp30 = 0;
            sp2C = 0;
            for (;; sp30++, debugMenuItem++) {
                if (debugMenuItem->entry == ENTRY_DUMMY) {
                    break;
                }

                if (debugMenuItem->unkC != -1) {
                    func_8008EAA8(debugMenuItem->unk8, debugMenuItem->unkC);
                    sp28 = debugMenuItem->unkC + 1;
                } else {
                    func_8008EAA8(debugMenuItem->unk8, sp28++);
                }
                if (debugMenuItem->unk10 != 0) {
                    if (sp24 == sp2C) {
                        func_8008ECE4(">%s", debugMenuItem->optionName);
                        if (debugMenuItem->entryRoutine != NULL) {
                            debugMenuItem->entryRoutine(debugMenuItem, SELECTION_STATE_ACTIVE);
                        }
                    } else {
                        func_8008ECE4(" %s", debugMenuItem->optionName);
                        if (debugMenuItem->entryRoutine != NULL) {
                            debugMenuItem->entryRoutine(debugMenuItem, SELECTION_STATE_INACTIVE);
                        }
                    }
                    sp2C++;
                } else {
                    func_8008ECE4(" %s", debugMenuItem->optionName);
                }
            }
            if (gControllers->unk8 & gInputMask_DPadUp) {
                sp24--;
            }
            if (gControllers->unk8 & gInputMask_DPadDown) {
                sp24++;
            }
            if (sp24 < 0) {
                sp24 = sp2C - 1;
            }
            if (sp24 >= sp2C) {
                sp24 = 0;
            }
            *D_801825F0 = sp24;
            break;
    }
    if (gControllers->unk6 & (u16) gInputMask_Start) {
        return -1;
    }
    return 0;
}

s32 SoundDebugMenu_BGMTest(DebugMenuOption* option, SelectionState selectionState) {
    if (selectionState >= SELECTION_STATE_ACTIVE) {
        if (gControllers->unk8 & gInputMask_DPadRight) {
            gMusicSequenceId++;
        }
        if (gControllers->unk8 & gInputMask_DPadLeft) {
            gMusicSequenceId--;
        }
        if (gMusicSequenceId < 0) {
            gMusicSequenceId = 0;
        }
        if (gControllers->unk6 & gInputMask_A) {
            AudioGeneral_PlayBGM(gMusicSequenceId);
        }
        if (gControllers->unk6 & gInputMask_B) {
            AudioMgr_StopMusic();
        }
        if (gControllers->unk8 & gInputMask_CDown) {
            D_800DB758 += 1;
        }
        if (gControllers->unk8 & gInputMask_CLeft) {
            D_800DB758 -= 1;
        }
        if (D_800DB758 < 0) {
            D_800DB758 = 1;
        }
        if (gControllers->unk6 & gInputMask_CRight) {
            func_80021F20(D_800DB758);
        }
    }
    func_8008ECE4("   %2d  speed[%d]", gMusicSequenceId, D_800DB758);
    return 0;
}

s32 SoundDebugMenu_SfxTest(DebugMenuOption* option, SelectionState selectionState) {
    if (selectionState >= SELECTION_STATE_ACTIVE) {
        if (gControllers->unk8 & gInputMask_DPadRight) {
            D_801ACC48 += 1;
        }
        if (gControllers->unk8 & gInputMask_DPadLeft) {
            D_801ACC48 -= 1;
        }
        if (D_801ACC48 < 0) {
            D_801ACC48 = 0;
        }
        if (gControllers->unk8 & gInputMask_CDown) {
            if ((D_800DB750 += 0x64) <= 0) {
                D_800DB750 = 0x7FFF;
            }
        }
        if (gControllers->unk8 & gInputMask_CLeft) {
            if ((D_800DB750 -= 0x64) < 0) {
                D_800DB750 = 0;
            }
        }
        if (gControllers->unk8 & gInputMask_CRight) {
            if ((++D_800DB754) >= 0x80) {
                D_800DB754 = 0x7F;
            }
        }
        if (gControllers->unk8 & gInputMask_CUp) {
            if (--D_800DB754 < 0) {
                D_800DB754 = 0;
            }
        }
        if (gControllers->unk6 & gInputMask_A) {
            func_8002206C(D_801ACC48, D_800DB750, D_800DB754);
        }
        if (gControllers->unk6 & gInputMask_B) {
            func_800220F4(D_801ACC48);
        }
    }
    func_8008ECE4("   %2d  V[%5d] P[%3d]", D_801ACC48, D_800DB750, D_800DB754);
    return 0;
}

s32 SoundDebugMenu_SfxOneShotTest(DebugMenuOption* option, SelectionState selectionState) {
    if (selectionState >= SELECTION_STATE_ACTIVE) {
        if (gControllers->unk8 & gInputMask_DPadRight) {
            D_801ACC48 += 1;
        }
        if (gControllers->unk8 & gInputMask_DPadLeft) {
            D_801ACC48 -= 1;
        }
        if (D_801ACC48 < 0) {
            D_801ACC48 = 0;
        }
        if (gControllers->unk6 & gInputMask_A) {
            func_800B9000((u16) D_801ACC48);
        }
        if (gControllers->unk6 & gInputMask_B) {
            func_800220F4(D_801ACC48);
        }
    }
    func_8008ECE4("   %2d  ", D_801ACC48);
    return 0;
}
