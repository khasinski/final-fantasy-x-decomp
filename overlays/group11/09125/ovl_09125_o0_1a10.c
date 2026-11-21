/* Shared P6 -O0 helper (711 instances): append child node to parent's circular list. */
#include "p6_overlay.h"

void func_01B01A10(P6AttachArg *arg)
{
    P6Node *parent = arg->node;
    P6Node *child = arg->parent;

    child->next = parent;
    child->prev = parent->last;
    parent->last->next = child;
    parent->last = child;
    child->parent = parent;
    parent->count++;
}
