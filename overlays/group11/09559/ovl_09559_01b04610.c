#include "oef_overlay.h"

extern OefHeapMgr D_01B0D100;
extern OefHeapCfg D_01B1DBC0;

void func_01B04610(OefPartObj *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B0D100;
    _pppStartPart(o, 0x1000, D_01B1DBC0.pdt[id], 1);
    o->rotation[0] = (int)rx;
    o->rotation[1] = (int)ry;
    o->position[0] = x;
    o->rotation[2] = (int)rz;
    o->position[1] = y;
    o->position[2] = z;
    o->scale[0] = sx;
    o->scale[1] = sy;
    o->scale[2] = sz;
    o->position[3] = 1.0f;
    o->enabled = 1;
    o->flag5C = 1;
    o->scale[3] = 1.0f;
}

void func_01B04720(OefPartObj *o)
{
    if (o->enabled != 0) {
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B0D100;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}
