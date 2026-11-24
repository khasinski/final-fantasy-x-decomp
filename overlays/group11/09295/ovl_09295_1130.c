#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0xA0];
    s32 wA0;
    s32 wA4;
} Arg1130;

typedef struct {
    u8 pad00[0x10];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    u8 pad34[0x4];
    s32 w38;
    s32 w3C;
    s32 w40;
    u8 pad44[0x3];
    u8 b47;
    u8 pad48[0x3];
    u8 b4B;
} PartA;

typedef struct {
    u8 pad00[0x10];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x4];
    float f40;
    float f44;
    float f48;
    float f4C;
    s32 w50;
    s32 w54;
    s32 w58;
    u8 pad5C[0x7];
    u8 b63;
} PartB;

extern u8 D_01B0DC20[];

extern void func_001B6790(s32, void *);
extern void func_001B6E48(s32, void *);
extern PartA *func_01B05DB0(void);
extern PartB *func_01B061F8(void);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B05118(void *, void *, void *);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B056A8(void *, void *);

void ovl_09295_1130(Arg1130 *arg)
{
    float v00[4];
    float v10[4];
    float v20[4];
    float v30[4];
    register s32 i __asm__("$17");
    float ang;
    float f10;

    if (arg->wA4 >= 19) {
        return;
    }

    func_001B6790(arg->wA0, v00);
    v30[0] = 0.0f;
    v30[2] = 0.0f;
    func_001B6E48(arg->wA0, &v30[1]);
    ang = 4.712389f - v30[1];
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    v30[1] = ang;

    for (i = 0; i < 3; i++) {
        PartA *p = func_01B05DB0();
        if (p == 0) {
            return;
        }
        v20[0] = func_002B3DB0(25.0f);
        v20[1] = 0.0f;
        v20[2] = func_002B3DB0(5.0f);
        copy_vec(v10, v00);
        func_01B05118(v30, v10, v20);
        func_01B056A8(p, func_002B49A0(D_01B0DC20, 9, 0));
        p->f10 = v10[0];
        p->f14 = v00[1] - 4.0f;
        p->f18 = v10[2];
        p->f1C = 1.0f;
        p->f20 = 0.0f;
        p->f28 = 0.0f;
        p->f24 = -0.2f;
        p->f2C = func_002B3DB0(3.1415927f);
        p->f30 = (func_002B3DF8(0.4f) + 1.0f) * 0.6f;
        p->w38 = 12;
        p->w3C = 8;
        p->w40 = -4;
        p->b47 = 0x40;
        p->b4B = 0;
    }

    {
        register float f1 __asm__("$f21") = 1.0f;
        register float f2 __asm__("$f20");
        register s32 six __asm__("$21");
        __asm__ volatile("" : "+f"(f1));
        i = 0;
        __asm__ volatile("" : "+r"(i));
        f2 = 2.0f;
        __asm__ volatile("" : "+f"(f2));
        six = 6;
        do {
            PartB *p = func_01B061F8();
            if (p == 0) {
                return;
            }
            f10 = 10.0f;
            v20[0] = func_002B3DB0(20.0f);
            v20[1] = 0.0f;
            v20[2] = func_002B3DB0(5.0f) - f10;
            copy_vec(v10, v00);
            func_01B05118(v30, v10, v20);
            i++;
            func_01B056A8(p, func_002B49A0(D_01B0DC20, 9, 1));
            p->f10 = v10[0];
            p->f20 = 0.0f;
            p->f14 = v00[1] - 4.0f;
            p->f18 = v10[2];
            p->f1C = f1;
            p->f24 = func_002B3DB0(f2);
            p->f28 = -5.0f;
            p->f2C = func_002B3DB0(f2);
            p->f30 = 0.0f;
            p->f34 = f1;
            p->f38 = f2;
            p->f40 = v00[1];
            p->f44 = func_002B3DB0(3.1415927f);
            p->f48 = 0.0f;
            p->f4C = (func_002B3DF8(0.4f) + f1) * 0.006f;
            *(volatile u8 *)&p->b63 = 0;
            *(volatile s32 *)&p->w50 = six;
            *(volatile s32 *)&p->w54 = six;
            *(volatile s32 *)&p->w58 = 0;
        } while (i < 4);

        f1 = 1.0f;
        __asm__ volatile("" : "+f"(f1));
        i = 0;
        __asm__ volatile("" : "+r"(i));
        six = 6;
        do {
            PartA *p = func_01B05DB0();
            if (p == 0) {
                return;
            }
            v20[0] = func_002B3DB0(20.0f);
            v20[1] = 0.0f;
            v20[2] = func_002B3DB0(5.0f) - f10;
            copy_vec(v10, v00);
            func_01B05118(v30, v10, v20);
            i++;
            func_01B056A8(p, func_002B49A0(D_01B0DC20, 9, 2));
            {
                register float x10 __asm__("$f1") = v10[0];
                register float f4 __asm__("$f2") = 4.0f;
                __asm__("" : "+f"(f4) : "r"(p));
                p->f10 = x10;
                p->f14 = v00[1] - f4;
            }
            p->f18 = v10[2];
            p->f1C = f1;
            p->f20 = func_002B3DB0(f2);
            p->f24 = -2.0f;
            p->f28 = func_002B3DB0(f2);
            p->f2C = func_002B3DB0(3.1415927f);
            p->f30 = (func_002B3DF8(0.4f) + f1) * 0.05f;
            *(volatile u8 *)&p->b4B = 0;
            *(volatile s32 *)&p->w38 = six;
            *(volatile s32 *)&p->w3C = six;
            *(volatile s32 *)&p->w40 = 0;
        } while (i < 3);
    }
}
