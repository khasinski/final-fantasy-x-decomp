#include "p7_overlay.h"

/* F3 TU rank 13 without its first two functions (see ovl_09053_f3_01b01f18.c). */

int func_01B02128(int idx)
{
    int v = func_01B01C60(idx);
    int *p;

    for (p = D_01B00578; *p != -1; p++) {
        if (*p == v) {
            return 1;
        }
    }
    return MsGetChrFly(func_01B01598(idx));
}

int func_01B02198(int idx)
{
    return func_001B8548(func_01B01598(idx)) == 0;
}

int func_01B021C0(int idx)
{
    return func_001B85B0(func_01B01598(idx)) == 0;
}

int func_01B021E8(int idx)
{
    return MsGetRamChrMonster(func_01B01598(idx)) == 0;
}

void func_01B02210(int idx, int speed)
{
    int chr;

    if (D_01B005A0.mode == 0) {
        chr = func_01B01598(idx);
        if (chr < 32) {
            MsEffectSetSpeed(chr, speed);
            return;
        }
    } else if (speed < 0) {
        speed = 256;
    }
    Ch_SetMotionSpeed(func_01B01630(idx), speed);
}

int func_01B02298(int idx)
{
    return func_001B84F8(func_01B01598(idx));
}
