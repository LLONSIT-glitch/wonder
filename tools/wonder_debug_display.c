void *func_800045AC(?);                             /* extern */
s32 func_80004654(?);                               /* extern */
? func_8001AB84();                                  /* extern */
? func_8001AC74();                                  /* extern */
s32 func_8005F064(u16);                             /* extern */
? func_8005F0DC(u16);                               /* extern */
? func_8005F268(u16);                               /* extern */
? func_8008EAA8(?, ?);                              /* extern */
? func_8008EC8C(?, ?);                              /* extern */
? func_8008ECAC(?, ?);                              /* extern */
? func_8008ECE4(? *, s32, s32, f64);                /* extern */
? func_80090728(?);                                 /* extern */
? func_80090754(?);                                 /* extern */
? func_80096474();                                  /* extern */
? func_800967D8();                                  /* extern */
? func_800974C0(? *);                               /* extern */
? func_80098820();                                  /* extern */
? func_80098868();                                  /* extern */
? func_80098D24(s32);                               /* extern */
? func_80099520();                                  /* extern */
? func_800A424C(? *, s32);                          /* extern */
? func_800A4638(? *);                               /* extern */
void *func_800BB448(s32);                           /* extern */
? func_800BB4B4(void *, ?);                         /* extern */
? func_800C1264(u8, ? *, ?);                        /* extern */
? func_800C1754();                                  /* extern */
? func_800C1A28();                                  /* extern */
? func_800C2304(?, ?, ?);                           /* extern */
void func_80031E3C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4); /* static */
extern s32 D_800DB880;
extern s32 gSysThreadIds;
extern ? D_80153E30;
extern ? D_801560F0;
extern ? D_801560F6;
extern ? D_801560F8;
extern ? D_80156104;
extern void *D_80156C10;
extern s32 D_8015B320;
extern s32 D_8015B328;
extern s32 D_801806C4;
extern u8 D_80180FF8;
extern void *D_801A30B0;
extern s32 D_801A72DC;
extern ? D_801A8D88;
extern ? D_801AB460;
extern ? D_801AB578;
extern OSMesgQueue D_801AC870;
extern s32 D_801AC878;

s32 func_80031C90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *sp24;

    if (!(arg0 & 0xFF)) {
        if (func_80004654(0x14) < 0) {
            return -1;
        }
        sp24 = D_80156C10;
        func_80031E3C(sp24, arg0 & 0xFF00, arg1, arg2, arg3);
        return 1;
    }
    if (!(arg0 & 0x100)) {
        sp24 = func_800045AC(0x14);
        if (sp24 == NULL) {
            return 0;
        }
        func_80031E3C(sp24, arg0 & 0xFF00, arg1, arg2, arg3);
        return 2;
    }
    return 0;
}

s32 func_80031D94(void *arg0) {
    s32 sp4;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t5;

    arg0->unk1A8 = 0;
    arg0->unk1AC = -1;
    arg0->unk208 = 0;
    sp4 = 0;
    do {
        (arg0 + (sp4 * 8))->unk1EC = 0.0f;
        temp_t1 = sp4 * 8;
        (arg0 + temp_t1)->unk1E8 = (f32) (arg0 + temp_t1)->unk1EC;
        temp_t5 = sp4 + 1;
        sp4 = temp_t5;
    } while (temp_t5 < 4);
    sp4 = 0;
    do {
        (arg0 + (sp4 * 4))->unk20C = 0;
        temp_t0 = sp4 + 1;
        sp4 = temp_t0;
    } while (temp_t0 < 8);
    return 0;
}

void func_80031E3C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *sp1C;
    s32 temp_t1;

    if (arg0->unk1AC < 0) {
        arg0->unk1AC = arg2;
        sp1C = func_800BB448(arg2);
        if (sp1C != NULL) {
            (arg0 + (arg0->unk208 * 4))->unk20C = sp1C;
            arg0->unk208 = (u16) (arg0->unk208 + 1);
            sp1C->unkC = arg3;
            sp1C->unk1A = (s8) arg4;
            func_800BB4B4(sp1C, 4);
            temp_t1 = arg3 / 256;
            if (((s32) (0x80 - temp_t1) / 8) > 0) {
                arg0->unk1EC = (f32) ((s32) (0x80 - temp_t1) / 8);
            } else {
                arg0->unk1EC = (f32) -((s32) (0x80 - (arg3 / 256)) / 8);
            }
        }
        arg0->unk1F0 = (f32) arg3;
        arg0->unk1F4 = (f32) arg4;
        arg0->unk1A8 = arg1;
    }
}

