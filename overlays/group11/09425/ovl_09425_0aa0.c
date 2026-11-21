/* 09425 effect initializer (580 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x20]; } OvlSnd;
typedef struct {
    int w0;
    int w4;
    u8 pad08[0x0C];
    u8 b14;
} OvlCfg;
typedef struct {
    float f00;
    u8 pad04[0x0C];
    float f10;
    u8 pad14[0x2C];
} OvlFade;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x58];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0658[];
extern u8 g_ovl_dat_0668[];
extern OvlCfg g_ovl_cfg;
extern u8 g_ovl_dat_0d88[];
extern int g_ovl_w4820;
extern u8 g_ovl_snd0[];
extern u8 g_ovl_snd1[];
extern OvlFade g_ovl_fade[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_4b90;
extern void *g_ovl_ptr_4b94;

extern void fn_ovl_0e40(int);
extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_39d8(void *, void *, void *, int);
extern void fn_ovl_3ab0(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1190(int, void *, int);
extern float fn_ovl_1068(int);
extern void fn_ovl_45e0(void *, int, int, float, float);
extern void fn_ovl_2fc0(int);
extern void fn_ovl_3158(void *, int, int, int);
extern void fn_ovl_2b78(int, void *, void *);
extern void *fn_ovl_3750(void *);
extern void fn_ovl_3918(void *);
extern void fn_ovl_0ce8(void);

int ovl_09425_0aa0(void)
{
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlFade *fade;

    g_ovl_ptr_4b94 = p + 0x40000;
    g_ovl_cfg.w0 = 20;
    g_ovl_cfg.b14 = 21;
    g_ovl_ptr_4b90 = p;
    g_ovl_cfg.w4 = 1;
    fn_ovl_0e40(g_ovl_w4820);
    res = g_ovl_res;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_39d8(mgr, g_ovl_dat_0040, g_ovl_ptr_4b90, 0x40000);
    ctx = &g_ovl_ctx[1];
    fn_ovl_3ab0(mgr, ctx, 1, 120, 0.35f, 110, g_ovl_dat_0d88);
    fn_ovl_1190(-1, &ctx->fD0, 3);
    ctx->fC4 = fn_ovl_1068(-1);
    ctx->fD4 -= 10.0f;
    ctx--;
    fn_ovl_3ab0(mgr, ctx, 0, 0, 0.15f, 0, 0);
    fn_ovl_1190(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_1068(-1);
    ctx->fD4 -= 1.0f;
    fade = g_ovl_fade;
    fn_ovl_45e0(fade, 90, 0, 1.0f, 0.5f);
    fade->f10 = 0.75f;
    fade++;
    fn_ovl_45e0(fade, 32, 280, 0.5f, 1.0f);
    fade->f00 = 0.75f;
    fn_ovl_2fc0(1);
    fn_ovl_3158(res, 0, 64, 256);
    fn_ovl_2b78(-1, g_ovl_snd0, g_ovl_dat_0658);
    fn_ovl_2b78(0, g_ovl_snd1, g_ovl_dat_0668);
    fn_ovl_3918(fn_ovl_3750((void *)fn_ovl_0ce8));
    return 0;
}
