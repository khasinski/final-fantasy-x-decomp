#include "p3_overlay.h"

void func_01B07490(P3FadePool *pool)
{
    P3FadeEnt *e = pool->ent;
    int i;

    for (i = 0; i < pool->n; i++, e++) {
        if (e->slot >= 0) {
            e->age++;
            if (e->age < 0x20) {
                e->alpha = (0x20 - e->age) << 7;
            } else {
                pool->map[e->slot] = -2;
                e->slot = -1;
            }
        }
    }
}
