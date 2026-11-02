/* tu_295 0x26f218-0x26fbf8: low; unk_26F218 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/t6.h"
#include "ffx/w9.h"

s8 func_0026F218(s8 a, float s) {
    return a * s - a;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026F248);

s8 func_0026F380(s8 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026F3A8);

s8 func_0026F4E8(s8 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026F510);

s16 func_0026F650(s16 a, float s) {
    return a * s - a;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026F680);

s16 func_0026F7B8(s16 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026F7E0);

s16 func_0026F920(s16 a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026F948);

float func_0026FA88(float a, float b) {
    return a * b - a;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26F218", func_0026FA98);

void func_0026FAF0(ScriptWork *base, T6_FxKeyF *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            v = SLOT_WORK(float, base, ctx, 0);
            v[0] = func_0026FA98(k->range);
            v[1] = func_0026FA98(k->range);
            v[2] = func_0026FA98(k->range);
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
        dst[0] += func_0026FA88(k->d[0], v[0]);
        dst[1] += func_0026FA88(k->d[1], v[1]);
        dst[2] += func_0026FA88(k->d[2], v[2]);
    }
}
