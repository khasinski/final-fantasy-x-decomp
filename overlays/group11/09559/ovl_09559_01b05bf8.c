#include "common.h"

typedef struct RingEnt {
    u_long128 v0;      /* 0x00 */
    u_long128 v1;      /* 0x10 */
    void *tex;         /* 0x20 */
    int a24;           /* 0x24 */
    int a28;           /* 0x28 */
    int a2c;           /* 0x2C */
    int a30;           /* 0x30 */
    float f34;         /* 0x34 */
    u8 pad38[8];
} RingEnt;             /* 0x40 */

extern RingEnt D_01B10B90[512];
extern int D_01B18B90;
extern int D_01B18B94;

static inline RingEnt *alloc_ring(void)
{
    RingEnt *e = &D_01B10B90[D_01B18B90];
    D_01B18B90++;
    if (D_01B18B90 >= 512) {
        D_01B18B90 = D_01B18B94;
    }
    return e;
}

RingEnt *func_01B05BF8(u_long128 *v0, u_long128 *v1, int a2, u8 *hdr, int a4, int a5, float f0)
{
    RingEnt *e = alloc_ring();
    void *tex = hdr + *(s16 *)(hdr + 16);

    e->v0 = *v0;
    e->a24 = a5;
    e->tex = tex;
    e->v1 = *v1;
    e->a2c = a2;
    e->f34 = f0;
    e->a30 = a4;
    e->a28 = 0;
    return e;
}
