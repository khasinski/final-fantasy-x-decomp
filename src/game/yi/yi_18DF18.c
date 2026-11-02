/* tu_141 0x18df18-0x18e228: medium; unk_18DF18 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_0018DF18(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019D038();
    return 1;
}

int func_0018DF38(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    if (on) {
        func_0026A6B8(id);
    } else {
        func_0026A710(id);
    }
    return on;
}

int func_0018DFA8(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    if (on) {
        func_0026A838(id);
    } else {
        func_0026A8A0(id);
    }
    return on;
}

int func_0018E018(Actor *a, void *op, ScriptCtx *ctx) {
    float f0, f1, f2;

    f2 = AtelPopStackFloat(a, ctx);
    f1 = AtelPopStackFloat(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    func_001739D0(f0, f1, f2);
    return 1;
}

int func_0018E090(Actor *a, void *op, ScriptCtx *ctx) {
    float x, y, z;

    func_00173828(&x, &y, &z);
    x = AtelPopStackFloat(a, ctx);
    func_001739D0(x, y, z);
    return 1;
}

float func_0018E0F0(Actor *a, void *op, ScriptCtx *ctx) {
    float x, y, z;

    func_00173828(&x, &y, &z);
    return x;
}

int func_0018E118(Actor *a, void *op, ScriptCtx *ctx) {
    float x, y, z;

    func_00173828(&x, &y, &z);
    y = AtelPopStackFloat(a, ctx);
    func_001739D0(x, y, z);
    return 1;
}

float func_0018E178(Actor *a, void *op, ScriptCtx *ctx) {
    float x, y, z;

    func_00173828(&x, &y, &z);
    return y;
}

int func_0018E1A0(Actor *a, void *op, ScriptCtx *ctx) {
    float x, y, z;

    func_00173828(&x, &y, &z);
    z = AtelPopStackFloat(a, ctx);
    func_001739D0(x, y, z);
    return 1;
}

float func_0018E200(Actor *a, void *op, ScriptCtx *ctx) {
    float x, y, z;

    func_00173828(&x, &y, &z);
    return z;
}
