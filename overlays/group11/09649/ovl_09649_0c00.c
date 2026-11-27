#include "common.h"

extern s32 D_01B0D6B0;
extern s32 D_01B0D6B4;
extern u8 D_01B13FE0[];
extern u8 D_01BE9C10[];

extern void func_01B05E38(void);
extern void func_01B07FA0(void);
extern void func_01B08688(void);
extern void func_01B09108(void);
extern void func_002B22F8(s32, s32);
extern void func_01B01700(void);
extern void func_002B4980(void *);
extern void func_01B07870(void *, s32, s32);
extern void func_01B08138(void *, s32, s32);

s32 func_01B01500(s32 a0)
{
    D_01B0D6B0 = a0;
    func_01B05E38();
    func_01B07FA0();
    func_01B08688();
    func_01B09108();
    func_002B22F8(0x3400, 0x800);
    func_01B01700();
    func_002B4980(D_01B13FE0);
    func_01B07870(D_01B13FE0, 0, 1000);
    func_01B08138(D_01B13FE0, 0, 1000);
    func_002B4980(D_01BE9C10);
    func_01B08138(D_01BE9C10, 0, 1000);
    D_01B0D6B4 = 0;
    return 0;
}
