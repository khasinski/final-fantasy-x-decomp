/* 09342 effect init + shadow setup (1344 B, 2 funcs). */

#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC0];
    float rot[4];
    float pos[4];
    u8 padE0[0x30];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

typedef struct {
    int pad00;
    int count;
} OvlCount;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    int w40;
    int w44;
    int w48;
    int w4C;
    int w50;
    u8 pad54[0x0C];
} OvlWork;

typedef struct {
    u8 pad00[0x04];
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x08];
    int w24;
    u8 pad28[0x04];
    u16 h2C;
} OvlShake;

typedef struct {
    void *w00;
    int w04;
    int w08;
    int w0C;
} OvlFade;

typedef struct {
    u8 pad00[0x14];
    void *w14;
    u8 b18;
} OvlTask;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_04f0[];
extern u8 g_ovl_dat_0520[];
extern u8 g_ovl_dat_0540[];
extern OvlCount g_ovl_dat_0588;
extern u8 g_ovl_55f8[];
extern OvlFade g_ovl_5618;
extern OvlShake g_ovl_5638;
extern void *g_ovl_ptr_5668;
extern OvlWork g_ovl_5670[];
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_59b0;
extern void *g_ovl_ptr_5ae0;
extern void *g_ovl_ptr_5ae4;

extern void func_00173B90(void *, int, int, int, void *, void *, void *, int);
extern void func_00173CD8(void *, void *, void *, int, unsigned long, unsigned long, float);
extern void *func_002B49A0(void *, int, int);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCF48(float *, float *);
extern void func_002DCFD8(float *, float *, float);
extern void func_002DD020(float *, float *, float *);
extern void func_002DD128(float *);
extern void func_002DD318(float *, float *, float);
extern void func_002DD3C0(float *, float *, float *);

extern void fn_ovl_0ed0(void);
extern void fn_ovl_0fb0(void);
extern void fn_ovl_10d0(int);
extern float fn_ovl_1478(int);
extern void fn_ovl_15a0(int, void *, int);
extern float fn_ovl_19f0(int);
extern int fn_ovl_2098(int, int);
extern void fn_ovl_2f88(int, void *, void *);
extern void fn_ovl_3648(void *, void *, void *);
extern OvlTask *fn_ovl_3b60(void *);
extern void fn_ovl_3d28(OvlTask *);
extern void fn_ovl_3de8(void *, void *, void *, int);
extern int fn_ovl_3ec0(void *, void *, float, int, int, int, void *);
extern void fn_ovl_4bf0(void *, void *, void *);
extern void fn_ovl_4cf8(void *, void *, void *);
extern void fn_ovl_5248(void *, int);
extern void fn_ovl_5350(void *, int);

void ovl_09342_0d50(void);

