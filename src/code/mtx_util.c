#include "common.h"

#ifdef __GNUC__
// Because of those ugly assignments we will have to use this to avoid gcc always complaining about them..
#pragma GCC diagnostic ignored "-Wsequence-point"
#endif


extern MtxF sMatrixStack[];          // Matrix stack
extern s32 sCurrentMatrixStackDepth; // Stack size
extern MtxF D_80180CF0[1];

void MtxUtil__MtxToMtxF(MtxF* dst, Mtx* src);
void MtxUtil__MtxFToMtx(MtxF* src, Mtx* dst);

// Helper function to print a matrix
#ifdef ISPRINT
void MtxUtil_PrintMtxF(const MtxF* mtx) {
    int r, c;

    if (mtx == NULL) {
        osSyncPrintf("MtxF: NULL\n");
        return;
    }

    osSyncPrintf("MtxF @ %p\n", mtx);
    for (r = 0; r < 4; r++) {
        osSyncPrintf("[ %8.4f %8.4f %8.4f %8.4f ]\n", mtx->mf[r][0], mtx->mf[r][1], mtx->mf[r][2], mtx->mf[r][3]);
    }
}
#endif

/*
 * @brief Initialize matrix stack
 *
 */
void MtxUtil_InitStack(void) {
    s32 size; // Matrix size
    f32* ptr; // Matrix ptr

    gCurrentMatrixStackPtr = sMatrixStack;
    sCurrentMatrixStackDepth = STACK_DEPTH;
    ptr = (f32*) gCurrentMatrixStackPtr;

    // Set identity matrix
    for (size = 16; size > 0; size--) {
        *ptr++ = 0.0f;
    }
    gCurrentMatrixStackPtr->mf[0][0] = gCurrentMatrixStackPtr->mf[1][1] = gCurrentMatrixStackPtr->mf[2][2] =
        gCurrentMatrixStackPtr->mf[3][3] = 1.0f;
}

/*
 * @brief Copies the current matrix to next stack level
 *
 * @return -1 if the stack is full otherwise the stack current depth index
 */
s32 MtxUtil_PushCopy(void) {
    s32 size;
    f32* sourceMatrix;
    f32* destMatrix;

    if (sCurrentMatrixStackDepth <= 0) {
        return -1;
    }
    sourceMatrix = (f32*) gCurrentMatrixStackPtr;
    gCurrentMatrixStackPtr++;
    destMatrix = (f32*) gCurrentMatrixStackPtr;
    for (size = 16; size > 0; size--) {
        *destMatrix++ = *sourceMatrix++;
    }
    sCurrentMatrixStackDepth--;
    return STACK_DEPTH - sCurrentMatrixStackDepth;
}

/*
 * @brief Pushes an identity matrix to the stack
 *
 * @return -1 if the stack is busy otherwise the stack depth index
 */
s32 MtxUtil_PushIdentity(void) {
    s32 size;
    f32* ptr;

    if (sCurrentMatrixStackDepth <= 0) {
        return -1;
    }
    gCurrentMatrixStackPtr++; // Advance matrix stack
    ptr = (f32*) gCurrentMatrixStackPtr;
    for (size = 16; size > 0; size--) {
        *ptr++ = 0.0f;
    }
    gCurrentMatrixStackPtr->mf[0][0] = gCurrentMatrixStackPtr->mf[1][1] = gCurrentMatrixStackPtr->mf[2][2] =
        gCurrentMatrixStackPtr->mf[3][3] = 1.0f;
    sCurrentMatrixStackDepth--;
    return STACK_DEPTH - sCurrentMatrixStackDepth;
}

/*
 * @brief Sets an identity matrix
 *
 * @param mtxF Matrix to identity
 *
 * @note If mtxF is null the function will identity the current matrix stack ptr
 *
 */
