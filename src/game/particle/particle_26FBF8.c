/* tu_296 0x26fbf8-0x270220: low; unk_26FBF8 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/w9.h"
#include "ffx/u4.h"

float func_0026FBF8(float a, float b) {
    return a * b;
}

float func_0026FC00(u8 range) {
    float a;
    float b;
    register int t __asm__("$8");

    MIPS_ADDI0(t, -1);
    VU0_QMTC2_NI(2, t);
    VU0_OP("vrxor R, $vf2x");
    VU0_OP("vitof0.x $vf2, $vf2");
    VU0_OP("vrnext.x $vf1, R");
    VU0_OP("vadd.x $vf1, $vf1, $vf2");
    VU0_QMFC2_NI(a, 1);
    if (range != 0) {
        MIPS_ADDI0(t, -1);
        VU0_QMTC2_NI(2, t);
        VU0_OP("vrxor R, $vf2x");
        VU0_OP("vitof0.x $vf2, $vf2");
        VU0_OP("vrnext.x $vf1, R");
        VU0_OP("vadd.x $vf1, $vf1, $vf2");
        VU0_QMFC2_NI(b, 1);
        a = (a + b) * 0.5f;
    }
    return a;
}

void func_0026FC68(ScriptWork *base, T6_FxKeyF *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_0026FC00(k->range);
            v[1] = func_0026FC00(k->range);
            v[2] = func_0026FC00(k->range);
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
        } else {
            dst = (float *)D_006EA450; /* DEBT(CAST): scratch target */
        }
        dst[0] += func_0026FBF8(k->d[0], v[0]);
        dst[1] += func_0026FBF8(k->d[1], v[1]);
        dst[2] += func_0026FBF8(k->d[2], v[2]);
    }
}

float func_0026FD70(float a, float b) {
    return a * b;
}

float func_0026FD78(u8 range) {
    float a;
    float b;
    register int t __asm__("$8");

    MIPS_ADDI0(t, -1);
    VU0_QMTC2_NI(2, t);
    VU0_OP("vrxor R, $vf2x");
    VU0_OP("vitof0.x $vf2, $vf2");
    VU0_OP("vrnext.x $vf1, R");
    VU0_OP("vadd.x $vf1, $vf1, $vf2");
    VU0_QMFC2_NI(a, 1);
    a = -a;
    if (range != 0) {
        MIPS_ADDI0(t, -1);
        VU0_QMTC2_NI(2, t);
        VU0_OP("vrxor R, $vf2x");
        VU0_OP("vitof0.x $vf2, $vf2");
        VU0_OP("vrnext.x $vf1, R");
        VU0_OP("vadd.x $vf1, $vf1, $vf2");
        VU0_QMFC2_NI(b, 1);
        a = (a - b) * 0.5f;
    }
    return a;
}

void func_0026FDE0(ScriptWork *base, T6_FxKeyF *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_0026FD78(k->range);
            v[1] = func_0026FD78(k->range);
            v[2] = func_0026FD78(k->range);
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
        } else {
            dst = (float *)D_006EA450; /* DEBT(CAST): scratch target */
        }
        dst[0] += func_0026FD70(k->d[0], v[0]);
        dst[1] += func_0026FD70(k->d[1], v[1]);
        dst[2] += func_0026FD70(k->d[2], v[2]);
    }
}

s8 func_0026FEE8(s8 a, float s) {
    return a * s - a;
}

float func_0026FF18(u8 range) {
    float a;
    float b;
    register int t __asm__("$8");

    MIPS_ADDI0(t, -1);
    VU0_QMTC2_NI(2, t);
    VU0_OP("vrxor R, $vf2x");
    VU0_OP("vitof0.x $vf2, $vf2");
    VU0_OP("vrnext.x $vf1, R");
    VU0_OP("vadd.x $vf1, $vf1, $vf2");
    VU0_QMFC2_NI(a, 1);
    if (range != 0) {
        MIPS_ADDI0(t, -1);
        VU0_QMTC2_NI(2, t);
        VU0_OP("vrxor R, $vf2x");
        VU0_OP("vitof0.x $vf2, $vf2");
        VU0_OP("vrnext.x $vf1, R");
        VU0_OP("vadd.x $vf1, $vf1, $vf2");
        VU0_QMFC2_NI(b, 1);
        a += b;
    } else {
        a += a;
    }
    return a;
}


void func_0026FF70(ScriptWork *base, T6_FxKeyB *k, ScriptCtx *ctx)
{
    float *v;
    u8 *dst;

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_0026FF18(k->range);
            v[1] = func_0026FF18(k->range);
            v[2] = func_0026FF18(k->range);
            v[3] = func_0026FF18(k->range);
            if (k->dst != -1) {
                dst = (u8 *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
            } else {
                dst = (u8 *)D_006EA450; /* DEBT(CAST): scratch target */
            }
            dst[0] += func_0026FEE8(k->d[0], v[0]);
            dst[1] += func_0026FEE8(k->d[1], v[1]);
            dst[2] += func_0026FEE8(k->d[2], v[2]);
            dst[3] += func_0026FEE8(k->d[3], v[3]);
        }
    }
}

s8 func_00270080(s8 a, float s) {
    return a * s;
}

float func_002700A8(u8 range) {
    float a;
    float b;
    register int t __asm__("$8");

    MIPS_ADDI0(t, -1);
    VU0_QMTC2_NI(2, t);
    VU0_OP("vrxor R, $vf2x");
    VU0_OP("vitof0.x $vf2, $vf2");
    VU0_OP("vrnext.x $vf1, R");
    VU0_OP("vadd.x $vf1, $vf1, $vf2");
    VU0_QMFC2_NI(a, 1);
    if (range != 0) {
        MIPS_ADDI0(t, -1);
        VU0_QMTC2_NI(2, t);
        VU0_OP("vrxor R, $vf2x");
        VU0_OP("vitof0.x $vf2, $vf2");
        VU0_OP("vrnext.x $vf1, R");
        VU0_OP("vadd.x $vf1, $vf1, $vf2");
        VU0_QMFC2_NI(b, 1);
        a = (a + b) * 0.5f;
    }
    return a;
}

void func_00270110(ScriptWork *base, T6_FxKeyB *k, ScriptCtx *ctx)
{
    float *v;
    u8 *dst;

    if (D_006A3BC4 == 0) {
        if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_002700A8(k->range);
            v[1] = func_002700A8(k->range);
            v[2] = func_002700A8(k->range);
            v[3] = func_002700A8(k->range);
            if (k->dst != -1) {
                dst = (u8 *)((char *)base + (k->dst + 0xA0)); /* DEBT(CAST): work area named by the key */
            } else {
                dst = (u8 *)D_006EA450; /* DEBT(CAST): scratch target */
            }
            dst[0] += func_00270080(k->d[0], v[0]);
            dst[1] += func_00270080(k->d[1], v[1]);
            dst[2] += func_00270080(k->d[2], v[2]);
            dst[3] += func_00270080(k->d[3], v[3]);
        }
    }
}
