#include "p6_overlay.h"

/* F2 TU rank 31: P6Obj150 transform update (fn[7] message handler). Compiled with -O0. */

extern void (*D_01B026F0[])(P6Vec *m, P6IVec *ang);   /* euler-to-matrix, by P6Obj150.order */

void func_01B09B18(P6Iter *it);
void func_01B09D00(P6Vec *dst, P6Vec *a, P6Vec *b);

void func_01B09630(register P6Iter *it)
{
    P6Obj150 *obj = (P6Obj150 *)it->cur;
    P6Obj150 *parent = obj->u120.p.parent;
    P6Vec scale;
    P6Iter m0;
    P6Iter m1;
    P6Iter m2;
    P6Iter m3;

    func_01B09B18(it);
    if (!(it->done & 1)) {
        return;
    }
    m0.cur = &obj->n0->node;
    m0.mark = it->mark;
    m0.cur->vt->fn[7](&m0);
    m1.cur = &obj->n1->node;
    m1.mark = it->mark;
    m1.cur->vt->fn[7](&m1);
    m2.cur = &obj->n2->node;
    m2.mark = it->mark;
    m2.cur->vt->fn[7](&m2);
    if (obj->u120.p.parent != 0) {
        m3.cur = &obj->u120.p.parent->node;
        m3.mark = it->mark;
        m3.cur->vt->fn[7](&m3);
    }
    D_01B026F0[obj->order](obj->m60, &obj->n1->v);
    func_002DD068(&scale, &obj->n2->v, obj->n2->v.w);
    func_002DD068(&obj->m20[0], &obj->m60[0], scale.x);
    func_002DD068(&obj->m20[1], &obj->m60[1], scale.y);
    func_002DD068(&obj->m20[2], &obj->m60[2], scale.z);
    func_002DD0B0(&obj->m20[3], &obj->n0->v);
    if (parent == 0) {
        /* DEBT(CAST): 128-bit copy (lq/sq); a struct assignment gives ld/sd pairs */
        *(u_long128 *)&obj->u120.rot = *(u_long128 *)&obj->n1->v;
        func_002DD0B0(&obj->scale, &obj->n2->v);
        func_002DD0C0(obj->mE0, obj->m60);
        func_002DD0C0(obj->mA0, obj->m20);
        return;
    }
    obj->u120.rot.x = parent->u120.rot.x + obj->n1->v.x;
    obj->u120.rot.y = parent->u120.rot.y + obj->n1->v.y;
    obj->u120.rot.z = parent->u120.rot.z + obj->n1->v.z;
    func_002DD050(&obj->scale, &parent->scale, &obj->n2->v);
    func_002DCE38(obj->mE0, parent->mE0, obj->m60);
    func_002DCE38(obj->mA0, parent->mA0, obj->m20);
    func_002DCE08(&obj->mA0[3], parent->mE0, &obj->m20[3]);
    func_01B09D00(&obj->mA0[3], &obj->mA0[3], &parent->mA0[3]);
}
