#include "common.h"

s16 func_80048DC4(UnkStruct_80048C30* arg0);
void func_80048F40(UnkStruct_80048C30*);

s32 func_80048C30(UnkStruct_80048C30* arg0, u16* start, f32 arg2) {
    u16 i;
    u16 count;
    u16* startPtr;
    u16* sp24;

    if ((arg0 == NULL) || (start == NULL)) {
        return -1;
    }
    arg0->unk0 = arg2;

    startPtr = start;
    count = 0;

    while (*startPtr++ != 0xFFFF) {
        count++;
    }

    if (count == 0) {
        return -2;
    }

    sp24 = arg0->unk10 = SysMem_HeapAlloc(count * sizeof(u16));
    startPtr = start;
    for (i = 0; i < count; i++) {
        *sp24++ = *startPtr++;
    }
    arg0->unk8 = count;
    func_80048F40(arg0);
    return 0;
}

s16 func_80048DC4(UnkStruct_80048C30* arg0) {
    u16 spE;
    u16 spC;
    u16 spA;
    f32 sp4;
    f32 sp0;

    if ((sp4 = arg0->unk0) != 65536.0f) {
        if (sp4 < (sp0 = arg0->unk4 + D_8018257C)) {
            arg0->unkC |= 3;
        }
        arg0->unk4 = sp0;
    }
    spC = arg0->unkC;

    if (((spE = gControllers->unk6) == 0) || (spC & 1)) {
        return spC;
    }
    spA = arg0->unkA;
    if (arg0->unk10[spA] != spE) {
        spC |= 2;
    }
    spA += 1;
    if (spA == arg0->unk8) {
        spC |= 1;
        if (!(spC & 2)) {
            spC |= 0x8000;
        }
    }
    arg0->unkC = spC;
    arg0->unkA = spA;
    return (s16) spC;
}

void func_80048F40(UnkStruct_80048C30* arg0) {
    if (arg0 == NULL) {
        return;
    }
    arg0->unkC = 0;
    arg0->unkA = arg0->unkC;
    arg0->unk4 = 0.0f;
}
