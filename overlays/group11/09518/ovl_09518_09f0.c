/* 09518 effect initializer (704 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x40]; } OvlFade;
typedef struct { u8 r, g, b, a; } OvlRgba;
typedef struct {
    u8 pad00[0x80];
    OvlRgba c0;
    OvlRgba c1;
    int delay;
    int cur;
    int total;
    int hold;
    u8 b98;
    u8 b99;
} OvlObj;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x10];
    float fE8;
    u8 padEC[0x24];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3fc0[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_dat_0558[];
extern void *g_ovl_tab_0570[];
extern u8 g_ovl_dat_4908[];
extern OvlObj g_ovl_obj;
extern OvlFade g_ovl_fade[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_4cf0;
extern void *g_ovl_ptr_4cf4;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3948(void *, void *, void *, int);
extern void fn_ovl_3a20(void *, void *, int, float, int, int, void *);
extern void fn_ovl_1100(int, void *, int);
extern float fn_ovl_0fd8(int);
extern void fn_ovl_31a8(void *, void *, void *);
extern int fn_ovl_0eb0(int);
extern void fn_ovl_4508(void *, int);
extern void fn_ovl_46c0(void *, int, int, float, float);
extern void fn_ovl_2f30(int);
extern int fn_ovl_1d70(int);
extern void fn_ovl_2ae8(int, void *, void *);
extern void *fn_ovl_36c0(void *);
extern void fn_ovl_3888(void *);
extern void fn_ovl_0cb0(void);

int ovl_09518_09f0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlFade *fade;
    /* DEBT(FAKE): pin q to s0 to match original callee-saved register allocation. */
    register u8 *q __asm__("s0");
    float scale;

    g_ovl_ptr_4cf0 = p;
    g_ovl_ptr_4cf4 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3948(mgr, g_ovl_dat_0040, g_ovl_ptr_4cf0, 0x40000);
    ctx = &g_ovl_ctx[0];
    fn_ovl_3a20(mgr, ctx, 0, 0.8f, 0, 0, 0);
    fn_ovl_1100(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0fd8(-1);
    ctx->fD4 -= 20.0f;
    ctx->fE8 = -150.0f;
    q = p + 0x140040;
    fn_ovl_31a8(q, g_ovl_res, g_ovl_dat_0558);
    ctx->w110 = q;
    if ((unsigned int)(fn_ovl_0eb0(0) - 8) < 10) {
        scale = 0.17999999f;
        g_ovl_obj.c0.a = 128;
        g_ovl_obj.c0.b = 255;
        g_ovl_obj.c0.g = 255;
        g_ovl_obj.c0.r = 255;
        g_ovl_obj.c1.r = 255;
        g_ovl_obj.c1.g = 255;
        g_ovl_obj.c1.b = 255;
        g_ovl_obj.c1.a = 0;
        g_ovl_obj.delay = 60;
        g_ovl_obj.b98 = 72;
        g_ovl_obj.b99 = 0;
        fn_ovl_4508(&g_ovl_obj, 40);
    } else {
        scale = 0.12f;
    }
    ctx = &g_ovl_ctx[1];
    fn_ovl_3a20(mgr, ctx, 1, scale, 60, 0, g_ovl_dat_3fc0);
    fn_ovl_1100(0, &ctx->fD0, 1);
    ctx->fC4 = fn_ovl_0fd8(0);
    q = p + 0x140000;
    fn_ovl_31a8(q, g_ovl_res, g_ovl_dat_0540);
    ctx->w110 = q;
    fade = g_ovl_fade;
    fn_ovl_46c0(&fade[0], 30, 0, 1.0f, 0.5f);
    fn_ovl_46c0(&fade[1], 30, 80, 0.5f, 1.0f);
    fn_ovl_2f30(1);
    {
        int idx = fn_ovl_1d70(-1);
        fn_ovl_2ae8(-1, g_ovl_dat_4908, g_ovl_tab_0570[idx]);
    }
    fn_ovl_3888(fn_ovl_36c0((void *)fn_ovl_0cb0));
    return 0;
}
