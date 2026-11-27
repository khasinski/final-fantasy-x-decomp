#include "p6_overlay.h"

typedef struct {
    P6Node *parent;
    P6Node *child;
} ArgFF20;

void func_01B0FF20(ArgFF20 *arg)
{
    P6Node *p = arg->parent;
    P6Node *c = arg->child;

    c->next = p;
    c->prev = p->last;
    p->last->next = c;
    p->last = c;
    c->parent = p;
    p->count++;
}
