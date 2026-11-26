/* tu_313 0x291120-0x2931b0: medium; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", pppKeOfsPt);

void func_002918F0(char *base, ScriptCtx *ctx) {
    Wkf0f4f8f2C *w = SLOT_WORK(Wkf0f4f8f2C, base, ctx, 0);

    w->f2C = w->f0 = w->f4 = w->f8 = 0.0f;
}

void func_00291918(void) {
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void pppKeOfsMatXYZ(u8 *s1, void *arg1, u8 *arg2) {
    float sp0[4];
    float sp10[4];
    register u8 *s0 __asm__("$16");
    register u8 *s2 __asm__("$18");
    register u8 *s3 __asm__("$19");
    register s32 *v0_p __asm__("$2");
    register u8 *v0 __asm__("$2");
    register void *a0 __asm__("$4");
    register u8 *a1 __asm__("$5");
    register u8 *a2 __asm__("$6");
    register float f20 __asm__("$f20");
    register float f0 __asm__("$f0");
    register float f1 __asm__("$f1");

    s3 = s1 + 0x10;
    v0_p = *(s32 **)(arg2 + 0xC);
    s0 = (u8 *)v0_p[2];
    s2 = (u8 *)v0_p[0];
    __asm__("" : "+r"(s0), "+r"(s2), "+r"(v0_p) : "r"(s1), "r"(s3));
    a1 = (u8 *)v0_p[1];
    s0 += 0xA0;
    s2 += 0xA0;
    __asm__("" : "+r"(s0), "+r"(s2), "+r"(a1));
    s0 = s1 + (s32)s0;
    a1 += 0xA0;
    __asm__("" : "+r"(s0), "+r"(a1) : "r"(s2));
    s2 = s1 + (s32)s2;
    __asm__("" : "+r"(s2), "+r"(a1));
    a1 = s1 + (s32)a1;
    pppGetRotMatrixXYZ((void *)s3, (void *)a1);

    VU0_QMTC2_NI(9, *(float *)(s0 + 0));
    VU0_LQC2(10, 0, s3);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, s3);

    v0 = s1 + 0x20;
    VU0_QMTC2_NI(9, *(float *)(s0 + 4));
    VU0_LQC2(10, 0, v0);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, v0);

    f1 = *(float *)(s0 + 8);
    v0 = s1 + 0x30;
    VU0_QMTC2_NI(9, f1);
    VU0_LQC2(10, 0, v0);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, v0);

    f20 = 1.0f;
    __asm__("" : "+f"(f20));
    a1 = s2 + 0x10;
    f0 = 0.0f;
    __asm__("" : "+r"(a1), "+f"(f0) : "f"(f20));
    a2 = s2 + 0x20;
    *(float *)(s1 + 0x4C) = f20;
    __asm__ volatile("" : "+r"(a2) : : "memory");
    a0 = sp0;
    __asm__("" : "+r"(a0), "+f"(f0));
    *(float *)(s1 + 0x40) = f0;
    *(float *)(s1 + 0x48) = f0;
    __asm__ volatile("" : "+f"(f0) : "r"(a0), "r"(a1), "r"(a2) : "memory");
    *(float *)(s1 + 0x44) = f0;
    func_002DD020((void *)a0, (void *)a1, (void *)a2);
    func_002DCE08(sp10, s3, sp0);
    *(float *)(s1 + 0x40) = (sp0[0] + *(float *)(s2 + 0)) - sp10[0];
    *(float *)(s1 + 0x44) = (sp0[1] + *(float *)(s2 + 4)) - sp10[1];
    *(float *)(s1 + 0x48) = (sp0[2] + *(float *)(s2 + 8)) - sp10[2];
    *(float *)(s1 + 0x4C) = f20;
}

void func_00291A70(ScriptWork *base, ScriptAxisEvent *event, ScriptCtx *ctx)
{
    SlotInfo *slots = ctx->info;
    ScriptAxisWork *work = SLOT_WORK(ScriptAxisWork, base, ctx, 0);
    float velocity;

    if (D_006A3BC4 == 0) {
        if (event->owner == base->owner) {
            work->axis.acceleration += event->delta[0][0];
            work->velocitySource = (char *)base + (slots->slot[1] + 0xA0);
            work->positionSource = (char *)base + (slots->slot[2] + 0xA0);
            work->axis.velocity += event->delta[0][1];
            work->axis.position += event->delta[0][2];
        }
        velocity = work->axis.velocity + work->axis.acceleration;
        work->axis.velocity = velocity;
        work->axis.position += velocity;
    }
}

void func_00291B18(char *base, ScriptCtx *ctx) {
    Wkf0f4f8 *w = SLOT_WORK(Wkf0f4f8, base, ctx, 0);

    w->f0 = w->f4 = w->f8 = 0.0f;
}

void func_00291B40(ScriptWork *base, ScriptAxisEvent *event, ScriptCtx *ctx)
{
    ScriptAxisPair *work = SLOT_WORK(ScriptAxisPair, base, ctx, 0);
    float first;
    float second;

    if (D_006A3BC4 == 0) {
        if (event->owner == base->owner) {
            work->axis[0].acceleration += event->delta[0][0];
            work->axis[0].velocity += event->delta[0][1];
            work->axis[0].position += event->delta[0][2];
            work->axis[1].acceleration += event->delta[1][0];
            work->axis[1].velocity += event->delta[1][1];
            work->axis[1].position += event->delta[1][2];
        }
        first = work->axis[0].velocity + work->axis[0].acceleration;
        second = work->axis[1].velocity + work->axis[1].acceleration;
        work->axis[0].velocity = first;
        work->axis[1].velocity = second;
        work->axis[0].position += first;
        work->axis[1].position += second;
    }
}

void func_00291C10(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8fCf10f14 *w = SLOT_WORK(Wkf0f4f8fCf10f14, base, ctx, 0);

    w->fC = w->f10 = w->f14 = w->f0 = w->f4 = w->f8 = 0.0f;
}

void func_00291C40(Vec4 *pos, Vec4 *rot, EvRef *ref)
{
    WkPosRot *w;
    s16 *r;

    if (ref->idx != 0xFFFFFFFF) {
        w = (WkPosRot *)(ppvMng->p3C[ref->idx].base + (ref->ofs + 0xA0));
        r = w->rot;
        pos->x = w->pos->x;
        pos->y = w->pos->y;
        pos->z = w->pos->z;
        pos->w = w->w;
        rot->x = func_002EC440(func_002EBC70(func_002ED038(r[0]), 1.0 / 16384));
        rot->y = func_002EC440(func_002EBC70(func_002ED038(r[1]), 1.0 / 16384));
        rot->z = func_002EC440(func_002EBC70(func_002ED038(r[2]), 1.0 / 16384));
        rot->w = func_002EC440(func_002EBC70(func_002ED038(r[3]), 1.0 / 16384));
    } else {
        *(u_long128 *)pos = 0; /* DEBT(CAST): cleared with one quadword store */
        *(u_long128 *)rot = 0; /* DEBT(CAST) */
        pos->w = 1.0f;
    }
}

