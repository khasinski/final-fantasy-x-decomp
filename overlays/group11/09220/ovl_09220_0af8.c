/* 09220 effect initializer (560 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x10];
    float fE8;
    u8 padEC[0x18];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_4040[];
extern u8 g_ovl_dat_0680[];
extern u8 g_ovl_dat_06a8[];
extern u8 g_ovl_dat_4e38[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_5100;
extern void *g_ovl_ptr_5104;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_39c8(void *, void *, void *, int);
extern void fn_ovl_3aa0(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1180(int, void *, int);
extern float fn_ovl_1058(int);
extern void fn_ovl_3228(void *, void *, void *);
extern void fn_ovl_47d0(float *, void *, void *);
extern void fn_ovl_2b68(int, void *, void *);
extern void *fn_ovl_3740(void *);
extern void fn_ovl_3908(void *);
extern void fn_ovl_0d28(void);
extern void fn_ovl_0da8(void);

int ovl_09220_0af8(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    float *pos0;
    float *pos1;
    float rot[4];
    float ang;

    g_ovl_ptr_5100 = p;
    g_ovl_ptr_5104 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_39c8(mgr, g_ovl_dat_0040, g_ovl_ptr_5100, 0x40000);
    ctx = &g_ovl_ctx[0];
    pos0 = &ctx->fD0;
    fn_ovl_3aa0(mgr, ctx, 0, 0, 0.4f, 0, 0);
    fn_ovl_1180(-1, pos0, 0);
    ctx->fC4 = fn_ovl_1058(-1);
    ctx->w104 = (void *)fn_ovl_0da8;
    p += 0x140000;
    fn_ovl_3228(p, res, g_ovl_dat_0680);
    ctx->w110 = p;
    ctx++;
    fn_ovl_3aa0(mgr, ctx, 1, 23, 0.1f, 0, g_ovl_dat_4040);
    pos1 = &ctx->fD0;
    fn_ovl_1180(0, pos1, 1);
    ctx->fD4 -= 2.0f;
    ctx->fE8 = -2.0f;
    fn_ovl_47d0(rot, pos0, pos1);
    g_ovl_ctx[0].fC0 = rot[0];
    ang = rot[1] + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    g_ovl_ctx[1].fC4 = ang;
    fn_ovl_2b68(-1, g_ovl_dat_4e38, g_ovl_dat_06a8);
    fn_ovl_3908(fn_ovl_3740((void *)fn_ovl_0d28));
    return 0;
}