s32 func_80031FF4(void *arg0) {
    s32 sp2C;
    s32 sp28;
    void *sp24;
    f32 temp_fs0;
    s32 temp_t1;
    s32 temp_t2;
    void *temp_t0;

    sp2C = 0;
    sp28 = 0;
    do {
        temp_t0 = (arg0 + (sp2C * 4))->unk20C;
        sp24 = temp_t0;
        if (temp_t0 != NULL) {
            if (sp24->unk4 & 2) {

            } else {
                (arg0 + (sp2C * 4))->unk20C = 0;
            }
        } else {
            sp28 += 1;
        }
        temp_t1 = sp2C + 1;
        sp2C = temp_t1;
    } while (temp_t1 < 3);
    if (sp28 == 3) {
        arg0->unk1A0 = 0;
        return -1;
    }
    if (!(arg0->unk1A8 & 0x100) && ((s32) arg0->unk208 < 3)) {
        temp_fs0 = arg0->unk1E8 + D_8018257C;
        arg0->unk1E8 = temp_fs0;
        if (arg0->unk1EC < temp_fs0) {
            arg0->unk1E8 = 0.0f;
            if ((f64) arg0->unk1EC > 3.0) {
                sp24 = func_800BB448(arg0->unk1AC);
                if (sp24 != NULL) {
                    sp24->unkC = (s32) (arg0->unk1F0 - (f32) (arg0->unk208 << 0xB));
                    if (sp24->unkC < 0x1000) {
                        sp24->unkC = 0x1000;
                    }
                    sp24->unk1A = (s8) (s16) (s32) arg0->unk1F4;
                    (arg0 + (arg0->unk208 * 4))->unk20C = sp24;
                    arg0->unk208 = (u16) (arg0->unk208 + 1);
                    func_800BB4B4(sp24, 4);
                }
            }
            temp_t2 = (s32) arg0->unk1F0 / 256;
            if (((s32) (0x80 - temp_t2) / 8) > 0) {
                arg0->unk1EC = (f32) ((s32) (0x80 - temp_t2) / 8);
            } else {
                arg0->unk1EC = (f32) -((s32) (0x80 - ((s32) arg0->unk1F0 / 256)) / 8);
            }
        }
    }
    return 0;
}

void func_80032380(void) {
    ? *sp34;
    void *sp1C;

    sp34 = &D_80153E30;
    if (D_801806C4 == 0) {
        func_800974C0(&D_80153E30);
    } else {
        func_800C1264(D_80180FF8, sp34, 0);
        do {
            Thread_ReceiveMsg(&D_801AC870, &sp1C, 1);
        } while (D_801AC878 != 0);
    }
}

void func_80032410(void *arg0) {
    void *sp2C;
    s32 sp28;
    s16 temp_s0;
    void *temp_t7;
    void *temp_t9;

    arg0->unk18->unk82EC = 0;
    sp28 = D_8018258C;
    if (arg0->unk18->unk82EC == 0) {
        do {
            func_800C143C(arg0->unk0, &sp2C, 1);
            temp_s0 = *sp2C;
            switch (temp_s0) {                      /* irregular */
            case 1:
                if (!(D_801A72DC & 0x20) && (sp28 != D_8018258C)) {
                    temp_t9 = arg0->unk18;
                    temp_t9->unk82EC = (s32) (temp_t9->unk82EC + 1);
                }
                break;
            case 6:
                if (!(D_801A72DC & 0x20) && (sp28 != D_8018258C)) {
                    temp_t7 = arg0->unk18;
                    temp_t7->unk82EC = (s32) (temp_t7->unk82EC + 1);
                }
                break;
            }
        } while (arg0->unk18->unk82EC == 0);
    }
    if (arg0->unk18->unk82D8 != 0) {
        do {
            func_800C143C(arg0->unk0, &sp2C, 1);
        } while (arg0->unk18->unk82D8 != 0);
    }
}

