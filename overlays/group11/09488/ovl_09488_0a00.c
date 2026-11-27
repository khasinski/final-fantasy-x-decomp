#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x30];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    u8 pad00[0x1E4];
    int count;
} OvlCount;

typedef struct {
    float f00;
    u8 pad04[0x0C];
    float f10;
    u8 pad14[0x2C];
} OvlLight;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0590[];
extern int g_ovl_dat_05a8[];
extern int g_ovl_dat_05b8[];
extern OvlCount g_ovl_dat_0608;
extern u8 g_ovl_dat_4050[];
extern u8 g_ovl_4808[];
extern OvlLight g_ovl_4830[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_48f0[];
extern void *g_ovl_ptr_5bf0;
extern void *g_ovl_ptr_5bf4;

extern float func_002B3DF8(float);
extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0d20(void);
extern int fn_ovl_0f20(int);
extern float fn_ovl_1048(int);
extern void fn_ovl_1170(int, void *, int);
extern int fn_ovl_15e8(int);
extern int fn_ovl_2560(void *);
extern void fn_ovl_2b58(int, void *, void *);
extern void fn_ovl_2fa0(int);
extern void fn_ovl_3218(void *, void *, void *);
extern void *fn_ovl_3730(void *);
extern void fn_ovl_38f8(void *);
extern void fn_ovl_39b8(void *, void *, void *, int);
extern int fn_ovl_3a90(void *, void *, float, int, int, int, void *);
extern void fn_ovl_45c0(void *, float, float, int, int);

int ovl_09488_0a00(void)
{
    signed char ids[16];
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlLight *l;
    float ang;
    int delay;
    int i;

    g_ovl_ptr_5bf0 = p;
    g_ovl_ptr_5bf4 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_39b8(mgr, g_ovl_dat_0040, g_ovl_ptr_5bf0, 0x40000);
    fn_ovl_2560(ids);
    ctx = g_ovl_48f0;
    ang = fn_ovl_1048(-1);

    delay = 0;
    for (i = 0; i < g_ovl_dat_0608.count; i++, ctx++, delay += 35) {
        int id = ids[i];
        int mode = 7;
        float scale = (func_002B3DF8(0.2f) + 1.0f) * 0.4f;
        int kind = fn_ovl_15e8(id);
        int *tp = g_ovl_dat_05a8;
        u8 *sub;

        while (*tp != -1) {
            if (*tp == kind) {
                mode = 5;
                break;
            }
            tp++;
        }

        fn_ovl_3a90(mgr, ctx, scale, 0, delay, 30, g_ovl_dat_4050);
        fn_ovl_1170(id, ctx->pos, mode);
        ctx->fC4 = ang;
        ctx->pos[1] -= 0.5f;
        ctx->w120 = fn_ovl_0f20(id);
        sub = p + ((i << 6) + 0x140000);
        fn_ovl_3218(sub, g_ovl_res, g_ovl_dat_0590);
        ctx->w110 = sub;
    }

    g_ovl_dat_05b8[1] = delay - 35;
    fn_ovl_2b58(-1, g_ovl_4808, (delay - 35 > 0) ? &g_ovl_dat_05b8[0] : &g_ovl_dat_05b8[2]);

    l = g_ovl_4830;
    fn_ovl_45c0(l, 1.0f, 0.33f, 8, 0);
    l->f10 = 0.45f;
    fn_ovl_45c0(l + 1, 0.33f, 1.0f, 16, delay + 30);
    l[1].f00 = 0.45f;

    fn_ovl_2fa0(1);
    fn_ovl_38f8(fn_ovl_3730((void *)fn_ovl_0d20));
    return 0;
}
