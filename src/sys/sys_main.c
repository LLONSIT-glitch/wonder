#include "common.h"

// UNK_TYPE func_80000C90(void*);

extern s32 D_8015C748[];
s32 func_80000C90(ThreadEntry* entry);
void func_80016620(f32*);
void func_80021F20(s32);

extern s16 D_801A7248;
extern s16 D_801A7274;
extern s16 D_801A7280;
extern s16 D_801A728C;

extern FuncPtr D_800DDB74[][2];
extern UnkStruct_80156DC0 D_80156DC0[];
extern UnkStruct_80156DC0 D_80156C20[];

void* SysMain(ThreadEntry* entry) {
    s32 sp1DC;
    char pad[0x184];
    ThreadEntry* threadEntry;
    UnkStruct_800F9C38* sp50;
    s32 pad2[4];

    threadEntry = entry;
    gSysThreadIds[0] = (s32) threadEntry->threadId;
    sp50 = threadEntry->unk18;
    func_800983B0(0, 1);
    func_800AD800();
    func_800984B4();
    func_800985BC(threadEntry->threadId);
    sp50 = threadEntry->unk18;
    sp50->unk80BC = 2;
    sp50->unk80DC = 2;
    gFrameBuffer1[0] = gFrameBuffer1[1] = gFrameBuffer1[2] = gFrameBuffer1[3] = 0;
    SysMem_Copy64(&gFrameBuffer1[4], &gFrameBuffer1, 0x4AFF);
    osViSwapBuffer(&gFrameBuffer1);
    SysMem_Copy64(&D_801DA800, &gFrameBuffer1, 0x4B00);
    func_8008E5A0();
    func_800B8A2C();

    gSpriteObjHeaderSegment = SpriteSeg1_ROM_START;
    gSpriteSeg1VramStart = SpriteSeg1_VRAM;

    D_80153E2C = &D_492860;
    D_801540D8 = &D_807A0080;

    D_801560E0 = &D_69A970;
    D_801560E8 = &D_809A8190;

    D_801849C0 = &D_80947340;
    D_801829B8 = &D_639B20;

    D_8015FB78 = &D_6E3A40;
    D_8015FB80 = &D_809F1260;
    
    D_800F193C = SysMem_GetPhysicalAddressFromVirtual(D_80153E2C, D_801540D8, &D_807A1A20);
    D_80153DB0 = SysMem_GetPhysicalAddressFromVirtual(D_801560E0, D_801560E8, &D_809A8230);
    func_800B1A50(SpriteSeg1_VRAM, &D_80409B40, &D_8040A9A0, &D_80412A40, &D_804412E0, &D_8044AB00, &D_8078D1C0,
                  &D_807991C0, &D_8079A730, 3);
    D_8015B334 = 5;
    D_8015B33C = 0xC8;
    D_801825D8 = D_800ED130;
    D_801825D0 = 90.0f;
    D_801825A0 = D_801825D0;
    D_801825A8 = (f32) D_8015B334;
    D_801825B0 = (f32) D_8015B33C;
    D_801825B8 = 1.0f;
    D_801825C0 = 320.0f;
    D_801825C8 = 240.0f;
    func_800BDC70(0, 0x3C, 0x64, 1);
    D_801A70E4 = 0;
    for (sp1DC = 0; sp1DC < 4; sp1DC++) {
        func_800BECCC(sp1DC, 90.0f, 90.0f);
    }
    func_80083EAC();
    D_801A7234 = 1;
    D_801A723C = 1;
    D_801A7320 = D_801A7234;
    D_801A7338 = D_801A723C;
    D_801A72AC = 1;
    D_801A72B4 = 2;
    D_801A8C40 = -2;
    D_801A8C58 = -2;
    D_801A8D80 = 0;
    D_801A8D78 = 0;
    D_801A8D70 = 0;
    D_801A7141 = 0;
    D_8015D7D8 = 0;
    for (sp1DC = 0; sp1DC < 8; sp1DC++) {
        D_801A8D88[sp1DC] = 0;
    }
    func_800044BC();
    D_801A3080 = 0;
    D_800F18E4 = 8;
    D_801A3068 = 0;
    D_801A8D88[0] |= 1;
    D_8015F880 = SysMem_GetPhysicalAddressFromVirtual(D_801829B8, D_801849C0, &D_80999AA0);
    sp1DC = Sys_GetSPIHeaderInfoFromVaddr(D_8015F880);
    D_8015F874 = SysMem_HeapAllocMark(D_80160494);
    func_800BF0B4(D_8015F880, sp1DC, D_8015F874);
    D_8015F880 = D_8015F874;
    D_801A8D88[0] |= 2;
    D_80153DF4 = 0;
    func_800BD620(1);
    D_80182640 = 0;
    func_8005D150();
    func_8005F01C();
    func_8002856C(0);
    D_801A8D88[0] |= 0x20;
    D_801A70E8 = 0x1388;
    D_801A718C = 0;
    D_8015F86C = 0;
    D_801A72E4 = 0;
    D_80189610 = 0x1A;
    D_80189AA8 = -0x21;
    D_801A72D4 = 0;
    D_8015C748[0] = &D_800D9EE4;
    D_8015C748[3] = 1;
    D_8015C748[4] = &D_800D9EF0;
    D_8015C748[7] = 1;
    D_8015C748[9] = &D_8015F86C;
    D_8015C748[10] = 4;
    D_8015C748[11] = 2;
    D_801A7294 = 0;
    D_801A72A0 = 1;
    D_801A8D70 = D_801A8D78 = 1;
    D_8015BAF8 = 4.0f;
    D_8015BAFC = 0;
    D_8015BB00 = 0;
    D_8015BB04 = 0;
    D_8015BB08 = 0x140;
    D_8015BB0C = 0xA8;
    D_8015BB10 = 0.0f;
    D_8015BB14 = 10.0f;
    D_8015BB18 = 0.0f;
    D_8015BB1C = 0x3E8;
    D_8015F7E0 = 0x21;
    SetPfsCodes(0x4234U, 0x4E4A324AU);

    while (TRUE) {
        sp50->unk82EC = 0;
        func_8000A2C0(threadEntry);
        if (D_801AA4EC != 0) {
            sp50->unk82EC = 0;
            func_80002F20();
            D_801A723C = 0;
            D_801A7234 = 0;
            func_8001AFA0(threadEntry);
            if ((D_801A7234 == D_801A723C) && (D_801A7234 == 0)) {
                D_801A8C40 = 0x1F4;
                D_801A7234 = D_801A723C = 1;
            }
        } else {
            D_801A8C40 = 0x1F4;
        }
        if (D_801A7234 == 0) {
            D_801A7234 = 1;
        }
        if (D_801A723C == 0) {
            D_801A723C = 1;
        }
        D_801ACC44 = -1;
        func_80098820();
        func_80098868();
        func_800C0A40();
        func_800BCB54();
        sp50->unk82EC = 0;
        func_80000C90(threadEntry);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/sys/sys_main/func_80000C90.s")

s32 func_80001F54(void) {
    UnkStruct_80156DC0* sp1C;

    if (!(D_801A8D88[0] & 0x80) && (D_801A8D88[3] & 1)) {
        D_801A8D88[3] = (u16) (D_801A8D88[3] & ~1);
        if (D_801ACC44 >= 0) {
            func_80021ED0(D_801ACC44);
        }
    }
    if (!(D_801A8D88[0] & 0x400)) {
        return -1;
    }
    if (D_801A8C34 == -1) {
        D_801A8D88[0] &= ~0x400;
        return 0;
    }
    sp1C = func_80016074(D_801A8C34);
    if (sp1C == NULL) {
        return -1;
    }
    if (sp1C->unk1A8 & 7) {
        return -1;
    }
    D_801A8D88[0] &= ~0x400;
    return 0;
}

s32 func_800020A8(s32 arg0) {
#undef FABS
#define FABS(x) ((x) > 0.0f ? (x) : -(x))
    UnkStruct_80156DC0* sp1C;

    sp1C = NULL;
    if (D_801A8C34 != -1) {
        sp1C = func_80016074(D_801A8C34);
        if (sp1C == NULL) {
            return 0;
        }
    }
    if ((D_801A7234 != D_801A7254) || (D_801A723C != D_801A725C) || (D_801A8D88[0] & 0x10)) {
        if ((D_801A8D88[0] & 0x80) || (sp1C == NULL)) {
            D_801A7234 = D_801A7254 & 0x7FFF;
            D_801A723C = D_801A725C & 0x7FFF;
            return 1;
        }
        if (sp1C->unk1A8 & 2) {
            if (!(D_801A8D88[0] & 0x10)) {
                D_801A7234 = D_801A7254 & 0x7FFF;
                D_801A723C = D_801A725C & 0x7FFF;
            } else {
                D_801A7234 &= 0x7FFF;
                D_801A723C &= 0x7FFF;
                D_801A8D88[0] &= ~0x10;
            }
            return 1;
        } else if (!(sp1C->unk1A8 & 1)) {
            D_801A7274 = D_801A7234;
            D_801A7280 = D_801A723C;
            D_801A728C = D_801A7248;
            if (D_801A8D88[3] & 2) {
                D_801A8D88[3] = (u16) (D_801A8D88[3] & ~2);
                func_80021F20(0x2A);
            }
            if (((D_801A7234 & 0x7FFF) == 1) && ((D_801A723C & 0x7FFF) == 3) && ((D_801A7254 & 0x7FFF) == 2) &&
                ((D_801A725C & 0x7FFF) == 1)) {
                D_801A8D88[3] = (u16) (D_801A8D88[3] & ~2);
                func_80021F20(0x2A);
            }
            if (((D_801A7234 & 0x7FFF) == 2) && ((D_801A723C & 0x7FFF) == 1) && ((D_801A7254 & 0x7FFF) == 1) &&
                ((D_801A725C & 0x7FFF) == 3)) {
                D_801A8D88[3] = (u16) (D_801A8D88[3] & ~2);
                func_80021F20(0x2A);
            }
            if (D_801A8D88[3] & 0x800) {
                D_801A8D88[3] = (u16) (D_801A8D88[3] & ~0x800);
                D_801A8C34 = 0xF;
            }
            if (D_801A8C34 == 0xF) {
                if (FALSE)
                    ;
                if (D_8015BAF8 == 0.0f) {
                    D_8015BAF8 = -4.0f;
                } else if (D_8015BAF8 > 0.0f) {

                    D_8015BAF8 = -FABS(D_8015BAF8);
                }
                func_80016620(&D_8015BAF8);
                D_801A8D88[0] |= 0x400;
                return 0;
                goto exit; // TODO: This doesn't make any sense..
            }

            if (D_801A8D88[0] & 0x80) {
                D_801A7234 = D_801A7254 & 0x7FFF;
                D_801A723C = D_801A725C & 0x7FFF;
                return 1;
            }
            if (!(D_801A8D88[0] & 0x10)) {
                D_801A7234 = D_801A7254 & 0x7FFF;
                D_801A723C = D_801A725C & 0x7FFF;
            } else {
                D_801A7234 &= 0x7FFF;
                D_801A723C &= 0x7FFF;
                D_801A8D88[0] &= ~0x10;
            }
            D_801A8D88[0] |= 0x400;
            return 1;
            goto exit;
        }
    }
exit:
    return 0;

#undef FABS
}


void func_8000262C(UnkStruct_80099E2C* arg0, UnkStruct_80099E2C* arg1) {
    s32 sp24;
    UnkStruct_80099E2C* sp20;
    s32 temp_t3;
    s32 temp_t8;

    if (arg0 != NULL) {
        D_801A8C18 = arg0;
    }
    if (arg1 != NULL) {
        D_801A8C24 = arg1;
    }
    
    for (sp24 = 0, sp20 = D_801A8C18; sp24 < 4; sp24++, sp20++) {
        if (sp20->unkC0 & 0x10000000) {
            func_800C1754();
            func_800A7230(sp20);
            func_800C2780(sp20->unkF0);
            func_800C25B8(sp20->unkEC);
            func_800C23E8(sp20->unkE8);
            func_800997D8(sp20);
            func_800C1A28();
        }
    } 
    if ((func_80016074(0xD) != NULL) && ((*D_8015BAC8)->unk1A8 & 1)) {
        for (sp24 = 0, sp20 = D_801A8C24; sp24 < 4; sp24++, sp20++) {
            if (sp20->unkC0 & 0x10000000) {
                func_800C1754();
                func_800A7230(sp20);
                func_800C2780(sp20->unkF0);
                func_800C25B8(sp20->unkEC);
                func_800C23E8(sp20->unkE8);
                func_800997D8(sp20);
                func_800C1A28();
            }
        } 
    }
}

void func_80002824(void) {
    UnkStruct_80156DC0* sp1C;
    s32 sp18;

    for (sp18 = 0; sp18 < 32; sp18++) {
        if (D_80156DC0[sp18].unk0 & 4) {
            D_80156DC0[sp18].unk0 = 0;
            continue;
        } 

        if (!(D_80156DC0[sp18].unk0 & 1)) {
            continue;
        }  
        if (D_80156DC0[sp18].unk0 & 8) {
            continue;
        } 
            
        sp1C = &D_80156C20[sp18];
            
        if (D_800DDB74[sp1C->unk1A4][0] == 0) {
            continue;
        } 
        D_800DDB74[sp1C->unk1A4][0](sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/sys/sys_main/func_800029BC.s")
