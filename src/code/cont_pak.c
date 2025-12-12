#include "common.h"

#define FLAGS_DELETE_FILE 0x10
#define FLAGS_PFS_DEL_FILE 0x20

#define FLAGS_OPEN_FILE 0x20
#define FLAGS_PFS_OPEN_FILE 0x40

#define FLAGS_READ_FILE 0x40
#define FLAGS_PFS_READ_FILE \
    0x80 /* Flags to indicate that the pfs operations that are being perfomed because of the read operation */

#define FLAGS_WRITE_FILE 0x80
#define FLAGS_PFS_WRITE_FILE \
    0x100 /* Flags to indicate that the pfs operations that are being perfomed because of the read operation */

#define FLAGS_FIND_FILE 0x100
#define FLAGS_PFS_FIND_FILE 0x200

extern s32 gCurrentPakPfsFlags; // Flags used

extern OSPfs sPfs;
extern OSPfsState gPfsState[];
// extern ? D_801813D4;
// extern ? D_801813D8;
extern s32 sPfsFilesUsed;
extern s32 sPfsMaxFiles;
extern s32 gPfsFreeSpace;
extern s32 sContPakFileDeleteSlot;
extern u16 sCompanyCode;
extern u32 sGameCode;
extern u8* sGameName;
extern u8* sExtname;
extern u8* sFileData;
extern s32 sFileSize;
extern s32 sFileOffset;
extern s32 sPfsSlot;
extern s32 sPfsResult;
extern s32 D_80181690;

// gCurrentPakOperationFlags = SysPfs api flags?
extern s32 gContPakFilesState[];

