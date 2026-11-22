#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x08];
    void *p110;
    u8 pad114[0x04];
    s32 w118;
    u8 pad11C[0x14];
} OvlCtx;

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
} Obj5820;

typedef struct {
    u8 pad00[0x40];
} OvlFade;

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
} Obj5780;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj58D0;

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
extern u8 D_01B00568[];
extern u8 D_01B00580[];
extern u8 D_01B009C0[];
extern u8 D_01B04198[];
extern Obj5780 D_01B05780;
extern Obj5820 D_01B05820;
extern OvlFade D_01B05850[];
extern Obj58D0 D_01B058D0;
extern OvlCtx D_01B05930[];
extern float D_01B05CC0;
extern s32 D_01B05CC4;
extern OvlMgr D_01B05CC8;
extern OvlCtx D_01B05D10[];
extern u8 *D_01B06300;
extern u8 *D_01B06304;
extern u8 D_01B0C030[];
extern u8 D_01BC9940[];

extern void *func_002B49A0(void *, int, int);

extern float func_01B011B0(int);
extern void func_01B012D8(int, Vec4 *, int);
extern int func_01B01750(int);
extern int func_01B01C18(int);
extern void func_01B03108(int);
extern void func_01B03380(void *, void *, void *);
extern void func_01B03588(void *, int, int);
extern OvlTask *func_01B03898(void *);
extern void func_01B03A60(void *);
extern void func_01B03B20(void *, void *, void *, int);
extern int func_01B03BF8(void *, void *, float, int, int, int, void *);
extern int func_01B03CD8(void *, void *);
extern void func_01B04F80(void *, int);
extern void func_01B050F0(void *, int);
extern void func_01B053D0(void *, float, float, int, int);
extern void func_01B05608(void *, void *, void *, int);

void ovl_09207_0e30(OvlTask *a0);
void ovl_09207_0eb0(OvlCtx *a0);

static inline void copy_vec(Vec4 *dst, Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09207_09e0(void)
{
    u8 *p = D_01BC9940;
    OvlMgr *mgr = &D_01B05CC8;
    OvlCtx *ctx;
    Vec4 pos0;
    Vec4 pos1;
    /* DEBT(FAKE): pin &pos1 to s4 so mgr gets s3 */
    register Vec4 *pos1p __asm__("$20");
    float rot;
    int i;
    int delay;
    OvlTask *t;

    D_01B06304 = p + 0x40000;
    D_01B06300 = p;
    mgr->w2C = func_002B49A0(D_01B0C030, 8, 0);
    func_01B03B20(mgr, D_01B00040, D_01B06300, 0x40000);
    rot = func_01B011B0(0);
    if (func_01B01750(0) == 0x108C) {
        func_01B012D8(0, &pos0, 5);
    } else {
        func_01B012D8(0, &pos0, 0);
    }

    ctx = &D_01B05D10[1];
    func_01B03BF8(mgr, ctx, 0.08f, 1, 0, 0, 0);
    copy_vec(&ctx->pos, &pos0);
    ctx->fC4 = rot;
    ctx->pos.y -= 14.0f;
    D_01B05CC0 = ctx->pos.y;
    ctx->p104 = (void *)ovl_09207_0eb0;
    ctx->pos.y -= 150.0f;
    pos1p = &pos1;
    MMI_COPY_LQ_A3(pos1p, &ctx->pos);
    MMI_COPY_SQ_A3(pos1p);

    ctx = &D_01B05D10[0];
    func_01B03BF8(mgr, ctx, 0.06f, 0, 16, 0, D_01B04198);
    copy_vec(&ctx->pos, &pos0);
    ctx->fC4 = rot;
    ctx->pos.y -= 14.0f;
    {
        u8 *buf = p + 0x140000;
        func_01B03380(buf, D_01B0C030, D_01B00580);
        ctx->p110 = buf;
    }

    if (func_01B01C18(0) == 0) {
        ctx = &D_01B05D10[3];
        func_01B03BF8(mgr, ctx, 0.06f, 3, 16, 0, 0);
        copy_vec(&ctx->pos, &pos0);
        ctx->fC4 = rot;
        ctx->pos.y -= 0.5f;

        ctx = &D_01B05D10[4];
        func_01B03BF8(mgr, ctx, 0.08f, 4, 14, 0, 0);
        copy_vec(&ctx->pos, &pos0);
        ctx->fC4 = rot;
        ctx->pos.y -= 14.0f;
    }

    pos1.y += 75.0f;
    ctx = D_01B05930;
    delay = 8;
    for (i = 0; i < 3; i++, ctx++) {
        delay += 2;
        pos1.y += 18.75f;
        func_01B03BF8(mgr, ctx, 0.08f, 2, delay, 0, 0);
        ctx->fC4 = rot;
        copy_vec(&ctx->pos, pos1p);
    }

    D_01B05CC4 = 14;
    func_01B050F0(&D_01B05820, 12);
    D_01B05820.f04 = 1.0f;
    D_01B05820.f08 = 1.0f;
    D_01B05820.w0C = 0;
    D_01B05820.f10 = 4.0f;
    D_01B05820.f14 = 4.0f;
    D_01B05820.w18 = 0;
    D_01B05820.w24 = 16;
    D_01B05820.h2C |= 3;

    func_01B053D0(&D_01B05850[0], 1.0f, 0.5f, 8, 0);
    func_01B053D0(&D_01B05850[1], 0.5f, 1.0f, 16, 55);
    func_01B03108(1);

    D_01B05780.b82 = 128;
    D_01B05780.b81 = 128;
    D_01B05780.b80 = 128;
    D_01B05780.b83 = 96;
    D_01B05780.b84 = 128;
    D_01B05780.b85 = 128;
    D_01B05780.b86 = 128;
    D_01B05780.b87 = 0;
    D_01B05780.w88 = 16;
    D_01B05780.b98 = 72;
    D_01B05780.b99 = 0;
    func_01B04F80(&D_01B05780, 32);

    func_01B05608(&D_01B058D0, D_01B0C030, D_01B00568, 1);
    D_01B058D0.w54 = 0;
    t = func_01B03898((void *)ovl_09207_0e30);
    t->b18 = 2;
    func_01B03A60(t);
    return 0;
}

void ovl_09207_0e30(OvlTask *a0)
{
    if (D_01B05CC4 > 0) {
        if (--D_01B05CC4 == 0) {
            func_01B03588(D_01B0C030, 0, 0);
        }
    }
    if (func_01B03CD8(&D_01B05CC8, D_01B06304) == 1) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B009C0;
    }
}

void ovl_09207_0eb0(OvlCtx *a0)
{
    if (a0->w118 < 16) {
        a0->pos.y += 9.375f;
    } else if (a0->w118 < 18) {
        float d = (float)a0->w118 / 18.0f;
        a0->pos.y += d + d;
    } else {
        a0->p104 = 0;
    }
}
