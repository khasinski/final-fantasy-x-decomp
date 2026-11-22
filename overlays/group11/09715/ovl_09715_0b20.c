/* 09715/09757 camera-locked sprite update, spawn, and cleanup (420 B span / 416 B code, 3 funcs). */

#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad00[0x60];
    float f60;
    float f64;
    float f68;
    float f6C;
    u8 pad70[0x10];
    Vec4 mat80[4];
    u8 padC0[0x10];
    Vec4 posD0;
    u8 padE0[0x24];
    void *fn104;
    u8 pad108[0x1E];
    u8 b126;
} OvlCtx;

typedef struct {
    u8 pad00[0x56];
    u8 b56;
} OvlScript;

extern u8 g_ovl_mgr[];
extern OvlCtx g_ovl_ctx;
extern int g_ovl_w6a14;
extern int g_ovl_w6a18;

extern void fn_ovl_2758(void *, void *);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern float fn_ovl_5510(void);
extern void func_00117E28(int);
extern void fn_ovl_39a8(void *, void *, int, int, float, int, int);
extern int func_002B2E10(void *, int, int, int);
extern void fn_ovl_0920(void);
extern void fn_ovl_3e78(void *);
extern void func_002B2F18(int);

void ovl_09715_0b20(OvlCtx *ctx)
{
    Vec4 mat0[4];
    Vec4 mat1[4];
    Vec4 v;
    float s;

    fn_ovl_2758(mat0, mat1);
    func_002DCF48(ctx->mat80, mat1);
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 5.0f;
    v.w = 1.0f;
    func_002DCE08(&ctx->posD0, ctx->mat80, &v);
    ctx->posD0.w = 1.0f;
    s = fn_ovl_5510() * 0.003f;
    ctx->f6C = s;
    ctx->f68 = s;
    ctx->f64 = s;
    ctx->f60 = s;
}

void ovl_09715_0bd0(void)
{
    OvlCtx *ctx;

    func_00117E28(1);
    ctx = &g_ovl_ctx;
    fn_ovl_39a8(g_ovl_mgr, ctx, 0, 30, 0.003f, 0, 0);
    ctx->fn104 = (void *)ovl_09715_0b20;
    {
        /* DEBT(FAKE): pin 2 to v0 to match register allocation */
        register int two __asm__("$2") = 2;
        ctx->b126 = two;
    }
    g_ovl_w6a14 = func_002B2E10((void *)fn_ovl_0920, 0, 0, 0);
}

void ovl_09715_0c60(OvlScript *scr)
{
    if (g_ovl_w6a18 == 1) {
        fn_ovl_3e78(g_ovl_mgr);
        func_002B2F18(g_ovl_w6a14);
        g_ovl_w6a14 = -1;
        scr->b56 = 1;
    }
}
