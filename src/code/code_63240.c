#include "common.h"

typedef struct UnkStruct_80180648_s {
    s16 work[0x100];
} UnkStruct_80180648;

void func_80031874(void);                               /* extern */
s32 func_80031AC8(void);                                /* extern */
s32 func_8005F064(s32);                                 /* extern */
s32 func_80061348(s32);                                 /* extern */
s32 func_80061488(s32);                                 /* extern */
void* func_80096B38(s32*, s32*, s32*, s32*, s32*, s32); /* extern */
void func_80096C6C(s32*, s32);                          /* extern */
extern s32 D_6A69E0;
extern s16 D_80180CE0;
extern void* D_80180CEC;
extern s32 D_809B4200;
extern s32 D_809D07B0;
extern s32 D_809D3920;
extern s32 D_809D45E0;
extern UnkStruct_80180648* D_80180648;

int func_80062640(void) {
    D_80180CE0 = 0;
    D_80180CEC = SysMem_HeapAlloc(0xC8);
}

int func_80062678(s16 arg0) {
    int sp2C;
    int* sp28;
    int* sp24;
    int sp20;

    ;
    if ((sp2C = arg0) < 0x2710) {
        sp28 = &D_809D07B0;
        sp24 = &D_809B4200;
    } else {
        sp28 = &D_809D45E0;
        sp24 = &D_809D3920;
        sp2C -= 0x2710;
    }
    sp24 = func_80096B38(&D_6A69E0, &D_809B4200, sp28, sp24, &sp20, sp2C);
    if (func_80031AC8() == -2) {
        func_80031874();
    }
    func_80096C6C(sp24, sp20);
}

