#include "common.h"

extern s32 D_01B0A0E0;
extern s32 D_01B0A0E4;
extern u8 D_01B0F9E0[];
extern u8 D_01BEB920[];

extern void func_01B02F28(void);
extern void func_01B05090(void);
extern void func_01B05778(void);
extern void func_01B061F8(void);
extern void func_002B22F8(s32, s32);
extern void func_002B4980(void *);
extern void func_01B04960(void *, s32, s32);
extern void func_01B05228(void *, s32, s32);

s32 ovl_09633_12a0(s32 a0)
{
    D_01B0A0E0 = a0;
    func_01B02F28();
    func_01B05090();
    func_01B05778();
    func_01B061F8();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B0F9E0);
    func_01B04960(D_01B0F9E0, 0, 1000);
    func_01B05228(D_01B0F9E0, 0, 1000);
    func_002B4980(D_01BEB920);
    func_01B05228(D_01BEB920, 0, 1000);
    D_01B0A0E4 = 0;
    return 0;
}
