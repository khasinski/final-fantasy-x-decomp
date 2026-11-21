/* Overlay 09409 effect initializer (300 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3d70[];
extern u8 g_ovl_dat_0518[];
extern void *g_ovl_ptr_4440;
extern void *g_ovl_ptr_4444;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_36f8(void *, void *, void *, int);
extern void fn_ovl_37d0(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0eb0(int, void *, int);
extern float fn_ovl_0d88(int);
extern void fn_ovl_2f58(void *, void *, void *);
extern void *fn_ovl_3470(void *);
extern void fn_ovl_3638(void *);
extern void fn_ovl_0968(void);

int ovl_09409_09c0(void)
{
    /* DEBT(FAKE): pin s2/s1 for g_ovl_buf/&g_ovl_mgr to match original s0..s2 allocation */
    register u8 *p __asm__("$18") = g_ovl_buf;
    register OvlMgr *mgr __asm__("$17") = &g_ovl_mgr;

    g_ovl_ptr_4440 = p;
    {
        /* DEBT(FAKE): pin v0 for p + 0x40000 to match original v0/v1 allocation */
        register u8 *q __asm__("$2") = p + 0x40000;
        g_ovl_ptr_4444 = q;
    }
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_36f8(mgr, g_ovl_dat_0040, g_ovl_ptr_4440, 0x40000);
    fn_ovl_37d0(mgr, &g_ovl_ctx, 0, 0, 40, g_ovl_dat_3d70, 0.07f);
    fn_ovl_0eb0(0, &g_ovl_ctx.fD0, 1);
    g_ovl_ctx.fC4 = fn_ovl_0d88(0);
    g_ovl_ctx.fD4 -= 3.0f;
    p += 0x100000;
    fn_ovl_2f58(p, g_ovl_res, g_ovl_dat_0518);
    g_ovl_ctx.w110 = p;
    fn_ovl_3638(fn_ovl_3470((void *)fn_ovl_0968));
    return 0;
}
