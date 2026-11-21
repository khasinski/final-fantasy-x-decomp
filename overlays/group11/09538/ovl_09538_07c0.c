/* 09538 effect initializer (472 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { u8 pad00[0x1E4]; int count; } OvlInfo;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3cb8[];
extern u8 g_ovl_dat_0360[];
extern int g_ovl_dat_0378[];
extern OvlInfo g_ovl_info;
extern u8 g_ovl_dat_41f8[];
extern void *g_ovl_ptr_5560;
extern void *g_ovl_ptr_5564;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3620(void *, void *, void *, int);
extern int fn_ovl_21c8(signed char *);
extern void fn_ovl_0cb0(int);
extern float func_002B3DF8(float);
extern void fn_ovl_36f8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0dd8(int, void *, int);
extern int fn_ovl_0b88(int);
extern void fn_ovl_2e80(void *, void *, void *);
extern void fn_ovl_27c0(int, void *, void *);
extern void *fn_ovl_3398(void *);
extern void fn_ovl_3560(void *);
extern void fn_ovl_0998(void);

int ovl_09538_07c0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    signed char order[16];
    int i;
    int delay = 0;
    OvlCtx *ctx;
    int d;

    g_ovl_ptr_5564 = p + 0x40000;
    g_ovl_ptr_5560 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3620(mgr, g_ovl_dat_0040, g_ovl_ptr_5560, 0x40000);
    fn_ovl_21c8(order);
    ctx = g_ovl_ctx;
    fn_ovl_0cb0(-1);
    for (i = 0; i < g_ovl_info.count; i++) {
        int idx = order[i];
        u8 *q;
        fn_ovl_36f8(mgr, ctx, 0, delay, func_002B3DF8(0.2f) * 0.2f + 0.2f, 18, g_ovl_dat_3cb8);
        delay += 15;
        fn_ovl_0dd8(idx, &ctx->fD0, 5);
        ctx->w120 = fn_ovl_0b88(idx);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2e80(q, g_ovl_res, g_ovl_dat_0360);
        ctx->w110 = q;
        ctx++;
    }
    d = delay - 15;
    g_ovl_dat_0378[1] = d;
    fn_ovl_27c0(-1, g_ovl_dat_41f8, d > 0 ? &g_ovl_dat_0378[0] : &g_ovl_dat_0378[2]);
    fn_ovl_3560(fn_ovl_3398((void *)fn_ovl_0998));
    return 0;
}
