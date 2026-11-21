/* 09519 effect initializer (396 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x54]; int w54; } OvlObj;
typedef struct { u8 pad00[0x40]; } OvlFade;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x20];
    float fE8;
    u8 padEC[0x44];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3ec0[];
extern u8 g_ovl_dat_05b8[];
extern u8 g_ovl_dat_05d0[];
extern u8 g_ovl_dat_5098[];
extern void *g_ovl_ptr_5310;
extern void *g_ovl_ptr_5314;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlObj g_ovl_obj;
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3848(void *, void *, void *, int);
extern void fn_ovl_3920(void *, void *, int, int, float, int, void *);
extern float fn_ovl_0ed8(int);
extern void fn_ovl_4f28(void *, void *, void *, int);
extern void fn_ovl_4cf0(void *, int, int, float, float);
extern void fn_ovl_2e30(int);
extern void fn_ovl_29e8(int, void *, void *);
extern void *fn_ovl_35c0(void *);
extern void fn_ovl_3788(void *);
extern void fn_ovl_0bb0(void);

int ovl_09519_0a20(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlObj *obj;
    OvlFade *fade;

    g_ovl_ptr_5310 = p;
    g_ovl_ptr_5314 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3848(mgr, g_ovl_dat_0040, g_ovl_ptr_5310, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_3920(mgr, ctx, 0, 60, 0.35f, 130, g_ovl_dat_3ec0);
    ctx->fE8 = -70.0f;
    ctx->fC4 = fn_ovl_0ed8(-1);
    obj = &g_ovl_obj;
    fn_ovl_4f28(obj, g_ovl_res, g_ovl_dat_05b8, 1);
    obj->w54 = -1;
    fade = g_ovl_fade;
    fn_ovl_4cf0(&fade[0], 30, 0, 1.0f, 0.5f);
    fn_ovl_4cf0(&fade[1], 30, 220, 0.5f, 1.0f);
    fn_ovl_2e30(1);
    fn_ovl_29e8(-1, g_ovl_dat_5098, g_ovl_dat_05d0);
    fn_ovl_3788(fn_ovl_35c0((void *)fn_ovl_0bb0));
    return 0;
}
