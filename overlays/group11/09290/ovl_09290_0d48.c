/* 09290 arc update + splash callback (724 B, 2 funcs). */

#include "common.h"

typedef struct {
    float p0[4];
    float p1[4];
    float t;
    int w24;
    int w28;
} OvlArc;

typedef struct {
    u8 pad00[0x60];
    float s60[3];
    u8 pad6C[0x54];
    float rot[4];
    float pos[4];
    u8 padE0[0x2C];
    void *w10C;
} OvlCtx;

typedef struct {
    u8 pad00[0x24];
    void *w24;
} OvlCbTbl;

typedef struct {
    u8 pad00[0x0C];
    int w0C;
    u8 pad10[0xD0];
    float pos[3];
} OvlPart;

extern OvlCbTbl g_ovl_dat_0568;
extern OvlArc g_ovl_5110;
extern float g_ovl_5140;
extern u8 g_ovl_5f90[12];
extern int g_ovl_5f9c;
extern u8 g_ovl_mgr[];
extern OvlCtx g_ovl_6110;
extern OvlCtx g_ovl_6240;

extern void func_002DCE08(float *, float *, float *);
extern void func_002DD0B0(float *, float *);
extern void func_002DD128(float *);
extern void func_002DD3C0(float *, float *, float *);
extern void func_002DD948(float *, float *);
extern void func_002DD968(float *, float *, float *, float);

extern void fn_ovl_0ee8(OvlPart *);
extern OvlCtx *fn_ovl_1020(void);
extern void fn_ovl_1428(int, void *, int);
extern void fn_ovl_3a68(void *);
extern int fn_ovl_3d48(void *, void *, float, int, int, int, void *);
extern float fn_ovl_4830(float, float, float, float);

void ovl_09290_0d48(void *task)
{
    float tmp[4];
    OvlArc *arc = &g_ovl_5110;
    OvlCtx *ctx;

    if (arc->w28 != 0) {
        arc->w28--;
        return;
    }

    if (arc->w24 > 0) {
        arc->w24--;
    }
    if (arc->w24 == 0) {
        u8 *q;
        int i;

        ctx = &g_ovl_6240;
        fn_ovl_3d48(g_ovl_mgr, ctx, 0.23f, 2, 0, 0, 0);
        func_002DD0B0(ctx->pos, arc->p0);
        ctx->w10C = &g_ovl_dat_0568;
        g_ovl_dat_0568.w24 = (void *)fn_ovl_0ee8;
        fn_ovl_1428(0, tmp, 0);
        g_ovl_5140 = tmp[1];
        for (i = 0; i < 12; i++) {
            g_ovl_5f90[i] = 0;
        }
        arc->w24 = -1;
    }

    ctx = &g_ovl_6110;
    func_002DD968(ctx->pos, arc->p0, arc->p1, arc->t);
    ctx->pos[1] -= fn_ovl_4830(0.0f, 30.0f, 0.0f, arc->t);
    arc->t += 0.05f;
    if (arc->t >= 1.0f) {
        g_ovl_5f9c = 1;
        fn_ovl_3a68(task);
    }
}

void ovl_09290_0ee8(OvlPart *part)
{
    float m[16];
    float v[4];
    float *pos = part->pos;
    OvlCtx *ctx = &g_ovl_6240;

    func_002DD128(m);
    m[0] = ((volatile float *)ctx->s60)[0];
    m[5] = ((volatile float *)ctx->s60)[1];
    m[10] = ((volatile float *)ctx->s60)[2];
    func_002DD3C0(m, m, ctx->rot);
    func_002DD948(&m[12], ctx->pos);

    v[0] = part->pos[0];
    v[1] = pos[1];
    v[2] = pos[2];
    v[3] = 1.0f;
    func_002DCE08(v, m, v);

    if (v[1] >= g_ovl_5140) {
        ctx = fn_ovl_1020();
        if (ctx != 0) {
            fn_ovl_3d48(g_ovl_mgr, ctx, 0.3f, 3, 0, 0, 0);
            ctx->pos[0] = v[0];
            ctx->pos[1] = g_ovl_5140 - 2.0f;
            ctx->pos[2] = v[2];
        }
        part->w0C = (int)0xFFFF0000;
    }
}
