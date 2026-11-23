/* 09290 effect init (616 B). */

#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x30];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

typedef struct {
    float p0[4];
    float p1[4];
    float f20;
    int w24;
    int w28;
} OvlArc;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_05c0[];
extern u8 g_ovl_dat_05d8[];
extern u8 g_ovl_dat_0600[];
extern u8 g_ovl_dat_42e8[];
extern u8 g_ovl_50e8[];
extern OvlArc g_ovl_5110;
extern int g_ovl_5f9c;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_5fe0[];
extern void *g_ovl_ptr_64a0;
extern void *g_ovl_ptr_64a4;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0cb8(void);
extern void fn_ovl_0d48(void);
extern float fn_ovl_1300(int);
extern void fn_ovl_1428(int, void *, int);
extern void fn_ovl_2e10(int, void *, void *);
extern void fn_ovl_34d0(void *, void *, void *);
extern void *fn_ovl_39e8(void *);
extern void fn_ovl_3bb0(void *);
extern void fn_ovl_3c70(void *, void *, void *, int);
extern int fn_ovl_3d48(void *, void *, float, int, int, int, void *);
extern void fn_ovl_4b80(void *, void *, void *);

static inline void copy_vec(float *dst, float *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09290_0a50(void)
{
    float rot[4];
    float off[4];
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlArc *arc;
    register float *arc_p1 __asm__("$22");
    u8 *sub;

    g_ovl_ptr_64a0 = p;
    g_ovl_ptr_64a4 = p + 0x40000;
    res = g_ovl_res;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3c70(mgr, g_ovl_dat_0040, g_ovl_ptr_64a0, 0x40000);

    ctx = g_ovl_5fe0;
    fn_ovl_3d48(mgr, ctx, 0.28f, 0, 12, 0, 0);
    fn_ovl_1428(-1, ctx->pos, 0);
    ctx->fC4 = fn_ovl_1300(-1);
    sub = p + 0x140000;
    fn_ovl_34d0(sub, res, g_ovl_dat_05c0);
    ctx->w110 = sub;

    rot[0] = 0.0f;
    rot[1] = ctx->fC4;
    rot[2] = 0.0f;
    off[0] = 0.0f;
    off[1] = 0.0f;
    off[2] = -40.0f;
    fn_ovl_4b80(rot, ctx->pos, off);

    ctx->pos[1] -= 45.0f;
    arc = &g_ovl_5110;
    arc_p1 = arc->p1;
    MMI_COPY_LQ_A3(arc_p1, ctx->pos);
    MMI_COPY_SQ_A3(arc_p1);
    ctx++;
    fn_ovl_1428(0, arc->p0, 2);
    {
        register float *pos2 __asm__("$19") = ctx->pos;
        arc->p0[1] += 4.0f;
        arc->f20 = 0.0f;
        arc->w28 = 16;
        arc->w24 = 19;

        fn_ovl_3d48(mgr, ctx, 0.19f, 1, 16, 20, g_ovl_dat_42e8);
        fn_ovl_1428(0, pos2, 0);
        MMI_COPY_LQ_A3(pos2, arc_p1);
        MMI_COPY_SQ_A3(pos2);
    }
    p += 0x140040;
    fn_ovl_34d0(p, res, g_ovl_dat_05d8);
    ctx->w110 = p;

    fn_ovl_2e10(-1, g_ovl_50e8, g_ovl_dat_0600);
    fn_ovl_3bb0(fn_ovl_39e8((void *)fn_ovl_0d48));
    fn_ovl_3bb0(fn_ovl_39e8((void *)fn_ovl_0cb8));
    g_ovl_5f9c = 0;
    return 0;
}
