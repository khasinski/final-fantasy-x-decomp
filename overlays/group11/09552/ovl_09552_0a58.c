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
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    u8 padE0[0x08];
    float fE8;
    u8 padEC[0x18];
    void *p104;
    u8 pad108[0x08];
    void *p110;
    u8 pad114[0x1C];
} OvlCtx;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    u8 pad18[0x90];
    s32 wA8;
    u8 padAC[0x04];
    u16 hB0;
    u8 padB2[0x0E];
} Obj59F0;

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
    s32 w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
} Obj5B70;

typedef struct {
    u8 pad00[0x04];
    float f04;
    float f08;
    s32 w0C;
    float f10;
    float f14;
    s32 w18;
    u8 pad1C[0x08];
    s32 w24;
    u8 pad28[0x04];
    u16 h2C;
    u8 pad2E[0x02];
} Obj5C10;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj5C40;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
    u8 b18;
} OvlTask;

extern u8 D_01B00040[];
extern u8 D_01B005B8[];
extern u8 D_01B005E0[];
extern u8 D_01B005F8[];
extern u8 D_01B00A38[];
extern u8 D_01B04338[];
extern u8 D_01B059C8[];
extern Obj59F0 D_01B059F0[];
extern Obj5B70 D_01B05B70;
extern Obj5C10 D_01B05C10;
extern Obj5C40 D_01B05C40;
extern s32 D_01B05CA0;
extern s32 D_01B05CA4;
extern s32 D_01B05CA8;
extern OvlMgr D_01B05CB0;
extern OvlCtx D_01B05CF0[];
extern u8 *D_01B061B0;
extern u8 *D_01B061B4;
extern u8 D_01B0B9B0[];
extern u8 D_01BADF00[];

extern s32 func_00297C28(void *, int, int, int, int, int, int);
extern void func_00297CE8(s32);
extern void *func_002B49A0(void *, int, int);

