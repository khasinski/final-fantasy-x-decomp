#include "p6_overlay.h"

/* F2 TU rank 100: angle conversions (radians to 0x10000-per-turn units). Compiled with -O0. */

float func_01B07238(register float rad)
{
    return 4.712389f - rad;
}

int func_01B07278(register float rad)
{
    return rad * 32768.0f / 3.1415927f;
}
