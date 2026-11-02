/* tu_329 0x2b4630-0x2b4ff8: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: sound/debug dual-output dispatch wrappers (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2B4630", op_oef2_set);

void op_oef2_set2(char *a) {
    op_oef2_set(a, a + *(s32 *)(a + 0x3C)); /* DEBT(CAST): header type unknown, offset word at +0x3C */
}

void op_oef2_set2_16(char *a) {
    a += 0x10;
    op_oef2_set(a, a + *(s32 *)(a + 0x3C)); /* DEBT(CAST): see op_oef2_set2 */
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B4630", op_oef2_a_get);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4630", func_002B4A58);

int op_oef2_obj_a_get(int a, int b, int c)
{
    int *t = op_oef2_a_get(a, 1, b);

    return (int)t + t[c] + c * 4;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B4630", op_oef2_a_set);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4630", func_002B4BA8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4630", func_002B4D78);
