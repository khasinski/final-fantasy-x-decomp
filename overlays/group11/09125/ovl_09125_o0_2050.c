/* Shared P6 -O0 helper: P6Node iterate children (212B, -O0). */
#include "p6_overlay.h"

void func_01B02050(register P6Iter *it)
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
