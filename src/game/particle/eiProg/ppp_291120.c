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

/* DEBT(CAST): ScriptWork supplies the owner field of the shared VM memory header. */
void func_00291A70(char *base, ScriptAxisEvent *event, ScriptCtx *ctx)
{
    SlotInfo *slots = ctx->info;
    ScriptAxisWork *work = SLOT_WORK(ScriptAxisWork, base, ctx, 0);
    float velocity;

    if (D_006A3BC4 == 0) {
        if (event->owner == ((ScriptWork *)base)->owner) {
            work->axis.acceleration += event->delta[0][0];
            work->velocitySource = base + (slots->slot[1] + 0xA0);
            work->positionSource = base + (slots->slot[2] + 0xA0);
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

/* DEBT(CAST): ScriptWork supplies the owner field of the shared VM memory header. */
void func_00291B40(char *base, ScriptAxisEvent *event, ScriptCtx *ctx)
{
    ScriptAxisPair *work = SLOT_WORK(ScriptAxisPair, base, ctx, 0);
    float first;
    float second;

    if (D_006A3BC4 == 0) {
        if (event->owner == ((ScriptWork *)base)->owner) {
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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00291DA8);

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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00292170);

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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00292558);

void func_00292880(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h2 = 0;
    w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_002928A0);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00292B20);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00292E70);

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
