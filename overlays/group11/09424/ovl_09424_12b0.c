#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x4];
    s32 w04;
    s32 w08;
    u8 pad0C[0x4];
    s32 w10;
    s32 w14;
} Obj8250;

typedef struct {
    u8 pad00[0x1C];
    s32 w1C;
    float f20;
    u8 pad24[0x4];
    s32 w28;
} Obj8270;

extern Obj8250 D_01B08250;
extern Obj8270 D_01B08270;

extern s32 func_001B4E58(s32);
extern void func_01B01C68(s32, s32, void *, void *);
extern void func_01B01D88(s32, s32, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE38(void *, void *, void *);

void ovl_09424_1350(void *a0);
void ovl_09424_1398(void *a0);

void ovl_09424_12b0(u8 *a0)
{
    ovl_09424_1398(a0 + 0x80);
    ovl_09424_1350(a0 + 0xD0);
    a0[0x126] = 2;
}

void ovl_09424_12e8(void)
{
    register Obj8250 *o1 __asm__("$2") = &D_01B08250;
    register s32 c16 __asm__("$6") = 16;
    register Obj8270 *o2 __asm__("$4");
    register s32 c10 __asm__("$3");
    register s32 c80 __asm__("$5");
    float f0;

    __asm__ volatile("" : "+r"(o1), "+r"(c16));
    o2 = &D_01B08270;
    __asm__ volatile("" : "+r"(o2));
    f0 = 0.1f;
    __asm__ volatile("" : "+f"(f0));
    c10 = 10;
    __asm__ volatile("" : "+r"(c10));
    *(volatile s32 *)&o1->w10 = c16;
    *(volatile s32 *)&o2->w28 = c10;
    __asm__ volatile("" : : "r"(c10));
    c80 = 80;
    __asm__ volatile("" : "+r"(c80));
    *(volatile s32 *)&o1->w04 = c80;
    *(volatile float *)&o2->f20 = f0;
    *(volatile s32 *)&o1->w08 = 0;
    *(volatile s32 *)&o1->w14 = c16;
    o2->w1C = 0;
}

s32 ovl_09424_1330(void)
{
    return func_001B4E58(20);
}

void ovl_09424_1350(void *a0)
{
    Vec4 v;

    v.x = 500.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    func_01B01C68(-1, 6, &v, a0);
}

void ovl_09424_1398(void *a0)
{
    float m0[16];
    float m1[16];

    func_01B01D88(-1, 6, m1);
    func_002DD128(m0);
    func_002DD318(m0, m0, -1.5707964f);
    func_002DCE38(a0, m1, m0);
}
