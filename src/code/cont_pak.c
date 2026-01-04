#include "common.h"

extern s32 gCurrentPakPfsFlags;
extern OSPfs sPfs;
extern OSPfsState gPfsState[];
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
extern s32 gContPakInitializeAttempts;
extern s32 gContPakFilesState[];

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
 * (stored in gContPakInitializeAttempts) is non‑zero. It performs a controller reset, checks
 * whether a Controller Pak is present, and, if so, calls `osPfsInit` to set up
 * the `OSPfs` handle used by the rest of this module.
 *
 * On success, it updates the global flags `gCurrentPakOperationFlags` and `gCurrentPakPfsFlags` to
 * reflect a ready PFS state and the retry counter is cleared. If all PFS and pak operations have already been applied
 * or the retry counter has expired, the function returns `-1` without changing the current state.
 *
 * @param contMesgQueue Message queue used by the controller / PFS APIs.
 * @return              0 on success, -1 if busy, an error occurred or the
 *                      retry count has run out.
 */
s32 ContPak_InitializePak(OSMesgQueue* contMesgQueue) {
    UNUSED s32 pad;
    if (gCurrentPakOperationFlags & PAK_BUSY) {
        return -1;
    }
    if (gCurrentPakPfsFlags & PFS_BUSY) {
        return -1;
    }
    if (gContPakInitializeAttempts == 0) {
        return -1;
    } else {
        gContPakInitializeAttempts--;
    }

    osContReset(contMesgQueue, gContStatus);

    // If the controller is not inserted
    if (!(gContStatus->status & CONT_CARD_ON)) {
        if (gContPakInitializeAttempts == 0) {
            gCurrentPakOperationFlags = FLAGS_PAK_INITILIZATION_FAILED;
            gContPakBitPattern = 0;
            gCurrentPakPfsFlags = 0;
        }
        return -1;
    } else if (osPfsIsPlug(contMesgQueue, &gContPakBitPattern) < 0) {
        if (gContPakInitializeAttempts == 0) {
            gCurrentPakOperationFlags = FLAGS_PAK_INITILIZATION_FAILED;
            gContPakBitPattern = 0;
            gCurrentPakPfsFlags = 0;
        }
        return -1;
    }
    if (gContPakBitPattern != 0) {
        gCurrentPakPfsFlags |= 2;
    } else {
        gCurrentPakPfsFlags &= ~2;
    }
    if (gContPakBitPattern & 16) {
        gCurrentPakPfsFlags |= 1;
    } else {
        gCurrentPakPfsFlags &= ~1;
    }

    if (gContPakBitPattern & 1) {
        osPfsInit(contMesgQueue, &sPfs, 0);
    }
    gCurrentPakOperationFlags = FLAGS_PAK_INITILIZATION_SUCCESS;
    gCurrentPakOperationFlags &= ~2;
    gCurrentPakPfsFlags &= ~4;
    gContPakInitializeAttempts = 0;
    return 0;
}

/**
 * Starts a controller / Controller Pak detection sequence.
 *
 * This function sets up the retry counter used by `ContPak_InitializePak`
 *
 * @param attempts Number of attempts to allow; if negative, it is clamped to 1.
 */
void ContPak_SetPakInitializationAttempts(s32 attempts) {
    gCurrentPakOperationFlags |= 2;
    gCurrentPakOperationFlags &= ~5;
    if (attempts < 0) {
        attempts = 1;
    }
    gContPakInitializeAttempts = attempts;
}

/**
 * Returns the current status of the controller / PFS detection sequence.
 *
 * The return value is a small enum-like set of values used by callers to
 * decide how to proceed:
 *   -  0: detection completed successfully.
 *   - -1: detection failed.
 *   -  1: detection is still in progress (more retries remaining).
 *   - -2: detection has not been started maybe?.
 */
s32 ContPak_GetPakInitilizationResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_PAK_INITILIZATION_SUCCESS) {
        return 0;
    }
    if (gCurrentPakOperationFlags & FLAGS_PAK_INITILIZATION_FAILED) {
        return -1;
    }
    if (gContPakInitializeAttempts != 0) {
        return 1;
    }
    return -2;
}

/**
 * Updates the Controller Pak files state
 *
 * Reads the number of files, queries the state of each file slot and stores
 * the result in `gContPakFilesState` / `gPfsState`, and updates the free block
 * count in `gPfsFreeSpace`.
 *
 * @return 0 on success, -1 if any of the underlying libultra pfs calls failed.
 */