/*
 * Flag layout used by this module
 *
 * gCurrentPakOperationFlags (high-level PFS state / pending operations)
 *   0x0001 : Detection / init failed (see func_800AE0EC, func_800AE398)
 *   0x0002 : Detection in progress (set by func_800AE348, cleared in func_800AE0EC)
 *   0x0004 : Detection completed successfully; controller + PFS ready
 *   0x0008 : Reserved for directory refresh scheduling (cleared here, set elsewhere)
 *   0x0010 : Delete-file operation scheduled / in progress (ContPak_SetFileDeleteParams, ContPak_DeleteFile)
 *   0x0020 : Create/open-file parameters staged (ContPak_SetOpenFileParams); not part of the global
 *            "busy" mask, but used to gate result polling (ContPak_GetOpenFileResult)
 *   0x0040 : Read-file parameters staged / read in progress (ContPak_SetFileReadParams, ContPak_ReadFile)
 *   0x0080 : Write-file parameters staged / write in progress (ContPak_SetFileWriteParams, ContPak_WriteFile)
 *   0x0100 : Find-existing-file operation staged / in progress (ContPak_SetFileFindParams, func_800AEB14)
 *
 *   0x01D8 : Aggregate "PFS busy" mask used by this file when scheduling new operations
 *            (bits 0x8, 0x10, 0x40, 0x80, 0x100).
 *
 * gCurrentPakPfsFlags (low-level PFS status and error flags)
 *   0x0001 : Controller Pak presence/status flag mirrored from D_8018127C & 0x10
 *   0x0002 : At least one Controller Pak detected (D_8018127C != 0)
 *   0x0004 : Directory / free-block info is valid (set on successful func_800AE40C)
 *   0x0008 : Error while querying number of files (osPfsNumFiles failure in func_800AE40C)
 *   0x0010 : Error while querying free blocks (osPfsFreeBlocks failure in func_800AE40C)
 *   0x0020 : Delete-file operation active (ContPak_DeleteFile / func_800AE7FC)
 *   0x0040 : Create/open-file operation active (ContPak_OpenFile / ContPak_GetOpenFileResult)
 *   0x0080 : Read-file operation active (ContPak_ReadFile / ContPak_GetReadFileResult)
 *   0x0100 : Write-file operation active (ContPak_WriteFile / ContPak_GetWriteFileResult)
 *   0x0200 : Find-existing-file operation active (func_800AEB14 / ContPak_GetFindFileResult)
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
s32 ContPak_FindPfsSlot(UNUSED OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* slotFound) {
    s32 slot;

    for (slot = 0; slot < 16; slot++) {
        if (gContPakFilesState[slot] == PFS_SUCCESS) {

            // !< If any of this checks is false find another slot..
            if (gPfsState[slot].company_code != companyCode) {
                continue;
            }

            if (gPfsState[slot].game_code != gameCode) {
                continue;
            }

            if (SysMem_Bcmp(gPfsState[slot].game_name, gameName, 16) != 0) {
                continue;
            }

            if (SysMem_Bcmp(gPfsState[slot].ext_name, extName, 4) != 0) {
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
s32 ContPak_GetPfsFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo) {
    s32 ret;
    s32 slotFound;

    ret = ContPak_FindPfsSlot(pfs, companyCode, gameCode, gameName, extName, &slotFound);
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
s32 ContPak_SetPfsCodes(u16 companyCode, u32 gameCode) {
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
 * On success, the global flags in `gCurrentPakOperationFlags` / `gCurrentPakPfsFlags` are updated to
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
    if (gCurrentPakOperationFlags & 0x1D8) {
        return -1;
    }
    if (gCurrentPakPfsFlags &
        (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)) {
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
            gCurrentPakOperationFlags = 1;
            D_8018127C = 0;
            gCurrentPakPfsFlags = 0;
        }
        return -1;
    } else if (osPfsIsPlug(contMesgQueue, &D_8018127C) < 0) {
        if (D_80181690 == 0) {
            gCurrentPakOperationFlags = 1;
            D_8018127C = 0;
            gCurrentPakPfsFlags = 0;
        }
        return -1;
    }
    if (D_8018127C != 0) {
        gCurrentPakPfsFlags |= 2;
    } else {
        gCurrentPakPfsFlags &= ~2;
    }
    if (D_8018127C & 16) {
        gCurrentPakPfsFlags |= 1;
    } else {
        gCurrentPakPfsFlags &= ~1;
    }
    if (D_8018127C & 1) {
        osPfsInit(contMesgQueue, &sPfs, 0);
    }
    gCurrentPakOperationFlags = 4;
    gCurrentPakOperationFlags &= ~2; // Still 4
    gCurrentPakPfsFlags &= ~4;
    D_80181690 = 0;
    return 0;
}

/**
 * Starts a controller / Controller Pak detection sequence.
 *
 * This function sets up the retry counter used by `func_800AE0EC` and marks
 * the PFS subsystem as "checking" in `gCurrentPakOperationFlags`. The actual hardware
 * interaction happens inside `func_800AE0EC`.
 *
 * @param arg0 Number of attempts to allow; if negative, it is clamped to 1.
 */
