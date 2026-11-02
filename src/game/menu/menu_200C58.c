/* tu_225 0x200c58-0x201760: low; unk_200C58 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/r4.h"

INCLUDE_ASM("build/ee_asm/game/menu/menu_200C58", func_00200C58);

INCLUDE_ASM("build/ee_asm/game/menu/menu_200C58", func_00200F98);

void *func_00201210(void *list, int a, int b, int c)
{
    return func_00201250(list, a, b, c, 0);
}

void *func_00201230(void *list, int a, int b, int c)
{
    return func_00201410(list, a, b, c, 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/menu_200C58", func_00201250);

INCLUDE_ASM("build/ee_asm/game/menu/menu_200C58", func_00201410);

INCLUDE_ASM("build/ee_asm/game/menu/menu_200C58", func_002014E0);
