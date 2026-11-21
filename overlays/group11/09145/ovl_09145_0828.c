/* 09145 effect initializer (476 B). */

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
    u8 padD4[0x3C];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_03d8[];
extern u8 g_ovl_dat_3cf0[];
extern OvlFade g_ovl_fade[];
extern OvlColorFade g_ovl_cfade;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx;
extern void *g_ovl_ptr_4830;
extern void *g_ovl_ptr_4834;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3678(void *, void *, void *, int);
extern void fn_ovl_3750(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0e30(int, void *, int);
extern void fn_ovl_2ed8(void *, void *, void *);
extern void fn_ovl_44b8(void *);
extern void fn_ovl_4280(void *, int, int, float, float);
extern void fn_ovl_2c60(int);
extern OvlTask *fn_ovl_33f0(void *);
extern void fn_ovl_35b8(OvlTask *);
extern void fn_ovl_0a08(void);

int ovl_09145_0828(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlFade *fade;
    OvlTask *t;

    g_ovl_ptr_4830 = p;
    g_ovl_ptr_4834 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3678(mgr, g_ovl_dat_0040, g_ovl_ptr_4830, 0x40000);
    ctx = &g_ovl_ctx;
    fn_ovl_3750(mgr, ctx, 0, 0, 0.12f, 30, g_ovl_dat_3cf0);
    fn_ovl_0e30(0, &ctx->fD0, 5);
    p += 0x140000;
    fn_ovl_2ed8(p, res, g_ovl_dat_03d8);
    ctx->w110 = p;
    g_ovl_cfade.r0 = 0.5f;
    g_ovl_cfade.g0 = 1.3f;
    g_ovl_cfade.b0 = 0.5f;
    g_ovl_cfade.t0 = 32;
    g_ovl_cfade.d0 = 12;
    g_ovl_cfade.t1 = 16;
    g_ovl_cfade.d1 = 58;
    g_ovl_cfade.id = 0;
    fn_ovl_44b8(&g_ovl_cfade);
    fade = g_ovl_fade;
    fn_ovl_4280(&fade[0], 8, 0, 1.0f, 0.5f);
    fade[0].f14 = 0.7f;
    fn_ovl_4280(&fade[1], 16, 74, 0.5f, 1.0f);
    fade[1].f04 = 0.7f;
    fn_ovl_2c60(1);
    t = fn_ovl_33f0((void *)fn_ovl_0a08);
    t->b18 = 2;
    fn_ovl_35b8(t);
    return 0;
}