void MtxUtil_Identity(MtxF* mtxF) {
    s32 size;
    f32* sourceMatrix;
    MtxF* identityMatrix;

    sourceMatrix = (f32*) mtxF;
    if (mtxF == NULL) {
        sourceMatrix = (f32*) gCurrentMatrixStackPtr;
    }
    identityMatrix = (MtxF*) sourceMatrix;
    for (size = 16; size > 0; size--) {
        *sourceMatrix++ = 0.0f;
    }
    identityMatrix->mf[0][0] = identityMatrix->mf[1][1] = identityMatrix->mf[2][2] = identityMatrix->mf[3][3] = 1.0f;
}

/*
 * @brief Zeros translation row of a given matrix
 *
 * @param mtxF Matrix to zero the translation row
 * 
 * @note If mtxF is null the function will zero the matrix from gCurrentMatrixStackPtr
 */
void MtxUtil_ClearTranslation(MtxF* mtxF) {
    UNUSED s32 pad;
    MtxF* destMatrix;

    if (mtxF == NULL) {
        destMatrix = gCurrentMatrixStackPtr;
    } else {
        destMatrix = mtxF;
    }
    destMatrix->mf[3][0] = destMatrix->mf[3][1] = destMatrix->mf[3][2] = 0.0f;
    destMatrix->mf[3][3] = 1.0f;
}

/*
 * @brief Identity the first two rows used for rotation
 *
 * @param mtxF Matrix to identity the rows
 *
 * @note If mtxF is null the function will do this process with gCurrentMatrixStackPtr
 */
void MtxUtil_ClearRotation(MtxF* mtxF) {
    s32 size;
    f32* sourceMatrix;
    MtxF* destMatrix;

    sourceMatrix = (f32*) mtxF;
    if (mtxF == NULL) {
        sourceMatrix = (f32*) gCurrentMatrixStackPtr;
    }
    destMatrix = (MtxF*) sourceMatrix;
    for (size = 12; size > 0; size--) {
        *sourceMatrix++ = 0.0f;
    }
    destMatrix->mf[0][0] = destMatrix->mf[1][1] = destMatrix->mf[2][2] = 1.0f;
}

/*
* @brief Pop's the matrix stack by restoring the previous matrix
*
* @return -1 if already at base otherwise 0
*/
s32 MtxUtil_Pop(void) {
    if (sCurrentMatrixStackDepth == 20) {
        return -1;
    }
    sCurrentMatrixStackDepth++;
    gCurrentMatrixStackPtr--;
    return 0;
}

/*
* @brief Copies the matrix from gCurrentMatrixStackPtr (current matrix stack pointer)
*
* @param mtxF Dest matrix to copy from gCurrentMatrixStackPtr
*
*/
void MtxUtil_CopyCurrent(MtxF* mtxF) {
    s32 size;
    f32* sourceMatrix;
    f32* destMatrix;

    sourceMatrix = (f32*) gCurrentMatrixStackPtr;
    destMatrix = (f32*) mtxF;

    for (size = 16; size > 0; size--) {
        *destMatrix++ = *sourceMatrix++;
    }
}

/*
* @brief Updates the matrix of gCurrentMatrixStackPtr
*
* @param mtxF Matrix to copy to gCurrentMatrixStackPtr
*
*/
void MtxUtil_SetCurrent(MtxF* mtxF) {
    s32 size;
    f32* sourceMatrix;
    f32* destMatrix;

    sourceMatrix = (f32*) mtxF;
    destMatrix = (f32*) gCurrentMatrixStackPtr;

    for (size = 16; size > 0; size--) {
        *destMatrix++ = *sourceMatrix++;
    }
}

