/* WIP (p3, file09044 0x01B06CA8..0x01B06D28, 131 containers). NOT MATCHING.
 * Remaining diff (6 insns): the target keeps sq before `lw ring->head` (the 128-bit store aliases
 * the u32 load) but lets the s16 store at 0x1C pass it. No union / cast combination tried reproduced
 * both dependencies at once. */
#include "p3_overlay.h"

typedef struct P3RingEnt {
    float v[4];             /* 0x00: set up by func_002B5978 */
    u_long128 q10;          /* 0x10 */
} P3RingEnt;

typedef struct P3Ring {
    u32 count;              /* 0x00 */
    u32 head;               /* 0x04 */
    u8 pad08[8];
    P3RingEnt ent[1];       /* 0x10 */
} P3Ring;

void func_002B5978(void *dst, float scale);

void func_01B06CA8(P3Ring *ring, int a1, u_long128 *src)
{
    P3RingEnt *e = &ring->ent[ring->head % ring->count];

    func_002B5978(e, 16.0f);
    e->q10 = *src;
    ((s16 *)&e->q10)[6] = 0;
    ring->head++;
}
