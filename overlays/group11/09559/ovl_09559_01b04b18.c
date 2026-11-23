/* Overlay 09559: rank 134 actor batch helpers (0x01B04B18..0x01B04E08). */
#include "common.h"

typedef struct Actor {
    int id;
    int handle;
    u8 pad08[0xC8];
} Actor;

extern int D_01B0D260;
extern Actor D_01B0D2A0[3];
extern Actor D_01B0D510[];

void func_002994D8(int);
void func_002994B8(int);
void func_001B5810(int, int);
int func_001B6210(int, int);
float func_002E94A0(void);

void func_01B04B18(Actor *a0, int a1) {
    while (a1-- != 0) {
        if (a0->id != 0xFF) {
            func_002994D8(a0->handle);
        }
    }
}

void func_01B04B80(Actor *a0, int a1) {
    while (a1-- != 0) {
        if (a0->id != 0xFF) {
            func_002994B8(a0->handle);
        }
    }
}

void func_01B04BE8(int a0) {
    int i;
    for (i = 0; i < D_01B0D260; i++) {
        if (D_01B0D510[i].id != 0xFF) {
            func_001B5810(D_01B0D510[i].id, a0);
        }
    }
}

void func_01B04C78(void) {
    int i;
    for (i = 0; i < D_01B0D260; i++) {
        func_001B6210(D_01B0D510[i].id, 0);
    }
    for (i = 0; i < 3; i++) {
        func_001B6210(D_01B0D2A0[i].id, 0);
    }
}

void func_01B04D18(void) {
    int i;
    for (i = 0; i < D_01B0D260; i++) {
        func_001B6210(D_01B0D510[i].id, -1);
    }
    for (i = 0; i < 3; i++) {
        func_001B6210(D_01B0D2A0[i].id, -1);
    }
}

u16 func_01B04DB8(void) {
    return (u16)(func_002E94A0() * 32768.0f / 3.1415927f);
}
