/* 09148 effect initializer (608 B). */

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
extern u8 g_ovl_dat_3f48[];
extern u8 g_ovl_dat_0590[];
extern int g_ovl_tbl[];
extern void *g_ovl_ptr_4920;
extern void *g_ovl_ptr_4924;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern OvlFade g_ovl_fade[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_38d0(void *, void *, void *, int);
extern int fn_ovl_1500(int);
extern void fn_ovl_39a8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_1088(int, void *, int);
extern float fn_ovl_14d8(int);
extern void fn_ovl_3130(void *, void *, void *);
extern void fn_ovl_44d8(void *, int, int, float, float);
extern void fn_ovl_2eb8(int);
extern void *fn_ovl_3648(void *);
extern void fn_ovl_3810(void *);
extern void fn_ovl_0a10(void);

int ovl_09148_0a68(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    OvlFade *fade;
    int id;
    int mode = 7;
    int *tbl;
    u8 *q;

    g_ovl_ptr_4924 = p + 0x40000;
    g_ovl_ptr_4920 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_38d0(mgr, g_ovl_dat_0040, g_ovl_ptr_4920, 0x40000);
    id = fn_ovl_1500(0);
    for (tbl = g_ovl_tbl; *tbl != -1; tbl++) {
        if (*tbl == id) {
            mode = 5;
            break;
        }
    }
    ctx = g_ovl_ctx;
    fn_ovl_39a8(mgr, ctx, 0, 0, 0.4f, 30, g_ovl_dat_3f48);
    fn_ovl_1088(0, &ctx->fD0, mode);
    if (id == 4215 || id == 4440 || id == 4441 || id == 4442) {
        ctx->fD4 = fn_ovl_14d8(-1);
    }
    ctx->fD4 -= 0.5f;
    q = p + 0x140000;
    fn_ovl_3130(q, g_ovl_res, g_ovl_dat_0590);
    ctx->w110 = q;
    fade = g_ovl_fade;
    fn_ovl_44d8(&fade[0], 8, 0, 1.0f, 0.33f);
    fade[0].f10 = 0.45f;
    fn_ovl_44d8(&fade[1], 16, 69, 0.33f, 1.0f);
    fade[1].f00 = 0.45f;
    fn_ovl_2eb8(1);
    fn_ovl_3810(fn_ovl_3648((void *)fn_ovl_0a10));
    return 0;
}
