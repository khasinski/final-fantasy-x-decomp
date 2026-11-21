/* Shared P6 -O2 helper: P6Node iterate children (hash 1313a3, 140B). */
#include "p6_overlay.h"

void func_01B033D8(P6Iter *it)
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