void func_800C1B64(MtxF* arg0) {
    MtxF* sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    if (arg0 == NULL) {
        sp2C = gCurrentMatrixStackPtr;
    } else {
        sp2C = arg0;
    }

    sp28 = sp2C->mf[3][0];
    sp24 = sp2C->mf[3][1];
    sp20 = sp2C->mf[3][2];

    sp2C->mf[3][0] = -(sp28 * sp2C->mf[0][0] + sp24 * (sp1C = sp2C->mf[0][1]) + sp20 * (sp18 = sp2C->mf[0][2]));
    sp2C->mf[3][1] = -(sp28 * (sp14 = sp2C->mf[1][0]) + sp24 * sp2C->mf[1][1] + sp20 * (sp10 = sp2C->mf[1][2]));
    sp2C->mf[3][2] = -(sp28 * (spC = sp2C->mf[2][0]) + sp24 * (sp8 = sp2C->mf[2][1]) + sp20 * sp2C->mf[2][2]);

    sp2C->mf[0][1] = sp14;
    sp2C->mf[1][0] = sp1C;
    sp2C->mf[1][2] = sp8;
    sp2C->mf[2][1] = sp10;
    sp2C->mf[0][2] = spC;
    sp2C->mf[2][0] = sp18;
}

UNUSED void func_800C1D0C(Mtx* arg0) {
    MtxF sp18;

    MtxUtil__MtxToMtxF(&sp18, arg0);
    func_800C1D44(&sp18);
}

void func_800C1D44(MtxF* arg0) {
    s32 i;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 m00;
    f32 m01;
    f32 m02;
    f32 m03;
    f32 m10;
    f32 m11;
    f32 m12;
    f32 m13;
    f32 m20;
    f32 m21;
    f32 m22;
    f32 m23;
    f32* spC;
    f32* sp8;

    spC = (f32*) gCurrentMatrixStackPtr;
    sp8 = (f32*) D_80180CF0;
    for (i = 0; i < 4; i++) {
        *sp8++ = *spC++;
        *sp8++ = *spC++;
        *sp8++ = *spC++;
        spC++;
        sp8++;
    }

    spC = (f32*) arg0;
    m00 = spC[0];
    m01 = spC[1];
    m02 = spC[2];
    m03 = spC[4];
    m10 = spC[5];
    m11 = spC[6];
    m12 = spC[8];
    m13 = spC[9];
    m20 = spC[10];
    m21 = spC[12];
    m22 = spC[13];
    m23 = spC[14];
    spC = (f32*) gCurrentMatrixStackPtr;
    sp8 = (f32*) D_80180CF0;

    for (i = 3; i > 0; i--) {
        spC[0] = ((sp48 = sp8[0]) * m00) + ((sp44 = sp8[4]) * m01) + ((sp40 = sp8[8]) * m02);
        spC[4] = (sp48 * m03) + (sp44 * m10) + (sp40 * m11);
        spC[8] = (sp48 * m12) + (sp44 * m13) + (sp40 * m20);
        spC[12] = sp8[12] + ((sp48 * m21) + (sp44 * m22) + (sp40 * m23)), spC++, sp8++; // wtf
    }
}

void func_800C2070(MtxF* arg0) {
    s32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32* spC;
    f32* sp8;

    sp3C = (spC = &gCurrentMatrixStackPtr->mf[0][0])[0];
    sp38 = spC[1];
    sp34 = spC[2];
    sp30 = spC[4];
    sp2C = spC[5];
    sp28 = spC[6];
    sp24 = spC[8];
    sp20 = spC[9];
    sp1C = spC[10];
    sp18 = spC[12];
    sp14 = spC[13];
    sp10 = spC[14];
    spC = (f32*) arg0;
    sp8 = (f32*) (gCurrentMatrixStackPtr - 1);
    for (sp4C = 0; sp4C < 3; sp4C++) {
        spC[0] = ((sp48 = sp8[0]) * sp3C) + ((sp44 = sp8[4]) * sp38) + ((sp40 = sp8[8]) * sp34);
        spC[4] = (sp48 * sp30) + (sp44 * sp2C) + (sp40 * sp28);
        spC[8] = (sp48 * sp24) + (sp44 * sp20) + (sp40 * sp1C);
        spC[12] = sp8[12] + ((sp48 * sp18) + (sp44 * sp14) + (sp40 * sp10)), *spC++, *sp8++; // wtf
    }

    spC[0] = spC[4] = spC[8] = 0.0f;
    spC[12] = 1.0f;
}

