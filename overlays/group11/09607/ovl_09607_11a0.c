#include "common.h"

extern s32 D_01B0AA58;
extern s32 D_01B0AA5C;
extern u8 D_01B10320[];
extern u8 D_01BEC260[];

extern void func_01B038A0(void);
extern void func_01B05A08(void);
extern void func_01B060F0(void);
extern void func_01B06B70(void);
extern void func_002B22F8(s32, s32);
extern void func_002B4980(void *);
extern void func_01B052D8(void *, s32, s32);
extern void func_01B05BA0(void *, s32, s32);

s32 func_01B01560(s32 a0)
{
    D_01B0AA58 = a0;
    func_01B038A0();
    func_01B05A08();
    func_01B060F0();
    func_01B06B70();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B10320);
    func_01B052D8(D_01B10320, 0, 1000);
    func_01B05BA0(D_01B10320, 0, 1000);
    func_002B4980(D_01BEC260);
    func_01B05BA0(D_01BEC260, 0, 1000);
    D_01B0AA5C = 0;
    return 0;
}
