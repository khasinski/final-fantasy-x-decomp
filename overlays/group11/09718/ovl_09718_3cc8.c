/* 09718 sub-effect init (900 B, shared by 9455 and 9718). */

#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Target9718;

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
} Work9718;

extern s32 fn_ovl_3568(s32);
extern void fn_ovl_38b8(void);
extern void fn_ovl_3a00(void);
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

void ovl_09718_3cc8(Work9718 *w, Target9718 *target, float scale)
{
    void *p[10];
    register u8 *sub220 __asm__("$20");
    register u8 *sub280 __asm__("$17");
    register u8 *sub2E0 __asm__("$18");
    u8 *sub594;
    register u8 *p8c8 __asm__("$16");
    float c99;
    float c10;
    float cm5;

    if (fn_ovl_3568(target->w54) != 0) {
        p[0] = w;
        p[1] = (void *)fn_ovl_38b8;
        p[2] = w;
        fn_ovl_d9c8(p);

        p[0] = g_ovl_dat_8b0;
        p[1] = w;
        fn_ovl_ddd0(p);

        p8c8 = g_ovl_dat_8c8;
        sub220 = w->sub220;
        p[0] = sub220;
        p[1] = p8c8;
        fn_ovl_9730(p);

        sub280 = w->sub280;
        sub2E0 = w->sub2E0;
        p[0] = target;
        p[1] = &w->pos240;
        p[2] = 0;
        fn_ovl_5a38(p);

        p[0] = sub280;
        p[1] = p8c8;
        fn_ovl_9730(p);

        {
            register float f1 __asm__("$f0") = 1.0f;
            register void *p670 __asm__("$3") = g_ovl_dat_670;
            register void **v0 __asm__("$2");
            __asm__("" : "+f"(f1));
            *(void *volatile *)&p[4] = sub2E0;
            v0 = &p[4];
            __asm__("" : "+f"(f1) : "r"(v0) : "memory");
            {
                register void *p6a0 __asm__("$5") = g_ovl_dat_6a0;
                __asm__("" : "+r"(p670));
                __asm__("" : "+r"(p6a0) : "r"(v0), "r"(p670), "f"(f1));
                *(volatile float *)&w->scale2A0.w = scale;
                __asm__("" : "+r"(v0) : "r"(p6a0) : "memory");
                {
                    register void **a0_ __asm__("$4") = v0;
                    __asm__("" : "+r"(a0_), "+f"(f1) : "r"(p6a0), "f"(scale));
                    *(volatile float *)&w->scale2A0.z = f1;
                    *(void *volatile *)&v0[1] = p8c8;
                    *(void *volatile *)&v0[2] = p6a0;
                    *(void *volatile *)&v0[4] = p670;
                    *(void *volatile *)&p[9] = sub280;
                    *(volatile float *)&w->scale2A0.x = f1;
                    *(volatile float *)&w->scale2A0.y = f1;
                    p[7] = sub220;
                    fn_ovl_a8b8(a0_);
                }
            }
        }

        p[0] = w->sub20;
        p[1] = g_ovl_dat_8e8;
        p[2] = sub2E0;
        p[3] = g_ovl_ptr_eddc;
        p[4] = g_ovl_dat_edb0;
        p[5] = (void *)3;
        fn_ovl_ca18(p);
    } else {
        p[0] = w;
        p[1] = (void *)fn_ovl_3a00;
        p[2] = w;
        fn_ovl_d9c8(p);

        p[0] = g_ovl_dat_8b0;
        p[1] = w;
        fn_ovl_ddd0(p);

        p8c8 = g_ovl_dat_8c8;
        sub220 = w->sub220;
        p[0] = sub220;
        p[1] = p8c8;
        fn_ovl_9730(p);

        sub280 = w->sub280;
        sub2E0 = w->sub2E0;
        p[0] = target;
        p[1] = &w->pos240;
        p[2] = 0;
        fn_ovl_5a38(p);

        p[0] = sub280;
        p[1] = p8c8;
        fn_ovl_9730(p);

        {
            register float f1 __asm__("$f0") = 1.0f;
            register void *p670 __asm__("$2");
            register void *p6a0 __asm__("$3");
            __asm__("" : "+f"(f1));
            p670 = g_ovl_dat_670;
            *(volatile float *)&w->scale2A0.w = scale;
            __asm__("" : "+r"(p670) : "f"(f1));
            *(volatile float *)&w->scale2A0.z = f1;
            p6a0 = g_ovl_dat_6a0;
            __asm__("" : "+r"(p6a0) : "r"(p670));
            *(void *volatile *)&p[1] = p8c8;
            {
                register void **a0_ __asm__("$4") = p;
                __asm__("" : "+r"(a0_) : "r"(p6a0) : "memory");
                __asm__("" : "+r"(p6a0) : "r"(a0_));
                *(void *volatile *)&p[2] = p6a0;
                *(void *volatile *)&p[4] = p670;
                *(void *volatile *)&p[5] = sub280;
                *(volatile float *)&w->scale2A0.x = f1;
                *(volatile float *)&w->scale2A0.y = f1;
                *(void *volatile *)&p[0] = sub2E0;
                __asm__("" : "+r"(sub220) : : "memory");
                p[3] = sub220;
                fn_ovl_a8b8(a0_);
            }
        }

        p[0] = w->sub20;
        p[1] = g_ovl_dat_8e8;
        p[2] = sub2E0;
        p[3] = g_ovl_ptr_eddc;
        p[4] = g_ovl_dat_edb0;
        p[5] = (void *)2;
        fn_ovl_ca18(p);
    }

    sub594 = w->sub594;
    p[0] = sub594;
    p[1] = g_ovl_dat_8c8;
    p[2] = g_ovl_dat_6a0;
    p[3] = sub220;
    p[4] = g_ovl_ptr_4d8;
    p[5] = 0;
    fn_ovl_c1a8(p);

    c99 = 0.99f;
    p[0] = sub594;
    p[1] = 0;
    fn_ovl_c170(p);

    c10 = 10.0f;
    cm5 = -5.0f;
    w->pos240.x += (func_001ACED8() - c99) * c10 + cm5;
    w->pos240.y += (func_001ACED8() - c99) * 4.0f + -2.0f;
    w->pos240.z += (func_001ACED8() - c99) * c10 + cm5;

    *(volatile float *)&w->f584 = scale;
    *(void *volatile *)&w->w590 = target;
    *(volatile s32 *)&w->state = 0;
    *(volatile float *)&w->f580 = 0.0f;
    *(volatile s32 *)&w->w588 = 0;
}
