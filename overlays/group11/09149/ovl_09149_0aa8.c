/* 09149 effect initializer (396 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    float f00;
    u8 pad04[0x0C];
    float f10;
    u8 pad14[0x2C];
} OvlFade;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3eb8[];
extern u8 g_ovl_dat_05e0[];
extern void *g_ovl_ptr_4890;
extern void *g_ovl_ptr_4894;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3840(void *, void *, void *, int);
extern void fn_ovl_3918(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0ff8(int, void *, int);
extern void fn_ovl_30a0(void *, void *, void *);
extern void fn_ovl_4448(void *, int, int, float, float);
extern void fn_ovl_2e28(int);
extern void *fn_ovl_35b8(void *);
extern void fn_ovl_3780(void *);
extern void fn_ovl_0a50(void);

int ovl_09149_0aa8(void)
{
    u8 *p = g_ovl_buf;
    u8 *res = g_ovl_res;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    OvlFade *fade;

    g_ovl_ptr_4890 = p;
    g_ovl_ptr_4894 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3840(mgr, g_ovl_dat_0040, g_ovl_ptr_4890, 0x40000);
    ctx = g_ovl_ctx;
    fn_ovl_3918(mgr, ctx, 0, 0, 0.4f, 30, g_ovl_dat_3eb8);
    fn_ovl_0ff8(0, &ctx->fD0, 5);
    p += 0x140000;
    fn_ovl_30a0(p, res, g_ovl_dat_05e0);
    ctx->w110 = p;
    fade = g_ovl_fade;
    fn_ovl_4448(&fade[0], 8, 0, 1.0f, 0.33f);
    fade[0].f10 = 0.45f;
    fn_ovl_4448(&fade[1], 16, 69, 0.33f, 1.0f);
    fade[1].f00 = 0.45f;
    fn_ovl_2e28(1);
    fn_ovl_3780(fn_ovl_35b8((void *)fn_ovl_0a50));
    return 0;
}
