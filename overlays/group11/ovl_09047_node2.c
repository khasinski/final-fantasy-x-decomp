#include "p6_overlay.h"

/* F2 TU rank 104: append a child to a P6Node. Compiled with -O0. */

typedef struct P6AddArg {
    P6Node *parent;
    P6Node *node;
} P6AddArg;

void func_01B07CB8(register P6AddArg *a)
{
    P6Node *parent = a->parent;
    P6Node *node = a->node;

    node->next = parent;
    node->prev = parent->last;
    parent->last->next = node;
    parent->last = node;
    node->parent = parent;
    parent->count++;
}
