/* tu_302 0x279f40-0x27bc40: medium; unk_279F40 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/particle/particle_279F40", func_00279F40);

void func_0027A078(T6_RKey *k, Wkb0b1b2b3 *w)
{
    w->b0 = 1;
    if (k->bD != 0 && func_002B3DB0(1.0f) > 0.0f) {
        w->b1 = 1;
    }
    if (k->bE != 0 && func_002B3DB0(1.0f) > 0.0f) {
        w->b2 = 1;
    }
    if (k->bF != 0 && func_002B3DB0(1.0f) > 0.0f) {
        w->b3 = 1;
    }
}

void func_0027A150(char *base, ScriptCtx *ctx) {
    Wkb0b1b2b3 *w = SLOT_WORK(Wkb0b1b2b3, base, ctx, 5);

    w->b0 = 0;
    w->b3 = 0;
    w->b2 = 0;
    w->b1 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_279F40", func_0027A178);

void func_0027A3F0(T6TransformFrame *frame, int unused1, T6TransformInput *input)
{
    T6_ColMgr *manager;
    float scaleX;
    float scaleY;
    float *matrix;
    u8 *flags;
    float *world;
    float *scale;
    float *position;
    int *offsets;

    matrix = frame->matrix[0];
    offsets = input->offsets;
    /* DEBT(CAST): offsets select byte flags and float vectors in the payload. */
    /* DEBT(ORDER): independent payload views preserve original load scheduling. */
    flags = (u8 *)(frame->payload + offsets[0]);
    position = (float *)(frame->payload + offsets[1]);
    scale = (float *)(frame->payload + offsets[2]);
    manager = ppvMng;
    func_002DD128(matrix);
    scaleX = scale[0];
    if (flags[1] & 2)
    {
        scaleX = -scaleX;
    }
    frame->matrix[0][0] = scaleX;
    scaleY = scale[1];
    if (flags[1] & 1)
    {
        scaleY = -scaleY;
    }
    frame->matrix[1][1] = scaleY;
    world = frame->world[0];
    frame->matrix[2][2] = (float) scale[2];
    frame->matrix[3][0] = (float) position[0];
    frame->matrix[3][1] = (float) position[1];
    frame->matrix[3][2] = (float) position[2];
    func_002DD068(world, matrix, manager->m60[0]);
    func_002DD068(frame->world[1], frame->matrix[1], manager->m60[1]);
    func_002DD068(frame->world[2], frame->matrix[2], manager->m60[2]);
    func_002DCE08(frame->world[3], D_006A39B0, frame->matrix[3]);
    func_002DCE38(world, D_006A3A70, world);
}

void func_0027A520(T6_RKey *k, Wkb0b1h2h4 *w)
{
    w->b0 = 1;
    w->b1 = 0;
    if ((k->bF & 1) && func_002B3DB0(1.0f) > 0.0f) {
        w->b1 |= 1;
    }
    if ((k->bF & 2) && func_002B3DB0(1.0f) > 0.0f) {
        w->b1 |= 2;
    }
}

void func_0027A5D8(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4 *w = SLOT_WORK(Wkb0b1h2h4, base, ctx, 0);

    w->b0 = 0;
    w->b1 = 0;
    w->h4 = 0;
    w->h2 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_279F40", func_0027A600);

int func_0027A7F0(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);

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
    return 1;
}

void func_0027A8D0(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);

    func_002DD128(s);
    s->w48 = 0;
    s->parts = 0;
    s->w4C = 0;
    s->aux = 0;
    s->nrec = (life->len - life->start) / 4096 + 1;
    s->rec = 0;
    s->done = 0;
}

void func_0027A958(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);

    if (s->parts != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->parts);
        s->parts = 0;
    }
    func_00267028(D_006A3924, D_006A3924->sub, s->aux);
    if (s->rec != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->rec);
        s->rec = 0;
    }
}

void func_0027A9D0(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);
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
    if (s->parts == 0 && !func_0027A7F0(o, k, ctx)) {
        return;
    }
    t = o->t;
    n = t / 4096;
    if (s->done == 0 && n < s->nrec) {
        src = SLOT_WORK(T6_PRec, o, ctx, 1);
        s->rec[n].h[0] = src->h[0];
        s->rec[n].h[1] = src->h[1];
        s->rec[n].h[2] = src->h[2];
        s->rec[n].h[3] = src->h[3];
    }
    if (t >= life->len - 0x1000) {
        p = s->parts;
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
        func_0027AD60(o, k, ctx);
    }
    func_0027AE48(o, k, ctx, s);
    if (D_006A3BC4 == 0) {
        func_0027BA78(k, s);
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_279F40", func_0027ABB0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_279F40", func_0027AD60);

INCLUDE_ASM("build/ee_asm/game/particle/particle_279F40", func_0027AE48);

void func_0027BA78(PtEmitter *e, PtOwner *o)
{
    PtAnim *anim = D_006A3924->tbl[e->id];
    Particle *p = o->parts;
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
