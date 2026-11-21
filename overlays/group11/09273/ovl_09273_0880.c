/* 09273 effect initializer (412 B). */

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
extern u8 g_ovl_dat_3cc0[];
extern u8 g_ovl_dat_03d8[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_4bc0;
extern void *g_ovl_ptr_4bc4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3628(void *, void *, void *, int);
extern void fn_ovl_3700(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0de0(int, void *, int);
extern int fn_ovl_0b90(int);
extern void fn_ovl_2e88(void *, void *, void *);
extern void *fn_ovl_33a0(void *);
extern void fn_ovl_3568(void *);
extern void fn_ovl_0828(void);

int ovl_09273_0880(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_4bc4 = p + 0x40000;
    g_ovl_ptr_4bc0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3628(mgr, g_ovl_dat_0040, g_ovl_ptr_4bc0, 0x40000);
    for (i = 0; i < g_ovl_hdr.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_3700(mgr, ctx, 0, delay, 0.17f, 20, g_ovl_dat_3cc0);
        delay += 15;
        fn_ovl_0de0(i, &ctx->fD0, 5);
        ctx->w120 = fn_ovl_0b90(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2e88(q, g_ovl_res, g_ovl_dat_03d8);
        ctx->w110 = q;
    }
    fn_ovl_3568(fn_ovl_33a0((void *)fn_ovl_0828));
    return 0;
}