/*
* @brief Translates the axes from gCurrentMatrixStackPtr translation row
* 
* @param x X axis
*
* @param y Y axis
*
* @param z Z axis
*/
void MtxUtil_TranslateLocal(f32 x, f32 y, f32 z) {
    f32* row;
    MtxF* matrixStackPtr;

    row = (f32*) &(matrixStackPtr = gCurrentMatrixStackPtr)->mf[3][0]; // why?
    row[0] += (matrixStackPtr->mf[0][0] * x) + (matrixStackPtr->mf[1][0] * y) + (matrixStackPtr->mf[2][0] * z);
    row[1] += (matrixStackPtr->mf[0][1] * x) + (matrixStackPtr->mf[1][1] * y) + (matrixStackPtr->mf[2][1] * z);
    row[2] += (matrixStackPtr->mf[0][2] * x) + (matrixStackPtr->mf[1][2] * y) + (matrixStackPtr->mf[2][2] * z);
}

/*
* @brief Rotates the current stack matrix around X axis
*
* @param deg Degrees to rotate the matrix around the X axis
*/
void MtxUtil_RotateX(f32 deg) {
    f32 mf00;
    f32 col;
    f32 sinf;
    f32 negSinf;
    f32 cosf;
    f32* sp30;
    f32* sp2C;
    f32* sp28;
    f32* sp24;

    MtxUtil_CopyCurrent(D_80180CF0);
    cosf = MathUtil_Cosf(deg * DEG_TO_RAD);
    sinf = MathUtil_Sinf(deg * DEG_TO_RAD);
    negSinf = -sinf;
    sp24 = &(sp28 = D_80180CF0->mf[1])[4];
    sp2C = &(sp30 = gCurrentMatrixStackPtr->mf[1])[4];
    sp30[0] = ((mf00 = sp28[0]) * cosf) + ((col = sp24[0]) * sinf);
    sp2C[0] = (mf00 * negSinf) + (col * cosf);
    sp30[1] = ((mf00 = sp28[1]) * cosf) + ((col = sp24[1]) * sinf);
    sp2C[1] = (f32) ((mf00 * negSinf) + (col * cosf));
    sp30[2] = ((mf00 = sp28[2]) * cosf) + ((col = sp24[2]) * sinf);
    sp2C[2] = (f32) ((mf00 * negSinf) + (col * cosf));
}

/*
* @brief Rotates the current stack matrix around Y axis
*
* @param deg Degrees to rotate the matrix around the Y axis
*/
void MtxUtil_RotateY(f32 deg) {
    f32 mf00;
    f32 col;
    f32 sinf;
    f32 negSinf;
    f32 cosf;
    MtxF* sp30;
    f32* sp2C;
    MtxF* sp28;
    f32* sp24;

    MtxUtil_CopyCurrent(D_80180CF0);
    cosf = MathUtil_Cosf(deg * DEG_TO_RAD);
    sinf = MathUtil_Sinf(deg * DEG_TO_RAD);
    negSinf = -sinf;
    sp24 = &(sp28 = D_80180CF0)->mf[2][0];
    sp2C = &(sp30 = gCurrentMatrixStackPtr)->mf[2][0];

    sp30->mf[0][0] = ((mf00 = sp28->mf[0][0]) * cosf) + ((col = sp24[0]) * negSinf);
    sp2C[0] = (mf00 * sinf) + (col * cosf);
    sp30->mf[0][1] = ((mf00 = sp28->mf[0][1]) * cosf) + ((col = sp24[1]) * negSinf);
    sp2C[1] = (f32) ((mf00 * sinf) + (col * cosf));
    sp30->mf[0][2] = ((mf00 = sp28->mf[0][2]) * cosf) + ((col = sp24[2]) * negSinf);
    sp2C[2] = (f32) ((mf00 * sinf) + (col * cosf));
}

