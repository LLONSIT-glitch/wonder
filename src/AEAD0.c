#include "common.h"

extern s32 D_8018129C;
extern OSPfs D_80181360;
extern OSPfsState sPfsState[];
// extern ? D_801813D4;
// extern ? D_801813D8;
extern s32 D_80181620;
extern s32 D_8018162C;
extern s32 D_80181638;
extern s32 D_80181640;
extern u16 D_80181646;
extern u32 D_8018164C;
extern u8* D_80181654;
extern u8* D_80181660;
extern u8* D_80181670;
extern s32 D_80181674;
extern s32 D_80181678;
extern s32 D_8018167C;
extern s32 D_80181684;
extern s32 D_80181690;

extern s32 sPfsFilesState[];

#define SLOT_FOUND 0
#define SLOT_NOT_FOUND 5
#define FILE_FOUND 9

/**
 * Finds a Controller Pak/Pfs file slot matching the specified parameters.
 *
 * @param pfs         Unused parameter.
 * @param companyCode The company code to match.
 * @param gameCode    The game code to match.
 * @param gameName    Pointer to the game name to match (16 bytes).
 * @param extName     Pointer to the extension name to match (4 bytes).
 * @param slotFound   Pointer to an integer where the found slot index will be stored.
 * @return            SLOT_FOUND if a matching slot is found, otherwise SLOT_NOT_FOUND.
 */
s32 FindPfsSlot(UNUSED OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* slotFound) {
    s32 slot;

    for (slot = 0; slot < 16; slot++) {
        if (sPfsFilesState[slot] == PFS_SUCCESS) {

            /* If any of this checks is false find another slot.. */
            if (sPfsState[slot].company_code != companyCode) {
                continue;
            }

            if (sPfsState[slot].game_code != gameCode) {
                continue;
            }

            if (SysMem_Compare((u8*) sPfsState[slot].game_name, gameName, 16) != 0) {
                continue;
            }

            if (SysMem_Compare((u8*) sPfsState[slot].ext_name, extName, 4) != 0) {
                continue;
            }
            *slotFound = slot;
            return SLOT_FOUND;
        }
    }
    return SLOT_NOT_FOUND;
}

s32 func_800AE01C(OSPfs* arg0, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo) {
    s32 sp2C;
    s32 sp28;

    sp2C = FindPfsSlot(arg0, companyCode, gameCode, gameName, extName, &sp28);
    if (sp2C == SLOT_FOUND) {
        return FILE_FOUND;
    }
    return osPfsAllocateFile((OSPfs*) arg0, companyCode, gameCode, gameName, extName, length, fileNo);
}

s32 func_800AE0C0(u16 arg0, u32 arg1) {
    D_80181646 = arg0;
    D_8018164C = arg1;
    return 0;
}
s32 func_800AE0EC(OSMesgQueue* arg0) {
    UNUSED s32 pad;
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    if (D_80181690 == 0) {
        return -1;
    } else {
        D_80181690 -= 1;
    }

    osContReset(arg0, D_80182540);

    if (!(D_80182540->status & 1)) {
        if (D_80181690 == 0) {
            D_80181350 = 1;
            D_8018127C = 0;
            D_8018129C = 0;
        }
        return -1;
    } else if (osPfsIsPlug(arg0, &D_8018127C) < 0) {
        if (D_80181690 == 0) {
            D_80181350 = 1;
            D_8018127C = 0;
            D_8018129C = 0;
        }
        return -1;
    }
    if (D_8018127C != 0) {
        D_8018129C |= 2;
    } else {
        D_8018129C &= ~2;
    }
    if (D_8018127C & 0x10) {
        D_8018129C |= 1;
    } else {
        D_8018129C &= ~1;
    }
    if (D_8018127C & 1) {
        osPfsInit(arg0, &D_80181360, 0);
    }
    D_80181350 = 4;
    D_80181350 &= ~2;
    D_8018129C &= ~4;
    D_80181690 = 0;
    return 0;
}

void func_800AE348(s32 arg0) {
    D_80181350 |= 2;
    D_80181350 &= ~5;
    if (arg0 < 0) {
        arg0 = 1;
    }
    D_80181690 = arg0;
}

s32 func_800AE398(void) {
    if (D_80181350 & 4) {
        return 0;
    }
    if (D_80181350 & 1) {
        return -1;
    }
    if (D_80181690 != 0) {
        return 1;
    }
    return -2;
}

s32 func_800AE40C(void) {
    s32 sp1C;

    D_80181350 &= ~8;
    D_8018129C &= ~0x1C;
    D_80181684 = osPfsNumFiles(&D_80181360, &D_8018162C, &D_80181620);
    if (D_80181684 != 0) {
        D_8018129C |= 8;
        return -1;
    }

    for (sp1C = 0; sp1C < 16; sp1C++) {
        sPfsFilesState[sp1C] = osPfsFileState(&D_80181360, sp1C, &sPfsState[sp1C]);
    }
    D_80181684 = osPfsFreeBlocks(&D_80181360, &D_80181638);
    if (D_80181684 != 0) {
        D_8018129C |= 0x10;
        return -1;
    }
    D_80181638 = (s32) D_80181638 >> 8;
    D_8018129C |= 4;
    return 0;
}

