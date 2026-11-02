/* tu_154 0x197cf8-0x198860: low; rcbgPSim (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"

void *func_00197CF8(void) {
    void *p = _rcAlloc(0xB0, D_0056DA88, 0x20);

    rcbgPSimInit(p);
    return p;
}

void func_00197D38(int a) {
    rcbgPSimCreate((void *)a); /* DEBT(TYPE): header declares an int parameter */
    func_0018FC10((void *)a);
}

void rcbgPSimInit(void *p) {
    R2Vt2 *o = p;

    func_002EF0D0(o, 0, 0xB0);
    o->id = 0x20004;
    o->p4 = func_00197D38;
    o->p8 = func_00198690;
    o->pC = func_00198730;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgPSim", rcbgPSimCreate);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgPSim", func_00197E10);

void rcbgPSimCreateFromOMD(void *o, int n, float f) {
    void *t = rcbgModelNew();

    rcbgModelCreateFromOMD(t, n);
    rcbgModelSetScale(t, f);
    func_00197E10(o, t);
}

void func_00198318(void *a) {
    Q3Link *n = a;

    if (n->link14 != 0) {
        n->link14->link14 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgPSim", rcbgPSimAddNail);

void rcbgPSimAddDamp(R2Obj18 *o, float f) {
    R2F1C *p = rcfxDampNew();

    p->f1C = f;
    rcfxParticleAddForce(o->f18, p);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgPSim", rcbgPSimAddGravity);

void rcbgPSimAddWind(R2Obj18 *o, int a, int b, float f) {
    void *p = rcfxWindNew();

    rcfxWindCalc(p, a, b, f);
    rcfxParticleAddForce(o->f18, p);
}

void func_00198690(R2ObjA8 *o) {
    V2Part *part;
    V2PartData *d;
    float f;

    if (o->w10 & 1) {
        rcfxParticleSetTime(o->p18, o->fAC);
        o->fAC += 0.5f;
    }
    part = o->p14;
    f = func_00195688(part);
    d = part->data;
    rcbgModelFToS0((u8 *)d + d->off8, o->p18->p18, d->count, f);
    if (o->p14->update != 0) {
        o->p14->update(o->p14);
    }
}

void func_00198730(R2ObjA8 *o) {
    if (o->p14->draw != 0) {
        o->p14->draw(o->p14);
    }
}

void func_00198760(void *p, int which, float *v) {
    R2ObjA8 *o = p;
    int done = 0;

    if (which == 0) {
        o->v50[0] = v[0];
        o->v50[1] = v[1];
        o->v50[2] = v[2];
        if (o->setA0 == 0) {
            if (o->wA8 != 0) {
                o->wA8--;
                done = o->wA8 == 0;
            }
            o->setA0 = 1;
        }
    } else {
        o->v90[0] = v[0];
        o->v90[1] = v[1];
        o->v90[2] = v[2];
        if (o->setA4 == 0) {
            if (o->wA8 != 0) {
                o->wA8--;
                done = o->wA8 == 0;
            }
            o->setA4 = 1;
        }
    }
    if (done) {
        func_00198828(o);
    }
}

void func_00198800(R2ObjA8 *o, int which, void *dst) {
    if (which == 0) {
        func_002DD0B0(dst, o->v50);
    } else {
        func_002DD0B0(dst, o->v90);
    }
}

void func_00198820(R2ObjA8 *o, int v) {
    o->wA8 = v;
}

void func_00198828(R2ObjA8 *o) {
    rcfxParticleResetForce(o->p18);
    o->w10 |= 1;
}
