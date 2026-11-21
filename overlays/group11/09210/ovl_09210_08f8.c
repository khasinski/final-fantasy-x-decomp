/* 09210 effect initializer (332 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_04a0[];
extern u8 g_ovl_dat_04b8[];
extern u8 g_ovl_dat_42c8[];
extern int g_ovl_timer;
extern void *g_ovl_ptr_4460;
extern void *g_ovl_ptr_4464;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_36f0(void *, void *, void *, int);
extern void fn_ovl_37c8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0ea8(int, void *, int);
extern float fn_ovl_0d80(int);
extern void fn_ovl_2f50(void *, void *, void *);
extern void fn_ovl_2890(int, void *, void *);
extern void *fn_ovl_3468(void *);
extern void fn_ovl_3630(void *);
extern void fn_ovl_0a48(void);

int ovl_09210_08f8(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;

    g_ovl_ptr_4460 = p;
    g_ovl_ptr_4464 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_36f0(mgr, g_ovl_dat_0040, g_ovl_ptr_4460, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_37c8(mgr, ctx, 0, 5, 0.1f, 0, 0);
    fn_ovl_0ea8(-1, &ctx->fD0, 0);
    ctx->fD4 -= 0.5f;
    ctx->fC4 = fn_ovl_0d80(-1);
    p += 0x140000;
    fn_ovl_2f50(p, res, g_ovl_dat_04a0);
    ctx->w110 = p;
    g_ovl_timer = 30;
    fn_ovl_2890(-1, g_ovl_dat_42c8, g_ovl_dat_04b8);
    fn_ovl_3630(fn_ovl_3468((void *)fn_ovl_0a48));
    return 0;
}
