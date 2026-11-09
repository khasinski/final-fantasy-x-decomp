/* tu_171 0x1a43b0-0x1a4a38: medium; rcfxParticle (config/tu_map.tsv) */
#define func_001A43B0 _hdr_func_001A43B0
#include "common.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#include "ffx/g2.h"
#undef func_001A43B0

void func_001A43B0(void)
{
}

void *func_001A43B8(void) {
    void *p = _rcAlloc(0x34, D_0056DE20, 0x14);

    func_001A4420(p);
    return p;
}

void func_001A43F8(void *p) {
    func_001A4480(p);
    func_0018FC10(p);
}

void func_001A4420(R2Obj1A44 *o) {
    o->f4 = 0.03f;
    o->fC = 0.001f;
    o->f14 = 0.1f;
    o->w0 = 0;
    o->w8 = 0;
    o->w10 = 0;
    o->p18 = 0;
    o->p1C = 0;
    o->p20 = 0;
    o->p24 = 0;
    o->w28 = 0;
    o->p2C = 0;
    o->w30 = 0;
}

void func_001A4480(void *p) {
    R2Obj1A44 *o = p;

    if (o->p18) {
        func_0018FC10(o->p18);
        o->p18 = 0;
    }
    if (o->p1C) {
        func_0018FC10(o->p1C);
        o->p1C = 0;
    }
    if (o->p20) {
        func_0018FC10(o->p20);
        o->p20 = 0;
    }
    if (o->p24) {
        func_0018FC10(o->p24);
        o->p24 = 0;
    }
    func_001A46E8(o);
}

void func_001A4508(R2Obj1A44 *o, int n) {
    o->w10 = n;
    o->p18 = _rcRealloc(o->p18, n * 16, D_0056DE20, 0x46);
    o->p1C = _rcRealloc(o->p1C, n * 16, D_0056DE20, 0x47);
    o->p20 = _rcRealloc(o->p20, n * 16, D_0056DE20, 0x48);
    o->p24 = _rcRealloc(o->p24, n * 16, D_0056DE20, 0x49);
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxParticle", rcfxParticleAddForce);

typedef struct RcfxForce {
    int w0;
    void (*fn4)(struct RcfxForce *);
} RcfxForce;

void func_001A46E8(void *p) {
    R2Obj1A44 *o = p;
    int i;

    for (i = 0; i < o->w28; i++) {
        RcfxForce *f = (RcfxForce *)o->p2C[i];
        if (f->fn4 != 0) {
            f->fn4(f);
        }
    }
    if (o->p2C != 0) {
        func_0018FC10(o->p2C);
        o->p2C = 0;
    }
}

void rcfxParticleResetForce(R2Obj1A44 *o) {
    int i;
    for (i = 0; i < o->w28; i++) {
        if (o->p2C[i]->fn10 != 0) {
            o->p2C[i]->fn10(o->p2C[i], o);
        }
    }
    func_001A47F0(o);
}

void func_001A47F0(R2Obj1A44 *o) {
    int i;
    for (i = 0; i < o->w10; i++) {
        o->p20[i].x = o->p20[i].y = o->p20[i].z = o->p20[i].w = 0.0f;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/fx/rcfxParticle", rcfxParticleCalcForce);

typedef struct {
    float t;
    float dt;
    float end;
} RcfxTime;

extern void rcfxParticleCalcForce(struct R2Obj1A44 *o);

void rcfxParticleSetTime(struct R2Obj1A44 *o, float f)
{
    RcfxTime *tm = (RcfxTime *)o;
    int i = 0x20;
    float end = tm->t + 0.5f;

    tm->end = end;
    while (tm->t < end) {
        rcfxParticleCalcForce(o);
        i--;
        tm->t += tm->dt;
        if (i <= 0) {
            break;
        }
    }
}
