/* 09170 effect initializer (696 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct { u8 pad00[0x40]; } OvlFade;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3f28[];
extern u8 g_ovl_dat_04f0[];
extern u8 g_ovl_dat_0508[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_5130;
extern void *g_ovl_ptr_5134;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3890(void *, void *, void *, int);
extern float fn_ovl_1438(int);
extern int fn_ovl_1988(int);
extern void fn_ovl_3968(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1048(int, void *, int);
extern int fn_ovl_0df8(int);
extern void fn_ovl_30f0(void *, void *, void *);
extern float fn_ovl_1498(int);
extern void fn_ovl_4498(void *, int, int, float, float);
extern void fn_ovl_2e78(int);
extern void *fn_ovl_3608(void *);
extern void fn_ovl_37d0(void *);
extern void fn_ovl_0978(void);

int ovl_09170_09d0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int n;
    u8 *dat;
    int i;
    int delay = 0;

    g_ovl_ptr_5134 = p + 0x50000;
    g_ovl_ptr_5130 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3890(mgr, g_ovl_dat_0040, g_ovl_ptr_5130, 0x50000);
    n = g_ovl_hdr.count;
    dat = (n == 1) ? g_ovl_dat_0508 : g_ovl_dat_04f0;
    for (i = 0; i < n; i++) {
        float s = fn_ovl_1438(i) * 0.14f;
        OvlCtx *ctx;
        u8 *q;
        float y;
        if (fn_ovl_1988(i) == 0) {
            ctx = &g_ovl_ctx[i];
            fn_ovl_3968(mgr, ctx, 0, delay, s, 20, g_ovl_dat_3f28);
            fn_ovl_1048(i, &ctx->fD0, 5);
        } else {
            ctx = &g_ovl_ctx[i];
            fn_ovl_3968(mgr, ctx, 1, delay, s, 20, g_ovl_dat_3f28);
            fn_ovl_1048(i, &ctx->fD0, 5);
        }
        ctx->w120 = fn_ovl_0df8(i);
        q = p + ((i << 6) + 0x150000);
        fn_ovl_30f0(q, g_ovl_res, dat);
        ctx->w110 = q;
        y = fn_ovl_1498(i);
        ctx->fD4 += 10.0f;
        if (ctx->fD4 > y) {
            ctx->fD4 = y - 0.5f;
        }
        delay += 15;
    }
    fn_ovl_4498(&g_ovl_fade[0], 8, 0, 1.0f, 0.5f);
    fn_ovl_4498(&g_ovl_fade[1], 16, (g_ovl_hdr.count - 1) * 15 + 29, 0.5f, 1.0f);
    fn_ovl_2e78(1);
    fn_ovl_37d0(fn_ovl_3608((void *)fn_ovl_0978));
    return 0;
}