void func_800AE348(s32 arg0) {
    gCurrentPakOperationFlags |= 2;
    gCurrentPakOperationFlags &= ~5;
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
    if (gCurrentPakOperationFlags & 4) {
        return 0;
    }
    if (gCurrentPakOperationFlags & 1) {
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
 * the result in `gContPakFilesState` / `gPfsState`, and updates the free block
 * count in `gPfsFreeSpace`. Various error flags are stored in `gCurrentPakPfsFlags` and
 * the raw libultra return code is left in `sPfsResult`.
 *
 * @return 0 on success, -1 if any of the underlying libultra calls failed.
 */
s32 func_800AE40C(void) {
    s32 fileSlot;

    gCurrentPakOperationFlags &= ~8;
    gCurrentPakPfsFlags &= ~0x1C;
    sPfsResult = osPfsNumFiles(&sPfs, &sPfsMaxFiles, &sPfsFilesUsed);
    if (sPfsResult != PFS_SUCCESS) {
        gCurrentPakPfsFlags |= 8;
        return -1;
    }

    for (fileSlot = 0; fileSlot < 16; fileSlot++) {
        gContPakFilesState[fileSlot] = osPfsFileState(&sPfs, fileSlot, &gPfsState[fileSlot]);
    }
    sPfsResult = osPfsFreeBlocks(&sPfs, &gPfsFreeSpace);
    if (sPfsResult != PFS_SUCCESS) {
        gCurrentPakPfsFlags |= 0x10;
        return -1;
    }
    gPfsFreeSpace = (s32) gPfsFreeSpace >> 8;
    gCurrentPakPfsFlags |= 4;
    return 0;
}

/**
 * Counts how many Controller Pak file slots are currently occupied.
 *
 * This simply scans `gContPakFilesState` and counts entries whose state is
 * `PFS_SUCCESS`.
 *
 * @return Number of valid files on the Controller Pak.
 */
s32 ContPak_GetAvailableSlots(void) {
    s32 slot;
    s32 availableSlots;

    for (slot = 0, availableSlots = 0; slot < 16; slot++) {
        if (gContPakFilesState[slot] == PFS_SUCCESS) {
            availableSlots++;
        }
    }
    return availableSlots;
}

/**
 * Schedules deletion of a Controller Pak file.
 *
 * The actual deletion is performed by `ContPak_DeleteFile`; this function just
 * records the target slot and marks the PFS subsystem as busy so that other
 * operations cannot run concurrently.
 *
 * @param fileSlot File slot index to delete.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileDeleteParams(s32 fileSlot) {
    if (gCurrentPakOperationFlags & 0x1D8) {
        return -1;
    }
    if (gCurrentPakPfsFlags &
        (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)) {
        return -1;
    }
    gCurrentPakOperationFlags |= FLAGS_DELETE_FILE;
    sContPakFileDeleteSlot = fileSlot;
    return 0;
}

/**
 * Performs the actual Controller Pak file deletion.
 *
 * This uses the slot index prepared by `ContPak_SetFileDeleteParams`, calls
 * `osPfsDeleteFile`, and, on success, updates the cached directory and free
 * block information by calling `func_800AE40C`.
 *
 * @return 0 on success, -1 on failure or when the slot does not contain a file.
 */
s32 ContPak_DeleteFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_DELETE_FILE;
    if (gContPakFilesState[sContPakFileDeleteSlot] == 0) {
        gCurrentPakPfsFlags |= FLAGS_PFS_DEL_FILE;
        sPfsResult = osPfsDeleteFile(&sPfs, gPfsState[sContPakFileDeleteSlot].company_code, gPfsState[sContPakFileDeleteSlot].game_code,
                                     (u8*) gPfsState[sContPakFileDeleteSlot].game_name, (u8*) gPfsState[sContPakFileDeleteSlot].ext_name);
        if (sPfsResult == 0) {
            gContPakFilesState[sContPakFileDeleteSlot] = -1;
            gPfsFreeSpace += (u32) (gPfsState[sContPakFileDeleteSlot].file_size + 255) >> 8;
            if (func_800AE40C() < 0) {
                gCurrentPakPfsFlags &= ~FLAGS_PFS_DEL_FILE;
                return -1;
            }
        }
    } else {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_DEL_FILE;
        sPfsResult = 5;
        return -1;
    }

    gCurrentPakPfsFlags &= ~FLAGS_PFS_DEL_FILE;
    return 0;
}

/**
 * Returns the result of the last delete-file operation.
 *
 * @return 0 if the last deletion finished successfully, a negative value if
 *         the operation is still in progress or blocked by another operation,
 *         or `sPfsResult | 0x1000` if libultra reported an error.
 */
s32 ContPak_GetDeleteFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_DELETE_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_DEL_FILE) {
        return -1;
    }
    if (sPfsResult != 0) {
        return sPfsResult | 0x1000;
    }
    return 0;
}

