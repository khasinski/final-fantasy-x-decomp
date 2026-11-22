/* 09523 spawn & stop helpers (172 B span / 168 B code, 2 funcs). */

#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    int idx;
} OvlArg;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    float fD8;
    u8 padDC[0x54];
} OvlCtx;

extern u8 g_ovl_mgr[];
extern OvlCtx g_ovl_ctx[];

extern void fn_ovl_3960(void *, void *, int, int, float, int, int);
extern void fn_ovl_3dd0(void *, void *);

void ovl_09523_0bd0(OvlArg *arg)
{
    OvlCtx *ctx = &g_ovl_ctx[arg->idx];

    fn_ovl_3960(g_ovl_mgr, ctx, 0, 0, 0.03f, 0, 0);
    ctx->fD8 = -190.0f;
    ctx->fC4 = 3.1415927f;
    ctx->fD4 = 0.0f;
    ctx->fD0 = 0.0f;
}

void ovl_09523_0c58(OvlArg *arg)
{
    fn_ovl_3dd0(g_ovl_mgr, &g_ovl_ctx[arg->idx]);
}
