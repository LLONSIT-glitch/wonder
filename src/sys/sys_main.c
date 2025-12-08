#include "common.h"

// UNK_TYPE func_80000C90(void*);

extern s32 D_8015C748[];
s32 func_80000C90(ThreadEntry* entry);
void func_80016620(f32*);
void func_80021F20(s32);
s32 func_80001F54(void);
s32 func_800020A8(s32 arg0);
void func_8000262C(UnkStruct_80099E2C* arg0, UnkStruct_80099E2C* arg1);
void func_80002824(void);

// Extern functions
void func_800BE510(f32, f32, f32);
UNK_TYPE func_800B1F0C(UnkStruct_80099E2C*, void*, UNK_TYPE, UNK_TYPE, f32, f32, s32);
UNK_TYPE func_8009A04C(f32, f32);
void func_8004DEA4(void);
void func_800305A4(void);
void func_8002A39C(void);
void func_80082958(void);
void func_80098BB8(void);
void func_80021FF8(s32, s32, s32);
void func_800B1BC8(void*, void*);
void func_80098BF4(void);
void func_80099520(void);
void func_800B1B04(void*, void*);
s16 func_800AD774(s32);
void func_800077A0(ThreadEntry*);
void func_80005880(ThreadEntry*);
void func_80032380(void);
void func_80099768(void);
void func_800AFB28(void);
void func_80033788(void);
void func_80032604(void);
void func_80034310(void);
void func_8009A664(Gfx**);
void func_8002C2F8(void);
void func_8001635C(void);
void func_800BE684(void);
s32 func_80031AC8(void);
void func_800BE610(void);
void CreateGfxTask(void*, u32);
void func_80098D24(u8 threadId);
void func_80099450(void);
s32 func_800065BC(ThreadEntry*);
void func_80096474(void);
void func_80090728(int);
void func_800967D8(void);
void func_80098C1C(void);
void func_80098CD8(void);
void func_80098CFC(void);
void func_80005460(void);
void func_80005124(s32, s32);
void func_800029BC(void);
s32 func_80083F28(void);

extern s16 D_801A7248;
extern s16 D_801A7274;
extern s16 D_801A7280;
extern s16 D_801A728C;

extern FuncPtr D_800DDB74[][2];
extern UnkStruct_8000DDE0 D_80156DC0[];
extern UnkStruct_8000DDE0 D_80156C20[];

// .data
u16 D_800D9F00[0x40] = {
    0,     1,     2,     3,     4,     5,     6,     7,     0x147, 0x287, 0x3C7, 0x507, 0x647, 0x787, 0x8C7, 0x8C6,
    0x8C5, 0x8C4, 0x8C3, 0x8C2, 0x8C1, 0x8C0, 0x780, 0x640, 0x500, 0x3C0, 0x280, 0x140, 0x141, 0x142, 0x143, 0x144,
    0x145, 0x146, 0x286, 0x3C6, 0x506, 0x646, 0x786, 0x785, 0x784, 0x783, 0x782, 0x781, 0x641, 0x501, 0x3C1, 0x281,
    0x282, 0x283, 0x284, 0x285, 0x3C5, 0x505, 0x645, 0x644, 0x643, 0x642, 0x502, 0x3C2, 0x3C3, 0x3C4, 0x504, 0x503,
};


