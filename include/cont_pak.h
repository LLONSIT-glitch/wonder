#ifndef PFS_H
#define PFS_H

// Controller Pak operation flags
#define FLAGS_PAK_UNKNOWN 0x8

#define FLAGS_PAK_INITILIZATION_FAILED 0x1
#define FLAGS_PAK_INITILIZATION_SUCCESS 0x4
#define FLAGS_PAK_DELETE_FILE 0x10
#define FLAGS_PAK_OPEN_FILE 0x20
#define FLAGS_PAK_READ_FILE 0x40
#define FLAGS_PAK_WRITE_FILE 0x80
#define FLAGS_PAK_FIND_FILE 0x100

#define FLAGS_PFS_DEL_FILE 0x20
#define FLAGS_PFS_OPEN_FILE 0x40
#define FLAGS_PFS_READ_FILE \
    0x80 /* Flags to indicate that the pfs operations that are being perfomed because of the read operation */
#define FLAGS_PFS_WRITE_FILE \
    0x100 /* Flags to indicate that the pfs operations that are being perfomed because of the read operation */
#define FLAGS_PFS_FIND_FILE 0x200

#define PFS_ERROR_MAGIC 0x1000

#define PAK_BUSY \
    (FLAGS_PAK_UNKNOWN + FLAGS_PAK_DELETE_FILE + FLAGS_PAK_READ_FILE + FLAGS_PAK_WRITE_FILE + FLAGS_PAK_FIND_FILE)
#define PFS_BUSY \
    (FLAGS_PFS_DEL_FILE | FLAGS_PFS_FIND_FILE | FLAGS_PFS_OPEN_FILE | FLAGS_PFS_READ_FILE | FLAGS_PFS_WRITE_FILE)

#define PFS_SUCCESS 0

#define SLOT_FOUND 0
#define SLOT_NOT_FOUND 5
#define FILE_FOUND 9

s32 ContPak_DeleteFile(void);
s32 ContPak_FindFile(void);
s32 ContPak_FindPfsSlot(UNUSED OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* slotFound);
s32 ContPak_GetAvailableSlots(void);
s32 ContPak_GetDeleteFileResult(void);
s32 ContPak_GetFindFileResult(void);
s32 ContPak_GetOpenFileResult(void);
s32 ContPak_GetPakInitilizationResult(void);
s32 ContPak_GetPfsFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo);
s32 ContPak_GetReadFileResult(void);
s32 ContPak_GetWriteFileResult(void);
s32 ContPak_InitializePak(OSMesgQueue* contMesgQueue);
s32 ContPak_OpenFile(void);
s32 ContPak_ReadFile(void);
s32 ContPak_SetFileDeleteParams(s32 fileSlot);
s32 ContPak_SetFileFindParams(u8* gameName, u8* extName);
s32 ContPak_SetFileReadParams(s32 slot, s32 offset, s32 size, u8* buf);
s32 ContPak_SetFileWriteParams(s32 slot, s32 offset, s32 size, u8* buf);
s32 ContPak_SetOpenFileParams(u8* gameName, u8* extName, s32 fileSize);
void ContPak_SetPakInitializationAttempts(s32 attempts);
s32 ContPak_SetPfsCodes(u16 companyCode, u32 gameCode);
s32 ContPak_UpdateFilesState(void);
s32 ContPak_WriteFile(void);
#endif /* PFS_H */