/*
* @brief Rotates the current stack matrix around Z axis
*
* @param deg Degrees to rotate the matrix around the Z axis
*/
void MtxUtil_RotateZ(f32 deg) {
    f32 mf00;
    f32 col;
    f32 sinf;
    f32 negSinf;
    f32 cosf;
    MtxF* sp30;
    f32* sp2C;
    MtxF* sp28;
    f32* sp24;

    MtxUtil_CopyCurrent(D_80180CF0);
    cosf = MathUtil_Cosf(deg * DEG_TO_RAD);
    sinf = MathUtil_Sinf(deg * DEG_TO_RAD);
    negSinf = -sinf;
    sp24 = &(sp28 = D_80180CF0)->mf[1][0];
    sp2C = &(sp30 = gCurrentMatrixStackPtr)->mf[1][0];
    sp30->mf[0][0] = ((mf00 = sp28->mf[0][0]) * cosf) + ((col = sp24[0]) * sinf);
    sp2C[0] = (mf00 * negSinf) + (col * cosf);
    sp30->mf[0][1] = ((mf00 = sp28->mf[0][1]) * cosf) + ((col = sp24[1]) * sinf);
    sp2C[1] = (f32) ((mf00 * negSinf) + (col * cosf));
    sp30->mf[0][2] = ((mf00 = sp28->mf[0][2]) * cosf) + ((col = sp24[2]) * sinf);
    sp2C[2] = (f32) ((mf00 * negSinf) + (col * cosf));
}

/*
* @brief Scale current stack matrix axes independently
*
* @param sx X axis to scale
*
* @param sy Y axis to scale
*
* @param sz Z axis to scale
*
*/
void MtxUtil_ScaleAxes(f32 sx, f32 sy, f32 sz) {
    f32* col1;
    f32* col2;
    f32* col3;

    col3 = &(col2 = (&(col1 = (f32*) gCurrentMatrixStackPtr->mf)[4]))[4];
    *col1++ *= sx;
    *col2++ *= sy;
    *col3++ *= sz;
    *col1++ *= sx;
    *col2++ *= sy;
    *col3++ *= sz;
    *col1++ *= sx;
    *col2++ *= sy;
    *col3++ *= sz;
}

/*
* @brief Gets the current matrix stack ptr in Mtx (fixed format)
*
* @param mtxF Matrix in fixed format get the current stack matrix
*
*/
void MtxUtil_GetCurrentFromMtxF(Mtx* mtx) {
    MtxUtil__MtxFToMtx(gCurrentMatrixStackPtr, mtx);
}

/*
* @brief Sets the current stack matrix 
*
* @param mtxF Matrix in fixed format to update the current stack matrix
*
*/
void MtxUtil_SetCurrentFromMtx(Mtx* mtx) {
    MtxUtil__MtxToMtxF(gCurrentMatrixStackPtr, mtx);
}

/*
* @brief Copies a matrix
*
* @param dst Destiny matrix
*
* @param src Source matrix
*
*/
void MtxUtil_Copy(MtxF* dst, MtxF* src) {
    s32 i;
    f32* sourceMatrix;
    f32* destMatrix;

    /* @bug: Null comparission with an uninitiliazed variable */
    if (sourceMatrix == NULL) {
        sourceMatrix = (f32*) gCurrentMatrixStackPtr;
    } else {
        sourceMatrix = (f32*) src;
    }
    destMatrix = (f32*) dst;
    for (i = 0; i < 16; i++) {
        *destMatrix++ = *sourceMatrix++;
    }
}

UNUSED void MtxUtil_CopyMtxFTranslationRow(MtxF* dst, MtxF* src) {
    if (src == NULL) {
        dst->mf[3][0] = gCurrentMatrixStackPtr->mf[3][0];
        dst->mf[3][1] = gCurrentMatrixStackPtr->mf[3][1];
        dst->mf[3][2] = gCurrentMatrixStackPtr->mf[3][2];
        dst->mf[3][3] = gCurrentMatrixStackPtr->mf[3][3];
    } else {
        dst->mf[3][0] = src->mf[3][0];
        dst->mf[3][1] = src->mf[3][1];
        dst->mf[3][2] = src->mf[3][2];
        dst->mf[3][3] = src->mf[3][3];
    }
}


