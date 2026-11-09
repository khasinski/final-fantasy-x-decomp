/* tu_308 0x288570-0x289808: low; unk_288570 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/u4.h"
#include "ffx/w9.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/particle/particle_288570", func_00288570);

INCLUDE_ASM("build/ee_asm/game/particle/particle_288570", func_00288780);

void func_00288910(ScriptWork *base, void *ev, ScriptCtx *ctx)
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

INCLUDE_ASM("build/ee_asm/game/particle/particle_288570", func_002889F0);

void func_00289058(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4 *w = SLOT_WORK(Wkb0b1h2h4, base, ctx, 0);

    w->b0 = 0x1F;
    w->h4 = 0;
    w->b1 = 0;
    w->h2 = 0;
}

void func_00289080(ScriptWork *base, void *ev, ScriptCtx *ctx)
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

INCLUDE_ASM("build/ee_asm/game/particle/particle_288570", func_00289160);

void func_002897E0(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4 *w = SLOT_WORK(Wkb0b1h2h4, base, ctx, 0);

    w->b0 = 0x1F;
    w->h4 = 0;
    w->b1 = 0;
    w->h2 = 0;
}
