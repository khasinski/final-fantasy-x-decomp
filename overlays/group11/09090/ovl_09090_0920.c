/* Overlay 09090 effect initializer (268 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xD0];
    u8 bD0[0x40];
    void *w110;
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3d00[];
extern u8 g_ovl_dat_04c8[];
extern void *g_ovl_ptr_43d0;
extern void *g_ovl_ptr_43d4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3688(void *, void *, void *, int);
extern void fn_ovl_3760(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0e40(int, void *, int);
extern void fn_ovl_2ee8(void *, void *, void *);
extern void *fn_ovl_3400(void *);
extern void fn_ovl_35c8(void *);
extern void fn_ovl_0918(void);

int ovl_09090_0920(void)
{
    u8 *p = g_ovl_buf;
    /* DEBT(FAKE): pin s1 for &g_ovl_mgr to match original s1/s2 allocation */
    register OvlMgr *mgr __asm__("$17") = &g_ovl_mgr;

    g_ovl_ptr_43d0 = p;
    {
        /* DEBT(FAKE): pin v0 for p + 0x40000 to match original v0/v1 allocation */
        register u8 *q __asm__("$2") = p + 0x40000;
        g_ovl_ptr_43d4 = q;
    }
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3688(mgr, g_ovl_dat_0040, g_ovl_ptr_43d0, 0x40000);
    fn_ovl_3760(mgr, &g_ovl_ctx, 0, 0, 0, g_ovl_dat_3d00, 0.06f);
    fn_ovl_0e40(0, g_ovl_ctx.bD0, 5);
    p += 0x140000;
    fn_ovl_2ee8(p, g_ovl_res, g_ovl_dat_04c8);
    g_ovl_ctx.w110 = p;
    fn_ovl_35c8(fn_ovl_3400((void *)fn_ovl_0918));
    return 0;
}
