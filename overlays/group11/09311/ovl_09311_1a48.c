#include "common.h"
#include "vu0.h"

#define VEC_COPY(dst, src) \
    MMI_COPY_LQ_A3((dst), (src)); \
    MMI_COPY_SQ_A3((dst))

typedef struct {
    int w00;
    int w04;
} Work7F0;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0[4];
    u8 padE0[0x50];
} OvlCtx;

typedef struct {
    u8 pad00[0x40];
    float f40[4];
    float f50[4];
    int w60;
    float f64;
    float f68;
    int w6C;
} OvlWork65C0;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
} OvlWork6630;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

extern u8 D_01B9D100[];
extern u8 D_01B0BD20[];
extern u8 D_01B00040[];
extern u8 D_01B00770[];
extern u8 D_01B007A0[];
extern Work7F0 D_01B007F0;
extern int D_01B06590;
extern u8 D_01B06598[];
extern OvlWork65C0 D_01B065C0;
extern OvlWork6630 D_01B06630;
extern u8 D_01B066D0[];
extern float D_01B06710;
extern int D_01B06714;
extern int D_01B06718;
extern int D_01B0671C;
extern void *D_01B06720;
extern OvlMgr D_01B06728;
extern OvlCtx D_01B06770[];
extern void *D_01B069D0;
extern void *D_01B069D4;

extern void *func_002B49A0(void *, int, int);
extern void *func_002B2E10(void *, int, int, int);
extern void func_01B02420(int);
extern void func_01B04FB8(void *, void *, void *, int);
extern void func_01B05090(void *, void *, int, float, int, int, void *);
extern void func_01B02770(int, void *, int);
extern float func_01B02648(int);
extern void func_01B039E0(int, void *);
extern void func_01B06418(void *, int);
extern void func_01B04818(void *, void *, void *);
extern void func_01B04158(int, void *, void *);
extern OvlTask *func_01B04D30(void *);
extern void func_01B04EF8(OvlTask *);
extern void func_01B01D20(void);
extern void func_01B01D28(void);
extern void func_01B020A0(void);

int func_01B01A48(void)
{
    u_long128 vec;
    u8 *p = D_01B9D100;
    u8 *res;
    register OvlMgr *mgr __asm__("s0");
    register OvlCtx *ctx __asm__("s1");
    register float *d0 __asm__("s2");
    OvlWork65C0 *w;
    OvlTask *t;

    D_01B069D0 = p;
    D_01B069D4 = p + 0x40000;
    D_01B007F0.w00 = 0x14;
    D_01B007F0.w04 = 0;
    func_01B02420(D_01B06590);

    res = D_01B0BD20;
    mgr = &D_01B06728;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B04FB8(mgr, D_01B00040, D_01B069D0, 0x40000);

    ctx = D_01B06770;
    func_01B05090(mgr, ctx, 0, 0.55f, 0, 0, 0);
    d0 = ctx->fD0;
    func_01B02770(-1, d0, 0);
    ctx->fC4 = func_01B02648(-1);
    ctx->fD0[1] += 35.0f;
    VEC_COPY(&vec, d0);

    ctx++;
    func_01B05090(mgr, ctx, 1, 0.7f, 0xF0, 0, 0);
    __asm__("");
    d0 = ctx->fD0;
    {
        register float *a1 __asm__("$5") = d0;
        __asm__("" : : "r"(a1));
        func_01B02770(-1, a1, 0);
    }
    ctx->fC4 = func_01B02648(-1);
    VEC_COPY(d0, &vec);

    w = &D_01B065C0;
    func_01B039E0(-1, w);
    w->f40[0] = 0.0f;
    w->f40[1] = ctx->fC4;
    w->f40[2] = 0.0f;
    w->f40[3] = 0.0f;
    func_01B02770(-1, w->f50, 0);
    {
        register float f64 __asm__("$f0") = 1.0f;
        register int w6c __asm__("$4") = 0x70;
        register int c80 __asm__("$6");
        register int c48 __asm__("$8");
        register int cf0 __asm__("$7");

        w->f64 = f64;
        w->w6C = w6c;
        w->f68 = -1.0f / 90.0f;
        D_01B06630.b82 = 0xFF;
        D_01B06630.b81 = 0xFF;
        D_01B06630.b80 = 0xFF;
        c80 = 0x80;
        D_01B06630.b83 = c80;
        D_01B06630.b87 = 0;
        D_01B06630.b86 = 0;
        D_01B06630.b85 = 0;
        D_01B06630.b84 = 0;
        c48 = 0x48;
        D_01B06630.b98 = c48;
        w->w60 = 0;
        cf0 = 0xF0;
        D_01B06630.w88 = cf0;
        D_01B06630.b99 = 0;
    }
    func_01B06418(&D_01B06630, 0x40);

    D_01B06710 = 0.085f;
    D_01B06714 = 0;
    D_01B06718 = 0;
    D_01B0671C = 0;
    D_01B06720 = func_002B2E10((void *)func_01B020A0, 0, 0, 0);
    func_01B04818(D_01B066D0, res, D_01B00770);
    func_01B04158(-1, D_01B06598, D_01B007A0);

    t = func_01B04D30((void *)func_01B01D20);
    t->b18 = 1;
    func_01B04EF8(t);

    t = func_01B04D30((void *)func_01B01D28);
    t->b18 = 2;
    func_01B04EF8(t);

    return 0;
}
