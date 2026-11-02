/* tu_307 0x2856f0-0x288570: low; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/r6.h" /* needed by t6.h (R6Fvec) */
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_002856F0(char *base, EvMsgB *ev, ScriptCtx *ctx) {
    Wkh0b2 *w;
    int cnt;

    if (D_006A3BC4 == 0) {
        cnt = ev->b7;
        if (cnt != 0) {
            w = SLOT_WORK(Wkh0b2, base, ctx, 0);
            if (w->b2 != 0) {
                w->b2--;
            } else {
                w->b2 = cnt;
                if (ev->wC != 0xFFFFFFFF && ev->w14 != 0xFFFFFFFF) {
                    if (func_0027F180(base, ev, func_00285540, &w->h0, ev->h4, ev->b8, ev->b6)) {
                        w->b2--;
                    }
                }
            }
        }
    }
}

void func_00285790(char *base, ScriptCtx *ctx) {
    Wkh0b2 *w = SLOT_WORK(Wkh0b2, base, ctx, 0);

    w->h0 = 0;
    w->b2 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", KeBornPtCmlp);

void func_002859B8(char *base, EvMsgC *p, ScriptCtx *ctx) {
    int out[4];

    if (D_006A3BC4 == 0) {
        if (p->w8 != 0xFFFFFFFF && p->w10 != 0xFFFFFFFF) {
            KeBornPtCmlp(base, p, ctx, out);
        }
    }
}

void func_00285A00(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 0);

    w->w0 = 0;
}

int func_00285A18(float *v, float *out)
{
    float x = v[0];
    float y = v[1];
    float a;
    double t;

    a = x * y; /* DEBT(FAKE): the product shares the result variable (register steering) */
    if (a > 0.0f) {
        a = -3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
        t = func_002E76D0(func_002ED038(y / x));
        a = func_002EC440(func_002EBBB0(func_002ED038(a), t));
    } else if (a < 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
        t = func_002E76D0(func_002ED038(x / y));
        a = func_002EC440(func_002EBC08(func_002ED038(a), t));
    } else if (x != 0.0f) {
        a = 3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
    } else if (y != 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
    } else {
        return 0;
    }
    *out = a;
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00285B98);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00285CF0);

void func_00285EA8(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
    w->w4 = 0;
    w->w8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00285EC8);

void func_00286110(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8f10f14f18f1Cf20f24 *w = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->f10 = w->f14 = w->f18 = w->f1C = w->f20 = w->f24 = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00286150);

void func_00286348(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
    w->w4 = 0;
    w->w8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00286368);

void func_002865F0(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8f10f14f18f1Cf20f24 *w = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->f10 = w->f14 = w->f18 = w->f1C = w->f20 = w->f24 = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00286630);

void func_00286900(char *base, ScriptCtx *ctx) {
    Wkq0w8 *w = SLOT_WORK(Wkq0w8, base, ctx, 0);

    w->q0 = 0;
    w->w8 = 0;
}

void func_00286920(char *base, ScriptCtx *ctx) {
    Wkq0w8 *w = SLOT_WORK(Wkq0w8, base, ctx, 0);

    w->q0 = 0;
    w->w8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00286940);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00287058);

void func_00287948(void) {
}

void func_00287950(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", pppKeMdlBmpDraw);
