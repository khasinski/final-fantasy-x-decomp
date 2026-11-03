#include "p1_overlay.h"

void func_01B08330(P1Ring *ring, P1Sub *src)
{
    P1RingEnt *e;

    e = ring->ent;
    e += ring->head % ring->count;
    e->y = src->rot[1];
    e->x = src->f40 * 0.00390625f;
    e->z = src->f48 * 0.00390625f;
    e->scale = src->f3C * 0.0625f;
    e->h14 = src->pos[2];
    e->h10 = src->pos[0];
    e->h12 = (int)src->pos[1] * 0.00390625f;
    if (e->h14 < 0.0f) {
        e->h14 = 0;
    }
    e->h16 = (int)src->f4C + 16;
    e->color = src->color;
    e->b1C = 8;
    ring->head++;
}
