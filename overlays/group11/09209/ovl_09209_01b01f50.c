#include "common.h"

extern u8 D_01C35380[];
extern u8 D_01B00040[];
extern u8 D_01B00740[];
extern u8 D_01B00A90[];
extern u8 D_01B0BC30[];
extern int D_01B0BC70;
extern u8 *D_01B0BC74;
extern u8 D_01B0BC78[];
extern u8 D_01B0BCD8[];
extern u8 *D_01B0BD58;
extern u8 *D_01B0BD5C;
extern u8 *D_01B0BD60;
extern u8 D_01B123A0[];

extern int func_002B49A0(void *, int, int);
extern void func_01B02090(void);
extern void func_01B02140(void);
extern void func_01B021A8(void);
extern void func_01B02CA0(void);
extern void func_01B023B8(void);
extern void func_01B06B58(int);
extern u8 *func_01B072E8(void (*)(void));
extern void func_01B074B0(void *);
extern void func_01B07570(void *, void *, void *, int);
extern void func_01B0ABD8(void *, void *);
extern void func_01B0B1F0(void *, int);

int func_01B01F50(void)
{
    u8 *s1 = D_01C35380;
    u8 *s0;
    u8 *p;

    D_01B0BC70 = 0;
    D_01B0BC74 = s1 + 0x40000;
    D_01B0BD60 = s1 + 0x1C0000;
    D_01B0BD5C = s1 + 0x1E0000;
    D_01B0BD58 = s1 + 0x230000;
    s0 = D_01B0BC30;
    *(int *)(s0 + 0x2C) = func_002B49A0(D_01B123A0, 8, 0);
    func_01B07570(s0, D_01B00040, s1, 0x40000);
    func_01B021A8();
    func_01B02CA0();
    func_01B023B8();
    func_01B0ABD8(D_01B0BC78, D_01B00740);
    func_01B0ABD8(D_01B0BCD8, D_01B00A90);
    func_01B06B58(1);
    p = func_01B072E8(func_01B02090);
    p[0x18] = 1;
    func_01B074B0(p);
    func_01B0B1F0(s1 + 0x220000, 0x200);
    p = func_01B072E8(func_01B02140);
    p[0x18] = 2;
    func_01B074B0(p);
    return 0;
}