extern void *func_01B012C0(int);
extern float func_01B01350(int);
extern void func_01B01478(int, Vec4 *, int);
extern void func_01B01650(int, Vec4 *);
extern float func_01B017E8(int);
extern int func_01B01DB8(int, int, int);
extern int func_01B01E78(int);
extern void func_01B02E60(int, void *, void *);
extern int func_01B02F18(void *);
extern void func_01B031B8(void *, int);
extern void func_01B03520(void *, void *, void *);
extern void func_01B03728(void *, int, int);
extern OvlTask *func_01B03A38(void *);
extern void func_01B03C00(OvlTask *);
extern void func_01B03CC0(void *, void *, void *, int);
extern void func_01B03D98(void *, void *, float, int, int, int, void *);
extern int func_01B03E78(void *, void *);
extern void func_01B04BD0(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B05120(void *, int, Vec4 *, int, float, float, float);
extern void func_01B05448(void *, int);
extern void func_01B055B8(void *, int);
extern void func_01B05850(void *, void *, void *, int);

void ovl_09552_0f30(OvlTask *a0);
void ovl_09552_1078(OvlCtx *a0);

static inline void copy_vec(Vec4 *dst, Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09552_0a58(void)
{
    u8 *p = D_01BADF00;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    OvlTask *t;
    int delay;

    {
        register u8 *p4 __asm__("$3") = p + 0x40000;
        D_01B061B0 = p;
        D_01B061B4 = p4;
    }
    res = D_01B0B9B0;
    mgr = &D_01B05CB0;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03CC0(mgr, D_01B00040, D_01B061B0, 0x40000);

    v10.x = 0.0f;
    v10.y = func_01B01350(-1);
    v10.z = 0.0f;

    ctx = &D_01B05CF0[3];
    func_01B03D98(mgr, ctx, 0.01f, 3, 53, 0, 0);
    func_01B01478(-1, &ctx->pos, 0);
    ctx->fC4 = v10.y;
    ctx->pos.y -= 0.5f;
    ctx->fE8 = -4.0f;

    func_01B01478(0, &v00, 3);
    v20.x = 0.0f;
    v20.y = 0.0f;
    v20.z = func_01B017E8(0) + 32.0f;
    func_01B04BD0(&v10, &v00, &v20);

    func_01B05120(&D_01B059F0[0], -1, &v00, 27, 0.2f, 1.0f, 1.0f);
    D_01B05CA8 = 120;
    D_01B059F0[0].w14 = 1;
    D_01B059F0[0].wA8 = 56;
    D_01B059F0[1].hB0 = 0;

    if (func_01B01DB8(0, 1, 56) == 0) {
        u8 *buf;
        ctx = &D_01B05CF0[1];
        func_01B03D98(mgr, ctx, 0.015f, 1, 83, 0, D_01B04338);
        func_01B01478(0, &ctx->pos, 3);
        copy_vec(&ctx->pos, &v00);
        ctx->fC4 = v10.y;
        ctx->pos.y -= 0.5f;
        ctx->fE8 = -35.0f;
        buf = p + 0x140000;
        func_01B03520(buf, res, D_01B005E0);
        ctx->p110 = buf;
        delay = 83;
    } else {
        u8 *buf;
        ctx = &D_01B05CF0[0];
        func_01B03D98(mgr, ctx, 0.015f, 0, 80, 0, D_01B04338);
        func_01B01478(0, &ctx->pos, 4);
        delay = 80;
        ctx->fC4 = v10.y;
        ctx->p104 = (void *)ovl_09552_1078;
        ctx->pos.x = v00.x;
        ctx->pos.z = v00.z;
        ctx->fE8 = -35.0f;
        buf = p + 0x140000;
        func_01B03520(buf, res, D_01B005E0);
        ctx->p110 = buf;

        ctx = &D_01B05CF0[2];
        func_01B03D98(mgr, ctx, 0.015f, 2, 83, 0, 0);
        func_01B01478(-1, &ctx->pos, 3);
        ctx->fC4 = v10.y;
        copy_vec(&ctx->pos, &v00);
        ctx->pos.y -= 0.5f;
        ctx->fE8 = -32.0f;
    }

    {
        register int n83 __asm__("$17") = 83;
        u8 *res2;
        __asm__("" : "+r"(n83));
        func_01B055B8(&D_01B05C10, 20);
        res2 = D_01B0B9B0;
        {
            Obj5C10 *c = &D_01B05C10;
            register u16 h __asm__("$6") = *(volatile u16 *)&c->h2C;
            register Obj5B70 *b __asm__("$2");
            register float f2 __asm__("$f2");
            register float f1 __asm__("$f1");
            register float f0 __asm__("$f0");
            register u8 c128 __asm__("$3");
            register u8 c72 __asm__("$7");
            register Obj5B70 *a0b __asm__("$4");
            register int c20 __asm__("$5");
            __asm__ volatile("" : "+r"(h));
            b = &D_01B05B70;
            f2 = 1.0f;
            __asm__ volatile("" : "+r"(b), "+f"(f2));
            f1 = 0.5f;
            __asm__ volatile("" : "+f"(f1));
            h |= 3;
            __asm__ volatile("" : "+r"(h));
            f0 = 3.0f;
            __asm__ volatile("" : "+f"(f0));
            c128 = 128;
            __asm__ volatile("" : "+r"(c128));
            *(volatile s32 *)&c->w24 = n83;
            __asm__ volatile("");
            c72 = 72;
            __asm__ volatile("" : "+r"(c72));
            *(volatile float *)&c->f08 = f1;
            __asm__ volatile("");
            a0b = b;
            __asm__ volatile("" : "+r"(a0b));
            *(volatile float *)&c->f10 = f0;
            __asm__ volatile("");
            c20 = 20;
            __asm__ volatile("" : "+r"(c20));
            *(volatile float *)&c->f14 = f2;
            *(volatile u16 *)&c->h2C = h;
            *(volatile u8 *)&b->b83 = c128;
            *(volatile u8 *)&b->b98 = c72;
            *(volatile float *)&c->f04 = f2;
            *(volatile s32 *)&c->w0C = 0;
            *(volatile s32 *)&c->w18 = 0;
            *(volatile s32 *)&b->w88 = delay;
            *(volatile u8 *)&b->b82 = c128;
            *(volatile u8 *)&b->b81 = c128;
            *(volatile u8 *)&b->b80 = c128;
            *(volatile u8 *)&b->b87 = 0;
            *(volatile u8 *)&b->b86 = 0;
            *(volatile u8 *)&b->b85 = 0;
            *(volatile u8 *)&b->b84 = 0;
            __asm__ volatile("");
            b->b99 = 0;
            func_01B05448(a0b, c20);
        }

        func_01B05850(&D_01B05C40, res2, D_01B005B8, 1);
        D_01B05C40.w54 = -1;
        D_01B05CA0 = func_00297C28(func_01B012C0(-1), 0, 0, 0, 0, 0, 0);
        D_01B05CA4 = n83;
        if (func_01B01E78(-1) == 1) {
            func_01B03728(res2, 0, 0);
        }
    }
    func_01B02E60(-1, D_01B059C8, D_01B005F8);
    t = func_01B03A38((void *)ovl_09552_0f30);
    t->b18 = 2;
    func_01B03C00(t);
    return 0;
}

void ovl_09552_0f30(OvlTask *a0)
{
    Vec4 v00;
    int r;

    if (D_01B05CA8 > 0) {
        if (--D_01B05CA8 == 0) {
            func_01B01650(-1, &v00);
            func_01B05120(&D_01B059F0[1], -1, &v00, 19, 0.1f, 1.2f, 1.0f);
            D_01B059F0[1].w14 = 1;
        }
    }
    if (D_01B05CA4 > 0) {
        if (--D_01B05CA4 == 0) {
            func_00297CE8(D_01B05CA0);
        }
    }
    r = func_01B02F18(D_01B059C8);
    if (func_01B03E78(&D_01B05CB0, D_01B061B4) == 1 && r == 1 && D_01B05CA4 == 0 && (D_01B059F0[1].hB0 & 0x8000)) {
        func_01B031B8(D_01B059C8, 0);
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00A38;
    }
}

void ovl_09552_1078(OvlCtx *a0)
{
    Vec4 v00;
    func_01B01478(0, &v00, 4);
    a0->pos.y = v00.y;
    a0->p104 = 0;
}