void func_80032604(void) {
    s32 sp2C;
    s32 temp_t0;
    u16 temp_s0;
    void *temp_t0_2;
    void *temp_t9;

    sp2C = 0;
    do {
        if (D_80180DA8[sp2C].state != -1) {
            SysMem_Copy8((sp2C * 0x28) + &D_801560F0, &D_80180DA8[sp2C], 0x28);
        } else {
            *(&D_801560F0 + (sp2C * 0x28)) = -1;
            *(&D_801560F8 + (sp2C * 0x28)) = 0;
            temp_t0_2 = (sp2C * 0x28) + &D_801560F0;
            temp_s0 = temp_t0_2->unk8;
            temp_t0_2->unk4 = temp_s0;
            *(&D_801560F6 + (sp2C * 0x28)) = temp_s0;
            temp_t9 = (sp2C * 0x28) + &D_801560F0;
            *(&D_80156104 + (sp2C * 0x28)) = 0.0f;
            temp_t9->unk10 = (f32) temp_t9->unk14;
        }
        temp_t0 = sp2C + 1;
        sp2C = temp_t0;
    } while (temp_t0 < 4);
}

void func_8003276C(? *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, ? *arg5, f32 arg6, f32 arg7) {
    func_800A424C(arg0, sp1C);
    arg0->unkEC = (s16) arg1;
    arg0->unkF0 = (s16) arg3;
    arg0->unkEE = (s16) arg2;
    arg0->unkF2 = (s16) arg4;
    arg0->unkE8 = arg5;
    arg0->unkF4 = arg6;
    arg0->unkF8 = arg7;
    arg0->unkE0 = SysMem_HeapAlloc(0x400);
    arg0->unkE4 = SysMem_HeapAlloc(0x400);
}

void func_80032844(? *arg0, f32 arg1, f32 arg2) {
    arg0->unkFC = 0.0f;
    arg0->unk100 = 0.0f;
    arg0->unk104 = arg1;
    arg0->unk108 = arg2;
}

