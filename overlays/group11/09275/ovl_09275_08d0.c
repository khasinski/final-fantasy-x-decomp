/* Overlay 09275 effect initializer (404 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[8];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3ce8[];
extern u8 g_ovl_dat_0428[];
extern void *g_ovl_ptr_43c0;
extern void *g_ovl_ptr_43c4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3670(void *, void *, void *, int);
extern int fn_ovl_1828(int);
extern void fn_ovl_3748(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0e28(int, void *, int);
extern float fn_ovl_0d00(int);
extern void fn_ovl_2ed0(void *, void *, void *);
extern void *fn_ovl_33e8(void *);
extern void fn_ovl_35b0(void *);
extern void fn_ovl_0878(void);

int ovl_09275_08d0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    u8 *p2;

    g_ovl_ptr_43c4 = p + 0x40000;
    g_ovl_ptr_43c0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3670(mgr, g_ovl_dat_0040, g_ovl_ptr_43c0, 0x40000);
    if (fn_ovl_1828(0) == 1) {
        ctx = &g_ovl_ctx;
        fn_ovl_3748(mgr, ctx, 0, 0, 20, g_ovl_dat_3ce8, 0.06f);
        fn_ovl_0e28(0, &ctx->fD0, 1);
        ctx->fD4 -= 2.0f;
    } else {
        ctx = &g_ovl_ctx;
        fn_ovl_3748(mgr, ctx, 0, 0, 20, g_ovl_dat_3ce8, 0.06f);
        fn_ovl_0e28(0, &ctx->fD0, 4);
    }
    ctx->fC0 = -0.2617994f;
    ctx->fC4 = fn_ovl_0d00(0);
    p2 = p + 0x140000;
    fn_ovl_2ed0(p2, g_ovl_res, g_ovl_dat_0428);
    ctx->w110 = p2;
    fn_ovl_35b0(fn_ovl_33e8((void *)fn_ovl_0878));
    return 0;
}
