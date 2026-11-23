#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S40A8Entry {
    u8 pad00[0xA0];
    float fA0;
    float fA4;
    float fA8;
    u8 padAC[0x34];
} S40A8Entry; /* size 0xE0 */

typedef struct S40A8Big {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[8];
    float vD0[4];
    u8 padE0[0x280];
    float v360[4];
    u8 pad370[0x10];
    void *p380;
    s32 s384;
    void *p388;
    u8 pad38C[8];
    s32 s394;
    s32 s398;
    u16 u39C;
} S40A8Big;

typedef struct S40A8Item {
    u8 pad00[0x60];
    float v60[4];
    u8 pad70[0x54];
    float fC4;
    u8 padC8[8];
    float vD0[4];
    u8 padE0[0x44];
    u16 u124;
    u8 pad126[0xA];
} S40A8Item; /* size 0x130 */

typedef struct S40A8Part {
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
    u8 pad54[0xC];
    s32 s60;
    u8 pad64[7];
    u8 b6B;
} S40A8Part;

typedef struct S40A8Task {
    u8 pad00[0x14];
    s16 h14;
    s16 h16;
} S40A8Task;

typedef struct S40A8Global {
    u8 pad00[0xC20];
    float vC20[4];
    u8 padC30[0x30];
    float vC60[4];
    u8 padC70[0x10];
    float vC80[4];
    u8 padC90[0x370];
    S40A8Entry arr1000[8]; /* 0x1000 */
    u8 pad1700[0x7E0];
    S40A8Big big;          /* 0x1EE0 */
    u8 pad2280[0x6B8];
    float f2938;           /* 0x2938 */
} S40A8Global;

extern S40A8Global *D_01B0E828;
extern u8 D_01B0D6B8[];
extern S40A8Item D_01B0DA90[];
extern s32 D_01B011F4;
extern void D_01B03EA8(void);

extern void func_01B08B18(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, float f0);
extern void func_01B0C1C8(S40A8Big *a0, s32 a1, float f0);
extern void func_01B08F88(void *a0, void *a1);
extern void func_01B08838(void *a0);
extern void func_01B06698(s32 a0, s32 a1, s32 a2, float *a3);
extern float func_01B06648(s32 a0);
extern S40A8Part *func_01B0CD08(void);
extern void **func_01B090A8(void *a0, s32 a1);
extern void func_01B09EE0(void *a0, void *a1);
extern float func_002B3DB0(float a0);

void func_01B040A8(void)
{
    S40A8Global *g = D_01B0E828;
    S40A8Big *big = &g->big;
    s32 n;
    s32 i;
    S40A8Entry *e;

    func_01B08B18(D_01B0D6B8, big, 9, 0, 0, 0, 0.06000000238418579f);
    COPY_VEC(big->vD0, g->vC80);
    {
        register float c0 __asm__("$f1") = g->vC20[0];
        register void *dst __asm__("$4") = big->v360;
        register void *src __asm__("$3");
        big->fC0 = c0;
        __asm__("" : "+r"(dst));
        src = g->vC60;
        __asm__("" : "+r"(src) : "r"(dst));
        big->fC4 = g->vC20[1];
        COPY_VEC(dst, src);
    }
    big->p380 = D_01B0D6B8;
    big->s384 = 0;
    big->s394 = 0;
    big->s398 = 0;
    big->u39C = 0;
    big->p388 = D_01B03EA8;
    func_01B0C1C8(big, 1, 12.0f);

    n = D_01B011F4;
    e = g->arr1000;
    for (i = 0; i < n; i++, e++) {
        e->fA8 = 0.75f;
        e->fA4 = 0.75f;
        e->fA0 = 0.75f;
    }
}

void func_01B041B0(void)
{
    D_01B0DA90[0].u124 |= 1;
}

void func_01B041C8(void)
{
    D_01B0DA90[0].v60[3] = 0.18f;
    D_01B0DA90[0].v60[2] = 0.18f;
    D_01B0DA90[0].v60[1] = 0.18f;
    D_01B0DA90[0].v60[0] = 0.18f;
    D_01B0DA90[0].u124 &= ~1;
}

void func_01B04200(void)
{
    S40A8Global *g = D_01B0E828;
    S40A8Item *it0 = &D_01B0DA90[0];
    S40A8Item *it1 = &D_01B0DA90[1];

    func_01B08F88(D_01B0D6B8, it0);
    func_01B08B18(D_01B0D6B8, it1, 4, 0, 0, 0, 0.18f);
    {
        register void *src __asm__("$3") = it0->vD0;
        __asm__("" : "+r"(src));
        COPY_VEC(it1->vD0, src);
    }
    it1->fC4 = g->f2938;
}

void func_01B042A0(S40A8Task *a0)
{
    float pts[4][4];
    float (*pt)[4];
    float floor_y;
    s32 i;

    if (a0->h14 > 0) {
        a0->h14--;
        return;
    }
    a0->h16--;
    if (a0->h16 <= 0) {
        func_01B08838(a0);
        return;
    }

    func_01B06698(-1, 0x11, 0, pts[0]);
    func_01B06698(-1, 0x37, 0, pts[1]);
    func_01B06698(-1, 0x92, 0, pts[2]);
    func_01B06698(-1, 0xA3, 0, pts[3]);
    floor_y = func_01B06648(-1) - 2.0f;

    pt = pts;
    for (i = 0; i < 2; pt++, i++) {
        S40A8Part *p;
        if ((*pt)[1] < floor_y) {
            continue;
        }
        p = func_01B0CD08();
        if (p == 0) {
            break;
        }
        func_01B09EE0(p->s30, *func_01B090A8(D_01B0D6B8, 2));
        COPY_VEC(p->v00, *pt);
        p->v00[0] += func_002B3DB0(1.0f);
        p->v00[1] = floor_y - 1.0f;
        p->v00[2] += func_002B3DB0(1.0f);
        p->f10 = func_002B3DB0(0.15f);
        p->f14 = func_002B3DB0(0.04f) + -0.08f;
        p->f18 = func_002B3DB0(0.15f);
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = 0.0f;
        p->f24 = 0.0001f;
        p->f28 = 0.0f;
        p->f2C = 1.0f;
        {
            float sz = (func_002B3DB0(0.2f) + 1.0f) * 0.35f;
            p->s60 = 0;
            p->s4C = 0x20;
            p->s50 = 0x20;
            *(volatile u8 *)&p->b6B = 0;
            p->f3C = sz;
        }
    }
}
