#include "p6_overlay.h"

/* F2 TU rank 54: P6PartObj control messages. Compiled with -O0. */

typedef struct P6PartColArg {
    P6PartObj *obj;
    P6Vec *v;               /* 0x04 */
    u16 time;               /* 0x08 */
} P6PartColArg;

void func_01B0AB00(register P6PartArg *a)
{
    P6PartObj *obj = a->obj;

    obj->wait = a->val;
}

void func_01B0AB38(register P6PartArg *a)
{
    P6PartObj *obj = a->obj;

    if (a->val) {
        obj->flags &= ~2;
    } else {
        obj->flags |= 2;
    }
}

void func_01B0ABA8(register P6PartColArg *a)
{
    P6PartObj *obj = a->obj;
    float k = 1.0f / 4096.0f;

    obj->col[0] = obj->col12[0] * k;
    obj->col[1] = obj->col12[1] * k;
    obj->col[2] = obj->col12[2] * k;
    obj->col[3] = obj->col12[3] * k;
    func_002DD0B0(&obj->v40, a->v);
    obj->hE4 = obj->hE6 = a->time;
    obj->flags |= 1;
}
