#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S33B8Entry {
    u8 pad00[0x14];
    s32 s14;
    u8 pad18[8];
    float m20[4][4];
    float f60;
    float f64;
    float f68;
    float f6C;
    float f70;
    float f74;
    float f78;
    float f7C;
    float f80;
    float f84;
    float f88;
    float f8C;
    float f90;
    float f94;
    float f98;
    float f9C;
    float fA0;
    float fA4;
    float fA8;
    float fAC;
    float fB0;
    float fB4;
    float fB8;
    float fBC;
    s32 sC0;
    s32 sC4;
    s32 sC8;
    s32 sCC;
    s32 sD0;
    u8 padD4[0xC];
} S33B8Entry; /* size 0xE0 */

typedef struct S33B8Item {
    u8 pad00[0x60];
    float v60[4];
    u8 pad70[0x60];
    float vD0[4];
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x10];
    s32 s118;
} S33B8Item;

typedef struct S33B8Sub1700 {
    float v00[4];
    float v10[4];
    s32 s20;
} S33B8Sub1700;

typedef struct S33B8Anim {
    s32 s00;
    s32 s04;
    s32 s08;
    s32 s0C;
} S33B8Anim;

typedef struct S33B8Global {
    u8 pad00[0xBE0];
    float vBE0[4];       /* 0x0BE0 */
    u8 padBF0[0x20];
    float vC10[4];       /* 0x0C10 */
    float vC20[4];       /* 0x0C20 */
    u8 padC30[0x20];
    float vC50[4];       /* 0x0C50 */
    float vC60[4];       /* 0x0C60 */
    float vC70[4];       /* 0x0C70 */
    float vC80[4];       /* 0x0C80 */
    u8 padC90[0x10];
    float fCA0;
    float fCA4;
    float fCA8;
    float fCAC;
    float fCB0;
    float fCB4;
    float fCB8;
    float fCBC;
    u8 padCC0[0x340];
    S33B8Entry arr1000[8]; /* 0x1000..0x1700 */
    S33B8Sub1700 s1700;    /* 0x1700 */
    u8 pad1724[0xCB8];
    S33B8Anim s23DC;       /* 0x23DC */
    u8 pad23EC[0x544];
    void *p2930;           /* 0x2930 */
    u8 pad2934[4];
    float f2938;           /* 0x2938 */
} S33B8Global;

typedef struct S33B8Count {
    s32 s00;
    s32 count;
} S33B8Count;

extern S33B8Global *D_01B0E828;
extern S33B8Count D_01B011F0;
extern void D_01B02F58(void);

extern void func_01B061F8(s32 a0, float *a1, s32 a2);
extern float func_01B06648(s32 a0);
extern float func_002B3DB0(float a0);
extern float func_01B099F0(float *a0, float *a1);
extern void func_01B09848(float *dst, float *a1, float *a2);
extern float func_01B060D0(s32 a0);
extern void func_01B07468(s32 a0, float (*m)[4]);
extern void func_01B07318(s32 a0, s32 a1);
extern void *func_01B087B8(void (*fn)(void));
extern void func_01B08980(void *a0);
extern void func_01B079E8(s32 a0, float *a1, float *a2);
extern void func_002DD128(float (*m)[4]);
extern void func_01B09A70(float (*m)[4], float *v);
extern void func_002DCE08(float *dst, float (*m)[4], float *src);
extern void func_002DD020(float *dst, float *a1, float *a2);
extern void func_00117E58(s32 a0);
extern void func_01B06698(s32 a0, s32 a1, s32 a2, float *a3);
extern void func_01B09950(float *a0, float *a1, float *a2);
extern void func_002DD068(float *dst, float *src, float s);
extern void func_01B0C650(S33B8Anim *a0, s32 a1);

