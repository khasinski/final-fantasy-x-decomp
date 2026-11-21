/* 09265 effect initializer (412 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
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
extern u8 g_ovl_dat_3e00[];
extern u8 g_ovl_dat_0518[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_4d00;
extern void *g_ovl_ptr_4d04;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3768(void *, void *, void *, int);
extern void fn_ovl_3840(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0f20(int, void *, int);
extern int fn_ovl_0cd0(int);
extern void fn_ovl_2fc8(void *, void *, void *);
extern void *fn_ovl_34e0(void *);
extern void fn_ovl_36a8(void *);
extern void fn_ovl_0968(void);

int ovl_09265_09c0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_4d04 = p + 0x40000;
    g_ovl_ptr_4d00 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3768(mgr, g_ovl_dat_0040, g_ovl_ptr_4d00, 0x40000);
    for (i = 0; i < g_ovl_hdr.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3840(mgr, ctx, 0, delay, 0.2f, 5, g_ovl_dat_3e00);
        delay += 15;
        fn_ovl_0f20(i, &ctx->fD0, 5);
        ctx->w120 = fn_ovl_0cd0(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2fc8(q, g_ovl_res, g_ovl_dat_0518);
        ctx->w110 = q;
    }
    fn_ovl_36a8(fn_ovl_34e0((void *)fn_ovl_0968));
    return 0;
}
