/* 09343 effect init (916 B). */

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
    u8 padE0[0x30];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    int pad00;
    int count;
} OvlCount;

typedef struct {
    float f00;
    float f04;
    u8 pad08[0x08];
    float f10;
    float f14;
    u8 pad18[0x28];
} OvlLight;

typedef struct {
    void *w00;
    int w04;
    int w08;
    int w0C;
    u8 pad10[0x0C];
} OvlFade;

typedef struct {
    u8 pad00[0x54];
    int w54;
} OvlObj5d70;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_04f0[];
extern u8 g_ovl_dat_0508[];
extern u8 g_ovl_dat_0520[];
extern u8 g_ovl_dat_0538[];
extern OvlCount g_ovl_dat_0590;
extern u8 g_ovl_dat_4040[];
extern u8 g_ovl_5308[];
extern OvlCtx g_ovl_5330[];
extern OvlFade g_ovl_5cb0[];
extern OvlLight g_ovl_5cf0[];
extern OvlObj5d70 g_ovl_5d70;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_5f40;
extern void *g_ovl_ptr_6070;
extern void *g_ovl_ptr_6074;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0d20(void);
extern int fn_ovl_0f10(int);
extern float fn_ovl_1038(int);
extern void fn_ovl_1160(int, void *, int);
extern void fn_ovl_2b48(int, void *, void *);
extern void fn_ovl_2f90(int);
extern void fn_ovl_3208(void *, void *, void *);
extern void *fn_ovl_3720(void *);
extern void fn_ovl_38e8(void *);
extern void fn_ovl_39a8(void *, void *, void *, int);
extern int fn_ovl_3a80(void *, void *, float, int, int, int, void *);
extern void fn_ovl_47b0(void *, void *, void *);
extern float fn_ovl_4958(void *, void *);
extern void fn_ovl_4e08(void *, int);
extern void fn_ovl_4f58(void *, float, float, int, int);
extern void fn_ovl_5190(void *, void *, void *, int);

int ovl_09343_0988(void)
{
    float pos0[4];
    float pos1[4];
    float vec[4];
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    OvlLight *l;
    OvlFade *f;
    register u8 *sub __asm__("$16");
    int i;

    g_ovl_ptr_6070 = p;
    g_ovl_ptr_6074 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_39a8(mgr, g_ovl_dat_0040, g_ovl_ptr_6070, 0x40000);

    ctx = &g_ovl_5f40;
    fn_ovl_3a80(mgr, ctx, 0.75f, 1, 27, 0, 0);
    fn_ovl_1160(-1, ctx->pos, 3);
    ctx->fC4 = fn_ovl_1038(-1);
    ctx->pos[1] -= 8.0f;
    sub = p + 0x140000;
    fn_ovl_3208(sub, g_ovl_res, g_ovl_dat_0508);
    ctx->w110 = sub;

    MMI_COPY_LQ_A3(pos0, ctx->pos);
    MMI_COPY_SQ_A3(pos0);
    pos0[1] = 0.0f;

    ctx = g_ovl_5330;
    for (i = 0; i < g_ovl_dat_0590.count; i++, ctx++) {
        fn_ovl_1160(i, pos1, 0);
        pos1[1] = 0.0f;
        fn_ovl_47b0(vec, pos1, pos0);
        fn_ovl_3a80(mgr, ctx, 0.2f, 0, (int)(fn_ovl_4958(pos0, pos1) * 0.8f), 0, g_ovl_dat_4040);
        fn_ovl_1160(i, ctx->pos, 1);
        ctx->fC4 = vec[1];
        ctx->w120 = fn_ovl_0f10(i);
        sub = p + ((i << 6) + 0x140040);
        fn_ovl_3208(sub, g_ovl_res, g_ovl_dat_0520);
        ctx->w110 = sub;
    }

    l = g_ovl_5cf0;
    fn_ovl_4f58(l, 1.0f, 0.5f, 30, 0);
    l->f10 = 0.65f;
    l->f14 = 0.65f;
    l++;
    fn_ovl_4f58(l, 0.5f, 1.0f, 16, 110);
    l->f00 = 0.65f;
    l->f04 = 0.65f;

    fn_ovl_2f90(1);

    f = g_ovl_5cb0;
    f->w08 = 80;
    f->w04 = 0;
    f->w0C = 0;
    f->w00 = 0;
    fn_ovl_4e08(f, 30);
    f++;
    f->w00 = 0;
    f->w04 = 80;
    f->w08 = 0;
    f->w0C = 110;
    fn_ovl_4e08(f, 16);

    fn_ovl_5190(&g_ovl_5d70, g_ovl_res, g_ovl_dat_04f0, 1);
    g_ovl_5d70.w54 = -1;
    fn_ovl_2b48(-1, g_ovl_5308, g_ovl_dat_0538);
    fn_ovl_38e8(fn_ovl_3720((void *)fn_ovl_0d20));
    return 0;
}
