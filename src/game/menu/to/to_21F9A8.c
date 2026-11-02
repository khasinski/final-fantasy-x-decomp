/* tu_245 0x21f9a8-0x21fdd8: low; ~TOBtlInitActiveChrCursor (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21F9A8", TOBtlInitActiveChrCursor);

void func_0021FB00(void)
{
    D_006929C0.ang += 0.10471976f;
    if (D_006929C0.ang > 3.1415927f) {
        D_006929C0.ang -= 6.2831855f;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_21F9A8", TOBtlDrawActiveChrCursor);
