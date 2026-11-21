/* Shared 09158/09159 effect initializer (520 B, 2 containers). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct { u8 pad00[0x64]; float f64; } OvlObj;
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
extern u8 g_ovl_dat_3e40[];
extern u8 g_ovl_dat_04f0[];
extern OvlHdr g_ovl_dat_0540;
extern void *g_ovl_ptr_56c0;
extern void *g_ovl_ptr_56c4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_37a8(void *, void *, void *, int);
extern void fn_ovl_0f60(int, void *, int);
extern OvlObj *fn_ovl_3880(void *, void *, int, int, float, int, void *);
extern void fn_ovl_3008(void *, void *, void *);
extern int fn_ovl_0d10(int);
extern void *fn_ovl_3520(void *);
extern void fn_ovl_36e8(void *);
extern void fn_ovl_0940(void);

int ovl_09158_0998(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    int i;
    int delay = 0;

    g_ovl_ptr_56c4 = p + 0x40000;
    g_ovl_ptr_56c0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_37a8(mgr, g_ovl_dat_0040, g_ovl_ptr_56c0, 0x40000);
    ctx = g_ovl_ctx;
    for (i = 0; i < g_ovl_dat_0540.count; i++) {
        float pos[4];
        OvlObj *obj;
        u8 *q;
        fn_ovl_0f60(i, pos, 0);
        obj = fn_ovl_3880(mgr, ctx, 1, delay, 0.025f, 0, 0);
        fn_ovl_0f60(i, &ctx->fD0, 5);
        ctx->fD4 = pos[1] - 90.0f;
        obj->f64 += obj->f64;
        q = p + ((i << 6) + 0x140000);
        fn_ovl_3008(q, g_ovl_res, g_ovl_dat_04f0);
        ctx->w110 = q;
        ctx++;
        fn_ovl_3880(mgr, ctx, 0, delay + 22, 0.025f, 0, g_ovl_dat_3e40);
        delay += 15;
        fn_ovl_0f60(i, &ctx->fD0, 5);
        ctx->fD4 = pos[1] - 6.0f;
        ctx->w120 = fn_ovl_0d10(i);
        ctx++;
    }
    fn_ovl_36e8(fn_ovl_3520((void *)fn_ovl_0940));
    return 0;
}
