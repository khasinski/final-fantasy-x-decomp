#include "p8_overlay.h"

void func_01B02EB8(P8Mtx *a, P8Mtx *b);
void func_01B038E8(void *a);
void func_01B03A88(void *a, P8Vec *pos);

int func_01B041E8(P8PppMgr *mgr, void *pkt)
{
    P8List *list = &mgr->list;
    P8PObj *o;
    P8Mtx m;
    P8Mtx ident;
    P8Vec v;
    int count;
    int r;
    u16 flags;

    list->cur = list->head;
    count = 0;
    D_006A3924 = mgr;
    if (pkt != 0) {
        D_006A3BCC = pkt;
    }
    func_01B02EB8(&D_006A3A70, &D_006A3970);
    func_002DD128(&ident);
    while ((o = func_01B04AD8(list)) != 0) {
        flags = o->flags;
        if (flags & 0x8000) {
            if (!(flags & 1)) {
                if (o->delay != 0) {
                    o->delay--;
                } else {
                    if (o->on_tick != 0) {
                        o->on_tick(o);
                    }
                    if (o->on_frame != 0 && o->trigger == o->frame) {
                        o->on_frame(o);
                    }
                    switch (o->mode) {
                    case 1:
                        func_002DD3C0(&m, &ident, &o->rot);
                        break;
                    case 2:
                        m.r[0].q = o->mtx[0].q;
                        m.r[1].q = o->mtx[1].q;
                        m.r[2].q = o->mtx[2].q;
                        m.r[3].q = ident.r[3].q;
                        break;
                    default:
                        func_002DD1C8(&m, &ident, o->rot.v.z);
                        func_002DD270(&m, &m, o->rot.v.x);
                        func_002DD318(&m, &m, o->rot.v.y);
                        break;
                    }
                    func_002DCE08(&v, &m, &o->offset);
                    func_002DD998(&m.r[0], &m.r[0], o->scale.v.x);
                    func_002DD998(&m.r[1], &m.r[1], o->scale.v.y);
                    func_002DD998(&m.r[2], &m.r[2], o->scale.v.z);
                    m.r[3].v.x = o->trans.v.x + v.v.x;
                    m.r[3].v.y = o->trans.v.y + v.v.y;
                    m.r[3].v.z = o->trans.v.z + v.v.z;
                    func_002DD948(&o->position, &m.r[3]);
                    func_002DD0C0(&D_006A3930, &m);
                    if (o->w108 != 0) {
                        D_006A3BC8 = o->w108;
                    }
                    D_006A3BB0.q = o->color.q;
                    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
                    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
                    if (o->flags & 0x4000) {
                        o->flags &= 0xBFFF;
                        r = 1;
                    } else {
                        D_006A3924 = mgr;
                        r = _pppRunPart(o, 0x30);
                    }
                    if (r == 1) {
                        D_006A3924 = mgr;
                        _pppAllFreePObject(o);
                        o->flags &= 0x7FFF;
                        func_01B04948(list, o);
                    } else if (o->w10C != 0) {
                        func_00268610(o, o->w10C, o);
                    }
                    if (o->w110 != 0) {
                        func_01B03A88(o->w110, &m.r[3]);
                        func_01B038E8(o->w110);
                    }
                    o->frame++;
                }
            }
            count++;
        }
        if (o == func_01B04AD8(list)) {
            func_01B04A78(list);
        }
    }
    return count == 0;
}
