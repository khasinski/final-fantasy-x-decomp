/* tu_052 0x12bc40-0x12bec0: low; unk_12BC40 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_0012BC40(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    int k = n > 0 ? n : 1;

    return func_002EAC30((u16)brnd(2), k) >> 16;
}

int func_0012BC90(void) {
    return brnd(2) & 0xFFFF;
}

int func_0012BCB0(Actor *a, void *op, ScriptCtx *ctx) {
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));

    t->flags34.b.b1 = 0;
    return 0;
}

int func_0012BCF0(Actor *a, void *op, ScriptCtx *ctx) {
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));

    t->flags34.b.b1 = 1;
    return 1;
}

int func_0012BD28(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00143170(v);
    return v;
}

int func_0012BD60(void) {
    return func_001431C0();
}

int func_0012BD80(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00143200(v);
    return v;
}

int func_0012BDB8(void) {
    return func_00143248();
}

int func_0012BDD8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00148758(v);
    return v;
}

int func_0012BE10(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelSetSaveDicIndex(v);
    return v;
}

int func_0012BE48(void) {
    return func_001487D0();
}

int func_0012BE68(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelSetBattleSceneGroup(v);
    return v;
}

int func_0012BEA0(void) {
    return func_00148870();
}
