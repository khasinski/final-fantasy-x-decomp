/* 09733 spawn, fade, and wrappers (292 B, 4 funcs). */

#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 pos;
    float f10;
    float f14;
    int w18;
    int w1C;
} SpawnTbl;

typedef struct {
    u8 pad00[0x70];
    s16 h70;
    s16 h72;
    s16 h74;
    s16 h76;
    u8 pad78[0x4C];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x24];
    void *fn104;
    u8 pad108[0x18];
    int w120;
    u16 h124;
    u8 pad126[0x0A];
} OvlCtx;

extern OvlCtx *g_ovl_work;
extern SpawnTbl g_ovl_tbl[];
extern u8 g_ovl_mgr[];

extern void fn_ovl_3b88(void *, void *, int, int, float, int, int);

OvlCtx *ovl_09733_0d80(int idx)
{
    SpawnTbl *e = &g_ovl_tbl[idx];
    OvlCtx *ctx = &g_ovl_work[idx];
    /* DEBT(FAKE): pin dst to v1 to match register allocation */
    register Vec4 *dst __asm__("$3");

    fn_ovl_3b88(g_ovl_mgr, ctx, e->w18, 0, e->f10, 0, 0);
    dst = &ctx->vD0;
    MMI_COPY_LQ_A3(dst, &e->pos);
    MMI_COPY_SQ_A3(dst);
    ctx->fC4 = e->f14;
    return ctx;
}

void ovl_09733_0e08(OvlCtx *ctx)
{
    int t = --ctx->w120;

    if (t < 64) {
        if (t > 0) {
            int d = 64;
            int v = (t << 12) / d;
            ctx->h76 = v;
            ctx->h74 = v;
            ctx->h72 = v;
            ctx->h70 = v;
            return;
        }
        ctx->h124 |= 0x4000;
    }
}

void ovl_09733_0e60(int idx, int delay)
{
    OvlCtx *ctx = ovl_09733_0d80(idx);

    ctx->w120 = delay + 164;
    ctx->fn104 = (void *)ovl_09733_0e08;
}

void ovl_09733_0e98(void)
{
    ovl_09733_0e60(0, 0);
}
