/* Shared 09053-family helper (TU rank 40, 226 containers): init 256-node free ring. */
#include "p7_overlay.h"

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
    /* DEBT(FAKE): register pin aligns 256 constant to $v1 so D_01B05F10 reloads into $a0. */
    register int n __asm__("$3");

    p = D_01B05F10;
    p->prev = p + 255;
    for (i = 0; i < 255; i++) {
        q = p + 1;
        q->prev = p;
        p->next = q;
        p = q;
    }
    n = 256;
    D_01B07B20 = n;
    /* DEBT(CAST): int store preserves store order before D_01B07B18. */
    *(int *)&q->next = (int)D_01B05F10;
    D_01B07B18 = D_01B05F10;
    D_01B07B10 = 0;
    D_01B07B14 = 0;
    D_01B07B1C = 0;
}

u16 func_01B03CE8(void)
{
    return D_01B07B20;
}
