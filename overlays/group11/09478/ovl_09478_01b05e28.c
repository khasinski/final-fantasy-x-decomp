#include "common.h"

extern u8 *D_01B101EC;
extern u8 *D_01B102F0;
extern u8 D_01B101A8[];
extern int D_01B101A0;

extern int func_01B0B770(void *, void *);
extern void func_001CDDD8(int);

void func_01B05E28(void)
{
    u8 *st = D_01B102F0;

    if (func_01B0B770(D_01B101A8, D_01B101EC) == 1 && *(int *)(st + 0x1B2C) == 1) {
        func_001CDDD8(D_01B101A0);
    }
}
