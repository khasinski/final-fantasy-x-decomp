/* 09286 projectile/particle update task (528 B). */

#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    Vec4 v00;
    Vec4 v10;
    float f20;
    int w24;
    int w28;
} OvlState;

typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    float fD8;
    float fDC;
} OvlCtx;

typedef struct {
    u8 pad00[0x10];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    int w2C;
    float f30;
    int w34;
    int w38;
    int w3C;
    u8 pad40[0x0B];
    u8 b4B;
} OvlPart;

extern OvlState g_ovl_state;
extern OvlCtx g_ovl_ctx;
extern u8 g_ovl_mgr[];

extern void fn_ovl_0ea8(int, void *);
extern void func_002DD968(void *, void *, void *, float);
extern float fn_ovl_4698(float, float, float, float);
extern void fn_ovl_4020(void *, void *);
extern int fn_ovl_38d0(void *);
extern OvlPart *fn_ovl_5680(void);
extern int *fn_ovl_4140(void *, int);
extern void fn_ovl_4f78(void *, int);
extern void func_002DD0B0(void *, void *);
extern float func_002B3DB0(float);
extern float func_001ACED8(void);

void ovl_09286_0c78(void *arg0)
{
    OvlState *st = &g_ovl_state;
    OvlCtx *ctx;
    int i;

    if (st->w24 > 0) {
        if (--st->w24 > 0) {
            return;
        }
        fn_ovl_0ea8(st->w28, &st->v10);
    }

    ctx = &g_ovl_ctx;
    func_002DD968(&ctx->fD0, &st->v00, &st->v10, st->f20);
    ctx->fD4 -= fn_ovl_4698(0.0f, 30.0f, 0.0f, st->f20);
    st->f20 += 0.05f;
    if (st->f20 >= 1.0f) {
        fn_ovl_4020(g_ovl_mgr, ctx);
        fn_ovl_38d0(arg0);
    } else {
        i = 0;
        do {
            OvlPart *p = fn_ovl_5680();
            if (p == 0) {
                break;
            }
            fn_ovl_4f78(p, *fn_ovl_4140(g_ovl_mgr, 0));
            func_002DD0B0(&p->f10, &ctx->fD0);
            p->f10 += func_002B3DB0(1.0f);
            p->f14 += func_002B3DB0(1.0f);
            p->f18 += func_002B3DB0(1.0f);
            p->f20 = (func_001ACED8() - 1.5f) * 0.5f;
            p->f24 = (func_001ACED8() - 1.5f) * 0.5f;
            p->f28 = (func_001ACED8() - 1.5f) * 0.5f;
            p->w2C = 0;
            p->f30 = 0.01f;
            p->w38 = 24;
            p->w3C = 24;
            p->b4B = 0;
            i++;
        } while (i < 4);
    }
}
