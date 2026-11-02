/* tu_144 0x18e9c8-0x18ef98: low; unk_18E9C8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_0018E9C8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    pppFpSetStickChr(x, func_0013B0F8(AtelPopStackInteger(a, ctx)), y);
    return 1;
}

int func_0018EA48(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);

    pppFpSetStickMap(x, AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EAA8(Actor *a, void *op, ScriptCtx *ctx) {
    func_00269DA8(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EAD0(Actor *a, void *op, ScriptCtx *ctx) {
    float v[3];

    v[0] = AtelPopStackFloat(a, ctx);
    v[1] = AtelPopStackFloat(a, ctx);
    v[2] = AtelPopStackFloat(a, ctx);
    pppFpSetStickPos(AtelPopStackInteger(a, ctx), v);
    return 1;
}

int func_0018EB48(Actor *a, void *op, ScriptCtx *ctx) {
    if (AtelPopStackInteger(a, ctx) != 0) {
        func_0019D258();
    } else {
        func_0019D288();
    }
    return 1;
}

int func_0018EB88(Actor *a, void *op, ScriptCtx *ctx) {
    int i;

    func_0026A958();
    for (i = 0; i < func_0019BC08(); i++) {
        func_0019C2E8(i, 0);
    }
    return 1;
}

int func_0018EBE0(Actor *a, void *op, ScriptCtx *ctx) {
    Yn_GuideMapSetMapNo(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EC08(Actor *a, void *op, ScriptCtx *ctx) {
    func_00269978(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EC30(Actor *a, void *op, ScriptCtx *ctx) {
    func_0026A770(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EC58(Actor *a, void *op, ScriptCtx *ctx) {
    func_001750A8(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EC80(Actor *a, void *op, ScriptCtx *ctx) {
    func_00175140();
    return 1;
}

int func_0018ECA0(Actor *a, void *op, ScriptCtx *ctx) {
    float f0, f1, f2, f3;

    f3 = AtelPopStackFloat(a, ctx);
    f2 = AtelPopStackFloat(a, ctx);
    f1 = AtelPopStackFloat(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    func_001750E8(f0, f1, f2, f3);
    return 1;
}

int func_0018ED38(Actor *a, void *op, ScriptCtx *ctx) {
    float f0, f1, f2, f3, f4, f5;

    f5 = AtelPopStackFloat(a, ctx);
    f4 = AtelPopStackFloat(a, ctx);
    f3 = AtelPopStackFloat(a, ctx);
    f2 = AtelPopStackFloat(a, ctx);
    f1 = AtelPopStackFloat(a, ctx);
    f0 = AtelPopStackFloat(a, ctx);
    func_00175110(f0, f1, f2, f3, f4, f5);
    return 1;
}

int func_0018EE08(Actor *a, void *op, ScriptCtx *ctx) {
    return func_00173B30(AtelPopStackInteger(a, ctx));
}

int func_0018EE30(Actor *a, void *op, ScriptCtx *ctx) {
    func_0026A9A8(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EE58(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1, n2, n3;

    n3 = AtelPopStackInteger(a, ctx);
    n2 = AtelPopStackInteger(a, ctx);
    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    ((void (*)(int, int, int, int))func_0019D2D8)(n0, n1, n2, n3); /* DEBT(TYPE): called with four arguments, declared with three */
    return 1;
}

int func_0018EEF0(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019D348();
    return 1;
}

int func_0018EF10(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);

    func_00269D60(x, AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018EF70(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019BBA0(AtelPopStackInteger(a, ctx));
    return 1;
}
