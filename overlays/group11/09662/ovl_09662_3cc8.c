/* 09662 sub-effect init (604 B). */

#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x200];
    u8 sub220[0x20];
    Vec4 pos240;
    u8 pad250[0x30];
    u8 sub280[0x20];
    Vec4 scale2A0;
    u8 pad2B0[0x30];
    u8 sub2E0[0x2A0];
    float f580;
    float f584;
    s32 w588;
    s32 state;
    void *w590;
    u8 sub594[0x40];
} Work9662;

extern void fn_ovl_38b8(void);
extern void fn_ovl_d9c8(void *);
extern void fn_ovl_ddd0(void *);
extern void fn_ovl_9730(void *);
extern void fn_ovl_5a38(void *);
extern void fn_ovl_a8b8(void *);
extern void fn_ovl_ca18(void *);
extern void fn_ovl_c1a8(void *);
extern void fn_ovl_c170(void *);
extern float func_001ACED8(void);

extern u8 g_ovl_dat_670[];
extern u8 g_ovl_dat_6a0[];
extern u8 g_ovl_dat_8b0[];
extern u8 g_ovl_dat_8c8[];
extern u8 g_ovl_dat_8e8[];
extern u8 g_ovl_dat_edb0[];
extern void *g_ovl_ptr_4d8;
extern void *g_ovl_ptr_eddc;

void ovl_09662_3cc8(Work9662 *w, void *target, float scale)
{
    void *p[10];
    u8 *sub220 = w->sub220;
    register u8 *sub280 __asm__("$20") = w->sub280;
    register u8 *sub2E0 __asm__("$21") = w->sub2E0;
    register u8 *sub594 __asm__("$22") = w->sub594;
    u8 *p8c8;
    u8 *p6a0;
    float c99;
    float c10;
    float cm5;

    {
        register void *v0_ __asm__("$2") = (void *)fn_ovl_38b8;
        p[0] = w;
        p[2] = w;
        p[1] = v0_;
        fn_ovl_d9c8(p);
    }

    c99 = 0.99f;
    p[0] = g_ovl_dat_8b0;
    p[1] = w;
    fn_ovl_ddd0(p);

    c10 = 10.0f;
    p8c8 = g_ovl_dat_8c8;
    p[0] = sub220;
    p[1] = p8c8;
    fn_ovl_9730(p);

    cm5 = -5.0f;
    p[0] = target;
    p[1] = &w->pos240;
    p[2] = 0;
    fn_ovl_5a38(p);

    p[0] = sub280;
    p[1] = p8c8;
    fn_ovl_9730(p);

    {
        register float f0 __asm__("$f0") = 1.0f;
        register void *p670 __asm__("$2") = g_ovl_dat_670;
        register void **v1 __asm__("$3");
        __asm__("" : "+f"(f0));
        *(void *volatile *)&p[4] = sub2E0;
        v1 = &p[4];
        __asm__("" : "+f"(f0) : "r"(v1) : "memory");
        __asm__ volatile("" : "+r"(v1), "+r"(p670), "+f"(f0));
        *(volatile float *)&w->scale2A0.w = scale;
        *(volatile float *)&w->scale2A0.z = f0;
        __asm__ volatile("" : "+f"(f0));
        p6a0 = g_ovl_dat_6a0;
        *(void *volatile *)&v1[4] = p670;
        __asm__ volatile("" : "+r"(p6a0));
        *(void *volatile *)&p[9] = sub280;
        {
            register void **a0_ __asm__("$4") = v1;
            __asm__ volatile("" : "+r"(a0_));
            *(volatile float *)&w->scale2A0.x = f0;
            *(volatile float *)&w->scale2A0.y = f0;
            *(void *volatile *)&v1[1] = p8c8;
            *(void *volatile *)&v1[2] = p6a0;
            p[7] = sub220;
            fn_ovl_a8b8(a0_);
        }
    }

    p[0] = w->sub20;
    p[1] = g_ovl_dat_8e8;
    p[2] = sub2E0;
    p[3] = g_ovl_ptr_eddc;
    p[4] = g_ovl_dat_edb0;
    p[5] = 0;
    fn_ovl_ca18(p);

    p[0] = sub594;
    p[1] = p8c8;
    p[2] = p6a0;
    p[3] = sub220;
    p[4] = g_ovl_ptr_4d8;
    p[5] = 0;
    fn_ovl_c1a8(p);

    p[0] = sub594;
    p[1] = 0;
    fn_ovl_c170(p);

    w->pos240.x += (func_001ACED8() - c99) * c10 + cm5;
    w->pos240.y += (func_001ACED8() - c99) * 4.0f + -2.0f;
    w->pos240.z += (func_001ACED8() - c99) * c10 + cm5;

    *(volatile float *)&w->f584 = scale;
    *(void *volatile *)&w->w590 = target;
    *(volatile s32 *)&w->state = 0;
    *(volatile float *)&w->f580 = 0.0f;
    *(volatile s32 *)&w->w588 = 0;
}
