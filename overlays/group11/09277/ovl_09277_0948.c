/* Overlay 09277 effect initializer (420 B). */

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
extern u8 g_ovl_dat_3d90[];
extern u8 g_ovl_dat_04a0[];
extern OvlHdr g_ovl_dat_04f0;
extern void *g_ovl_ptr_4c90;
extern void *g_ovl_ptr_4c94;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_36f8(void *, void *, void *, int);
extern void fn_ovl_37d0(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0eb0(int, void *, int);
extern int fn_ovl_0c60(int);
extern void fn_ovl_2f58(void *, void *, void *);
extern void *fn_ovl_3470(void *);
extern void fn_ovl_3638(void *);
extern void fn_ovl_08f0(void);

int ovl_09277_0948(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_4c94 = p + 0x40000;
    g_ovl_ptr_4c90 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_36f8(mgr, g_ovl_dat_0040, g_ovl_ptr_4c90, 0x40000);
    for (i = 0; i < g_ovl_dat_04f0.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_37d0(mgr, ctx, 0, delay, 20, g_ovl_dat_3d90, 0.15f);
        delay += 15;
        fn_ovl_0eb0(i, &ctx->fD0, 2);
        ctx->fD4 += 3.0f;
        ctx->w120 = fn_ovl_0c60(i);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2f58(q, g_ovl_res, g_ovl_dat_04a0);
        ctx->w110 = q;
    }
    fn_ovl_3638(fn_ovl_3470((void *)fn_ovl_08f0));
    return 0;
}
