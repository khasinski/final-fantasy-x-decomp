#include "p3_overlay.h"

u32 func_01B06FD0(void *res, int n)
{
    /* header 0x30 + entries + s16 map, rounded up to 16 */
    return (n * sizeof(P3FadeEnt) + func_002B7E18(res) * sizeof(s16) + 0x3F) & ~0xF;
}

void func_01B07018(P3FadePool *pool, void *res, void *a2, int n)
{
    P3FadeEnt *e;
    s16 *map;
    int i;
    int cnt;

    pool->n = n;
    pool->h02 = 0;
    pool->nmap = func_002B7E18(res);
    e = pool->ent;
    for (i = 0; i < n; i++) {
        e->slot = -1;
        e++;
    }
    map = (s16 *)e;
    pool->map = map;
    cnt = func_002B7E18(res);
    for (i = 0; i < cnt; i++) {
        *map++ = -1;
    }
    func_002B7EA0(res, a2, pool->x10, pool->x20);
}
