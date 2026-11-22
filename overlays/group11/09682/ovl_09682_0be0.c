/* 09682 spawn helper & wrapper (144 B, 2 funcs). */

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
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x50];
} OvlCtx;

typedef struct {
    u8 pad00[0x2C];
    int idx;
} OvlArg;

extern OvlCtx *g_ovl_work;
extern SpawnTbl g_ovl_tbl[];
extern u8 g_ovl_mgr[];

extern void fn_ovl_3950(void *, void *, int, int, float, int, int);

OvlCtx *ovl_09682_0be0(int idx)
{
    SpawnTbl *e = &g_ovl_tbl[idx];
    OvlCtx *ctx = &g_ovl_work[idx];
    /* DEBT(FAKE): pin dst to v1 to match register allocation */
    register Vec4 *dst __asm__("$3");

    fn_ovl_3950(g_ovl_mgr, ctx, e->w18, 0, e->f10, 0, 0);
    dst = &ctx->vD0;
    MMI_COPY_LQ_A3(dst, &e->pos);
    MMI_COPY_SQ_A3(dst);
    ctx->fC4 = e->f14;
    return ctx;
}

void ovl_09682_0c68(OvlArg *arg)
{
    ovl_09682_0be0(arg->idx);
}
