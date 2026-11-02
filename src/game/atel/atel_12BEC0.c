/* tu_053 0x12bec0-0x12c2d0: low; unk_12BEC0 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_0012BEC0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0011FD00(AtelPopStackInteger(a, ctx) != 0);
}

int func_0012BEE8(Actor *a, void *op, ScriptCtx *ctx) {
    int v[3];

    func_0011FD38(&v[0], &v[1], &v[2]);
    v[0] = AtelPopStackInteger(a, ctx);
    Sg_SetTkAntiXYB(v[0], v[1], v[2]);
    return v[0];
}

int func_0012BF48(Actor *a, void *op, ScriptCtx *ctx) {
    int x, y, z;

    func_0011FD38(&x, &y, &z);
    y = AtelPopStackInteger(a, ctx);
    Sg_SetTkAntiXYB(x, y, z);
    return y;
}

int func_0012BFA8(Actor *a, void *op, ScriptCtx *ctx) {
    int x, y, z;

    func_0011FD38(&x, &y, &z);
    z = AtelPopStackInteger(a, ctx);
    Sg_SetTkAntiXYB(x, y, z);
    return z;
}

int func_0012C008(void) {
    int v;

    func_0011FD38(&v, 0, 0);
    return v;
}

int func_0012C030(void) {
    int v;

    func_0011FD38(0, &v, 0);
    return v;
}

int func_0012C058(void) {
    int v;

    func_0011FD38(0, 0, &v);
    return v;
}

int func_0012C080(void) {
    int v = func_0011FD00(0);

    func_0011FD00(v);
    return v;
}

int func_0012C0B8(Actor *a) {
    a->w44 = 0;
    return 1;
}

int func_0012C0C8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0013A008(v);
    return v;
}

int func_0012C100(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00139FE0(v);
    return v;
}

int func_0012C138(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);

    if (n <= 0) {
        n = 1;
    }
    AtelSkipReqLevel2(a->id, n - 1);
    return n;
}

int func_0012C188(Actor *a, void *op, ScriptCtx *ctx) {
    s32 *w = (s32 *)AtelGetCurCtrlWork(); /* DEBT(CAST): flag word of the event state */
    int on = AtelPopStackInteger(a, ctx) != 0;

    *w = (*w & ~0x80) | (on << 7);
    return on;
}

float func_0012C1F0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0013A378(a, AtelPopStackInteger(a, ctx))->f0C;
}

float func_0012C228(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0013A378(a, AtelPopStackInteger(a, ctx))->f10;
}

float func_0012C260(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0013A378(a, AtelPopStackInteger(a, ctx))->f14;
}

float func_0012C298(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0013A378(a, AtelPopStackInteger(a, ctx))->f08;
}
