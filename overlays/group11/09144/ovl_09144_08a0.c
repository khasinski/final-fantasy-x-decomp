/* 09144 effect initializer (584 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x18]; u8 b18; } OvlTask;
typedef struct {
    u8 pad00[0x04];
    float f04;
    u8 pad08[0x0C];
    float f14;
    u8 pad18[0x28];
} OvlFade;
typedef struct {
    float r0, g0, b0;
    float r1, g1, b1;
    int t0, d0, t1, d1, id, d2;
    unsigned short flags;
} OvlColorFade;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0450[];
extern u8 g_ovl_dat_3de0[];
extern OvlFade g_ovl_fade[];
extern OvlColorFade g_ovl_cfade;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_4a50;
extern void *g_ovl_ptr_4a54;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3768(void *, void *, void *, int);
extern int fn_ovl_1860(int);
extern void fn_ovl_3840(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0f20(int, void *, int);
extern void fn_ovl_2fc8(void *, void *, void *);
extern void fn_ovl_45a8(void *);
extern void fn_ovl_4370(void *, int, int, float, float);
extern void fn_ovl_2d50(int);
extern OvlTask *fn_ovl_34e0(void *);
extern void fn_ovl_36a8(OvlTask *);
extern void fn_ovl_0ae8(void);

int ovl_09144_08a0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    OvlFade *fade;
    OvlTask *t;
    u8 *q;

    g_ovl_ptr_4a54 = p + 0x40000;
    g_ovl_ptr_4a50 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3768(mgr, g_ovl_dat_0040, g_ovl_ptr_4a50, 0x40000);
    if (fn_ovl_1860(0) == 0) {
        ctx = &g_ovl_ctx[0];
        fn_ovl_3840(mgr, ctx, 0, 0, 0.12f, 30, g_ovl_dat_3de0);
        fn_ovl_0f20(0, &ctx->fD0, 7);
        ctx->fD4 -= 0.5f;
    } else {
        ctx = &g_ovl_ctx[1];
        fn_ovl_3840(mgr, ctx, 1, 0, 0.12f, 30, g_ovl_dat_3de0);
        fn_ovl_0f20(0, &ctx->fD0, 5);
    }
    q = p + 0x140000;
    fn_ovl_2fc8(q, g_ovl_res, g_ovl_dat_0450);
    ctx->w110 = q;
    g_ovl_cfade.r0 = 0.5f;
    g_ovl_cfade.g0 = 1.3f;
    g_ovl_cfade.b0 = 0.5f;
    g_ovl_cfade.t0 = 32;
    g_ovl_cfade.d0 = 12;
    g_ovl_cfade.t1 = 16;
    g_ovl_cfade.d1 = 58;
    g_ovl_cfade.id = 0;
    fn_ovl_45a8(&g_ovl_cfade);
    fade = g_ovl_fade;
    fn_ovl_4370(&fade[0], 8, 0, 1.0f, 0.5f);
    fade[0].f14 = 0.7f;
    fn_ovl_4370(&fade[1], 16, 74, 0.5f, 1.0f);
    fade[1].f04 = 0.7f;
    fn_ovl_2d50(1);
    t = fn_ovl_34e0((void *)fn_ovl_0ae8);
    t->b18 = 2;
    fn_ovl_36a8(t);
    return 0;
}
