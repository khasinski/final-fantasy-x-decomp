/* 09147 effect initializer (452 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x40]; } OvlFade;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    float fD8;
    u8 padDC[0x34];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3fb8[];
extern u8 g_ovl_dat_06a8[];
extern void *g_ovl_ptr_4ac0;
extern void *g_ovl_ptr_4ac4;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3940(void *, void *, void *, int);
extern void fn_ovl_1740(float *);
extern void fn_ovl_3a18(void *, void *, int, int, float, int, void *);
extern void fn_ovl_31a0(void *, void *, void *);
extern void fn_ovl_4548(void *, int, int, float, float);
extern void fn_ovl_2f28(int);
extern void *fn_ovl_36b8(void *);
extern void fn_ovl_3880(void *);
extern void fn_ovl_0b18(void);

int ovl_09147_0b70(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    float pos[4];

    g_ovl_ptr_4ac0 = p;
    g_ovl_ptr_4ac4 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3940(mgr, g_ovl_dat_0040, g_ovl_ptr_4ac0, 0x40000);
    fn_ovl_1740(pos);
    ctx = g_ovl_ctx;
    fn_ovl_3a18(mgr, ctx, 0, 0, 0.27f, 30, g_ovl_dat_3fb8);
    ctx->fD0 = pos[0];
    ctx->fD4 = pos[1];
    ctx->fD8 = pos[2];
    p += 0x140000;
    fn_ovl_31a0(p, res, g_ovl_dat_06a8);
    ctx->w110 = p;
    ctx++;
    fn_ovl_3a18(mgr, ctx, 1, 0, 0.27f, 0, 0);
    ctx->fD0 = pos[0];
    ctx->fD4 = pos[1];
    ctx->fD8 = pos[2];
    fn_ovl_4548(&g_ovl_fade[0], 8, 0, 1.0f, 1.5f);
    fn_ovl_4548(&g_ovl_fade[1], 16, 80, 1.5f, 1.0f);
    fn_ovl_2f28(1);
    fn_ovl_3880(fn_ovl_36b8((void *)fn_ovl_0b18));
    return 0;
}
