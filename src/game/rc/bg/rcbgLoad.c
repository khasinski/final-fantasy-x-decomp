/* tu_149 0x193c80-0x1944c0: medium; rcbgLoad (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#include "ffx/g2.h"

int func_00193C80(W3Voice *v) {
    if (v->subB0.img != 0) {
        return func_0019A408(v->subB0.img, 0);
    }
    return 0;
}

int func_00193CB0(int n) {
    int r = n % 16;

    if (r != 0) {
        return 16 - r;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgLoad", rcbgPreLoad);

void rcbgSceneLoad(W3Pool *p, W3Reader *r) {
    int i;

    func_0019DE78(r, &p->count, 4);
    func_0019D878(r, 0xC);
    if (p->count > 0) {
        p->voices = _rcAlloc(p->count * sizeof(W3Voice), D_0056D810, 0x42);
        for (i = 0; i < p->count; i++) {
            rcbgLayerLoad(&p->voices[i], r);
        }
    }
    func_0019DE78(r, p->blk70, 0x10);
    func_0019DE78(r, p->blk80, 0x10);
    func_0019DE78(r, p->blk90, 0x10);
    func_0019DE78(r, &p->iB0, 4);
    func_0019DE78(r, &p->i64, 4);
    rcbgSceneChkLayer((S2Table *)p); /* DEBT(TYPE): S2Table and W3Pool describe the same object */
    rcbgSceneSetMatrix(p);
}

void rcbgSceneChkLayer(S2Table *t) {
    int i;
    S2TableEnt *e = t->ent;

    for (i = 0; i < t->count; i++, e++) {
        if (e->w8 >= 0x1C0) {
            t->w100 = 1;
        }
        if (e->w0 & 0x10) {
            t->w104 = 1;
        }
    }
    rcbgSceneChkSortLayer(t);
    if (t->w100) {
        func_0018F5E8(D_0056D820);
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgLoad", rcbgSceneChkSortLayer);

void rcbgSceneModelLoad(void *owner, W3Reader *r) {
    void *o = rcbgModelNew();

    rcbgModelLoad(o, r);
    func_001991D8(owner, o);
}

void func_001941A0(void *owner, W3Reader *r) {
    W3Img *o = func_00199ED8();

    func_00194420(o, r);
    func_001991D8(owner, o);
}

void rcbgLayerLoad(W3Voice *v, W3Reader *r) {
    R2Anim *anim = (R2Anim *)&v->sub90; /* DEBT(TYPE): W3Voice.sub90 is really this 0x20-byte block */
    W3Blk *tex = &v->subB0;
    int n;

    func_00192990(v);
    func_0019DE78(r, v, 0x90);
    func_0019DE78(r, &n, 4);
    func_0019D878(r, 0xC);
    if (n > 0) {
        rcbgAnimeSetDataCnt(anim, n);
        func_0019DE78(r, anim->frames, anim->n * 4);
        if ((anim->n * 4) & 0xF) {
            func_0019D878(r, 0x10 - ((anim->n * 4) & 0xF));
        }
        anim->img = func_00199ED8();
        func_00194420(anim->img, r);
    }
    func_0019DE78(r, &tex->b0A, 1);
    func_0019DE78(r, &tex->b0B, 1);
    func_0019D878(r, 0xE);
    tex->img = func_00199ED8();
    func_00194420(tex->img, r);
    func_00194318(v);
}

void func_00194318(W3Voice *v) {
    float hw = v->i04 * 0.5f;
    float hh = v->i08 * 0.5f;

    v->f68 = hw;
    v->f64 = hw;
    v->f70 = hh;
    v->f6C = hh;
    v->f4C = hw;
    v->f50 = hh;
}

void rcbgModelLoad(S2Vt *o, W3Reader *r) {
    int n;

    func_0019DE78(r, &o->w10, 4);
    func_0019DE78(r, &n, 4);
    o->w14 = _rcAlloc(n, D_0056D810, 0x12B);
    func_0019DE78(r, o->w14, n);
    func_0019DE78(r, o->body20, 0x70);
    func_0019DE78(r, &o->v90, 0x20);
    func_0019DE78(r, &o->fB0, 0x10);
    func_0019DE78(r, o->matC0, 0x40);
    func_0019DE78(r, o->mat100, 0x40);
}

void func_00194420(W3Img *o, W3Reader *r) {
    func_0019DE78(r, &o->reg18, 8);
    func_0019DE78(r, &o->reg20, 8);
    func_0019DE78(r, &o->reg28, 8);
    func_0019DE78(r, &o->i30, 4);
    func_0019DE78(r, &o->stride, 4);
    o->buf = r->cur;
    func_0019D878(r, o->i30 * o->stride);
    func_0019A420(o);
}
