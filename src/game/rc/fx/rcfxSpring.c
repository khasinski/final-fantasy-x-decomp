/* tu_172 0x1a4a38-0x1a4dd8: medium; rcfxSpring (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

void *func_001A4A38(void) {
    void *p = _rcAlloc(0x30, D_0056DE30, 0x13);

    func_001A4AA0(p);
    return p;
}

void func_001A4A78(void *p) {
    func_001A4B10(p);
    func_0018FC10(p);
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxSpring", func_001A4AA0);

void func_001A4B10(R2Ptr20 *o) {
    if (o->p20 != 0) {
        func_0018FC10(o->p20);
        o->p20 = 0;
    }
    if (o->p24 != 0) {
        func_0018FC10(o->p24);
        o->p24 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxSpring", func_001A4B60);

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxSpring", func_001A4BD0);

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxSpring", func_001A4BD8);
