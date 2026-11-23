#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S4070Trail {
    u8 pad00[0x213];
    u8 b213;
    u8 pad214[8];
    float f21C;
    float f220;
    u8 pad224[8];
    s32 s22C;
} S4070Trail;

typedef struct S4070Sub {
    float v00[4];
    u8 pad10[0x2900];
    S4070Trail trail; /* 0x2910 -> +0x2F80 = 0x5890 */
    u8 pad2B40[0x20];
    void *p2B60;
    s32 s2B64;
    s32 s2B68;
} S4070Sub;

typedef struct S4070Item {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    float vD0[4];
    u8 padE0[4];
    float fE4;
    float fE8;
    u8 padEC[0x44];
} S4070Item; /* size 0x130 */

typedef struct S4070Global {
    S4070Item items[1]; /* 0x0000 */
    u8 pad130[0x2E50];
    S4070Sub sub;       /* 0x2F80 */
    u8 pad5AF0[0x8FE4];
    float fEAD0;        /* 0xEAD0 */
} S4070Global;

extern S4070Global *D_01B0DCA8;
extern u8 D_01B0DBE0[];
extern s32 D_01B00B20[];

extern void func_01B066A0(float *dst);
extern void func_01B09968(void *a0);
extern void func_01B04018(s32 a0, float *a1);
extern void func_002DD128(float (*m)[4]);
extern void func_01B067B8(S4070Trail *a0, float (*m)[4], float *v);
extern void **func_01B0A1D8(void *a0, s32 a1);
extern void func_01B06738(S4070Trail *a0, void *tex);
extern void *func_01B098E8(void (*fn)(void *));
extern void func_01B09AB0(void *a0);
extern void func_01B0A0B8(void *a0, void *a1);
extern void func_01B09C48(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, float f0);

void func_01B04070(void *a0)
{
    float m00[4][4];
    float v40[4];
    S4070Global *g = D_01B0DCA8;
    S4070Sub *sub = &g->sub;
    S4070Trail *trail;

    if (sub->s2B64 > 0) {
        sub->s2B64--;
    }
    trail = &sub->trail;
    func_01B066A0(v40);
    if (sub->s2B64 <= 0) {
        if (sub->s2B68 == 0 && trail->s22C > 0) {
            trail->s22C--;
            COPY_VEC(v40, sub->v00);
        } else {
            func_01B09968(a0);
            return;
        }
    } else {
        func_01B04018(sub->s2B68, v40);
        COPY_VEC(sub->v00, v40);
    }

    if (sub->s2B68 == 0) {
        func_002DD128(m00);
        m00[2][2] = 0.2f;
        m00[1][1] = 0.2f;
        m00[0][0] = 0.2f;
        func_01B067B8(trail, m00, v40);
    }
}

void func_01B04168(S4070Trail *a0)
{
    void *tex = *func_01B0A1D8(D_01B0DBE0, 11);
    func_01B06738(a0, tex);
    a0->s22C = 0x10;
    a0->f220 = 1.0f;
    a0->f21C = 0.5f;
    a0->b213 = 0x40;
}

void func_01B041D0(void)
{
    S4070Global *g = D_01B0DCA8;
    S4070Sub *sub = &g->sub;

    if (sub->s2B68 == 0) {
        func_01B04168(&sub->trail);
    }
    if (sub->s2B68 != 1) {
        sub->s2B64 = 0x71;
        func_01B09AB0(func_01B098E8(func_01B04070));
    }
}

void func_01B04240(void)
{
    register S4070Global *g __asm__("$17") = D_01B0DCA8;
    S4070Sub *sub = &g->sub;
    s32 idx;
    S4070Item *it;
    float f;

    func_01B0A0B8(D_01B0DBE0, sub->p2B60);
    idx = D_01B00B20[sub->s2B68];
    it = &g->items[idx];
    func_01B09C48(D_01B0DBE0, it, idx, 0, 0, 0, 0.2f);
    func_01B066A0(it->vD0);
    it->fC4 = g->fEAD0;
    it->fE4 = 3.0f;
    it->fE8 = -3.0f;
}
