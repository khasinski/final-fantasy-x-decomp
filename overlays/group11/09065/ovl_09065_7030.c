/* EE Battle-Effect Overlay: group 0x11, file 09065 (shared by ~131 p4 overlays)
 * .text: 0x01B07030..0x01B07148 (2 functions, 280B incl. 4B align pad).
 */
#include "p4_overlay.h"
#include "vu0.h"

typedef struct {
    float pos[3];       /* 0x00 */
    union {
        u32 rgba;
        u8 b[4];
    } col;              /* 0x0C */
    union {
        u_long128 q;
        struct {
            u8 pad00[0x0C];
            s16 h0C;
            s16 pad0E;
        } s;
    } v;                /* 0x10 */
} Ovl7030Item;

typedef struct {
    u32 count;          /* 0x00 */
    u32 cursor;         /* 0x04 */
    u32 pad08[2];       /* 0x08 */
    Ovl7030Item items[1]; /* 0x10 */
} Ovl7030Pool;

void func_01B07030(Ovl7030Pool *pool, u32 count)
{
    u32 i;
    Ovl7030Item *it;

    pool->count = count;
    pool->cursor = 0;
    it = pool->items;
    for (i = 0; i < pool->count; i++, it++) {
        MMI_SQ_ZERO(0, it);
        MMI_SQ_ZERO(16, it);
        it->v.s.h0C = 32;
        it->col.rgba = 0x80008080;
        it->col.b[2] = func_002B3D10(64) + 64;
    }
}

void func_01B070C8(Ovl7030Pool *pool, float *src, u_long128 *vel)
{
    Ovl7030Item *it;
    u32 c;

    it = &pool->items[pool->cursor % pool->count];
    func_002B5978(it->pos, src, 16.0f);
    it->v.q = *vel;
    c = pool->cursor;
    it->v.s.h0C = 0;
    /* DEBT(ORDER): prevent ee-gcc from hoisting epilogue ld ra/s2/s0 above sq/sh */
    __asm__ volatile("");
    pool->cursor = c + 1;
}
