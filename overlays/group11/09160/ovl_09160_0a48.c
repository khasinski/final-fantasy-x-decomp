/* 09160 effect initializer (672 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct { u8 pad00[0x40]; } OvlFade;
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
extern u8 g_ovl_dat_3f88[];
extern u8 g_ovl_dat_0568[];
extern u8 g_ovl_dat_0580[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_5b10;
extern void *g_ovl_ptr_5b14;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_38f0(void *, void *, void *, int);
extern void fn_ovl_10a8(int, void *, int);
extern OvlObj *fn_ovl_39c8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_3150(void *, void *, void *);
extern int fn_ovl_0e58(int);
extern void fn_ovl_44f8(void *, int, int, float, float);
extern void fn_ovl_2ed8(int);
extern void *fn_ovl_3668(void *);
extern void fn_ovl_3830(void *);
extern void fn_ovl_09f0(void);

int ovl_09160_0a48(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    int n;
    u8 *dat;
    int i;
    int delay = 0;

    g_ovl_ptr_5b14 = p + 0x40000;
    g_ovl_ptr_5b10 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_38f0(mgr, g_ovl_dat_0040, g_ovl_ptr_5b10, 0x40000);
    n = g_ovl_hdr.count;
    ctx = g_ovl_ctx;
    dat = (n == 1) ? g_ovl_dat_0580 : g_ovl_dat_0568;
    for (i = 0; i < n; i++) {
        float pos[4];
        OvlObj *obj;
        u8 *q;
        fn_ovl_10a8(i, pos, 0);
        obj = fn_ovl_39c8(mgr, ctx, 0, delay, 0.025f, 0, 0);
        fn_ovl_10a8(i, &ctx->fD0, 5);
        ctx->fD4 = pos[1] - 90.0f;
        obj->f64 += obj->f64;
        q = p + ((i << 6) + 0x140000);
        fn_ovl_3150(q, g_ovl_res, dat);
        ctx->w110 = q;
        ctx++;
        fn_ovl_39c8(mgr, ctx, 1, delay + 22, 0.032f, 0, g_ovl_dat_3f88);
        delay += 15;
        fn_ovl_10a8(i, &ctx->fD0, 5);
        ctx->fD4 = pos[1] - 6.0f;
        ctx->w120 = fn_ovl_0e58(i);
        ctx++;
    }
    fn_ovl_44f8(&g_ovl_fade[0], 8, 0, 1.0f, 0.33f);
    fn_ovl_44f8(&g_ovl_fade[1], 16, (g_ovl_hdr.count - 1) * 15 + 46, 0.33f, 1.0f);
    fn_ovl_2ed8(1);
    fn_ovl_3830(fn_ovl_3668((void *)fn_ovl_09f0));
    return 0;
}