s32 func_800AE580(void) {
    s32 slot;
    s32 availableSlots;

    for (slot = 0, availableSlots = 0; slot < 16; slot++) {
        if (sPfsFilesState[slot] == PFS_SUCCESS) {
            availableSlots++;
        }
    }
    return availableSlots;
}

s32 func_800AE5F0(s32 arg0) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    D_80181350 |= 0x10;
    D_80181640 = arg0;
    return 0;
}

s32 func_800AE664(void) {
    D_80181350 &= ~0x10;
    if (sPfsFilesState[D_80181640] == 0) {
        D_8018129C |= 0x20;
        D_80181684 = osPfsDeleteFile(&D_80181360, sPfsState[D_80181640].company_code, sPfsState[D_80181640].game_code,
                                     (u8*) sPfsState[D_80181640].game_name, (u8*) sPfsState[D_80181640].ext_name);
        if (D_80181684 == 0) {
            sPfsFilesState[D_80181640] = -1;
            D_80181638 += (u32) (sPfsState[D_80181640].file_size + 0xFF) >> 8;
            if (func_800AE40C() < 0) {
                D_8018129C &= ~0x20;
                return -1;
            }
        }
    } else {
        D_8018129C &= ~0x20;
        D_80181684 = 5;
        return -1;
    }

    D_8018129C &= ~0x20;
    return 0;
}

s32 func_800AE7FC(void) {
    if (D_80181350 & 0x10) {
        return -1;
    }
    if (D_8018129C & 0x20) {
        return -1;
    }
    if (D_80181684 != 0) {
        return D_80181684 | 0x1000;
    }
    return 0;
}

s32 func_800AE880(u8* arg0, u8* arg1, s32 arg2) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    D_80181654 = arg0;
    D_80181660 = arg1;
    D_80181674 = arg2;
    D_80181350 |= 0x20;
    return 0;
}

s32 func_800AE904(void) {
    D_80181350 &= ~0x20;
    D_8018129C |= 0x40;
    if (func_800AE40C() < 0) {
        D_8018129C &= ~0x40;
        return -1;
    }
    D_80181684 = func_800AE01C(&D_80181360, D_80181646, D_8018164C, D_80181654, D_80181660, D_80181674, &D_8018167C);
    if (D_80181684 == 0) {
        func_800AE40C();
    }
    D_8018129C &= ~0x40;
    return 0;
}

s32 func_800AEA0C(void) {
    if (D_80181350 & 0x20) {
        return -1;
    }
    if (D_8018129C & 0x40) {
        return -1;
    }
    if (D_80181684 != 0) {
        return D_80181684 | 0x1000;
    }
    return D_8018167C;
}

s32 func_800AEA98(u8* arg0, u8* arg1) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    D_80181654 = arg0;
    D_80181660 = arg1;
    D_80181350 |= 0x100;
    return 0;
}

s32 func_800AEB14(void) {
    D_80181350 &= ~0x100;
    D_8018129C |= 0x200;
    if (func_800AE40C() < 0) {
        D_8018129C &= ~0x200;
        return -1;
    }
    D_80181684 = FindPfsSlot(&D_80181360, D_80181646, D_8018164C, D_80181654, D_80181660, &D_8018167C);
    D_8018129C &= ~0x200;
    return 0;
}

s32 func_800AEBF4(void) {
    if (D_80181350 & 0x100) {
        return -1;
    }
    if (D_8018129C & 0x200) {
        return -1;
    }
    if (D_80181684 != 0) {
        return D_80181684 | 0x1000;
    }
    return D_8018167C;
}

s32 func_800AEC80(s32 arg0, s32 arg1, s32 arg2, u8* arg3) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    D_8018167C = arg0;
    D_80181678 = arg1;
    D_80181674 = arg2;
    D_80181670 = arg3;
    D_80181350 |= 0x80;
    return 0;
}

s32 func_800AED0C(void) {
    D_80181350 &= ~0x80;
    D_8018129C |= 0x100;
    if (func_800AE40C() < 0) {
        D_8018129C &= ~0x100;
        return -1;
    }
    D_80181684 = osPfsReadWriteFile(&D_80181360, D_8018167C, 1U, D_80181678, D_80181674, D_80181670);
    D_8018129C &= ~0x100;
    return 0;
}

s32 func_800AEDE8(void) {
    if (D_80181350 & 0x80) {
        return -1;
    }
    if (D_8018129C & 0x100) {
        return -1;
    }
    if (D_80181684 != 0) {
        return D_80181684 | 0x1000;
    }
    return 0;
}

s32 func_800AEE6C(s32 arg0, s32 arg1, s32 arg2, u8* arg3) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    D_8018167C = arg0;
    D_80181678 = arg1;
    D_80181674 = arg2;
    D_80181670 = arg3;
    D_80181350 |= 0x40;
    return 0;
}

s32 func_800AEEF8(void) {
    D_80181350 &= ~0x40;
    D_8018129C |= 0x80;
    if (func_800AE40C() < 0) {
        D_8018129C &= ~0x80;
        return -1;
    }
    D_80181684 = osPfsReadWriteFile(&D_80181360, D_8018167C, 0U, D_80181678, D_80181674, D_80181670);
    D_8018129C &= ~0x80;
    return 0;
}

s32 func_800AEFD4(void) {
    if (D_80181350 & 0x40) {
        return -1;
    }
    if (D_8018129C & 0x80) {
        return -1;
    }
    if (D_80181684 != 0) {
        return D_80181684 | 0x1000;
    }
    return 0;
}
