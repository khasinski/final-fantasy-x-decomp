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

    func_002DD128(s);
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

extern s32 D_006A3BC4;
void func_0027C9C8(T6_PObj *, T6_PKey *, ScriptCtx *);
void func_0027CAB0(T6_PObj *, T6_PKey *, ScriptCtx *, T6_PSysC *);
void func_0027D6E0(PtEmitter *, T6_PSysC *);

/* DEBT(CAST): raw byte offsets for emitter/slot color and velocity records */
void func_0027C6A8(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysC *s = SLOT_WORK(T6_PSysC, o, ctx, 0);
    T6_PLife *life = *o->life;
    T6_PRec *src;
    Particle *p;
    int t;
    int i;
    int n;

    if (k->id == 0xFFFF) {
        return;
    }
    if (D_006A3924->tbl[k->id] == 0) {
        return;
    }
    if (s->parts == 0 && !func_0027C478(o, k, ctx)) {
        return;
    }
    t = o->t;
    n = t / 4096;
    if (s->done == 0 && (u32)n < s->nrec) {
        src = SLOT_WORK(T6_PRec, o, ctx, 1);
        s->vec[n][0] = *(float *)((u8 *)k + 0x40);
        s->rec[n].h[0] = src->h[0];
        s->vec[n][1] = *(float *)((u8 *)k + 0x44);
        s->rec[n].h[1] = src->h[1];
        s->vec[n][2] = *(float *)((u8 *)k + 0x48);
        s->rec[n].h[2] = src->h[2];
        s->vec[n][3] = 0.0f;
        s->rec[n].h[3] = src->h[3];
    }
    if (t >= life->len - 0x1000) {
        p = (Particle *)s->parts;
        n = k->count;
        for (i = 0; i < n; i++, p++) {
            if (p->flags & 1) {
                break;
            }
        }
        if (i < n) {
            o->t = t - 0x1000;
        }
        s->done = 1;
    }
    if (D_006A3BC4 == 0 && ppvMng->b1D == 0) {
        func_0027C9C8(o, k, ctx);
    }
    func_0027CAB0(o, k, ctx, s);
    if (D_006A3BC4 == 0) {
        func_0027D6E0(k, s);
    }
}

/* DEBT(TYPE): arguments of the forwarded call unknown */
void func_0027C8B0(int *a) {
    func_00270C78(a);
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027C8B8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027C9C8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027CAB0);

void func_0027D6E0(PtEmitter *e, T6_PSysC *o)
{
    PtAnim *anim = D_006A3924->tbl[e->id];
    Particle *p = (Particle *)o->parts;
    PtKey *k;
    int i;
    u16 f;
    int n = e->count;

    for (i = 0; i < n; i++, p++) {
        if (p->flags & 1) {
            k = &anim->keys[p->frame];
            func_002DD020(&p->v10, &p->v10, (Vec4 *)o->vec[p->age]);
            p->acc.x += e->accB.x;
            p->acc.y += e->accB.y;
            p->acc.z += e->accB.z;
            p->pos.x += p->acc.x;
            p->pos.y += p->acc.y;
            p->pos.z += p->acc.z;
            p->time += e->speed.h;
            if (p->time >= k->dur) {
                p->time -= k->dur;
                f = p->frame;
                if (++p->frame >= anim->frames) {
                    if (k->flags & 0x80) {
                        p->frame = 0;
                    } else {
                        p->frame = f;
                    }
                    p->time = 0;
                }
            }
            p->age++;
            if (p->age >= o->nrec) {
                p->flags &= ~1;
            }
        }
    }
}

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

    func_002DD128(s);
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

typedef struct ParticleB { /* 0xB0 bytes */
    u32 flags;
    u16 time;
    u16 frame;
    u32 age;
    u8 padC[4];
    Vec4 v10;
    Vec4 vel;
    Vec4 v30;
    Vec4 pos;
    Vec4 acc;
    u8 pad60[0x50];
} ParticleB;

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027DC40);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027DE20);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027DF48);

INCLUDE_ASM("build/ee_asm/game/particle/particle_27BC40", func_0027E080);

void func_0027EBD8(PtEmitter *e, PtOwnerB *o)
{
    PtAnim *anim = D_006A3924->tbl[e->id];
    ParticleB *p = (ParticleB *)o->parts;
    PtKey *k;
    int i;
    u16 f;
    int n = e->count;

    for (i = 0; i < n; i++, p++) {
        if (p->flags & 1) {
            p->age++;
            k = &anim->keys[p->frame];
            if (p->age >= o->nrec) {
                p->flags &= ~1;
            }
            func_002DD020(&p->vel, &p->vel, &p->v30);
            func_002DD020(&p->v10, &p->v10, &p->vel);
            p->acc.x += e->acc.x;
            p->acc.y += e->acc.y;
            p->acc.z += e->acc.z;
            p->pos.x += p->acc.x;
            p->pos.y += p->acc.y;
            p->pos.z += p->acc.z;
            p->time += e->speed.h;
            if (p->time >= k->dur) {
                p->time -= k->dur;
                f = p->frame;
                if (++p->frame >= anim->frames) {
                    if (k->flags & 0x80) {
                        p->frame = 0;
                    } else {
                        p->frame = f;
                    }
                    p->time = 0;
                }
            }
        }
    }
}
