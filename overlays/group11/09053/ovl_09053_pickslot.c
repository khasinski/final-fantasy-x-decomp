#include "p8_overlay.h"

extern P8Dmg D_01B006A4[]; /* == D_01B005A0.dmg */

int func_001ACEA0(void);

/* Fill out[0..total) with target slots, each slot drawn at random weighted by its
 * remaining damage amount. */
int func_01B02BD8(s8 *out)
{
    int weight[8];
    s8 pool[256];
    int total = D_01B005A0.total;
    int count = D_01B005A0.count;
    int i, j, k, n, slot;

    if (count >= 2) {
        for (i = 0; i < count; i++) {
            P8Dmg *d = &D_01B006A4[i];
            weight[i] = d->amount;
        }
        for (i = 0; i < total; i++) {
            n = 0;
            for (j = 0; j < count; j++) {
                for (k = 0; k < weight[j]; k++) {
                    pool[n++] = j;
                }
            }
            slot = pool[func_001ACEA0() % n];
            out[i] = slot;
            weight[slot]--;
        }
    } else {
        for (i = 0; i < total; i++) {
            out[i] = 0;
        }
    }
    return total;
}
