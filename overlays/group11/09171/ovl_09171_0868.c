/* 09171 effect initializer (572 B). */

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
extern u8 g_ovl_dat_3d48[];
extern u8 g_ovl_dat_0388[];
extern u8 g_ovl_dat_03a0[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_4f50;
extern void *g_ovl_ptr_4f54;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_36b0(void *, void *, void *, int);
extern float fn_ovl_1258(int);
extern void fn_ovl_3788(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0e68(int, void *, int);
extern int fn_ovl_0c18(int);
extern void fn_ovl_2f10(void *, void *, void *);
extern void fn_ovl_42b8(void *, int, int, float, float);
extern void fn_ovl_2c98(int);
extern void *fn_ovl_3428(void *);
extern void fn_ovl_35f0(void *);
extern void fn_ovl_0810(void);

int ovl_09171_0868(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int n;
    u8 *dat;
    int i;
    int delay = 0;

    g_ovl_ptr_4f54 = p + 0x50000;
    g_ovl_ptr_4f50 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_36b0(mgr, g_ovl_dat_0040, g_ovl_ptr_4f50, 0x50000);
    n = g_ovl_hdr.count;
    dat = (n == 1) ? g_ovl_dat_03a0 : g_ovl_dat_0388;
    for (i = 0; i < n; i++) {
        float s = fn_ovl_1258(i) * 0.14f;
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3788(mgr, ctx, 0, delay, s, 20, g_ovl_dat_3d48);
        delay += 15;
        fn_ovl_0e68(i, &ctx->fD0, 5);
        ctx->fD4 += 10.0f;
        ctx->w120 = fn_ovl_0c18(i);
        q = p + ((i << 6) + 0x150000);
        fn_ovl_2f10(q, g_ovl_res, dat);
        ctx->w110 = q;
    }
    fn_ovl_42b8(&g_ovl_fade[0], 8, 0, 1.0f, 0.5f);
    fn_ovl_42b8(&g_ovl_fade[1], 16, (g_ovl_hdr.count - 1) * 15 + 29, 0.5f, 1.0f);
    fn_ovl_2c98(1);
    fn_ovl_35f0(fn_ovl_3428((void *)fn_ovl_0810));
    return 0;
}
