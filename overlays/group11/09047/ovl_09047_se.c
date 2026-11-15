#include "p6_overlay.h"

/* F2 TU rank 51: positional sound emitter node (fn[7] message handler). Compiled with -O0. */

int op_oef2_se_on(int se, int vol, int b);
int op_oef2_se_3d_on(int se, P6Vec *pos, int b);
int op_oef2_se_3d_move(int se, P6Vec *pos, int b);
void func_01B0A640(P6Iter *it);

void func_01B0A370(register P6Iter *it)
{
    P6SeObj *obj = (P6SeObj *)it->cur;
    P6Vec pos;
    P6Iter m0;
    P6Iter m1;

    func_01B0A640(it);
    if (!(it->done & 1)) {
        return;
    }
    m0.cur = &obj->pos->node;
    m0.mark = it->mark;
    m0.cur->vt->fn[7](&m0);
    m1.cur = &obj->frame->node;
    m1.mark = it->mark;
    m1.cur->vt->fn[7](&m1);
    func_002DCE08(&pos, obj->frame->mA0, &obj->pos->v);
    if (obj->flags & 1) {
        if (--obj->delay == -1) {
            if (obj->flags & 2) {
                op_oef2_se_on(obj->se, obj->vol, obj->w28);
            } else {
                op_oef2_se_3d_on(obj->se, &pos, obj->w28);
            }
            obj->flags &= ~1;
        }
    } else if (!(obj->flags & 2)) {
        op_oef2_se_3d_move(obj->se, &pos, obj->w28);
    }
}