/*
* @brief Copies the orientation rows of a matrix
*
* @param dst Destiny matrix
*
* @param src Source matrix
*
*/
void MtxUtil_CopyOrientation(MtxF* dst, MtxF* src) {
    s32 size;
    f32* sourceMatrix;
    f32* destMatrix;

    /* @bug: Null comparission with an uninitiliazed variable */
    if (sourceMatrix == NULL) {
        sourceMatrix = (f32*) gCurrentMatrixStackPtr;
    } else {
        sourceMatrix = (f32*) src;
    }
    destMatrix = (f32*) dst;
    for (size = 0; size < 12; size++) {
        *destMatrix++ = *sourceMatrix++;
    }
}

/*
* @brief Converts a mtx to mtxF
*
* @param src Matrix to convert
*
* @param dst Matrix to store the result of the conversion
*
*/
void MtxUtil_MtxToMtxF(Mtx* src, MtxF* dst) {
    if (dst == NULL) {
        MtxUtil__MtxToMtxF(gCurrentMatrixStackPtr, src);
    } else {
        MtxUtil__MtxToMtxF(dst, src);
    }
}

/*
* @brief Converts a mtxF to mtx
*
* @param src Matrix to convert
*
* @param dst Matrix to store the result of the conversion
*
*/
void MtxUtil_MtxFToMtx(MtxF* src, Mtx* dest) {
    if (src == NULL) {
        MtxUtil__MtxFToMtx(gCurrentMatrixStackPtr, dest);
    } else {
        MtxUtil__MtxFToMtx(src, dest);
    }
}

void MtxUtil__MtxFToMtx(MtxF* src, Mtx* dst) {
    s32 row;
    s32 colPair;
    s32 floatIndex;
    s32 intPart;  // Integer part
    s32 fracPart; // Fractional part
    s32* intPlanePtr;
    s32* fracPlanePtr;
    f32* srcFloatMtxPtr;

    intPlanePtr = &dst->m[0][0];
    fracPlanePtr = &dst->m[2][0];
    srcFloatMtxPtr = (float*) src->mf;

    for (row = 0; row < 4; row++) {
        for (colPair = 0; colPair < 2; colPair++) {
            *intPlanePtr++ =
                ((intPart = (s32) (srcFloatMtxPtr[(floatIndex = (row * 4) + (colPair * 2))] * 65536.0f)) & 0xFFFF0000) |
                (((fracPart = (s32) (srcFloatMtxPtr[floatIndex + 1] * 65536.0f)) >> 0x10) & 0xFFFF);

            *fracPlanePtr++ = ((intPart << 0x10) & 0xFFFF0000) | (fracPart & 0xFFFF);
        }
    }
}

void MtxUtil__MtxToMtxF(MtxF* dst, Mtx* src) {
    s16 row;
    s16 colPair;
    s16 dstIndex;
    s32 fixedValueHi;
    s32 fixedValueLo;
    u32* intPartPtr;
    u32* fracPartPtr;
    u32 intWord;
    u32 fracWord;
    f32* dstFloatMtx;

    intPartPtr = (u32*) &src->m[0][0];  // integer plane
    fracPartPtr = (u32*) &src->m[2][0]; // fractional plane
    dstFloatMtx = (f32*) dst->mf;

    for (row = 0; row < 4; row++) {
        for (colPair = 0; colPair < 2; colPair++) {

            fixedValueHi = ((intWord = *intPartPtr++) & 0xFFFF0000) | (((fracWord = *fracPartPtr++) >> 16) & 0xFFFF);

            fixedValueLo = ((intWord << 16) & 0xFFFF0000) | (fracWord & 0xFFFF);

            dstFloatMtx[(dstIndex = row * 4 + colPair * 2)] = FIXED_TO_FLOAT(fixedValueHi);
            dstFloatMtx[dstIndex + 1] = FIXED_TO_FLOAT(fixedValueLo);
        }
    }
}