extern Vec4 D_006A3B30[4];
extern Vec4 D_006A3B70[4];
extern u8 *op1_md_draw(void *, void *);

typedef struct {
    /* 0x00 */ u32 flags;
    /* 0x04 */ s32 x04;
    /* 0x08 */ u16 x08;
    /* 0x0A */ u8 x0A;
    /* 0x0B */ u8 pad0B;
    /* 0x0C */ u32 x0C;
    /* 0x10 */ union {
        u64 d;
        struct { s32 a, b; } w;
    } x10;
    /* 0x18 */ u8 col[4];
    /* 0x1C */ u32 x1C;
    /* 0x20 */ void *x20;
    /* 0x24 */ void *x24;
    /* 0x28 */ void *x28;
    /* 0x2C */ void *x2C;
    /* 0x30 */ u32 x30;
    /* 0x34 */ u8 *x34;
    /* 0x38 */ u32 x38;
    /* 0x3C */ u32 x3C;
    /* 0x40 */ u32 x40;
    /* 0x44 */ void *x44;
    /* 0x48 */ u32 x48;
    /* 0x4C */ u8 x4C;
    /* 0x4D */ u8 x4D;
    /* 0x4E */ u8 pad4E[0x1A];
} MdDrawParam;

#define PPP_MUL_COL(dst_p, src_p, mng_p) { \
        void *_s = (src_p); \
        void *_m = (mng_p); \
        void *_d = (dst_p); \
        __asm__ volatile("ld $8, 0(%0)" : : "r"(_s), "r"(_m), "r"(_d) : "$8", "memory"); \
        __asm__ volatile("ld $9, 0(%0)" : : "r"(_m), "r"(_s) : "$9", "memory"); \
        __asm__ volatile("pextlh $8, $0, $8" : : : "$8"); \
        __asm__ volatile("pextlh $9, $0, $9" : : : "$9"); \
        __asm__ volatile("pmulth $8, $8, $9" : : : "$8"); \
        __asm__ volatile("psrlw $8, $8, 19" : : : "$8"); \
        __asm__ volatile("ppach $8, $0, $8" : : : "$8"); \
        __asm__ volatile("ppacb $8, $0, $8" : : : "$8"); \
        __asm__ volatile("sw $8, 0(%0)" : : "r"(_d), "r"(_s), "r"(_m) : "memory"); \
    }

