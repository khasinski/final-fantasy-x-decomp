/* 09358 effect initializer (612 B). */

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
    u8 padEC[0x18];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_40a0[];
extern u8 g_ovl_dat_0658[];
extern u8 g_ovl_dat_06d0[];
extern u8 g_ovl_dat_45f8[];
extern void *g_ovl_ptr_5110;
extern void *g_ovl_ptr_5114;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlCtx g_ovl_ctx_b[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3a28(void *, void *, void *, int);
extern float fn_ovl_10b8(int);
extern void fn_ovl_3b00(void *, void *, int, int, float, int, void *);
extern void fn_ovl_11e0(int, void *, int);
extern void fn_ovl_3288(void *, void *, void *);
extern void fn_ovl_2bc8(int, void *, void *);
extern void *fn_ovl_37a0(void *);
extern void fn_ovl_3968(void *);
extern void fn_ovl_0d78(void);
extern void fn_ovl_0df8(void);

int ovl_09358_0b10(void)
{
    OvlMgr *mgr;
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlCtx *ctx;
    float ang;
    float ang2;
    int i;

    g_ovl_ptr_5110 = p;
    g_ovl_ptr_5114 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3a28(mgr, g_ovl_dat_0040, g_ovl_ptr_5110, 0x40000);
    ang = fn_ovl_10b8(-1);
    ctx = &g_ovl_ctx_b[1];
    fn_ovl_3b00(mgr, ctx, 1, 0, 0.17f, 0, 0);
    fn_ovl_11e0(-1, &ctx->fD0, 1);
    ctx->fC4 = ang;
    ctx->fE8 = -70.0f;
    ctx->fD4 += 7.0f;
    p += 0x140000;
    fn_ovl_3288(p, res, g_ovl_dat_0658);
    ctx->w110 = p;
    ctx--;
    fn_ovl_3b00(mgr, ctx, 0, 66, 0.15f, 0, g_ovl_dat_40a0);
    fn_ovl_11e0(0, &ctx->fD0, 3);
    ang2 = ang + 3.1415927f;
    if (ang2 > 3.1415927f) {
        ang2 -= 6.2831855f;
    } else if (ang2 < -3.1415927f) {
        ang2 += 6.2831855f;
    }
    ctx->fC4 = ang2;
    ctx->fD4 -= 13.0f;
    ctx = g_ovl_ctx;
    for (i = 0; i < 6; i++, ctx++) {
        fn_ovl_3b00(mgr, ctx, 2, 0, 0.1f, 0, 0);
        ctx->w120 = i;
        ctx->fC4 = ang;
        ctx->w104 = (void *)fn_ovl_0df8;
    }
    fn_ovl_2bc8(-1, g_ovl_dat_45f8, g_ovl_dat_06d0);
    fn_ovl_3968(fn_ovl_37a0((void *)fn_ovl_0d78));
    return 0;
}
