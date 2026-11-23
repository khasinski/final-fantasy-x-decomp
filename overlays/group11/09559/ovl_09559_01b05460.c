/* Overlay 09559: rank 387 actor circle placement (0x01B05460..0x01B05550). */
#include "common.h"

typedef struct Actor {
    u8 pad00[0x16];
    s16 rotY;
    u8 pad18[0x28];
    float pos[4];
    u8 pad50[0x80];
} Actor;

extern float D_004F4610[];

void func_01B05460(Actor *a0, int a1, float *a2, u16 a3, u16 a4, float f12) {
    int i;
    if (a1 == 1) {
        a0->pos[0] = a2[0];
        a0->rotY = a4;
        a0->pos[1] = a2[1];
        a0->pos[2] = a2[2];
        a0->pos[3] = 1.0f;
        return;
    }
    for (i = 0; i < a1; i++, a0++) {
        u16 ang = a3 + (i * 0x10000) / a1;
        a0->rotY = ang + a4;
        a0->pos[0] = a2[0] + D_004F4610[((u16)(ang + 0x4000)) >> 4] * f12;
        a0->pos[2] = a2[2] + D_004F4610[ang >> 4] * f12;
        a0->pos[1] = a2[1];
        a0->pos[3] = 1.0f;
    }
}
