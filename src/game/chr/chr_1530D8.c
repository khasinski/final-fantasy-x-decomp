/* tu_094 0x1530d8-0x1531c8: low; unk_1530D8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_001530D8(Actor *a, int *p, ScriptCtx *ctx)
{
    int v1 = AtelPopStackInteger(a, ctx);
    int v0 = AtelPopStackInteger(a, ctx);

    p[1] = v1;
    return p[0] = v0;
}

int func_00153138(void) {
    return 5;
}

int func_00153140(Actor *a, int *p, ScriptCtx *ctx)
{
    ChN_ReadSystemMGRP(p[0], p[1]);
    return 0;
}

int func_00153168(Actor *a, int *p, ScriptCtx *ctx)
{
    return *p = AtelPopStackInteger(a, ctx);
}

int func_00153198(void) {
    return 5;
}

int func_001531A0(Actor *a, int *p, ScriptCtx *ctx)
{
    func_00104FC0(p[0]);
    return 0;
}
