/* Shared P6 -O0 helper: P6Node attach (236B, -O0). */
#include "p6_overlay.h"

void func_01B01F60(register P6AttachArg *arg)
{
    P6Node *node = arg->node;
    P6Node *parent = arg->parent;

    node->mark = 255;
    node->first = node->last = node;
    node->parent = parent;
    node->b1B = 0;
    if (parent != 0) {
        node->next = parent;
        node->prev = parent->last;
        if (parent->last == parent) {
            parent->first = node;
        } else {
            parent->last->next = node;
        }
        parent->last = node;
        parent->count++;
    }
}
