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

/*
 * Flag layout used by this module
 *
 * D_80181350 (high-level PFS state / pending operations)
 *   0x0001 : Detection / init failed (see func_800AE0EC, func_800AE398)
 *   0x0002 : Detection in progress (set by func_800AE348, cleared in func_800AE0EC)
 *   0x0004 : Detection completed successfully; controller + PFS ready
 *   0x0008 : Reserved for directory refresh scheduling (cleared here, set elsewhere)
 *   0x0010 : Delete-file operation scheduled / in progress (func_800AE5F0, func_800AE664)
 *   0x0020 : Create/open-file parameters staged (func_800AE880); not part of the global
 *            "busy" mask, but used to gate result polling (func_800AEA0C)
 *   0x0040 : Read-file parameters staged / read in progress (SetFileReadParams, ReadFile)
 *   0x0080 : Write-file parameters staged / write in progress (SetFileWriteParams, WriteFile)
 *   0x0100 : Find-existing-file operation staged / in progress (func_800AEA98, func_800AEB14)
 *
 *   0x01D8 : Aggregate "PFS busy" mask used by this file when scheduling new operations
 *            (bits 0x8, 0x10, 0x40, 0x80, 0x100).
 *
 * D_8018129C (low-level PFS status and error flags)
 *   0x0001 : Controller Pak presence/status flag mirrored from D_8018127C & 0x10
 *   0x0002 : At least one Controller Pak detected (D_8018127C != 0)
 *   0x0004 : Directory / free-block info is valid (set on successful func_800AE40C)
 *   0x0008 : Error while querying number of files (osPfsNumFiles failure in func_800AE40C)
 *   0x0010 : Error while querying free blocks (osPfsFreeBlocks failure in func_800AE40C)
 *   0x0020 : Delete-file operation active (func_800AE664 / func_800AE7FC)
 *   0x0040 : Create/open-file operation active (func_800AE904 / func_800AEA0C)
 *   0x0080 : Read-file operation active (ReadFile / func_800AEFD4)
 *   0x0100 : Write-file operation active (WriteFile / func_800AEDE8)
 *   0x0200 : Find-existing-file operation active (func_800AEB14 / func_800AEBF4)
 *
 *   0x03E0 : Aggregate "error/busy" mask for operations started via this module
 *            (bits 0x20, 0x40, 0x80, 0x100, 0x200). When any of these bits are set,
 *            new high-level operations are rejected.
 */

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

/**
 * Runs one step of the controller / Controller Pak detection and initialisation.
 *
 * This function is expected to be called repeatedly while a retry countdown
 * (stored in D_80181690) is non‑zero. It performs a controller reset, checks
 * whether a Controller Pak is present, and, if so, calls `osPfsInit` to set up
 * the `OSPfs` handle used by the rest of this module.
 *
 * On success, the global flags in `D_80181350` / `D_8018129C` are updated to
 * reflect a ready PFS state and the retry counter is cleared. If the PFS
 * subsystem is currently busy, an error condition is active, or the retry
 * counter has expired, the function returns `-1` without changing the current
 * state.
 *
 * @param contMesgQueue Message queue used by the controller / PFS APIs.
 * @return              0 on success, -1 if busy, an error occurred or the
 *                      retry count has run out.
 */
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

/**
 * Starts a controller / Controller Pak detection sequence.
 *
 * This function sets up the retry counter used by `func_800AE0EC` and marks
 * the PFS subsystem as "checking" in `D_80181350`. The actual hardware
 * interaction happens inside `func_800AE0EC`.
 *
 * @param arg0 Number of attempts to allow; if negative, it is clamped to 1.
 */
void func_800AE348(s32 arg0) {
    D_80181350 |= 2;
    D_80181350 &= ~5;
    if (arg0 < 0) {
        arg0 = 1;
    }
    D_80181690 = arg0;
}

/**
 * Returns the current status of the controller / PFS detection sequence.
 *
 * The return value is a small enum-like set of values used by callers to
 * decide how to proceed:
 *   -  0: detection completed successfully.
 *   - -1: detection failed.
 *   -  1: detection is still in progress (more retries remaining).
 *   - -2: detection has not been started.
 */
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

/**
 * Refreshes cached Controller Pak directory information.
 *
 * Reads the number of files, queries the state of each file slot and caches
 * the result in `gPfsFilesState` / `gPfsState`, and updates the free block
 * count in `D_80181638`. Various error flags are stored in `D_8018129C` and
 * the raw libultra return code is left in `D_80181684`.
 *
 * @return 0 on success, -1 if any of the underlying libultra calls failed.
 */
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

/**
 * Counts how many Controller Pak file slots are currently occupied.
 *
 * This simply scans `gPfsFilesState` and counts entries whose state is
 * `PFS_SUCCESS`.
 *
 * @return Number of valid files on the Controller Pak.
 */
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

