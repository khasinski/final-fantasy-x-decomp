/* 09522 state machine 2 (972 B). */
#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    int frame;
    int timer;
    u8 pad24[0x0C];
    u8 sub30[0x20];
    u8 sub50[0x54];
    int chr_id;
    u8 padA8[0x4C8];
    u8 sub570[0xA0];
    u8 sub610[0x20];
    u8 sub630[4];
    float f634;
    u32 w638;
    float f63c;
    u8 sub640[0x20];
    float f660;
    float f664;
    float f668;
    float f66c;
    u8 sub670[0x20];
    u8 sub690[0x160];
    u8 sub7f0[0x150];
    u8 sub940[0x100];
    u8 suba40[0x40];
    u8 suba80[0x10];
} OvlObj2;

typedef struct {
    u32 w00;
    OvlObj2 *obj;
} OvlCtx2;

extern int g_ovl_758;
extern int g_ovl_760;
extern u8 g_ovl_880[];
extern u8 g_ovl_910[];
extern u8 g_ovl_b38[];
extern u8 g_ovl_b58[];
extern u8 g_ovl_b80[];
extern u8 g_ovl_d1d0[];
extern int g_ovl_d1fc;

extern void fn_ovl_40f0(void *);
extern void fn_ovl_2b40(void *);
extern void fn_ovl_7b48(void *);
extern void fn_ovl_3e50(void *);
extern void fn_ovl_8018(void *);
extern void fn_ovl_4080(void *);
extern float MsGetChrWidth(int);
extern void fn_ovl_8cd0(void *);
extern void fn_ovl_ae30(void *);
extern void fn_ovl_6e90(void *);
extern void fn_ovl_6fc0(void *);
extern void fn_ovl_a5c0(void *);
extern void fn_ovl_a588(void *);
extern void fn_ovl_2270(void *, void *);
extern void fn_ovl_70a0(void *);
extern void fn_ovl_2d20(void *);
extern void fn_ovl_2c50(void *);
extern void fn_ovl_4298(void *);
extern void fn_ovl_4190(void *);
extern void fn_ovl_be88(void *);

