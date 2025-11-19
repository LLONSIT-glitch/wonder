#include "common.h"


s32 func_80020720(UnkStruct_80020720* arg0) {
    s32 pad;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    u8* gameName;
    u8* extName;
    s32 sp28;
    s32 sp24;

    func_8008EAA8(2, 1);
    func_8008ECE4("== %s ==", arg0->unk4);
    switch (D_801825E4) {                           /* switch 7; irregular */
    case 0:                                         /* switch 7 */
        D_801825F0[0] = 0;
        D_801825F0[1] = 0;
        D_801825F0[2] = -1;
        D_80182618->ptrs[0] = SysMem_HeapAlloc(0x12);
        D_80182618->ptrs[1] = SysMem_HeapAlloc(6);
        D_80182618->ptrs[2] = SysMem_HeapAlloc(0x1600);
        D_80182618->ptrs[3] = SysMem_HeapAlloc(0x1600);
        gameName = D_80182618->ptrs[0];
        extName = D_80182618->ptrs[1];
        
        for (sp40 = 0; sp40 < 0x11; sp40++) {
            gameName[sp40] = 0;
        } 
        gameName[0] = '-';
        gameName[1] = 0x1E;
        gameName[2] = ',';
        gameName[3] = '-';
        gameName[4] = 0x1F;
        gameName[5] = '"';
        gameName[6] = '%';
        gameName[7] = 0x1E;
      
        for (sp40 = 0; sp40 < 5; sp40++) {
            extName[sp40] = 0;
        } 
        
        for (sp40 = 0; sp40 < 0x1600; sp40++) {
            D_80182618->ptrs[2][sp40] = sp40 & 0xFF;
        } 
        break;
    case 1:                                         /* switch 7 */
        gameName = D_80182618->ptrs[0];
        extName = D_80182618->ptrs[1];
        func_8008EAA8(0, 4);
        if (D_8018129C & 1) {
            // Backup available in ROM
            func_8008ECE4("  ROM内Backup        あり\n");
        } else {
            // No backup in ROM
            func_8008ECE4("  ROM内Backup        なし\n");
        }
        if (D_8018129C & 2) {
            // Controller packs available remaining
            func_8008ECE4("  コントローラパック あり  残り %3d\n", D_80181638);
        } else {
            // Controller Pack: No
            func_8008ECE4("  コントローラパック なし          \n");
        }
        switch (D_801825F0[0]) {                 /* switch 1 */
        case 1:                                     /* switch 1 */
            sp40 = func_800AEA0C();
            if (sp40 >= 0x1001) {
                sp40 -= 0x1000;
                switch (sp40) {                     /* switch 2 */
                case 4:                             /* switch 2 */
                    func_8008ECE4("PFS ERR CONTRFAIL   \n");
                    break;
                case 5:                             /* switch 2 */
                    func_8008ECE4("Invalid parameter   \n");
                    break;
                case 9:                             /* switch 2 */
                    func_8008ECE4("File exist          \n");
                    if (gameName[8] == 0) {
                        gameName[8] = 0x1AU;
                    } else {
                        gameName[8]++;
                    }
                    break;
                case 1:                             /* switch 2 */
                    func_8008ECE4("PFS ERR NO PACK     \n");
                    break;
                case 2:                             /* switch 2 */
                    func_8008ECE4("PFS ERR NEW PACK    \n");
                    break;
                case 3:                             /* switch 2 */
                    func_8008ECE4("PFS ERR INCONSISTENT\n");
                    break;
                case 8:                             /* switch 2 */
                    func_8008ECE4("Pfs is full         \n");
                    break;
                case 7:                             /* switch 2 */
                    func_8008ECE4("Data full           \n");
                    break;
                default:                            /* switch 2 */
                    func_8008ECE4("Unknown error [%04x]\n", sp40);
                    break;
                }
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            } else if (sp40 != -1) {
                func_8008ECE4("Allocate OK [%2d]     \n", sp40);
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
                D_801825F0[2] = sp40;
            }
            break;
        case 2:                                     /* switch 1 */
            sp40 = func_800AEBF4();
            if (sp40 >= 0x1001) {
                sp40 -= 0x1000;
                switch (sp40) {                     /* switch 3 */
                case 4:                             /* switch 3 */
                    func_8008ECE4("PFS ERR CONTRFAIL   \n");
                    break;
                case 5:                             /* switch 3 */
                    func_8008ECE4("Invalid parameter   \n");
                    break;
                case 9:                             /* switch 3 */
                    func_8008ECE4("File exist          \n");
                    break;
                case 1:                             /* switch 3 */
                    func_8008ECE4("PFS ERR NO PACK     \n");
                    break;
                case 2:                             /* switch 3 */
                    func_8008ECE4("PFS ERR NEW PACK    \n");
                    break;
                case 3:                             /* switch 3 */
                    func_8008ECE4("PFS ERR INCONSISTENT\n");
                    break;
                case 8:                             /* switch 3 */
                    func_8008ECE4("Pfs is full         \n");
                    break;
                default:                            /* switch 3 */
                    func_8008ECE4("Unknown error [%04x]\n", sp40);
                    break;
                }
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            } else if (sp40 != -1) {
                func_8008ECE4("File find   [%2d]     \n", sp40);
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
                D_801825F0[2] = sp40;
            }
            break;
        case 3:                                     /* switch 1 */
            sp40 = func_800AEDE8();
            if (sp40 >= 0x1001) {
                sp40 -= 0x1000;
                switch (sp40) {                     /* switch 4 */
                case 4:                             /* switch 4 */
                    func_8008ECE4("PFS ERR CONTRFAIL   \n");
                    break;
                case 5:                             /* switch 4 */
                    func_8008ECE4("Invalid parameter   \n");
                    break;
                case 1:                             /* switch 4 */
                    func_8008ECE4("PFS ERR NO PACK     \n");
                    break;
                case 2:                             /* switch 4 */
                    func_8008ECE4("PFS ERR NEW PACK    \n");
                    break;
                case 3:                             /* switch 4 */
                    func_8008ECE4("PFS ERR INCONSISTENT\n");
                    break;
                case 6:                             /* switch 4 */
                    func_8008ECE4("PFS ERR BAD DATA    \n");
                    break;
                default:                            /* switch 4 */
                    func_8008ECE4("Unknown error [%04x]\n", sp40);
                    break;
                }
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            } else if (sp40 != -1) {
                func_8008ECE4("Write success [%2d]     \n", D_801825F0[2]);
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            }
            break;
        case 4:                                     /* switch 1 */
            sp40 = func_800AEFD4();
            if (sp40 >= 0x1001) {
                sp40 -= 0x1000;
                switch (sp40) {                     /* switch 5 */
                case 4:                             /* switch 5 */
                    func_8008ECE4("PFS ERR CONTRFAIL   \n");
                    break;
                case 5:                             /* switch 5 */
                    func_8008ECE4("Invalid parameter   \n");
                    break;
                case 1:                             /* switch 5 */
                    func_8008ECE4("PFS ERR NO PACK     \n");
                    break;
                case 2:                             /* switch 5 */
                    func_8008ECE4("PFS ERR NEW PACK    \n");
                    break;
                case 3:                             /* switch 5 */
                    func_8008ECE4("PFS ERR INCONSISTENT\n");
                    break;
                case 6:                             /* switch 5 */
                    func_8008ECE4("PFS ERR BAD DATA    \n");
                    break;
                default:                            /* switch 5 */
                    func_8008ECE4("Unknown error [%04x]\n", sp40);
                    break;
                }
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            } else if (sp40 != -1) {
                for (sp40 = 0; sp40 < 0x1600; sp40++) {
                    if (D_80182618->ptrs[2][sp40] != D_80182618->ptrs[3][sp40]) { 
                        break;
                    }
                }

                if (sp40 == 0x1600) {
                    func_8008ECE4("Load success [%2d]      \n", D_801825F0[2]);
                } else {
                    func_8008ECE4("Load data error [%2d]   \n", D_801825F0[2]);
                }
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            }
            break;
        case 5:                                     /* switch 1 */
            sp40 = func_800AE7FC();
            if (sp40 >= 0x1001) {
                sp40 -= 0x1000;
                switch (sp40) {                     /* switch 6 */
                case 4:                             /* switch 6 */
                    func_8008ECE4("PFS ERR CONTRFAIL   \n");
                    break;
                case 5:                             /* switch 6 */
                    func_8008ECE4("Invalid parameter   \n");
                    break;
                case 9:                             /* switch 6 */
                    func_8008ECE4("File exist          \n");
                    break;
                case 1:                             /* switch 6 */
                    func_8008ECE4("PFS ERR NO PACK     \n");
                    break;
                case 2:                             /* switch 6 */
                    func_8008ECE4("PFS ERR NEW PACK    \n");
                    break;
                case 3:                             /* switch 6 */
                    func_8008ECE4("PFS ERR INCONSISTENT\n");
                    break;
                case 8:                             /* switch 6 */
                    func_8008ECE4("Pfs is full         \n");
                    break;
                case 7:                             /* switch 6 */
                    func_8008ECE4("Data full           \n");
                    break;
                default:                            /* switch 6 */
                    func_8008ECE4("Unknown error [%04x]\n", sp40);
                    break;
                }
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
            } else if (sp40 != -1) {
                func_8008ECE4("Delete success [%2d]     \n", sp40);
                D_801825F0[1] = 0x3C;
                D_801825F0[0] = 0;
                D_801825F0[2] = -1;
            }
            break;
        default:                                    /* switch 1 */
            if (D_801560F0->unk6 & (u16) D_801810F2) {
                func_800AE348(1);
            }
            if ((D_801560F0->unk6 & D_80180FF4) && (func_800AE880(gameName, extName, 0x1600) == 0)) {
                D_801825F0[0] = 1;
            }
            if ((D_801560F0->unk6 & (u16) D_8018101C) && (func_800AEA98(gameName, extName) == 0)) {
                D_801825F0[0] = 2;
            }
            if ((D_801560F0->unk6 & (u16) D_80181258)) {
                if ((D_801825F0[2] != -1))  {
                    if ((SetFileWriteParams(D_801825F0[2], 0, 0x1600, D_80182618->ptrs[2]) == 0)) {
                        D_801825F0[0] = 3;
                    }
                }
            }
            if ((D_801560F0->unk6 & (u16) D_80181260) && (D_801825F0[2] != -1)) {
                for (sp40 = 0; sp40 < 0x1600; sp40++) {
                    D_80182618->ptrs[3][sp40] = D_80182618->ptrs[2][sp40] ^ 0xFF;
                } 
                if (SetFileReadParams(D_801825F0[2], 0, 0x1600, D_80182618->ptrs[3]) == 0) {
                    D_801825F0[0] = 4;
                }
            }
            if ((D_801560F0->unk6 & (u16) D_8018126C)) {
                if ((D_801825F0[2] != -1)) {
                    if ((func_800AE5F0(D_801825F0[2]) == 0)) {
                        D_801825F0[0] = 5;
                    }
                }
            }
            if (D_801825F0[1] == 0) {
                func_8008ECE4("                    \n");
            } else {
                D_801825F0[1] = (s32) ((f32) D_801825F0[1] - (1.0f * D_8018257C));
            }
            break;
        }
        break;
    }
    if (D_801560F0->unk6 & (u16) D_801811A4) {
        for (sp40 = 0; sp40 < 4; sp40++) {
            SysMem_Free(D_80182618->ptrs[sp40]);
        }
        return -1;
    }
    return 0;
}
