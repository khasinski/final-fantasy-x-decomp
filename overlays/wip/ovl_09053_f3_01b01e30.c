#include "p7_overlay.h"

/* PARKED (P7): F3 TU rank 52 (func_01B01E30, 232 B, 226 containers): centre of all target
 * positions. Everything matches except the FPU register assignment of the three sums: target
 * keeps x/y/z in f21/f22/f20 (z initialised first) and divides in place. Tried all 6
 * declaration orders x 2 summation orders x in-place/out-of-place division (24 variants). */

void func_01B01E30(float *out)
{
    P7Targets *t = &D_01B005A0;
    float pos[4];
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float n;
    int i;

    for (i = 0; i < t->count; i++) {
        func_01B017E8(i, pos, 0);
        z += pos[2];
        x += pos[0];
        y += pos[1];
    }
    n = t->count;
    out[3] = 1.0f;
    z /= n;
    x /= n;
    y /= n;
    out[2] = z;
    out[0] = x;
    out[1] = y;
}