void func_00291DA8(u8 *base, u8 *param, ScriptCtx *ctx)
{
    MdDrawParam draw;
    u8 *mdl;
    u32 idx;

    if (*(u32 *)(param + 4) == 0xFFFF) {
        return;
    }
    PPP_MUL_COL(draw.col, base + (ctx->info->slot[0] + 0xA0), (u8 *)ppvMng + 0x70);
    if (draw.col[3] == 0) {
        return;
    }
    mdl = *(u8 **)(*(u8 **)((u8 *)D_006A3924 + 0x20) + (*(u32 *)(param + 4) << 5) + 0x1C);
    if (*(u32 *)mdl & 1) {
        draw.flags = 0xC0;
    } else {
        draw.flags = 0x4C;
    }
    if (!(*(u32 *)mdl & 2)) {
        draw.flags |= 0x10;
    }
    draw.x08 = *(u16 *)(mdl + 0x16);
    draw.x0A = 0;
    draw.x1C = *(u32 *)((u8 *)ppvMng + 0x78);
    draw.x38 = *(u32 *)(base + 0x90);
    draw.x3C = *(u32 *)(base + 0x94);
    idx = *(u32 *)(param + 0x28);
    if (idx != 0xFFFFFFFFU) {
        u8 *p = ppvMng->p3C[idx].base + (*(s32 *)(param + 0x2C) + 0xA0);
        draw.x4D = func_002EC338(func_002EBC70(func_002ED038(*(float *)(p + 8)), 128.0));
        draw.x4C = func_002EC338(func_002EBC70(func_002ED038(*(float *)(p + 0x14)), 128.0));
        func_00291C40(&D_006A3B30[0], &D_006A3B70[0], (EvRef *)(param + 0x8));
        func_00291C40(&D_006A3B30[1], &D_006A3B70[1], (EvRef *)(param + 0x10));
        func_00291C40(&D_006A3B30[2], &D_006A3B70[2], (EvRef *)(param + 0x18));
        func_00291C40(&D_006A3B30[3], &D_006A3B70[3], (EvRef *)(param + 0x20));
    }
    draw.x04 = D_00303550;
    draw.x20 = base + 0x50;
    draw.x24 = D_006A3B70;
    draw.x28 = D_006A3B30;
    draw.x2C = base + 0x10;
    draw.x34 = D_006A3BCC;
    draw.x0C = 0;
    draw.x10.d = 0;
    draw.x40 = 0;
    draw.x44 = 0;
    D_006A3BCC = op1_md_draw(mdl, &draw);
}

