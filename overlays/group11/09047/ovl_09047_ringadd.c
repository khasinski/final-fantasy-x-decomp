#include "p6_overlay.h"

/* F2 TU rank 118: insert a P6Link at the end of a task ring. Compiled with -O0. */

void func_01B0BB38(P6TaskArg *a)
{
    P6Link *ring = &a->task->ring;
    P6Link *link = a->link;

    link->prev = ring->prev;
    link->next = ring;
    ring->prev->next = link;
    ring->prev = link;
}
