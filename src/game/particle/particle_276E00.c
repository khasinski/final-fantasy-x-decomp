/* tu_299 0x276e00-0x2781c8: medium; unk_276E00 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/w9.h"
#include "ffx/u4.h"
#include "ffx/r6.h"
#include "ffx/v6.h"

int func_00276E00(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);

    s->parts = pppMemAlloc(D_006A3924, D_006A3924->sub, k->count * 0xA0);
    if (s->parts == 0) {
        return 0;
    }
    func_002EF0D0(s->parts, 0, k->count * 0xA0);
    s->rec = pppMemAlloc(D_006A3924, D_006A3924->sub, s->nrec * 8);
    if (s->rec == 0) {
        return 0;
    }
    func_002EF0D0(s->rec, 0, s->nrec * 8);
    return 1;
}

void func_00276EC8(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);

    func_002DD128((struct W3Whole *)s); /* DEBT(CAST): prototype takes the W3Whole view */
    s->w44 = 0;
    s->w48 = 0;
    s->parts = 0;
    s->rec = 0;
    s->nrec = (life->len - life->start) / 4096 + 1;
    s->done = 0;
}

void func_00276F50(char *base, ScriptCtx *ctx)
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

void func_00276FB8(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);
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
    if (s->parts == 0 && !func_00276E00(o, k, ctx)) {
        return;
    }
    t = o->t;
    n = t / 4096;
    if (s->done == 0 && n < s->nrec) {
        src = SLOT_WORK(T6_PRec, o, ctx, 1);
        s->rec[n].h[0] = src->h[0];
        s->rec[n].h[1] = src->h[1];
        s->rec[n].h[2] = src->h[2];
        i = 0; /* DEBT(FAKE): dead store, steers register allocation */
        s->rec[n].h[3] = src->h[3];
    }
    if (t >= life->len - 0x1000) {
        p = (Particle *)s->parts; /* DEBT(CAST): parts is declared as a word pointer */
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
    if (D_006A3BC4 == 0) {
        if (((u8 *)ppvMng)[0x1D] == 0) { /* DEBT(CAST): byte 0x1D of the manager */
            func_00277298(o, k, ctx);
        }
        func_002773A0(o, k, ctx, s);
        func_00278000((PtEmitterB *)k, (PtOwnerB *)s); /* DEBT(CAST): emitter/owner views of the key and work */
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_276E00", func_00277188);

INCLUDE_ASM("build/ee_asm/game/particle/particle_276E00", func_00277298);

INCLUDE_ASM("build/ee_asm/game/particle/particle_276E00", func_002773A0);

void func_00278000(PtEmitterB *e, PtOwnerB *o)
{
    PtAnim *anim = (PtAnim *)D_006A3924->tbl[e->anim]; /* DEBT(CAST): tbl is declared as DataRef ** */
    Particle *p = o->parts;
    PtKey *k;
    int i;
    u16 f;
    int n = e->count;

    for (i = 0; i < n; i++, p++) {
        if (p->flags & 1) {
            p->age++;
            k = &anim->keys[p->frame];
            if (p->age >= o->life) {
                p->flags &= ~1;
            }
            p->vel.x += e->vel.x;
            p->vel.y += e->vel.y;
            p->vel.z += e->vel.z;
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
