#include "p8_overlay.h"

extern P8Task *D_01B07B10; /* active list head */
extern P8Task *D_01B07B14; /* active list tail */
extern P8Task *D_01B07B18; /* free ring */
extern P8Task *D_01B07B1C; /* iteration cursor */
extern u16 D_01B07B20;     /* free count */

void func_01B03E28(P8Task *t);
void func_01B03FF0(P8Task *t);

P8Task *func_01B03DA8(P8TaskFn fn)
{
    P8Task *t;

    if (D_01B07B20 == 0) {
        return 0;
    }
    t = D_01B07B18;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    if (D_01B07B20 > 1) {
        D_01B07B18 = t->next;
    } else {
        D_01B07B18 = 0;
    }
    t->group = 0;
    t->w14 = 0;
    D_01B07B20--;
    t->fn = fn;
    t->link = 0;
    t->next = 0;
    t->prev = 0;
    t->top = t;
    return t;
}

void func_01B03E28(P8Task *t)
{
    while (t->top->link != 0) {
        func_01B03FF0(t);
    }
    if (t->prev != 0) {
        t->prev->next = t->next;
    }
    if (t->next != 0) {
        t->next->prev = t->prev;
    }
    if (D_01B07B10 == t) {
        D_01B07B10 = t->next;
    }
    if (D_01B07B14 == t) {
        D_01B07B14 = t->prev;
    }
    if (D_01B07B1C == t) {
        D_01B07B1C = t->next;
    }
    if (D_01B07B18 != 0) {
        t->next = D_01B07B18;
        t->prev = D_01B07B18->prev;
        D_01B07B18->prev = t;
    } else {
        t->next = t;
        t->prev = t;
    }
    D_01B07B18 = t;
    if (++D_01B07B20 == 256) {
        D_01B07B10 = 0;
    }
}

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
