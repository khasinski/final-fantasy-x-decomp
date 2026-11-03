#include "p8_overlay.h"

void func_01B04088(P8PObj *o, int delay, int trigger, P8PObjFn on_frame);

P8PObj *func_01B04108(P8PppMgr *mgr, P8PObj *o, int idx, int delay, int trigger, P8PObjFn on_frame, float scale)
{
    int pdt = mgr->cfg->pdt[idx];

    o->rotation[0] = o->rotation[1] = o->rotation[2] = o->rotation[3] = 0;
    o->position.v.x = o->position.v.y = o->position.v.z = 0.0f;
    o->position.v.w = 1.0f;
    o->scale.v.x = o->scale.v.y = o->scale.v.z = o->scale.v.w = scale;
    D_006A3924 = mgr;
    _pppStartPart(o, 0x1000, pdt, 1);
    func_01B04088(o, delay, trigger, on_frame);
    func_01B047E8(&mgr->list, o);
    return o;
}
