/* tu_127 0x17a1b8-0x17a9c0: low; unk_17A1B8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A1B8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A2A8);

int func_0017A368(int a) {
    int r = -1;
    int i;

    for (i = 0; i < 16; i++) {
        if ((a >> i) & 1) {
            r = i;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A398);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A508);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A600);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A800);

void func_0017A930(char *s)
{
    while (*s != 0) {
        *s = func_002F2110(*s);
        s++;
    }
}

void func_0017A978(char *s)
{
    while (*s != 0) {
        *s = func_002F2130(*s);
        s++;
    }
}
