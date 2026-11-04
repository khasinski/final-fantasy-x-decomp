#include "p8_overlay.h"

/* PARKED (P8): func_01B03E28 of F5 TU rank 23 (file09053 0x01B03E28..0x01B03F70).
 * Everything matches except global-alloc swapping s3/s4 for the %hi registers of
 * D_01B07B18 (free ring, s4 in the original) and D_01B07B20 (free count, s3): 9 words.
 * Tried: local copy of the ring pointer, count++/+=1/comma forms, statement orders of the
 * ring insert and count update, loop forms (while/for/do), a struct for the five globals
 * (gives one shared base register). */

extern P8Task *D_01B07B10; /* active list head */
extern P8Task *D_01B07B14; /* active list tail */
extern P8Task *D_01B07B18; /* free ring */
extern P8Task *D_01B07B1C; /* iteration cursor */
extern u16 D_01B07B20;     /* free count */

void func_01B03FF0(P8Task *t);

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