void* SysMain(ThreadEntry* entry) {
    s32 sp1DC;
    char pad[0x184];
    ThreadEntry* threadEntry;
    UnkStruct_800F9C38* sp50;
    s32 pad2[4];

    threadEntry = entry;
    gSysThreadIds[THREAD_SYS_MAIN] = threadEntry->threadId;
    sp50 = threadEntry->unk18;
    func_800983B0(0, 1);
    func_800AD800();
    func_800984B4();
    func_800985BC(threadEntry->threadId);
    sp50 = threadEntry->unk18;
    sp50->unk80BC = 2;
    sp50->unk80DC = 2;
    gFrameBuffer2[0] = gFrameBuffer2[1] = gFrameBuffer2[2] = gFrameBuffer2[3] = 0;
    SysMem_Copy64(&gFrameBuffer2[4], &gFrameBuffer2, 0x4AFF);
    osViSwapBuffer(&gFrameBuffer2);
    SysMem_Copy64(&gFrameBuffer1, &gFrameBuffer2, 0x4B00);
    func_8008E5A0();
    AudioMgr_InitThread();

    gSpriteObjHeaderSegment = SpriteSeg1_ROM_START;
    gSpriteSeg1VramStart = SpriteSeg1_VRAM;

    D_80153E2C = SpriteSeg2_ROM_START;
    D_801540D8 = SpriteSeg2_VRAM;

    D_801560E0 = Seg_69A970_ROM_START;
    D_801560E8 = Seg_69A970_VRAM;

    D_801849C0 = Seg_639B20_VRAM;
    D_801829B8 = Seg_639B20_ROM_START;

    D_8015FB78 = Seg_6E3A40_ROM_START;
    D_8015FB80 = Seg_6E3A40_VRAM;

    D_800F193C = SysMem_GetPhysicalAddressFromVirtual(D_80153E2C, D_801540D8, &D_807A1A20);
    D_80153DB0 = SysMem_GetPhysicalAddressFromVirtual(D_801560E0, D_801560E8, &D_809A8230);
    func_800B1A50(SpriteSeg1_VRAM, D_80409B40, gSpriteObjDefs, gSpriteFramesStart, gMainSpritesSpiOffsets, gMainSprites,
                  gSpritePalettes, D_807991C0, D_8079A730, 3);
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
    Spi_DecompressAsset(D_8015F880, sp1DC, D_8015F874);
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
            func_8001AFA0((void*) threadEntry); // TODO: is UnkStruct_8000DDE0 ThreadEntry?
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

typedef struct UnkStruct_sp284_s {
    char pad[0x14C];
    s32 unk14C;
} UnkStruct_sp284;

extern UnkStruct_80099E2C* D_801A8C18;

s32 func_80000C90(ThreadEntry* entry) {
    s32 pad2;
    s32 sp428;
    s32 sp424;
    s32 sp420;
    s32 sp41C;
    s32 sp418;
    ThreadEntry* threadEntry;
    UnkStruct_800F9C38* sp410;
    s16* threadMesg;
    u8 pad_sp3F0[0x40C - 0x3F0];
    s16 pad_sp3EE;
    s16 sp3EC;
    u8 pad_sp358[0x3E8 - 0x358];
    f32 sp358;
    f32 sp354;
    u8 sp288[0x354 - 0x288];
    UnkStruct_80099E2C* sp284;
    UnkStruct_80099E2C* sp280;
    s32 pad_sp34[2];
    UnkStruct_8000DDE0* sp274;
    u8 pad_sp19C[0x274 - 0x19C];
    s32 pad;
    UnkStruct_80099E2C sp38;

    D_80153DF4 = 0;
    threadEntry = entry;
    sp410 = threadEntry->unk18;
    sp420 = 0;
    sp428 = 0;
    sp3EC = 0x20;
    D_8015F7E0 = 0x21;
    func_80098820();
    func_80098868();
    D_801A8D88[0] |= 2;
    Thread_SendMesgNoBlock(threadEntry->threadId, &sp3EC, 1);

    while (sp428 == 0) {
        Thread_ReceiveMsgInThread(threadEntry->threadId, (OSMesg*) &threadMesg, OS_MESG_BLOCK);
        switch (*threadMesg) {
            case 32:
                func_80098BF4();
                sp418 = 0;

                do {
                    Thread_ReceiveMsgInThread(threadEntry->threadId, (OSMesg*) &threadMesg, OS_MESG_BLOCK);
                    switch (*threadMesg) { /* switch 1; irregular */
                        case 1:            /* switch 1 */
                        case 5:            /* switch 1 */
                            sp418 += 1;
                            break;
                        case 2: /* switch 1 */
                            func_80099520();
                            sp410->unk82EC -= 1;
                            sp418 = 0;
                            break;
                    }
                } while (sp418 < 5);
                func_80098820();
                func_80098868();
                D_801560E4 &= ~2;
                D_801560E4 |= 1;
                sp420 = 0;

                if (func_80002F20() == 1) {
                    // Halt
                    while (TRUE)
                        ;
                }
                sp280 = &sp38;
                func_80099E2C(sp280);
                func_800B1B04(sp280, &sp38.unk160 + 1);
                func_800B1F0C(sp280, &sp38.unk160 + 1, 0x690221, 0x5F, 0.0f, 0.0f, 0);
                sp280->unkC0 |= 0x208;
                sp280->unkC8 = 0x7FFFFFFF;
                sp280->unkC4 = func_800AD774(2);
                sp420 = 1;
                sp410->unk82EC = 0;
                func_80098820();
                func_80098868();
                Thread_ResetMqValidCount(threadEntry->threadId);
                threadEntry->unk8 = 0;
                D_801A7320 = D_801A7234;
                D_801A7338 = D_801A723C;
                if (((D_801A7234 == 7) && (D_801A723C == 1)) || ((D_801A7234 == 7) && (D_801A723C == 2))) {
                    func_80098BF4();
                    func_800077A0(threadEntry);
                    Thread_ResetMqValidCount(threadEntry->threadId);
                    Thread_SendMesgNoBlock(threadEntry->threadId, &sp3EC, /* Unused */ OS_MESG_BLOCK);
                } else if ((D_801A7234 == 0xB) && (D_801A723C == 0x18)) {
                    D_801A72AC = 0xB;
                    D_801A72B4 = 0x18;
                    D_801A8D88[3] = (u16) (D_801A8D88[3] | 0x8000);
                    func_80098BF4();
                    func_80005880(threadEntry);
                    D_801A7234 = D_801A7254 & 0x7FFF;
                    D_801A723C = D_801A725C & 0x7FFF;
                    D_801A8D88[0] |= 2;
                    D_801A8D88[1] = 0;
                    D_801A8D88[3] = (u16) (D_801A8D88[3] & 0xFFFF7FFF);
                    sp274 = func_80016074(0xF);
                    sp274->unk1E8 = 0.0f;
                    D_8015BAF8 = 4.0f;
                    Thread_ResetMqValidCount(threadEntry->threadId);
                    Thread_SendMesgNoBlock(threadEntry->threadId, &sp3EC, /* Unused */ OS_MESG_BLOCK);
                } else if ((D_801A7234 == 0xB) && (D_801A723C == 0x19)) {
                    if (!(D_801A8D88[2] & 0x10)) {
                        D_801A72AC = 0xB;
                        D_801A72B4 = 0x19;
                        func_80098BF4();
                        func_80005880(threadEntry);
                        D_801A7234 = D_801A7254 & 0x7FFF;
                        D_801A723C = D_801A725C & 0x7FFF;
                        sp274 = func_80016074(15);
                        if (sp274 != NULL) {
                            sp274->unk1E8 = 0.0f;
                            D_8015BAF8 = 4.0f;
                        }
                    } else {
                        D_801A8C40 = func_80083F28();
                        D_801A7234 = D_801A7254 = 1;
                        D_801A723C = D_801A725C = 1;
                    }
                    D_801A8D88[0] |= 2;
                    D_801A8D88[1] = 0;
                    Thread_ResetMqValidCount(threadEntry->threadId);
                    Thread_SendMesgNoBlock(threadEntry->threadId, &sp3EC, /* Unused */ OS_MESG_BLOCK);
                }
                continue;
            case 1:
                if (!(D_801A8D88[0] & 2) && (sp410->unk82EC < 2)) {
                    D_801560E4 &= ~1;
                    D_801560E4 |= 2;
                    D_801806C4 = 1;
                    func_80032380();
                    D_801560E4 &= ~2;
                    D_801560E4 |= 1;
                    D_801806C4 = 1;
                    D_801A30AC = D_8018258C;
                    func_80099768();
                    func_800AFB28();
                    func_800BE510(D_801825D0, (f32) D_8015B334, (f32) D_8015B33C);
                    func_8009A04C((f32) D_8015B334, (f32) D_8015B33C);
                    if (D_801A8D88[0] & 8) {
                        func_80033788();
                    }
                    func_80032604();
                    func_8000262C(D_801A7340, D_801A7340 + 4);
                    func_80002824();
                    if (D_801A721C == 1) {
                        func_80034310();
                    }
                    func_8004DEA4();
                    func_800305A4();
                    func_8002A39C();
                    func_80082958();

                    for (sp284 = (void*) D_801A8C54; sp284 != NULL;) {
                        func_800C1754();
                        func_8009A14C(sp284);
                        func_800997D8(sp284);
                        func_800C1A28();
                        sp284 = sp284->unk14C;
                    }
                    sp41C = 0;
                    if (!(D_801A8D88[3] & 0x4000) && !(D_801A72DC & 1) && !(D_801A8D88[0] & 0x1000) &&
                        !(D_801A8D88[0] & 0x400) && (D_801560F0->unk6 & (u16) D_801811A4)) {
                        if (D_801A8C40 < 0) {
                            sp41C += 1;
                        } else if (D_801A8D88[0] & 0x4000) {
                            sp41C += 1;
                        }
                    }
                    if (sp41C != 0) {
                        func_80098BB8();
                        sp424 = 0;
                        func_80021FF8(-1, 0x20, 0x3FFF);
                        sp280 = &sp38;
                        if (sp420 != 0) {
                            func_800B1BC8(sp280, &sp38.unk160 + 1);
                        } else {
                            func_80099E2C(sp280);
                        }
                        func_800B1B04(sp280, &sp38.unk160 + 1);
                        func_800B1F0C(sp280, &sp38.unk160 + 1, 0x690221, 0x5F, 0.0f, 0.0f, 0);
                        sp280->unkC0 = (s32) (sp280->unkC0 | 0x208);
                        sp280->unkC8 = 0x7FFFFFFF;
                        sp280->unkC4 = func_800AD774(2);
                        sp420 = 1;
                    }
                    if (!(D_801A8D88[0] & 0x100)) {
                        func_8009A664(&gDisplayListHead);
                        func_8002C2F8();
                    } else {
                        func_8002C2F8();
                        func_8009A664(&gDisplayListHead);
                    }
                    func_8001635C();
                    func_800BE684();
                    if (D_801A72DC & 1) {
                        sp280 = &sp38;
                        func_800C1754();
                        sp280->unkCC = -88.0f;
                        sp280->unkD0 = -42.0f;
                        if (func_80031AC8() != -2) {
                            sp280->unkD0 = (f32) (sp280->unkD0 + 6.0f);
                        }
                        func_8009A14C(sp280);
                        func_800997D8(sp280);
                        func_800C1A28();
                    }
                    func_8009A664(&gDisplayListHead);
                    func_800BE610();
                    CreateGfxTask(D_801A1B4C, (u32) gDisplayListHead - (u32) D_801A1B4C);
                    func_80098D24(threadEntry->threadId);
                    func_80099450();
                    func_80001F54();
                    if (func_800020A8(0) == 1) {
                        D_801A8D88[0] |= 2;
                        Thread_SendMesgNoBlock(threadEntry->threadId, &sp3EC, 1);
                    }
                    sp410->unk82EC++;
                }
                continue;
            case 2:
                if (sp410->unk82EC != 0) {
                    func_80099520();
                    sp410->unk82EC--;
                    D_801819A8 = osGetTime();
                }
                if ((D_801A8D88[0] & 4) &&
                    ((func_800065BC(threadEntry), (D_801A7320 != D_801A7234)) || (D_801A7338 != D_801A723C))) {
                    D_801A7254 = D_801A7320 | 0x8000;
                    D_801A725C = D_801A7338;
                }
                if (D_801A8D88[0] & 0x40) {
                    D_801A8D88[0] |= 4;
                    func_80005880(threadEntry);
                    continue;
                }

                continue;
            case 5:
                func_80032604();
                if ((sp410->unk82EC <= 0) && (D_801560F0->unk6 & (u16) D_801811A4)) {
                    func_80021FF8(-1, 0x20, 0x7FFF);
                    func_80098BF4();
                    sp410->unk82EC = 0;
                    Thread_ResetMqValidCount(threadEntry->threadId);
                    func_80098820();
                    func_80098D24(threadEntry->threadId);
                    continue;
                }

                if (D_801A8D88[0] & 0x20) {
                    func_80096474();
                    D_8015B320 = 0x10;
                    D_8015B328 = 0xFF;
                    D_8015B338 = 0;
                    D_80156BC0 = D_80156C08 = 2;
                    D_8015B344 = 320.0f;
                    D_8015BACC = 240.0f;
                    D_8015BAF0 = 320.0f;
                    D_8015BB28 = 240.0f;
                    func_80090728(0x200);
                    Sys_SwapFrameBuffer(osViGetCurrentFramebuffer());
                    func_800967D8();
                }

                if (D_801A8D88[0] & 0x4000) {
                    if (D_801560F0->unk6 & (u16) D_80181038) {
                        func_80098868();
                        func_80098C1C();
                        func_80098820();
                        func_80098D24(threadEntry->threadId);
                        sp424 = 0;
                        continue; // m2c got a little bit confused here..
                    }
                    if (D_801560F0->unk2C & (u16) D_80181038) {
                        sp424 ^= 1;
                        if (sp424 != 0) {
                            func_80098868();
                            func_80098C1C();
                            func_80098D24(threadEntry->threadId);
                        }
                        continue;
                    }

                    if (D_801560F0->unk6 & (u16) D_80181042) {
                        D_801A8D88[0] |= 0x8004;
                        func_80098CD8();
                        func_80098BF4();
                        func_80098820();
                        func_80098868();
                        sp410->unk82EC = 0;
                        Thread_ResetMqValidCount(threadEntry->threadId);
                        func_800065BC(threadEntry);
                        func_80098CFC();
                        func_80098BB8();
                        func_80098C1C();
                        func_80098868();
                        func_80098820();
                        if ((D_801A7320 != D_801A7234) || (D_801A7338 != D_801A723C)) {
                            D_801A7254 = D_801A7320 | 0x8000;
                            D_801A725C = D_801A7338;
                            func_80098BF4();
                            func_80098820();
                        } else if (D_801A8D88[0] & 0x10) {
                            D_801A8D88[0] &= ~0x10;
                            D_801A7254 |= 0x8000;
                            func_80098BF4();
                            func_80098820();
                        }
                        func_80098D24(threadEntry->threadId);
                        continue;
                    }
                }
                func_80098D24(threadEntry->threadId);
                continue;

            case 33:
                while (TRUE) {
                    Thread_ReceiveMsgInThread(threadEntry->threadId, (OSMesg*) &threadMesg, 1);
                    if (*threadMesg == 2) {
                        if (FALSE) {}

                        func_80099520();
                        sp410->unk82EC -= 1;
                        if (FALSE) {}
                    }
                    if (sp410->unk82EC == 0) {
                        break;
                    }
                }
                func_80005460();
                SysMem_Copy8(sp288, D_801A8C18, 0x160);
                func_80005124(D_801A8C10, D_801A8C1C);
                D_801A8C18->unkCC = sp354;
                D_801A8C18->unkD0 = sp358;
                D_801A7234 = D_801A7254 = D_801A8C10;
                D_801A723C = D_801A725C = D_801A8C1C;
                sp410->unk82EC = 0;
                Thread_ResetMqValidCount(threadEntry->threadId);
                func_80098820();
                threadEntry->unk8 = 0;
                continue;
            case 4:
                func_800029BC();
                while (TRUE)
                    ;
                // what?
                continue;
            case 3:
                continue;
        }
        continue;
    }
}

s32 func_80001F54(void) {
    UnkStruct_8000DDE0* sp1C;

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
    UnkStruct_8000DDE0* sp1C;

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
                D_801A8D88[3] &= ~2;
                func_80021F20(0x2A);
            }
            if (((D_801A7234 & 0x7FFF) == 1) && ((D_801A723C & 0x7FFF) == 3) && ((D_801A7254 & 0x7FFF) == 2) &&
                ((D_801A725C & 0x7FFF) == 1)) {
                D_801A8D88[3] &= ~2;
                func_80021F20(0x2A);
            }
            if (((D_801A7234 & 0x7FFF) == 2) && ((D_801A723C & 0x7FFF) == 1) && ((D_801A7254 & 0x7FFF) == 1) &&
                ((D_801A725C & 0x7FFF) == 3)) {
                D_801A8D88[3] &= ~2;
                func_80021F20(0x2A);
            }
            if (D_801A8D88[3] & 0x800) {
                D_801A8D88[3] = (u16) (D_801A8D88[3] & ~0x800);
                D_801A8C34 = 0xF;
            }
            if (D_801A8C34 == 0xF) {
                if (FALSE) {}
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
    UnkStruct_8000DDE0* sp1C;
    s32 sp18;

    for (sp18 = 0; sp18 < 32; sp18++) {
        if (D_80156DC0[sp18].unk0.unk0 & 4) {
            D_80156DC0[sp18].unk0.unk0 = 0;
            continue;
        }

        if (!(D_80156DC0[sp18].unk0.unk0 & 1)) {
            continue;
        }
        if (D_80156DC0[sp18].unk0.unk0 & 8) {
            continue;
        }

        sp1C = &D_80156C20[sp18];

        if (D_800DDB74[sp1C->unk1A4][0] == 0) {
            continue;
        }
        D_800DDB74[sp1C->unk1A4][0](sp1C);
    }
}

typedef u16 frame_row[320][1];

void func_800029BC(void) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 pad;
    s32 sp34;
    union {
        frame_row* frameRow;
        u8* ptr;
    } sp30;

    void* curFrameBuf;
    u32 imask = osSetIntMask(OS_IM_NONE);
    curFrameBuf = osViGetCurrentFramebuffer();
    switch (guRandom() % 3) {
        case 0:
            for (sp4C = 0; sp4C < 16; sp4C++) {
                sp30.frameRow = curFrameBuf;
                sp30.frameRow[0][0][0] = 1;
                sp30.frameRow[0][0][1] = 1;
                sp30.frameRow[0][0][2] = 1;
                sp30.frameRow[0][0][3] = 1;
                SysMem_Copy64(sp30.frameRow[0] + 4, sp30.frameRow, (sp4C * 0x50) + 0x4F);

                for (sp48 = 1; sp48 < 15; sp48++) {
                    SysMem_Copy64((sp48 * 0x140 * 0x10 * 2) + (u8*) sp30.frameRow, sp30.frameRow, (sp4C * 0x50) + 0x50);
                }

                for (sp34 = 0x12C; sp34 > 0; sp34--) {
                    osWritebackDCacheAll();
                }
            }
            break;
        case 1:
            // Wtf this is actually insane...
            for (sp4C = 0; sp4C < 0x40; sp4C++) {
                sp30.frameRow = curFrameBuf;
                for (sp3C = 0; sp3C < 0xF0; sp3C += 8) {
                    for (sp40 = 0; sp40 < 0x140; sp40 += 0x40) {
                        for (sp48 = 0; sp48 <= sp4C; sp48++) {
                            // sp40 is multiplied too much here, it should just access a s16/u16 here
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48]] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 8] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 16] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 24] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 32] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 40] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 48] = 1;
                            (&(&((u16*) sp30.frameRow)[sp40])[sp3C * 0x140])[D_800D9F00[sp48] + 56] = 1;
                        }
                    }
                }

                // huh?
                for (sp34 = 0; sp34 > 0; sp34--) {
                    osWritebackDCacheAll();
                }
            }
            break;

        case 2:
            for (sp4C = 0; sp4C < 6; sp4C++) {
                sp30.frameRow = curFrameBuf;
                for (sp44 = 0; sp44 < 0x3200; sp44++) {
                    for (sp48 = 0; sp48 <= sp4C; sp48++) {
                        ((s16*) sp30.frameRow)[sp48] = 1;
                    }
                    sp30.ptr += 0xC;
                }

                for (sp34 = 0x320; sp34 > 0; sp34--) {
                    osWritebackDCacheAll();
                }
            }
            break;
    }

    // Halt
    while (TRUE) {}
}
