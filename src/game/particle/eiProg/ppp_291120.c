/* tu_313 0x291120-0x2931b0: medium; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", pppKeOfsMatXYZ);

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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_291120", func_00293010);

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
