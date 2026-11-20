/* Shared 09053-family helper (TU rank 243, 41 containers): poll pppcalc and switch callback. */
#include "p7_overlay.h"

typedef struct Ovl09053Node {
    u8 pad00[0x10];
    int cb;
} Ovl09053Node;

typedef struct Ovl09053Task {
    u8 pad00[0x08];
    Ovl09053Node *node;
    u8 pad0C[0x08];
    int timer;
} Ovl09053Task;

void D_01B009B8(void);
extern u8 D_01B05BA8[];
extern int D_01B05E54;
int func_01B041E8(void *a, int b);

void func_01B00CE8(Ovl09053Task *t)
{
    if (func_01B041E8(D_01B05BA8, D_01B05E54) == 1) {
        t->timer = 3;
        /* DEBT(CAST): int cb aliases timer to preserve original store order. */
        t->node->cb = (int)D_01B009B8;
    }
}
