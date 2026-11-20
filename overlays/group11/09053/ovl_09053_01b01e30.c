/* Shared 09053-family helper (TU rank 33, 226 containers): average target positions. */
#include "p7_overlay.h"

void func_01B01E30(float *out)
{
    P7Targets *t = &D_01B005A0;
    float pos[4];
    /* DEBT(FAKE): register pin matches original $f20 allocation for z sum. */
    register float z __asm__("$f20") = 0.0f;
    float y = 0.0f;
    float x = 0.0f;
    float n;
    int i;

    for (i = 0; i < t->count; i++) {
        func_01B017E8(i, pos, 0);
        x += pos[0];
        y += pos[1];
        z += pos[2];
    }
    n = t->count;
    out[3] = 1.0f;
    x /= n;
    y /= n;
    z /= n;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
