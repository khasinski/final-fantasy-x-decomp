/* tu_303 0x27bc40-0x27ed88: low; unk_27BC40 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_0027BC40(R6Src *s, R6Dst *d) {
    d->f4 = s->f8;
    d->src = s;
    d->f10 = s->f14;
    d->f8 = d->fC = d->f14 = d->f18 = 0.0f;
}

void func_0027BC70(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
}

void func_0027BC88(char *base, ScriptCtx *ctx) {
    Wkf8fCf14f18 *w = SLOT_WORK(Wkf8fCf14f18, base, ctx, 2);

    w->f8 = w->fC = w->f14 = w->f18 = 0.0f;
}

void func_0027BCB0(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027BCB8);

void func_0027C028(R6Src *s, R6Dst *d) {
    d->f4 = s->f8;
    d->src = s;
    d->f10 = s->f14;
    d->f8 = d->fC = d->f14 = d->f18 = 0.0f;
}

void func_0027C058(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
}

void func_0027C070(char *base, ScriptCtx *ctx) {
    Wkf8fCf14f18 *w = SLOT_WORK(Wkf8fCf14f18, base, ctx, 2);

    w->f8 = w->fC = w->f14 = w->f18 = 0.0f;
}

void func_0027C098(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027C0A0);

int func_0027C478(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysC *s = SLOT_WORK(T6_PSysC, o, ctx, 0);

    s->parts = pppMemAlloc(D_006A3924, D_006A3924->sub, k->count * 0xA0);
    if (s->parts == 0) {
        return 0;
    }
    func_002EF0D0(s->parts, 0, k->count * 0xA0);
    s->aux = pppMemAlloc(D_006A3924, D_006A3924->sub, 0xC);
    if (s->aux == 0) {
        return 0;
    }
    s->rec = pppMemAlloc(D_006A3924, D_006A3924->sub, s->nrec * 8);
    if (s->rec == 0) {
        return 0;
    }
    func_002EF0D0(s->rec, 0, s->nrec * 8);
    s->vec = pppMemAlloc(D_006A3924, D_006A3924->sub, s->nrec * 16);
    if (s->vec == 0) {
        return 0;
    }
    func_002EF0D0(s->vec, 0, s->nrec * 16);
    return 1;
}

void func_0027C588(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysC *s = SLOT_WORK(T6_PSysC, o, ctx, 0);

    func_002DD128((struct W3Whole *)s); /* DEBT(CAST): prototype takes the W3Whole view */
    s->w48 = 0;
    s->parts = 0;
    s->w4C = 0;
    s->nrec = (life->len - life->start) / 4096 + 1;
    s->aux = 0;
    s->rec = 0;
    s->vec = 0;
    s->done = 0;
}

void func_0027C618(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PSysC *s = SLOT_WORK(T6_PSysC, o, ctx, 0);

    if (s->parts != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->parts);
        s->parts = 0;
    }
    func_00267028(D_006A3924, D_006A3924->sub, s->aux);
    if (s->rec != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->rec);
        s->rec = 0;
    }
    if (s->vec != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->vec);
        s->vec = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027C6A8);

/* DEBT(TYPE): arguments of the forwarded call unknown */
void func_0027C8B0(int *a) {
    func_00270C78(a);
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027C8B8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027C9C8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027CAB0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027D6E0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027D888);

int func_0027DA88(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);

    s->parts = pppMemAlloc(D_006A3924, D_006A3924->sub, k->count * 0xB0);
    if (s->parts == 0) {
        return 0;
    }
    func_002EF0D0(s->parts, 0, k->count * 0xB0);
    s->rec = pppMemAlloc(D_006A3924, D_006A3924->sub, s->nrec * 8);
    if (s->rec == 0) {
        return 0;
    }
    func_002EF0D0(s->rec, 0, s->nrec * 8);
    return 1;
}

void func_0027DB50(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);

    func_002DD128((struct W3Whole *)s); /* DEBT(CAST): prototype takes the W3Whole view */
    s->w44 = 0;
    s->w48 = 0;
    s->parts = 0;
    s->rec = 0;
    s->nrec = (life->len2 - life->start2) / 4096 + 1;
    s->done = 0;
}

void func_0027DBD8(char *base, ScriptCtx *ctx)
{
    Wkp40p4C *w = SLOT_WORK(Wkp40p4C, base, ctx, 0);

    if (w->p40 != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p40);
        w->p40 = 0;
    }
    if (w->p4C != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p4C);
        w->p4C = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027DC40);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027DE20);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027DF48);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027E080);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027EBD8);
