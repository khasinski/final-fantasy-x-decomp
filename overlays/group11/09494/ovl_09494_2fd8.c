#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void copy_vec_from_sp(void *dst, void *src) {
    __asm__ volatile("lq $7, %0" : : "m"(*(u_long128 *)src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float fD0[4];
} Sub390;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    u32 w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
} Sub1C60;

typedef struct {
    u8 pad00[0x130];
    u8 f130[0x260];
    Sub390 f390;
    u8 pad470[0x1790];
    float f1C00[4];
    u8 pad1C10[0x20];
    float f1C30[4];
    float f1C40[4];
    u8 pad1C50[0x10];
    Sub1C60 f1C60;
    u8 pad1CFC[0x214];
    float f1F10;
    u8 pad1F14[0xC];
    int w1F20;
} ObjA310;

extern u8 D_01B066A8[];
extern u8 D_01B0A228[];
extern ObjA310 *D_01B0A310;

extern void func_01B02D40(void);
extern void func_01B06578(void *, void *);
extern void func_01B06108(void *, void *, int, int, int, void *, float);
extern void func_01B097B8(void *, int);
extern void func_01B044B0(int, int);

void func_01B02FD8(void)
{
    float tmp[4];
    register ObjA310 *s2 __asm__("$18") = D_01B0A310;
    float f1;
    float f2;
    register float *s3 __asm__("$19");
    int i;

    if (s2->w1F20 > 0) {
        func_01B02D40();
        s2->w1F20--;
        f1 = (float)s2->w1F20 / 12.0f;
    } else {
        f1 = 1.0f;
    }
    f2 = 1.0f - f1;
    s3 = s2->f1C40;
    {
        register float *dst __asm__("$6") = s2->f1C00;
        float *p0 = s3;
        for (i = 0; i < 3; i++) {
            tmp[i] = p0[i] * f2 + s2->f1C30[i] * f1;
        }
        tmp[3] = 1.0f;
        copy_vec_from_sp(dst, tmp);
    }

    if (s2->w1F20 == 0) {
        Sub390 *f390 = &s2->f390;
        u8 *a228 = D_01B0A228;
        func_01B06578(a228, s2->f130);
        {
            register float f12 __asm__("$f12") = 0.02f;
            register void *t1 __asm__("$9") = D_01B066A8;
            register void *a0 __asm__("$4");
            register void *a1 __asm__("$5");
            register int a2 __asm__("$6");
            register int t0 __asm__("$8");
            __asm__("" : "+f"(f12));
            __asm__("" : "+r"(t1) : "f"(f12));
            a0 = a228;
            __asm__("" : "+r"(a0) : "r"(t1));
            a1 = f390;
            __asm__("" : "+r"(a1) : "r"(a0));
            a2 = 3;
            __asm__("" : "+r"(a2) : "r"(a1));
            t0 = 0;
            __asm__("" : "+r"(t0) : "r"(a2));
            func_01B06108(a0, a1, a2, 0, t0, t1, f12);
        }
        {
            register float *f460 __asm__("$3") = s2->f390.fD0;
            __asm__("" : "+r"(f460));
            __asm__ volatile("lq $7, 0(%0)" : : "r"(s3), "r"(f460) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(f460) : "memory");
        }
        {
            Sub1C60 *p = &s2->f1C60;
            register u8 b83 __asm__("$4") = 0x80;
            register u8 ff __asm__("$3") = 0xFF;
            register u8 b98 __asm__("$6") = 0x48;
            register int a1 __asm__("$5");
            float f1f10 = s2->f1F10;
            __asm__("" : "+r"(p), "+r"(b83), "+r"(ff) : "f"(f1f10));
            f390->fC4 = f1f10;
            __asm__("" : "+r"(b98) : : "memory");
            p->b83 = b83;
            a1 = 0x14;
            __asm__("" : "+r"(a1) : : "memory");
            *(volatile u8 *)&p->b86 = ff;
            *(volatile u8 *)&p->b98 = b98;
            *(volatile u8 *)&p->b82 = ff;
            *(volatile u8 *)&p->b81 = ff;
            *(volatile u8 *)&p->b80 = ff;
            *(volatile u8 *)&p->b84 = ff;
            *(volatile u8 *)&p->b85 = ff;
            p->b87 = 0;
            p->w88 = 0;
            p->b99 = 0;
            func_01B097B8(p, a1);
        }
        func_01B044B0(1, 0);
        s2->w1F20--;
    }
}
