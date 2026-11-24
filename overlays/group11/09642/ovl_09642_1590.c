#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    float x, y, z, w;
} VecF;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    float fC8;
    u8 padCC[0x04];
    VecF vD0;
    float fE0;
    u8 padE4[0x4C];
} Part1590;

typedef struct {
    u8 pad00[0x80];
    u8 b80, b81, b82, b83, b84, b85, b86, b87;
    int w88;
    u8 pad8C[0x0C];
    u8 b98, b99;
} Sub9A0;

typedef struct {
    u8 pad00[0xF0];
    u8 bF0, bF1, bF2, bF3;
    u8 padF4[0x04];
    int wF8;
    float fFC;
    int w100;
    u8 pad104[0x0C];
    int w110;
    u8 pad114[0x0C];
    int w120;
    s16 h124;
} SubC00;

typedef struct {
    u8 pad00[0x4C0];
    Part1590 p[3];
    u8 pad850[0x80];
    u8 f8D0[0x30];
    VecF v900;
    u8 pad910[0x20];
    VecF v930;
    VecF v940;
    VecF v950;
    VecF v960;
    u8 pad970[0x10];
    VecF v980;
    VecF v990;
    Sub9A0 s9A0;
    u8 padA3C[0x1C4];
    SubC00 sC00;
    u8 padD26[0x1E];
    float fD48;
} Work1590;

extern u8 D_01B08FE0[];
extern Work1590 *D_01B09148;

extern void func_00118098(int, int);
extern void func_01B031C8(int, int);
extern void func_01B03348(int, void *);
extern void func_01B038C8(int, void *, void *);
extern void func_01B049F8(void *, void *, int, int, int, int, float);
extern void func_01B080A8(void *, int);
extern void func_01B08B38(void *, int);

void func_01B01590(void)
{
    Work1590 *w = D_01B09148;
    Part1590 *p;
    float a;

    p = &w->p[0];
    func_01B049F8(D_01B08FE0, p, 0, 0, 0, 0, 0.00069999998f);
    {
        register void *dst __asm__("$3") = &p->vD0;
        __asm__("" : "+r"(dst));
        copy_vec4_a3(dst, &w->v980);
    }
    p->fC4 = w->fD48;
    p->vD0.y -= 15.0f;

    p = &w->p[1];
    func_01B049F8(D_01B08FE0, p, 0, 0, 0, 0, 0.000525f);
    {
        register void *dst __asm__("$3") = &p->vD0;
        __asm__("" : "+r"(dst));
        copy_vec4_a3(dst, &w->v980);
    }
    {
        register float f_d48 __asm__("$f2") = w->fD48;
        register float f_pi4 __asm__("$f0") = 0.785398185f;
        register float a1 __asm__("$f3");
        __asm__("" : "+f"(f_d48));
        __asm__("" : "+f"(f_pi4));
        a1 = f_d48 + f_pi4;
        if (a1 > 3.14159274f) {
            a1 -= 6.28318548f;
        } else if (a1 < -3.14159274f) {
            a1 += 6.28318548f;
        }
        p->fC4 = a1;
    }
    {
        register float f15 __asm__("$f2") = 15.0f;
        p->fC8 = 0.785398185f;
        p->vD0.y -= f15;
        p->fE0 = f15;
    }

    p++;
    func_01B049F8(D_01B08FE0, p, 0, 0, 0, 0, 0.00034999999f);
    {
        register void *dst __asm__("$3") = &p->vD0;
        __asm__("" : "+r"(dst));
        copy_vec4_a3(dst, &w->v980);
    }
    a = w->fD48 + -0.785398185f;
    if (a > 3.14159274f) {
        a -= 6.28318548f;
    } else if (a < -3.14159274f) {
        a += 6.28318548f;
    }
    p->fC4 = a;
    {
        register float y __asm__("$f1") = p->vD0.y;
        register float fifteen __asm__("$f2") = 15.0f;
        register float c8 __asm__("$f3") = -0.785398185f;
        register float e0 __asm__("$f0") = -15.0f;
        y -= fifteen;
        p->fC8 = c8;
        p->vD0.y = y;
        p->fE0 = e0;
    }

    copy_vec4_a3(&w->v940, &w->v990);
    func_01B03348(1, w->f8D0);
    copy_vec4_a3(&w->v950, &w->v930);
    copy_vec4_a3(&w->v960, &w->v940);
    func_01B038C8(1, w->f8D0, &w->v950);
    copy_vec4_a3(&w->v900, &w->v960);
    func_01B031C8(1, 1);

    {
        Sub9A0 *s9a0 = &w->s9A0;
        s9a0->b82 = 0x80;
        s9a0->b81 = 0x80;
        s9a0->b80 = 0x80;
        s9a0->b83 = 0x80;
        s9a0->b84 = 0x80;
        s9a0->b85 = 0x80;
        s9a0->b86 = 0x80;
        s9a0->b98 = 0x48;
        s9a0->b87 = 0;
        s9a0->w88 = 0;
        s9a0->b99 = 0;
        func_01B080A8(s9a0, 0x18);
    }

    {
        SubC00 *sc00 = &w->sC00;
        sc00->bF0 = 0x80;
        sc00->bF1 = 0x80;
        sc00->bF2 = 0x80;
        sc00->bF3 = 0x30;
        sc00->h124 = 4;
        sc00->fFC = 0.05f;
        sc00->w120 = 0;
        sc00->w110 = 0;
        sc00->wF8 = 0;
        sc00->w100 = 0;
        func_01B08B38(sc00, 0x32);
    }

    func_00118098(0, 0);
    func_00118098(1, 0);
}
