/* 09226 effect initializer (424 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x68]; float f68; } OvlObj;
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
extern u8 g_ovl_dat_3e60[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_dat_0568[];
extern u8 g_ovl_dat_4c58[];
extern void *g_ovl_ptr_4df0;
extern void *g_ovl_ptr_4df4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_37e8(void *, void *, void *, int);
extern OvlObj *fn_ovl_38c0(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0fa0(int, void *, int);
extern void fn_ovl_15e8(void *);
extern void fn_ovl_3048(void *, void *, void *);
extern void fn_ovl_45f0(float *, float *, void *);
extern void fn_ovl_2988(int, void *, void *);
extern void *fn_ovl_3560(void *);
extern void fn_ovl_3728(void *);
extern void fn_ovl_0b60(void);

int ovl_09226_09b8(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    OvlObj *obj;
    float rot[4];
    float pos[4];

    g_ovl_ptr_4df0 = p;
    g_ovl_ptr_4df4 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_37e8(mgr, g_ovl_dat_0040, g_ovl_ptr_4df0, 0x40000);
    ctx = g_ovl_ctx;
    obj = fn_ovl_38c0(mgr, ctx, 0, 20, 0.12f, 0, g_ovl_dat_3e60);
    fn_ovl_0fa0(0, &ctx->fD0, 1);
    fn_ovl_15e8(&ctx->fD0);
    p += 0x140000;
    fn_ovl_3048(p, res, g_ovl_dat_0540);
    ctx->w110 = p;
    fn_ovl_0fa0(-1, pos, 3);
    fn_ovl_45f0(rot, pos, &ctx->fD0);
    ctx->fC4 = rot[1];
    ctx->fE8 = 45.0f;
    ctx->fD4 = pos[1] - 6.0f;
    obj->f68 *= 0.7f;
    fn_ovl_2988(-1, g_ovl_dat_4c58, g_ovl_dat_0568);
    fn_ovl_3728(fn_ovl_3560((void *)fn_ovl_0b60));
    return 0;
}
