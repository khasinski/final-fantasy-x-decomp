#include "p7_overlay.h"

/* PARKED (P7): F3 TU rank 76 (func_01B03C78, 112 B, 226 containers): initialises a circular
 * list of 256 28-byte nodes. Remaining diff: the loop "next" pointer is a1 in the target and a2
 * here (the constant 256 then takes a1 instead of v1), which also shuffles the final stores
 * (target order: 7B20, last->next, 7B18, 7B10, 7B14, 7B1C). Tried pointer and index loops,
 * count-up/count-down, statement orders. */

typedef struct P7Node {
    struct P7Node *prev;
    struct P7Node *next;
    int data[5];
} P7Node;

extern P7Node D_01B05F10[256];
extern int D_01B07B10;
extern int D_01B07B14;
extern P7Node *D_01B07B18;
extern int D_01B07B1C;
extern u16 D_01B07B20;

void func_01B03C78(void)
{
    P7Node *q;
    P7Node *p;
    int i;

    p = D_01B05F10;
    p->prev = p + 255;
    for (i = 0; i < 255; i++) {
        q = p + 1;
        q->prev = p;
        p->next = q;
        p = q;
    }
    D_01B07B20 = 256;
    q->next = D_01B05F10;
    D_01B07B18 = D_01B05F10;
    D_01B07B10 = 0;
    D_01B07B14 = 0;
    D_01B07B1C = 0;
}
