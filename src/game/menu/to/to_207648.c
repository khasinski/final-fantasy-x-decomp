/* tu_228 0x207648-0x207f50: medium; ~TOValueToMesFontL (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", func_00207648);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", TOIntToMes);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", func_00207988);

int func_00207A80(int i)
{
    return D_00669AE0[i]->wC;
}

void func_00207AA0(int id)
{
    if (D_003238E4 & 0x20) {
        func_00204C60(id);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", TOFuncPadMessageSelect);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_207648", TOFuncPadMessageInputValue);

int func_00207EE0(int a)
{
    a = TOGetMessageStatus(a);
    if (a == 3) {
        if (D_003238E4 & 0x20) {
            return 1;
        }
    }
    return 0;
}

int func_00207F20(void)
{
    if (func_00205DB8(7) == 2) {
        return D_00668FEA;
    }
    return -1;
}
