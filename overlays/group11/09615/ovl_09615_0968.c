/* Overlay 09615 effect initializer (444 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    float fD0;
    float fD4;
    u8 padD8[0x10];
    float fE8;
    u8 padEC[0x24];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3e20[];
extern u8 g_ovl_dat_0518[];
extern OvlHdr g_ovl_dat_0568;
extern void *g_ovl_ptr_4d20;
extern void *g_ovl_ptr_4d24;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3788(void *, void *, void *, int);
extern void fn_ovl_3860(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0f40(int, void *, int);
extern float fn_ovl_0e18(int);
extern int fn_ovl_0cf0(int);
extern void fn_ovl_2fe8(void *, void *, void *);
extern void *fn_ovl_3500(void *);
extern void fn_ovl_36c8(void *);
extern void fn_ovl_0b28(void);

int ovl_09615_0968(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_4d24 = p + 0x40000;
    g_ovl_ptr_4d20 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3788(mgr, g_ovl_dat_0040, g_ovl_ptr_4d20, 0x40000);
    for (i = 0; i < g_ovl_dat_0568.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3860(mgr, ctx, 0, delay, 20, g_ovl_dat_3e20, 0.22f);
        delay += 15;
        fn_ovl_0f40(i, &ctx->fD0, 0);
        ctx->fC4 = fn_ovl_0e18(i);
        ctx->fE8 = -25.0f;
        ctx->fD4 -= 35.0f;
        ctx->w120 = fn_ovl_0cf0(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2fe8(q, g_ovl_res, g_ovl_dat_0518);
        ctx->w110 = q;
    }
    fn_ovl_36c8(fn_ovl_3500((void *)fn_ovl_0b28));
    return 0;
}
