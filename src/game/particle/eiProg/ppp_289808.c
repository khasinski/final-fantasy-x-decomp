/* tu_309 0x289808-0x28b480: low; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/u4.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/q6.h"

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_00289808);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_00289B68);

void func_0028A2F8(char *base, ScriptCtx *ctx)
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

void func_0028A350(char *base, ScriptCtx *ctx) {
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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_0028A388);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", pppKeShpTailPhtDraw);

void func_0028B050(char *base, ScriptCtx *ctx)
{
    Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4 *w = SLOT_WORK(Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4, base, ctx, 0);

    w->b1F4 = 0;
    w->h1F0 = 0;
    w->w1EC = 0;
    w->h1F2 = func_002EFD78();
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
    w->f1E0 = w->f1E4 = w->f1E8 = 0.0f;
}

void func_0028B0B8(char *base, ScriptCtx *ctx)
{
    Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4 *w = SLOT_WORK(Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4, base, ctx, 0);

    w->b1F4 = 0;
    w->h1F0 = 0;
    w->w1EC = 0;
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
    w->f1E0 = w->f1E4 = w->f1E8 = 0.0f;
}

void func_0028B100(void) {
}

void func_0028B108(void) {
}

void func_0028B110(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4b6 *w = SLOT_WORK(Wkb0b1h2h4b6, base, ctx, 0);

    w->h2 = 0;
    w->h4 = 0;
    w->b1 = 0;
    w->b0 = 0x1F;
    w->b6 = 0;
}

void func_0028B140(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_0028B148);

void func_0028B460(char *base, ScriptCtx *ctx) {
    Wkq0w8 *w = SLOT_WORK(Wkq0w8, base, ctx, 0);

    w->q0 = 0;
    w->w8 = 0;
}
