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

void _m2c_func_0028EEC8_func_00282B88(s32, s32, u8 *, float) __asm__("func_00282B88");
void _m2c_func_0028EEC8_func_00282E68(void *, s32, void *, s32, s32, s32, s32, void *, u16 *, s32) __asm__("func_00282E68");
void _m2c_func_0028EEC8_func_002B2A28(u8 *, s32, s32, s32) __asm__("func_002B2A28");
void _m2c_func_0028EEC8_func_002DAC50(u8 *, u8 *) __asm__("func_002DAC50");
void _m2c_func_0028EEC8_func_002F8660(s32, s32) __asm__("func_002F8660");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0028EEC8(void *arg0, void *arg1, void *arg2) {
    float temp_f1;
    float temp_f2;
    float temp_f3;
    s32 temp_22;
    s32 temp_5;
    u32 temp_7;
    u8 *temp_17_2;
    u8 *temp_18;
    u8 *temp_19;
    void *temp_17;
    void *temp_3;

    temp_17 = arg0 + ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg2) + (0xC)))) + (8))) + 0xA0);
    if (D_006A3BC4 == 0) {
        temp_f3 = (*(float *)((u8 *)(temp_17) + (8)));
        temp_f2 = (*(float *)((u8 *)(temp_17) + (4))) + temp_f3;
        temp_f1 = (*(float *)((u8 *)(temp_17) + (0))) + temp_f2;
        (*(float *)((u8 *)(temp_17) + (4))) = temp_f2;
        (*(float *)((u8 *)(temp_17) + (0))) = temp_f1;
        if ((*(s32 *)((u8 *)(arg0) + (0xC))) == (*(s32 *)((u8 *)(arg1) + (0)))) {
            (*(float *)((u8 *)(temp_17) + (0))) = (float) (temp_f1 + (*(float *)((u8 *)(arg1) + (8))));
            (*(float *)((u8 *)(temp_17) + (4))) = (float) (temp_f2 + (*(float *)((u8 *)(arg1) + (0xC))));
            (*(float *)((u8 *)(temp_17) + (8))) = (float) (temp_f3 + (*(float *)((u8 *)(arg1) + (0x10))));
        }
    }
    temp_5 = (*(s32 *)((u8 *)(arg1) + (4)));
    if (temp_5 != 0xFFFF) {
        temp_22 = (*(u8 *)((u8 *)(arg1) + (0x1C))) * 4;
        temp_7 = (*(u32 *)((u8 *)(((*(s32 *)((u8 *)(D_006A3924) + (0x20))) + (temp_5 << 5))) + (0x10)));
        temp_18 = D_006A3BCC + 0x10;
        func_002DA928(temp_18, ((temp_7 >> 5) & 0x3FFF) + temp_22, 4, (temp_7 >> 0x13) & 0xF, 0, 0, 0x10, 0x10);
        temp_19 = D_006A3BCC;
        temp_17_2 = temp_19 + 0x70;
        _m2c_func_0028EEC8_func_00282B88((*(s32 *)((u8 *)(arg1) + (0x14))), (*(s32 *)((u8 *)(arg1) + (0x18))), temp_17_2, (*(float *)((u8 *)(temp_17) + (0))));
        if ((*(u8 *)((u8 *)(arg1) + (0x1D))) & 2) {
            s32 c107 = 0x107;
            __asm__ volatile("" : "+r"(c107));
            _m2c_func_0028EEC8_func_002F8660(0, c107);
            _m2c_func_0028EEC8_func_002DAC50(temp_18, temp_17_2);
        } else {
            (*(u64 *)((u8 *)(temp_18) + (0x50))) = (0x08000000ULL << 32) | 0x8100;
            _m2c_func_0028EEC8_func_002B2A28(D_006A3BCC, 0x107, 0, 0);
            D_006A3BCC = temp_19 + 0x1070;
        }
        temp_3 = (*(void **)((u8 *)(arg2) + (0xC)));
        _m2c_func_0028EEC8_func_00282E68(arg0, (*(s32 *)((u8 *)(arg1) + (4))), arg0 + ((*(s32 *)((u8 *)(temp_3) + (0))) + 0xA0), temp_22, 0, 0, (((*(u8 *)((u8 *)(arg1) + (0x1D))) | (*(u8 *)((u8 *)(arg1) + (0x20)))) | ((*(u8 *)((u8 *)(arg1) + (0x1F))) | (*(u8 *)((u8 *)(arg1) + (0x1E))))) | (*(u8 *)((u8 *)(arg1) + (0x21))), arg0 + ((*(s32 *)((u8 *)(temp_3) + (0xC))) + 0xA0), ppvMng->scale, ppvMng->w78);
    }
}

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
