#include "p9_overlay.h"

/* Effect slot lookup (family F9, TU rank 344, file09206). */

typedef struct P9Slot {
    u8 data[0x150];
} P9Slot;

extern int D_01B115A8;
extern P9Slot D_01B115B0[];

P9Slot *func_01B09BE8(int i)
{
    if (i == -1) {
        i = D_01B115A8;
    }
    return &D_01B115B0[i];
}
