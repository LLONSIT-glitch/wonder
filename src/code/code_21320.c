#include "common.h"

s32 func_80020720(DebugMenuInfo* arg0) {
    s32 pad;
    s32 contPakResult;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    u8* gameName;
    u8* extName;
    s32 sp28;
    s32 sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4("== %s ==", arg0->debugMenuTitle);
    switch (gDebugMenuState) { /* switch 7; irregular */
        case 0:                /* switch 7 */
            gSpriteObjCheckDebugMenuState[0] = 0;
            gSpriteObjCheckDebugMenuState[1] = 0;
            gSpriteObjCheckDebugMenuState[2] = -1;
            D_80182618->ptrs[0] = SysMem_HeapAlloc(18);
            D_80182618->ptrs[1] = SysMem_HeapAlloc(6);
            D_80182618->ptrs[2] = SysMem_HeapAlloc(0x1600);
            D_80182618->ptrs[3] = SysMem_HeapAlloc(0x1600);
            gameName = D_80182618->ptrs[0];
            extName = D_80182618->ptrs[1];

            for (contPakResult = 0; contPakResult < 0x11; contPakResult++) {
                gameName[contPakResult] = 0;
            }
            gameName[0] = '-';
            gameName[1] = 0x1E;
            gameName[2] = ',';
            gameName[3] = '-';
            gameName[4] = 0x1F;
            gameName[5] = '"';
            gameName[6] = '%';
            gameName[7] = 0x1E;

            for (contPakResult = 0; contPakResult < 5; contPakResult++) {
                extName[contPakResult] = 0;
            }

            for (contPakResult = 0; contPakResult < 0x1600; contPakResult++) {
                D_80182618->ptrs[2][contPakResult] = contPakResult & 0xFF;
            }
            break;
        case 1: /* switch 7 */
            gameName = D_80182618->ptrs[0];
            extName = D_80182618->ptrs[1];
            func_8008EAA8(0, 4);
            if (gCurrentPakPfsFlags & 1) {
                // Backup available in ROM
                func_8008ECE4("  ROM内Backup        あり\n");
            } else {
                // No backup in ROM
                func_8008ECE4("  ROM内Backup        なし\n");
            }
            if (gCurrentPakPfsFlags & 2) {
                // Controller packs available remaining
                func_8008ECE4("  コントローラパック あり  残り %3d\n", gPfsFreeSpace);
            } else {
                // Controller Pack: No
                func_8008ECE4("  コントローラパック なし          \n");
            }
            switch (gSpriteObjCheckDebugMenuState[0]) { /* switch 1 */
                case 1:                                 /* switch 1 */
                    contPakResult = ContPak_GetOpenFileResult();
                    if (contPakResult >= PFS_ERROR_MAGIC + 1) {
                        contPakResult -= PFS_ERROR_MAGIC;
                        switch (contPakResult) { /* switch 2 */
                            case 4:              /* switch 2 */
                                func_8008ECE4("PFS ERR CONTRFAIL   \n");
                                break;
                            case 5: /* switch 2 */
                                func_8008ECE4("Invalid parameter   \n");
                                break;
                            case 9: /* switch 2 */
                                func_8008ECE4("File exist          \n");
                                if (gameName[8] == 0) {
                                    gameName[8] = 0x1AU;
                                } else {
                                    gameName[8]++;
                                }
                                break;
                            case 1: /* switch 2 */
                                func_8008ECE4("PFS ERR NO PACK     \n");
                                break;
                            case 2: /* switch 2 */
                                func_8008ECE4("PFS ERR NEW PACK    \n");
                                break;
                            case 3: /* switch 2 */
                                func_8008ECE4("PFS ERR INCONSISTENT\n");
                                break;
                            case 8: /* switch 2 */
                                func_8008ECE4("Pfs is full         \n");
                                break;
                            case 7: /* switch 2 */
                                func_8008ECE4("Data full           \n");
                                break;
                            default: /* switch 2 */
                                func_8008ECE4("Unknown error [%04x]\n", contPakResult);
                                break;
                        }
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    } else if (contPakResult != -1) {
                        func_8008ECE4("Allocate OK [%2d]     \n", contPakResult);
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                        gSpriteObjCheckDebugMenuState[2] = contPakResult;
                    }
                    break;
                case 2: /* switch 1 */
                    contPakResult = ContPak_GetFindFileResult();
                    if (contPakResult >= PFS_ERROR_MAGIC + 1) {
                        contPakResult -= PFS_ERROR_MAGIC;
                        switch (contPakResult) { /* switch 3 */
                            case 4:              /* switch 3 */
                                func_8008ECE4("PFS ERR CONTRFAIL   \n");
                                break;
                            case 5: /* switch 3 */
                                func_8008ECE4("Invalid parameter   \n");
                                break;
                            case 9: /* switch 3 */
                                func_8008ECE4("File exist          \n");
                                break;
                            case 1: /* switch 3 */
                                func_8008ECE4("PFS ERR NO PACK     \n");
                                break;
                            case 2: /* switch 3 */
                                func_8008ECE4("PFS ERR NEW PACK    \n");
                                break;
                            case 3: /* switch 3 */
                                func_8008ECE4("PFS ERR INCONSISTENT\n");
                                break;
                            case 8: /* switch 3 */
                                func_8008ECE4("Pfs is full         \n");
                                break;
                            default: /* switch 3 */
                                func_8008ECE4("Unknown error [%04x]\n", contPakResult);
                                break;
                        }
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    } else if (contPakResult != -1) {
                        func_8008ECE4("File find   [%2d]     \n", contPakResult);
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                        gSpriteObjCheckDebugMenuState[2] = contPakResult;
                    }
                    break;
                case 3: /* switch 1 */
                    contPakResult = ContPak_GetWriteFileResult();
                    if (contPakResult >= PFS_ERROR_MAGIC + 1) {
                        contPakResult -= PFS_ERROR_MAGIC;
                        switch (contPakResult) { /* switch 4 */
                            case 4:              /* switch 4 */
                                func_8008ECE4("PFS ERR CONTRFAIL   \n");
                                break;
                            case 5: /* switch 4 */
                                func_8008ECE4("Invalid parameter   \n");
                                break;
                            case 1: /* switch 4 */
                                func_8008ECE4("PFS ERR NO PACK     \n");
                                break;
                            case 2: /* switch 4 */
                                func_8008ECE4("PFS ERR NEW PACK    \n");
                                break;
                            case 3: /* switch 4 */
                                func_8008ECE4("PFS ERR INCONSISTENT\n");
                                break;
                            case 6: /* switch 4 */
                                func_8008ECE4("PFS ERR BAD DATA    \n");
                                break;
                            default: /* switch 4 */
                                func_8008ECE4("Unknown error [%04x]\n", contPakResult);
                                break;
                        }
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    } else if (contPakResult != -1) {
                        func_8008ECE4("Write success [%2d]     \n", gSpriteObjCheckDebugMenuState[2]);
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    }
                    break;
                case 4: /* switch 1 */
                    contPakResult = ContPak_GetReadFileResult();
                    if (contPakResult >= PFS_ERROR_MAGIC + 1) {
                        contPakResult -= PFS_ERROR_MAGIC;
                        switch (contPakResult) { /* switch 5 */
                            case 4:              /* switch 5 */
                                func_8008ECE4("PFS ERR CONTRFAIL   \n");
                                break;
                            case 5: /* switch 5 */
                                func_8008ECE4("Invalid parameter   \n");
                                break;
                            case 1: /* switch 5 */
                                func_8008ECE4("PFS ERR NO PACK     \n");
                                break;
                            case 2: /* switch 5 */
                                func_8008ECE4("PFS ERR NEW PACK    \n");
                                break;
                            case 3: /* switch 5 */
                                func_8008ECE4("PFS ERR INCONSISTENT\n");
                                break;
                            case 6: /* switch 5 */
                                func_8008ECE4("PFS ERR BAD DATA    \n");
                                break;
                            default: /* switch 5 */
                                func_8008ECE4("Unknown error [%04x]\n", contPakResult);
                                break;
                        }
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    } else if (contPakResult != -1) {
                        for (contPakResult = 0; contPakResult < 0x1600; contPakResult++) {
                            if (D_80182618->ptrs[2][contPakResult] != D_80182618->ptrs[3][contPakResult]) {
                                break;
                            }
                        }

                        if (contPakResult == 0x1600) {
                            func_8008ECE4("Load success [%2d]      \n", gSpriteObjCheckDebugMenuState[2]);
                        } else {
                            func_8008ECE4("Load data error [%2d]   \n", gSpriteObjCheckDebugMenuState[2]);
                        }
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    }
                    break;
                case 5: /* switch 1 */
                    contPakResult = ContPak_GetDeleteFileResult();
                    if (contPakResult >= PFS_ERROR_MAGIC + 1) {
                        contPakResult -= PFS_ERROR_MAGIC;
                        switch (contPakResult) { /* switch 6 */
                            case 4:              /* switch 6 */
                                func_8008ECE4("PFS ERR CONTRFAIL   \n");
                                break;
                            case 5: /* switch 6 */
                                func_8008ECE4("Invalid parameter   \n");
                                break;
                            case 9: /* switch 6 */
                                func_8008ECE4("File exist          \n");
                                break;
                            case 1: /* switch 6 */
                                func_8008ECE4("PFS ERR NO PACK     \n");
                                break;
                            case 2: /* switch 6 */
                                func_8008ECE4("PFS ERR NEW PACK    \n");
                                break;
                            case 3: /* switch 6 */
                                func_8008ECE4("PFS ERR INCONSISTENT\n");
                                break;
                            case 8: /* switch 6 */
                                func_8008ECE4("Pfs is full         \n");
                                break;
                            case 7: /* switch 6 */
                                func_8008ECE4("Data full           \n");
                                break;
                            default: /* switch 6 */
                                func_8008ECE4("Unknown error [%04x]\n", contPakResult);
                                break;
                        }
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                    } else if (contPakResult != -1) {
                        func_8008ECE4("Delete success [%2d]     \n", contPakResult);
                        gSpriteObjCheckDebugMenuState[1] = 0x3C;
                        gSpriteObjCheckDebugMenuState[0] = 0;
                        gSpriteObjCheckDebugMenuState[2] = -1;
                    }
                    break;
                default: /* switch 1 */
                    if (gControllers->unk6 & (u16) gInputMask_Z) {
                        ContPak_SetPakInitializationAttempts(1);
                    }
                    if ((gControllers->unk6 & gInputMask_A) &&
                        (ContPak_SetOpenFileParams(gameName, extName, 0x1600) == 0)) {
                        gSpriteObjCheckDebugMenuState[0] = 1;
                    }
                    if ((gControllers->unk6 & (u16) gInputMask_B) &&
                        (ContPak_SetFileFindParams(gameName, extName) == 0)) {
                        gSpriteObjCheckDebugMenuState[0] = 2;
                    }
                    if ((gControllers->unk6 & (u16) gInputMask_CDown)) {
                        if ((gSpriteObjCheckDebugMenuState[2] != -1)) {
                            if ((ContPak_SetFileWriteParams(gSpriteObjCheckDebugMenuState[2], 0, 0x1600,
                                                            D_80182618->ptrs[2]) == 0)) {
                                gSpriteObjCheckDebugMenuState[0] = 3;
                            }
                        }
                    }
                    if ((gControllers->unk6 & (u16) gInputMask_CLeft) && (gSpriteObjCheckDebugMenuState[2] != -1)) {
                        for (contPakResult = 0; contPakResult < 0x1600; contPakResult++) {
                            D_80182618->ptrs[3][contPakResult] = D_80182618->ptrs[2][contPakResult] ^ 0xFF;
                        }
                        if (ContPak_SetFileReadParams(gSpriteObjCheckDebugMenuState[2], 0, 0x1600,
                                                      D_80182618->ptrs[3]) == 0) {
                            gSpriteObjCheckDebugMenuState[0] = 4;
                        }
                    }
                    if ((gControllers->unk6 & (u16) gInputMask_CRight)) {
                        if ((gSpriteObjCheckDebugMenuState[2] != -1)) {
                            if ((ContPak_SetFileDeleteParams(gSpriteObjCheckDebugMenuState[2]) == 0)) {
                                gSpriteObjCheckDebugMenuState[0] = 5;
                            }
                        }
                    }
                    if (gSpriteObjCheckDebugMenuState[1] == 0) {
                        func_8008ECE4("                    \n");
                    } else {
                        gSpriteObjCheckDebugMenuState[1] =
                            (s32) ((f32) gSpriteObjCheckDebugMenuState[1] - (1.0f * D_8018257C));
                    }
                    break;
            }
            break;
    }
    if (gControllers->unk6 & (u16) gInputMask_Start) {
        for (contPakResult = 0; contPakResult < 4; contPakResult++) {
            SysMem_Free(D_80182618->ptrs[contPakResult]);
        }
        return -1;
    }
    return 0;
}