void func_01B033B8(void)
{
    float v00[4];
    float v10[4];
    S33B8Global *g = D_01B0E828;
    S33B8Entry *e = g->arr1000;
    s32 n = D_01B011F0.count;
    register float max_dist __asm__("$f22") = 0.0f;
    s32 i;
    void *t;

    for (i = 0; i < n; i++, e++) {
        float h;
        float r;
        float v;
        float dist;

        e->s14 = 1;
        func_01B061F8(i, v00, 0);
        h = func_01B06648(i);
        e->f94 = v00[1];
        r = func_002B3DB0(5.0f);
        v = (r + 130.0f + (v00[1] - h)) / 59.0f;
        v00[1] = g->vC50[1];
        dist = func_01B099F0(v00, g->vC50);
        if (dist > max_dist) {
            max_dist = dist;
        }
        e->fB8 = dist;
        e->fBC = dist;
        func_01B09848(v10, g->vC50, v00);
        e->fB0 = v10[1];
        e->fB4 = 0.034906585f;
        e->f60 = 0.0f;
        e->f64 = v * -2.0f;
        e->f68 = 0.0f;
        e->f6C = 0.0f;
        e->f70 = 0.0f;
        e->f74 = (v + v) / 59.0f;
        e->f78 = 0.0f;
        e->f7C = 0.0f;
        e->f80 = 0.0f;
        e->f84 = func_01B060D0(i);
        e->f88 = 0.0f;
        e->f8C = 0.0f;
        e->fA0 = 1.0f;
        e->fA4 = 1.0f;
        e->fA8 = 1.0f;
        e->sC0 = 0x3C;
        e->sC4 = 8;
        e->sC8 = 0;
        e->sCC = 1;
        e->sD0 = 0;
        func_01B07468(i, e->m20);
        func_01B07318(i, 0);
    }

    if (max_dist > 35.0f) {
        S33B8Count *p = &D_01B011F0;
        s32 cnt;
        __asm__ volatile("" : "+r"(p));
        max_dist = 35.0f / max_dist;
        __asm__ volatile("" : "+f"(max_dist) : "r"(p));
        cnt = p->count;
        e = g->arr1000;
        for (i = 0; i < cnt; i++, e++) {
            e->fBC *= max_dist;
        }
    }

    t = func_01B087B8(D_01B02F58);
    func_01B08980(t);
    g->p2930 = t;
}

void func_01B03640(void)
{
    float m00[4][4];
    float v40[4];
    S33B8Global *g = D_01B0E828;

    func_01B09848(g->vC20, g->vC70, g->vC60);
    g->vC20[0] = -0.41887903f;
    g->vC20[1] = g->f2938;
    g->vC20[2] = 0.0f;
    func_01B079E8(-1, g->vBE0, g->vC20);
    COPY_VEC(g->vC10, g->vC70);
    v40[0] = 0.0f;
    v40[1] = 0.0f;
    v40[2] = 120.0f;
    v40[3] = 1.0f;
    func_002DD128(m00);
    func_01B09A70(m00, g->vC20);
    func_002DCE08(v40, m00, v40);
    func_002DD020(g->vC80, g->vC70, v40);
    g->vC80[3] = 1.0f;
    g->vC10[1] -= 110.0f;
    g->fCA0 = 0.0f;
    g->fCA4 = 0.5f;
    g->fCA8 = 0.0f;
    g->fCAC = 0.0f;
    g->fCB0 = 0.0f;
    g->fCB4 = 0.01f;
    g->fCB8 = 0.0f;
    g->fCBC = 0.0f;
    func_00117E58(0x28);
}

void func_01B03778(float *a0)
{
    float v00[4];
    S33B8Global *g = D_01B0E828;

    func_01B06698(-1, 0x5C, 0, a0);
    v00[0] = 0.0f;
    v00[1] = -2.0f;
    v00[2] = -2.0f;
    func_01B09950(g->vC20, a0, v00);
}

void func_01B037E0(S33B8Item *a0)
{
    if (a0->s118 < 0x3B) {
        func_01B03778(a0->vD0);
    } else {
        a0->p104 = 0;
    }
}
