/* tu_176 0x1a55a8-0x1a56f8: medium; rcfxDamp (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxDamp", func_001A55A8);

void *rcfxDampNew(void) {
    void *p = _rcAlloc(0x20, D_0056DE70, 0x12);

    func_001A5650(p);
    return p;
}

void func_001A5648(void *p) {
    func_0018FC10(p);
}

void func_001A5650(void *p) {
    S2Obj1A5 *o = p;

    o->w0 = 0x30003;
    o->p4 = func_001A5648;
    o->w8 = 0;
    o->wC = 0;
    o->w10 = 0;
    o->p14 = func_001A5698;
    o->w18 = 0;
    o->f1C = 0.0001f;
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxDamp", func_001A5698);
