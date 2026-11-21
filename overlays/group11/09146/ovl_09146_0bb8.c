/* 09146 effect initializer (724 B). */

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
extern u8 g_ovl_dat_4110[];
extern u8 g_ovl_dat_06a8[];
extern u8 g_ovl_dat_06d0[];
extern int g_ovl_tab_06f8[];
extern int g_ovl_tab_0708[];
extern OvlFade g_ovl_fade[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_4c10;
extern void *g_ovl_ptr_4c14;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3a98(void *, void *, void *, int);
extern void fn_ovl_1898(float *);
extern int fn_ovl_16c8(int);
extern float fn_ovl_16a0(int);
extern void fn_ovl_1250(int, float *, int);
extern void fn_ovl_3b70(void *, void *, int, int, float, int, void *);
extern void fn_ovl_32f8(void *, void *, void *);
extern void fn_ovl_46a0(void *, int, int, float, float);
extern void fn_ovl_3080(int);
extern void *fn_ovl_3810(void *);
extern void fn_ovl_39d8(void *);
extern void fn_ovl_0b60(void);

int ovl_09146_0bb8(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    OvlFade *fade;
    u8 *q;
    u8 *dat;
    int *tp;
    int id;
    int found;
    float pos[4];
    float y;

    g_ovl_ptr_4c14 = p + 0x40000;
    g_ovl_ptr_4c10 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3a98(mgr, g_ovl_dat_0040, g_ovl_ptr_4c10, 0x40000);
    fn_ovl_1898(pos);
    id = fn_ovl_16c8(0);
    found = 0;
    for (tp = g_ovl_tab_06f8; *tp != -1; tp++) {
        if (*tp == id) {
            found = 1;
            break;
        }
    }
    if (!found) {
        y = fn_ovl_16a0(0) - 40.0f;
    } else {
        fn_ovl_1250(0, pos, 5);
        y = pos[1];
    }
    id = fn_ovl_16c8(-1);
    tp = g_ovl_tab_0708;
    found = 0;
    for (; *tp != -1; tp++) {
        if (*tp == id) {
            found = 1;
            break;
        }
    }
    if (!found) {
        dat = g_ovl_dat_06a8;
    } else {
        dat = g_ovl_dat_06d0;
    }
    ctx = g_ovl_ctx;
    fn_ovl_3b70(mgr, ctx, 0, 0, 0.27f, 30, g_ovl_dat_4110);
    ctx->fD0 = pos[0];
    ctx->fD4 = y;
    ctx->fD8 = pos[2];
    q = p + 0x140000;
    fn_ovl_32f8(q, g_ovl_res, dat);
    ctx->w110 = q;
    ctx++;
    fn_ovl_3b70(mgr, ctx, 1, 0, 0.27f, 0, 0);
    ctx->fD0 = pos[0];
    ctx->fD4 = y;
    ctx->fD8 = pos[2];
    fade = g_ovl_fade;
    fn_ovl_46a0(&fade[0], 8, 0, 1.0f, 1.5f);
    fn_ovl_46a0(&fade[1], 16, 80, 1.5f, 1.0f);
    fn_ovl_3080(1);
    fn_ovl_39d8(fn_ovl_3810((void *)fn_ovl_0b60));
    return 0;
}
