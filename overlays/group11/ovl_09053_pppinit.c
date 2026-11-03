#include "p8_overlay.h"

void func_01B04030(P8PppMgr *mgr, void *data, void *buf, int size)
{
    _pppInitData(mgr->cfg, data);
    pppInitEnv(mgr, mgr->cfg, buf, size);
    func_01B04750(&mgr->list);
}
