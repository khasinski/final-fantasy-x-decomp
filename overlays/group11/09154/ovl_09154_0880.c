/* 09154 effect initializer (520 B). */

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
extern u8 g_ovl_dat_3d28[];
extern u8 g_ovl_dat_03d8[];
extern OvlHdr g_ovl_dat_0428;
extern void *g_ovl_ptr_4f30;
extern void *g_ovl_ptr_4f34;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3690(void *, void *, void *, int);
extern void fn_ovl_3768(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0e48(int, void *, int);
extern int fn_ovl_0bf8(int);
extern void fn_ovl_2ef0(void *, void *, void *);
extern void fn_ovl_4298(void *, int, int, float, float);
extern void fn_ovl_2c78(int);
extern void *fn_ovl_3408(void *);
extern void fn_ovl_35d0(void *);
extern void fn_ovl_0828(void);

int ovl_09154_0880(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 8;

    g_ovl_ptr_4f34 = p + 0x40000;
    g_ovl_ptr_4f30 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3690(mgr, g_ovl_dat_0040, g_ovl_ptr_4f30, 0x40000);
    for (i = 0; i < g_ovl_dat_0428.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3768(mgr, ctx, 0, delay, 0.17f, 18, g_ovl_dat_3d28);
        delay += 15;
        fn_ovl_0e48(i, &ctx->fD0, 5);
        ctx->w120 = fn_ovl_0bf8(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2ef0(q, g_ovl_res, g_ovl_dat_03d8);
        ctx->w110 = q;
    }
    fn_ovl_4298(&g_ovl_fade[0], 8, 0, 1.0f, 0.5f);
    fn_ovl_4298(&g_ovl_fade[1], 16, (g_ovl_dat_0428.count - 1) * 15 + 32, 0.5f, 1.0f);
    fn_ovl_2c78(1);
    fn_ovl_35d0(fn_ovl_3408((void *)fn_ovl_0828));
    return 0;
}
