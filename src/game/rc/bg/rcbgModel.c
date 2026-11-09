/* tu_151 0x194f80-0x195378: high; rcbgModel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

void *rcbgModelNew(void) {
    void *p = _rcAlloc(0x140, D_0056D938, 0x1C);

    rcbgModelInit(p);
    return p;
}

void rcbgModelDelete(void *p) {
    func_00195078(p);
    func_0018FC10(p);
}

void rcbgModelInit(void *p) {
    S2Vt *o = p;

    o->w0 = 0x20001;
    o->p4 = rcbgModelDelete;
    o->p8 = (char *)func_001956B0 + 0xA0; /* DEBT(CAST): points into the middle of func_001956B0 */
    o->pC = rcbgModelDraw;
    o->w10 = 0;
    o->w14 = 0;
    func_002EF0D0(o->body20, 0, 0x70);
    func_0018F310(&o->v90);
    o->fB0 = o->fB4 = o->fB8 = o->fBC = 0.0f;
    func_002DD128(o->matC0);
    func_002DD128(o->mat100);
}

void func_00195078(void *p) {
    Obj195078 *o = p;

    if (o->buf != 0) {
        func_0018FC10(o->buf);
        o->buf = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgModel", func_001950B0);
