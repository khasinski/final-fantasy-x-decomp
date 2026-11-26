#include "oef_overlay.h"

extern int D_01B00578;
extern int D_01B0057C;
extern int D_01B00580;
extern int D_01B057E0;
extern OefHeapMgr D_01B06270;
extern OefHeapCfg D_01B06360;

extern void func_002DD0C0(void *, void *);

int func_01B03300(void)
{
    if (D_01B00578 == 0) {
        if (func_0029B830(D_01B057E0) != 0) {
            return 0;
        }
        D_01B00578++;
    }
    if (D_01B0057C == 0) {
        D_01B0057C = 1;
        MsEffectReady(D_01B057E0, 0);
    }
    if (D_01B00580 == 0) {
        if (MsEffectMotionLevel(D_01B057E0) <= 0) {
            return 0;
        }
        D_01B00580++;
    }
    return 0;
}

void func_01B033A8(OefPartObj *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B06270;
    _pppStartPart(o, 0x1000, D_01B06360.pdt[id], 1);
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

void func_01B034B8(OefPartObj *o)
{
    if (o->enabled != 0) {
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B06270;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

void func_01B03550(OefPartObj *o)
{
    pppSetMatrix(o);
    func_002DD0C0(D_006A39B0, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B06270;
    if (_pppRunPart(o, 0x30) != 0) {
        o->enabled = 0;
    }
}
