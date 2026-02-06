#include "common.h"

#ifdef __GNUC__
// Because of those ugly assignments we will have to use this to avoid gcc always complaining about them..
#pragma GCC diagnostic ignored "-Wsequence-point"
#endif

#define ROUND(x) (x >= 0.0) ? (x + 0.5) : (x - 0.5)

extern f64 D_800EFEB8;
extern f64 D_800EFEC0;
extern f64 D_800EFEB0;
extern f64 D_800EFEC8;
extern f64 D_800EFED0;
extern f64 D_800EFED8;

extern f64 D_800EAA80;
extern f32 D_800EAA88;
extern f64 D_800EAA90;

typedef struct f645 {
    f64 a, b, c, d, e;
} f645;

extern f645 D_800EAA98[];

f32 func_800C38F4(f32); /* extern */

#ifdef NEEDS_RODATA
f32 MathUtil_Sinf(f32 x) {
    f64 dx;     // sp20
    f64 xsq;    // sp18
    f64 poly;   // sp10
    f32 spC;    // spC
    s32 number; // sp8
    s32 ix;     // sp4

    if ((ix = (*(s32*) &x >> 0x16) & 0x1FF) < 0xE6) {
        return x;
    }

    dx = x;
    if (ix < 255) {
        xsq = SQ(dx);

        return (dx * xsq) * ((((D_800EAA98->d * xsq) + D_800EAA98->c) * xsq + D_800EAA98->b) * xsq + D_800EAA98->a) +
               dx;
    }

    if (ix < 310) {

        number = ROUND(dx * 0.318309886183790691);

        xsq = (dx = (dx - ((poly = number) * 3.14159262180328369)) - (poly * 3.17865095470563921e-08)) * dx;

        spC = (dx * xsq) * ((((D_800EAA98->d * xsq) + D_800EAA98->c) * xsq + D_800EAA98->b) * xsq + D_800EAA98->a) + dx;

        return number & 1 ? -spC : spC;
    }
    return 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/math_util/MathUtil_Sinf.s")
#endif

#ifdef NEEDS_RODATA
#define ROUND(x) (s32)(((x) >= 0.0f) ? ((x) + 0.5f) : ((x) - 0.5f))

f32 MathUtil_Cosf(f32 arg0) {
    f64 sp30;
    f64 sp28;
    f64 poly;
    f32 sp1C;
    s32 number;

    if (((*(s32*)&arg0 >> 0x16) & 0x1FF) < 0x136) {
        number = ROUND((((sp30 = FABS(arg0)) * 0.318309886183790691) + 0.5));
       
        sp28 = (sp30 = (sp30 - ((poly = number - 0.5) * 3.14159262180328369)) - (poly * 3.17865095470563921e-08)) * sp30;
        sp1C = (f32)sp30 + (sp30 * sp28 * ((((((D_800EAA98->d * sp28) + D_800EAA98->c) * sp28) + D_800EAA98->b) * sp28) + D_800EAA98->a));

        return number & 1 ? -sp1C : sp1C;
    }
    return 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/math_util/MathUtil_Cosf.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/code/math_util/func_800C3650.s")

f32 func_800C3808(f32 arg0) {
    return func_800C38F4(arg0 / sqrtf((f32) (1.0 - (f64) (arg0 * arg0))));
}

f32 func_800C3874(f32 arg0) {
    return (f32) (D_800EFEB0 - (f64) func_800C38F4(arg0 / sqrtf((f32) (1.0 - (f64) (arg0 * arg0)))));
}

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

f32 func_800C3A34(f32 arg0, f32 arg1) {
    f32 sp1C;

    if (arg0 == 0.0) {
        sp1C = 0.0f;
    } else if (arg0 > 0.0) {
        if (arg1 >= 0.0) {
            sp1C = func_800C38F4(arg1 / arg0);
        } else {
            sp1C = (D_800EFEC8 - func_800C38F4(-arg1 / arg0));
        }
    } else {
        arg0 = (arg0 * -1.0);
        if (arg1 >= 0.0) {
            sp1C = (D_800EFED0 - func_800C38F4(arg1 / arg0));
        } else {
            sp1C = (func_800C38F4(-arg1 / arg0) + D_800EFED8);
        }
    }
    return sp1C;
}

f32 MathUtil_MultiplyVec3fComponents(Vec3f* vec1, Vec3f* vec2) {
    return (vec2->z * vec1->z) + ((vec1->x * vec2->x) + (vec1->y * vec2->y));
}

f32 MathUtil_GetDistance2D(f32 x1, f32 y1, f32 x2, f32 y2) {
    f32 dx;
    f32 dy;

    return sqrtf(((dx = (x1 - x2)) * dx) + (dy = (y1 - y2)) * dy);
}
#define DIFF_SQ(x, y) ((x = x - y) * x)

f32 MathUtil_GetDistanceIfWithinRadius(f32 x1, f32 y1, f32 z1, f32 mag1, f32 x2, f32 y2, f32 z2, f32 mag2) {
    mag1 += mag2; // Calculate a max distance to use it as a limit to calc the new distance

    mag2 = sqrtf((DIFF_SQ(x1, x2) + DIFF_SQ(y1, y2) + DIFF_SQ(z1, z2)));
    if (mag2 <= mag1) {
        return mag2;
    }
    return -1.0f;
}

void func_800C3D70(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32* arg6) {
    s32 i;
    f32 sp50[3];
    f32 distance;

    if ((x1 == x2) && (y1 == y2) && (z1 == z2)) {
        arg6[6] = 0.0f;
    } else {
        distance = arg6[6] =
            sqrtf(((sp50[0] = x1 - x2) * sp50[0]) + ((sp50[1] = y1 - y2) * sp50[1]) + ((sp50[2] = z1 - z2) * sp50[2]));
        for (i = 0; i < 3; i++) {
            arg6[i] = sp50[i] / distance;
        }
        arg6[3] = x1;
        arg6[4] = y1;
        arg6[5] = z1;
    }
}

s32 func_800C3F2C(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32 arg4) {
    f32 sp4;
    f32* sp0;

    arg4 *= D_8018257C;
    if ((sp4 = arg0[6]) != 0.0) {
        sp0 = arg0;
        if (sp4 > arg4) {
            sp4 = arg4;
            arg0[6] -= arg4;
            *arg1 += *(sp0++) * sp4;
            *arg2 += *(sp0++) * sp4;
            *arg3 += *sp0 * sp4;
        } else {
            arg0[6] = 0.0f;
            *arg1 = arg0[3];
            *arg2 = arg0[4];
            *arg3 = arg0[5];
        }
        return 1;
    }
    return 0;
}
