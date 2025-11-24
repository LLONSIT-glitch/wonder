#ifndef MATH_H
#define MATH_H
typedef struct Vec3f_s {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;


f32 MathUtil_MultiplyVec3fComponents(Vec3f* vec1, Vec3f* vec2);
f32 MathUtil_Sinf(f32);
f32 MathUtil_Cosf(f32);
#endif /* MATH_H */