int func_80062750(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80062784(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800627B8(void) {
    return func_8005F064(0x9D);
}

int func_800627E8(void) {
    return func_8005F064(0x9D);
}

int func_80062818(void) {
    return func_8005F064(0xA1);
}

int func_80062848(void) {
    return func_8005F064(0xA1);
}

int func_80062878(void) {
    return func_8005F064(0xA2);
}

int func_800628A8(void) {
    return func_8005F064(0xA2);
}

int func_800628D8(void) {
    return func_8005F064(0xA5);
}

int func_80062908(void) {
    return func_8005F064(0xA5);
}

int func_80062938(void) {
    return func_8005F064(0xA6);
}

int func_80062968(void) {
    return func_8005F064(0xA6);
}

int func_80062998(void) {
    return func_8005F064(0xA7);
}

int func_800629C8(void) {
    return func_8005F064(0xA7);
}

int func_800629F8(void) {
    return func_8005F064(0xA8);
}

int func_80062A28(void) {
    return func_8005F064(0xA8);
}

int func_80062A58(void) {
    return func_8005F064(0xA9);
}

int func_80062A88(void) {
    return func_8005F064(0xA9);
}

int func_80062AB8(void) {
    return func_8005F064(0xAB);
}

int func_80062AE8(void) {
    return func_8005F064(0xAB);
}

int func_80062B18(void) {
    return func_8005F064(0xAD);
}

int func_80062B48(void) {
    return func_8005F064(0xAD);
}

int func_80062B78(void) {
    return func_8005F064(0xAC);
}

int func_80062BA8(void) {
    return func_8005F064(0xAC);
}

int func_80062BD8(void) {
    return func_8005F064(0x98);
}

int func_80062C08(void) {
    return func_8005F064(0x98);
}

int func_80062C38(void) {
    return func_80061488(0x694) >= 2;
}

int func_80062C70(void) {
    return func_80061488(0x6C5) >= 2;
}

int func_80062CA8(void) {
    return func_80061348(0x694) == 0;
}

int func_80062CDC(void) {
    return func_80061488(0x695) >= 2;
}

int func_80062D14(void) {
    return func_80061488(0x696) >= 2;
}

int func_80062D4C(void) {
    return func_80061488(0x697) >= 2;
}

int func_80062D84(void) {
    return func_80061488(0x6A8) >= 2;
}

int func_80062DBC(void) {
    return func_80061488(0x6A9) >= 2;
}

int func_80062DF4(void) {
    return func_8005F064(0x86);
}

int func_80062E24(void) {
    return func_8005F064(0xAC);
}

int func_80062E54(void) {
    return func_80061488(0x633) >= 2;
}

int func_80062E8C(void) {
    return func_8005F064(0xAC);
}

int func_80062EBC(void) {
    return func_8005F064(0x8B);
}

int func_80062EEC(void) {
    return func_8005F064(0x8B);
}

int func_80062F1C(void) {
    return func_8005F064(0x8B);
}

int func_80062F4C(void) {
    return func_8005F064(0x8B) == 0;
}

int func_80062F80(void) {
    return func_8005F064(0x8C);
}

int func_80062FB0(void) {
    return func_8005F064(0x8C);
}

int func_80062FE0(void) {
    return func_8005F064(0x8C);
}

int func_80063010(void) {
    return func_8005F064(0x8C) == 0;
}

int func_80063044(void) {
    return func_8005F064(0x8D);
}

int func_80063074(void) {
    return func_80061488(0x621) >= 2;
}

int func_800630AC(void) {
    return func_8005F064(0x29) == 0;
}

int func_800630E0(void) {
    return func_80061488(0x621) == 1;
}

int func_80063118(void) {
    return func_80061488(0x621) >= 3;
}

int func_80063150(void) {
    return func_80061488(0x621) == 1;
}

int func_80063188(void) {
    return func_80061488(0x621) == 1;
}

int func_800631C0(void) {
    return func_80061488(0x61A) == 1;
}

int func_800631F8(void) {
    return func_8005F064(0x4C) == 0;
}

int func_8006322C(void) {
    return func_80061488(0x61C) == 1;
}

int func_80063264(void) {
    return func_80061488(0x61C) == 1;
}

int func_8006329C(void) {
    return func_80061488(0x61C) == 1;
}

int func_800632D4(void) {
    return func_8005F064(0x8A);
}

int func_80063304(void) {
    return func_8005F064(0x8A) == 0;
}

int func_80063338(void) {
    return func_80061488(0x610) == 1;
}

int func_80063370(void) {
    return func_80061488(0x612) == 1;
}

int func_800633A8(void) {
    return func_8005F064(0x88);
}

int func_800633D8(void) {
    return func_8005F064(0x71) == 0;
}

int func_8006340C(void) {
    return func_8005F064(0x71);
}

int func_8006343C(void) {
    return func_8005F064(0x71);
}

int func_8006346C(void) {
    return func_80061348(0x3E7) == 0 || func_80061348(0x3E8) == 0 || D_80180648->work[0x10] >= 0x12C;
}

int func_800634E4(void) {
    return func_80061488(0x5E7) == 1 && !(func_80061348(0x3E7) == 0) && !(func_80061348(0x3E8) == 0) &&
           !(D_80180648->work[0x10] >= 0x12C);
}

int func_80063584(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_800635B8(void) {
    return D_80180648->work[0x10] >= 0x1F4;
}

int func_800635EC(void) {
    return D_80180648->work[0] == 0;
}

int func_8006361C(void) {
    return D_80180648->work[3] >= 0x384 && D_80180648->work[4] >= 0x384;
}

int func_80063670(void) {
    return func_8005F064(0x78);
}

int func_800636A0(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_800636D4(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80063708(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_8006373C(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_80063770(void) {
    return func_8005F064(0x2C) == 0;
}

int func_800637A4(void) {
    return D_80180648->work[8] >= 0x1F4 && D_80180648->work[9] >= 0x1F4;
}

int func_800637F8(void) {
    return func_80061488(0x606) == 1;
}

int func_80063830(void) {
    return func_80061488(0x606) == 1;
}

int func_80063868(void) {
    return func_8005F064(0x2C);
}

int func_80063898(void) {
    return D_80180648->work[8] >= 0x1F4 && D_80180648->work[9] >= 0x1F4;
}

int func_800638EC(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_80063920(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80063954(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_80063988(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_800639BC(void) {
    return D_80180648->work[0xE] >= 0x12C;
}

int func_800639F0(void) {
    return D_80180648->work[0xE] >= 0x1F4;
}

int func_80063A24(void) {
    return func_8005F064(0x2C);
}

int func_80063A54(void) {
    return func_8005F064(0x2C);
}

int func_80063A84(void) {
    return func_8005F064(0x2C) == 0;
}

int func_80063AB8(void) {
    return func_8005F064(0x2C);
}

int func_80063AE8(void) {
    return func_8005F064(0x2C);
}

int func_80063B18(void) {
    return func_8005F064(0x2C) == 0;
}

int func_80063B4C(void) {
    return func_8005F064(0x2C);
}

int func_80063B7C(void) {
    return func_8005F064(0x2C);
}

int func_80063BAC(void) {
    return func_8005F064(0x2C) == 0;
}

int func_80063BE0(void) {
    return func_8005F064(0x2C);
}

int func_80063C10(void) {
    return func_8005F064(0x2C);
}

int func_80063C40(void) {
    return func_8005F064(0x2C) == 0;
}

int func_80063C74(void) {
    return func_8005F064(0x7A);
}

int func_80063CA4(void) {
    return func_8005F064(0x7A);
}

int func_80063CD4(void) {
    return func_8005F064(0x7A) == 0;
}

int func_80063D08(void) {
    return func_8005F064(0x7A);
}

int func_80063D38(void) {
    return func_80061488(0x5D8) == 1;
}

int func_80063D70(void) {
    return func_80061488(0x5D8) == 1;
}

int func_80063DA8(void) {
    return func_80061488(0x5D8) == 1;
}

int func_80063DE0(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_80063E14(void) {
    return !func_80061348(0x13A) || !func_80061348(0x13E);
}

int func_80063E64(void) {
    return func_80061488(0x5DC) == 1;
}

int func_80063E9C(void) {
    return func_8005F064(0x5F);
}

int func_80063ECC(void) {
    return func_80061488(0x5DE) >= 2;
}

int func_80063F04(void) {
    return func_8005F064(0x5F);
}

int func_80063F34(void) {
    return func_80061488(0x5DE) == 1;
}

int func_80063F6C(void) {
    return func_80061488(0x5E1) == 1;
}

int func_80063FA4(void) {
    return func_8005F064(0x4C) == 0;
}

int func_80063FD8(void) {
    return func_80061488(0x5E3) == 1;
}

int func_80064010(void) {
    return func_8005F064(0xA) == 0;
}

int func_80064044(void) {
    return func_80061488(0x5BE) >= 2;
}

int func_8006407C(void) {
    return func_8005F064(0xD0) && !func_8005F064(0xA);
}

int func_800640CC(void) {
    return func_8005F064(0xA) == 0;
}

int func_80064100(void) {
    return D_80180648->work[0x22] >= 0x64 && !func_8005F064(0xA);
}

int func_80064160(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_8006422C(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_800642F8(void) {
    return func_80061488(0x624) >= 2;
}

int func_80064330(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80064364(void) {
    return func_80061488(0x628) >= 3;
}

int func_8006439C(void) {
    return func_80061488(0x628) == 3;
}

int func_800643D4(void) {
    return func_80061488(0x628) == 2;
}

int func_8006440C(void) {
    return D_80180648->work[0x22] >= 0x64 && !func_8005F064(0xA);
}

int func_8006446C(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064538(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064604(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80064638(void) {
    return func_80061488(0x62D) >= 2;
}

int func_80064670(void) {
    return D_80180648->work[0x22] >= 0x64 && !func_8005F064(0xA);
}

int func_800646D0(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_8006479C(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064868(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006489C(void) {
    return func_80061488(0x632) >= 3;
}

int func_800648D4(void) {
    return func_80061488(0x632) == 2;
}

int func_8006490C(void) {
    return func_8005F064(0x6D);
}

int func_8006493C(void) {
    return D_80180648->work[0x22] >= 0x64 && !func_8005F064(0xA);
}

int func_8006499C(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064A68(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064B34(void) {
    return func_8005F064(0x4C);
}

int func_80064B64(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80064B98(void) {
    return func_8005F064(0xAC);
}

int func_80064BC8(void) {
    return func_8005F064(0x4C);
}

int func_80064BF8(void) {
    return D_80180648->work[0x22] >= 0x64 && !func_8005F064(0xA);
}

int func_80064C58(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064D24(void) {
    return func_80061488(0x5BF) > 0 && func_80061488(0x629) > 0 && func_80061488(0x62E) > 0 &&
           func_80061488(0x633) > 0 && func_80061488(0x638) > 0 && func_8005F064(0xAF) && !(func_80061348(0x6C8) == 0);
}

int func_80064DF0(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80064E24(void) {
    return func_8005F064(0xA);
}

int func_80064E54(void) {
    return func_8005F064(0x42);
}

int func_80064E84(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80064EB8(void) {
    return D_80180648->work[0xF] >= 0x12C;
}

int func_80064EEC(void) {
    return func_8005F064(0xA7);
}

int func_80064F1C(void) {
    return D_80180648->work[0x10] >= 0x1F4;
}

int func_80064F50(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80064F84(void) {
    return D_80180648->work[0xD] >= 0x1F4;
}

int func_80064FB8(void) {
    return D_80180648->work[0xC] >= 0x1F4;
}

int func_80064FEC(void) {
    return func_8005F064(0xA7);
}

int func_8006501C(void) {
    return func_80061488(0x5E0) >= 3;
}

int func_80065054(void) {
    return func_80061488(0x5E0) >= 3;
}

int func_8006508C(void) {
    return D_80180648->work[3] >= 0x2BC;
}

int func_800650C0(void) {
    return D_80180648->work[0x14] >= 0x2BC;
}

int func_800650F4(void) {
    return func_8005F064(0xA7);
}

int func_80065124(void) {
    return D_80180648->work[0xC] >= 0x1F4;
}

int func_80065158(void) {
    return D_80180648->work[0xE] >= 0x1F4;
}

int func_8006518C(void) {
    return D_80180648->work[0x10] >= 0x1F4;
}

int func_800651C0(void) {
    return D_80180648->work[0x12] >= 0x1F4;
}

int func_800651F4(void) {
    return D_80180648->work[0xF] >= 0x1F4;
}

int func_80065228(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_8006525C(void) {
    return D_80180648->work[0x13] >= 0x1F4;
}

int func_80065290(void) {
    return func_8005F064(0xD);
}

int func_800652C0(void) {
    return func_8005F064(0xC);
}

int func_800652F0(void) {
    return func_8005F064(0xF);
}

int func_80065320(void) {
    return D_80180648->work[0x14] >= 0x2BC;
}

int func_80065354(void) {
    return D_80180648->work[0xF] < 0x12D && D_80180648->work[0x14] < 0x1F5;
}

int func_800653A0(void) {
    return D_80180648->work[0x1A] >= 0x1F4;
}

int func_800653D4(void) {
    return D_80180648->work[0x19] >= 0x1F4;
}

int func_80065408(void) {
    return D_80180648->work[0x18] >= 0x1F4;
}

int func_8006543C(void) {
    return func_8005F064(0x6C) && !func_8005F064(0x6F);
}

int func_8006548C(void) {
    return func_8005F064(0xA8) == 0;
}

int func_800654C0(void) {
    return func_80061488(0x74C) >= 2;
}

int func_800654F8(void) {
    return !func_80061348(0x3D6) || func_80061348(0x3DC) == 1;
}

int func_8006554C(void) {
    return func_8005F064(0xA9) == 0;
}

int func_80065580(void) {
    return D_80180648->work[6] < 0x2BD && D_80180648->work[6] >= 0x12D;
}

int func_800655D0(void) {
    return D_80180648->work[6] < 0x12D;
}

int func_80065600(void) {
    return D_80180648->work[7] < 0x2BD && D_80180648->work[7] >= 0x12D;
}

int func_80065650(void) {
    return D_80180648->work[7] < 0x12D;
}

int func_80065680(void) {
    return func_8005F064(0x89) == 0;
}

int func_800656B4(void) {
    return func_8005F064(0x93);
}

int func_800656E4(void) {
    return func_8005F064(0x93) == 0;
}

int func_80065718(void) {
    return func_8005F064(0x93);
}

int func_80065748(void) {
    return func_8005F064(0x93);
}

int func_80065778(void) {
    return D_80180648->work[0x10] >= 0x384;
}

int func_800657AC(void) {
    return D_80180648->work[0x10] >= 0x384;
}

int func_800657E0(void) {
    return D_80180648->work[0x10] >= 0x384;
}

int func_80065814(void) {
    return func_80061488(0x5F1) == 1;
}

int func_8006584C(void) {
    return D_80180648->work[0x12] >= 0x12C;
}

int func_80065880(void) {
    return D_80180648->work[0x12] >= 0x2BC;
}

int func_800658B4(void) {
    return func_8005F064(0x94);
}

int func_800658E4(void) {
    return func_8005F064(0x94) == 0;
}

int func_80065918(void) {
    return func_80061488(0x5A6) == 1;
}

int func_80065950(void) {
    return D_80180648->work[0x10] >= 0x12C;
}

int func_80065984(void) {
    return func_80061488(0x5A6) == 1;
}

int func_800659BC(void) {
    return func_80061488(0x5A6) == 1;
}

int func_800659F4(void) {
    return func_80061488(0x59C) >= 2 && D_80180648->work[0x18] >= 0x2BC;
}

int func_80065A58(void) {
    return func_80061488(0x59C) >= 2 && D_80180648->work[0x19] >= 0x2BC;
}

int func_80065ABC(void) {
    return func_80061488(0x59C) >= 2 && D_80180648->work[0x1A] >= 0x2BC;
}

int func_80065B20(void) {
    return func_80061488(0x59C) >= 2 && D_80180648->work[0x1B] >= 0x2BC;
}

int func_80065B84(void) {
    return func_80061488(0x59C) >= 2;
}

int func_80065BBC(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80065BF0(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_80065C24(void) {
    return func_80061488(0x6CF) == 0;
}

int func_80065C58(void) {
    return D_80180648->work[0xF] >= 0x2BC && func_8005F064(0x95);
}

int func_80065CB8(void) {
    return func_8005F064(0x95);
}

int func_80065CE8(void) {
    return D_80180648->work[0x18] < 0x2BD && D_80180648->work[0x18] < 0x321;
}

int func_80065D34(void) {
    return D_80180648->work[0x19] >= 0x2BC && D_80180648->work[0x19] < 0x321;
}

int func_80065D84(void) {
    return D_80180648->work[0x1A] >= 0x2BC && D_80180648->work[0x1A] < 0x321;
}

int func_80065DD4(void) {
    return D_80180648->work[0x1B] >= 0x2BC && D_80180648->work[0x1B] < 0x321;
}

int func_80065E24(void) {
    return func_80061488(0x120) >= 2;
}

int func_80065E5C(void) {
    return func_80061488(0x122) >= 2;
}

int func_80065E94(void) {
    return func_80061348(0x121) == 0;
}

int func_80065EC8(void) {
    return func_80061348(0x12E) == 0;
}

int func_80065EFC(void) {
    return func_80061348(0x121) == 0;
}

int func_80065F30(void) {
    return func_80061348(0x12E) == 0;
}

int func_80065F64(void) {
    return func_80061348(0x121) == 0;
}

int func_80065F98(void) {
    return func_80061348(0x12E) == 0;
}

int func_80065FCC(void) {
    return func_80061488(0x130) >= 2;
}

int func_80066004(void) {
    return D_80180648->work[0x19] >= 0x259 && D_80180648->work[0x19] < 0x2BD;
}

int func_80066054(void) {
    return D_80180648->work[0x19] >= 0x1F4 && D_80180648->work[0x19] < 0x259;
}

int func_800660A4(void) {
    return D_80180648->work[0x16] >= 0x1F4;
}

int func_800660D8(void) {
    return D_80180648->work[0x16] < 0x1F4;
}

int func_80066108(void) {
    return func_80061348(0x121) == 0;
}

int func_8006613C(void) {
    return func_80061348(0x12E) == 0;
}

int func_80066170(void) {
    return func_80061348(0x121) == 0;
}

int func_800661A4(void) {
    return func_80061348(0x12E) == 0;
}

int func_800661D8(void) {
    return func_80061348(0x121) == 0;
}

int func_8006620C(void) {
    return func_80061348(0x12E) == 0;
}

int func_80066240(void) {
    return func_80061348(0x121) == 0;
}

int func_80066274(void) {
    return func_80061348(0x12E) == 0;
}

int func_800662A8(void) {
    return func_80061348(0x121) == 0;
}

int func_800662DC(void) {
    return func_80061348(0x12E) == 0;
}

int func_80066310(void) {
    return func_80061348(0x121) == 0;
}

int func_80066344(void) {
    return func_80061348(0x121) == 0;
}

int func_80066378(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x135) == 0;
}

int func_800663C8(void) {
    return func_80061348(0x138) == 0;
}

int func_800663FC(void) {
    return func_80061348(0x13C) == 0;
}

int func_80066430(void) {
    return func_80061348(0x13D) == 0;
}

int func_80066464(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x122) == 0;
}

int func_800664B4(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x135) == 0;
}

int func_80066504(void) {
    return func_80061348(0x138) == 0;
}

int func_80066538(void) {
    return func_80061348(0x13C) == 0;
}

int func_8006656C(void) {
    return func_80061348(0x13D) == 0;
}

int func_800665A0(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x122) == 0;
}

int func_800665F0(void) {
    return func_80061488(0x124) >= 2;
}

int func_80066628(void) {
    return func_80061348(0x122) == 0 || func_80061348(0x135) == 0 || func_80061348(0x138) == 0 ||
           func_80061348(0x139) == 0;
}

int func_800666A8(void) {
    return func_80061348(0x13C) == 0 || func_80061348(0x13F) == 0 || func_80061348(0x13D) == 0 ||
           func_80061348(0x142) == 0;
}

int func_80066728(void) {
    return func_80061348(0x135) == 0;
}

int func_8006675C(void) {
    return func_80061348(0x135) == 1;
}

int func_80066794(void) {
    return func_80061348(0x135) == 0 || func_80061348(0x122) == 0;
}

int func_800667E4(void) {
    return func_80061348(0x253) == 1;
}

int func_8006681C(void) {
    return func_80061348(0x136) == 0;
}

int func_80066850(void) {
    return func_80061348(0x135) == 0 || func_80061348(0x122) == 0;
}

int func_800668A0(void) {
    return func_80061348(0x139) == 0;
}

int func_800668D4(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x135) == 0;
}

int func_80066924(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x122) == 0;
}

int func_80066974(void) {
    return func_80061348(0x139) == 0;
}

int func_800669A8(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x135) == 0;
}

int func_800669F8(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x122) == 0;
}

int func_80066A48(void) {
    return func_80061348(0x13F) == 0;
}

int func_80066A7C(void) {
    return func_80061348(0x142) == 0;
}

int func_80066AB0(void) {
    return func_80061348(0x13F) == 0;
}

int func_80066AE4(void) {
    return func_80061348(0x142) == 0;
}

int func_80066B18(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80066B4C(void) {
    return func_80061348(0x122) == 0;
}

int func_80066B80(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80066BB4(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80066BE8(void) {
    return func_80061348(0x143) == 0;
}

int func_80066C1C(void) {
    return func_80061348(0x145) == 0;
}

int func_80066C50(void) {
    return func_80061348(0x146) == 0;
}

int func_80066C84(void) {
    return func_80061348(0x253) == 0;
}

int func_80066CB8(void) {
    return func_80061348(0x14F) == 0;
}

int func_80066CEC(void) {
    return func_80061348(0x152) == 0;
}

int func_80066D20(void) {
    return func_80061348(0x153) == 0;
}

int func_80066D54(void) {
    return func_80061348(0x147) == 0;
}

int func_80066D88(void) {
    return func_80061348(0x2AD) == 0;
}

int func_80066DBC(void) {
    return func_80061348(0x121) == 0;
}

int func_80066DF0(void) {
    return func_80061348(0x120) == 1;
}

int func_80066E28(void) {
    return func_80061348(0x120) == 1;
}

int func_80066E60(void) {
    return func_80061348(0x124) == 1;
}

int func_80066E98(void) {
    return func_80061348(0x124) == 1;
}

int func_80066ED0(void) {
    return func_80061488(0x256) >= 2;
}

int func_80066F08(void) {
    return func_80061348(0x122) == 0 || func_80061348(0x134) == 0 || func_80061348(0x138) == 0 ||
           func_80061348(0x139) == 0;
    ;
}

int func_80066F88(void) {
    return func_80061348(0x13C) == 0 || func_80061348(0x13F) == 0 || func_80061348(0x13D) == 0 ||
           func_80061348(0x142) == 0;
    ;
}

int func_80067008(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006703C(void) {
    return func_80061488(0x264) >= 2;
}

int func_80067074(void) {
    return D_80180648->work[0x16] >= 0x64;
}

int func_800670A8(void) {
    return D_80180648->work[0x16] >= 0x32;
}

int func_800670DC(void) {
    return D_80180648->work[0x16] >= 0x32;
}

int func_80067110(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80067144(void) {
    return func_80061488(0x2D9) >= 3;
}

int func_8006717C(void) {
    return func_80061488(0x2D3) < 3;
}

int func_800671B0(void) {
    return func_80061488(0x2DD) >= 2;
}

int func_800671E8(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006721C(void) {
    return func_80061488(1) >= 2;
}

int func_80067254(void) {
    return func_80061488(1) >= 2;
}

int func_8006728C(void) {
    return func_80061488(0xB) >= 2;
}

int func_800672C4(void) {
    return func_80061488(0xD) >= 2;
}

int func_800672FC(void) {
    return func_80061488(2) >= 2;
}

int func_80067334(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80067368(void) {
    return D_80180648->work[0x10] >= 0x1F4;
}

int func_8006739C(void) {
    return func_80061488(0x2E3) >= 2;
}

int func_800673D4(void) {
    return D_80180648->work[3] >= 0x12C;
}

int func_80067408(void) {
    return D_80180648->work[3] >= 0x1F4;
}

int func_8006743C(void) {
    return D_80180648->work[3] >= 0x258;
}

int func_80067470(void) {
    return func_80061488(0x13) >= 2;
}

int func_800674A8(void) {
    return func_80061488(0x13) >= 2;
}

int func_800674E0(void) {
    return D_80180648->work[0xE] >= 0xC8;
}

int func_80067514(void) {
    return func_80061488(0x14) >= 3 && func_80061348(0x12E) == 0;
}

int func_80067568(void) {
    return D_80180648->work[5] >= 0x32 && D_80180648->work[6] >= 0x32;
}

int func_800675BC(void) {
    return D_80180648->work[0xE] >= 0x64;
}

int func_800675F0(void) {
    return D_80180648->work[8] >= 0x12C;
}

int func_80067624(void) {
    return func_80061488(0x2F4) >= 2;
}

int func_8006765C(void) {
    return D_80180648->work[5] >= 0x96 && D_80180648->work[6] >= 0x96;
}

int func_800676B0(void) {
    return D_80180648->work[5] >= 0xC8 && D_80180648->work[6] >= 0xC8;
}

int func_80067704(void) {
    return D_80180648->work[5] >= 0x12C && D_80180648->work[6] >= 0x12C;
}

int func_80067758(void) {
    return func_80061348(0x12E) == 0;
}

int func_8006778C(void) {
    return func_80061348(0x121) == 0;
}

int func_800677C0(void) {
    return func_80061348(0x12E) == 0;
}

int func_800677F4(void) {
    return func_80061348(0x121) == 0;
}

int func_80067828(void) {
    return func_80061348(0x12E) == 0;
}

int func_8006785C(void) {
    return func_80061348(0x121) == 0;
}

int func_80067890(void) {
    return func_80061488(0x21) == 2;
}

int func_800678C8(void) {
    return func_80061488(0x21) >= 3;
}

int func_80067900(void) {
    return D_80180648->work[0x11] >= 0x12C;
}

int func_80067934(void) {
    return D_80180648->work[5] >= 0x96 && D_80180648->work[6] >= 0x96;
}

int func_80067988(void) {
    return func_80061488(0x309) >= 2;
}

int func_800679C0(void) {
    return D_80180648->work[8] >= 0x12C;
}

int func_800679F4(void) {
    return D_80180648->work[9] >= 0x1F4;
}

int func_80067A28(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80067A5C(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80067A90(void) {
    return D_80180648->work[8] >= 0x12C;
}

int func_80067AC4(void) {
    return func_80061348(0x143) == 0;
}

int func_80067AF8(void) {
    return D_80180648->work[0x11] >= 0x12C;
}

int func_80067B2C(void) {
    return D_80180648->work[0x11] >= 0x12C;
}

int func_80067B60(void) {
    return func_80061488(0x35) >= 2 && D_80180648->work[7] >= 0x64;
}

int func_80067BC4(void) {
    return func_80061488(0x35) >= 2;
}

int func_80067BFC(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80067C30(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80067C64(void) {
    return D_80180648->work[0xD] >= 0x12C;
}

int func_80067C98(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_80067CCC(void) {
    return D_80180648->work[0xA] >= 0x12C && D_80180648->work[5] >= 0x96 && D_80180648->work[6] >= 0x96;
}

int func_80067D3C(void) {
    return D_80180648->work[0xA] >= 0x12C;
}

int func_80067D70(void) {
    return D_80180648->work[0xA] >= 0x12C && D_80180648->work[0xB] >= 0x12C;
}

int func_80067DC4(void) {
    return D_80180648->work[0xA] >= 0x258 && D_80180648->work[0xB] >= 0x258;
}

int func_80067E18(void) {
    return D_80180648->work[0xA] >= 0x1F4 && D_80180648->work[0xB] >= 0x1F4;
}

int func_80067E6C(void) {
    return D_80180648->work[0xA] >= 0x190 && D_80180648->work[0xB] >= 0x190;
}

int func_80067EC0(void) {
    return D_80180648->work[0xA] >= 0x12C && D_80180648->work[0xB] >= 0x12C;
}

int func_80067F14(void) {
    return D_80180648->work[0xA] >= 0x258 && D_80180648->work[0xB] >= 0x258;
}

int func_80067F68(void) {
    return D_80180648->work[0xB] >= 0x12C && D_80180648->work[5] >= 0x12C && D_80180648->work[6] >= 0x12C;
}

int func_80067FD8(void) {
    return D_80180648->work[7] >= 0x12C;
}

int func_8006800C(void) {
    return D_80180648->work[0xB] >= 0x190 && D_80180648->work[5] >= 0x190 && D_80180648->work[6] >= 0x190;
}

int func_8006807C(void) {
    return D_80180648->work[7] >= 0x190;
}

int func_800680B0(void) {
    return D_80180648->work[0xB] >= 0x1F4 && D_80180648->work[5] >= 0x1F4 && D_80180648->work[6] >= 0x1F4;
}

int func_80068120(void) {
    return D_80180648->work[7] >= 0x1F4;
}

int func_80068154(void) {
    return D_80180648->work[0xB] >= 0x258 && D_80180648->work[5] >= 0x258 && D_80180648->work[6] >= 0x258;
}

int func_800681C4(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_800681F8(void) {
    return D_80180648->work[7] >= 0x258;
}

int func_8006822C(void) {
    return D_80180648->work[0xB] >= 0x190 && D_80180648->work[5] >= 0x190 && D_80180648->work[6] >= 0x190;
}

int func_8006829C(void) {
    return D_80180648->work[0xB] >= 0x1F4 && D_80180648->work[5] >= 0x1F4 && D_80180648->work[6] >= 0x1F4;
}

int func_8006830C(void) {
    return D_80180648->work[0xB] >= 0x258 && D_80180648->work[5] >= 0x258 && D_80180648->work[6] >= 0x258;
}

int func_8006837C(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_800683B0(void) {
    return D_80180648->work[0xA] >= 0x64 && D_80180648->work[0xB] >= 0x64;
}

int func_80068404(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_80068438(void) {
    return D_80180648->work[7] >= 0x64;
}

int func_8006846C(void) {
    return func_80061488(0x341) == 2;
}

int func_800684A4(void) {
    return func_80061488(0x341) >= 3;
}

int func_800684DC(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80068510(void) {
    return D_80180648->work[0xC] >= 0x64;
}

int func_80068544(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80068578(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_800685AC(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_800685E0(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80068614(void) {
    return D_80180648->work[0xD] < 0x12D;
}

int func_80068644(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_80068678(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_800686AC(void) {
    return func_80061488(0x64) >= 2;
}

int func_800686E4(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_80068718(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_8006874C(void) {
    return D_80180648->work[0xD] >= 0x12C;
}

int func_80068780(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_800687B4(void) {
    return D_80180648->work[0xD] >= 0x1F4;
}

int func_800687E8(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_8006881C(void) {
    return func_80061488(0x73) >= 2;
}

int func_80068854(void) {
    return D_80180648->work[0x19] >= 0x12C;
}

int func_80068888(void) {
    return D_80180648->work[0x19] >= 0x12C;
}

int func_800688BC(void) {
    return func_80061488(0x351) >= 3;
}

int func_800688F4(void) {
    return D_80180648->work[0xE] >= 0x12C;
}

int func_80068928(void) {
    return func_80061488(0x81) >= 2;
}

int func_80068960(void) {
    return D_80180648->work[8] < 0x12D;
}

int func_80068990(void) {
    return D_80180648->work[9] < 0x12D;
}

int func_800689C0(void) {
    return D_80180648->work[0x17] >= 0x2BC || D_80180648->work[2] >= 0x384;
}

int func_80068A14(void) {
    return func_80061488(0x93) >= 2;
}

int func_80068A4C(void) {
    return D_80180648->work[0x18] >= 0x2BC || D_80180648->work[2] >= 0x384;
}

int func_80068AA0(void) {
    return func_80061488(0xA9) >= 2;
}

int func_80068AD8(void) {
    return D_80180648->work[0x11] < 0x12D;
}

int func_80068B08(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_80068B3C(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_80068B70(void) {
    return !(func_80061348(0x707) == 2) && !(func_80061348(0x70B) == 2);
}

int func_80068BD0(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_80068C04(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_80068C38(void) {
    return func_80061488(0xC1) >= 2;
}

int func_80068C70(void) {
    return func_80061488(0x367) >= 2;
}

int func_80068CA8(void) {
    return D_80180648->work[0x12] < 0x12D;
}

int func_80068CD8(void) {
    return func_80061488(0xD5) >= 2;
}

int func_80068D10(void) {
    return D_80180648->work[0x13] < 0x12D;
}

int func_80068D40(void) {
    return func_80061488(0xED) >= 2;
}

int func_80068D78(void) {
    return D_80180648->work[0x14] < 0xC9;
}

int func_80068DA8(void) {
    return D_80180648->work[0x16] >= 0x64;
}

int func_80068DDC(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_80068E10(void) {
    return D_80180648->work[0x22] >= 0x3E7;
}

int func_80068E44(void) {
    return func_80061488(0xF6) >= 2;
}

int func_80068E7C(void) {
    return func_8005F064(0xA6) == 0;
}

int func_80068EB0(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80068EE4(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80068F18(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_80068F4C(void) {
    return D_80180648->work[2] < 0x385;
}

int func_80068F7C(void) {
    return D_80180648->work[2] < 0x385;
}

int func_80068FAC(void) {
    return func_80061488(0x390) >= 2;
}

int func_80068FE4(void) {
    return !(func_80061348(0x37E) == 0) && !(func_80061348(0x383) == 0);
}

int func_8006903C(void) {
    return !(func_80061348(0x37E) == 0) && !(func_80061348(0x383) == 0);
}

int func_80069094(void) {
    return func_80061348(0x377) == 0;
}

int func_800690C8(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_80069388(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_80069648(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_80069908(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_80069BC8(void) {
    return func_80061488(0x37D) >= 2;
}

int func_80069C00(void) {
    return !(func_80061348(0x377) == 0) && !(func_80061348(0x383) == 0);
}

int func_80069C58(void) {
    return func_80061488(0x3BD) >= 2;
}

int func_80069C90(void) {
    return !(func_80061348(0x377) == 0) && !(func_80061348(0x383) == 0);
}

int func_80069CE8(void) {
    return D_80180648->work[0x1C] == 0x3E7 && D_80180648->work[0] == 0x3E7;
}

int func_80069D3C(void) {
    return D_80180648->work[0x1C] == 0x3E7;
}

int func_80069D70(void) {
    return D_80180648->work[0x1D] == 0x3E7 && D_80180648->work[1] == 0x3E7;
}

int func_80069DC4(void) {
    return D_80180648->work[0x1D] == 0x3E7;
}

int func_80069DF8(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006A0B8(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006A378(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006A638(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006A8F8(void) {
    return func_80061488(0x382) >= 2;
}

int func_8006A930(void) {
    return !(func_80061348(0x377) == 0) && !(func_80061348(0x37E) == 0);
}

int func_8006A988(void) {
    return func_80061488(0x3BF) >= 2;
}

int func_8006A9C0(void) {
    return !(func_80061348(0x377) == 0) && !(func_80061348(0x37E) == 0);
}

int func_8006AA18(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006ACD8(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006AF98(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006B258(void) {
    return (((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1))) ||
            ((func_80061348(0x38B) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1))) ||
            (((func_80061348(0x38B) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x382) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x3BD) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (((func_80061348(0x75D) == 1) && (func_80061348(0x37D) == 1) && ((func_80061348(0x3BF) == 1)))) ||
            (func_80061348(0x75D) == 1 && func_80061348(0x3BD) == 1 && func_80061348(0x382) == 1));
}

int func_8006B518(void) {
    return D_80180648->work[0x17] < 0x2BD;
}

int func_8006B548(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006B57C(void) {

    return func_80061488(0x1FF) >= 3 && D_80180648->work[0x17] < 0x2BC;
}

int func_8006B5DC(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006B610(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006B644(void) {
    return func_80061348(0x1F9) == 0 && D_80180648->work[0x17] < 0x2BC;
}

int func_8006B6A0(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006B6D4(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_8006B708(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_8006B73C(void) {
    return func_80061488(0x1F9) >= 3;
}

int func_8006B774(void) {
    return func_80061488(0x202) >= 2;
}

int func_8006B7AC(void) {
    return func_80061488(0x201) >= 2;
}

int func_8006B7E4(void) {
    return func_80061488(0x204) >= 2;
}

int func_8006B81C(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006B850(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006B884(void) {
    return D_80180648->work[9] >= 0x32;
}

int func_8006B8B8(void) {
    return D_80180648->work[9] >= 0x32;
}

int func_8006B8EC(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006B920(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_8006B954(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006B988(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_8006B9BC(void) {
    return func_80061488(0x396) >= 5;
}

int func_8006B9F4(void) {
    return func_80061488(0x396) == 4;
}

int func_8006BA2C(void) {
    return func_80061488(0x396) >= 2;
}

int func_8006BA64(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_8006BA98(void) {
    return D_80180648->work[0x17] < 0x12C;
}

int func_8006BAC8(void) {
    return D_80180648->work[0x16] >= 0x1F4;
}

int func_8006BAFC(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006BB30(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006BB64(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006BB98(void) {
    return func_80061488(0x39A) >= 2;
}

int func_8006BBD0(void) {
    return func_80061488(0x39A) >= 2;
}

int func_8006BC08(void) {
    return func_80061488(0x66F) >= 2;
}

int func_8006BC40(void) {
    return func_8005F064(0x18);
}

int func_8006BC70(void) {
    return func_8005F064(0x21);
}

int func_8006BCA0(void) {
    return func_8005F064(0x41);
}

int func_8006BCD0(void) {
    return func_8005F064(0x1F);
}

int func_8006BD00(void) {
    return func_8005F064(0x1E);
}

int func_8006BD30(void) {
    return func_8005F064(0x1B);
}

int func_8006BD60(void) {
    return func_8005F064(0x32);
}

int func_8006BD90(void) {
    return func_8005F064(0x3B);
}

int func_8006BDC0(void) {
    return func_8005F064(0x3A);
}

int func_8006BDF0(void) {
    return func_8005F064(0xB2);
}

int func_8006BE20(void) {
    return func_8005F064(0x39);
}

int func_8006BE50(void) {
    return func_8005F064(0x38);
}

int func_8006BE80(void) {
    return func_8005F064(0xB1);
}

int func_8006BEB0(void) {
    return func_8005F064(0xB0);
}

int func_8006BEE0(void) {
    return func_8005F064(0x4D);
}

int func_8006BF10(void) {
    return func_8005F064(0x54);
}

int func_8006BF40(void) {
    return func_8005F064(0xB3);
}

int func_8006BF70(void) {
    return func_8005F064(0x53);
}

int func_8006BFA0(void) {
    return func_8005F064(0x11);
}

int func_8006BFD0(void) {
    return func_8005F064(0x2F);
}

int func_8006C000(void) {
    return func_8005F064(0x2E);
}

int func_8006C030(void) {
    return func_8005F064(0x2D);
}

int func_8006C060(void) {
    return func_8005F064(0xB5);
}

int func_8006C090(void) {
    return func_8005F064(0x2C);
}

int func_8006C0C0(void) {
    return func_8005F064(0xB4);
}

int func_8006C0F0(void) {
    return func_8005F064(0x45);
}

int func_8006C120(void) {
    return func_8005F064(0x4E);
}

int func_8006C150(void) {
    return func_8005F064(0x4D);
}

int func_8006C180(void) {
    return func_8005F064(0x4C);
}

int func_8006C1B0(void) {
    return func_8005F064(0x7F);
}

int func_8006C1E0(void) {
    return func_8005F064(0x4B);
}

int func_8006C210(void) {
    return func_8005F064(0x78);
}

int func_8006C240(void) {
    return func_8005F064(0x15);
}

int func_8006C270(void) {
    return func_8005F064(0x71);
}

int func_8006C2A0(void) {
    return func_8005F064(0xB7);
}

int func_8006C2D0(void) {
    return func_8005F064(0x14);
}

int func_8006C300(void) {
    return func_8005F064(0xB6);
}

int func_8006C330(void) {
    return func_8005F064(0x4B);
}

int func_8006C360(void) {
    return func_8005F064(0x7E);
}

int func_8006C390(void) {
    return func_8005F064(0x4C);
}

int func_8006C3C0(void) {
    return func_8005F064(0x7F);
}

int func_8006C3F0(void) {
    return func_8005F064(0x4B);
}

int func_8006C420(void) {
    return func_8005F064(0x4A);
}

int func_8006C450(void) {
    return func_8005F064(0x5B);
}

int func_8006C480(void) {
    return func_8005F064(0xB8);
}

int func_8006C4B0(void) {
    return func_8005F064(0x5D);
}

int func_8006C4E0(void) {
    return func_8005F064(0xBA);
}

int func_8006C510(void) {
    return func_8005F064(0x61);
}

int func_8006C540(void) {
    return func_8005F064(0x5C);
}

int func_8006C570(void) {
    return func_8005F064(0x5B);
}

int func_8006C5A0(void) {
    return func_8005F064(0xB9);
}

int func_8006C5D0(void) {
    return func_8005F064(0x19);
}

int func_8006C600(void) {
    return func_8005F064(0x60);
}

int func_8006C630(void) {
    return func_8005F064(0x5F);
}

int func_8006C660(void) {
    return func_8005F064(0x56);
}

int func_8006C690(void) {
    return func_8005F064(0xAF);
}

int func_8006C6C0(void) {
    return func_8005F064(0x70);
}

int func_8006C6F0(void) {
    return func_8005F064(0x6F);
}

int func_8006C720(void) {
    return func_8005F064(0x6D) != 0 && func_80061348(0x12E) == 0;
}

int func_8006C770(void) {
    return func_8005F064(0x6D) != 0 && func_80061348(0x121) == 0;
}

int func_8006C7C0(void) {
    return func_8005F064(0x6D);
}

int func_8006C7F0(void) {
    return func_8005F064(0x97);
}

int func_8006C820(void) {
    return func_8005F064(0xBB);
}

int func_8006C850(void) {
    return func_8005F064(0x40);
}

int func_8006C880(void) {
    return func_80061488(0x687) >= 2;
}

int func_8006C8B8(void) {
    return func_8005F064(0x72);
}

int func_8006C8E8(void) {
    return func_8005F064(0x23);
}

int func_8006C918(void) {
    return func_8005F064(0x29);
}

int func_8006C948(void) {
    return func_8005F064(0xBD);
}

int func_8006C978(void) {
    return func_8005F064(0x27);
}

int func_8006C9A8(void) {
    return func_8005F064(0x25);
}

int func_8006C9D8(void) {
    return func_8005F064(0x65);
}

int func_8006CA08(void) {
    return func_8005F064(0x69);
}

int func_8006CA38(void) {
    return func_8005F064(0xBF);
}

int func_8006CA68(void) {
    return func_8005F064(0x66);
}

int func_8006CA98(void) {
    return func_8005F064(0xBE);
}

int func_8006CAC8(void) {
    return func_8005F064(0x78);
}

int func_8006CAF8(void) {
    return func_8005F064(0x7B);
}

int func_8006CB28(void) {
    return func_8005F064(0x96);
}

int func_8006CB58(void) {
    return func_8005F064(0x7A);
}

int func_8006CB88(void) {
    return func_8005F064(0x9A);
}

int func_8006CBB8(void) {
    return func_80061488(0x480) >= 2;
}

int func_8006CBF0(void) {
    return func_80061488(0x480) >= 3;
}

int func_8006CC28(void) {
    return func_80061488(0x480) < 3;
}

int func_8006CC5C(void) {
    return func_80061488(0x482) >= 2;
}

int func_8006CC94(void) {
    return D_80180648->work[0xE] >= 0x12C && D_80180648->work[0xC] >= 0x12C;
}

int func_8006CCE8(void) {
    return D_80180648->work[3] >= 0x1F4;
}

int func_8006CD1C(void) {
    return D_80180648->work[5] >= 0x1F4 || D_80180648->work[6] >= 0x1F4;
}

int func_8006CD70(void) {
    return D_80180648->work[8] >= 0x1F4 || D_80180648->work[9] >= 0x1F4;
}

int func_8006CDC4(void) {
    return D_80180648->work[0xA] >= 0x12C || D_80180648->work[0xB] >= 0x12C;
}

int func_8006CE18(void) {
    return D_80180648->work[0xC] >= 0x1F4;
}

int func_8006CE4C(void) {
    return D_80180648->work[0xD] >= 0x1F4;
}

int func_8006CE80(void) {
    return D_80180648->work[0xE] >= 0x1F4;
}

int func_8006CEB4(void) {
    return D_80180648->work[0xF] >= 0x1F4;
}

int func_8006CEE8(void) {
    return D_80180648->work[0x10] >= 0x1F4;
}

int func_8006CF1C(void) {
    return D_80180648->work[0x11] >= 0x1F4;
}

int func_8006CF50(void) {
    return D_80180648->work[0x12] >= 0x1F4;
}

int func_8006CF84(void) {
    return D_80180648->work[0x13] >= 0x1F4;
}

int func_8006CFB8(void) {
    return D_80180648->work[0x14] >= 0x1F4;
}

int func_8006CFEC(void) {
    return D_80180648->work[0x15] >= 0x1F4;
}

int func_8006D020(void) {
    return D_80180648->work[9] >= 0x64;
}

int func_8006D054(void) {
    return D_80180648->work[0xB] >= 0x384;
}

int func_8006D088(void) {
    return D_80180648->work[0xB] >= 0x2BC;
}

int func_8006D0BC(void) {
    return D_80180648->work[0xB] >= 0x1F4;
}

int func_8006D0F0(void) {
    return D_80180648->work[0xB] >= 0x12C;
}

int func_8006D124(void) {
    return D_80180648->work[0xB] >= 0x384;
}

int func_8006D158(void) {
    return D_80180648->work[0x22] < 0x3E8;
}

int func_8006D188(void) {
    return D_80180648->work[0x16] >= 0x2BC;
}

int func_8006D1BC(void) {
    return func_8005F064(0xAC) == 0;
}

int func_8006D1F0(void) {
    return func_80061348(0x135) == 0;
}

int func_8006D224(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x135) == 0;
}

int func_8006D274(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x135) == 0;
}

int func_8006D2C4(void) {
    return func_80061348(0x12E) == 0;
}

int func_8006D2F8(void) {
    return func_80061348(0x121) == 0;
}

int func_8006D32C(void) {
    return func_80061348(0x135) == 0;
}

int func_8006D360(void) {
    return D_80180648->work[9] >= 0x64;
}

int func_8006D394(void) {
    return func_80061488(0x574) == 2;
}

int func_8006D3CC(void) {
    return func_80061488(0x574) >= 3;
}

int func_8006D404(void) {
    return D_80180648->work[9] < 0x97;
}

int func_8006D434(void) {
    return D_80180648->work[9] >= 0x64;
}

int func_8006D468(void) {
    return func_8005F064(0xAB);
}

int func_8006D498(void) {
    return D_80180648->work[9] >= 0x1F4 && D_80180648->work[0xF] >= 0x1F4 && !func_8005F064(0xCE);
}

int func_8006D514(void) {
    return (D_80180648->work[9] >= 0x12C) && (func_80061348(0x71B) == 1) ||
           (D_80180648->work[9] >= 0x12C && func_80061348(0x71C) == 1);
}

int func_8006D5BC(void) {
    return D_80180648->work[9] >= 0x12C;
}

int func_8006D5F0(void) {
    return D_80180648->work[9] >= 0xC8;
}

int func_8006D624(void) {
    return !(func_80061348(0x71D) == 0);
}

int func_8006D65C(void) {
    return func_80061348(0x57D) == 1;
}

int func_8006D694(void) {
    return D_80180648->work[0x10] >= 0x64;
}

int func_8006D6C8(void) {
    return D_80180648->work[0x16] >= 0x12C;
}

int func_8006D6FC(void) {
    return func_80061488(0x580) >= 2;
}

int func_8006D734(void) {
    return func_8005F064(1) == 0;
}

int func_8006D768(void) {
    return func_80061348(0x139) == 0 && func_80061348(0x13F) == 0 && func_80061348(0x142) == 0;
}

int func_8006D7D0(void) {
    return func_80061348(0x2C8) == 0;
}

int func_8006D804(void) {
    return D_80180648->work[3] >= 0x12C && D_80180648->work[4] >= 0x12C && func_8005F064(0xCF) != 0;
}

int func_8006D880(void) {
    return func_80061488(0x6E3) >= 2;
}

int func_8006D8B8(void) {
    return D_80180648->work[3] >= 0x2BC && D_80180648->work[4] >= 0x2BC;
}

int func_8006D90C(void) {
    return D_80180648->work[3] >= 0x2BC && D_80180648->work[4] >= 0x2BC;
}

int func_8006D960(void) {
    return D_80180648->work[3] >= 0x384 && D_80180648->work[4] >= 0x384 && func_8005F064(2) != 0;
}

int func_8006D9DC(void) {
    return D_80180648->work[3] >= 0x384 && D_80180648->work[4] >= 0x384 && func_8005F064(0xCD) != 0;
}

int func_8006DA58(void) {
    return func_8005F064(1);
}

int func_8006DA88(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x122) == 0 && func_80061348(0x13A) == 0;
}

int func_8006DAF0(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x122) == 0 && func_80061348(0x13E) == 0;
}

int func_8006DB58(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x134) == 0 && func_80061348(0x13A) == 0;
}

int func_8006DBC0(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x134) == 0 && func_80061348(0x13E) == 0;
}

int func_8006DC28(void) {
    return func_80061348(0x138) == 0 && func_80061348(0x13A) == 0;
}

int func_8006DC78(void) {
    return func_80061348(0x139) == 0 && func_80061348(0x13E) == 0;
}

int func_8006DCC8(void) {
    return func_80061348(0x13C) == 0 && func_80061348(0x13A) == 0;
}

int func_8006DD18(void) {
    return func_80061348(0x13F) == 0 && func_80061348(0x140) == 0;
}

int func_8006DD68(void) {
    return func_80061348(0x13D) == 0 && func_80061348(0x13A) == 0;
}

int func_8006DDB8(void) {
    return func_80061348(0x142) == 0 && func_80061348(0x140) == 0;
}

int func_8006DE08(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x122) == 0;
}

int func_8006DE58(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x122) == 0;
}

int func_8006DEA8(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x134) == 0;
}

int func_8006DEF8(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x134) == 0;
}

int func_8006DF48(void) {
    return func_80061348(0x138) == 0;
}

int func_8006DF7C(void) {
    return func_80061348(0x139) == 0;
}

int func_8006DFB0(void) {
    return func_80061348(0x13C) == 0;
}

int func_8006DFE4(void) {
    return func_80061348(0x13F) == 0;
}

int func_8006E018(void) {
    return func_80061348(0x13D) == 0;
}

int func_8006E04C(void) {
    return func_80061348(0x142) == 0;
}

int func_8006E080(void) {
    return func_80061348(0x121) == 0 && func_80061348(0x136) == 0;
}

int func_8006E0D0(void) {
    return func_80061348(0x12E) == 0 && func_80061348(0x136) == 0;
}

int func_8006E120(void) {
    return func_80061348(0x121) == 0;
}

int func_8006E154(void) {
    return func_80061348(0x12E) == 0;
}

int func_8006E188(void) {
    return (((func_80061348(0x121) == 0) && (func_80061348(0x122) == 0) && ((func_80061348(0x13A) == 0))) ||
            ((func_80061348(0x12E) == 0) && (func_80061348(0x122) == 0) && (func_80061348(0x13E) == 0)) ||
            ((func_80061348(0x121) == 0) && (func_80061348(0x134) == 0) && (func_80061348(0x13A) == 0)) ||
            ((func_80061348(0x12E) == 0) && (func_80061348(0x134) == 0) && (func_80061348(0x13E) == 0)) ||
            ((func_80061348(0x138) == 0) && (func_80061348(0x13A) == 0)) ||
            ((func_80061348(0x139) == 0) && (func_80061348(0x13E) == 0)) ||
            ((func_80061348(0x13C) == 0) && (func_80061348(0x13A) == 0)) ||
            ((func_80061348(0x13F) == 0) && (func_80061348(0x140) == 0)) ||
            ((func_80061348(0x13D) == 0) && (func_80061348(0x13A) == 0)) ||
            ((func_80061348(0x142) == 0) && (func_80061348(0x140) == 0)) ||
            ((func_80061348(0x121) == 0) && (func_80061348(0x122) == 0)) ||
            ((func_80061348(0x12E) == 0) && (func_80061348(0x122) == 0)) ||
            ((func_80061348(0x121) == 0) && (func_80061348(0x134) == 0)) ||
            ((func_80061348(0x12E) == 0) && (func_80061348(0x134) == 0)) ||
            (!(func_80061348(0x138)) || !(func_80061348(0x139)) || !(func_80061348(0x13C)) || !(func_80061348(0x13F)) ||
             !(func_80061348(0x13D)) || !(func_80061348(0x142))));
}

int func_8006E538(void) {
    return func_80061348(0x125) == 0 && func_80061348(0x12B) == 0;
}

int func_8006E588(void) {
    return func_80061348(0x125) == 0 && func_80061348(0x148) == 0;
}

int func_8006E5D8(void) {
    return func_80061348(0x125) == 0 && func_80061348(0x149) == 0;
}

int func_8006E628(void) {
    return func_80061348(0x125) == 0 && func_80061348(0x14A) == 0;
}

int func_8006E678(void) {
    return func_80061348(0x125) == 0 && func_80061348(0x14B) == 0;
}

int func_8006E6C8(void) {
    return (func_80061348(0x125) == 0) && func_80061348(0x14B) == 1;
}

int func_8006E71C(void) {
    return func_80061348(0x127) == 0 && func_80061348(0x14D) == 0;
}

int func_8006E76C(void) {
    return func_80061348(0x127) == 0 && func_80061348(0x2A8) == 0;
}

int func_8006E7BC(void) {
    return func_80061348(0x127) == 0 && func_80061348(0x15D) == 0;
}

int func_8006E80C(void) {
    return func_80061348(0x127) == 0 && func_80061348(0x161) == 0;
}

int func_8006E85C(void) {
    return func_80061348(0x127) == 0 && func_80061348(0x161) == 1;
}

int func_8006E8B0(void) {
    return func_80061348(0x127) == 1 && func_80061348(0x155) == 0;
}

int func_8006E904(void) {
    return func_80061348(0x127) == 1 && func_80061348(0x2C6) == 0;
}

int func_8006E958(void) {
    return func_80061348(0x127) == 1 && func_80061348(0x2C8) == 0;
}

int func_8006E9AC(void) {
    return func_80061348(0x127) == 1 && func_80061348(0x2C8) == 1;
}

int func_8006EA04(void) {
    return (((func_80061348(0x125) == 0) && (func_80061348(0x12B) == 0)) ||
            ((func_80061348(0x125) == 0) && (func_80061348(0x148) == 0)) ||
            ((func_80061348(0x125) == 0) && (func_80061348(0x149) == 0)) ||
            ((func_80061348(0x125) == 0) && (func_80061348(0x14A) == 0)) ||
            ((func_80061348(0x125) == 0) && (func_80061348(0x14B) == 0)) ||
            ((func_80061348(0x125) == 0) && (func_80061348(0x14B) == 1)) ||
            ((func_80061348(0x127) == 0) && (func_80061348(0x14D) == 0)) ||
            ((func_80061348(0x127) == 0) && (func_80061348(0x2A8) == 0)) ||
            ((func_80061348(0x127) == 0) && (func_80061348(0x15D) == 0)) ||
            ((func_80061348(0x127) == 0) && (func_80061348(0x161) == 0)) ||
            ((func_80061348(0x127) == 0) && (func_80061348(0x161) == 1)) ||
            ((func_80061348(0x127) == 1) && (func_80061348(0x155) == 0)) ||
            ((func_80061348(0x127) == 1) && (func_80061348(0x2C6) == 0)) ||
            ((func_80061348(0x127) == 1) && (func_80061348(0x2C8) == 0)) ||
            (func_80061348(0x127) == 1 && func_80061348(0x2C8) == 1));
}

int func_8006ED10(void) {
    return func_80061348(0x12C) == 0;
}

int func_8006ED44(void) {
    return func_80061348(0x143) == 0;
}

int func_8006ED78(void) {
    return func_80061348(0x145) == 0;
}

int func_8006EDAC(void) {
    return func_80061348(0x146) == 0;
}

int func_8006EDE0(void) {
    return func_80061348(0x253) == 0;
}

int func_8006EE14(void) {
    return func_80061348(0x253) == 1;
}

int func_8006EE4C(void) {
    return func_80061348(0x14E) == 0;
}

int func_8006EE80(void) {
    return func_80061348(0x14F) == 0;
}

int func_8006EEB4(void) {
    return func_80061348(0x152) == 0;
}

int func_8006EEE8(void) {
    return func_80061348(0x153) == 0;
}

int func_8006EF1C(void) {
    return func_80061348(0x147) == 0;
}

int func_8006EF50(void) {
    return func_80061348(0x2AD) == 0;
}

int func_8006EF84(void) {
    return func_80061348(0x2AD) == 1;
}

int func_8006EFBC(void) {
    return func_80061348(0x156) == 0;
}

int func_8006EFF0(void) {
    return func_80061348(0x158) == 0 || func_80061348(0x158) == 1;
}

int func_8006F044(void) {
    return func_80061348(0x2B1) == 0;
}

int func_8006F078(void) {
    return func_80061348(0x2B5) == 0;
}

int func_8006F0AC(void) {
    return func_80061348(0x2B8) == 0;
}

int func_8006F0E0(void) {
    return func_80061348(0x2BB) == 0;
}

int func_8006F114(void) {
    return func_80061348(0x2BE) == 0;
}

int func_8006F148(void) {
    return func_80061348(0x2BE) == 1;
}

int func_8006F180(void) {
    return func_80061348(0x2CD) == 0;
}

int func_8006F1B4(void) {
    return func_80061348(0x2CD) == 1;
}

int func_8006F1EC(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006F220(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006F254(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006F288(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006F2BC(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006F2F0(void) {
    return D_80180648->work[0x17] >= 0x1F4;
}

int func_8006F324(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006F358(void) {
    return D_80180648->work[0x17] >= 0x12C && D_80180648->work[0x17] < 0x2BC;
}

int func_8006F3A8(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_8006F3DC(void) {
    return D_80180648->work[0x17] < 0x12C;
}

int func_8006F40C(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006F440(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_8006F474(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006F4A8(void) {
    return D_80180648->work[7] < 0x1F5 && func_80061488(0x575) >= 2;
}

int func_8006F508(void) {
    return D_80180648->work[7] < 0x1F5;
}

int func_8006F538(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006F56C(void) {
    return D_80180648->work[0x17] < 0x385;
}

int func_8006F59C(void) {
    return func_80061488(0x3BB) >= 2;
}

int func_8006F5D4(void) {
    return D_80180648->work[0x18] >= 0x1F4 || D_80180648->work[0x19] >= 0x1F4 || D_80180648->work[0x1A] >= 0x1F4 ||
           D_80180648->work[0x1B] >= 0x1F4;
}

int func_8006F660(void) {
    return D_80180648->work[0x18] >= 0x1F4;
}

int func_8006F694(void) {
    return D_80180648->work[0x19] >= 0x1F4;
}

int func_8006F6C8(void) {
    return D_80180648->work[0x1A] >= 0x1F4;
}

int func_8006F6FC(void) {
    return D_80180648->work[0x1B] >= 0x1F4;
}

int func_8006F730(void) {
    return func_8005F064(0x9B);
}

int func_8006F760(void) {
    return func_80061488(0x3C8) >= 2;
}

int func_8006F798(void) {
    return D_80180648->work[0x17] < 0x1F5;
}

int func_8006F7C8(void) {
    return func_80061488(0x3D3) >= 2;
}

int func_8006F800(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8006F834(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006F8C4(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006F954(void) {
    return D_80180648->work[7] >= 0x1F4 && D_80180648->work[0xF] >= 0x1F4;
}

int func_8006F9A8(void) {
    return func_80061348(0x3D4) == 1;
}

int func_8006F9E0(void) {
    return func_80061348(0x3D4) == 1;
}

int func_8006FA18(void) {
    return func_80061348(0x3D4) == 1;
}

int func_8006FA50(void) {
    return func_80061488(0x3D6) == 1;
}

int func_8006FA88(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006FB18(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006FBA8(void) {
    return D_80180648->work[0x17] >= 0x12C;
}

int func_8006FBDC(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006FC6C(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006FCFC(void) {
    return func_80061488(0x3DD) >= 0xA;
}

int func_8006FD34(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006FDC4(void) {
    return func_80061348(0x3D4) == 1 && func_80061348(0x3D6) == 1 && func_80061348(0x3D0) == 1 &&
           func_80061348(0x3E7) == 1;
}

int func_8006FE54(void) {
    return func_80061348(0x3D7) == 0 || func_80061348(0x3DC) == 1;
}

int func_8006FEA8(void) {
    return D_80180648->work[0x17] < 0x2BD;
}

int func_8006FED8(void) {
    return func_80061348(0x3D7) == 0 || func_80061348(0x3DC) == 1;
}

int func_8006FF2C(void) {
    return func_80061348(0x3D7) == 0 || func_80061348(0x3DC) == 1;
}

int func_8006FF80(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_8006FFB4(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_8006FFE8(void) {
    return func_80061348(0x420) == 0;
}

int func_8007001C(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800700A4(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_8007012C(void) {
    return func_80061348(0x420) == 0;
}

int func_80070160(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800701E8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070270(void) {
    return func_80061488(0x423) >= 2;
}

int func_800702A8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070330(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800703B8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070440(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800704C8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070550(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800705D8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070660(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800706E8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070770(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_800707F8(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070880(void) {
    return func_80061348(0x420) == 0 && func_80061348(0x425) == 0 && func_80061348(0x41B) == 1 &&
           func_80061348(0x427) == 1;
}

int func_80070908(void) {
    return func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070998(void) {
    return func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070A28(void) {
    return func_80061348(0x436) == 1;
}

int func_80070A60(void) {
    return func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070AF0(void) {
    return func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070B80(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80070BB4(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80070BE8(void) {
    return func_80061348(0x52F) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070C78(void) {
    return func_80061348(0x52F) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070D08(void) {
    return func_80061348(0x52F) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070D98(void) {
    return func_80061348(0x52F) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070E28(void) {
    return D_80180648->work[7] >= 0x1F4 && D_80180648->work[0xF] >= 0x1F4;
}

int func_80070E7C(void) {
    return D_80180648->work[7] >= 0x1F4 && D_80180648->work[0xF] >= 0x1F4;
}

int func_80070ED0(void) {
    return func_80061348(0x42E) == 1 && func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070F60(void) {
    return func_80061348(0x42E) == 1 && func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80070FF0(void) {
    return func_80061348(0x42E) == 1 && func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80071080(void) {
    return func_80061348(0x42E) == 1 && func_80061348(0x436) == 1 && func_80061348(0x52F) == 1 &&
           func_80061348(0x4B9) == 1;
}

int func_80071110(void) {
    return func_80061348(0x4B9) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x52F) == 1;
}

int func_800711A0(void) {
    return func_80061348(0x4B9) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x52F) == 1;
}

int func_80071230(void) {
    return func_80061348(0x4B9) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x52F) == 1;
}

int func_800712C0(void) {
    return func_80061348(0x4B9) == 1 && func_80061348(0x436) == 1 && func_80061348(0x42E) == 1 &&
           func_80061348(0x52F) == 1;
}

int func_80071350(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_800713E0(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_80071470(void) {
    return D_80180648->work[5] >= 0x384;
}

int func_800714A4(void) {
    return D_80180648->work[5] >= 0x2BC;
}

int func_800714D8(void) {
    return D_80180648->work[5] >= 0x384;
}

int func_8007150C(void) {
    return func_80061348(0x43D) == 0;
}

int func_80071540(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80071574(void) {
    return D_80180648->work[0xD] >= 0x64;
}

int func_800715A8(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800715DC(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_8007166C(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_800716FC(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80071730(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80071764(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_800717F4(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_80071884(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_80071914(void) {
    return func_80061348(0x438) == 1 && func_80061348(0x43D) == 1 && func_80061348(0x4BA) == 1 &&
           func_80061348(0x4BB) == 1;
}

int func_800719A4(void) {
    return func_8005F064(0xBB);
}

int func_800719D4(void) {
    return func_80061348(0x440) == 1;
}

int func_80071A0C(void) {
    return func_80061348(0x43E) == 1 && func_80061348(0x444) == 1;
}

int func_80071A64(void) {
    return func_80061348(0x43E) == 1 && func_80061348(0x444) == 1;
}

int func_80071ABC(void) {
    return func_80061348(0x441) == 1 && func_80061348(0x531) == 1 && func_80061348(0x4BC) == 1;
    ;
}

int func_80071B30(void) {
    return func_80061348(0x441) == 1 && func_80061348(0x531) == 1 && func_80061348(0x4BC) == 1;
    ;
}

int func_80071BA4(void) {
    return func_80061348(0x43E) == 1 && func_80061348(0x444) == 1;
}

int func_80071BFC(void) {
    return func_80061348(0x43E) == 1 && func_80061348(0x444) == 1;
}

int func_80071C54(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80071C88(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80071CBC(void) {
    return func_80061348(0x441) == 1 && func_80061348(0x531) == 1 && func_80061348(0x4BC) == 1;
    ;
}

int func_80071D30(void) {
    return func_80061348(0x441) == 1 && func_80061348(0x531) == 1 && func_80061348(0x4BC) == 1;
    ;
}

int func_80071DA4(void) {
    return func_80061348(0x441) == 1 && func_80061348(0x531) == 1 && func_80061348(0x4BC) == 1;
    ;
}

int func_80071E18(void) {
    return func_80061348(0x441) == 1 && func_80061348(0x531) == 1 && func_80061348(0x4BC) == 1;
    ;
}

int func_80071E8C(void) {
    return D_80180648->work[8] < 0xC9 && D_80180648->work[9] < 0xC9;
    ;
}

int func_80071ED8(void) {
    return func_80061348(0x440) == 1 && func_80061348(0x447) == 1;
}

int func_80071F30(void) {
    return D_80180648->work[9] < 0xC9;
}

int func_80071F60(void) {
    return D_80180648->work[9] < 0xC9;
}

int func_80071F90(void) {
    return D_80180648->work[9] < 0xC9;
}

int func_80071FC0(void) {
    return D_80180648->work[9] < 0xC9;
}

int func_80071FF0(void) {
    return D_80180648->work[9] < 0xC9;
}

int func_80072020(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80072054(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80072088(void) {
    return func_80061348(0x44B) == 1 && func_80061348(0x4BE) == 1 && func_80061348(0x4BD) == 1;
}

int func_800720FC(void) {
    return func_80061348(0x44B) == 1 && func_80061348(0x4BE) == 1 && func_80061348(0x4BD) == 1;
}

int func_80072170(void) {
    return func_80061348(0x44B) == 1 && func_80061348(0x4BE) == 1 && func_80061348(0x4BD) == 1;
}

int func_800721E4(void) {
    return func_80061348(0x44B) == 1 && func_80061348(0x4BE) == 1 && func_80061348(0x4BD) == 1;
}

int func_80072258(void) {
    return func_80061348(0x44B) == 1 && func_80061348(0x4BE) == 1 && func_80061348(0x4BD) == 1;
}

int func_800722CC(void) {
    return func_80061348(0x44B) == 1 && func_80061348(0x4BE) == 1 && func_80061348(0x4BD) == 1;
}

int func_80072340(void) {
    return func_80061488(0x44C) == 2;
}

int func_80072378(void) {
    return func_80061488(0x44C) >= 3;
}

int func_800723B0(void) {
    return func_80061488(0x44C) >= 2;
}

int func_800723E8(void) {
    return func_80061488(0x44C) >= 2;
}

int func_80072420(void) {
    return D_80180648->work[1] >= 0xE6;
}

int func_80072454(void) {
    return func_80061488(0x51C) == 2;
}

int func_8007248C(void) {
    return func_80061488(0x51C) >= 3;
}

int func_800724C4(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800724F8(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_8007252C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80072560(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80072594(void) {
    return D_80180648->work[0x17] >= 0x320 && D_80180648->work[0x19] >= 0x2BC;
}

int func_800725E8(void) {
    return func_80061488(0x50D) >= 2;
}

int func_80072620(void) {
    return D_80180648->work[1] >= 0x14A;
}

int func_80072654(void) {
    return func_80061488(0x519) == 1;
}

int func_8007268C(void) {
    return func_80061488(0x519) == 1;
}

int func_800726C4(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800726F8(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8007272C(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80072760(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80072794(void) {
    return func_80061488(0x50E) == 0;
}

int func_800727C8(void) {
    return func_80061488(0x50E) > 0;
}

int func_800727FC(void) {
    return func_80061348(0x50E) == 1;
}

int func_80072834(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072868(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_8007289C(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_800728D0(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80072904(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072938(void) {
    return D_80180648->work[8] >= 0x2BC;
}

int func_8007296C(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_800729A0(void) {
    return D_80180648->work[8] >= 0x320;
}

int func_800729D4(void) {
    return func_80061488(0x523) >= 2;
}

int func_80072A0C(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072A40(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80072A74(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80072AA8(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80072ADC(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80072B10(void) {
    return D_80180648->work[8] >= 0x2BC;
}

int func_80072B44(void) {
    return D_80180648->work[8] >= 0x2BC;
}

int func_80072B78(void) {
    return D_80180648->work[8] >= 0x320;
}

int func_80072BAC(void) {
    return D_80180648->work[8] >= 0x320;
}

int func_80072BE0(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80072C14(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80072C48(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80072C7C(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80072CB0(void) {
    return func_80061488(0x50F) >= 2;
}

int func_80072CE8(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072D1C(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072D50(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80072D84(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072DB8(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80072DEC(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072E20(void) {
    return D_80180648->work[8] >= 0x2BC;
}

int func_80072E54(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072E88(void) {
    return D_80180648->work[8] >= 0x320;
}

int func_80072EBC(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80072EF0(void) {
    return func_8005F064(0x19);
}

int func_80072F20(void) {
    return func_8005F064(0x19);
}

int func_80072F50(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80072F84(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80072FB8(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80072FEC(void) {
    return D_80180648->work[8] >= 0x258;
}

int func_80073020(void) {
    return D_80180648->work[8] >= 0x2BC;
}

int func_80073054(void) {
    return D_80180648->work[8] >= 0x2BC;
}

int func_80073088(void) {
    return D_80180648->work[8] >= 0x320;
}

int func_800730BC(void) {
    return D_80180648->work[8] >= 0x320;
}

int func_800730F0(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073124(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073158(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8007318C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800731C0(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800731F4(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80073228(void) {
    return D_80180648->work[1] >= 0x1AE;
}

int func_8007325C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073290(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800732C4(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800732F8(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_8007332C(void) {
    return func_80061488(0x518) > 0;
}

int func_80073360(void) {
    return !func_8005F064(0x5F) || !func_80061488(0x644);
}

int func_800733B0(void) {
    return !func_8005F064(0x60) || !func_80061488(0x63E);
}

int func_80073400(void) {
    return func_80061488(0x63E) == 1;
}

int func_80073438(void) {
    return func_80061488(0x640) >= 2;
}

int func_80073470(void) {
    return !func_8005F064(0x61) || !func_80061488(0x63F);
}

int func_800734C0(void) {
    return func_80061488(0x63F) == 1;
}

int func_800734F8(void) {
    return func_8005F064(0x88);
}

int func_80073528(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_8007355C(void) {
    return func_80061488(0x641) == 1;
}

int func_80073594(void) {
    return func_8005F064(0x88) == 0;
}

int func_800735C8(void) {
    return func_80061488(0x643) == 1;
}

int func_80073600(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80073634(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073668(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8007369C(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800736D0(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80073704(void) {
    return func_80061488(0x6CA) == 0;
}

int func_80073738(void) {
    return D_80180648->work[8] >= 0x12C && D_80180648->work[8] < 0x1F4;
}

int func_80073788(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_800737BC(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_800737F0(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_80073824(void) {
    return func_80061488(0x538) >= 2;
}

int func_8007385C(void) {
    return D_80180648->work[1] >= 0x14A;
}

int func_80073890(void) {
    return func_80061488(0x456) >= 2;
}

int func_800738C8(void) {
    return func_80061488(0x456) < 6 || !(func_80061348(0x456) == 0);
}

int func_8007391C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073950(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073984(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800739B8(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800739EC(void) {
    return func_80061488(0x456) == 2;
}

int func_80073A24(void) {
    return func_80061488(0x456) == 3;
}

int func_80073A5C(void) {
    return func_80061488(0x456) == 4;
}

int func_80073A94(void) {
    return func_80061488(0x456) == 5;
}

int func_80073ACC(void) {
    return func_80061488(0x456) >= 6;
}

int func_80073B04(void) {
    return !(func_80061348(0x558) == 0);
}

int func_80073B3C(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073BCC(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073C5C(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073CEC(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073D7C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073DB0(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80073DE4(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073E74(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073F04(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80073F94(void) {
    return func_80061348(0x456) == 1 && func_80061348(0x4D3) == 1 && func_80061348(0x4D4) == 1 &&
           func_80061348(0x4D5) == 1;
}

int func_80074024(void) {
    return func_80061348(0x457) == 1;
}

int func_8007405C(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_800740B4(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_8007410C(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_80074164(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_800741BC(void) {
    return func_80061348(0x458) == 1;
}

int func_800741F4(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_8007424C(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_800742A4(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_800742FC(void) {
    return func_80061348(0x457) == 1 && func_80061348(0x458) == 1;
}

int func_80074354(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_800743E4(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_80074474(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800744A8(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800744DC(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_8007456C(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_800745FC(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_8007468C(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_8007471C(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_800747AC(void) {
    return func_80061348(0x4D7) == 1 && func_80061348(0x4D8) == 1 && func_80061348(0x4D9) == 1 &&
           func_80061348(0x4DA) == 1;
}

int func_8007483C(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_800748CC(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_8007495C(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_800749EC(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_80074A7C(void) {
    return D_80180648->work[3] >= 0x384 || D_80180648->work[4] >= 0x384;
}

int func_80074AD0(void) {
    return func_80061488(0x628) >= 2;
}

int func_80074B08(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_80074B98(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_80074C28(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_80074CB8(void) {
    return func_80061348(0x4DB) == 1 && func_80061348(0x459) == 1 && func_80061348(0x4DD) == 1 &&
           func_80061348(0x4DE) == 1;
}

int func_80074D48(void) {
    return D_80180648->work[0x14] >= 0x1F4;
}

int func_80074D7C(void) {
    return D_80180648->work[0x14] >= 0x12C;
}

int func_80074DB0(void) {
    return func_80061488(0x45A) >= 2;
}

int func_80074DE8(void) {
    return D_80180648->work[0x14] < 0x2BD;
}

int func_80074E18(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_80074EA8(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_80074F38(void) {
    return func_80061348(0x125) == 0;
}

int func_80074F6C(void) {
    return !func_80061348(0x14D) || !func_80061348(0x2A8);
}

int func_80074FBC(void) {
    return func_80061348(0x125) == 0;
}

int func_80074FF0(void) {
    return !func_80061348(0x14D) || !func_80061348(0x2A8);
}

int func_80075040(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80075074(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800750A8(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_80075138(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_800751C8(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_80075258(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_800752E8(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_80075378(void) {
    return func_80061348(0x45A) == 1 && func_80061348(0x4DF) == 1 && func_80061348(0x4E0) == 1 &&
           func_80061348(0x4E1) == 1;
}

int func_80075408(void) {
    return D_80180648->work[9] >= 0x12C && D_80180648->work[15] >= 0x12C && !func_8005F064(0xCE);
}

int func_80075484(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_800754B8(void) {
    return D_80180648->work[9] >= 0x1F4 && D_80180648->work[15] >= 0x1F4 && !func_8005F064(0xCE);
}

int func_80075534(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80075568(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8007559C(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800755D0(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80075604(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_80075694(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_80075724(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80075758(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8007578C(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_8007581C(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_800758AC(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800758E0(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80075914(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_800759A4(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_80075A34(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_80075AC4(void) {
    return func_80061348(0x45D) == 1 && func_80061348(0x4E5) == 1 && func_80061348(0x4E6) == 1 &&
           func_80061348(0x4E7) == 1;
}

int func_80075B54(void) {
    return func_80061348(0x45C) == 1;
}

int func_80075B8C(void) {
    return func_8005F064(0x48) == 0;
}

int func_80075BC0(void) {
    return func_80061488(0x464) < 4;
}

int func_80075BF4(void) {
    return func_80061488(0x469) >= 3;
}

int func_80075C2C(void) {
    return func_80061488(0x468) >= 3;
}

int func_80075C64(void) {
    return func_80061488(0x469) >= 3;
}

int func_80075C9C(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80075CD0(void) {
    return func_80061488(0x62D) > 0;
}

int func_80075D04(void) {
    return func_80061488(0x62D) > 0;
}

int func_80075D38(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80075DC8(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80075E58(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80075E8C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80075EC0(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80075F50(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80075FE0(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80076070(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80076100(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80076190(void) {
    return func_80061348(0x46B) == 1 && func_80061348(0x4E8) == 1 && func_80061348(0x4E9) == 1 &&
           func_80061348(0x4EA) == 1;
}

int func_80076220(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80076254(void) {
    return D_80180648->work[0x17] >= 0x2BC;
}

int func_80076288(void) {
    return func_8005F064(0xA7) && func_8005F064(0xA8) && func_8005F064(0xA9) && func_8005F064(0xAB);
}

int func_80076308(void) {
    return func_80061488(0x514) >= 2;
}

int func_80076340(void) {
    return D_80180648->work[1] >= 0x82;
}

int func_80076374(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800763A8(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800763DC(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80076410(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80076444(void) {
    return func_80061488(0x515) >= 2;
}

int func_8007647C(void) {
    return D_80180648->work[1] >= 0xE6;
}

int func_800764B0(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_800764E4(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076518(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_8007654C(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_80076580(void) {
    return func_80061488(0x46F) >= 2;
}

int func_800765B8(void) {
    return func_8005F064(0xA);
}

int func_800765E8(void) {
    return D_80180648->work[1] >= 0xE6;
}

int func_8007661C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076650(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076684(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800766B8(void) {
    return D_80180648->work[7] >= 0x2BD;
}

int func_800766EC(void) {
    return func_80061348(0x473) == 1 && func_80061348(0x4F4) == 1 && func_80061348(0x4F5) == 1;
}

int func_80076760(void) {
    return func_80061348(0x473) == 1 && func_80061348(0x4F4) == 1 && func_80061348(0x4F5) == 1;
}

int func_800767D4(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076808(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_8007683C(void) {
    return func_80061348(0x473) == 1 && func_80061348(0x4F4) == 1 && func_80061348(0x4F5) == 1;
}

int func_800768B0(void) {
    return func_80061348(0x473) == 1 && func_80061348(0x4F4) == 1 && func_80061348(0x4F5) == 1;
}

int func_80076924(void) {
    return func_80061348(0x473) == 1 && func_80061348(0x4F4) == 1 && func_80061348(0x4F5) == 1;
}

int func_80076998(void) {
    return func_80061348(0x473) == 1 && func_80061348(0x4F4) == 1 && func_80061348(0x4F5) == 1;
}

int func_80076A0C(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076A40(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076A74(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076AA8(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076ADC(void) {
    return func_80061488(0x477) >= 2;
}

int func_80076B14(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076B48(void) {
    return D_80180648->work[6] >= 0x2BD;
}

int func_80076B7C(void) {
    return func_80061488(0x4F7) >= 2;
}

int func_80076BB4(void) {
    return D_80180648->work[0x17] < 0x1F5;
}

int func_80076BE4(void) {
    return D_80180648->work[0x17] < 0x1F5;
}

int func_80076C14(void) {
    return D_80180648->work[0x17] < 0x1F5;
}

int func_80076C44(void) {
    return D_80180648->work[0x17] < 0x1F5;
}

int func_80076C74(void) {
    return D_80180648->work[0x14] >= 0x1F4;
}

int func_80076CA8(void) {
    return D_80180648->work[0x14] >= 0x1F4;
}

int func_80076CDC(void) {
    return func_80061488(0x551) >= 2;
}

int func_80076D14(void) {
    return func_80061488(0x54C) == 0;
}

int func_80076D48(void) {
    return !(func_80061348(0x552) == 0);
}

int func_80076D80(void) {
    return !(func_80061348(0x553) == 0);
}

int func_80076DB8(void) {
    return func_80061488(0x54F) >= 2;
}

int func_80076DF0(void) {
    return !func_80061348(0x43F) && func_8005F064(0xBB);
}

int func_80076E40(void) {
    return func_80061488(0x653) >= 2;
}

int func_80076E78(void) {
    return func_80061488(0x653) == 1;
}

int func_80076EB0(void) {
    return func_80061488(0x653) == 1;
}

int func_80076EE8(void) {
    return func_80061488(0x653) == 1;
}

int func_80076F20(void) {
    return func_80061488(0x653) == 1;
}

int func_80076F58(void) {
    return func_80061488(0x653) == 1;
}

int func_80076F90(void) {
    return func_80061488(0x492) >= 2;
}

int func_80076FC8(void) {
    return func_80061348(0x457) == 0;
}

int func_80076FFC(void) {
    return func_80061488(0x557) >= 2;
}

int func_80077034(void) {
    return !(func_80061348(0x494) == 1);
}

int func_80077070(void) {
    return func_8005F064(0x3A);
}

int func_800770A0(void) {
    return func_8005F064(0x39);
}

int func_800770D0(void) {
    return D_80180648->work[7] >= 0x12C;
}

int func_80077104(void) {
    return func_80061488(0x55C) >= 3;
}

int func_8007713C(void) {
    return func_80061488(0x55C) == 2;
}

int func_80077174(void) {
    return D_80180648->work[7] >= 0x12C;
}

int func_800771A8(void) {
    return D_80180648->work[8] >= 0x1F4;
}

int func_800771DC(void) {
    return func_80061488(0x651) >= 3;
}

int func_80077214(void) {
    return func_80061488(0x651) >= 3;
}

int func_8007724C(void) {
    return func_80061488(0x651) >= 3;
}

int func_80077284(void) {
    return func_80061488(0x55D) >= 3 && D_80180648->work[0x18] >= 0x2BC;
}

int func_800772E8(void) {
    return func_80061488(0x55D) >= 3 && D_80180648->work[0x19] >= 0x2BC;
}

int func_8007734C(void) {
    return func_80061488(0x55D) >= 3 && D_80180648->work[0x1A] >= 0x2BC;
}

int func_800773B0(void) {
    return func_80061488(0x55D) >= 3 && D_80180648->work[0x1B] >= 0x2BC;
}

int func_80077414(void) {
    return func_80061488(0x55D) >= 3;
}

int func_8007744C(void) {
    return func_80061488(0x55D) == 2;
}

int func_80077484(void) {
    return func_80061348(0x493) == 0;
}

int func_800774B8(void) {
    return func_80061348(0x6B0) == 1;
}

int func_800774F0(void) {
    return func_80061488(0x496) == 1;
}

int func_80077528(void) {
    return D_80180648->work[0xD] >= 0x2BC;
}

int func_8007755C(void) {
    return D_80180648->work[0xC] >= 0x2BC;
}

int func_80077590(void) {
    return D_80180648->work[0xD] >= 0x2BC;
}

int func_800775C4(void) {
    return D_80180648->work[0xC] >= 0x2BC;
}

int func_800775F8(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_8007762C(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80077660(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_80077694(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_800776C8(void) {
    return func_80061488(0x6CE) == 0;
}

int func_800776FC(void) {
    return func_80061488(0x6CE) == 0;
}

int func_80077730(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_80077764(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80077798(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_800777CC(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_80077800(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_80077834(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80077868(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_8007789C(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_800778D0(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_80077904(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80077938(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_8007796C(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_800779A0(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_800779D4(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80077A08(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_80077A3C(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_80077A70(void) {
    return (D_80180648->work[0] < 0x65) || D_80180648->work[1] < 0x65;
}

int func_80077ABC(void) {
    return !(func_80061348(0x5C7) == 0);
}

int func_80077AF4(void) {
    return func_80061488(0x56A) >= 2;
}

int func_80077B2C(void) {
    return func_80061488(0x56E) >= 2;
}

int func_80077B64(void) {
    return func_80061488(0x5B2) >= 2;
}

int func_80077B9C(void) {
    return D_80180648->work[0x10] >= 0xC8;
}

int func_80077BD0(void) {
    return D_80180648->work[0xF] >= 0xC8;
}

int func_80077C04(void) {
    return D_80180648->work[8] >= 0xC8;
}

int func_80077C38(void) {
    return func_80061488(0x5F5) == 1;
}

int func_80077C70(void) {
    return func_80061348(0x558) == 0;
}

int func_80077CA4(void) {
    return D_80180648->work[7] >= 0x1F4;
}

int func_80077CD8(void) {
    return func_80061488(0x561) >= 3;
}

int func_80077D10(void) {
    return D_80180648->work[0x10] < 0xC9;
}

int func_80077D40(void) {
    return D_80180648->work[0xF] < 0xC9;
}

int func_80077D70(void) {
    return D_80180648->work[8] < 0xC9;
}

int func_80077DA0(void) {
    return func_8005F064(0x99) && func_8005F064(0x19);
}

int func_80077DF0(void) {
    return func_8005F064(0x99) && func_8005F064(0x19);
}

int func_80077E40(void) {
    return func_8005F064(0x99) && func_8005F064(0x19);
}

int func_80077E90(void) {
    return func_8005F064(0x99) && func_8005F064(0x19);
}

int func_80077EE0(void) {
    return D_80180648->work[0x18] >= 0x2BC;
}

int func_80077F14(void) {
    return D_80180648->work[0x19] >= 0x2BC;
}

int func_80077F48(void) {
    return D_80180648->work[0x1A] >= 0x2BC;
}

int func_80077F7C(void) {
    return D_80180648->work[0x1B] >= 0x2BC;
}

int func_80077FB0(void) {
    return func_8005F064(0x99) == 0;
}
