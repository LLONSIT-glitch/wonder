#ifndef MTX_UTIL_H
#define MTX_UTIL_H


#define STACK_DEPTH 20
#define FIXED_TO_FLOAT(x) ((x) / 65536.0f)
#define DEG_TO_RAD 0.0174532919999999987

extern MtxF* gCurrentMatrixStackPtr; // Matrix stack pointer

void MtxUtil_ClearRotation(MtxF* mtxF);
void MtxUtil_ClearTranslation(MtxF* mtxF);
void MtxUtil_Copy(MtxF* dst, MtxF* src);
void MtxUtil_CopyCurrent(MtxF* mtxF);
UNUSED void MtxUtil_CopyMtxFTranslationRow(MtxF* dst, MtxF* src);
void MtxUtil_CopyOrientation(MtxF* dst, MtxF* src);
void MtxUtil_GetCurrentFromMtxF(Mtx* mtx);
void MtxUtil_Identity(MtxF* mtxF);
void MtxUtil_InitStack(void);
void MtxUtil_MtxFToMtx(MtxF* src, Mtx* dest);
void MtxUtil_MtxToMtxF(Mtx* src, MtxF* dst);
s32 MtxUtil_Pop(void);
void MtxUtil_PrintMtxF(const MtxF* mtx);
s32 MtxUtil_PushCopy(void);
s32 MtxUtil_PushIdentity(void);
void MtxUtil_RotateX(f32 deg);
void MtxUtil_RotateY(f32 deg);
void MtxUtil_RotateZ(f32 deg);
void MtxUtil_ScaleAxes(f32 sx, f32 sy, f32 sz);
void MtxUtil_SetCurrent(MtxF* mtxF);
void MtxUtil_SetCurrentFromMtx(Mtx* mtx);
void MtxUtil_TranslateLocal(f32 x, f32 y, f32 z);
void MtxUtil__MtxFToMtx(MtxF* src, Mtx* dst);
void MtxUtil__MtxToMtxF(MtxF* dst, Mtx* src);
void func_800C1B64(MtxF* arg0);
UNUSED void func_800C1D0C(Mtx* arg0);
void func_800C1D44(MtxF* arg0);
void func_800C2070(MtxF* arg0);

#endif /* MTX_UTIL_H */