void func_00292008(Vec4 *pos, Vec4 *rot, EvRef *ref)
{
    WkPosRot *w;
    s16 *r;

    if (ref->idx != 0xFFFFFFFF) {
        w = (WkPosRot *)(ppvMng->p3C[ref->idx].base + (ref->ofs + 0xA0));
        r = w->rot;
        pos->x = w->pos->x;
        pos->y = w->pos->y;
        pos->z = w->pos->z;
        pos->w = w->w;
        rot->x = func_002EC440(func_002EBC70(func_002ED038(r[0]), 1.0 / 16384));
        rot->y = func_002EC440(func_002EBC70(func_002ED038(r[1]), 1.0 / 16384));
        rot->z = func_002EC440(func_002EBC70(func_002ED038(r[2]), 1.0 / 16384));
        rot->w = func_002EC440(func_002EBC70(func_002ED038(r[3]), 1.0 / 16384));
    } else {
        *(u_long128 *)pos = 0; /* DEBT(CAST): cleared with one quadword store */
        *(u_long128 *)rot = 0; /* DEBT(CAST) */
        pos->w = 1.0f;
    }
}

void func_00292170(u8 *base, u8 *param, ScriptCtx *ctx)
{
    MdDrawParam draw;
    u8 *mdl;
    u32 idx;

    if (*(u32 *)(param + 4) == 0xFFFF) {
        return;
    }
    PPP_MUL_COL(draw.col, base + (ctx->info->slot[0] + 0xA0), (u8 *)ppvMng + 0x70);
    if (draw.col[3] == 0) {
        return;
    }
    draw.flags = 0xC0;
    mdl = *(u8 **)(*(u8 **)((u8 *)D_006A3924 + 0x20) + (*(u32 *)(param + 4) << 5) + 0x1C);
    if (!(*(u32 *)mdl & 2)) {
        draw.flags |= 0x10;
    }
    draw.x0A = 0;
    draw.x08 = *(u16 *)(param + 8);
    draw.x1C = *(u32 *)((u8 *)ppvMng + 0x78);
    draw.x38 = *(u32 *)(base + 0x90);
    draw.x3C = *(u32 *)(base + 0x94);
    idx = *(u32 *)(param + 0x2C);
    if (idx != 0xFFFFFFFFU) {
        u8 *p = ppvMng->p3C[idx].base + (*(s32 *)(param + 0x30) + 0xA0);
        draw.x4D = func_002EC338(func_002EBC70(func_002ED038(*(float *)(p + 8)), 128.0));
        draw.x4C = func_002EC338(func_002EBC70(func_002ED038(*(float *)(p + 0x14)), 128.0));
        func_00292008(&D_006A3B30[0], &D_006A3B70[0], (EvRef *)(param + 0xC));
        func_00292008(&D_006A3B30[1], &D_006A3B70[1], (EvRef *)(param + 0x14));
        func_00292008(&D_006A3B30[2], &D_006A3B70[2], (EvRef *)(param + 0x1C));
        func_00292008(&D_006A3B30[3], &D_006A3B70[3], (EvRef *)(param + 0x24));
    }
    draw.x0C = 0;
    draw.x10.d = 0;
    draw.x40 = 0;
    draw.x04 = D_00303550;
    draw.x20 = base + 0x50;
    draw.x44 = base + 0x50;
    draw.x24 = D_006A3B70;
    draw.x28 = D_006A3B30;
    draw.x2C = base + 0x10;
    draw.x34 = D_006A3BCC;
    D_006A3BCC = op1_md_draw(mdl, &draw);
}

