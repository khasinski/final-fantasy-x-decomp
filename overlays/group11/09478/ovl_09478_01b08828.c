#include "common.h"

extern u8 *D_01B102F0;

int func_01B08828(void)
{
    return *(int *)(D_01B102F0 + 0x1B24) == 0;
}
