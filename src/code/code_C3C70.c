#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/MathUtil_Sinf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/MathUtil_Cosf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3874.s")

extern f64 D_800EFEB8;
extern f64 D_800EFEC0;

f32 func_800C38F4(f32 arg0) {
    s32 sp4;
    f32 sp0;

    sp4 = 0;
    if (arg0 > 1.0) {
        sp4++;
        arg0 = (1.0 / arg0);
    } else if (arg0 < -1.0) {
        sp4 -= 1;
        arg0 = (1.0 / arg0);
    }
    sp0 = (arg0 / (1.0 + ((arg0 * arg0) * D_800EFEB8)));
    if (sp4 != 0) {
        return (f32) ((D_800EFEC0 - (f64) sp0) * (f64) sp4);
    }
    return sp0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3A34.s")

f32 MathUtil_MultiplyVec3fComponents(Vec3f* vec1, Vec3f* vec2) {
    return (vec2->z * vec1->z) + ((vec1->x * vec2->x) + (vec1->y * vec2->y));
}

#ifdef NON_MATCHING
float MathUtil_GetDistance2D(float x1, float y1, float x2, float y2) {
    register float dx = x1 - x2;
    register float dy = y1 - y2;

    return sqrtf(SQ(dx) + SQ(dy));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/MathUtil_GetDistance2D.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/code_C3C70/func_800C3F2C.s")
