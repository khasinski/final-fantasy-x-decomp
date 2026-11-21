/* 09318 effect initializer (612 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 r, g, b, a; } OvlRgba;
typedef struct {
    u8 pad00[0x80];
    OvlRgba c0;
    OvlRgba c1;
    int delay;
    int cur;
    int total;
    int hold;
    u8 b98;
    u8 b99;
} OvlObj;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    u8 padD4[0x30];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_4078[];
extern u8 g_ovl_dat_0630[];
extern u8 g_ovl_dat_0648[];
extern u8 g_ovl_dat_0660[];
extern u8 g_ovl_dat_4748[];
extern OvlObj g_ovl_obj;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_4ab0;
extern void *g_ovl_ptr_4ab4;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3a00(void *, void *, void *, int);
extern void fn_ovl_3ad8(void *, void *, int, float, int, int, void *);
extern void fn_ovl_11b8(int, void *, int);
extern float fn_ovl_1090(int);
extern void fn_ovl_3260(void *, void *, void *);
extern void fn_ovl_45c0(void *, int);
extern void fn_ovl_2ba0(int, void *, void *);
extern void *fn_ovl_3778(void *);
extern void fn_ovl_3940(void *);
extern void fn_ovl_0d18(void);
extern void fn_ovl_0d98(void);

int ovl_09318_0ab0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    /* DEBT(FAKE): pin q to s0 to match original callee-saved register allocation. */
    register u8 *q __asm__("s0");
    float ang;

    g_ovl_ptr_4ab0 = p;
    g_ovl_ptr_4ab4 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3a00(mgr, g_ovl_dat_0040, g_ovl_ptr_4ab0, 0x40000);
    ctx = &g_ovl_ctx[1];
    fn_ovl_3ad8(mgr, ctx, 1, 0.2f, 22, 0, 0);
    fn_ovl_11b8(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_1090(-1);
    ctx->w104 = (void *)fn_ovl_0d98;
    q = p + 0x140000;
    fn_ovl_3260(q, g_ovl_res, g_ovl_dat_0630);
    ctx->w110 = q;
    ctx--;
    fn_ovl_3ad8(mgr, ctx, 0, 0.2f, 38, 0, g_ovl_dat_4078);
    fn_ovl_11b8(0, &ctx->fD0, 1);
    ang = fn_ovl_1090(-1) + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    ctx->fC4 = ang;
    q = p + 0x140040;
    fn_ovl_3260(q, g_ovl_res, g_ovl_dat_0648);
    ctx->w110 = q;
    g_ovl_obj.c0.b = 128;
    g_ovl_obj.c0.g = 128;
    g_ovl_obj.c0.r = 128;
    g_ovl_obj.c0.a = 128;
    g_ovl_obj.c1.r = 128;
    g_ovl_obj.c1.g = 128;
    g_ovl_obj.c1.b = 128;
    g_ovl_obj.c1.a = 0;
    g_ovl_obj.delay = 22;
    g_ovl_obj.b98 = 72;
    g_ovl_obj.b99 = 0;
    fn_ovl_45c0(&g_ovl_obj, 16);
    fn_ovl_2ba0(-1, g_ovl_dat_4748, g_ovl_dat_0660);
    fn_ovl_3940(fn_ovl_3778((void *)fn_ovl_0d18));
    return 0;
}
