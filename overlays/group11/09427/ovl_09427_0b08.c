/* 09427 spawn helper (104 B). */

#include "common.h"

typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    float fD8;
    float fDC;
} OvlCtx;

extern u8 g_ovl_mgr[];
extern OvlCtx g_ovl_ctx;

extern void fn_ovl_3850(void *, void *, int, int, float, int, int);

void ovl_09427_0b08(void)
{
    OvlCtx *ctx = &g_ovl_ctx;

    fn_ovl_3850(g_ovl_mgr, ctx, 0, 0, 1.0f, 0, 0);
    ctx->fDC = 1.0f;
    ctx->fD4 = 0.0f;
    ctx->fD8 = 0.0f;
    ctx->fD0 = 0.0f;
}
