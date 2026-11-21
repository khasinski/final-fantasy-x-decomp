/* 09172 effect initializer (564 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct { u8 pad00[0x40]; } OvlFade;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
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
extern u8 g_ovl_dat_3db8[];
extern u8 g_ovl_dat_0400[];
extern u8 g_ovl_dat_0418[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_4fc0;
extern void *g_ovl_ptr_4fc4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3720(void *, void *, void *, int);
extern float fn_ovl_12c8(int);
extern void fn_ovl_37f8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0ed8(int, void *, int);
extern float fn_ovl_0db0(int);
extern int fn_ovl_0c88(int);
extern void fn_ovl_2f80(void *, void *, void *);
extern void fn_ovl_4328(void *, int, int, float, float);
extern void fn_ovl_2d08(int);
extern void *fn_ovl_3498(void *);
extern void fn_ovl_3660(void *);
extern void fn_ovl_0888(void);

int ovl_09172_08e0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int n;
    u8 *dat;
    int i;
    int delay = 0;

    g_ovl_ptr_4fc4 = p + 0x40000;
    g_ovl_ptr_4fc0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3720(mgr, g_ovl_dat_0040, g_ovl_ptr_4fc0, 0x40000);
    n = g_ovl_hdr.count;
    dat = (n == 1) ? g_ovl_dat_0418 : g_ovl_dat_0400;
    for (i = 0; i < n; i++) {
        float s = fn_ovl_12c8(i) * 0.12f;
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_37f8(mgr, ctx, 0, delay, s, 20, g_ovl_dat_3db8);
        delay += 15;
        fn_ovl_0ed8(i, &ctx->fD0, 5);
        ctx->fC4 = fn_ovl_0db0(i);
        ctx->w120 = fn_ovl_0c88(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2f80(q, g_ovl_res, dat);
        ctx->w110 = q;
    }
    fn_ovl_4328(&g_ovl_fade[0], 8, 0, 1.0f, 0.5f);
    fn_ovl_4328(&g_ovl_fade[1], 16, (g_ovl_hdr.count - 1) * 15 + 24, 0.5f, 1.0f);
    fn_ovl_2d08(1);
    fn_ovl_3660(fn_ovl_3498((void *)fn_ovl_0888));
    return 0;
}
