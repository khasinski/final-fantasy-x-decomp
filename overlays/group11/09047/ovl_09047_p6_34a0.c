/* Shared P6 -O2 helper: P6Node detach (hash 3878e5, 100B). */
#include "p6_overlay.h"

void func_01B034A0(P6AttachArg *arg)
{
    P6Node *node = arg->node;
    P6Node *parent = node->parent;

    if (parent == 0) {
        return;
    }
    parent->count--;
    if (node->next == parent) {
        parent->last = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    if (node->prev == parent) {
        parent->first = node->next;
    } else {
        node->prev->next = node->next;
    }
    node->next = node->prev = node;
    node->parent = 0;
}
