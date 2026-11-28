#include "common.h"

extern u8 D_01C11440[];
extern u8 D_01B00040[];
extern u8 D_01B00720[];
extern u8 D_01B00830[];
extern u8 D_01B0A350[];
extern s32 D_01B0A390;
extern u8 *D_01B0A394;
extern u8 D_01B0A398[];
extern u8 D_01B0A3F8[];
extern u8 *D_01B0A478;
extern u8 *D_01B0A47C;
extern u8 *D_01B0A480;
extern u8 D_01B0FB90[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B06128(void *, void *, void *, s32);
extern void func_01B01CB0(void);
extern void func_01B01DC8(void);
extern void func_01B09790(void *, void *);
extern void func_01B05710(s32);
extern u8 *func_01B05EA0(void (*)(void));
extern void func_01B06068(void *);
extern void func_01B09DA8(void *, s32);
extern void func_01B01B98(void);
extern void func_01B01C48(void);

s32 func_01B01A60(void) {
    u8 *s1 = D_01C11440;
    u8 *s0 = D_01B0A350;
    u8 *p;

    D_01B0A390 = 0;
    D_01B0A394 = s1 + 0x40000;
    D_01B0A480 = s1 + 0x1C0000;
    D_01B0A47C = s1 + 0x1E0000;
    D_01B0A478 = s1 + 0x230000;
    *(s32 *)(s0 + 0x2C) = func_002B49A0(D_01B0FB90, 8, 0);
    func_01B06128(s0, D_01B00040, s1, 0x40000);
    func_01B01CB0();
    func_01B01DC8();
    func_01B09790(D_01B0A398, D_01B00720);
    func_01B09790(D_01B0A3F8, D_01B00830);
    func_01B05710(1);
    p = func_01B05EA0(func_01B01B98);
    p[0x18] = 1;
    func_01B06068(p);
    func_01B09DA8(s1 + 0x220000, 0x200);
    p = func_01B05EA0(func_01B01C48);
    p[0x18] = 2;
    func_01B06068(p);
    return 0;
}
