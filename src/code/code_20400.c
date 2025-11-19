#include "common.h"

typedef u32 Sp54[4];

void func_8001F800(void) {
    s32 sp6C;
    s32 sp68;
    s32 pad[2];
    s32 s0;
    u16 sp5A;
    Sp54* sp54;
    UnkStruct_80099E2C* sp50;
    u8* sp4C;
    u8 sp4B;
    u16 sp48;

    if (D_801560F0->unk8 & D_80180E68) {
        switch (D_801825F0[5]) {                /* irregular */
        case 0:
            sp54 = (Sp54*) D_80182618->ptrs[0];
            sp54 += (sp6C = D_801825F0[1]);
            sp5A = sp54[0][0] >> 0x10;

            while (++sp6C, ++sp54, sp6C < D_801825F0[3] && ((sp54[0][0] >> 0x10) == sp5A)) {
            }
            
            if (sp6C < D_801825F0[3]) {
                D_801825F0[1] = sp6C;
            }
            break;
        case 1:
            if (++D_801825F0[1] >= D_801825F0[3]) {
                D_801825F0[1] = D_801825F0[3] - 1;
            }
            break;
        case 2:
            if (++D_801825F0[2] >= D_801825F0[4]) {
                D_801825F0[2] = D_801825F0[4] - 1;
            }
            if (D_801825F0[7] > 0) {
                sp4C = D_80182618->ptrs[1];
                sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
                func_800B3DBC((u8**)&sp50, &sp4C, D_801825F0[2]);
            }
            break;
        case 3:
            D_801825F0[0] ^= 4;
        }
    }
    if (D_801560F0->unk8 & D_80180E74) {
        switch (D_801825F0[5]) {                /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            sp54 = (Sp54*) D_80182618->ptrs[0];
            sp54 += (sp6C = D_801825F0[1]);
            sp5A = sp54[0][0] >> 0x10;

            while (--sp6C, --sp54, sp6C >= 0 && ((sp54[0][0] >> 0x10) == sp5A)) {
            }

            if (sp6C >= 0) {
                D_801825F0[1] = sp6C;
            }
            break;
        case 1:                                     /* switch 1 */
            if (--D_801825F0[1] < 0) {
                D_801825F0[1] = 0;
            }
            break;
        case 2:                                     /* switch 1 */
            if (--D_801825F0[2] < 0) {
                D_801825F0[2] = 0;
            }
            if (D_801825F0[7] > 0) {
                sp4C = D_80182618->ptrs[1];
                sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
                func_800B3DBC((u8**)&sp50, &sp4C, D_801825F0[2]);
            }
            break;
        case 3:                                     /* switch 1 */
            D_801825F0[0] ^= 4;
        }
    }
    if (D_801560F0->unk6 & D_80180EEC) {
        if (++D_801825F0[5] > 3) {
            D_801825F0[5] = 3;
        }
    }
    if (D_801560F0->unk6 & D_80180EC0) {
        if (--D_801825F0[5] < 0) {
            D_801825F0[5] = 0;
        }
    }
    if (D_801560F0->unk6 & D_80180FF4) {
        sp54 = (Sp54*) D_80182618->ptrs[0];
        sp54 += D_801825F0[1];
        sp5A = sp54[0][0] >> 0x10;
        sp4C = D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
        if (D_801825F0[0] & 4) {
            sp4B = 4;
        } else {
            sp4B = 0;
        }
        func_80022124();
        D_801825F0[7] = func_800B202C((u8**)&sp50, &sp4C, sp54[0][0], D_801825F0[2], sp50->unkCC, sp50->unkD0, (s32) sp4B);
        D_801825F0[0] |= 2;
        D_801825F0[0] |= 1;
    } else if (D_801825F0[0] & 2) {
        sp4C = D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
        sp6C = func_800B2748((u8**)&sp50, &sp4C);
        if (sp6C < 0) {
            D_801825F0[0] &= ~2;
            D_801825F0[0] &= ~1;
        } else {
            D_801825F0[7] = sp6C;
        }
    }
    if (D_801560F0->unk6 & D_8018101C) {
        D_801825F0[0] &= ~2;
        if (!(D_801825F0[0] & 1)) {
            sp54 = (Sp54*) D_80182618->ptrs[0];
            sp54 += D_801825F0[1];
            sp5A = sp54[0][0] >> 0x10;
            sp4C = D_80182618->ptrs[1];
            sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
            if (D_801825F0[0] & 4) {
                sp4B = 4;
            } else {
                sp4B = 0;
            }
            func_80022124();
            D_801825F0[7] = func_800B202C((u8**)&sp50, &sp4C, sp54[0][0], D_801825F0[2], sp50->unkCC, sp50->unkD0, (s32) sp4B);
            D_801825F0[0] |= 1;
        } else {
            sp4C = D_80182618->ptrs[1];
            sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
            sp6C = func_800B2748((u8**)&sp50, &sp4C);
            if (sp6C < 0) {
                D_801825F0[0] &= ~1;
            } else {
                D_801825F0[7] = sp6C;
            }
        }
    }
    if ((D_801560F0->unk6 & D_80180FF4) && (D_801560F0->unk6 & D_8018101C)) {
        for (sp68 = 0, sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2]; sp68 < 8; sp68++, sp50++) {
            sp50->unkD0 = 0.0f;
            sp50->unkCC = (f32) sp50->unkD0;
            sp50->unkF8 = 1.0f;
            sp50->unkF4 = (f32) sp50->unkF8;
        } 
    }
    if (D_801560F0->unk6 & D_801810F2) {
        sp4C = D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
        sp6C = func_800B2CBC((u8**)&sp50, &sp4C, 2);
        if (sp6C < 0) {
            D_801825F0[0] &= ~1;
        } else {
            D_801825F0[7] = sp6C;
        }
    }
    if (D_801825F0[0] & 1) {
        sp4C = D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2];
        sp48 = func_800B3434(&sp4C, 0);
        if (sp48 & 0x4000) {
            func_800B9000(func_800B32E4(&sp4C, 0));
        }
        if (sp48 & 0x8000) {
            func_800B9000(func_800B32E4(&sp4C, 1));
        }
        if (D_801560F0->unk4 & (D_801811AC | D_80181258 | D_8018126C | D_80181260)) {
            func_800B2CBC((u8**)&sp50, &sp4C, 6);
        } else {
            func_800B2CBC((u8**)&sp50, &sp4C, 5);
        }
    }

    for (sp68 = 0, sp50 = (UnkStruct_80099E2C*)D_80182618->ptrs[2]; sp68 < 8; sp68++, sp50++) {
        if (FABS(D_801560F0->unk10) >= 10.0) {
            sp50->unkCC += D_801560F0->unk10 * 0.1;
        }
  
        if (FABS(D_801560F0->unk14) >= 10.0) {
            sp50->unkD0 += D_801560F0->unk14 * 0.1;
        }
        if (D_801560F0->unk8 & D_80181042) {
            sp50->unkF8 = (sp50->unkF4 += 0.2);
        }
        if (D_801560F0->unk8 & D_80181038) {
            sp50->unkF8 = (sp50->unkF4 -= 0.2);
            if (sp50->unkF8 <= 0.0) {
                sp50->unkF8 = sp50->unkF4 = 0.009999999776f;
            }
        }
        if ((D_801560F0->unk6 & D_80181042) && (D_801560F0->unk6 & D_80181038)) {
            sp50->unkF8 = sp50->unkF4 = 1.0f;
        }
        if (sp68 >= D_801825F0[7]) {
            continue;
        } 
        
        func_800C1754();
        func_8009A14C((u8 *)sp50);
        func_800997D8(sp50);
        func_800C1A28();
    } 
}
