/* 09513 effect initializer (444 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x08];
    float fE0;
    float fE4;
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
extern u8 g_ovl_dat_3f10[];
extern u8 g_ovl_dat_05b8[];
extern u8 g_ovl_dat_05d0[];
extern u8 g_ovl_dat_05e8[];
extern u8 g_ovl_dat_4468[];
extern void *g_ovl_ptr_4730;
extern void *g_ovl_ptr_4734;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3898(void *, void *, void *, int);
extern void fn_ovl_3970(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1050(int, void *, int);
extern float fn_ovl_0f28(int);
extern void fn_ovl_30f8(void *, void *, void *);
extern void fn_ovl_2a38(int, void *, void *);
extern void *fn_ovl_3610(void *);
extern void fn_ovl_37d8(void *);
extern void fn_ovl_0bf8(void);
extern void fn_ovl_0c78(void);

int ovl_09513_0a38(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    u8 *q;

    g_ovl_ptr_4730 = p;
    g_ovl_ptr_4734 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3898(mgr, g_ovl_dat_0040, g_ovl_ptr_4730, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_3970(mgr, ctx, 0, 70, 1.5f, 130, g_ovl_dat_3f10);
    fn_ovl_1050(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0f28(-1);
    ctx->fE0 = 400.0f;
    ctx->fE8 = 200.0f;
    ctx->fD4 += 200.0f;
    q = p + 0x140000;
    fn_ovl_30f8(q, res, g_ovl_dat_05b8);
    ctx->w110 = q;
    ctx++;
    fn_ovl_3970(mgr, ctx, 1, 0, 2.0f, 0, 0);
    ctx->fC4 = fn_ovl_0f28(-1);
    ctx->w104 = (void *)fn_ovl_0c78;
    p += 0x140040;
    fn_ovl_30f8(p, res, g_ovl_dat_05d0);
    ctx->w110 = p;
    fn_ovl_2a38(-1, g_ovl_dat_4468, g_ovl_dat_05e8);
    fn_ovl_37d8(fn_ovl_3610((void *)fn_ovl_0bf8));
    return 0;
}