void func_002923C0(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8fCf10f14 *w = SLOT_WORK(Wkf0f4f8fCf10f14, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->fC = w->f10 = w->f14 = 0.0f;
}

void func_002923F0(Vec4 *pos, Vec4 *rot, EvRef *ref)
{
    WkPosRot *w;
    s16 *r;

    if (ref->idx != 0xFFFFFFFF) {
        w = (WkPosRot *)(ppvMng->p3C[ref->idx].base + (ref->ofs + 0xA0));
        r = w->rot;
        pos->x = w->pos->x;
        pos->y = w->pos->y;
        pos->z = w->pos->z;
        pos->w = w->w;
        rot->x = func_002EC440(func_002EBC70(func_002ED038(r[0]), 1.0 / 16384));
        rot->y = func_002EC440(func_002EBC70(func_002ED038(r[1]), 1.0 / 16384));
        rot->z = func_002EC440(func_002EBC70(func_002ED038(r[2]), 1.0 / 16384));
        rot->w = func_002EC440(func_002EBC70(func_002ED038(r[3]), 1.0 / 16384));
    } else {
        *(u_long128 *)pos = 0; /* DEBT(CAST): cleared with one quadword store */
        *(u_long128 *)rot = 0; /* DEBT(CAST) */
        pos->w = 1.0f;
    }
}

void func_00292558(u8 *base, u8 *param, ScriptCtx *ctx)
{
    MdDrawParam draw;
    float *work = (float *)(base + (ctx->info->slot[2] + 0xA0));
    u8 *mdl;
    u32 idx;

    if (D_006A3BC4 == 0) {
        work[1] += work[2];
        work[4] += work[5];
        work[0] += work[1];
        work[3] += work[4];
        if (*(s32 *)param == *(s32 *)(base + 0xC)) {
            work[0] += *(float *)(param + 0x8);
            work[1] += *(float *)(param + 0xC);
            work[2] += *(float *)(param + 0x10);
            work[3] += *(float *)(param + 0x14);
            work[4] += *(float *)(param + 0x18);
            work[5] += *(float *)(param + 0x1C);
        }
    }
    if (*(u32 *)(param + 4) == 0xFFFF) {
        return;
    }
    PPP_MUL_COL(draw.col, base + (ctx->info->slot[0] + 0xA0), (u8 *)ppvMng + 0x70);
    if (draw.col[3] == 0) {
        return;
    }
    mdl = *(u8 **)(*(u8 **)((u8 *)D_006A3924 + 0x20) + (*(u32 *)(param + 4) << 5) + 0x1C);
    if (*(u32 *)mdl & 1) {
        draw.flags = 0xC0;
    } else {
        draw.flags = 0x4C;
    }
    if (!(*(u32 *)mdl & 2)) {
        draw.flags |= 0x10;
    }
    draw.x08 = *(u16 *)(mdl + 0x16);
    draw.x0A = 0;
    draw.x1C = *(u32 *)((u8 *)ppvMng + 0x78);
    draw.x38 = *(u32 *)(base + 0x90);
    draw.x3C = *(u32 *)(base + 0x94);
    idx = *(u32 *)(param + 0x40);
    if (idx != 0xFFFFFFFFU) {
        u8 *p = ppvMng->p3C[idx].base + (*(s32 *)(param + 0x44) + 0xA0);
        draw.x4D = func_002EC338(func_002EBC70(func_002ED038(*(float *)(p + 8)), 128.0));
        draw.x4C = func_002EC338(func_002EBC70(func_002ED038(*(float *)(p + 0x14)), 128.0));
        func_002923F0(&D_006A3B30[0], &D_006A3B70[0], (EvRef *)(param + 0x20));
        func_002923F0(&D_006A3B30[1], &D_006A3B70[1], (EvRef *)(param + 0x28));
        func_002923F0(&D_006A3B30[2], &D_006A3B70[2], (EvRef *)(param + 0x30));
        func_002923F0(&D_006A3B30[3], &D_006A3B70[3], (EvRef *)(param + 0x38));
    }
    draw.x04 = D_00303550;
    draw.x20 = base + 0x50;
    draw.x24 = D_006A3B70;
    draw.x10.w.a = (s32)(work[0] * 65536.0f);
    draw.x28 = D_006A3B30;
    draw.x10.w.b = (s32)(work[3] * 65536.0f);
    draw.x2C = base + 0x10;
    draw.x34 = D_006A3BCC;
    draw.x0C = 0;
    draw.x40 = 0;
    draw.x44 = 0;
    D_006A3BCC = op1_md_draw(mdl, &draw);
}

void func_00292880(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h2 = 0;
    w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_002928A0);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00292B20);

