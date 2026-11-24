/* tu_312 0x28fdd8-0x291120: low; unk_28FDD8 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/u4.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/q6.h"

void func_0028FDD8(ScriptWork *base, void *ev, ScriptCtx *ctx)
{
    WkRing *w;
    Vec4 *p;
    int n;
    Vec4 v;

    if (D_006A3BC4 == 0) {
        w = SLOT_WORK(WkRing, base, ctx, 0);
        if (base->owner == 0) {
            p = w->v;
            func_002DD0B0(&v, &base->f40);
            v.w = 1.0f;
            for (n = w->count; n > 0; n--) {
                func_002DD0B0(p, &v);
                p++;
            }
        }
        if (w->cur == 0) {
            w->cur = w->count;
        }
        w->cur--;
        func_00282798(&w->v[w->cur], &base->f40);
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28FDD8", func_0028FEB8);

void func_00290550(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4 *w = SLOT_WORK(Wkb0b1h2h4, base, ctx, 0);

    w->b0 = 0x1F;
    w->h4 = 0;
    w->b1 = 0;
    w->h2 = 0;
}

typedef struct Wk290578 {
    s16 a[4];
    s16 b[4];
    s16 va[4];
    s16 aa[4];
    s16 vb[4];
    s16 ab[4];
    Vec4 ring[28];
    u8 pad1F0[8];
    u8 cur;
} Wk290578;

typedef struct Ev290578 {
    s32 frame;
    u8 pad4[0x1C];
    s16 a[4];
    s16 b[4];
    s16 va[4];
    s16 aa[4];
    s16 vb[4];
    s16 ab[4];
} Ev290578;

void func_00290578(ScriptWork *base, Ev290578 *ev, ScriptCtx *ctx)
{
    Wk290578 *w;
    Vec4 *p;
    int n;
    Vec4 v;

    if (D_006A3BC4 != 0) {
        return;
    }
    w = SLOT_WORK(Wk290578, base, ctx, 0);
    if (base->owner == 0) {
        p = w->ring;
        func_002DD0B0(&v, &base->f40);
        v.w = 1.0f;
        for (n = 28; n > 0; n--) {
            func_002DD0B0(p, &v);
            p++;
        }
    }
    if (w->cur == 0) {
        w->cur = 28;
    }
    w->cur--;
    func_00282798(&w->ring[w->cur], &base->f40);
    w->va[0] += w->aa[0];
    w->a[0] += w->va[0];
    w->va[1] += w->aa[1];
    w->a[1] += w->va[1];
    w->va[2] += w->aa[2];
    w->a[2] += w->va[2];
    w->va[3] += w->aa[3];
    w->a[3] += w->va[3];
    w->vb[0] += w->ab[0];
    w->b[0] += w->vb[0];
    w->vb[1] += w->ab[1];
    w->b[1] += w->vb[1];
    w->vb[2] += w->ab[2];
    w->b[2] += w->vb[2];
    w->vb[3] += w->ab[3];
    w->b[3] += w->vb[3];
    if (base->owner == ev->frame) {
        w->a[0] += ev->a[0];
        w->a[1] += ev->a[1];
        w->a[2] += ev->a[2];
        w->a[3] += ev->a[3];
        w->va[0] += ev->va[0];
        w->va[1] += ev->va[1];
        w->va[2] += ev->va[2];
        w->va[3] += ev->va[3];
        w->aa[0] += ev->aa[0];
        w->aa[1] += ev->aa[1];
        w->aa[2] += ev->aa[2];
        w->aa[3] += ev->aa[3];
        w->b[0] += ev->b[0];
        w->b[1] += ev->b[1];
        w->b[2] += ev->b[2];
        w->b[3] += ev->b[3];
        w->vb[0] += ev->vb[0];
        w->vb[1] += ev->vb[1];
        w->vb[2] += ev->vb[2];
        w->vb[3] += ev->vb[3];
        w->ab[0] += ev->ab[0];
        w->ab[1] += ev->ab[1];
        w->ab[2] += ev->ab[2];
        w->ab[3] += ev->ab[3];
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28FDD8", func_002908D0);

void func_00291090(char *base, ScriptCtx *ctx)
{
    Wkq0q8q10q18q20q28w1F0h1F4b1F8 *w = SLOT_WORK(Wkq0q8q10q18q20q28w1F0h1F4b1F8, base, ctx, 0);

    w->b1F8 = 0;
    w->h1F4 = 0;
    w->w1F0 = 0;
    w->h1F6 = func_002EFD78();
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
}

void func_002910E8(char *base, ScriptCtx *ctx) {
    Wkq0q8q10q18q20q28w1F0h1F4b1F8 *w = SLOT_WORK(Wkq0q8q10q18q20q28w1F0h1F4b1F8, base, ctx, 0);

    w->b1F8 = 0;
    w->h1F4 = 0;
    w->w1F0 = 0;
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
}
