/* Overlay 09559: rank 52 sprite pool init, tick and alloc (0x01B05638..0x01B056E0). */
#include "common.h"

typedef struct Sprite {
    u8 pad00[0x80];
    void *used;
    u8 pad84[4];
    u16 age;
    u8 pad8A[0x26];
} Sprite;

extern Sprite D_01B0F590[32];
extern Sprite D_01B0F7A0[29];

void func_01B05638(void) {
    int i;
    for (i = 31; i >= 0; i--) {
        D_01B0F590[i].used = 0;
    }
}

void func_01B05670(void) {
    int i;
    for (i = 0; i < 32; i++) {
        D_01B0F590[i].age++;
    }
}

Sprite *func_01B056A8(void) {
    Sprite *p = D_01B0F7A0;
    do {
        if (p->used == 0) {
            return p;
        }
        p++;
    } while (p < &D_01B0F7A0[29]);
    return 0;
}
