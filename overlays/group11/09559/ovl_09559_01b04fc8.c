/* Overlay 09559: rank 352 actor matrix update helpers (0x01B04FC8..0x01B050E8). */
#include "common.h"

typedef struct Actor {
    int id;
    int handle;
    u8 pad08[0xE];
    s16 rotY;
    u8 pad18[0x10];
    float scale;
    u8 pad2C[0x14];
    u_long128 pos;
    u8 pad50[0x40];
    u_long128 mat[4];
} Actor;

void func_0026BE48(void *, int);
void func_01B049B8(void *, void *, float);
void func_00110830(int, void *);

void func_01B04FC8(Actor *a0) {
    u_long128 m[4];
    func_0026BE48(m, -a0->rotY - 0x4000);
    func_01B049B8(a0->mat, m, a0->scale);
    a0->mat[3] = a0->pos;
}

void func_01B05018(Actor *a0, int a1) {
    while (a1-- != 0) {
        func_01B04FC8(a0);
        a0++;
    }
}

void func_01B05070(Actor *a0, int a1) {
    while (a1-- != 0) {
        if (a0->id != 0xFF) {
            func_01B04FC8(a0);
            func_00110830(a0->handle, a0->mat);
        }
        a0++;
    }
}
