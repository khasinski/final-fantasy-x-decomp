/* 09411 bone/emitter dispatch (188 B, 09411 @ 0x01B01168). */

#include "common.h"

extern int func_01B01430(int);
extern int func_00111B50(int);
extern void func_01B01AE8(int, int, float *);
extern void func_01B00F10(float *);

void ovl_09411_1168(void)
{
    float pos[4];
    int v = func_00111B50(func_01B01430(-1)) >> 8;

    v -= 2;
    if (v < 0) {
        v = 10;
    }

    switch (v) {
    case 0:
        func_01B01AE8(-1, 5, pos);
        func_01B00F10(pos);
        func_01B01AE8(-1, 7, pos);
        func_01B00F10(pos);
        break;
    case 6:
        func_01B01AE8(-1, 4, pos);
        func_01B00F10(pos);
        func_01B01AE8(-1, 8, pos);
        func_01B00F10(pos);
        break;
    }
}
