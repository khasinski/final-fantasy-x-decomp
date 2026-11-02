/* tu_334 0x2d0af0-0x2d1d68: low; unk_2D0AF0 (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: misc globals (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D0AF0);

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D0CE0);

void func_002D0EC8(s32 arg0, s32 arg1, int unused2, s32 arg3)
{
    func_002B7208(arg1, arg0);
    func_002D0AF0(arg0, arg0, arg3);
}

void func_002D0F10(W10MultiplierCount *info, int unused, W10MultiplierTable *table)
{
    int remaining = info->count;
    Vec4 *value = table->values;

    if (remaining > 0) {
        do {
            value->w = 1.0f;
            remaining--;
            value->z = 1.0f;
            value->y = 1.0f;
            value->x = 1.0f;
            value++;
        } while (remaining != 0);
    }
}

void func_002D0F50(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D0F58);

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D10D8);

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D14D8);

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D17F0);

INCLUDE_ASM("build/ee_asm/game/op/op_2D0AF0", func_002D1AB8);
