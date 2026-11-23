/* Overlay 09559: rank 518 actor pos/rot apply loop (0x01B05108..0x01B051A8). */
#include "common.h"

typedef struct Actor {
    int id;
    u8 pad04[0x10];
    s16 rotY;
    u8 pad16[0x1A];
    float pos[4];
    u8 pad40[0x90];
} Actor;

int func_001B6BB0(int, float *);
void func_001B6F58(int, float);

void func_01B05108(Actor *a0, int a1) {
    while (a1-- != 0) {
        func_001B6BB0(a0->id, a0->pos);
        func_001B6F58(a0->id, (float)a0->rotY * 3.1415927f * 3.0517578125e-5f);
        a0++;
    }
}
