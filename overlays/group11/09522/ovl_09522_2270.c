/* 09522 unique setup function (380 B). */
#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 w18;
    u32 w1C;
    u8 pad20[0x0C];
    float f2C;
    u8 pad30[4];
    float f34;
    float f38;
    u8 pad3C[4];
    void *p40;
    u8 pad44[0x0C];
    u8 sub50[0x20];
    u8 sub70[4];
    float f74;
    u8 pad78[8];
    u8 sub80[0x20];
    u8 subA0[4];
    float fA4;
    u8 padA8[4];
    float fAC;
    u8 subB0[0x20];
    u8 subD0[0x10];
    u8 subE0[0x10];
} OvlObj2270;

extern u8 fn_ovl_1f48[];
extern u8 g_ovl_910[];
extern u8 g_ovl_b20[];
extern u8 g_ovl_b38[];

extern void fn_ovl_bde0(void *);
extern void fn_ovl_c1e8(void *);
extern void fn_ovl_7b48(void *);
extern void fn_ovl_3d38(void *);
extern void fn_ovl_8018(void *);
extern void fn_ovl_4080(void *);
extern void fn_ovl_37f8(void *);
extern void fn_ovl_8cd0(void *);
extern void fn_ovl_39f0(void *);
extern float MsGetChrBtlPosHeight(int);

void ovl_09522_2270(OvlObj2270 *s0, u8 *s2)
{
    void *a[4];
    void *b[6];
    u8 *s6 = s0->sub80;
    u8 *s5 = s0->subB0;
    u8 *s4 = s0->sub50;
    u8 *s3 = s0->subE0;
    u8 *s1;

    a[0] = s0;
    a[1] = fn_ovl_1f48;
    a[2] = s0;
    fn_ovl_bde0(a);

    a[0] = g_ovl_b20;
    a[1] = s0;
    fn_ovl_c1e8(a);

    s1 = g_ovl_b38;
    a[0] = s6;
    a[1] = s1;
    fn_ovl_7b48(a);

    a[0] = s2;
    a[1] = s0->subA0;
    fn_ovl_3d38(a);

    s0->f34 = s0->fA4;
    s0->fAC = 1.0f;

    a[0] = s5;
    a[1] = s1;
    fn_ovl_8018(a);

    a[0] = s2;
    a[1] = s0->subD0;
    fn_ovl_4080(a);

    a[0] = s4;
    a[1] = s1;
    fn_ovl_7b48(a);

    a[0] = s2;
    a[1] = s0->sub70;
    fn_ovl_37f8(a);

    {
        u32 *p = (u32 *)b;
        s0->f38 = s0->f74;
        *(volatile u32 *)&b[0] = (u32)s3;
        p[1] = (u32)s1;
        p[2] = (u32)g_ovl_910;
        b[3] = s6;
        b[4] = s5;
        b[5] = s4;
        fn_ovl_8cd0(p);
    }

    a[0] = s2;
    a[1] = s3;
    fn_ovl_39f0(a);

    s0->f2C = MsGetChrBtlPosHeight(*(int *)(s2 + 0x54));
    s0->p40 = s2;
    s0->w1C = 0;
    s0->w18 = 0;
}
