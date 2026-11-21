/* 09164 effect initializer (540 B). */

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
extern u8 g_ovl_dat_3ef8[];
extern u8 g_ovl_dat_0590[];
extern OvlHdr g_ovl_dat_05e0;
extern void *g_ovl_ptr_5100;
extern void *g_ovl_ptr_5104;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3860(void *, void *, void *, int);
extern void fn_ovl_3938(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1018(int, void *, int);
extern int fn_ovl_0dc8(int);
extern void fn_ovl_30c0(void *, void *, void *);
extern void fn_ovl_4468(void *, int, int, float, float);
extern void fn_ovl_2e48(int);
extern void *fn_ovl_35d8(void *);
extern void fn_ovl_37a0(void *);
extern void fn_ovl_09e0(void);

int ovl_09164_0a38(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_5104 = p + 0x40000;
    g_ovl_ptr_5100 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3860(mgr, g_ovl_dat_0040, g_ovl_ptr_5100, 0x40000);
    for (i = 0; i < g_ovl_dat_05e0.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3938(mgr, ctx, 0, delay, 0.2f, 20, g_ovl_dat_3ef8);
        delay += 15;
        fn_ovl_1018(i, &ctx->fD0, 7);
        ctx->fD4 -= 0.5f;
        ctx->w120 = fn_ovl_0dc8(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_30c0(q, g_ovl_res, g_ovl_dat_0590);
        ctx->w110 = q;
    }
    fn_ovl_4468(&g_ovl_fade[0], 8, 0, 1.0f, 0.5f);
    fn_ovl_4468(&g_ovl_fade[1], 16, (g_ovl_dat_05e0.count - 1) * 15 + 24, 0.5f, 1.0f);
    fn_ovl_2e48(1);
    fn_ovl_37a0(fn_ovl_35d8((void *)fn_ovl_09e0));
    /* DEBT(ORDER): keep delay live past loop to match s2/s3 prologue zero-init order. */
    __asm__("" : : "r"(delay));
    return 0;
}
