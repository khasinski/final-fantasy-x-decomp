#include "p6_overlay.h"

/* F2 TU rank 40: child-list maintenance of P6Node. Compiled with -O0. */

void func_01B03778(register P6AttachArg *arg)
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

void func_01B03868(register P6Iter *it)
{
    P6Node *root = it->cur;
    P6Node *n;

    if (root->mark == it->mark) {
        it->done = 0;
        return;
    }
    n = root->last;
    while (n != root) {
        it->cur = n;
        n = n->prev;
        it->cur->vt->fn[7](it);
    }
    it->cur = root;
    root->mark = it->mark;
    it->done = 1;
}

void func_01B03940(register P6AttachArg *arg)
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
