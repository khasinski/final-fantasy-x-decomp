/* tu_092 0x152308-0x152420: low; unk_152308 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_00152308(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));

    if (c == 0) {
        return 0;
    }
    return c->b742 != 0;
}

int func_00152348(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));

    if (c == 0) {
        return 0;
    }
    Ch_ResetMotion(c);
    return 0;
}

int func_00152388(Actor *a, void *op, ScriptCtx *ctx)
{
    int r1;
    int r2;
    Actor *r3;
    Chr *r4;

    r1 = AtelPopStackInteger(a, ctx);
    r2 = AtelPopStackInteger(a, ctx);
    r3 = AtelGetBasicWork(r2);
    r4 = AtelGetCharHandle(r3);
    if (r4 == 0) {
        return 0;
    }
    Ch_SetMotionSpeed_I(r4, r1);
    return 0;
}

float func_001523F8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001109F0(AtelPopStackFloat(a, ctx));
    return 0;
}
