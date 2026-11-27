#include "common.h"

extern u8 D_01BE9C10[];
extern u8 D_01CA3EC0[];
extern u8 D_01B00040[];
extern u8 D_01B009A0[];
extern u8 D_01B0D6B8[];
extern s32 D_01B0E7A0;
extern u8 *D_01B0E7A4;
extern u8 D_01B0E7A8[];
extern u8 *D_01B0E828;
extern u8 *D_01B0E82C;
extern u8 *D_01B0E834;
extern u8 D_01B13FE0[];

extern void func_002B4980(void *);
extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B01908(void);
extern void func_01B019B8(void);
extern void func_01B01A20(void);
extern void func_01B022D0(void);
extern void func_01B08028(s32);
extern u8 *func_01B087B8(void (*)(void));
extern void func_01B08980(void *);
extern void func_01B08A40(void *, void *, void *, s32);
extern void func_01B0C0A8(void *, void *);
extern void func_01B0C850(void *, s32);

s32 func_01B017D8(void)
{
    u8 *s1;
    u8 *s0;
    u8 *p;

    func_002B4980(D_01BE9C10);
    s1 = D_01CA3EC0;
    D_01B0E7A0 = 0;
    D_01B0E7A4 = s1 + 0x40000;
    D_01B0E834 = s1 + 0x140000;
    D_01B0E82C = s1 + 0x170000;
    D_01B0E828 = s1 + 0x200000;
    s0 = D_01B0D6B8;
    *(s32 *)(s0 + 0x2C) = func_002B49A0(D_01B13FE0, 8, 0);
    func_01B08A40(s0, D_01B00040, s1, 0x40000);
    func_01B01A20();
    func_01B022D0();
    func_01B08028(1);
    func_01B0C0A8(D_01B0E7A8, D_01B009A0);
    p = func_01B087B8(func_01B01908);
    p[0x18] = 1;
    func_01B08980(p);
    func_01B0C850(s1 + 0x1F0000, 0x200);
    p = func_01B087B8(func_01B019B8);
    p[0x18] = 2;
    func_01B08980(p);
    return 0;
}
