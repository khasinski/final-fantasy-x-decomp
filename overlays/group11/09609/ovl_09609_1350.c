#include "common.h"

extern void *D_01B0DEA8;
extern s32 D_01B0DEAC;
extern u8 D_01B17DF0;
extern u8 D_01C03DD0;

extern void func_002B22F8(s32, s32);
extern void func_002B4980(void *);
extern void func_01B06380(void);
extern void func_01B07238(void);
extern void func_01B08C70(void *, s32, s32);
extern void func_01B093A0(void);
extern void func_01B09538(void *, s32, s32);
extern void func_01B09A88(void);
extern void func_01B0A508(void);

s32 func_01B01350(void *arg0) {
    D_01B0DEA8 = arg0;
    func_01B07238();
    func_01B093A0();
    func_01B09A88();
    func_01B0A508();
    func_002B22F8(0x3400, 0x800);
    func_01B06380();
    func_002B4980(&D_01B17DF0);
    func_01B08C70(&D_01B17DF0, 0, 0x3E8);
    func_01B09538(&D_01B17DF0, 0, 1);
    func_002B4980(&D_01C03DD0);
    func_01B09538(&D_01C03DD0, 0, 1);
    D_01B0DEAC = 0;
    return 0;
}
