#include "p6_overlay.h"

/* F2 TU rank 117: unlink a P6Link from its ring. Compiled with -O0. */

typedef struct P6LinkArg1 {
    P6Link *link;
} P6LinkArg1;

void func_01B0B6A8(P6LinkArg1 *a)
{
    P6Link *link = a->link;
    P6Link *next = link->next;

    link->next->prev = link->prev;
    link->prev->next = link->next;
    link->next = link->prev = link;
}
