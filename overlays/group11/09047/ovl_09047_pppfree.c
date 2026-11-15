#include "p6_overlay.h"

/* F2 TU rank 136: P6PartObj destructor. Compiled with -O0. */

extern int D_006A3924;

void _pppAllFreePObject(void *part);
void func_01B0AAB8(P6PartArg *a);

void func_01B0AA50(P6PartArg *a)
{
    D_006A3924 = a->obj->heap;
    _pppAllFreePObject(a->obj->part);
    func_01B0AAB8(a);
}