/**
 * Prepares parameters for creating or opening a Controller Pak save file.
 *
 * The actual work is done in `ContPak_OpenFile`; this function just stores the
 * desired game name, extension and size and marks the operation as pending in
 * `gCurrentPakOperationFlags`.
 *
 * @param arg0 Pointer to the game name.
 * @param arg1 Pointer to the extension name.
 * @param arg2 Requested file size in bytes.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetOpenFileParams(u8* gameName, u8* extName, s32 fileSize) {
    if (gCurrentPakOperationFlags & 0x1D8) {
        return -1;
    }
    if (gCurrentPakPfsFlags &
        (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)) {
        return -1;
    }
    sGameName = gameName;
    sExtname = extName;
    sFileSize = fileSize;
    gCurrentPakOperationFlags |= FLAGS_OPEN_FILE;
    return 0;
}

/**
 * Creates or opens a Controller Pak save file using the prepared parameters.
 *
 * This function refreshes the directory information, calls `ContPak_GetPfsFile` to
 * locate or create the file, and stores both the libultra return code and the
 * resulting slot index for later querying.
 *
 * @return 0 on success (regardless of whether the underlying libultra call
 *         succeeded), -1 if the directory refresh failed.
 */
s32 ContPak_OpenFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_OPEN_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_OPEN_FILE;
    if (func_800AE40C() < 0) {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_OPEN_FILE;
        return -1;
    }
    sPfsResult = ContPak_GetPfsFile(&sPfs, sCompanyCode, sGameCode, sGameName, sExtname, sFileSize, &sPfsSlot);
    if (sPfsResult == 0) {
        func_800AE40C();
    }
    gCurrentPakPfsFlags &= ~FLAGS_PFS_OPEN_FILE;
    return 0;
}

/**
 * Returns the result of the last create/open file operation.
 *
 * If the operation completed successfully, this returns the file slot index.
 * Otherwise it either reports that the operation is still busy or propagates
 * the libultra error code stored in `sPfsResult`.
 */
s32 ContPak_GetOpenFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_OPEN_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_OPEN_FILE) {
        return -1;
    }
    if (sPfsResult != 0) {
        return sPfsResult | 0x1000;
    }
    return sPfsSlot;
}

/**
 * Prepares parameters for searching an existing Controller Pak file.
 *
 * The actual search is carried out by `func_800AEB14`; this function stores
 * the game and extension names and marks the operation as pending.
 *
 * @param gameName Pointer to the game name.
 * @param extName Pointer to the extension name.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileFindParams(u8* gameName, u8* extName) {
    if (gCurrentPakOperationFlags & 0x1D8) {
        return -1;
    }
    if (gCurrentPakPfsFlags &
        (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)) {
        return -1;
    }
    sGameName = gameName;
    sExtname = extName;
    gCurrentPakOperationFlags |= FLAGS_FIND_FILE;
    return 0;
}

/**
 * Searches for an existing Controller Pak file using the prepared parameters.
 *
 * This refreshes directory information and calls `ContPak_FindPfsSlot`, storing the
 * resulting libultra error code and file slot index for later retrieval.
 *
 * @return Always 0; callers should inspect `ContPak_GetFindFileResult` for the final
 *         status and slot index.
 */
s32 ContPak_FindFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_FIND_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_FIND_FILE;
    if (func_800AE40C() < 0) {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_FIND_FILE;
        return -1;
    }
    sPfsResult = ContPak_FindPfsSlot(&sPfs, sCompanyCode, sGameCode, sGameName, sExtname, &sPfsSlot);
    gCurrentPakPfsFlags &= ~FLAGS_PFS_FIND_FILE;
    return 0;
}

/**
 * Returns the result of the last "find existing file" operation.
 *
 * If a matching file was found, this returns its slot index. Otherwise it
 * either reports that the operation is still busy or propagates the libultra
 * error code stored in `sPfsResult`.
 */
s32 ContPak_GetFindFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_FIND_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_FIND_FILE) {
        return -1;
    }
    if (sPfsResult != 0) {
        return sPfsResult | 0x1000;
    }
    return sPfsSlot;
}

