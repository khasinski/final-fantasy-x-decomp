#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x0C];
    s32 w0C;
} Cfg824;

typedef struct {
    s32 w00;
    s32 w04;
} Cfg6D0;

typedef struct {
    u8 pad00[0x40];
} OvlFade;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} OvlCtx;

extern u8 D_01B96640[];
extern u8 D_01B96640_a[];
extern void *D_01B07040;
extern void *D_01B07044;
extern OvlMgr D_01B04A00;
extern OvlCtx D_01B04A40[];
extern u8 D_01B0DCB0[];
extern u8 D_01B00040[];
extern s32 D_01B006C0[];
extern u8 D_01B006A8[];
extern Cfg6D0 D_01B006D0[];
extern Cfg824 D_01B00824;
extern u8 D_01B04180[];
extern u8 D_01B04958[];
extern OvlFade D_01B04980[];
extern u8 D_01B00E70[];

extern void *func_002B49A0(void *, s32, s32);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B03B08(void *, void *, void *, s32);
extern void func_01B01908(Vec4 *);
extern s32 func_01B01738(s32);
extern float func_01B01710(s32);
extern void func_01B012C0(s32, Vec4 *, s32);
extern float func_01B01198(s32);
extern void func_01B03BE0(void *, void *, s32, s32, float, s32, void *);
extern void func_01B03368(void *, void *, void *);
extern void func_01B02CA8(s32, void *, void *);
extern void func_01B04710(void *, float, float, s32, s32);
extern void func_01B030F0(s32);
extern void *func_01B03880(void *);
extern void func_01B03A48(void *);

s32 ovl_09486_0b18(void)
{
    Vec4 v0;
    Vec4 v1;
    u8 *p = D_01B96640;
    OvlMgr *mgr = &D_01B04A00;
    register OvlCtx *ctx __asm__("$17");
    OvlFade *fade;
    s32 id;
    s32 found;
    s32 *tbl;
    float ang;
    s32 i, n;
    s32 delay;
    s32 d;

    D_01B07044 = p + 0x40000;
    D_01B07040 = p;
    mgr->w2C = func_002B49A0(D_01B0DCB0, 8, 0);
    func_01B03B08(mgr, D_01B00040, D_01B07040, 0x40000);

    func_01B01908(&v0);
    id = func_01B01738(0);
    tbl = D_01B006C0;
    found = 0;
    for (; *tbl != -1; tbl++) {
        if (*tbl == id) {
            found = 1;
            break;
        }
    }
    if (!found) {
        v0.y = func_01B01710(0) - 40.0f;
    } else {
        func_01B012C0(0, &v0, 5);
    }

    ang = func_01B01198(-1);
    delay = 0;
    ctx = D_01B04A40;
    MMI_COPY_LQ_A3(&v1, &v0);
    MMI_COPY_SQ_A3(&v1);
    n = D_01B00824.w0C;
    for (i = 0; i < n; i++) {
        float s;
        u8 *q;
        s32 off;

        s = (func_002B3DF8(0.2f) + 1.0f) * 0.27f;
        func_01B03BE0(mgr, ctx, 0, delay, s, 30, D_01B04180);
        {
            register Vec4 *vp __asm__("$3") = &ctx->pos;
            MMI_COPY_LQ_A3(vp, &v1);
            MMI_COPY_SQ_A3(vp);
        }
        ctx->fC4 = ang;
        off = (i << 6) + 0x140000;
        q = p + off;
        func_01B03368(q, D_01B0DCB0, D_01B006A8);
        ctx->p110 = q;
        ctx++;

        func_01B03BE0(mgr, ctx, 1, delay, s, 0, 0);
        {
            register Vec4 *vp __asm__("$3") = &ctx->pos;
            MMI_COPY_LQ_A3(vp, &v1);
            MMI_COPY_SQ_A3(vp);
        }
        ctx->fC4 = ang;
        delay += 75;
        ctx++;

        v1.x = v0.x + func_002B3DB0(10.0f);
        v1.y = v0.y - func_002B3DF8(10.0f);
        v1.z = v0.z + func_002B3DB0(10.0f);
    }

    d = delay - 75;
    D_01B006D0[0].w04 = d;
    func_01B02CA8(-1, D_01B04958, (d > 0) ? &D_01B006D0[0] : &D_01B006D0[1]);

    fade = D_01B04980;
    func_01B04710(&fade[0], 1.0f, 1.5f, 8, 0);
    func_01B04710(&fade[1], 1.5f, 1.0f, 16, delay + 5);
    func_01B030F0(1);
    func_01B03A48(func_01B03880(D_01B00E70));
    return 0;
}
