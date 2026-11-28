#include "common.h"

extern int D_01B00F6C;
extern int D_01B011EC;
extern int D_01B00F58;
extern int D_01B00F60[];
extern u8 *D_01B00F54;
extern void *D_01B009BC;
extern void func_001C5E90(void *, u32, int);

int func_01B03108(void)
{
    int i;

    if (D_01B00F6C != 0) {
        return 0;
    }
    if (D_01B011EC < 0x28) {
        return 1;
    }
    for (i = 0; i < 3 && i <= D_01B00F58 - 1; i++) {
        if (D_01B00F60[i] != 0) {
            func_001C5E90(D_01B009BC, D_01B00F54[i], 0);
        }
    }
    return 0;
}
