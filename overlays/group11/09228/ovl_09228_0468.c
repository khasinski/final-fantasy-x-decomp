#include "common.h"

typedef struct {
    u8 pad00[0x16];
    s16 h16;
    u8 pad18[0x08];
} Slot0468;

extern Slot0468 D_01D01BC0[64];

void ovl_09228_0468(void)
{
    int i;

    for (i = 0; i < 64; i++) {
        D_01D01BC0[i].h16 = -1;
    }
}
