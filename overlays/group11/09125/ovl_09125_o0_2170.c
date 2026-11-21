/* Shared P6 -O0 helper: P6Node detach (256B, -O0). */
#include "p6_overlay.h"

void func_01B02170(register P6AttachArg *arg)
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
