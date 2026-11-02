/* tu_312 0x28fdd8-0x291120: low; unk_28FDD8 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/u4.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/q6.h"

void func_0028FDD8(char *base, void *ev, ScriptCtx *ctx)
{
    WkRing *w;
    Vec4 *p;
    int n;
    Vec4 v;

    if (D_006A3BC4 == 0) {
        w = SLOT_WORK(WkRing, base, ctx, 0);
        if (((ScriptWork *)base)->owner == 0) { /* DEBT(CAST): base is the script memory header */
            p = w->v;
            func_002DD0B0(&v, base + 0x40);
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
        func_00282798(&w->v[w->cur], base + 0x40);
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

INCLUDE_ASM("build/ee_asm/game/particle/particle_28FDD8", func_00290578);

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
