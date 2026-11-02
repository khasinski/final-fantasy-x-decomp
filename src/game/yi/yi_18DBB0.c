/* tu_140 0x18dbb0-0x18df18: low; unk_18DBB0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_0018DBB0(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1, n2, n3;
    float f0;

    n3 = AtelPopStackInteger(a, ctx);
    n2 = AtelPopStackInteger(a, ctx);
    n1 = AtelPopStackInteger(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C630(n0, f0, n1, n2, n3);
    return 1;
}

int func_0018DC60(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C678();
    return 1;
}

int func_0018DC80(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C6A8(AtelPopStackFloat(a, ctx));
    return 1;
}

int func_0018DCA8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C6E0();
}

int func_0018DCC8(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;
    float f0, f1;

    f1 = AtelPopStackFloat(a, ctx);
    n1 = AtelPopStackInteger(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C718(n0, f0, n1, f1);
    return 1;
}

int func_0018DD60(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C758();
    return 1;
}

int func_0018DD80(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C788();
    return 1;
}

int func_0018DDA0(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C7C8();
    return 1;
}

int func_0018DDC0(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;

    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C810(n0, n1);
    return 1;
}

int func_0018DE20(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C878(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018DE48(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;

    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C1B0(n0, n1);
    return 1;
}

int func_0018DEA8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C218(AtelPopStackInteger(a, ctx));
}

int func_0018DED0(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019CEC0(AtelPopStackFloat(a, ctx));
    return 1;
}

float func_0018DEF8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019CEF0();
}