s32 ContPak_UpdateFilesState(void) {
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
    gPfsFreeSpace >>= 8;
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
 * Set the required parameters for the deletion of a Controller Pak file.
 * @param fileSlot File slot index to delete.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileDeleteParams(s32 fileSlot) {
    if (gCurrentPakOperationFlags & PAK_BUSY) {
        return -1;
    }
    if (gCurrentPakPfsFlags & PFS_BUSY) {
        return -1;
    }
    gCurrentPakOperationFlags |= FLAGS_PAK_DELETE_FILE;
    sContPakFileDeleteSlot = fileSlot;
    return 0;
}

/**
 * Performs the actual Controller Pak file deletion.
 *
 * This uses the slot index prepared by `ContPak_SetFileDeleteParams`, calls
 * `osPfsDeleteFile`, and, on success, updates the cached directory and free
 * block information by calling `ContPak_UpdateFilesState`.
 *
 * @return 0 on success, -1 on failure or when the slot does not contain a file.
 */
s32 ContPak_DeleteFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_PAK_DELETE_FILE;
    if (gContPakFilesState[sContPakFileDeleteSlot] == 0) {
        gCurrentPakPfsFlags |= FLAGS_PFS_DEL_FILE;
        sPfsResult = osPfsDeleteFile(
            &sPfs, gPfsState[sContPakFileDeleteSlot].company_code, gPfsState[sContPakFileDeleteSlot].game_code,
            (u8*) gPfsState[sContPakFileDeleteSlot].game_name, (u8*) gPfsState[sContPakFileDeleteSlot].ext_name);
        if (sPfsResult == 0) {
            gContPakFilesState[sContPakFileDeleteSlot] = -1;
            gPfsFreeSpace += (u32) (gPfsState[sContPakFileDeleteSlot].file_size + 255) >> 8;
            if (ContPak_UpdateFilesState() < PFS_SUCCESS) {
                gCurrentPakPfsFlags &= ~FLAGS_PFS_DEL_FILE;
                return -1;
            }
        }
    } else {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_DEL_FILE;
        sPfsResult = PFS_ERR_INVALID;
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
 *         or `sPfsResult | PFS_ERROR_MAGIC` if libultra reported an error.
 */
s32 ContPak_GetDeleteFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_PAK_DELETE_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_DEL_FILE) {
        return -1;
    }
    if (sPfsResult != 0) {
        return sPfsResult | PFS_ERROR_MAGIC;
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
 * @param gameName Pointer to the game name.
 * @param extName Pointer to the extension name.
 * @param fileSize Requested file size in bytes.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetOpenFileParams(u8* gameName, u8* extName, s32 fileSize) {
    if (gCurrentPakOperationFlags & PAK_BUSY) {
        return -1;
    }
    if (gCurrentPakPfsFlags & PFS_BUSY) {
        return -1;
    }
    sGameName = gameName;
    sExtname = extName;
    sFileSize = fileSize;
    gCurrentPakOperationFlags |= FLAGS_PAK_OPEN_FILE;
    return 0;
}

/**
 * Creates or opens a Controller Pak save file using the prepared parameters by `ContPak_SetOpenFileParams`
 *
 * This function refreshes the directory information, calls `ContPak_GetPfsFile` to
 * locate or create the file, and stores both the libultra return code and the
 * resulting slot index for later querying.
 *
 * @return 0 on success (regardless of whether the underlying libultra call
 *         succeeded), -1 if the directory refresh failed.
 */
s32 ContPak_OpenFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_PAK_OPEN_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_OPEN_FILE;
    if (ContPak_UpdateFilesState() < 0) {
        gCurrentPakPfsFlags &= ~FLAGS_PFS_OPEN_FILE;
        return -1;
    }
    sPfsResult = ContPak_GetPfsFile(&sPfs, sCompanyCode, sGameCode, sGameName, sExtname, sFileSize, &sPfsSlot);
    if (sPfsResult == 0) {
        ContPak_UpdateFilesState();
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
 * 
 * @return 0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_GetOpenFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_PAK_OPEN_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_OPEN_FILE) {
        return -1;
    }
    if (sPfsResult != PFS_SUCCESS) {
        return sPfsResult | PFS_ERROR_MAGIC;
    }
    return sPfsSlot;
}

/**
 * Prepares parameters for searching an existing Controller Pak file.
 *
 * The actual search is carried out by `ContPak_FindFile`; this function stores
 * the game and extension names.
 *
 * @param gameName Pointer to the game name.
 * @param extName Pointer to the extension name.
 * @return     0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileFindParams(u8* gameName, u8* extName) {
    if (gCurrentPakOperationFlags & PAK_BUSY) {
        return -1;
    }
    if (gCurrentPakPfsFlags & PFS_BUSY) {
        return -1;
    }
    sGameName = gameName;
    sExtname = extName;
    gCurrentPakOperationFlags |= FLAGS_PAK_FIND_FILE;
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
    gCurrentPakOperationFlags &= ~FLAGS_PAK_FIND_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_FIND_FILE;
    if (ContPak_UpdateFilesState() < 0) {
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
 * @return If a matching file was found, returns a slot index otherwise -1 if the PFS subsystem is busy or in an error
 * state.
 */
s32 ContPak_GetFindFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_PAK_FIND_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_FIND_FILE) {
        return -1;
    }
    if (sPfsResult != PFS_SUCCESS) {
        return sPfsResult | PFS_ERROR_MAGIC;
    }
    return sPfsSlot;
}