void func_00292E70(float *a0, float *a1, u32 *a2) {
    u32 idx = a2[0];
    if (idx != 0xFFFFFFFFU) {
        float sp00[4];
        u8 *mng = (u8 *)ppvMng;
        u8 *p = *(u8 **)(*(u8 **)(mng + 0x3C) + idx * 0x10 + 4) + (a2[1] + 0xA0);
        float *src = *(float **)(p + 0xC);
        s16 *s = *(s16 **)(p + 0x10);
        sp00[0] = src[0];
        sp00[1] = src[1];
        sp00[2] = src[2];
        sp00[3] = 1.0f;
        func_002DCE08((void *)a0, (void *)&D_006A3930, (void *)sp00);
        a0[3] = *(float *)(p + 8) * *(float *)(mng + 0x60);
        a1[0] = (float)((double)(float)s[0] * (1.0 / 16384.0));
        a1[1] = (float)((double)(float)s[1] * (1.0 / 16384.0));
        a1[2] = (float)((double)(float)s[2] * (1.0 / 16384.0));
        a1[3] = (float)((double)(float)s[3] * (1.0 / 16384.0));
    } else {
        *(u_long128 *)a0 = 0;
        *(u_long128 *)a1 = 0;
        a0[3] = 1.0f;
    }
}

/* DEBT(CAST) */
void func_00293010(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *s0;
    u8 *s2;
    s32 idx;

    idx = *(s32 *)(arg1 + 0x28);
    if (idx != 0xFFFFFFFF) {
        s2 = arg0 + (**(s32 **)(arg2 + 0xC) + 0xA0);
        if (*(s32 *)(s2 + 0x80) != 0) {
            s0 = *(u8 **)((idx << 4) + *(s32 *)((u8 *)ppvMng + 0x3C) + 4) + (*(s32 *)(arg1 + 0x2C) + 0xA0);
            *(u8 *)(s2 + 0x88) = func_002EC338(func_002EBC70(func_002ED038(*(float *)(s0 + 8)), 128.0));
            *(u8 *)(s2 + 0x89) = func_002EC338(func_002EBC70(func_002ED038(*(float *)(s0 + 0x14)), 128.0));
            func_00292E70((void *)(s2 + 0x40), (void *)s2, (void *)(arg1 + 8));
            func_00292E70((void *)(s2 + 0x50), (void *)(s2 + 0x10), (void *)(arg1 + 0x10));
            func_00292E70((void *)(s2 + 0x60), (void *)(s2 + 0x20), (void *)(arg1 + 0x18));
            func_00292E70((void *)(s2 + 0x70), (void *)(s2 + 0x30), (void *)(arg1 + 0x20));
        }
    }
}

void func_00293138(void) {
}

void func_00293140(void) {
}

void func_00293148(void) {
    func_00266EA0((ListNode *)&D_0036F1F0); /* DEBT(CAST): ObjTable vs ListNode */
}

void func_00293158(void) {
}

void func_00293160(void) {
}

void func_00293168(void) {
}

int func_00293170(void) {
    return (int)pppAlloc(); /* DEBT(CAST): returns the block pointer as int */
}

void func_00293190(void) {
}

void func_00293198(void) {
}

void *func_002931A0(void) {
    return D_00370918;
}
