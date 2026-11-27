#include "common.h"

extern u8 D_01C00A80[];
extern u8 D_01B00040[];
extern u8 D_01B00788[];
extern u8 D_01B0A508[];
extern s32 D_01B0A548;
extern u8 *D_01B0A54C;
extern u8 D_01B0A550[];
extern u8 *D_01B0A5F0;
extern u8 *D_01B0A5F4;
extern u8 *D_01B0A5F8;
extern u8 D_01B12470[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B01C18(void);
extern void func_01B01D00(void);
extern void func_01B01D98(void);
extern void func_01B058F8(s32);
extern u8 *func_01B06088(void (*)(void));
extern void func_01B06250(void *);
extern void func_01B06310(void *, void *, void *, s32);
extern void func_01B09978(void *, void *);
extern void func_01B09E88(void *, s32);
extern void func_01B0A420(void *, s32);

s32 func_01B01AE0(void)
{
    u8 *s1 = D_01C00A80;
    u8 *s0;
    u8 *p;

    D_01B0A548 = 0;
    D_01B0A54C = s1 + 0x040000;
    D_01B0A5F8 = s1 + 0x140000;
    D_01B0A5F4 = s1 + 0x180000;
    D_01B0A5F0 = s1 + 0x1F5000;
    s0 = D_01B0A508;
    *(s32 *)(s0 + 0x2C) = func_002B49A0(D_01B12470, 8, 0);
    func_01B06310(s0, D_01B00040, s1, 0x40000);
    func_01B01D98();
    func_01B0A420(s1 + 0x1F0000, 0x40);
    func_01B09978(D_01B0A550, D_01B00788);
    func_01B058F8(1);
    p = func_01B06088(func_01B01C18);
    p[0x18] = 1;
    func_01B06250(p);
    func_01B09E88(s1 + 0x1E8000, 0x100);
    p = func_01B06088(func_01B01D00);
    p[0x18] = 2;
    func_01B06250(p);
    return 0;
}
