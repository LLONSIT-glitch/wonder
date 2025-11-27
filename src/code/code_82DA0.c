#include "common.h"

void func_80082C04(UnkStruct_8018165C*);      /* extern */
void func_80082D18(UnkStruct_8018165C*, s32); /* extern */
void func_80082DD4(UnkStruct_8018165C*);      /* extern */
s32 func_8008250C(UnkStruct_801A7340_unk144*, UnkStruct_8008250C*);
void func_8005A5F4(UnkStruct_800B23C4*, void*);
extern UnkStruct_8018165C* D_8018165C;

void func_800821A0(void) {
    UnkStruct_801A7340_unk144* sp54;
    UnkStruct_8018165C* sp50; /* compiler-managed */
    UnkStruct_8018165C* sp4C;
    UnkStruct_8008250C sp2C;

    D_8018165C = NULL;
    sp50 = NULL;
    if (D_801A7340->unk144 == NULL) {
        return;
    }

    for (sp54 = D_801A7340->unk144; sp54->unk0 != 0x8000 || sp54->unk2 != 0x8000; sp54++) {
        if (func_8008250C(sp54, &sp2C) != 0) {
            sp4C = SysMem_HeapAlloc(sizeof(UnkStruct_8018165C));
            if (D_8018165C == NULL) {
                D_8018165C = sp4C;
            } else if (sp50 != 0) {
                sp50->unk44 = sp4C;
            }

            sp4C->unk44 = 0;
            sp4C->unk40 = (s32) sp50;
            sp50 = sp4C;
            sp4C->unk2 = D_801A7234;
            sp4C->unk4 = D_801A723C;
            sp4C->unk0 = 0;
            sp4C->unk6 = (s16) ((s32) (sp54->unk8 & 0x3C) >> 2);
            sp4C->unk14 = (f32) sp54->unkC;
            sp4C->unk18 = (f32) sp54->unkE;
            sp4C->unk1C = (f32) sp54->unkC;
            sp4C->unk20 = (f32) sp54->unkE;
            sp4C->unk8 = (s16) sp2C.unk0;
            sp4C->unkA = sp2C.unk2;
            sp4C->unkC = sp2C.unk4;
            sp4C->unk10 = 0.0f;
            sp4C->unk24 = sp2C.unk8;
            sp4C->unk28 = sp2C.unkC;
            sp4C->unk2C = sp2C.unk10;
            sp4C->unk38 = sp2C.unk18;
            sp4C->unk34 = sp2C.unk14;
            sp4C->unk3C = sp2C.unk1C;

            if (sp4C->unkC != 0) {
                sp4C->unk30 = func_800B202C(&sp4C->unk24, &sp4C->unk28, (sp4C->unk8 << 0x10) | sp4C->unkA, sp4C->unk2C,
                                            sp4C->unk14, sp4C->unk18, 0U);
                func_8005A5F4((UnkStruct_800B23C4*) &sp4C->unk28, NULL);
                sp4C->unk0 |= 1;
                if (sp4C->unk30 == -1) {
                    sp4C->unkC = 0;
                }
            } else {
                sp4C->unk30 = 0;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008250C.s")

void func_80082958(void) {
    UnkStruct_8018165C* sp24; /* compiler-managed */

    if (D_8018165C == NULL) {
        return;
    }
    sp24 = D_8018165C;
    do {
        switch (sp24->unkC) { /* irregular */
            case 1:
                func_80082C04(sp24);
                break;
            case 2:
                switch (sp24->unkA) { /* switch 1; irregular */
                    case 0x244:       /* switch 1 */
                        if ((sp24->unk0 & 8) && (sp24->unk0 & 4)) {
                            func_80082D18(sp24, 0x246);
                            sp24->unk0 &= ~8;
                        }
                        break;
                    case 0x246: /* switch 1 */
                        if ((sp24->unk0 & 8) && (sp24->unk0 & 4)) {
                            func_80082D18(sp24, 0x247);
                            sp24->unk0 &= ~8;
                            sp24->unkE = 0;
                        }
                        break;
                    case 0x247: /* switch 1 */
                        if (sp24->unk0 & 2) {
                            func_80082D18(sp24, 0x244);
                        }
                        break;
                }
                break;
            case 3:
                if (sp24->unkE >= 0x259) {
                    if (!(sp24->unk0 & 4) || (sp24->unkE >= 0x259)) {
                        sp24->unkC = -1;
                    }
                } else {
                    sp24->unkE += (s32) D_8018257C;
                }
                break;
            case 4:
                break;
        }
        if (sp24->unkC > 0) {
            func_80082DD4(sp24);
        }
    } while ((sp24 = sp24->unk44) != NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80082C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80082D18.s")

void func_80082DD4(UnkStruct_8018165C* arg0) {
    s32 sp1C;

    if (arg0->unk0 & 1) {
        arg0->unk0 &= ~1;
    } else {
        sp1C = func_800B2748(&arg0->unk24, &arg0->unk28);
        if (sp1C != -1) {
            arg0->unk30 = sp1C;
            func_8005A5F4((UnkStruct_800B23C4*) &arg0->unk28, NULL);
        } else {
            arg0->unk0 |= 2;
        }
    }

    for (sp1C = 0; sp1C < arg0->unk30; sp1C++) {
        arg0->unk24[sp1C].unkCC = arg0->unk14;
        arg0->unk24[sp1C].unkD0 = arg0->unk18;
        arg0->unk24[sp1C].unkD4 = 0.0f;
        arg0->unk24[sp1C].unkF4 = 1.0f;
        arg0->unk24[sp1C].unkF8 = 1.0f;
        arg0->unk24[sp1C].unk11E = (s16) arg0->unk3C;
        arg0->unk24[sp1C].unkC8 = arg0->unk38;
        func_800C1754();
        func_8009A14C(&arg0->unk24[sp1C]);
        if (!(*D_801A8D88 & 0x200)) {
            func_800997D8(&arg0->unk24[sp1C]);
        }
        func_800C1A28();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008308C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008312C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800831E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80083700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80083AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80083E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80083EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80083F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80083FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80084020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800841CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80084244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800847EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800848B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80084D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80084D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80084E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80084F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800851C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800854B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800856B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800856E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800857BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800859DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80085ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80085B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80085C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80085CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80085D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80085F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008606C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800862A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800863D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800867F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800868C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80086F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800870BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008717C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800875E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80087F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008834C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800883F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800886C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80088F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80089170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80089418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80089584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800897A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_800898D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008997C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80089B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_80089BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A46C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008A964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008AA44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008AAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008ABB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008AD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008AF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B1D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008B738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008BA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008BC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008BE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008BEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008BFF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C0A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C3D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008C854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008CA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008CC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_82DA0/func_8008CE48.s")
