#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

static inline void wrap_angle(float *dst, float delta)
{
    float a = *dst + delta;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *dst = a;
}

typedef struct S4738Node {
    float v00[4];
    u8 pad10[0x50];
} S4738Node; /* size 0x60 */

typedef struct S4738Sub1730 {
    S4738Node arr[18];   /* 0x000..0x6C0 */
    float v6C0[4];       /* 0x6C0 */
    float v6D0[4];       /* 0x6D0 */
    float m6E0[4][4];    /* 0x6E0 */
    u8 pad720[0x40];
    float v760[4];       /* 0x760 */
    float v770[4];       /* 0x770 */
    float f780;          /* 0x780 */
    u8 pad784[0x1C];
    s32 s7A0;            /* 0x7A0 */
    s32 s7A4;            /* 0x7A4 */
} S4738Sub1730;

typedef struct S4738Part {
    float v00[4];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 s30[0xC];
    float f3C;
    u8 pad40[0xC];
    s32 s4C;
    s32 s50;
    s32 s54;
    u8 pad58[8];
    s32 s60;
    u8 pad64[3];
    u8 b67;
    u8 pad68[3];
    u8 b6B;
} S4738Part;

typedef struct S4738Global {
    u8 pad00[0x14B0];
    float vC60[4];       /* 0x14B0? check offset */
    u8 padC70[0xAC0];
    S4738Sub1730 sub;    /* 0x1F80 */
} S4738Global;

extern S4738Global *D_01B0B1F8;
extern u8 D_01B0B130[];

extern void **func_01B06F48(void *a0, s32 a1);
extern float func_01B044E8(s32 a0);
extern void func_01B04538(s32 a0, s32 a1, s32 a2, float *a3);
extern void func_002DD128(float (*m)[4]);
extern void func_01B07910(float (*m)[4], float *v);
extern void func_002DD270(float (*dst)[4], float (*src)[4], float a0);
extern void func_002DD318(float (*dst)[4], float (*src)[4], float a0);
extern void func_002DCE38(float (*dst)[4], float (*a1)[4], float (*a2)[4]);
extern void func_002DCE08(float *dst, float (*m)[4], float *src);
extern S4738Part *func_01B0A788(void);
extern void func_01B07D80(void *a0, void *a1);
extern float func_002B3DB0(float a0);

void func_01B02890(void)
{
    float m00[4][4];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    float pts[2][4];
    S4738Global *g = D_01B0B1F8;
    S4738Sub1730 *sub = &g->sub;
    void *tex;
    float floor_y;
    float (*pt)[4];
    register s32 i __asm__("$21");

    func_01B04538(-1, 0x11, 0, v40);
    func_01B04538(-1, 0x37, 0, v50);

    VU0_LQC2_INPUTS(1, v40, v50, v60);
    VU0_LQC2(2, 0, v50);
    VU0_OP("vsub.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, v60);

    VU0_LQC2_INPUTS(1, v50, v60, sub->v760);
    VU0_LQC2(2, 0, v60);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, sub->v760);

    sub->v760[1] -= 3.0f;
    func_002DD128(sub->m6E0);
    func_01B07910(sub->m6E0, sub->v770);
    sub->m6E0[3][2] = -100.0f;
    wrap_angle(&sub->f780, 0.0017453293f);

    func_002DD128(m00);
    func_002DD270(m00, m00, sub->f780);
    func_002DCE38(sub->m6E0, sub->m6E0, m00);
    sub->m6E0[3][2] = 0.0f;

    v70[0] = 0.0f;
    v70[1] = 0.0f;
    v70[2] = -40.0f;
    v70[3] = 1.0f;
    func_002DCE08(v70, sub->m6E0, v70);

    VU0_LQC2(1, 0, sub->v760);
    VU0_LQC2(2, 0, v70);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, sub->v760);

    tex = *func_01B06F48(D_01B0B130, 5);
    floor_y = func_01B044E8(-1) - 1.0f;
    func_01B04538(-1, 0x92, 0, pts[0]);
    func_01B04538(-1, 0xA3, 0, pts[1]);

    v70[0] = 0.0f;
    v70[1] = 0.0f;
    v70[3] = 1.0f;
    pt = pts;
    for (i = 0; i < 1; pt++, i++) {
        S4738Part *p = func_01B0A788();
        if (p == 0) {
            break;
        }
        func_01B07D80(p->s30, tex);
        func_002DD128(m00);
        func_002DD318(m00, m00, func_002B3DB0(3.1415927f));
        v70[2] = func_002B3DB0(10.0f);
        func_002DCE08(v60, m00, v70);
        COPY_VEC(p->v00, *pt);
        p->v00[0] += v60[0];
        p->v00[1] += func_002B3DB0(1.0f);
        p->v00[2] += v60[2];
        p->f10 = func_002B3DB0(0.2f);
        p->f14 = func_002B3DB0(0.1f) + -0.3f;
        p->f18 = func_002B3DB0(0.2f);
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = 0.0f;
        p->f24 = 0.0001f;
        p->f28 = 0.0f;
        p->f2C = 1.0f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.35f;
        p->s4C = 0x20;
        p->s50 = 0x10;
        p->s54 = -0x10;
        p->b67 = 0x40;
        p->b6B = 0;
        p->s60 = 0;
        if (p->v00[1] > floor_y) {
            p->v00[1] = floor_y - 1.0f;
        }
    }

    sub->s7A0--;
    if (sub->s7A0 == 0) {
        register s32 c1e __asm__("$3") = 0x1E;
        sub->s7A4 = 1;
        sub->s7A0 = c1e;
        v60[0] = (g->vC60[0] - sub->v760[0]) / 29.0f;
        v60[1] = (g->vC60[1] - sub->v760[1]) / 29.0f;
        v60[2] = (g->vC60[2] - sub->v760[2]) / 29.0f;
        sub->v6C0[0] = v60[0] + v60[0];
        sub->v6C0[1] = v60[1] + v60[1];
        sub->v6C0[2] = v60[2] + v60[2];
        sub->v6C0[3] = 0.0f;
        sub->v6D0[0] = (v60[0] * -2.0f) / 29.0f;
        sub->v6D0[1] = (v60[1] * -2.0f) / 29.0f;
        sub->v6D0[2] = (v60[2] * -2.0f) / 29.0f;
        sub->v6D0[3] = 0.0f;
    }
}
