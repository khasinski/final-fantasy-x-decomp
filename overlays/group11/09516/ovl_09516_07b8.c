/* 09516 effect initializer (428 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x54]; int w54; } OvlObj;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x58];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0360[];
extern u8 g_ovl_dat_0378[];
extern u8 g_ovl_dat_4bc8[];
extern void *g_ovl_ptr_4ef0;
extern void *g_ovl_ptr_4ef4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlObj g_ovl_obj;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_35f0(void *, void *, void *, int);
extern void fn_ovl_36c8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0da8(int, void *, int);
extern float fn_ovl_0c80(int);
extern void fn_ovl_4a50(void *, void *, void *, int);
extern void fn_ovl_1a40(int, int);
extern void fn_ovl_2790(int, void *, void *);
extern void *fn_ovl_3368(void *);
extern void fn_ovl_3530(void *);
extern void fn_ovl_0968(void);

int ovl_09516_07b8(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlObj *obj;

    g_ovl_ptr_4ef0 = p;
    g_ovl_ptr_4ef4 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_35f0(mgr, g_ovl_dat_0040, g_ovl_ptr_4ef0, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_36c8(mgr, ctx, 0, 100, 0.6f, 0, 0);
    fn_ovl_0da8(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0c80(-1);
    ctx->fD4 -= 0.5f;
    ctx++;
    fn_ovl_36c8(mgr, ctx, 1, 75, 0.6f, 0, 0);
    fn_ovl_0da8(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0c80(-1);
    ctx->fD4 -= 0.5f;
    obj = &g_ovl_obj;
    fn_ovl_4a50(obj, g_ovl_res, g_ovl_dat_0360, 1);
    obj->w54 = -1;
    fn_ovl_1a40(-1, 0);
    fn_ovl_2790(-1, g_ovl_dat_4bc8, g_ovl_dat_0378);
    fn_ovl_3530(fn_ovl_3368((void *)fn_ovl_0968));
    return 0;
}
