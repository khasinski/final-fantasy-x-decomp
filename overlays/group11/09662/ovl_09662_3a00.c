/* 09662 sub-effect update (708 B, shared with 9455, 9662, 9718). */
#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Target9662;

typedef struct {
    u8 pad00[0x108];
    s32 w108;
    u8 pad10C[0x14];
    u8 sub120[0xE8];
    s32 w208;
    u8 pad20C[0x14];
    u8 sub220[0x20];
    Vec4 pos240;
    u8 sub250[0x20];
    Vec4 pos270;
    u8 sub280[0x30];
    u8 sub2B0[0x20];
    Vec4 scale2D0;
    u8 sub2E0[0x150];
    u8 sub430[0x150];
    float f580;
    float f584;
    s32 w588;
    s32 state;
    Target9662 *w590;
    u8 sub594[0x40];
} Work9662;

typedef struct {
    void *w00;
    Work9662 *work;
} Task9662;

extern s32 g_ovl_ptr_4f4;
extern u8 g_ovl_dat_670[];
extern u8 g_ovl_dat_6a0[];
extern u8 g_ovl_dat_8c8[];
extern u8 g_ovl_dat_8e8[];
extern u8 g_ovl_dat_edb0[];
extern s32 g_ovl_ptr_eddc;

extern void func_001C5E90(s32, s32, s32);

extern void fn_ovl_5a38(void *);
extern void fn_ovl_9730(void *);
extern void fn_ovl_9780(void *);
extern void fn_ovl_9878(void *);
extern void fn_ovl_a8b8(void *);
extern void fn_ovl_a908(void *);
extern void fn_ovl_a9b0(void *);
extern void fn_ovl_c1f8(void *);
extern void fn_ovl_c300(void *);
extern void fn_ovl_ca18(void *);
extern void fn_ovl_da70(void *);

void ovl_09662_3a00(Task9662 *a0)
{
    void *p[27];
    Work9662 *w = a0->work;

    w->f580 += 1.0f / 30.0f;
    switch (w->state) {
    case 0:
        if (w->f580 >= 0.25f) {
            u8 *p8c8 = g_ovl_dat_8c8;
            u8 *sub250 = w->sub250;
            u8 *sub2B0;
            u8 *sub430;

            p[0] = sub250;
            p[1] = p8c8;
            fn_ovl_9730(p);

            p[0] = w->w590;
            p[1] = &w->pos270;
            p[2] = (void *)1;
            fn_ovl_5a38(p);

            w->pos270.x = w->pos240.x;
            w->pos270.z = w->pos240.z;
            w->pos270.y -= 0.2f;

            sub2B0 = w->sub2B0;
            p[0] = sub2B0;
            p[1] = p8c8;
            fn_ovl_9730(p);

            sub430 = w->sub430;
            {
                register float f1 __asm__("$f1") = w->f584;
                register void *p6a0 __asm__("$3") = g_ovl_dat_6a0;
                register float f0 __asm__("$f0") = 1.0f;
                register void **v0 __asm__("$2");
                __asm__("" : "+f"(f0) : "f"(f1));
                v0 = &p[4];
                *(void *volatile *)&p[4] = sub430;
                __asm__("" : "+r"(v0) : "f"(f0));
                *(volatile float *)&w->scale2D0.z = f0;
                __asm__("" : : : "memory");
                {
                    register void *p670 __asm__("$5") = g_ovl_dat_670;
                    *(volatile float *)&w->scale2D0.w = f1;
                    __asm__("" : "+r"(p670) : : "memory");
                    *(void *volatile *)&v0[1] = p8c8;
                    __asm__("" : : : "memory");
                    {
                        register void **a0_ __asm__("$4") = v0;
                        __asm__("" : "+r"(a0_) : : "memory");
                        *(void *volatile *)&v0[2] = p6a0;
                        *(void *volatile *)&p[7] = sub250;
                        *(void *volatile *)&v0[4] = p670;
                        *(void *volatile *)&p[9] = sub2B0;
                        *(volatile float *)&w->scale2D0.x = f0;
                        __asm__("" : : "f"(f0) : "memory");
                        w->scale2D0.y = f0;
                        fn_ovl_a8b8(a0_);
                    }
                }
            }

            p[0] = w->sub120;
            p[1] = g_ovl_dat_8e8;
            p[2] = sub430;
            p[3] = (void *)g_ovl_ptr_eddc;
            p[4] = g_ovl_dat_edb0;
            p[5] = (void *)1;
            fn_ovl_ca18(p);

            func_001C5E90(g_ovl_ptr_4f4, w->w590->w54, 32);
            {
                register s32 next __asm__("$3") = w->state + 1;
                w->state = next;
            }
        }
        break;
    case 1:
        if ((w->w108 & 4) != 0 && (w->w208 & 4) != 0) {
            u8 *sub220 = w->sub220;
            u8 *sub280 = w->sub280;
            u8 *sub2E0 = w->sub2E0;
            u8 *sub250 = w->sub250;
            u8 *sub2B0 = w->sub2B0;
            u8 *sub430 = w->sub430;
            u8 *sub594 = w->sub594;

            p[12] = sub220;
            fn_ovl_9878(&p[12]);
            p[13] = sub220;
            fn_ovl_9780(&p[13]);

            p[14] = sub280;
            fn_ovl_9878(&p[14]);
            p[15] = sub280;
            fn_ovl_9780(&p[15]);

            p[16] = sub2E0;
            fn_ovl_a9b0(&p[16]);
            p[17] = sub2E0;
            fn_ovl_a908(&p[17]);

            p[18] = sub250;
            fn_ovl_9878(&p[18]);
            p[19] = sub250;
            fn_ovl_9780(&p[19]);

            p[20] = sub2B0;
            fn_ovl_9878(&p[20]);
            p[21] = sub2B0;
            fn_ovl_9780(&p[21]);

            p[22] = sub430;
            fn_ovl_a9b0(&p[22]);
            p[23] = sub430;
            fn_ovl_a908(&p[23]);

            p[24] = sub594;
            fn_ovl_c300(&p[24]);
            p[25] = sub594;
            fn_ovl_c1f8(&p[25]);

            p[26] = a0->w00;
            fn_ovl_da70(&p[26]);
            w->state = 255;
        }
        break;
    }
}
