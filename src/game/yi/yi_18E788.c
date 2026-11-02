/* tu_143 0x18e788-0x18e9c8: low; unk_18E788 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_0018E788(Actor *a, void *op, ScriptCtx *ctx) {
    int n0;
    float f0, f1;

    f1 = AtelPopStackFloat(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019CB18(n0, f0, f1);
    return 1;
}

int func_0018E800(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int idx = AtelPopStackInteger(a, ctx);

    func_0019CB18(idx, f, func_0019CC98(idx));
    return 1;
}

int func_0018E870(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int idx = AtelPopStackInteger(a, ctx);

    func_0019CB18(idx, func_0019CC38(idx), f);
    return 1;
}

int func_0018E8E0(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;
    float f0, f1;

    n1 = AtelPopStackInteger(a, ctx);
    f1 = AtelPopStackFloat(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019CB98(n0, f0, f1, n1);
    return 1;
}

float func_0018E978(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019CC38(AtelPopStackInteger(a, ctx));
}

float func_0018E9A0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019CC98(AtelPopStackInteger(a, ctx));
}
