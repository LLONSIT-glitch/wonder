#ifndef PFS_H
#define PFS_H

#define PFS_SUCCESS 0


s32 ContPak_SetFileWriteParams(s32 slot, s32 offset, s32 size, u8* buf);
s32 ContPak_SetFileReadParams(s32 slot, s32 offset, s32 size, u8* buf);
s32 ContPak_SetPfsCodes(u16 companyCode, u32 gameCode);
s32 ContPak_GetDeleteFileResult(void);
s32 ContPak_FindFile(void);
#endif /* PFS_H */

