#include "common.h"

extern u8 D_01B0C808[];
extern u8 D_01B0C828[];

extern void func_00103208(s32);
extern void func_00110718(s32, s32);
extern void func_00117E58(s32);
extern void func_00118098(s32, s32);
extern s32 func_01B053A8(s32);
extern s32 func_01B053E0(s32, s32);
extern void func_01B061A0(s32, s32);
extern void func_01B06228(s32, s32);
extern void func_01B06420(s32);
extern void func_01B06650(s32, s32);
extern void func_01B067D0(s32, s32);
extern void func_01B06BA8(s32);
extern void func_01B072A0(void *, s32);
extern void func_01B099F8(void);

void func_01B03BA0(void)
{
    s32 v;

    func_00103208(func_01B053A8(1));
    func_00103208(func_01B053A8(2));
    func_01B06BA8(0x3011);
    func_01B06BA8(0x3013);
    func_01B067D0(0, 0);
    func_01B067D0(-1, 0);
    func_01B072A0(D_01B0C808, 0);
    func_01B072A0(D_01B0C828, 0);
    func_01B06228(0, 1);
    func_01B06228(-1, 1);
    func_01B06650(-1, 0);
    func_01B061A0(-1, 1);
    func_01B06420(1);
    func_00118098(0, 0);
    func_00118098(1, 0);
    func_00117E58(0);
    v = func_01B053E0(0, 1);
    if (v != 0) {
        func_00110718(v, 0);
    }
    func_01B099F8();
}
