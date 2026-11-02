/* tu_175 0x1a5358-0x1a55a8: medium; rcfxGravity (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxGravity", func_001A5358);

void *rcfxGravityNew(void) {
    void *p = _rcAlloc(0x30, D_0056DE60, 0x12);

    func_001A5558(p);
    return p;
}

void func_001A5550(void *p) {
    func_0018FC10(p);
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxGravity", func_001A5558);
