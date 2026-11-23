/* Shared 09286/09695/09698/09699/09701 effect init (612 B). */

#include "vu0.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    u128 vecD0;
    u8 padE0[0x30];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

typedef struct {
    u128 vec00;
    u8 pad10[0x10];
    int w20;
    int w24;
    int w28;
} OvlState;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTaskObj;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern int g_ovl_tab_0478[];
extern u8 g_ovl_dat_0498[];
extern u8 g_ovl_dat_04b0[];
extern u8 g_ovl_dat_04e8[];
extern u8 g_ovl_5a58[];
extern OvlState g_ovl_state;
extern void *g_ovl_5ab0;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_5d60;
extern void *g_ovl_5d64;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0bc8(void);
extern void fn_ovl_0bf8(void);
extern void fn_ovl_0c78(void);
extern int fn_ovl_0e88(void);
extern float fn_ovl_1168(int);
extern void fn_ovl_1290(int, u128 *, int);
extern void fn_ovl_18d8(u128 *);
extern void fn_ovl_2c78(int, void *, void *);
extern void fn_ovl_3338(void *, void *, void *);
extern OvlTaskObj *fn_ovl_3850(void *);
extern void fn_ovl_3a18(OvlTaskObj *);
extern void fn_ovl_3ad8(void *, void *, void *, int);
extern void fn_ovl_3bb0(void *, void *, int, int, int, void *, float);
extern void fn_ovl_4150(void);
extern void fn_ovl_55e8(void *, int);

int ovl_09286_0960(void)
{
    u128 v;
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlState *state;
    register OvlCtx *ctx __asm__("$17");
    OvlTaskObj *t;
    int idx;
    int val;

    g_ovl_5d60 = p;
    g_ovl_5d64 = p + 0x40000;
    g_ovl_5ab0 = p + 0x140000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3ad8(mgr, g_ovl_dat_0040, g_ovl_5d60, 0x40000);

    state = &g_ovl_state;
    idx = fn_ovl_0e88();
    val = g_ovl_tab_0478[idx];
    ctx = g_ovl_ctx;

    fn_ovl_3bb0(mgr, ctx, 0, val - 1, 0, 0, 0.12f);
    fn_ovl_1290(-1, &ctx->vecD0, 0);
    ctx->fC4 = fn_ovl_1168(-1);
    fn_ovl_3338(p + 0x163000, g_ovl_res, g_ovl_dat_04b0);
    ctx->w110 = p + 0x163000;
    fn_ovl_18d8(&v);

    ctx++;
    fn_ovl_3bb0(mgr, ctx, 1, val + 0x13, 0, (void *)fn_ovl_4150, 0.9f);
    fn_ovl_1290(0, &ctx->vecD0, 0);
    ctx->fC4 = fn_ovl_1168(-1);
    MMI_COPY_LQ_A3(&ctx->vecD0, &v);
    MMI_COPY_SQ_A3(&ctx->vecD0);
    fn_ovl_3338(p + 0x163040, g_ovl_res, g_ovl_dat_0498);
    ctx->w110 = p + 0x163040;

    MMI_COPY_LQ_A3(&v, &v);
    MMI_COPY_SQ_A3(&state->vec00);
    state->w24 = val;
    state->w28 = idx;
    state->w20 = 0;
    fn_ovl_2c78(-1, g_ovl_5a58, g_ovl_dat_04e8);

    t = fn_ovl_3850((void *)fn_ovl_0bc8);
    t->b18 = 1;
    fn_ovl_3a18(t);

    t = fn_ovl_3850((void *)fn_ovl_0c78);
    fn_ovl_3a18(t);

    fn_ovl_55e8(p + 0x160000, 0x80);

    t = fn_ovl_3850((void *)fn_ovl_0bf8);
    t->b18 = 2;
    fn_ovl_3a18(t);
    return 0;
}
