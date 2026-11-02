/* tu_139 0x18d7f8-0x18dbb0: low; unk_18D7F8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_0018D7F8(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1, n2;

    n2 = AtelPopStackInteger(a, ctx);
    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019BF20(n0, n1, n2);
    return 1;
}

int func_0018D870(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019BF98(AtelPopStackInteger(a, ctx));
}

int func_0018D898(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C000(AtelPopStackInteger(a, ctx));
}

int func_0018D8C0(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1, n2;

    n2 = AtelPopStackInteger(a, ctx);
    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C068(n0, n1, n2);
    return 1;
}

int func_0018D938(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C0E0(AtelPopStackInteger(a, ctx));
}

int func_0018D960(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C148(AtelPopStackInteger(a, ctx));
}

int func_0018D988(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C280(AtelPopStackInteger(a, ctx));
}

int func_0018D9B0(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;

    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C2E8(n0, n1);
    return 1;
}

int func_0018DA10(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C350(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018DA38(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C3B8(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018DA60(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C428(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018DA88(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019C490(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018DAB0(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;

    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019C500(n0, n1);
    return 1;
}

int func_0018DB10(Actor *a, void *op, ScriptCtx *ctx) {
    float f0, f1;

    f1 = AtelPopStackFloat(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    func_0019C580(f0, f1);
    return 1;
}

int func_0018DB70(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C5C0();
}

int func_0018DB90(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019C5F8();
}
