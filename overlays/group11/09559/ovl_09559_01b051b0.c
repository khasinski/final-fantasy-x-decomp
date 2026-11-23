/* Overlay 09559: rank 580 actor loop caller (0x01B051B0..0x01B05230). */
#include "common.h"

typedef struct Actor {
    int id;
    int handle;
    u8 pad08[0xC8];
} Actor;

extern int D_01B0D260;
extern Actor D_01B0D510[];

void func_01B051A8(int, int);

void func_01B051B0(int a0) {
    int i;
    for (i = 0; i < D_01B0D260; i++) {
        func_01B051A8((&D_01B0D510[i])->handle, a0);
    }
}
