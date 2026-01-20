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
    UnkStruct_800B23C4* sp4C;
    u8 sp4B;
    u16 sp48;

    if (gControllers->unk8 & gInputMask_DPadUp) {
        switch (D_801825F0[5]) { /* irregular */
            case 0:
                sp54 = (Sp54*) D_80182618->ptrs[0];
                sp54 += (sp6C = D_801825F0[1]);
                sp5A = sp54[0][0] >> 0x10;

                while (++sp6C, ++sp54, sp6C < D_801825F0[3] && ((sp54[0][0] >> 0x10) == sp5A)) {}

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
                    sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
                    sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
                    func_800B3DBC(&sp50, &sp4C, D_801825F0[2]);
                }
                break;
            case 3:
                D_801825F0[0] ^= 4;
        }
    }
    if (gControllers->unk8 & gInputMask_DPadDown) {
        switch (D_801825F0[5]) { /* switch 1; irregular */
            case 0:              /* switch 1 */
                sp54 = (Sp54*) D_80182618->ptrs[0];
                sp54 += (sp6C = D_801825F0[1]);
                sp5A = sp54[0][0] >> 0x10;

                while (--sp6C, --sp54, sp6C >= 0 && ((sp54[0][0] >> 0x10) == sp5A)) {}

                if (sp6C >= 0) {
                    D_801825F0[1] = sp6C;
                }
                break;
            case 1: /* switch 1 */
                if (--D_801825F0[1] < 0) {
                    D_801825F0[1] = 0;
                }
                break;
            case 2: /* switch 1 */
                if (--D_801825F0[2] < 0) {
                    D_801825F0[2] = 0;
                }
                if (D_801825F0[7] > 0) {
                    sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
                    sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
                    func_800B3DBC(&sp50, &sp4C, D_801825F0[2]);
                }
                break;
            case 3: /* switch 1 */
                D_801825F0[0] ^= 4;
        }
    }
    if (gControllers->unk6 & gInputMask_DPadRight) {
        if (++D_801825F0[5] > 3) {
            D_801825F0[5] = 3;
        }
    }
    if (gControllers->unk6 & gInputMask_DPadLeft) {
        if (--D_801825F0[5] < 0) {
            D_801825F0[5] = 0;
        }
    }
    if (gControllers->unk6 & gInputMask_A) {
        sp54 = (Sp54*) D_80182618->ptrs[0];
        sp54 += D_801825F0[1];
        sp5A = sp54[0][0] >> 0x10;
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
        if (D_801825F0[0] & 4) {
            sp4B = 4;
        } else {
            sp4B = 0;
        }
        func_80022124();
        D_801825F0[7] = func_800B202C(&sp50, &sp4C, sp54[0][0], D_801825F0[2], sp50->unkCC, sp50->unkD0, (s32) sp4B);
        D_801825F0[0] |= 2;
        D_801825F0[0] |= 1;
    } else if (D_801825F0[0] & 2) {
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
        sp6C = func_800B2748(&sp50, &sp4C);
        if (sp6C < 0) {
            D_801825F0[0] &= ~2;
            D_801825F0[0] &= ~1;
        } else {
            D_801825F0[7] = sp6C;
        }
    }
    if (gControllers->unk6 & gInputMask_B) {
        D_801825F0[0] &= ~2;
        if (!(D_801825F0[0] & 1)) {
            sp54 = (Sp54*) D_80182618->ptrs[0];
            sp54 += D_801825F0[1];
            sp5A = sp54[0][0] >> 0x10;
            sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
            sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
            if (D_801825F0[0] & 4) {
                sp4B = 4;
            } else {
                sp4B = 0;
            }
            func_80022124();
            D_801825F0[7] =
                func_800B202C(&sp50, &sp4C, sp54[0][0], D_801825F0[2], sp50->unkCC, sp50->unkD0, (s32) sp4B);
            D_801825F0[0] |= 1;
        } else {
            sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
            sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
            sp6C = func_800B2748(&sp50, &sp4C);
            if (sp6C < 0) {
                D_801825F0[0] &= ~1;
            } else {
                D_801825F0[7] = sp6C;
            }
        }
    }
    if ((gControllers->unk6 & gInputMask_A) && (gControllers->unk6 & gInputMask_B)) {
        for (sp68 = 0, sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2]; sp68 < 8; sp68++, sp50++) {
            sp50->unkD0 = 0.0f;
            sp50->unkCC = (f32) sp50->unkD0;
            sp50->unkF8 = 1.0f;
            sp50->unkF4 = (f32) sp50->unkF8;
        }
    }
    if (gControllers->unk6 & gInputMask_Z) {
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
        sp6C = func_800B2CBC(&sp50, &sp4C, 2);
        if (sp6C < 0) {
            D_801825F0[0] &= ~1;
        } else {
            D_801825F0[7] = sp6C;
        }
    }
    if (D_801825F0[0] & 1) {
        sp4C = (UnkStruct_800B23C4*) D_80182618->ptrs[1];
        sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2];
        sp48 = func_800B3434(&sp4C, 0);
        if (sp48 & 0x4000) {
            func_800B9000(func_800B32E4(&sp4C, 0));
        }
        if (sp48 & 0x8000) {
            func_800B9000(func_800B32E4(&sp4C, 1));
        }
        if (gControllers->button & (gInputMask_CUp | gInputMask_CDown | gInputMask_CRight | gInputMask_CLeft)) {
            func_800B2CBC(&sp50, &sp4C, 6);
        } else {
            func_800B2CBC(&sp50, &sp4C, 5);
        }
    }

    for (sp68 = 0, sp50 = (UnkStruct_80099E2C*) D_80182618->ptrs[2]; sp68 < 8; sp68++, sp50++) {
        if (FABS(gControllers->stickX) >= 10.0) {
            sp50->unkCC += gControllers->stickX * 0.1;
        }

        if (FABS(gControllers->stickY) >= 10.0) {
            sp50->unkD0 += gControllers->stickY * 0.1;
        }
        if (gControllers->unk8 & gInputMask_R) {
            sp50->unkF8 = (sp50->unkF4 += 0.2);
        }
        if (gControllers->unk8 & gInputMask_L) {
            sp50->unkF8 = (sp50->unkF4 -= 0.2);
            if (sp50->unkF8 <= 0.0) {
                sp50->unkF8 = sp50->unkF4 = 0.009999999776f;
            }
        }
        if ((gControllers->unk6 & gInputMask_R) && (gControllers->unk6 & gInputMask_L)) {
            sp50->unkF8 = sp50->unkF4 = 1.0f;
        }
        if (sp68 >= D_801825F0[7]) {
            continue;
        }

        MtxUtil_PushIdentity();
        func_8009A14C(sp50);
        func_800997D8(sp50);
        MtxUtil_Pop();
    }
}
