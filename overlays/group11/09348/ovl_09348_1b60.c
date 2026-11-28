#include "common.h"

extern void *D_01B0A9B8;
extern s32 D_01B0A9BC;
extern u8 D_01B10130[];
extern u8 D_01C00590[];

extern void func_01B035D0(void);
extern void func_01B05738(void);
extern void func_01B05E20(void);
extern void func_01B068A0(void);
extern void func_002B22F8(s32, s32);
extern void func_002B4980(void *);
extern void func_01B05008(void *, s32, s32);
extern void func_01B058D0(void *, s32, s32);
extern void func_01B058E0(void *, s32, s32);

s32 func_01B01B60(void *a0) {
    D_01B0A9B8 = a0;
    func_01B035D0();
    func_01B05738();
    func_01B05E20();
    func_01B068A0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B10130);
    func_01B05008(D_01B10130, 0, 1000);
    func_01B058D0(D_01B10130, 0, 1000);
    func_002B4980(D_01C00590);
    func_01B058D0(D_01C00590, 0, 1000);
    func_002B4980(D_01C00590);
    func_01B058E0(D_01C00590, 0, 0);
    func_01B058E0(D_01C00590, 1, 1);
    D_01B0A9BC = 0;
    return 0;
}