void ovl_09522_23f0(OvlCtx2 *a0)
{
    OvlObj2 *s4 = a0->obj;
    u32 pad00[4];
    union {
        u32 w[6];
        struct {
            u32 w0;
            u32 w1;
            float f2;
            float f3;
        } f;
        struct {
            u32 w0;
            u32 w1;
            u32 w2;
            u8 b0c;
        } b;
        struct {
            u32 pad10[4];
            struct {
                u32 w0;
                u32 w1;
                u32 w2;
                u32 w3;
                u8 b10;
            } a20;
        } s;
    } u;
    u32 arg40;
    u32 arg44;
    u32 arg48;
    u32 arg4c;
    u32 arg50;
#define a10 u
#define a20 u.s.a20

    again:
    switch (s4->state) {
    case 0:
    {
        float w;
        u32 *p = a10.w;

        p[1] = (u32)g_ovl_b38;
        a10.b.w0 = (u32)s4->sub570;
        a10.b.w2 = (u32)g_ovl_760;
        a10.b.b0c = 0;
        fn_ovl_40f0(p);

        {
            u32 *p2 = (u32 *)&a20;
            p2[1] = (u32)g_ovl_b38;
            a20.w0 = (u32)s4->sub30;
            a20.w2 = (u32)g_ovl_760;
            a20.w3 = 0;
            a20.b10 = 0;
            fn_ovl_2b40(p2);
        }

        a10.w[0] = (u32)s4->sub610;
        p[1] = (u32)g_ovl_b38;
        fn_ovl_7b48(p);

        a10.w[1] = (u32)s4->sub630;
        p[2] = 1;
        a10.w[0] = (u32)s4->sub50;
        fn_ovl_3e50(p);

        {
            float y = s4->f634;
            s4->f63c = 1.0f;
            y -= 0.5f;
            a10.w[0] = (u32)s4->sub670;
            p[1] = (u32)g_ovl_b38;
            s4->f634 = y;
            fn_ovl_8018(p);
        }

        a10.w[0] = (u32)s4->sub50;
        a10.w[1] = (u32)s4->sub690;
        fn_ovl_4080(p);

        a10.w[0] = (u32)s4->sub640;
        p[1] = (u32)g_ovl_b38;
        fn_ovl_7b48(p);

        s4->f660 = 1.0f;
        s4->f664 = 1.0f;
        s4->f668 = 1.0f;
        w = MsGetChrWidth(s4->chr_id) * 0.1f * 0.7f;
        s4->f66c = w;
        if (w > 1.0f) {
            s4->f66c = 1.0f;
        }

        a10.w[0] = (u32)s4->sub7f0;
        p[2] = (u32)g_ovl_910;
        a10.w[3] = (u32)s4->sub610;
        a10.w[4] = (u32)s4->sub670;
        a10.w[5] = (u32)s4->sub640;
        p[1] = (u32)g_ovl_b38;
        fn_ovl_8cd0(p);

        {
            u32 d1fc = g_ovl_d1fc;
            u32 b58 = (u32)g_ovl_b58;
            u32 d1d0 = (u32)g_ovl_d1d0;
            a10.w[3] = d1fc;
            a10.w[0] = (u32)s4->sub940;
            p[4] = d1d0;
            p[1] = b58;
            a10.w[2] = (u32)s4->sub7f0;
            a10.w[5] = 0;
            fn_ovl_ae30(p);
        }

        p[1] = (u32)g_ovl_b58;
        a10.w[0] = (u32)g_ovl_b80;
        fn_ovl_6e90(p);

        *(volatile float *)(g_ovl_b80 + 0x30) = 0.5f;
        a10.w[0] = (u32)g_ovl_b80;
        *(volatile float *)&p[2] = 0.03f;
        *(volatile float *)(g_ovl_b80 + 0x6C) = 0.5f;
        *(volatile float *)(g_ovl_b80 + 0x68) = 0.5f;
        *(volatile float *)(g_ovl_b80 + 0x64) = 0.5f;
        *(volatile float *)(g_ovl_b80 + 0x60) = 0.5f;
        *(volatile float *)(g_ovl_b80 + 0x38) = 0.5f;
        *(volatile float *)(g_ovl_b80 + 0x34) = 0.5f;
        a10.w[1] = 0;
        fn_ovl_6fc0(p);

        {
            u32 v = *(volatile u32 *)&g_ovl_758;
            *(volatile u32 *)&p[1] = (u32)g_ovl_b38;
            a10.w[2] = (u32)s4->sub7f0;
            p[3] = (u32)g_ovl_880;
            a10.w[4] = v;
            a10.w[0] = (u32)s4->suba40;
            a10.w[5] = 0;
            fn_ovl_a5c0(p);
        }

        a10.w[0] = (u32)s4->suba40;
        a10.w[1] = 0;
        fn_ovl_a588(p);

        fn_ovl_2270(s4->suba80, s4->sub50);
        s4->state = 20;
        goto again;
    }
    case 20:
        s4->timer = 45;
        s4->state = 21;
        /* fallthrough */

    case 21:
        if (s4->timer > 0) {
            break;
        }
        {
            u8 *v0 = g_ovl_b80;
            u32 *v1 = a10.w;
            a10.w[0] = (u32)v0;
            ((float *)v1)[2] = 0.03f;
            ((float *)v1)[3] = 1.0f;
            *(float *)(v0 + 0x68) = 1.0f;
            *(float *)(v0 + 0x64) = 1.0f;
            *(float *)(v0 + 0x60) = 1.0f;
            *(float *)(v0 + 0x38) = 1.0f;
            *(float *)(v0 + 0x34) = 1.0f;
            *(float *)(v0 + 0x30) = 1.0f;
            *(float *)(v0 + 0x6C) = 1.0f;
            a10.w[1] = 0;
            fn_ovl_70a0(v1);
        }
        s4->state = 10000;
        goto again;

    case 10000:
        arg40 = (u32)s4->sub30;
        fn_ovl_2d20(&arg40);
        arg44 = (u32)s4->sub30;
        fn_ovl_2c50(&arg44);
        arg48 = (u32)s4->sub570;
        fn_ovl_4298(&arg48);
        arg4c = (u32)s4->sub570;
        fn_ovl_4190(&arg4c);
        arg50 = a0->w00;
        fn_ovl_be88(&arg50);
        break;
    }

    s4->timer--;
    s4->frame++;
}
