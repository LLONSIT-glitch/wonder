#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005D150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005D2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005D394.s")

extern u32 D_80180658;
extern s32 D_80180660;
extern u32 D_809DF1C4;
typedef struct UnkStruct_8005D6BC_s {
    s16 unk0;
    s8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
} UnkStruct_8005D6BC;

typedef struct UnkStruct_8005D6BC_sp28_s {
    s16 unk0;
    char pad[0x8];
    char unkA;
    s16 unk10;
    char pad1[0x4];
} UnkStruct_8005D6BC_sp28;

void* func_8005D6BC(void) {
    u32 sp34;
    void* sp30;
    UnkStruct_8005D6BC* sp2C;
    UnkStruct_8005D6BC_sp28* sp28;
    sp30 = SysMem_HeapAllocMark(D_80180658 * 6);
    SysMem_DmaCopy((u32) SysMem_GetPhysicalAddressFromVirtual((u32) Seg_6A69E0_ROM_START, (s32) &Seg_6A69E0_VRAM, (s32) &D_809DF1C4), sp28 = SysMem_HeapAlloc(D_80180660), D_80180660);
    for (sp34 = 0, sp2C = sp30; sp34 < (u32) D_80180658; sp34++, sp2C++) {
        sp2C->unk0 = (sp28 + sp34)->unk0;
        sp2C->unk2 = 3;
        sp2C->unk3 = 0;
        sp2C->unk4 = sp28->unkA;
    }
    SysMem_Free(sp28);
    return sp30;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005D800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005E19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005E474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005E908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005EB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005EC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005EF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005F01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005F064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005F0DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005F268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005F31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005F410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_5DD50/func_8005FC18.s")
