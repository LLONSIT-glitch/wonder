#ifndef PFS_H
#define PFS_H

#define PFS_SUCCESS 0


s32 SetFileWriteParams(s32 slot, s32 offset, s32 size, u8* buf);
s32 SetFileReadParams(s32 slot, s32 offset, s32 size, u8* buf);
s32 SetPfsCodes(u16 companyCode, u32 gameCode);
#endif /* PFS_H */

