/* tu_169 0x19fc00-0x1a21e0: low; ~rcef (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#define func_001A1FF0 s2_func_001A1FF0 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/s2.h"
#undef func_001A1FF0
#include "ffx/v2.h"
#include "ffx/r2.h"
#include "ffx/w3.h"
#include "ffx/u2.h"

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_0019FC00);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefMainProcRunAfter);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_0019FE38);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_0019FE48);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_0019FE58);

void *func_0019FF48(S2Obj1C *o) {
    void *p = rcefObjNew();

    rcefObjInit(p);
    func_001A1FF0(o->sub, p);
    return p;
}

void *func_0019FF90(S2Obj1C *o, int fn) {
    void *p = func_0019FF48(o);

    func_001A1D08(p, fn);
    return p;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefMainKickPar);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0000);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0040);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0080);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A01B0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A01E0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0210);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0248);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A02D8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A02E8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0308);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A04D8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A06A8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0700);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A08A8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0A10);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0AB0);

void *rcefObjNew(void)
{
    void *p = pppMemAlloc(D_006A3924, D_006A3924->sub, 0x490);

    rcefObjInit(p);
    return p;
}

void func_001A0B38(void *p)
{
    rcefObjProc(p);
    func_00267028(D_006A3924, D_006A3924->sub, p);
}

void rcefObjInit(void *p)
{
    S2Obj1A *o = p;

    func_002EF0D0(o, 0, 0x490);
    rcefTaskInit((W3Task *)o); /* DEBT(CAST): the object is also a W3Task */
    o->i13C = 0;
    o->i16C = 0;
    o->fnB4 = rcefObjProc;
    o->fnB0 = func_001A0C70;
    o->v130[2] = o->v130[1] = o->v130[0] = 1.0f;
    o->v160[2] = o->v160[1] = o->v160[0] = 1.0f;
    o->v170[2] = o->v170[1] = o->v170[0] = 1.0f;
    o->v170[3] = 1.0f;
    func_002DD128((struct W3Whole *)o->m1B0); /* DEBT(CAST): matrices are passed as the W3Whole view */
    func_002DD128((struct W3Whole *)o->m1F0);
    func_002DD128((struct W3Whole *)o->m230);
    rcefParInit(o->b280);
    rcefAnimeInit(o->b330);
    func_001A19F0(o->b3C0);
}

void rcefObjProc(S2Obj1A *o) {
    func_001A14C8(o->b280);
    func_001A1778(o->b330);
    func_001A1A00(o->b3C0);
    func_001A1C40((W3Task *)o); /* DEBT(CAST): the object is also a W3Task */
}

void func_001A0C60(S2Obj1A *o) {
    o->flagsBC = 1;
}

void func_001A0C70(S2Obj1A *o) {
    rcefObjCalcLocalMatrix(o);
    func_001A0F58(o);
    rcefParProc(o->b280);
    func_001A17A0(o->b330);
    func_001A1A68(o->b3C0);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefObjCalcLocalMatrix);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0F58);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefObjCalcParentMatrix);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A11F0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1238);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1270);

void func_001A1378(S2Obj1A *o, int a, int b) {
    o->f270 = a;
    o->flagsBC = (o->flagsBC & ~6) | 2;
    o->f274 = b;
}

void func_001A13A0(S2Obj1A *o, int a, int b) {
    func_001A1378(o, a, Ch_OptposGetElement((s32)rcefGetChrHandle(a), b, 0)); /* DEBT(CAST): Chr pointer passed as s32 */
}

int func_001A1400(void *a) {
    Obj1A0B70 *o = a;

    return (o->flags280 & 1) ^ 1;
}

int func_001A1410(void *p) {
    Obj1A0B70 *o = p;

    return (o->flags330 & 1) ^ 1;
}

void func_001A1420(Obj1A0B70 *o, u32 flags) {
    func_001A1460(o);
    o->flagsBC |= flags;
}

void func_001A1460(Obj1A0B70 *o) {
    o->flagsBC &= 0xFFFFF00F;
}

void rcefParInit(R2Obj1A14 *o) {
    func_002EF0D0(o, 0, 0xB0);
    o->w6C = 1;
    o->f5C = 1.0f;
    o->fA0 = 1.0f;
    o->fA4 = 1.0f;
    o->fA8 = 1.0f;
    o->wAC = 0;
}

void func_001A14C8(void *b) {
}

void func_001A14D0(R2Obj1A14D0 *o, R2Tbl50 *tbl, int n, int a, int b, int c) {
    o->f0 = 1;
    o->f4 = (int)tbl;
    o->f8 = n;
    o->f70 = o->f74 = o->f78 = 1.0f;
    o->fC = tbl->ent[n].b;
    o->f90 = a;
    o->f94 = b;
    o->f98 = c;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefParProc);

