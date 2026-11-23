/* 09484 effect init (960 B). */

#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x28];
    void *w108;
    u8 pad10C[0x04];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    u8 pad00[0x78];
    void *w78;
} OvlParam;

typedef struct {
    u8 pad00[0x1E4];
    int count;
} OvlCount;

typedef struct {
    u8 pad00[0x08];
    float f08;
    u8 pad0C[0x0C];
    float f18;
    u8 pad1C[0x24];
} OvlLight;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern OvlParam g_ovl_dat_0450;
extern OvlParam g_ovl_dat_04d8;
extern u8 g_ovl_dat_05a0[];
extern int g_ovl_dat_05b8[];
extern OvlCount g_ovl_dat_0608;
extern u8 g_ovl_dat_4288[];
extern u8 g_ovl_52e8[];
extern OvlLight g_ovl_5310[];
extern void *g_ovl_ptr_5390;
extern float g_ovl_ang;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_53e0[];
extern void *g_ovl_ptr_79e0;
extern void *g_ovl_ptr_79e4;

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0dc0(void);
extern void fn_ovl_0ed0(void);
extern void fn_ovl_0f60(void);
extern int fn_ovl_1158(int);
extern void fn_ovl_1280(int);
extern void fn_ovl_13a8(int, void *, int);
extern float fn_ovl_17f8(int);
extern int fn_ovl_1ce8(int);
extern void fn_ovl_2798(void *);
extern void fn_ovl_2d90(int, void *, void *);
extern void fn_ovl_31d8(int);
extern void fn_ovl_3450(void *, void *, void *);
extern void *fn_ovl_3968(void *);
extern void fn_ovl_3b30(void *);
extern void fn_ovl_3bf0(void *, void *, void *, int);
extern int fn_ovl_3cc8(void *, void *, float, int, int, int, void *);
extern void fn_ovl_5098(void *, float, float, int, int);

static inline void copy_vec(float *dst, float *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09484_0a00(void)
{
    float pos[4];
    signed char ids[16];
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlLight *l;
    int delay;
    int i;

    g_ovl_ptr_79e0 = p;
    g_ovl_ptr_79e4 = p + 0x40000;
    g_ovl_ptr_5390 = p + 0x120000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3bf0(mgr, g_ovl_dat_0040, g_ovl_ptr_79e0, 0x40000);
    fn_ovl_2798(ids);
    ctx = g_ovl_53e0;
    fn_ovl_1280(-1);

    g_ovl_dat_0450.w78 = (void *)fn_ovl_0ed0;
    g_ovl_dat_04d8.w78 = (void *)fn_ovl_0f60;

    delay = 0;
    for (i = 0; i < g_ovl_dat_0608.count; i++, delay += 45) {
        int id = ids[i];
        float ang = func_002B3DB0(3.1415927410125732f);
        float scale = func_002B3DF8(0.2f) + 1.0f;

        fn_ovl_13a8(id, pos, 5);
        if (fn_ovl_1ce8(id) == 0) {
            u8 *sub;

            fn_ovl_3cc8(mgr, ctx, scale * 0.4f, 1, delay, 18, g_ovl_dat_4288);
            copy_vec(ctx->pos, pos);
            ctx->fC4 = ang;
            ctx->w120 = fn_ovl_1158(id);
            sub = p + ((i << 6) + 0x200000);
            fn_ovl_3450(sub, g_ovl_res, g_ovl_dat_05a0);
            ctx->w110 = sub;

            ctx++;
            fn_ovl_3cc8(mgr, ctx, scale * 0.3f, 0, delay + 20, 0, 0);
            copy_vec(ctx->pos, pos);
            ctx->pos[1] = fn_ovl_17f8(id) - 0.5f;
            ctx->fC4 = ang;
            ctx->w108 = &g_ovl_dat_0450;
            ctx++;
        } else {
            u8 *sub;

            fn_ovl_3cc8(mgr, ctx, scale * 0.3f, 2, delay, 18, g_ovl_dat_4288);
            copy_vec(ctx->pos, pos);
            ctx->fC4 = ang;
            ctx->w120 = fn_ovl_1158(id);
            sub = p + ((i << 6) + 0x200000);
            fn_ovl_3450(sub, g_ovl_res, g_ovl_dat_05a0);
            ctx->w110 = sub;
            ctx->w108 = &g_ovl_dat_04d8;
            ctx++;
        }
    }

    g_ovl_dat_05b8[1] = delay - 45;
    fn_ovl_2d90(-1, g_ovl_52e8, (delay - 45 > 0) ? &g_ovl_dat_05b8[0] : &g_ovl_dat_05b8[2]);

    g_ovl_ang = 0.0f;
    l = g_ovl_5310;
    fn_ovl_5098(l, 1.0f, 0.33f, 8, 0);
    l->f18 = 0.45f;
    l++;
    fn_ovl_5098(l, 0.33f, 1.0f, 16, delay + 40);
    l->f08 = 0.45f;

    fn_ovl_31d8(1);
    fn_ovl_3b30(fn_ovl_3968((void *)fn_ovl_0dc0));
    return 0;
}
