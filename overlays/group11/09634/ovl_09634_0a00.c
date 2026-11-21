typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x08];
    float fE0;
    u8 padE4[0x20];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3eb8[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_dat_0558[];
extern void *g_ovl_ptr_46c0;
extern void *g_ovl_ptr_46c4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3840(void *, void *, void *, int);
extern float fn_ovl_0ed0(int);
extern void fn_ovl_3918(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0ff8(int, void *, int);
extern void fn_ovl_30a0(void *, void *, void *);
extern void fn_ovl_2e28(int);
extern void *fn_ovl_35b8(void *);
extern void fn_ovl_3780(void *);
extern void fn_ovl_09a8(void);
extern void fn_ovl_0c20(void);

int ovl_09634_0a00(void) {
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    /* DEBT(FAKE): pin ctx to s1 so res uses s2 and q/q2 use s0 */
    register OvlCtx *ctx __asm__("$17");
    u8 *q;
    u8 *q2;
    float ang;

    g_ovl_ptr_46c4 = p + 0x40000;
    g_ovl_ptr_46c0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3840(mgr, g_ovl_dat_0040, g_ovl_ptr_46c0, 0x40000);
    ang = fn_ovl_0ed0(-1) + 1.5707964f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    ctx = g_ovl_ctx;
    fn_ovl_3918(mgr, ctx, 0, 70, 0.2f, 130, g_ovl_dat_3eb8);
    fn_ovl_0ff8(-1, &ctx->fD0, 0);
    ctx->fC4 = ang;
    ctx->fE0 = 120.0f;
    ctx->fD4 -= 30.0f;
    q = p + 0x140000;
    fn_ovl_30a0(q, g_ovl_res, g_ovl_dat_0540);
    ctx->w110 = q;
    ctx++;
    fn_ovl_3918(mgr, ctx, 1, 0, 0.8f, 0, 0);
    ctx->fC4 = fn_ovl_0ed0(-1);
    ctx->w104 = (void *)fn_ovl_0c20;
    q2 = p + 0x140040;
    fn_ovl_30a0(q2, g_ovl_res, g_ovl_dat_0558);
    ctx->w110 = q2;
    fn_ovl_2e28(1);
    fn_ovl_3780(fn_ovl_35b8((void *)fn_ovl_09a8));
    return 0;
}
