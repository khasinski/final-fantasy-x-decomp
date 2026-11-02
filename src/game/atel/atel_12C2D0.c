/* tu_054 0x12c2d0-0x12c788: low; unk_12C2D0 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_0012C2D0(Actor *a) {
    return (func_0013C9C8(a, a->slotIdx)->info->flags & 0x1F) != 0;
}

int func_0012C300(Actor *a) {
    return (a->slot[a->slotIdx].flags & 0x7F) != 0;
}

int func_0012C320(Actor *a, void *op, ScriptCtx *ctx)
{
    int d = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);

    a->arrAE0[0] = AtelPopStackInteger(a, ctx);
    a->arrAE0[1] = b;
    a->arrAE0[2] = c;
    a->arrAE0[3] = d;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12C2D0", func_0012C3B0);

int func_0012C450(Actor *a, void *op, ScriptCtx *ctx) {
    return a->arrAE0[AtelPopStackInteger(a, ctx)];
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12C2D0", func_0012C488);

INCLUDE_ASM("build/ee_asm/game/atel/atel_12C2D0", func_0012C610);

float func_0012C748(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0013A378(a, AtelPopStackInteger(a, ctx))->h06;
}
