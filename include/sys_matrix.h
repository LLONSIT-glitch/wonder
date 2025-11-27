#ifndef SYS_MATRIX_H
#define SYS_MATRIX_H

typedef struct LookAtParams_s {
    /* 0x0 */ Vec3f unk0; 
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
    /* 0x24 */ Vec3f unk24;
} LookAtParams;                                                  /* size = 0x30 */
void func_800B1250(Gfx** gdl, LookAtParams* arg1, u16 arg2);
#endif /* SYS_MATRIX_H */
