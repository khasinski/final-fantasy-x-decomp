/* 09413 spawn helper (128 B). */

#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
} OvlCtx;

extern u8 g_ovl_mgr[];
extern OvlCtx g_ovl_ctx;

extern void fn_ovl_3740(void *, void *, int, int, float, int, int);
extern void fn_ovl_0e20(int, void *, int);
extern float fn_ovl_0cf8(int);

void ovl_09413_09e0(void)
{
    OvlCtx *ctx = &g_ovl_ctx;

    fn_ovl_3740(g_ovl_mgr, ctx, 0, 0, 0.9f, 0, 0);
    fn_ovl_0e20(-1, &ctx->fD0, 3);
    ctx->fD4 -= 0.5f;
    ctx->fC4 = fn_ovl_0cf8(-1);
}
