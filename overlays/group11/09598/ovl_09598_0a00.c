/* 09598 effect initializer (552 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x08];
    float fE0;
    float fE4;
    float fE8;
    u8 padEC[0x18];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3ec0[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_dat_0558[];
extern void *g_ovl_ptr_46c0;
extern void *g_ovl_ptr_46c4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3848(void *, void *, void *, int);
extern float fn_ovl_0ed8(int);
extern void fn_ovl_3920(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1000(int, void *, int);
extern void fn_ovl_30a8(void *, void *, void *);
extern void fn_ovl_2e30(int);
extern void *fn_ovl_35c0(void *);
extern void fn_ovl_3788(void *);
extern void fn_ovl_09a8(void);
extern void fn_ovl_0c28(void);

int ovl_09598_0a00(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    /* DEBT(FAKE): pin q to s1 to match original s1/s2 allocation with g_ovl_res. */
    register u8 *q __asm__("s1");
    float ang;

    g_ovl_ptr_46c4 = p + 0x40000;
    g_ovl_ptr_46c0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3848(mgr, g_ovl_dat_0040, g_ovl_ptr_46c0, 0x40000);
    ang = fn_ovl_0ed8(-1) + 1.5707964f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    ctx = g_ovl_ctx;
    fn_ovl_3920(mgr, ctx, 0, 70, 1.2f, 130, g_ovl_dat_3ec0);
    fn_ovl_1000(-1, &ctx->fD0, 0);
    ctx->fC4 = ang;
    ctx->fE0 = -400.0f;
    ctx->fD4 += 150.0f;
    ctx->fE8 = -200.0f;
    q = p + 0x140000;
    fn_ovl_30a8(q, g_ovl_res, g_ovl_dat_0540);
    ctx->w110 = q;
    ctx++;
    fn_ovl_3920(mgr, ctx, 1, 0, 2.0f, 0, 0);
    ctx->fC4 = fn_ovl_0ed8(-1);
    ctx->w104 = (void *)fn_ovl_0c28;
    q = p + 0x140040;
    fn_ovl_30a8(q, g_ovl_res, g_ovl_dat_0558);
    ctx->w110 = q;
    fn_ovl_2e30(1);
    fn_ovl_3788(fn_ovl_35c0((void *)fn_ovl_09a8));
    return 0;
}
