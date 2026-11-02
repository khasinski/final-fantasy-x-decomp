/* tu_297 0x270220-0x270bb8: low; unk_270220 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/w9.h"
#include "ffx/u4.h"

s8 func_00270220(s8 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_270220", func_00270248);

void func_002702B0(ScriptWork *base, T6_FxKeyB *k, ScriptCtx *ctx)
{
    float *v;
    u8 *dst;

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_00270248(k->range);
            v[1] = func_00270248(k->range);
            v[2] = func_00270248(k->range);
            v[3] = func_00270248(k->range);
            if (k->dst != -1) {
                dst = (u8 *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
            } else {
                dst = (u8 *)D_006EA450; /* DEBT(CAST): scratch target */
            }
            dst[0] += func_00270220(k->d[0], v[0]);
            dst[1] += func_00270220(k->d[1], v[1]);
            dst[2] += func_00270220(k->d[2], v[2]);
            dst[3] += func_00270220(k->d[3], v[3]);
        }
    }
}

s8 func_002703C0(s16 a, float s) {
    return a * s - a;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_270220", func_002703F0);

void func_00270448(ScriptWork *base, T6_FxKeyH *k, ScriptCtx *ctx)
{
    float *v;
    u16 *dst;

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_002703F0(k->range);
            v[1] = func_002703F0(k->range);
            v[2] = func_002703F0(k->range);
            v[3] = func_002703F0(k->range);
            if (k->dst != -1) {
                dst = (u16 *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
            } else {
                dst = (u16 *)D_006EA450; /* DEBT(CAST): scratch target */
            }
            dst[0] += func_002703C0(k->d[0], v[0]);
            dst[1] += func_002703C0(k->d[1], v[1]);
            dst[2] += func_002703C0(k->d[2], v[2]);
            dst[3] += func_002703C0(k->d[3], v[3]);
        }
    }
}

s8 func_00270558(s16 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_270220", func_00270580);

void func_002705E8(ScriptWork *base, T6_FxKeyH *k, ScriptCtx *ctx)
{
    float *v;
    u16 *dst;

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_00270580(k->range);
            v[1] = func_00270580(k->range);
            v[2] = func_00270580(k->range);
            v[3] = func_00270580(k->range);
            if (k->dst != -1) {
                dst = (u16 *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
            } else {
                dst = (u16 *)D_006EA450; /* DEBT(CAST): scratch target */
            }
            dst[0] += func_00270558(k->d[0], v[0]);
            dst[1] += func_00270558(k->d[1], v[1]);
            dst[2] += func_00270558(k->d[2], v[2]);
            dst[3] += func_00270558(k->d[3], v[3]);
        }
    }
}

s8 func_002706F8(s16 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_270220", func_00270720);

void func_00270788(ScriptWork *base, T6_FxKeyH *k, ScriptCtx *ctx)
{
    float *v;
    u16 *dst;

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_00270720(k->range);
            v[1] = func_00270720(k->range);
            v[2] = func_00270720(k->range);
            v[3] = func_00270720(k->range);
            if (k->dst != -1) {
                dst = (u16 *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
            } else {
                dst = (u16 *)D_006EA450; /* DEBT(CAST): scratch target */
            }
            dst[0] += func_002706F8(k->d[0], v[0]);
            dst[1] += func_002706F8(k->d[1], v[1]);
            dst[2] += func_002706F8(k->d[2], v[2]);
            dst[3] += func_002706F8(k->d[3], v[3]);
        }
    }
}

void func_00270898(char *base, ScriptCtx *ctx)
{
    U4Wk10 *w = SLOT_WORK(U4Wk10, base, ctx, 0);

    w->f10 = 0.0f;
    w->f14 = 0.0f;
    w->f1C = w->f20 = w->f24 = w->f10;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_270220", func_002708C8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_270220", func_002709B0);
