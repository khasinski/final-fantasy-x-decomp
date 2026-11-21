/* 09362 effect initializer (400 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int w4; } OvlPair;
typedef struct { u8 pad00[0x54]; int w54; } OvlObj;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x58];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_dat_0558[];
extern OvlPair g_ovl_dat_05a0;
extern u8 g_ovl_dat_0ba8[];
extern int g_ovl_w4da0;
extern u8 g_ovl_dat_4da8[];
extern OvlObj g_ovl_obj;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_50d0;
extern void *g_ovl_ptr_50d4;

extern void fn_ovl_0c40(int);
extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_37d8(void *, void *, void *, int);
extern void fn_ovl_38b0(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0f90(int, void *, int);
extern void fn_ovl_4c38(void *, void *, void *, int);
extern void fn_ovl_2978(int, void *, void *);
extern void *fn_ovl_3550(void *);
extern void fn_ovl_3718(void *);
extern void fn_ovl_0b20(void);

int ovl_09362_0990(void)
{
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlObj *obj;

    g_ovl_ptr_50d0 = p;
    g_ovl_ptr_50d4 = p + 0x40000;
    g_ovl_dat_05a0.w0 = 20;
    g_ovl_dat_05a0.w4 = 0;
    fn_ovl_0c40(g_ovl_w4da0);
    res = g_ovl_res;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_37d8(mgr, g_ovl_dat_0040, g_ovl_ptr_50d0, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_38b0(mgr, ctx, 0, 152, 1.5f, 0, g_ovl_dat_0ba8);
    fn_ovl_0f90(-1, &ctx->fD0, 0);
    ctx++;
    fn_ovl_38b0(mgr, ctx, 1, 0, 0.3f, 0, 0);
    fn_ovl_0f90(-1, &ctx->fD0, 1);
    ctx->fD4 -= 5.0f;
    obj = &g_ovl_obj;
    fn_ovl_4c38(obj, res, g_ovl_dat_0540, 1);
    obj->w54 = -1;
    fn_ovl_2978(-1, g_ovl_dat_4da8, g_ovl_dat_0558);
    fn_ovl_3718(fn_ovl_3550((void *)fn_ovl_0b20));
    return 0;
}
