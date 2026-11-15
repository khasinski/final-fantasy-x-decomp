#include "p6_overlay.h"

/* F2 TU rank 146: P6Link constructor. Compiled with -O0. */

typedef struct P6LinkArg1 {
    P6Link *link;
} P6LinkArg1;

extern P6NodeVt D_01B02748;

void func_01B0B628(P6LinkArg1 *a)
{
    P6Link *link = a->link;

    link->next = link->prev = link;
    a->link->vt = &D_01B02748;
}
