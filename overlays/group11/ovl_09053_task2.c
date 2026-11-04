#include "p8_overlay.h"

/* F5 TU rank 23 after func_01B03E28 (parked, see ovl_09053_task.c). */

extern P8Task *D_01B07B10; /* active list head */
extern P8Task *D_01B07B14; /* active list tail */

P8Task *func_01B03DA8(P8TaskFn fn);
void func_01B03E28(P8Task *t);
void func_01B03FF0(P8Task *t);

void func_01B03F70(P8Task *t)
{
    if (D_01B07B10 != 0) {
        t->prev = D_01B07B14;
        t->next = 0;
        D_01B07B14->next = t;
    } else {
        t->next = 0;
        t->prev = 0;
        D_01B07B10 = t;
    }
    t->top = t;
    D_01B07B14 = t;
}

void func_01B03FB0(P8Task *t, P8TaskFn fn)
{
    P8Task *c = func_01B03DA8(fn);

    if (c != 0) {
        c->link = t->top;
        t->top = c;
    }
}

void func_01B03FF0(P8Task *t)
{
    P8Task *link = t->top->link;

    t->top->link = 0;
    func_01B03E28(t->top);
    t->top = link;
}
