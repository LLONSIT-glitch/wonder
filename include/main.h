#ifndef MAIN_H
#define MAIN_H
void Main_BootProc(void* arg);
UNUSED s32 Main_ContInit(s32 arg0);
void Main_GfxClearScreen(Gfx** gdl);
void Main_GfxFullSync(void);
void Main_GfxInit(void);
void Main_GfxSetSegments(Gfx** gdl);
void Main_IdleThreadEntry(void* entry);
int Main_SetContRawStickScale(s32 controller, f32 scaleX, f32 scaleY);
void Main_SetContStickScale(f32 x, f32 y);
void Main_Unused(s32 arg0, s32 arg1);
UNUSED void Main_UpdateControllers(s32 contInitialized);
void func_800BD8D4(s32 arg0, UNUSED s32 arg1);
void func_800BD9D0(s32 mode, s32 arg1);
void func_800BDA58(u32 arg0);
void func_800BDC70(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800BDE6C(s32 arg0);
void func_800BE068(void);
void func_800BE08C(void);
void func_800BE0C4(void);
void func_800BE4EC(void);
void func_800BE510(f32 arg0, f32 arg1, f32 arg2);
void func_800BE684(void);
#endif /* MAIN_H */