/**
 * Sets up parameters for writing to a Controller Pak file.
 *
 * The actual write is performed by `ContPak_WriteFile`; this function sets the file
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
    if (gCurrentPakOperationFlags & PAK_BUSY) {
        return -1;
    }
    if (gCurrentPakPfsFlags & PFS_BUSY) {
        return -1;
    }
    sPfsSlot = slot;
    sFileOffset = offset;
    sFileSize = size;
    sFileData = buf;
    gCurrentPakOperationFlags |= FLAGS_PAK_WRITE_FILE;
    return 0;
}

/**
 * Performs the actual write to a Controller Pak file.
 *
 * This function updates the Controller Pak files state, and then calls to
 * `osPfsReadWriteFile` in write mode and stores the return code in
 * `sPfsResult`.
 *
 * @return 0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_WriteFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_PAK_WRITE_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_WRITE_FILE;
    if (ContPak_UpdateFilesState() < 0) {
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
 * @return 0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_GetWriteFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_PAK_WRITE_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_WRITE_FILE) {
        return -1;
    }
    if (sPfsResult != PFS_SUCCESS) {
        return sPfsResult | PFS_ERROR_MAGIC;
    }
    return 0;
}

/**
 * Sets up parameters for reading from a Controller Pak file.
 *
 * The actual read is performed by `ContPak_ReadFile`; this function sets the file
 * slot, offset, size and buffer pointer.
 *
 * @param slot   File slot to read from.
 * @param offset Byte offset within the file.
 * @param size   Number of bytes to read.
 * @param buf    Destination buffer.
 * @return       0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_SetFileReadParams(s32 slot, s32 offset, s32 size, u8* buf) {
    if (gCurrentPakOperationFlags & PAK_BUSY) {
        return -1;
    }
    if (gCurrentPakPfsFlags & PFS_BUSY) {
        return -1;
    }
    sPfsSlot = slot;
    sFileOffset = offset;
    sFileSize = size;
    sFileData = buf;
    gCurrentPakOperationFlags |= FLAGS_PAK_READ_FILE;
    return 0;
}

/**
 * Performs the actual read from a Controller Pak file.
 *
 * This function first refreshes the directory information, then calls
 * `osPfsReadWriteFile` in read mode and stores the libultra return code in
 * `sPfsResult`.
 *
 * @return 0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_ReadFile(void) {
    gCurrentPakOperationFlags &= ~FLAGS_PAK_READ_FILE;
    gCurrentPakPfsFlags |= FLAGS_PFS_READ_FILE;
    if (ContPak_UpdateFilesState() < 0) {
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
 * @return 0 on success, -1 if the PFS subsystem is busy or in an error state.
 */
s32 ContPak_GetReadFileResult(void) {
    if (gCurrentPakOperationFlags & FLAGS_PAK_READ_FILE) {
        return -1;
    }
    if (gCurrentPakPfsFlags & FLAGS_PFS_READ_FILE) {
        return -1;
    }
    if (sPfsResult != PFS_SUCCESS) {
        return sPfsResult | PFS_ERROR_MAGIC;
    }
    return 0;
}
