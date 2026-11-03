#include "p6_overlay.h"

/* F2 TU rank 75: P6SeObj start / constructor. Compiled with -O0. */

typedef struct P6SeStart {
    P6SeObj *obj;
    int delay;
} P6SeStart;

typedef struct P6SeInit {
    P6SeObj *obj;
    int w04;
    P6Obj150 *frame;        /* 0x08 */
    P6Node30 *pos;          /* 0x0C */
    int res;                /* 0x10 */
    int idx;                /* 0x14 */
} P6SeInit;

int op_oef2_a_get(int res, int kind, int idx);
void func_01B0A550(P6SeInit *a);

void func_01B0A260(register P6SeStart *a)
{
    a->obj->delay = a->delay;
    a->obj->flags |= 1;
}

void func_01B0A2A8(register P6SeInit *a)
{
    P6SeObj *obj = a->obj;

    func_01B0A550(a);
    obj->se = op_oef2_a_get(a->res, 6, a->idx);
    obj->frame = a->frame;
    obj->pos = a->pos;
    obj->vol = 64;
    obj->w28 = 256;
    obj->flags = 0;
}
