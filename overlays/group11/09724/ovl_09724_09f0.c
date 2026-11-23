/* 09724 effect init (916 B). */

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
extern OvlCount g_ovl_dat_05f0;
extern u8 g_ovl_dat_4230[];
extern OvlLight g_ovl_5290[];
extern void *g_ovl_ptr_5310;
extern float g_ovl_ang;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_5360[];
extern void *g_ovl_ptr_7960;
extern void *g_ovl_ptr_7964;

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0d88(void);
extern void fn_ovl_0e78(void);
extern void fn_ovl_0f08(void);
extern int fn_ovl_1100(int);
extern void fn_ovl_1228(int);
extern void fn_ovl_1350(int, void *, int);
extern float fn_ovl_17a0(int);
extern int fn_ovl_1c90(int);
extern void fn_ovl_2740(void *);
extern void fn_ovl_3180(int);
extern void fn_ovl_33f8(void *, void *, void *);
extern void *fn_ovl_3910(void *);
extern void fn_ovl_3ad8(void *);
extern void fn_ovl_3b98(void *, void *, void *, int);
extern int fn_ovl_3c70(void *, void *, float, int, int, int, void *);
extern void fn_ovl_5040(void *, float, float, int, int);

static inline void copy_vec(float *dst, float *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09724_09f0(void)
{
    float pos[4];
    signed char ids[16];
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlLight *l;
    int delay;
    int i;

    g_ovl_ptr_7960 = p;
    g_ovl_ptr_7964 = p + 0x40000;
    g_ovl_ptr_5310 = p + 0x120000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3b98(mgr, g_ovl_dat_0040, g_ovl_ptr_7960, 0x40000);
    fn_ovl_2740(ids);
    ctx = g_ovl_5360;
    fn_ovl_1228(-1);

    g_ovl_dat_0450.w78 = (void *)fn_ovl_0e78;
    g_ovl_dat_04d8.w78 = (void *)fn_ovl_0f08;

    delay = 0;
    for (i = 0; i < g_ovl_dat_05f0.count; i++, delay += 45) {
        int id = ids[i];
        float ang = func_002B3DB0(3.1415927410125732f);
        float scale = func_002B3DF8(0.2f) + 1.0f;

        fn_ovl_1350(id, pos, 5);
        if (fn_ovl_1c90(id) == 0) {
            u8 *sub;

            fn_ovl_3c70(mgr, ctx, scale * 0.4f, 1, delay, 18, g_ovl_dat_4230);
            copy_vec(ctx->pos, pos);
            ctx->fC4 = ang;
            ctx->w120 = fn_ovl_1100(id);
            sub = p + ((i << 6) + 0x200000);
            fn_ovl_33f8(sub, g_ovl_res, g_ovl_dat_05a0);
            ctx->w110 = sub;

            ctx++;
            fn_ovl_3c70(mgr, ctx, scale * 0.3f, 0, delay + 20, 0, 0);
            copy_vec(ctx->pos, pos);
            ctx->pos[1] = fn_ovl_17a0(id) - 0.5f;
            ctx->fC4 = ang;
            ctx->w108 = &g_ovl_dat_0450;
            ctx++;
        } else {
            u8 *sub;

            fn_ovl_3c70(mgr, ctx, scale * 0.3f, 2, delay, 18, g_ovl_dat_4230);
            copy_vec(ctx->pos, pos);
            ctx->fC4 = ang;
            ctx->w120 = fn_ovl_1100(id);
            sub = p + ((i << 6) + 0x200000);
            fn_ovl_33f8(sub, g_ovl_res, g_ovl_dat_05a0);
            ctx->w110 = sub;
            ctx->w108 = &g_ovl_dat_04d8;
            ctx++;
        }
    }

    g_ovl_ang = 0.0f;
    l = g_ovl_5290;
    fn_ovl_5040(l, 1.0f, 0.33f, 8, 0);
    l->f18 = 0.45f;
    l++;
    fn_ovl_5040(l, 0.33f, 1.0f, 16, delay + 40);
    l->f08 = 0.45f;

    fn_ovl_3180(1);
    fn_ovl_3ad8(fn_ovl_3910((void *)fn_ovl_0d88));
    return 0;
}