void rcefAnimeInit(Obj1A1740 *o) {
    func_002EF0D0(o, 0, 0x90);
    o->h44 = 0x200;
}

void func_001A1778(void *b) {
}

void func_001A1780(R2Rec1A17 *r, int a, int b, int c) {
    r->f0 = 1;
    r->f4 = a;
    r->f48 = b;
    r->f4C = c;
    r->f20 = r->f50;
}

void func_001A17A0(void *b) {
    u32 *o = b;

    if (*o & 1) {
        func_001A17E8(o);
        func_001A1948(o);
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A17E8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1948);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A19F0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1A00);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1A08);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1A68);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1AB0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1BE8);

void rcefTaskInit(W3Task *t)
{
    func_002EF0D0(t, 0, sizeof(W3Task));
    t->flags |= 1;
    t->fnCleanup = func_001A1C40;
    t->prio = 0x8000;
}

void func_001A1C40(W3Task *t)
{
}

void rcefTaskProc(W3Task *t)
{
    do {
        t->flags &= ~2;
        if (t->fn[t->sp] != 0) {
            t->fn[t->sp](t);
        }
    } while (t->flags & 2);
    if (t->fnExit != 0 && !(t->flags & 4)) {
        t->fnExit(t);
    }
}

void func_001A1CE0(W3Task *t)
{
    if (t->fnCleanup != 0) {
        t->fnCleanup(t);
    }
}

void func_001A1D08(W3Task *t, W3TaskFn fn)
{
    t->fn[t->sp] = fn;
}

void func_001A1D20(W3Task *t, W3TaskFn fn)
{
    func_001A1D08(t, fn);
    t->flags |= 2;
}

void func_001A1D50(W3Task *t, W3TaskFn fn)
{
    if (t->sp < 7) {
        t->sp++;
        t->fn[t->sp] = fn;
    }
}

void func_001A1D78(W3Task *t, W3TaskFn fn)
{
    func_001A1D50(t, fn);
    t->flags |= 2;
}

void func_001A1DA8(W3Task *t)
{
    if (t->sp > 0) {
        t->sp--;
    }
}

void func_001A1DC0(W3Task *t)
{
    func_001A1DA8(t);
    t->flags |= 2;
}

void func_001A1DF0(W3Task *t, int n)
{
    if (n > 0) {
        func_001A1D50(t, func_001A1E40);
        t->frame[t->sp].count = n;
    }
}

void func_001A1E40(W3Task *t)
{
    t->frame[t->sp].count--;
    if (t->frame[t->sp].count <= 0) {
        func_001A1DC0(t);
    }
}

void rcefTaskKill(W3Task *t)
{
    t->prev->next = t->next;
    t->next->prev = t->prev;
    func_001A1CE0(t);
    func_00267028(D_006A3924, D_006A3924->sub, t);
}

void func_001A1ED8(W3Sched *s)
{
    rcefTaskInit(&s->head);
    rcefTaskInit(&s->tail);
    s->head.next = &s->tail;
    s->tail.prio = 0xFFFF;
    s->head.prio = 0;
    s->tail.prev = &s->head;
    s->i178 = 0;
}

void func_001A1F28(W3Sched *s)
{
    while (s->tail.prev != &s->head) {
        rcefTaskKill(s->tail.prev);
    }
}

void rcefTaskCtrlProc(W3Task *t)
{
    W3Task *first;
    W3Task *cur;

    first = t;
    for (; t != 0; t = t->next) {
        rcefTaskProc(t);
    }
    t = first;
    while (t != 0) {
        if (t->flags & 4) {
            cur = t;
            t = t->next;
            rcefTaskKill(cur);
        } else {
            t = t->next;
        }
    }
}

void func_001A1FF0(W3Task *t, W3Task *n) {
    int prio; /* DEBT(FAKE): temp only steers the loop entry */

    for (; t != 0; t = t->next) {
        prio = t->prio;
        if (n->prio < prio) {
            t->prev->next = n;
            n->prev = t->prev;
            t->prev = n;
            n->next = t;
            break;
        }
    }
}

int func_001A2040(W3Sched *s)
{
    return s->head.next == &s->tail;
}

void func_001A2058(W3Task *t)
{
    if (func_0029B830(D_00313CB4) == 0) {
        func_001A1DC0(t);
    }
}

void func_001A2098(W3Task *t)
{
    if (MsEffectMotionLevel(D_00313CB4) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A20D8(W3Task *t)
{
    if (func_001A1400(t) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A2110(W3Task *t)
{
    if (func_001A1410(t) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A2148(W3Task *t)
{
    if (MsEffectCheckMotion(t->frame[t->sp].count) == -1) {
        func_001A1DC0(t);
    }
}

void func_001A2198(W3Task *t)
{
    if (func_001D4578(t->frame[t->sp].count) == 0) {
        func_001A1DC0(t);
    }
}
