#include "common.h"

extern s32 D_8018129C;
extern OSPfs D_80181360;
extern OSPfsState gPfsState[];
// extern ? D_801813D4;
// extern ? D_801813D8;
extern s32 D_80181620;
extern s32 D_8018162C;
extern s32 D_80181638;
extern s32 D_80181640;
extern u16 sCompanyCode;
extern u32 sGameCode;
extern u8* sGameName;
extern u8* sExtname;
extern u8* sFileData;
extern s32 sFileSize;
extern s32 sFileOffset;
extern s32 sPfsSlot;
extern s32 D_80181684;
extern s32 D_80181690;

// D_80181350 = SysPfs api flags?
extern s32 gPfsFilesState[];

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
        if (gPfsFilesState[slot] == PFS_SUCCESS) {

            /* If any of this checks is false find another slot.. */
            if (gPfsState[slot].company_code != companyCode) {
                continue;
            }

            if (gPfsState[slot].game_code != gameCode) {
                continue;
            }

            if (SysMem_Compare((u8*) gPfsState[slot].game_name, gameName, 16) != 0) {
                continue;
            }

            if (SysMem_Compare((u8*) gPfsState[slot].ext_name, extName, 4) != 0) {
                continue;
            }
            *slotFound = slot;
            return SLOT_FOUND;
        }
    }
    return SLOT_NOT_FOUND;
}

/**
 * Retrieves the file number of a file on the Controller Pak (memory card) that matches the specified
 * company code, game code, game name, and extension name.
 *
 * @param arg0         Pointer to an OSPfs structure representing the Controller Pak.
 * @param companyCode  16-bit company code identifying the developer.
 * @param gameCode     32-bit game code identifying the game.
 * @param gameName     Pointer to a buffer containing the game's name.
 * @param extName      Pointer to a buffer containing the file's extension name.
 * @param length       Length of the gameName and extName buffers.
 * @param fileNo       Pointer to an integer where the found file number will be stored.
 * @return             Status code indicating success or failure of the operation.
 * 
 * @note If the file doesn't exists the function will try to create a new by calling osPfsAllocateFile
 */
s32 GetPfsFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo) {
    s32 ret;
    s32 sp28;

    ret = FindPfsSlot(pfs, companyCode, gameCode, gameName, extName, &sp28);
    if (ret == SLOT_FOUND) {
        return FILE_FOUND;
    }
    return osPfsAllocateFile((OSPfs*) pfs, companyCode, gameCode, gameName, extName, length, fileNo);
}


/**
 * Sets the PFS (Peripheral File System) codes for the game.
 *
 * @param companyCode The 16-bit code representing the company.
 * @param gameCode The 32-bit code representing the game.
 * @return Returns an status code indicating success or failure.
 */
s32 SetPfsCodes(u16 companyCode, u32 gameCode) {
    sCompanyCode = companyCode;
    sGameCode = gameCode;
    return PFS_SUCCESS;
}

s32 func_800AE0EC(OSMesgQueue* contMesgQueue) {
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
        D_80181690--;
    }

    osContReset(contMesgQueue, D_80182540);

    // If the controller is not inserted
    if (!(D_80182540->status & CONT_CARD_ON)) {
        if (D_80181690 == 0) {
            D_80181350 = 1;
            D_8018127C = 0;
            D_8018129C = 0;
        }
        return -1;
    } else if (osPfsIsPlug(contMesgQueue, &D_8018127C) < 0) {
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
    if (D_8018127C & 16) {
        D_8018129C |= 1;
    } else {
        D_8018129C &= ~1;
    }
    if (D_8018127C & 1) {
        osPfsInit(contMesgQueue, &D_80181360, 0);
    }
    D_80181350 = 4;
    D_80181350 &= ~2; // Still 4
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
    if (D_80181684 != PFS_SUCCESS) {
        D_8018129C |= 8;
        return -1;
    }

    for (sp1C = 0; sp1C < 16; sp1C++) {
        gPfsFilesState[sp1C] = osPfsFileState(&D_80181360, sp1C, &gPfsState[sp1C]);
    }
    D_80181684 = osPfsFreeBlocks(&D_80181360, &D_80181638);
    if (D_80181684 != PFS_SUCCESS) {
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
        if (gPfsFilesState[slot] == PFS_SUCCESS) {
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
    if (gPfsFilesState[D_80181640] == 0) {
        D_8018129C |= 0x20;
        D_80181684 = osPfsDeleteFile(&D_80181360, gPfsState[D_80181640].company_code, gPfsState[D_80181640].game_code,
                                     (u8*) gPfsState[D_80181640].game_name, (u8*) gPfsState[D_80181640].ext_name);
        if (D_80181684 == 0) {
            gPfsFilesState[D_80181640] = -1;
            D_80181638 += (u32) (gPfsState[D_80181640].file_size + 255) >> 8;
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
    sGameName = arg0;
    sExtname = arg1;
    sFileSize = arg2;
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
    D_80181684 = GetPfsFile(&D_80181360, sCompanyCode, sGameCode, sGameName, sExtname, sFileSize, &sPfsSlot);
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
    return sPfsSlot;
}

s32 func_800AEA98(u8* arg0, u8* arg1) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    sGameName = arg0;
    sExtname = arg1;
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
    D_80181684 = FindPfsSlot(&D_80181360, sCompanyCode, sGameCode, sGameName, sExtname, &sPfsSlot);
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
    return sPfsSlot;
}

s32 SetFileWriteParams(s32 slot, s32 offset, s32 size, u8* buf) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    sPfsSlot = slot;
    sFileOffset = offset;
    sFileSize = size;
    sFileData = buf;
    D_80181350 |= 0x80;
    return 0;
}

s32 WriteFile(void) {
    D_80181350 &= ~0x80;
    D_8018129C |= 0x100;
    if (func_800AE40C() < 0) {
        D_8018129C &= ~0x100;
        return -1;
    }
    D_80181684 = osPfsReadWriteFile(&D_80181360, sPfsSlot, PFS_WRITE, sFileOffset, sFileSize, sFileData);
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

s32 SetFileReadParams(s32 slot, s32 offset, s32 size, u8* buf) {
    if (D_80181350 & 0x1D8) {
        return -1;
    }
    if (D_8018129C & 0x3E0) {
        return -1;
    }
    sPfsSlot = slot;
    sFileOffset = offset;
    sFileSize = size;
    sFileData = buf;
    D_80181350 |= 0x40;
    return 0;
}

s32 ReadFile(void) {
    D_80181350 &= ~0x40;
    D_8018129C |= 0x80;
    if (func_800AE40C() < 0) {
        D_8018129C &= ~0x80;
        return -1;
    }
    D_80181684 = osPfsReadWriteFile(&D_80181360, sPfsSlot, PFS_READ, sFileOffset, sFileSize, sFileData);
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
