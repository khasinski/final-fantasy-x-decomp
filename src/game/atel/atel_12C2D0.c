/* tu_054 0x12c2d0-0x12c788: low; unk_12C2D0 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#define func_0012C3B0 _hdr_func_0012C3B0
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_0012C3B0

int func_0012C2D0(Actor *a) {
    return (func_0013C9C8(a, a->slotIdx)->info->flags & 0x1F) != 0;
}

int func_0012C300(Actor *a) {
    return (a->slot[a->slotIdx].flags & 0x7F) != 0;
}

int func_0012C320(Actor *a, void *op, ScriptCtx *ctx)
{
    int d = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);

    a->arrAE0[0] = AtelPopStackInteger(a, ctx);
    a->arrAE0[1] = b;
    a->arrAE0[2] = c;
    a->arrAE0[3] = d;
    return 0;
}

float _m2c_func_0012C3B0_func_0014D7E0(void) __asm__("func_0014D7E0");
/* DEBT(CAST) */
s32 func_0012C3B0(void *arg0) {
    float var_f20;
    s32 temp_5;
    s32 var_16;

    temp_5 = (*(u8 *)((u8 *)(arg0) + (0x32))) * 0x44;
    var_f20 = (*(float *)((u8 *)((((void *)((u8 *)(temp_5) + (s32)arg0)))) + (0x890)));
    var_16 = 0;
    if (var_f20 > 0.0f) {
        var_16 = 1;
    }
    if (var_f20 < 0.0f) {
        var_f20 = -var_f20;
    }
    if (((_m2c_func_0012C3B0_func_0014D7E0() * 3.1415927f) / 180.0f) <= var_f20) {
        var_16 |= 2;
    }
    return var_16;
}

int func_0012C450(Actor *a, void *op, ScriptCtx *ctx) {
    return a->arrAE0[AtelPopStackInteger(a, ctx)];
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12C2D0", func_0012C488);

int func_0012C610(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ActorSlotB *s = &a->slotB[a->slotIdx];
    int v1 = AtelPopStackInteger(a, ctx);
    int v2 = AtelPopStackInteger(a, ctx);
    int v3 = AtelPopStackInteger(a, ctx);
    float diff = __builtin_fabsf(func_002D4338(s->f20 - st->f34));
    float res;

    if (v3 & 2) {
        diff /= 3.1415927f;
        if (diff >= 1.0f) {
            diff = 1.0f;
        }
        res = (float)v1 * diff;
    } else {
        diff /= 1.5707964f;
        if (diff >= 1.0f) {
            diff = 1.0f;
        }
        res = (float)v2 * diff;
    }
    return (int)res;
}

float func_0012C748(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0013A378(a, AtelPopStackInteger(a, ctx))->h06;
}
