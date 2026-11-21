/* Shared 09285-family effect initializer (732 B, 5 containers). */

typedef unsigned char u8;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct {
    u128 src;
    u128 dst;
    float t;
    int delay;
    int idx;
} OvlArc;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    float fD8;
    u8 padDC[0x34];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_4040[];
extern int g_ovl_delays[];
extern u8 g_ovl_dat_0498[];
extern u8 g_ovl_dat_04b0[];
extern u8 g_ovl_dat_04e8[];
extern OvlHdr g_ovl_hdr;
extern u8 g_ovl_dat_4e38[];
extern OvlArc g_ovl_arc;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_5130;
extern void *g_ovl_ptr_5134;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_39c8(void *, void *, void *, int);
extern int fn_ovl_0d78(void);
extern void fn_ovl_3aa0(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1180(int, void *, int);
extern float fn_ovl_1058(int);
extern void fn_ovl_3228(void *, void *, void *);
extern int fn_ovl_15f8(int);
extern void fn_ovl_17c8(float *);
extern void fn_ovl_2b68(int, void *, void *);
extern void *fn_ovl_3740(void *);
extern void fn_ovl_3908(void *);
extern void fn_ovl_0c88(void);
extern void fn_ovl_0c08(void);

int ovl_09285_0928(void)
{
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlArc *arc;
    OvlCtx *ctx;
    u128 *pos_p;
    /* DEBT(FAKE): pin q to s0 ($16) to match original callee-saved reg allocation. */
    register u8 *q __asm__("$16");
    float pos[4];
    int idx;
    /* DEBT(FAKE): pin delay to s4 ($20) to match original callee-saved reg allocation. */
    register int delay __asm__("$20");
    int i;
    int found = 0;

    g_ovl_ptr_5134 = p + 0x40000;
    res = g_ovl_res;
    g_ovl_ptr_5130 = p;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_39c8(mgr, g_ovl_dat_0040, g_ovl_ptr_5130, 0x40000);
    arc = &g_ovl_arc;
    idx = fn_ovl_0d78();
    delay = g_ovl_delays[idx];
    ctx = &g_ovl_ctx[0];
    fn_ovl_3aa0(mgr, ctx, 0, delay - 1, 0.12f, 0, 0);
    fn_ovl_1180(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_1058(-1);
    q = p + 0x140000;
    fn_ovl_3228(q, res, g_ovl_dat_04b0);
    ctx->w110 = q;
    for (i = 0; i < g_ovl_hdr.count; i++) {
        if (fn_ovl_15f8(i) == 4198) {
            fn_ovl_1180(i, pos, 0);
            found = 1;
        }
    }
    if (!found) {
        fn_ovl_17c8(pos);
    }
    ctx = &g_ovl_ctx[1];
    fn_ovl_3aa0(mgr, ctx, 1, delay + 19, 0.9f, 0, g_ovl_dat_4040);
    /* DEBT(CAST): 128-bit quadword pointer to vec4 at ctx->fD0. */
    pos_p = (u128 *)&ctx->fD0;
    fn_ovl_1180(0, pos_p, 3);
    ctx->fC4 = fn_ovl_1058(-1);
    ctx->fD0 = pos[0];
    ctx->fD4 -= 2.0f;
    ctx->fD8 = pos[2];
    q = p + 0x140040;
    fn_ovl_3228(q, g_ovl_res, g_ovl_dat_0498);
    ctx->w110 = q;
    /* DEBT(ORDER): keep pos_p materialized in s1 across calls instead of folding 208(s2). */
    __asm__ volatile("" : "+r"(pos_p));
    {
        /* DEBT(FAKE): pin quadword copy temporary to a3 ($7) to match lq/sq register. */
        register u128 _t __asm__("$7");
        _t = *(const volatile u128 *)pos_p;
        *(volatile u128 *)&arc->src = _t;
    }
    /* DEBT(ORDER): keep quadword store before arc->delay/idx/t stores. */
    __asm__ volatile("");
    arc->delay = delay;
    arc->idx = idx;
    arc->t = 0.0f;
    fn_ovl_2b68(-1, g_ovl_dat_4e38, g_ovl_dat_04e8);
    fn_ovl_3908(fn_ovl_3740((void *)fn_ovl_0c88));
    fn_ovl_3908(fn_ovl_3740((void *)fn_ovl_0c08));
    return 0;
}
