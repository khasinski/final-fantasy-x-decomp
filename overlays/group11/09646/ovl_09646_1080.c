#include "common.h"

extern s32 D_01B09710;
extern s32 D_01B09714;
extern u8 D_01B0EFE0[];
extern u8 D_01BC3630[];

extern void func_01B02558(void);
extern void func_01B046C0(void);
extern void func_01B04DA8(void);
extern void func_01B05828(void);
extern void func_002B22F8(s32, s32);
extern void func_01B01298(void);
extern void func_002B4980(void *);
extern void func_01B03F90(void *, s32, s32);
extern void func_01B04858(void *, s32, s32);

s32 ovl_09646_1080(s32 a0)
{
    D_01B09710 = a0;
    func_01B02558();
    func_01B046C0();
    func_01B04DA8();
    func_01B05828();
    func_002B22F8(0x3400, 0x800);
    func_01B01298();
    func_002B4980(D_01B0EFE0);
    func_01B03F90(D_01B0EFE0, 0, 1000);
    func_01B04858(D_01B0EFE0, 0, 1000);
    func_002B4980(D_01BC3630);
    func_01B04858(D_01BC3630, 0, 1000);
    D_01B09714 = 0;
    return 0;
}
