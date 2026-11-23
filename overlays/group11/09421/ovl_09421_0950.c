/* 09421 effect init (744 B). */

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
    u8 padE0[0x24];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
    float pos2[4];
    int w140;
    int w144;
    u8 pad148[0x08];
} OvlCtx;

typedef struct {
    int pad00;
    int count;
} OvlCount;

typedef struct {
    u8 pad00[0x14];
    void *w14;
    u8 b18;
} OvlTaskObj;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_04a0[];
extern u8 g_ovl_dat_04b8[];
extern u8 g_ovl_dat_04d0[];
extern OvlCount g_ovl_dat_0528;
extern u8 g_ovl_dat_43f8[];
extern u8 g_ovl_5578[];
extern OvlCtx g_ovl_55a0[];
extern void *g_ovl_ptr_6020;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_6070;
extern void *g_ovl_ptr_62d0;
extern void *g_ovl_ptr_62d4;

extern void *func_002B49A0(void *, int, int);
extern int func_002EFD78(void);
extern void fn_ovl_0c38(void);
extern void fn_ovl_0c68(void);
extern void fn_ovl_0d00(void);
extern void fn_ovl_0f00(void);
extern int fn_ovl_12c8(int);
extern float fn_ovl_13f0(int);
extern void fn_ovl_1518(int, void *, int);
extern void fn_ovl_2f00(int, void *, void *);
extern void fn_ovl_35c0(void *, void *, void *);
extern OvlTaskObj *fn_ovl_3ad8(void *);
extern void fn_ovl_3ca0(OvlTaskObj *);
extern void fn_ovl_3d60(void *, void *, void *, int);
extern int fn_ovl_3e38(void *, void *, int, int, int, void *, float);
extern void fn_ovl_4fd0(void *, int);

int ovl_09421_0950(void)
{
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlTaskObj *t;
    int i;

    g_ovl_ptr_62d0 = p;
    g_ovl_ptr_62d4 = p + 0x40000;
    res = g_ovl_res;
    g_ovl_ptr_6020 = p + 0x140000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3d60(mgr, g_ovl_dat_0040, g_ovl_ptr_62d0, 0x40000);

    fn_ovl_3e38(mgr, &g_ovl_6070, 0, 23, 0, 0, 0.15f);
    fn_ovl_1518(-1, g_ovl_6070.pos, 0);
    g_ovl_6070.fC4 = fn_ovl_13f0(-1);
    g_ovl_6070.pos[1] -= 8.0f;
    g_ovl_6070.w104 = (void *)fn_ovl_0d00;
    {
        u8 *sub = p + 0x190000;
        fn_ovl_35c0(sub, res, g_ovl_dat_04a0);
        g_ovl_6070.w110 = sub;
    }

    ctx = g_ovl_55a0;
    for (i = 0; i < g_ovl_dat_0528.count; i++, ctx++) {
        float *pos = ctx->pos;
        int d = func_002EFD78() % 10 + 163;
        u8 *sub;

        fn_ovl_3e38(mgr, ctx, 1, d, 0, g_ovl_dat_43f8, 0.15f);
        fn_ovl_1518(i, pos, 1);
        ctx->fC4 = fn_ovl_13f0(i);
        ctx->w120 = fn_ovl_12c8(i);
        sub = p + ((i << 6) + 0x190040);
        fn_ovl_35c0(sub, g_ovl_res, g_ovl_dat_04b8);
        ctx->w110 = sub;
        MMI_COPY_LQ_A3(ctx->pos2, pos);
        MMI_COPY_SQ_A3(ctx->pos2);
        ctx->pos2[1] -= 50.0f;
        ctx->w140 = 103;
        ctx->w144 = 30;
        t = fn_ovl_3ad8((void *)fn_ovl_0f00);
        t->w14 = ctx;
        fn_ovl_3ca0(t);
    }

    t = fn_ovl_3ad8((void *)fn_ovl_0c38);
    t->b18 = 1;
    fn_ovl_3ca0(t);
    fn_ovl_2f00(-1, g_ovl_5578, g_ovl_dat_04d0);
    fn_ovl_4fd0(p + 0x180000, 512);
    t = fn_ovl_3ad8((void *)fn_ovl_0c68);
    t->b18 = 2;
    fn_ovl_3ca0(t);
    return 0;
}
