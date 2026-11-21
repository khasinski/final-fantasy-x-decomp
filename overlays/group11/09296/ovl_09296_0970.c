/* 09296 effect initializer (312 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
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
extern u8 g_ovl_dat_0b30[];
extern u8 g_ovl_dat_0518[];
extern u8 g_ovl_dat_0530[];
extern u8 g_ovl_dat_4338[];
extern void *g_ovl_ptr_44d0;
extern void *g_ovl_ptr_44d4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3760(void *, void *, void *, int);
extern void fn_ovl_3838(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0f18(int, void *, int);
extern float fn_ovl_0df0(int);
extern void fn_ovl_2fc0(void *, void *, void *);
extern void fn_ovl_2900(int, void *, void *);
extern void *fn_ovl_34d8(void *);
extern void fn_ovl_36a0(void *);
extern void fn_ovl_0aa8(void);

int ovl_09296_0970(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;

    g_ovl_ptr_44d0 = p;
    g_ovl_ptr_44d4 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3760(mgr, g_ovl_dat_0040, g_ovl_ptr_44d0, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_3838(mgr, ctx, 0, 30, 0.25f, 0, g_ovl_dat_0b30);
    fn_ovl_0f18(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0df0(-1);
    ctx->fE8 = -5.0f;
    p += 0x140000;
    fn_ovl_2fc0(p, res, g_ovl_dat_0518);
    ctx->w110 = p;
    fn_ovl_2900(-1, g_ovl_dat_4338, g_ovl_dat_0530);
    fn_ovl_36a0(fn_ovl_34d8((void *)fn_ovl_0aa8));
    return 0;
}
