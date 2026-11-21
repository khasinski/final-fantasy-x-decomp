/* 09156 effect initializer (520 B). */

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
extern u8 g_ovl_dat_3df0[];
extern u8 g_ovl_dat_04a0[];
extern OvlHdr g_ovl_dat_04f0;
extern void *g_ovl_ptr_4ff0;
extern void *g_ovl_ptr_4ff4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3758(void *, void *, void *, int);
extern void fn_ovl_3830(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0f10(int, void *, int);
extern int fn_ovl_0cc0(int);
extern void fn_ovl_2fb8(void *, void *, void *);
extern void fn_ovl_4360(void *, int, int, float, float);
extern void fn_ovl_2d40(int);
extern void *fn_ovl_34d0(void *);
extern void fn_ovl_3698(void *);
extern void fn_ovl_08f0(void);

int ovl_09156_0948(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_4ff4 = p + 0x40000;
    g_ovl_ptr_4ff0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3758(mgr, g_ovl_dat_0040, g_ovl_ptr_4ff0, 0x40000);
    for (i = 0; i < g_ovl_dat_04f0.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3830(mgr, ctx, 0, delay, 0.25f, 18, g_ovl_dat_3df0);
        delay += 15;
        fn_ovl_0f10(i, &ctx->fD0, 5);
        ctx->w120 = fn_ovl_0cc0(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2fb8(q, g_ovl_res, g_ovl_dat_04a0);
        ctx->w110 = q;
    }
    fn_ovl_4360(&g_ovl_fade[0], 8, 0, 1.0f, 0.33f);
    fn_ovl_4360(&g_ovl_fade[1], 16, (g_ovl_dat_04f0.count - 1) * 15 + 32, 0.33f, 1.0f);
    fn_ovl_2d40(1);
    fn_ovl_3698(fn_ovl_34d0((void *)fn_ovl_08f0));
    /* DEBT(ORDER): keep delay live past loop to match s2/s3 prologue zero-init order. */
    __asm__("" : : "r"(delay));
    return 0;
}
