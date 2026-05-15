#include "common.h"
#include "main.h"

void func_8008EC8C(f32, f32);          /* extern */
void func_8008ECAC(f32, f32);          /* extern */
void func_80090728(s32);               /* extern */
void func_80090754(s32);               /* extern */
void func_80096474(void);              /* extern */
void func_800967D8(void);              /* extern */
void* CreateGfxTask(void*, s32);       /* extern */
void Update_ControllerRaw(u8);         /* extern */
void func_8000262C(SpriteObj*, s32);   /* extern */
s32 func_80005124(s32, s32);           /* extern */
void func_80032604(void);              /* extern */
void func_8008CE90(void);              /* extern */
s32 func_8008D0CC(void);               /* extern */
void func_8008D23C(void);              /* extern */
void func_80099450(void);              /* extern */
void func_80099520(void);              /* extern */
void func_80099768(void);              /* extern */
void func_8009A664(Gfx**);             /* extern */
void func_800A6670(void*, SpriteObj*); /* extern */
void func_800A6F20(s32, s32);          /* extern */
void func_800AFB28(void);              /* extern */

extern f32 D_80156190;
extern f32 D_80156194;
extern f32 D_80156198;
extern f32 D_8015619C;
extern s16 D_801A9950;
extern SpriteObj D_801A99A8[8];
extern f32 D_801AA4A8[];
extern s16* D_800D9F80;
extern s8 D_800ED180;
extern s8 D_800ED18C;
extern s8 D_800ED198;
extern s8 D_800ED1A4;
extern s8 D_800ED1A8;
extern s16 D_8015BB48[];
extern s32 D_80180648;

void func_800062C0(SpriteObj* obj, s32 arg1);

void func_800062C0(SpriteObj* obj, s32 arg1) {
    s32 i;
    s16* sp20;
    s32 pad[2];

    sp20 = D_80180648;
    func_80096474();
    Sys_SwapFrameBuffer(obj->spritePtrs.ptrs[0]);
    func_8008EC8C((f32) obj->unk100, (f32) obj->unk102);
    func_8008ECAC((f32) obj->unk100, (f32) obj->unk102);
    D_8015B328 = 0x10;
    D_8015BB48[D_8015B320] = 1;
    func_80090754(0xE8);
    func_80090728(0x400);
    for (i = 0; i < 0x2A; i++) {
        if (i == 0) {
            func_8008EAA8(1, 1);
        } else if ((i >= 3) && (i < 0xC)) {
            func_8008EAA8(1, i + 2);
        } else if ((i >= 0xC) && (i < 0x18)) {
            func_8008EAA8(0xB, i - 7);
        } else if ((i >= 0x18) && (i < 0x1C)) {
            func_8008EAA8(0x15, i - 0x13);
        } else if (i >= 0x1C) {
            func_8008EAA8(0x15, i - 0x10);
        }
        if (D_800D9F80[i] == sp20[i]) {
            func_8008ECE4("      %l%3d", 16, sp20[i]);
        } else {
            if (D_800D9F80[i] < sp20[i]) {
                func_8008ECE4("      %l%3d", 10, sp20[i]);
            } else {
                func_8008ECE4("      %l%3d", 4, sp20[i]);
            }
        }
        if (arg1 == i) {
            func_8008ECE4("*");
        } else {
            func_8008ECE4(" ");
        }
    }
    func_800967D8();
}

