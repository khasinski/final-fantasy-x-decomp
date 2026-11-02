/* tu_277 0x254028-0x254a38: medium; decode (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

int func_00254028(Actor *a, int b, ScriptCtx *ctx) {
    AtelPopStackInteger(a, ctx);
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/sqs/decode", spline_get_near_point);

INCLUDE_ASM("build/ee_asm/game/sqs/decode", spline_get_near_point_init);

INCLUDE_ASM("build/ee_asm/game/sqs/decode", func_002545E0);

INCLUDE_ASM("build/ee_asm/game/sqs/decode", func_00254730);

int func_00254910(u8 *p, void *dst, int *out)
{
    int len = p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);

    func_002EEF1C(dst, p + 5, len);
    *out = len;
    return len;
}

int sa_decode(int a, u8 *p)
{
    int out;

    D_00327070[*p](p, a, &out);
    return out;
}

int func_002549C8(u8 *p)
{
    if (p[0] != 1) {
        func_001577A8(D_00573818, D_00573820, 0x40);
    }
    return p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);
}
