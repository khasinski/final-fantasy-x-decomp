/* Shared P6 -O2 helper: P6Node append child (hash 2c52c1, 52B). */
#include "p6_overlay.h"

typedef struct {
    P6Node *parent;
    P6Node *node;
} P6AppendArg;

void func_01B03468(P6AppendArg *arg)
{
    P6Node *p = arg->parent;
    P6Node *n = arg->node;

    n->next = p;
    p->count++;
    n->prev = p->last;
    p->last->next = n;
    p->last = n;
    n->parent = p;
}
