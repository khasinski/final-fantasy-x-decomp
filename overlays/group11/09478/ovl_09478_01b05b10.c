#include "common.h"

extern u8 *D_01B102F0;
extern int func_01B0A338(int);

int func_01B05B10(void)
{
    return func_01B0A338(*(int *)(D_01B102F0 + 0x1B20)) == 1;
}
