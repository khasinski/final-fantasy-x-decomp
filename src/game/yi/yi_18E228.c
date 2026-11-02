/* tu_142 0x18e228-0x18e788: medium; unk_18E228 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_0018E228(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    v[3] = 0;
    v[2] = AtelPopStackInteger(a, ctx);
    v[1] = AtelPopStackInteger(a, ctx);
    v[0] = AtelPopStackInteger(a, ctx);
    func_00173A38(v);
    return 1;
}

int func_0018E290(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    func_00173888(v);
    v[0] = AtelPopStackInteger(a, ctx);
    func_00173A38(v);
    return 1;
}

int func_0018E2E0(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    func_00173888(v);
    v[1] = AtelPopStackInteger(a, ctx);
    func_00173A38(v);
    return 1;
}

int func_0018E330(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    func_00173888(v);
    v[2] = AtelPopStackInteger(a, ctx);
    func_00173A38(v);
    return 1;
}

int func_0018E380(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    func_00173888(v);
    return v[0];
}

int func_0018E3A0(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    func_00173888(v);
    return v[1];
}

int func_0018E3C0(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    func_00173888(v);
    return v[2];
}

int func_0018E3E0(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    v[3] = 0;
    v[2] = AtelPopStackInteger(a, ctx);
    v[1] = AtelPopStackInteger(a, ctx);
    v[0] = AtelPopStackInteger(a, ctx);
    func_00173650(v);
    return 1;
}

int func_0018E448(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    yiGetBackColor(v);
    v[0] = AtelPopStackInteger(a, ctx);
    func_00173650(v);
    return 1;
}

int func_0018E498(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    yiGetBackColor(v);
    v[1] = AtelPopStackInteger(a, ctx);
    func_00173650(v);
    return 1;
}

int func_0018E4E8(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    yiGetBackColor(v);
    v[2] = AtelPopStackInteger(a, ctx);
    func_00173650(v);
    return 1;
}

int func_0018E538(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    yiGetBackColor(v);
    return v[0];
}

int func_0018E558(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    yiGetBackColor(v);
    return v[1];
}

int func_0018E578(Actor *a, void *op, ScriptCtx *ctx) {
    int v[4];

    yiGetBackColor(v);
    return v[2];
}

int func_0018E598(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);

    func_0019C8E0(AtelPopStackInteger(a, ctx), f, f);
    return 1;
}

int func_0018E5F8(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);

    func_0019C8E0(AtelPopStackInteger(a, ctx), f, 0.0f);
    return 1;
}

int func_0018E658(Actor *a, void *op, ScriptCtx *ctx) {
    float f0;
    int n0;

    f0 = AtelPopStackFloat(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C8E0(n0, 0.0f, f0);
    return 1;
}

int func_0018E6B8(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    float f = AtelPopStackFloat(a, ctx);

    func_0019C980(AtelPopStackInteger(a, ctx), f, f, n);
    return 1;
}

float func_0018E738(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019CA58(AtelPopStackInteger(a, ctx));
}

float func_0018E760(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019CAB8(AtelPopStackInteger(a, ctx));
}
