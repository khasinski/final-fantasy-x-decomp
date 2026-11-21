/* 09221 effect initializer (652 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x10];
    float fE8;
    u8 padEC[0x24];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_04f0[];
extern u8 g_ovl_dat_0518[];
extern OvlHdr g_ovl_hdr;
extern u8 g_ovl_dat_3f08[];
extern u8 g_ovl_dat_4d08[];
extern OvlCtx g_ovl_ctx[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx_b;
extern void *g_ovl_ptr_6400;
extern void *g_ovl_ptr_6404;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3890(void *, void *, void *, int);
extern void fn_ovl_3968(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1048(int, void *, int);
extern float fn_ovl_0f20(int);
extern void fn_ovl_30f0(void *, void *, void *);
extern void fn_ovl_4698(float *, void *, float *);
extern void fn_ovl_2a30(int, void *, void *);
extern void *fn_ovl_3608(void *);
extern void fn_ovl_37d0(void *);
extern void fn_ovl_0c08(void);

int ovl_09221_0978(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    float rot[4];
    float pos[4];
    int i;

    g_ovl_ptr_6400 = p;
    g_ovl_ptr_6404 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3890(mgr, g_ovl_dat_0040, g_ovl_ptr_6400, 0x40000);
    ctx = &g_ovl_ctx_b;
    fn_ovl_3968(mgr, ctx, 0, 20, 0.04f, 0, 0);
    fn_ovl_1048(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0f20(-1);
    ctx->fD4 += 3.0f;
    ctx->fE8 -= 15.0f;
    p += 0x140000;
    fn_ovl_30f0(p, res, g_ovl_dat_04f0);
    ctx->w110 = p;
    fn_ovl_1048(-1, pos, 1);
    for (i = 0; i < g_ovl_hdr.count; i++) {
        float *pos2;
        ctx = &g_ovl_ctx[i * 2];
        fn_ovl_3968(mgr, ctx, 1, 35, 0.15f, 0, g_ovl_dat_3f08);
        fn_ovl_1048(i, &ctx->fD0, 1);
        ctx->fC4 = fn_ovl_0f20(i);
        ctx++;
        fn_ovl_3968(mgr, ctx, 2, 35, 0.36f, 0, 0);
        pos2 = &ctx->fD0;
        fn_ovl_1048(i, pos2, 3);
        fn_ovl_4698(rot, pos2, pos);
        ctx->fC4 = rot[1];
        ctx->fE8 -= 4.0f;
    }
    fn_ovl_2a30(-1, g_ovl_dat_4d08, g_ovl_dat_0518);
    fn_ovl_37d0(fn_ovl_3608((void *)fn_ovl_0c08));
    return 0;
}
