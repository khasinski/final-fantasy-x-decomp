/* tu_173 0x1a4dd8-0x1a4fc8: medium; rcfxNail (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

void *rcfxNailNew(void) {
    void *p = _rcAlloc(0x38, D_0056DE40, 0x12);

    func_001A4E40(p);
    return p;
}

void func_001A4E18(void *p) {
    func_001A4EA0(p);
    func_0018FC10(p);
}

void func_001A4E40(void *p) {
    R2Obj1A4E *o = p;

    o->id = 0x30004;
    o->p4 = func_001A4E18;
    o->p10 = (u8 *)func_001A4F20 + 0xA8; /* DEBT(CAST) */
    o->p14 = (u8 *)rcfxWindNew - 0x1B0; /* DEBT(CAST) */
    o->w18 = 2;
    o->w8 = 0;
    o->wC = 0;
    o->w1C = 0;
    o->w20 = 0;
    o->w24 = 0;
    o->w28 = 0;
    o->w2C = 0;
    o->w30 = 0;
    o->w34 = 0;
}

void func_001A4EA0(S2Four *p) {
    if (p->p20) {
        func_0018FC10(p->p20);
        p->p20 = 0;
    }
    if (p->p24) {
        func_0018FC10(p->p24);
        p->p24 = 0;
    }
    if (p->p28) {
        func_0018FC10(p->p28);
        p->p28 = 0;
    }
    if (p->p2C) {
        func_0018FC10(p->p2C);
        p->p2C = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxNail", func_001A4F20);