/**
 * Sets up parameters for an asynchronous write to a Controller Pak file.
 *
 * The actual write is performed by `ContPak_WriteFile`; this function records the file
 * slot, offset, size and buffer pointer and marks the write operation as
 * pending in `gCurrentPakOperationFlags`.
 *
 * @param slot   File slot to write to.
 * @param offset Byte offset within the file.
 * @param size   Number of bytes to write.
 * @param buf    Source buffer.
 * @return       0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileWriteParams(s32 slot, s32 offset, s32 size, u8* buf) {
    if (gCurrentPakOperationFlags & 0x1D8) {
        return -1;
    }
    if (gCurrentPakPfsFlags &
        (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)) {
        return -1;
    }
    sPfsSlot = slot;
    sFileOffset = offset;
    sFileSize = size;
    sFileData = buf;
    gCurrentPakOperationFlags |= FLAGS_WRITE_FILE;
    return 0;
}

/**
 * Performs the actual write to a Controller Pak file.
 *
 * This function first refreshes the directory information, then calls
 * `osPfsReadWriteFile` in write mode and stores the libultra return code in
 * `sPfsResult`.
 *
 * @return 0 on success (irrespective of the libultra result), -1 if the
 *         directory refresh step failed.
 */
s32 ContPak_WriteFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_WRITE_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_WRITE_FILE;
    if (func_800AE40C() < 0) {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_WRITE_FILE;
        return -1;
    }
    sPfsResult = osPfsReadWriteFile(&sPfs, sPfsSlot, PFS_WRITE, sFileOffset, sFileSize, sFileData);
    gCurrentPakPfsFlags &= ~FLAGS_PFS_WRITE_FILE;
    return 0;
}

/**
 * Returns the result of the last write-file operation.
 *
 * @return 0 if the write finished successfully, a negative value if the
 *         operation is still in progress or blocked, or `sPfsResult | 0x1000`
 *         if libultra reported an error.
 */
s32 ContPak_GetWriteFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_WRITE_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_WRITE_FILE) {
        return -1;
    }
    if (sPfsResult != 0) {
        return sPfsResult | 0x1000;
    }
    return 0;
}

/**
 * Sets up parameters for an asynchronous read from a Controller Pak file.
 *
 * The actual read is performed by `ContPak_ReadFile`; this function records the file
 * slot, offset, size and buffer pointer and marks the read operation as
 * pending in `gCurrentPakOperationFlags`.
 *
 * @param slot   File slot to read from.
 * @param offset Byte offset within the file.
 * @param size   Number of bytes to read.
 * @param buf    Destination buffer.
 * @return       0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileReadParams(s32 slot, s32 offset, s32 size, u8* buf) {
    if (gCurrentPakOperationFlags & 0x1D8) {
        return -1;
    }
    if (gCurrentPakPfsFlags &
        (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)) {
        return -1;
    }
    sPfsSlot = slot;
    sFileOffset = offset;
    sFileSize = size;
    sFileData = buf;
    gCurrentPakOperationFlags |= FLAGS_READ_FILE;
    return 0;
}

/**
 * Performs the actual read from a Controller Pak file.
 *
 * This function first refreshes the directory information, then calls
 * `osPfsReadWriteFile` in read mode and stores the libultra return code in
 * `sPfsResult`.
 *
 * @return 0 on success (irrespective of the libultra result), -1 if the
 *         directory refresh step failed.
 */
s32 ContPak_ReadFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_READ_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_READ_FILE;
    if (func_800AE40C() < 0) {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_READ_FILE;
        return -1;
    }
    sPfsResult = osPfsReadWriteFile(&sPfs, sPfsSlot, PFS_READ, sFileOffset, sFileSize, sFileData);
    gCurrentPakPfsFlags &= ~FLAGS_PFS_READ_FILE;
    return 0;
}

/**
 * Returns the result of the last read-file operation.
 *
 * @return 0 if the read finished successfully, a negative value if the
 *         operation is still in progress or blocked, or `sPfsResult | 0x1000`
 *         if libultra reported an error.
 */
s32 ContPak_GetReadFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_READ_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_READ_FILE) {
        return -1;
    }
    if (sPfsResult != 0) {
        return sPfsResult | 0x1000;
    }
    return 0;
}
