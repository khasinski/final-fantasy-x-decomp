#include "p8_overlay.h"

/* PARKED (P8): F5 TU rank 55, func_01B04108 (220 B, 221 containers). Only the scheduling
 * of the field stores differs (9 words with this version). Original order after the
 * prologue: rotation int stores 0x5C..0x50, then the pdt[idx] load, then position.x,
 * position.w, scale.x, the D_006A3924 store, then the remaining position/scale stores.
 * Tried all 720 orders of the six statement groups with int and void* pdt element
 * types, chained and unchained stores, float-typed rotation words, an int-typed
 * D_006A3924 store. */

void func_01B04088(P8PObj *o, int delay, int trigger, P8PObjFn on_frame);

P8PObj *func_01B04108(P8PppMgr *mgr, P8PObj *o, int idx, int delay, int trigger, P8PObjFn on_frame, float scale)
{
    void *pdt;

    o->rotation[0] = o->rotation[1] = o->rotation[2] = o->rotation[3] = 0;
    pdt = mgr->cfg->pdt[idx];
    o->scale.v.x = o->scale.v.y = o->scale.v.z = o->scale.v.w = scale;
    o->position.v.w = 1.0f;
    o->position.v.x = o->position.v.y = o->position.v.z = 0.0f;
    D_006A3924 = mgr;
    _pppStartPart(o, 0x1000, pdt, 1);
    func_01B04088(o, delay, trigger, on_frame);
    func_01B047E8(&mgr->list, o);
    return o;
}
