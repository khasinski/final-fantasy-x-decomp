/* tu_024 0x117d38-0x117d78: medium; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"

void func_00117D38(Chr *chr)
{
    if (CHR_S32(chr, 0x708) != 0) { /* DEBT(CAST) */
        tex_anim_no_set(chr->w70C);
    }
}

void func_00117D58(Chr *chr)
{
    if (CHR_S32(chr, 0x708) != 0) { /* DEBT(CAST) */
        tex_anim_timer(chr->w70C);
    }
}
