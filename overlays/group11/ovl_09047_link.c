#include "p6_overlay.h"

/* F2 TU rank 57: task ring maintenance. Compiled with -O0. */

typedef struct P6LinkMsg {
    P6Link *cur;
    int w04;
} P6LinkMsg;

extern int D_01B00040;

void func_01B0BCB0(P6TaskArg *a)
{
    P6Link *ring = &a->task->ring;
    P6Link *link = a->link;

    link->prev = ring->prev;
    link->next = ring;
    ring->prev->next = link;
    ring->prev = link;
    a->task->flags &= ~1;
}

void func_01B0BD50(P6TaskArg *a)
{
    P6Task *task = a->task;
    P6Link *ring = &task->ring;
    P6Link *n = ring->prev;
    P6LinkMsg m;

    if (D_01B00040 == 0) {
        while (n != ring) {
            m.cur = n;
            n = n->prev;
            m.cur->vt->fn[8](&m);
        }
    }
    if (ring->prev == ring) {
        task->flags |= 1;
    }
}