void func_8003288C(? *arg0) {
    s32 *sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 *sp3C;
    s32 *sp38;
    s32 *sp34;
    s32 *sp30;
    s32 *sp2C;
    s32 *sp28;
    s32 *sp24;
    s32 *sp20;
    s32 *sp1C;
    s32 *sp18;
    s32 *sp14;
    s32 *sp10;
    s32 *spC;
    s32 *temp_t0_2;
    s32 *temp_t0_3;
    s32 *temp_t0_4;
    s32 *temp_t3;
    s32 *temp_t3_2;
    s32 *temp_t3_3;
    s32 *temp_t3_4;
    s32 *temp_t4;
    s32 *temp_t5;
    s32 *temp_t7;
    s32 *temp_t8;
    s32 *temp_t9;
    s32 *temp_t9_2;
    s32 temp_t0;
    s32 temp_t2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_a2;
    s32 var_a3;

    sp64 = (arg0 + (D_801824FC * 4))->unkE0;
    arg0->unkD8 = sp64;
    arg0->unkFC = (f32) (arg0->unkFC + arg0->unk104);
    arg0->unk100 = (f32) (arg0->unk100 + arg0->unk108);
    if (arg0->unk104 >= 0.0f) {
        if (arg0->unkF4 < arg0->unkFC) {
            arg0->unkFC = (f32) (arg0->unkFC - arg0->unkF4);
        }
    } else if (arg0->unkFC < 0.0f) {
        arg0->unkFC = (f32) (arg0->unkFC + arg0->unkF4);
    }
    if (arg0->unk108 >= 0.0f) {
        if (arg0->unkF8 < arg0->unk100) {
            arg0->unk100 = (f32) (arg0->unk100 - arg0->unkF8);
        }
    } else if (arg0->unk100 < 0.0f) {
        arg0->unk100 = (f32) (arg0->unk100 + arg0->unkF8);
    }
    if ((arg0->unkF0 - arg0->unkEC) > 0) {
        var_a1 = arg0->unkF0 - arg0->unkEC;
    } else {
        var_a1 = -(arg0->unkF0 - arg0->unkEC);
    }
    sp60 = (((f32) var_a1 / arg0->unkF4) + arg0->unkFC) * 64.0f;
    if ((arg0->unkF2 - arg0->unkEE) > 0) {
        var_a1_2 = arg0->unkF2 - arg0->unkEE;
    } else {
        var_a1_2 = -(arg0->unkF2 - arg0->unkEE);
    }
    sp5C = (((f32) var_a1_2 / arg0->unkF8) + arg0->unk100) * 64.0f;
    if ((arg0->unkF0 - arg0->unkEC) > 0) {
        var_a1_3 = arg0->unkF0 - arg0->unkEC;
    } else {
        var_a1_3 = -(arg0->unkF0 - arg0->unkEC);
    }
    sp58 = ((((f32) var_a1_3 * arg0->unkF4) / arg0->unkF4) + arg0->unkFC) * 64.0f;
    if ((arg0->unkF2 - arg0->unkEE) > 0) {
        var_a1_4 = arg0->unkF2 - arg0->unkEE;
    } else {
        var_a1_4 = -(arg0->unkF2 - arg0->unkEE);
    }
    sp54 = ((((f32) var_a1_4 * arg0->unkF8) / arg0->unkF8) + arg0->unk100) * 64.0f;
    sp40 = (s32) (arg0->unkF4 / 4.0f) & 0xFF;
    sp48 = 8;
loop_25:
    if (sp40 & 0x80) {
        if (sp40 & 0x7F) {
            sp48 = 0;
        }
    } else {
        sp40 *= 2;
        temp_t0 = sp48 - 1;
        sp48 = temp_t0;
        if (temp_t0 > 0) {
            goto loop_25;
        }
    }
    sp40 = (s32) (arg0->unkF8 / 4.0f) & 0xFF;
    sp44 = 8;
loop_31:
    if (sp40 & 0x80) {
        if (sp40 & 0x7F) {
            sp44 = 0;
        }
    } else {
        sp40 *= 2;
        temp_t2 = sp44 - 1;
        sp44 = temp_t2;
        if (temp_t2 > 0) {
            goto loop_31;
        }
    }
    temp_t3 = sp64;
    sp64 = temp_t3 + 8;
    sp3C = temp_t3;
    sp3C->unk0 = 0xBB000001;
    sp3C->unk4 = 0x80008000;
    temp_t9 = sp64;
    sp64 = temp_t9 + 8;
    sp38 = temp_t9;
    sp38->unk0 = 0x04300040;
    sp38->unk4 = (void *) D_801A30B0;
    D_801A30B0->unk0 = (s16) arg0->unkEC;
    D_801A30B0->unk2 = (s16) arg0->unkEE;
    D_801A30B0->unk4 = 0;
    D_801A30B0->unk8 = (s16) (s32) sp60;
    D_801A30B0->unkA = (s16) (s32) sp5C;
    D_801A30B0->unk6 = 0;
    D_801A30B0->unkC = 0xFF;
    D_801A30B0->unkD = 0xFF;
    D_801A30B0->unkE = 0xFF;
    D_801A30B0->unkF = 0xFF;
    D_801A30B0 += 0x10;
    D_801A30B0->unk0 = (s16) arg0->unkF0;
    D_801A30B0->unk2 = (s16) arg0->unkEE;
    D_801A30B0->unk4 = 0;
    D_801A30B0->unk8 = (s16) (s32) sp58;
    D_801A30B0->unkA = (s16) (s32) sp5C;
    D_801A30B0->unk6 = 0;
    D_801A30B0->unkC = 0xFF;
    D_801A30B0->unkD = 0xFF;
    D_801A30B0->unkE = 0xFF;
    D_801A30B0->unkF = 0xFF;
    D_801A30B0 += 0x10;
    D_801A30B0->unk0 = (s16) arg0->unkEC;
    D_801A30B0->unk2 = (s16) arg0->unkF2;
    D_801A30B0->unk4 = 0;
    D_801A30B0->unk8 = (s16) (s32) sp60;
    D_801A30B0->unkA = (s16) (s32) sp54;
    D_801A30B0->unk6 = 0;
    D_801A30B0->unkC = 0xFF;
    D_801A30B0->unkD = 0xFF;
    D_801A30B0->unkE = 0xFF;
    D_801A30B0->unkF = 0xFF;
    D_801A30B0 += 0x10;
    D_801A30B0->unk0 = (s16) arg0->unkF0;
    D_801A30B0->unk2 = (s16) arg0->unkF2;
    D_801A30B0->unk4 = 0;
    D_801A30B0->unk8 = (s16) (s32) sp58;
    D_801A30B0->unkA = (s16) (s32) sp54;
    D_801A30B0->unk6 = 0;
    D_801A30B0->unkC = 0xFF;
    D_801A30B0->unkD = 0xFF;
    D_801A30B0->unkE = 0xFF;
    D_801A30B0->unkF = 0xFF;
    D_801A30B0 += 0x10;
    temp_t3_2 = sp64;
    sp64 = temp_t3_2 + 8;
    sp34 = temp_t3_2;
    sp34->unk0 = 0xFD100000;
    sp34->unk4 = (s32) (arg0->unkE8 & 0x1FFFFFFF);
    temp_t0_2 = sp64;
    sp64 = temp_t0_2 + 8;
    sp30 = temp_t0_2;
    sp30->unk0 = 0xF5100000;
    sp30->unk4 = (s32) (((sp44 & 0xF) << 0xE) | 0x07000000 | ((sp48 & 0xF) * 0x10));
    temp_t3_3 = sp64;
    sp64 = temp_t3_3 + 8;
    sp2C = temp_t3_3;
    sp2C->unk0 = 0xE6000000;
    sp2C->unk4 = 0;
    temp_t9_2 = sp64;
    sp64 = temp_t9_2 + 8;
    sp28 = temp_t9_2;
    sp28->unk0 = 0xF3000000;
    if ((((s32) arg0->unkF4 * (s32) arg0->unkF8) - 1) < 0x7FF) {
        var_a3 = ((s32) arg0->unkF4 * (s32) arg0->unkF8) - 1;
    } else {
        var_a3 = 0x7FF;
    }
    if (((s32) ((s32) arg0->unkF4 * 2) / 8) <= 0) {
        var_a2 = 1;
    } else {
        var_a2 = (s32) ((s32) arg0->unkF4 * 2) / 8;
    }
    if (((s32) ((s32) arg0->unkF4 * 2) / 8) <= 0) {
        var_a1_5 = 1;
    } else {
        var_a1_5 = (s32) ((s32) arg0->unkF4 * 2) / 8;
    }
    sp28->unk4 = (s32) ((((s32) (var_a2 + 0x7FF) / var_a1_5) & 0xFFF) | (((var_a3 & 0xFFF) << 0xC) | 0x07000000));
    temp_t3_4 = sp64;
    sp64 = temp_t3_4 + 8;
    sp24 = temp_t3_4;
    sp24->unk0 = 0xE7000000;
    sp24->unk4 = 0;
    temp_t7 = sp64;
    sp64 = temp_t7 + 8;
    sp20 = temp_t7;
    *temp_t7 = ((((s32) (((s32) arg0->unkF4 * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
    sp20->unk4 = (s32) (((sp44 & 0xF) << 0xE) | ((sp48 & 0xF) * 0x10));
    temp_t0_3 = sp64;
    sp64 = temp_t0_3 + 8;
    sp1C = temp_t0_3;
    sp1C->unk0 = 0xF2000000;
    sp1C->unk4 = (s32) ((((((s32) arg0->unkF4 - 1) * 4) & 0xFFF) << 0xC) | ((((s32) arg0->unkF8 - 1) * 4) & 0xFFF));
    temp_t5 = sp64;
    sp64 = temp_t5 + 8;
    sp18 = temp_t5;
    sp18->unk0 = 0xBF000000;
    sp18->unk4 = 0x1E0A;
    temp_t8 = sp64;
    sp64 = temp_t8 + 8;
    sp14 = temp_t8;
    sp14->unk0 = 0xBF000000;
    sp14->unk4 = 0x141E;
    temp_t0_4 = sp64;
    sp64 = temp_t0_4 + 8;
    sp10 = temp_t0_4;
    sp10->unk0 = 0xE7000000;
    sp10->unk4 = 0;
    temp_t4 = sp64;
    sp64 = temp_t4 + 8;
    spC = temp_t4;
    spC->unk0 = 0xB8000000;
    spC->unk4 = 0;
}

void func_80033614(void) {
    s32 sp34;
    s32 sp30;
    ? *sp2C;
    s32 temp_t1;
    s32 temp_t9;

    sp2C = &D_801AB460;
    if (D_800DB880 == 0) {
        D_800DB880 += 1;
        sp30 = 0;
        do {
            sp34 = 0;
loop_3:
            *(&D_801AB578 + ((sp34 + (sp30 << 6)) * 2)) = ((guRandom() % 32767) * 2) | 1;
            temp_t9 = sp34 + 1;
            sp34 = temp_t9;
            if (temp_t9 < 0x40) {
                goto loop_3;
            }
            temp_t1 = sp30 + 1;
            sp30 = temp_t1;
        } while (temp_t1 < 0x20);
        func_8003276C(sp2C, -0x80, -0x80, 0x80, 0x80, &D_801AB578, 64.0f, 32.0f);
        sp2C->unkC0 = (s32) (sp2C->unkC0 | 0x800);
        sp2C->unkC4 = 8;
        func_80032844(sp2C, 0.5f, 0.5f);
    }
    func_8003288C(sp2C);
    func_800C1754();
    func_800C2304(0, 0, 0xC2200000);
    func_800A4638(sp2C);
    func_800C1A28();
}

void func_80033788(void) {
    s32 sp2C;
    s32 temp_s1;
    s32 temp_t3;

    func_8001AB84();
    func_8008EAA8(0, 0);
    func_8008ECE4(" vinc=%08x V-Average=%f\n", D_8018258C, second half of f64, (f64) D_8018257C);
    func_8008ECE4(" Mem Lock:$%08x Unlock:$%08x\n", SysMem_GetLockedSize(), SysMem_GetUnlockedSize());
    sp2C = (s32) sHeapBlocksCount;
    func_8008ECE4(" Mem free:$%08x Mem Block size:%3d\n", SysMem_GetFreeSpace(), sp2C);
    func_8008ECE4(" system_flags\n");
    sp2C = 0;
    do {
        func_8008ECE4("%d:$%04x ", sp2C, (s32) *(&D_801A8D88 + (sp2C * 2)));
        if (((s32) (sp2C + 1) % 4) == 0) {
            func_8008ECE4("\n");
        }
        temp_t3 = sp2C + 1;
        sp2C = temp_t3;
    } while (temp_t3 < 8);
    func_8001AC74();
}

void func_800338D0(void) {
    s32 sp3C;
    u8 *sp38;
    void *sp34;
    void *sp30;
    void *sp2C;
    void *sp28;

    sp38 = &D_800F1918;
    sp34 = sp38->unk18;
    if (sp34->unk82EC > 0) {
        if (sp34->unk82EC > 0) {
            do {
                func_800C143C(sp38->unk0, &sp30, 1);
                if (*sp30 == 2) {
                    func_80099520();
                    sp34->unk82EC = (s32) (sp34->unk82EC - 1);
                }
            } while (sp34->unk82EC > 0);
        }
        func_80098820();
        func_80098868();
    }
    sp3C = 0;
    if (sp3C == 0) {
        do {
            func_800C143C((u8) gSysThreadIds, &sp30, 1);
            if (*sp30 == 1) {
                func_80032604();
                func_80096474();
                Sys_SwapFrameBuffer(osViGetCurrentFramebuffer());
                func_8008EC8C(0x43A00000, 0x43700000);
                func_8008ECAC(0x43A00000, 0x43700000);
                func_80090754(0x4E8);
                func_80090728(0x200);
                func_8008EAA8(0xA, 0xA);
                sp2C = func_800045AC(3);
                sp28 = sp2C->unk20C;
                D_8015B328 = 0xFF;
                D_8015B320 = 0x10;
                func_8008ECE4("フラグを選択して下さい[%3d] ", (s32) *sp28->unkC);
                func_8008EAA8(0xA, 0xB);
                if (func_8005F064(*sp28->unkC) != 0) {
                    func_8008ECE4("現在 ON  ");
                } else {
                    func_8008ECE4("現在 OFF ");
                }
                func_8008ECE4(" PAD A:ON B:OFF");
                func_8008EAA8(0xA, 0xC);
                func_8008ECE4(" PAD Z/START EXIT");
                if (D_801560F0.unk6 & D_80180FF4) {
                    func_8005F0DC(*sp28->unkC);
                } else if (D_801560F0.unk6 & (u16) D_8018101C) {
                    func_8005F268(*sp28->unkC);
                }
                func_800967D8();
                if (D_801560F0.unk6 & ((u16) D_801810F2 | (u16) D_801811A4)) {
                    sp3C += 1;
                }
                func_80098D24(gSysThreadIds);
            }
        } while (sp3C == 0);
    }
}
