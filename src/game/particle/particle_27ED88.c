/* tu_304 0x27ed88-0x27f2e8: low; unk_27ED88 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_0027ED88(int a, R6Wvec *w) {
    w->w0 = a;
    w->w8 = 0;
    w->w4 = 0;
}

void func_0027ED98(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 1);

    w->w0 = 0;
}

void func_0027EDB0(void) {
}

void func_0027EDB8(void) {
}

void func_0027EDC0(char *base, U4WrapKey *k, ScriptCtx *ctx)
{
    R6Wvec *w = SLOT_WORK(R6Wvec, base, ctx, 1);

    if (w->w0 == 0) {
        func_0027ED88((int)k, w);
    }
    func_0027EE38(base, k, ctx);
    func_0027EED0(base, k, ctx);
}

void func_0027EE38(char *base, U4WrapKey *k, ScriptCtx *ctx)
{
    U4WrapPos *p = SLOT_WORK(U4WrapPos, base, ctx, 1);
    u32 w;
    u32 h;

    p->x += k->dx;
    p->y += k->dy;
    w = k->w << 8;
    h = k->h << 8;
    if (p->x < 0) {
        p->x += w;
    }
    if ((u32)p->x >= w) {
        p->x -= w;
    }
    if (p->y < 0) {
        p->y += h;
    }
    if ((u32)p->y >= h) {
        p->y -= h;
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27ED88", func_0027EED0);

void func_0027F178(int a) {
    func_00270C80(a);
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_27ED88", func_0027F180);
