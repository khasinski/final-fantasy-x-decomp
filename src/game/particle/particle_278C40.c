/* tu_301 0x278c40-0x279f40: medium; unk_278C40 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_00278C40(R6Src *s, R6Dst *d) {
    d->f4 = s->f8;
    d->src = s;
    d->f10 = s->f14;
    d->f8 = d->fC = d->f14 = d->f18 = 0.0f;
}

void func_00278C70(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
}

void func_00278C88(char *base, ScriptCtx *ctx) {
    Wkf8fCf14f18 *w = SLOT_WORK(Wkf8fCf14f18, base, ctx, 2);

    w->f8 = w->fC = w->f14 = w->f18 = 0.0f;
}

void func_00278CB0(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_278C40", func_00278CB8);

void func_00279008(int a, R6Fvec *v) {
    v->w10 = a;
    v->x = v->y = v->z = 0.0f;
}

void func_00279020(char *base, ScriptCtx *ctx) {
    Wkw10 *w = SLOT_WORK(Wkw10, base, ctx, 0);

    w->w10 = 0;
}

void func_00279038(char *base, ScriptCtx *ctx) {
    R6VecSub *w = SLOT_WORK(R6VecSub, base, ctx, 0);

    w->f0 -= w->p10->f10;
    w->f4 -= w->p10->f14;
    w->f8 -= w->p10->f18;
}

void func_00279080(ScriptWork *base, T6_VKeyF *k, ScriptCtx *ctx)
{
    R6Fvec *v = SLOT_WORK(R6Fvec, base, ctx, 0);

    if (D_006A3BC4 == 0) {
        if (v->w10 == 0) {
            func_00279008((int)k, v); /* DEBT(CAST): the key record is remembered as a word */
        }
        if (k->key == base->owner) {
            v->x += k->d[0];
            v->y += k->d[1];
            v->z += k->d[2];
        }
    }
}

void func_00279128(int a, R6Wvec *w) {
    w->w10 = a;
    w->w4 = 0;
    w->w0 = 0;
    w->w8 = 0;
}

void func_00279140(char *base, ScriptCtx *ctx) {
    Wkw10 *w = SLOT_WORK(Wkw10, base, ctx, 0);

    w->w10 = 0;
}

void func_00279158(char *base, ScriptCtx *ctx) {
    R6VecSubI *w = SLOT_WORK(R6VecSubI, base, ctx, 0);

    w->w0 -= w->p10->w10;
    w->w4 -= w->p10->w14;
    w->w8 -= w->p10->w18;
}

void func_002791A0(ScriptWork *base, T6_VKeyI *k, ScriptCtx *ctx)
{
    R6Wvec *v = SLOT_WORK(R6Wvec, base, ctx, 0);

    if (D_006A3BC4 == 0) {
        if (v->w10 == 0) {
            func_00279128((int)k, v); /* DEBT(CAST): the key record is remembered as a word */
        }
        if (k->key == base->owner) {
            v->w0 += k->d[0];
            v->w4 += k->d[1];
            v->w8 += k->d[2];
        }
    }
}

void func_00279248(int a, R6Fvec *v) {
    v->w10 = a;
    v->x = v->y = v->z = 0.0f;
}

void func_00279260(char *base, ScriptCtx *ctx) {
    Wkw10 *w = SLOT_WORK(Wkw10, base, ctx, 0);

    w->w10 = 0;
}

void func_00279278(char *base, ScriptCtx *ctx) {
    R6VecSub *w = SLOT_WORK(R6VecSub, base, ctx, 0);

    w->f0 -= w->p10->f10;
    w->f4 -= w->p10->f14;
    w->f8 -= w->p10->f18;
}

void func_002792C0(ScriptWork *base, T6_VKeyF *k, ScriptCtx *ctx)
{
    R6Fvec *v = SLOT_WORK(R6Fvec, base, ctx, 0);

    if (D_006A3BC4 == 0) {
        if (v->w10 == 0) {
            func_00279248((int)k, v); /* DEBT(CAST): the key record is remembered as a word */
        }
        if (k->key == base->owner) {
            v->x += k->d[0];
            v->y += k->d[1];
            v->z += k->d[2];
        }
    }
}

void func_00279368(u8 *p) {
    func_002DCE38(p + 0x50, &D_006A3AB0, p + 0x10);
}

void func_00279380(char *base, ScriptCtx *ctx) {
    Wkf0f4f8 *w = SLOT_WORK(Wkf0f4f8, base, ctx, 1);

    w->f0 = w->f4 = w->f8 = 0.0f;
}

void func_002793A8(char *base, ScriptCtx *ctx) {
    func_00279380(base, ctx);
}

void func_002793B0(ScriptWork *base, T6_VKeyF *k, ScriptCtx *ctx)
{
    float *v = SLOT_WORK(float, base, ctx, 0);
    float *d = SLOT_WORK(float, base, ctx, 1);

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            d[0] += k->d[0];
            d[1] += k->d[1];
            d[2] += k->d[2];
        }
        v[0] += d[0];
        v[1] += d[1];
        v[2] += d[2];
    }
}

void func_00279458(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 1);

    w->w8 = 0;
    w->w4 = 0;
    w->w0 = 0;
}

void func_00279478(char *base, ScriptCtx *ctx) {
    func_00279458(base, ctx);
}

void func_00279480(ScriptWork *base, T6_VKeyI *k, ScriptCtx *ctx)
{
    int *v = SLOT_WORK(int, base, ctx, 0);
    int *d = SLOT_WORK(int, base, ctx, 1);

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            d[0] += k->d[0];
            d[1] += k->d[1];
            d[2] += k->d[2];
        }
        v[0] += d[0];
        v[1] += d[1];
        v[2] += d[2];
    }
}

void func_00279528(char *base, ScriptCtx *ctx) {
    Wkf0f4f8 *w = SLOT_WORK(Wkf0f4f8, base, ctx, 1);

    w->f0 = w->f4 = w->f8 = 0.0f;
}

void func_00279550(char *base, ScriptCtx *ctx) {
    func_00279528(base, ctx);
}

void func_00279558(ScriptWork *base, T6_VKeyF *k, ScriptCtx *ctx)
{
    float *v = SLOT_WORK(float, base, ctx, 0);
    float *d = SLOT_WORK(float, base, ctx, 1);

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            d[0] += k->d[0];
            d[1] += k->d[1];
            d[2] += k->d[2];
        }
        v[0] += d[0];
        v[1] += d[1];
        v[2] += d[2];
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_278C40", func_00279600);

void func_00279728(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
}

void func_00279740(char *base, ScriptCtx *ctx) {
    Wkf8fCf14f18 *w = SLOT_WORK(Wkf8fCf14f18, base, ctx, 2);

    w->f8 = w->fC = w->f14 = w->f18 = 0.0f;
}

void func_00279768(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_278C40", func_00279770);

void func_00279BF0(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h0 = 0;
    w->h2 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_278C40", func_00279C10);

INCLUDE_ASM("build/ee_asm/game/particle/particle_278C40", func_00279D28);
