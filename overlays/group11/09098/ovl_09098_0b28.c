/* 09098 effect initializer (368 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
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
extern u8 g_ovl_dat_0680[];
extern void *g_ovl_ptr_4720;
extern void *g_ovl_ptr_4724;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_38a0(void *, void *, void *, int);
extern void fn_ovl_3978(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1058(int, void *, int);
extern void fn_ovl_3100(void *, void *, void *);
extern void *fn_ovl_3618(void *);
extern void fn_ovl_37e0(void *);
extern void fn_ovl_0ad0(void);

int ovl_09098_0b28(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;

    g_ovl_ptr_4720 = p;
    g_ovl_ptr_4724 = p + 0x60000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_38a0(mgr, g_ovl_dat_0040, g_ovl_ptr_4720, 0x60000);
    ctx = g_ovl_ctx;
    fn_ovl_3978(mgr, ctx, 0, 0, 0.05f, 0, 0);
    fn_ovl_1058(-1, &ctx->fD0, 0);
    ctx->fD4 -= 12.0f;
    p += 0x160000;
    fn_ovl_3100(p, res, g_ovl_dat_0680);
    ctx->w110 = p;
    ctx++;
    fn_ovl_3978(mgr, ctx, 1, 20, 0.05f, 0, 0);
    fn_ovl_1058(0, &ctx->fD0, 0);
    ctx->fD4 -= 12.0f;
    fn_ovl_37e0(fn_ovl_3618((void *)fn_ovl_0ad0));
    return 0;
}
