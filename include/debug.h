#ifndef DEBUG_H
#define DEBUG_H


typedef enum SelectionState_e { 
    SELECTION_STATE_INACTIVE = -1,
    SELECTION_STATE_ACTIVE
} SelectionState;

typedef enum SpriteDebugIndex_e {
    SPRDBG_FLAGS = 0,
    SPRDBG_SELECTED_SPRITE,
    SPRDBG_SELECTED_PALETTE,
    SPRDBG_SPRITE_COUNT,
    SPRDBG_PALETTE_COUNT,
    SPRDBG_CURRENT_OPTION,
    SPRDBG_UNUSED,
    SPRDBG_ACTIVE_INSTANCE_COUNT,
    SPRDBG_COUNT
} SpriteDebugIndex;


typedef struct DebugMenuInfo_s {
    s32 unk0;
    char* debugMenuTitle;
} DebugMenuInfo;

typedef struct DebugMenuOption_s {
    /* 0x00 */ s32 entry;                                   /* inferred */
    /* 0x04 */ char* optionName;                           /* inferred */
    /* 0x08 */ s32 unk8;                                   /* inferred */
    /* 0x0C */ s32 unkC;                                   /* inferred */
    /* 0x10 */ s32 unk10;                                  /* inferred */
    /* 0x14 */ s32 (*entryRoutine)(struct DebugMenuOption_s* option, SelectionState state); /* inferred */
    /* 0x18 */ s32 (*unk18)(struct DebugMenuOption_s*);      /* inferred */
    /* 0x1C */ char pad1C[0xC];                            /* maybe part of unk18[3]? */
} DebugMenuOption;                                           /* size = 0x28 */

#define DEBUG_MENU_STATE_INITIALIZE 0
#define DEBUG_MENU_STATE_UPDATE 1

// object check debug menu
#define FLAGS_SPRITE_LOOP 4

#endif /* DEBUG_H */
