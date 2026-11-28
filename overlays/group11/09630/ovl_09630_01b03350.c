#include "common.h"

extern u8 D_01C0D9C0[];
extern u8 D_01B00040[];
extern u8 D_01B006A8[];
extern u8 D_01B00A40[];
extern u8 D_01B0C700[];
extern s32 D_01B0C740;
extern u8 *D_01B0C744;
extern u8 D_01B0C748[];
extern u8 D_01B0C7A8[];
extern u8 *D_01B0C888;
extern u8 *D_01B0C88C;
extern u8 *D_01B0C890;
extern u8 *D_01B0C894;
extern u8 D_01B11E30[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B036F0(void);
extern void func_01B037F8(void);
extern void func_01B03868(void);
extern void func_01B03928(void);
extern void func_01B03B28(void);
extern void func_01B07390(s32);
extern u8 *func_01B07B20(void (*)(void));
extern void func_01B07CE8(void *);
extern void func_01B07DA8(void *, void *, void *, s32);
extern void func_01B0B410(void *, void *);
extern void func_01B0BCC0(void *, s32);

s32 func_01B035A0(void)
{
    u8 *s1 = D_01C0D9C0;
    u8 *s0;
    u8 *p;

    D_01B0C740 = 0;
    D_01B0C744 = s1 + 0x40000;
    D_01B0C88C = s1 + 0x120000;
    D_01B0C890 = s1 + 0x160000;
    D_01B0C894 = s1 + 0x1A0000;
    D_01B0C888 = s1 + 0x1D0000;
    s0 = D_01B0C700;
    *(s32 *)(s0 + 0x2C) = func_002B49A0(D_01B11E30, 8, 0);
    func_01B07DA8(s0, D_01B00040, s1, 0x40000);
    func_01B03868();
    func_01B03928();
    func_01B03B28();
    func_01B0B410(D_01B0C748, D_01B006A8);
    func_01B0B410(D_01B0C7A8, D_01B00A40);
    func_01B07390(1);
    p = func_01B07B20(func_01B036F0);
    p[0x18] = 1;
    func_01B07CE8(p);
    func_01B0BCC0(s1 + 0x1B0000, 0x400);
    p = func_01B07B20(func_01B037F8);
    p[0x18] = 2;
    func_01B07CE8(p);
    return 0;
}
