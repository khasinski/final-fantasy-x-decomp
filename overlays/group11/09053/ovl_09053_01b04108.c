/* Shared 09053-family helper (TU rank 29, 221 containers): start ppp particle object. */
#include "common.h"

typedef struct {
    u8 pad[0x10];
    void **pdt;
} P8StartCfg;

typedef struct {
    u8 pad[0x2C];
    P8StartCfg *cfg;
    u8 list[0x10];
} P8StartMgr;

typedef struct {
    u8 pad[0x40];
    float px, py, pz, pw;
    int rx, ry, rz, rw;
    float sx, sy, sz, sw;
} P8StartObj;

extern P8StartMgr *D_006A3924;
extern void _pppStartPart(P8StartObj *, int, void *, int);
extern void func_01B04088(P8StartObj *, int, int, void *);
extern void func_01B047E8(void *, P8StartObj *);

P8StartObj *func_01B04108(P8StartMgr *mgr, P8StartObj *o, int idx, int delay, int trigger, void *on_frame, float scale)
{
    o->px = o->py = o->pz = 0.0f;
    o->pw = 1.0f;
    o->rx = o->ry = o->rz = o->rw = 0;
    o->sx = o->sy = o->sz = o->sw = scale;
    D_006A3924 = mgr;
    _pppStartPart(o, 0x1000, mgr->cfg->pdt[idx], 1);
    func_01B04088(o, delay, trigger, on_frame);
    func_01B047E8(mgr->list, o);
    return o;
}
