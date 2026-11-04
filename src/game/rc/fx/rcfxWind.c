/* tu_174 0x1a4fc8-0x1a5358: medium; rcfxWind (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxWind", func_001A4FC8);

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxWind", func_001A50B8);

void *rcfxWindNew(void) {
    void *p = _rcAlloc(0x60, D_0056DE50, 0x15);

    func_001A52B0(p);
    return p;
}

void func_001A52A8(void *p) {
    func_0018FC10(p);
}

void func_001A52B0(void *p) {
    R2Obj1A52 *o = p;

    o->w0 = 0x30006;
    o->p4 = (u8 *)rcfxWindNew + 0x40; /* DEBT(CAST) */
    o->w8 = 0;
    o->wC = 0;
    o->w10 = 0;
    o->p14 = (u8 *)rcfxWindCalc + 0x20; /* DEBT(CAST) */
    o->w18 = 0;
    o->f20 = 1.0f;
    o->f24 = 0.0f;
    o->w28 = 0;
    o->w2C = 0;
    o->w30 = 0;
    o->w34 = 0;
    o->f38 = 0.1f;
    o->w3C = 0;
    o->f40 = 1.0f;
    o->f48 = o->f24;
    o->f44 = o->f24;
    o->f50 = o->f24;
    o->f4C = o->f24;
}

void rcfxWindCalc(void * p, int a, int b, float f)
{
    __asm__ volatile(
        "addiu      $2, $4, 0x20\n"
        "lqc2       $vf31, 0x0($5)\n"
        "sqc2       $vf31, 0x0($2)\n"
        "addiu      $3, $4, 0x30\n"
        "lqc2       $vf31, 0x0($6)\n"
        "sqc2       $vf31, 0x0($3)\n"
        "swc1      $f12, 0x40($4)\n"
        :  : "r"(p), "r"(a), "r"(b) : "$2", "$3");
}