/**
 * Schedules deletion of a Controller Pak file.
 *
 * The actual deletion is performed by `func_800AE664`; this function just
 * records the target slot and marks the PFS subsystem as busy so that other
 * operations cannot run concurrently.
 *
 * @param arg0 File slot index to delete.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
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

/**
 * Performs the actual Controller Pak file deletion.
 *
 * This uses the slot index prepared by `func_800AE5F0`, calls
 * `osPfsDeleteFile`, and, on success, updates the cached directory and free
 * block information by calling `func_800AE40C`.
 *
 * @return 0 on success, -1 on failure or when the slot does not contain a file.
 */
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

/**
 * Returns the result of the last delete-file operation.
 *
 * @return 0 if the last deletion finished successfully, a negative value if
 *         the operation is still in progress or blocked by another operation,
 *         or `D_80181684 | 0x1000` if libultra reported an error.
 */
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

/**
 * Prepares parameters for creating or opening a Controller Pak save file.
 *
 * The actual work is done in `func_800AE904`; this function just stores the
 * desired game name, extension and size and marks the operation as pending in
 * `D_80181350`.
 *
 * @param arg0 Pointer to the game name.
 * @param arg1 Pointer to the extension name.
 * @param arg2 Requested file size in bytes.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
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

/**
 * Creates or opens a Controller Pak save file using the prepared parameters.
 *
 * This function refreshes the directory information, calls `GetPfsFile` to
 * locate or create the file, and stores both the libultra return code and the
 * resulting slot index for later querying.
 *
 * @return 0 on success (regardless of whether the underlying libultra call
 *         succeeded), -1 if the directory refresh failed.
 */
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

/**
 * Returns the result of the last create/open file operation.
 *
 * If the operation completed successfully, this returns the file slot index.
 * Otherwise it either reports that the operation is still busy or propagates
 * the libultra error code stored in `D_80181684`.
 */
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

/**
 * Prepares parameters for searching an existing Controller Pak file.
 *
 * The actual search is carried out by `func_800AEB14`; this function stores
 * the game and extension names and marks the operation as pending.
 *
 * @param arg0 Pointer to the game name.
 * @param arg1 Pointer to the extension name.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
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

/**
 * Searches for an existing Controller Pak file using the prepared parameters.
 *
 * This refreshes directory information and calls `FindPfsSlot`, storing the
 * resulting libultra error code and file slot index for later retrieval.
 *
 * @return Always 0; callers should inspect `func_800AEBF4` for the final
 *         status and slot index.
 */
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

/**
 * Returns the result of the last "find existing file" operation.
 *
 * If a matching file was found, this returns its slot index. Otherwise it
 * either reports that the operation is still busy or propagates the libultra
 * error code stored in `D_80181684`.
 */
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

/**
 * Sets up parameters for an asynchronous write to a Controller Pak file.
 *
 * The actual write is performed by `WriteFile`; this function records the file
 * slot, offset, size and buffer pointer and marks the write operation as
 * pending in `D_80181350`.
 *
 * @param slot   File slot to write to.
 * @param offset Byte offset within the file.
 * @param size   Number of bytes to write.
 * @param buf    Source buffer.
 * @return       0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
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

/**
 * Performs the actual write to a Controller Pak file.
 *
 * This function first refreshes the directory information, then calls
 * `osPfsReadWriteFile` in write mode and stores the libultra return code in
 * `D_80181684`.
 *
 * @return 0 on success (irrespective of the libultra result), -1 if the
 *         directory refresh step failed.
 */
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

/**
 * Returns the result of the last write-file operation.
 *
 * @return 0 if the write finished successfully, a negative value if the
 *         operation is still in progress or blocked, or `D_80181684 | 0x1000`
 *         if libultra reported an error.
 */
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

/**
 * Sets up parameters for an asynchronous read from a Controller Pak file.
 *
 * The actual read is performed by `ReadFile`; this function records the file
 * slot, offset, size and buffer pointer and marks the read operation as
 * pending in `D_80181350`.
 *
 * @param slot   File slot to read from.
 * @param offset Byte offset within the file.
 * @param size   Number of bytes to read.
 * @param buf    Destination buffer.
 * @return       0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
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

/**
 * Performs the actual read from a Controller Pak file.
 *
 * This function first refreshes the directory information, then calls
 * `osPfsReadWriteFile` in read mode and stores the libultra return code in
 * `D_80181684`.
 *
 * @return 0 on success (irrespective of the libultra result), -1 if the
 *         directory refresh step failed.
 */
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

/**
 * Returns the result of the last read-file operation.
 *
 * @return 0 if the read finished successfully, a negative value if the
 *         operation is still in progress or blocked, or `D_80181684 | 0x1000`
 *         if libultra reported an error.
 */
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
