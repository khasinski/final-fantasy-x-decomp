/* tu_003 0x104528-0x104718: low; ~ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

INCLUDE_ASM("build/ee_asm/game/chr/ch_104528", func_00104528);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104528", ch_create_chrname);

char *ch_create_name(int v)
{
    int k = (v >> 12) & 0xF;
    char *buf;

    if (v == 0) {
        return D_005693E0;
    }
    buf = D_0057DAA8;
    func_002F0008(buf, D_005693E8, func_00101528(k), v & 0xFFF);
    return buf;
}

char *ch_create_section(s32 v)
{
    return sg_getdbname((v >> 12) & 0xF);
}

void func_00104710(void) {
}