int ovl_09342_0990(void)
{
    float m[16];
    float pos0[4];
    float pos1[4];
    float off[4];
    float vec[4];
    float rot[4];
    float tmp[4];
    register float *pos0p __asm__("$23");
    u8 *p = g_ovl_buf;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlWork *work;
    OvlShake *shk;
    OvlFade *f;
    OvlTask *t;
    int i;

    g_ovl_ptr_5ae0 = p;
    g_ovl_ptr_5ae4 = p + 0x40000;
    g_ovl_ptr_5668 = p + 0x140000;
    res = g_ovl_res;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(res, 8, 0);
    fn_ovl_3de8(mgr, g_ovl_dat_0040, g_ovl_ptr_5ae0, 0x40000);

    ctx = &g_ovl_59b0;
    fn_ovl_3ec0(mgr, ctx, 1.2f, 0, 66, 0, 0);
    fn_ovl_15a0(-1, ctx->pos, 3);
    ctx->rot[1] = fn_ovl_1478(-1);
    p += 0x240000;
    fn_ovl_3648(p, res, g_ovl_dat_04f0);
    ctx->w110 = p;

    pos0p = pos0;
    MMI_COPY_LQ_A3(pos0p, ctx->pos);
    MMI_COPY_SQ_A3(pos0p);

    off[0] = 0.0f;
    off[1] = -20.0f;
    off[2] = -24.0f;
    off[3] = 1.0f;

    work = g_ovl_5670;
    for (i = 0; i < g_ovl_dat_0588.count; i++, work++) {
        work->w4C = fn_ovl_2098(i, 0);
        fn_ovl_2f88(i, work, g_ovl_dat_0540);
        fn_ovl_15a0(i, pos1, 3);
        pos0[1] = pos1[1];
        fn_ovl_4bf0(rot, pos0p, pos1);
        func_002DD128(m);
        func_002DD318(m, m, rot[1]);
        func_002DCE08(vec, m, off);
        func_002DD020(tmp, pos1, vec);
        func_002DCFD8(tmp, tmp, 20.0f);

        work->f20 = vec[0] / 20.0f;
        work->f24 = tmp[1] * 2.0f;
        work->f28 = vec[2] / 20.0f;
        work->f2C = 0.0f;
        work->f30 = 0.0f;
        work->f34 = (tmp[1] * -4.0f) / 20.0f;
        work->f38 = 0.0f;
        work->f3C = 0.0f;
        work->w40 = 76;
        work->w44 = 20;
        work->w48 = i;
        work->w50 = 0;

        t = fn_ovl_3b60((void *)fn_ovl_0fb0);
        t->w14 = work;
        fn_ovl_3d28(t);
    }

    shk = &g_ovl_5638;
    fn_ovl_5350(shk, 32);
    shk->f04 = 4.0f;
    shk->f08 = 2.0f;
    shk->f10 = 4.0f;
    shk->f14 = 2.0f;
    shk->f0C = 0.0f;
    shk->f18 = 0.0f;
    shk->h2C |= 3;
    shk->w24 = 76;
    f = &g_ovl_5618;

    f->w00 = 0;
    f->w04 = 80;
    f->w08 = 0;
    f->w0C = 71;
    fn_ovl_5248(f, 80);

    ovl_09342_0d50();
    fn_ovl_10d0(1);
    fn_ovl_2f88(-1, g_ovl_55f8, g_ovl_dat_0520);
    t = fn_ovl_3b60((void *)fn_ovl_0ed0);
    t->b18 = 2;
    fn_ovl_3d28(t);
    return 0;
}

void ovl_09342_0d50(void)
{
    float m[16];
    float inv[16];
    float pos[4];
    float off[4];
    float v0[4];
    float v1[4];
    OvlCtx *ctx = &g_ovl_59b0;
    int s;

    func_002DD128(m);
    func_002DD3C0(m, m, ctx->rot);
    MMI_COPY_LQ_A3(pos, ctx->pos);
    MMI_COPY_SQ_A3(pos);
    pos[1] = fn_ovl_19f0(-1);
    off[0] = 1.5f;
    off[1] = 0.0f;
    off[2] = -1.5f;
    off[3] = 1.0f;
    fn_ovl_4cf8(ctx->rot, pos, off);

    {
        register int sv __asm__("$3");
        float sc = 0.1f;
        float *dst;
        __asm__("" : "+f"(sc));
        dst = &m[12];
        __asm__("" : "+r"(dst) : "f"(sc));
        MIPS_MFC1(sv, sc);
        VU0_LQC2(1, 0, pos);
        VU0_QMTC2(2, sv);
        VU0_OP("vmulx.xyz $vf1, $vf1, $vf2x");
        VU0_SQC2(1, 0, dst);
    }

    func_002DCF48(inv, m);

    v0[0] = -7.9f;
    v0[1] = 0.0f;
    v0[2] = -7.9f;
    v0[3] = 1.0f;
    v1[0] = 7.8f;
    v1[1] = 0.0f;
    v1[2] = 7.8f;
    v1[3] = 1.0f;

    func_00173B90(g_ovl_ptr_5668, 0x100000, 0, 0, inv, v0, v1, 1);
    func_00173CD8(g_ovl_ptr_5668, v0, v1, 256, 0x10401C0UL, 0x00FF000000FF0000UL, 1.0f);
}
