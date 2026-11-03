#include "p6_overlay.h"

/* F2 TU rank 18: particle (ppp) effect element. Compiled with -O0.
 * The TU's third function (func_01B0AE50) uses VU0 macro instructions (lqc2/vitof0/vdiv/
 * vmulq/vftoi12/sqc2, inline asm in the original) and is not part of this unit. */

extern int D_006A3924;

void _pppStartPart(void *part, int a, int res, int b);
void _pppAllFreePObject(void *part);
void func_01B0B230(int a);
void func_01B0B258(P6PartArg *a);

void func_01B0ACD8(register P6PartArg *a)
{
    P6PartObj *obj = a->obj;
    P6Vec *pos;

    func_01B0B258(a);
    func_01B0B230(a->w08);
    obj->w50 = a->w08;
    obj->heap = a->w10;
    obj->flags = 0;
    obj->wait = 0;
    D_006A3924 = obj->heap;
    _pppStartPart(obj->part, 4096, a->res->parts[a->idx], 1);
    pos = &a->res->pos[a->idx];
    func_002DD0B0(&a->obj->pos, pos);
    obj->wF4 = 0;
    obj->wE0 = 0;
}

void func_01B0ADE0(register P6PartArg *a)
{
    int ret;

    if (!(a->obj->flags & 4)) {
        D_006A3924 = a->obj->heap;
        _pppAllFreePObject(a->obj->part);
    }
    ret = 0;
}
