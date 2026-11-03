#include "p8_overlay.h"

int func_01B04578(P8PppMgr *mgr, P8PObj *o)
{
    if (func_01B04948(&mgr->list, o) == 0) {
        return 0;
    }
    D_006A3924 = mgr;
    _pppAllFreePObject(o);
    o->flags &= 0x7FFF;
    return 1;
}

int func_01B045D8(P8PppMgr *mgr)
{
    P8List *list = &mgr->list;
    P8PObj *o;
    int n = 0;

    list->cur = list->head;
    while ((o = func_01B04AD8(list)) != 0) {
        D_006A3924 = mgr;
        _pppAllFreePObject(o);
        n++;
        o->flags &= 0x7FFF;
        func_01B04948(list, o);
        if (o == func_01B04AD8(list)) {
            func_01B04A78(list);
        }
    }
    return n;
}

u8 *func_01B04688(P8PppMgr *mgr, int idx)
{
    return mgr->rec20 + idx * 32;
}

void **func_01B04698(P8PppMgr *mgr, int idx)
{
    return &mgr->tbl[idx];
}
