/* tu_311 0x28d740-0x28fdd8: low; unk_28D740 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/r6.h" /* needed by t6.h (R6Fvec) */
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_0028D740(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 0);

    w->w0 = 0;
    w->w4 = 0;
    w->w8 = 0;
}

void func_0028D760(T6_SWorkMtx *base, void *msg, ScriptCtx *ctx)
{
    void *dst = SLOT_WORK(void, base, ctx, 1);

    func_002DCE38(base->b, D_006A39B0, base->a);
    func_002DD0C0(dst, base->b);
    func_002DCE38(base->b, D_006A3A70, base->b);
}

void func_0028D7D0(T6_SWorkMtx *base, void *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    void *dst = SLOT_WORK(void, base, ctx, 1);

    func_002DD068(base->b[0], base->a[0], mgr->m60[0]);
    func_002DD068(base->b[1], base->a[1], mgr->m60[1]);
    func_002DD068(base->b[2], base->a[2], mgr->m60[2]);
    func_002DCE08(base->b[3], D_006A39B0, base->a[3]);
    func_002DD0C0(dst, base->b);
    func_002DCE38(base->b, D_006A3A70, base->b);
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028D888);

void func_0028D990(T6_SWorkMtx *base, void *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;

    func_002DCE38(SLOT_WORK(void, base, ctx, 1), D_006A39B0, SLOT_WORK(void, base, ctx, 0));
    func_002DD068(base->b[0], base->a[0], mgr->m60[0]);
    func_002DD068(base->b[1], base->a[1], mgr->m60[1]);
    func_002DD068(base->b[2], base->a[2], mgr->m60[2]);
    func_002DCE08(base->b[3], D_006A39B0, base->a[3]);
    func_002DCE38(base->b, D_006A3A70, base->b);
}

void func_0028DA50(T6_SWorkMtx *base, void *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_Row *dst = SLOT_WORK(T6_Row, base, ctx, 1);
    T6_Row *src = SLOT_WORK(T6_Row, base, ctx, 0);

    func_002DD068(dst[0], src[0], mgr->m60[0]);
    func_002DD068(dst[1], src[1], mgr->m60[1]);
    func_002DD068(dst[2], src[2], mgr->m60[2]);
    func_002DCE08(dst[3], D_006A39B0, src[3]);
    func_002DD068(base->b[0], base->a[0], mgr->m60[0]);
    func_002DD068(base->b[1], base->a[1], mgr->m60[1]);
    func_002DD068(base->b[2], base->a[2], mgr->m60[2]);
    func_002DCE08(base->b[3], D_006A39B0, base->a[3]);
    func_002DCE38(base->b, D_006A3A70, base->b);
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028DB58);

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028DD08);

void func_0028DEB8(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8fCf10f14 *w = SLOT_WORK(Wkf0f4f8fCf10f14, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->fC = w->f10 = w->f14 = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028DEE8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028E148);

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028E4A0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028E6B0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028E938);

void func_0028EB80(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8fCf10f14 *w = SLOT_WORK(Wkf0f4f8fCf10f14, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->fC = w->f10 = w->f14 = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028EBB0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028EEC8);

void func_0028F0D8(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
    w->w4 = 0;
    w->w8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028F0F8);

void func_0028F3A8(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8f10f14f18f1Cf20f24 *w = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->f10 = w->f14 = w->f18 = w->f1C = w->f20 = w->f24 = 0.0f;
}

void func_0028F3E8(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h2 = 0;
    w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028F408);

void func_0028F650(char *base, void *ev, ScriptCtx *ctx)
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

INCLUDE_ASM("build/ee_asm/game/particle/particle_28D740", func_0028F730);

void func_0028FDB0(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4 *w = SLOT_WORK(Wkb0b1h2h4, base, ctx, 0);

    w->b0 = 0x1F;
    w->h4 = 0;
    w->b1 = 0;
    w->h2 = 0;
}