void func_800065BC(ThreadEntry* entry) {
    s32 i;
    s32 sp1D0;
    s32 sp1CC;
    s32 sp1C8;
    s32 sp1C4;
    s32 sp1C0;
    s32 sp1BC;
    ThreadEntry* threadEntry;
    UnkStruct_800F9C38* sp1B4;
    s16* sp1B0;
    u8* sp1AC;
    SpriteObj* sp1A8;
    SpriteObj* objPtr;
    s32 pad3;
    SpriteObj obj;
    s16* sp3C;
    s32 pad2;
    s32 pad;

    threadEntry = entry;
    sp1B4 = threadEntry->unk18;
    D_801AA4A8[0] = (f32) D_80156190;
    D_801AA4A8[1] = (f32) D_80156194;
    D_801AA4A8[2] = (f32) D_80156198;
    D_801AA4A8[3] = (f32) D_8015619C;
    func_800AC0A4(0x14, 2, 0x12C, 0xE1);
    if (*D_801A8D88 & 0x8000) {
        sp1A8 = &D_801A7340[12];
        sp1A8->rotateX = 90.0f;
        sp1A8->rotateZ = 90.0f;
        sp1A8->unkF4 = sp1A8->unkF8 = (f32) (1.0 - (f64) (sp1A8->rotateX / 90.0f));
        sp1A8->unkC0 &= ~8;
        sp1A8->unkC0 |= 0x810;
        objPtr = &obj;
        func_80099E2C(objPtr);
        obj.unkCC = obj.unkD0 = obj.unkD4 = 0.0f;
        obj.unk108 = 0;
        obj.unk104 = 0;
        obj.rotateX = obj.rotateY = obj.rotateZ = 0.0f;
        obj.unkF4 = obj.unkF8 = 1.0f;
        obj.unk11E = 0xFF;
        obj.unk116 = 1;
        obj.unkC0 = 0x814;
        obj.unk114 = 4;
        obj.unkC8 = sp1A8->unkC8 + 1;
        obj.unk100 = 0x100;
        obj.unk102 = 0xB0;
        obj.spritePtrs.ptr = SysMem_HeapAlloc(objPtr->unk100 * objPtr->unk102);
        obj.currentPaletteColors = D_8015BB48;
        sp1AC = obj.spritePtrs.ptr;

        for (i = 0; i < (obj.unk100 * obj.unk102); i++) {
            sp1AC[i] = 0;
        }

        if (D_800D9F80 == NULL) {
            D_800D9F80 = &D_801A9950;
            SysMem_Copy8(D_800D9F80, (void*) D_80180648, 0x54);
        }
        sp3C = D_80180648;
        sp1C4 = 0;
        func_800062C0(objPtr, sp1C4);
        sp1C8 = 0;
        sp1CC = 0;
    } else {
        while (sp1B4->unk82EC > 0) {
            Thread_ReceiveMsgInThread(threadEntry->threadId, (OSMesg) &sp1B0, OS_MESG_BLOCK);
            if (*sp1B0 == 2) {
                if (FALSE)
                    ;
                func_80099520();
                sp1B4->unk82EC--;
                continue;
            }
        }
        func_80098820();
        func_80098868();
        for (i = 0; i < ARRAY_COUNT(D_801A99A8); i++) {
            func_80099E2C(&D_801A99A8[i]);
        }

        func_800A6670(0, D_801A99A8);
        func_800A6670(4, &D_801A99A8[4]);
        sp1BC = func_80005124(0xB, 0x1A);
        if (sp1BC == 0) {
            func_800A6F20(0, 8);
        }
        func_8008CE90();
        Thread_ResetMqValidCount(threadEntry->threadId);
        func_80098820();
    }
    sp1D0 = 0;
    *D_801A8D88 |= 4;
    while (sp1D0 == 0) {
        Thread_ReceiveMsgInThread(threadEntry->threadId, (OSMesg) &sp1B0, OS_MESG_BLOCK);
        switch (*sp1B0) { /* irregular */
            case 1:
                if (sp1B4->unk82EC < 2) {
                    func_80099768();
                    func_800AFB28();
                    func_800BE510(D_801825D0, (f32) D_8015B334, (f32) D_8015B33C);
                    func_80032604();
                    if (*D_801A8D88 & 0x8000) {
                        sp1C0 = 0;
                        if ((gControllers->unk8 & gInputMask_DPadDown) || (gControllers->unk8 & gInputMask_DPadRight)) {
                            sp1C4 += 1;
                            sp1C0 += 1;
                        }
                        if ((gControllers->unk8 & gInputMask_DPadUp) || (gControllers->unk8 & gInputMask_DPadLeft)) {
                            sp1C4 -= 1;
                            sp1C0 += 1;
                        }
                        if (sp1C4 < 0) {
                            sp1C4 = 0;
                        }
                        if (sp1C4 >= 0x2A) {
                            sp1C4 = 0x29;
                        }
                        if (gControllers->unk8 & gInputMask_A) {
                            sp3C[sp1C4]++;
                            sp1C0 += 1;
                        }
                        if (gControllers->unk8 & gInputMask_B) {
                            sp3C[sp1C4]--;
                            sp1C0 += 1;
                        }
                        if (gControllers->unk8 & gInputMask_CDown) {
                            sp3C[sp1C4] += 10;
                            sp1C0 += 1;
                        }
                        if (gControllers->unk8 & gInputMask_CLeft) {
                            sp3C[sp1C4] -= 10;
                            sp1C0 += 1;
                        }
                        if (gControllers->unk8 & gInputMask_CRight) {
                            sp3C[sp1C4] += 100;
                            sp1C0 += 1;
                        }
                        if (gControllers->unk8 & gInputMask_CUp) {
                            sp3C[sp1C4] -= 100;
                            sp1C0 += 1;
                        }
                        if (sp3C[sp1C4] < 0) {
                            sp3C[sp1C4] = 0;
                        }
                        if (sp3C[sp1C4] >= 0x3E8) {
                            sp3C[sp1C4] = 0x3E7;
                        }
                        if (sp1C0 != 0) {
                            func_800062C0(objPtr, sp1C4);
                        }
                        objPtr = &obj;
                        MtxUtil_PushIdentity();
                        func_8009A14C(sp1A8);
                        if (!(sp1A8->unkC0 & 8)) {
                            if (sp1C8 == 0) {
                                if (sp1A8->rotateX > 0.0f) {
                                    sp1A8->rotateX = (f32) ((f64) sp1A8->rotateX - (3.0 * (f64) D_8018257C));
                                    sp1A8->rotateZ = (f32) ((f64) sp1A8->rotateZ - (3.0 * (f64) D_8018257C));
                                    sp1A8->unkF4 = sp1A8->unkF8 = (f32) (1.0 - (f64) (sp1A8->rotateX / 90.0f));
                                    objPtr->unkF4 = objPtr->unkF8 = sp1A8->unkF4;
                                } else {
                                    sp1A8->rotateZ = 0.0f;
                                    sp1A8->rotateX = sp1A8->rotateZ;
                                    sp1A8->unkC0 &= ~0x10;
                                    sp1A8->unkC0 |= 0x48;
                                    objPtr->unkC0 &= ~0x10;
                                    objPtr->unkC0 |= 0x48;
                                    sp1A8->unkF8 = 1.0f;
                                    sp1A8->unkF4 = sp1A8->unkF8;
                                    objPtr->unkF8 = 1.0f;
                                    objPtr->unkF4 = objPtr->unkF8;
                                }
                            } else if (sp1A8->rotateX != 0.0f) {
                                sp1A8->rotateX = (f32) ((f64) sp1A8->rotateX - (3.0 * (f64) D_8018257C));
                                sp1A8->rotateZ = (f32) ((f64) sp1A8->rotateZ - (3.0 * (f64) D_8018257C));
                                sp1A8->unkF4 = sp1A8->unkF8 = (f32) (1.0 - (f64) (sp1A8->rotateX / 90.0f));
                                objPtr->unkF4 = objPtr->unkF8 = sp1A8->unkF4;
                            } else {
                                sp1A8->rotateZ = 0.0f;
                                sp1A8->rotateX = sp1A8->rotateZ;
                                sp1A8->unkC0 &= ~0x10;
                                sp1A8->unkC0 |= 8;
                                objPtr->unkC0 &= ~0x10;
                                objPtr->unkC0 |= 8;
                                sp1A8->unkF8 = 1.0f;
                                sp1A8->unkF4 = sp1A8->unkF8;
                                objPtr->unkF8 = 1.0f;
                                objPtr->unkF4 = objPtr->unkF8;
                            }
                        }
                        MtxUtil_RotateZ(sp1A8->rotateZ);
                        MtxUtil_RotateY(sp1A8->rotateY);
                        MtxUtil_RotateX(sp1A8->rotateX);
                        func_800997D8(sp1A8);
                        func_800997D8(objPtr);
                        MtxUtil_Pop();
                    } else if (func_8008D0CC() != 0) {
                        sp1D0 = 1;
                    }
                    func_8000262C(&D_801A99A8, 0);
                    func_8009A664(&gDisplayListHead);
                    Main_GfxFullSync();
                    CreateGfxTask(D_801A1B4C, (u32) gDisplayListHead - (u32) D_801A1B4C);
                    Update_ControllerRaw(threadEntry->threadId);
                    func_80099450();
                    sp1B4->unk82EC++;
                }
                continue;
            case 2:
                func_80099520();
                sp1B4->unk82EC--;
                if (*D_801A8D88 & 0x8000) {
                    if (sp1CC == 0) {
                        if ((sp1A8->unkC0 & 8) &&
                            ((gControllers->unk6 & (u16) gInputMask_Start) || (gControllers->unk6 & gInputMask_Z))) {
                            sp1CC += 1;
                            sp1A8->rotateZ = -3.0f;
                            sp1A8->rotateX = sp1A8->rotateZ;
                            sp1A8->unkC0 &= ~0x48;
                            sp1A8->unkC0 |= 0x10;
                            objPtr->unkC0 &= ~0x48;
                            objPtr->unkC0 |= 0x10;
                            sp1C8 += 1;
                        }
                    } else {
                        if (FABS(sp1A8->rotateX) >= 90.0f) {
                            sp1D0 = 1;
                        }
                    }
                    if (gControllers->unk6 & gInputMask_L) {
                        func_8001AFA0((void*) threadEntry); // TODO
                    }
                }
                continue;
            case 4:
                while (TRUE)
                    ;
                continue;
        }

        continue;
    }

    if (*D_801A8D88 & 0x8000) {
        SysMem_Free(obj.spritePtrs.ptr);
        SysMem_Copy8(D_800D9F80, (void*) D_80180648, 0x54);
        *D_801A8D88 &= 0xFFFF7FFF;
    } else {
        func_8008D23C();
        while (sp1B4->unk82EC > 0) {
            Thread_ReceiveMsgInThread(threadEntry->threadId, (OSMesg) &sp1B0, OS_MESG_BLOCK);
            if (*sp1B0 == 2) {
                if (FALSE)
                    ;
                func_80099520();
                sp1B4->unk82EC--;
                continue;
            }
        }
        func_80098820();
        func_80098868();
        if (sp1BC == 0) {
            func_800A6670(0, &D_801A99A8);
            func_800A6670(4, &D_801A99A8[4]);
            func_80005460();
        }
        func_800A6670(0, D_801A7340);
        func_800A6670(4, &D_801A7340[4]);
    }
    *D_801A8D88 &= ~4;
    D_80156190 = D_801AA4A8[0];
    D_80156194 = D_801AA4A8[1];
    D_80156198 = D_801AA4A8[2];
    D_8015619C = D_801AA4A8[3];
    Thread_ResetMqValidCount(threadEntry->threadId);
    func_80098820();
}
