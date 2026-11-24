#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} OvlCtx;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    int f1C;
    float f20;
    float f24;
    u8 pad28[0x34];
    float f5C;
    u8 pad60[0x238];
    int f298;
} OvlA;

extern void func_01B0EA88(void *);

void func_01B02CD8(OvlCtx *a0) {
    void *tmp0;
    OvlA *s = a0->p04;

    switch (s->state18) {
    case 0:
        s->f24 = 0.0f;
        s->state18++;
        /* fallthrough */
    case 1:
        s->f24 += 0.008f;
        if (s->f24 >= 1.0f) {
            s->state18 = 10000;
        }
        break;
    case 10000:
        if (s->f298 & 4) {
            tmp0 = a0->p00;
            func_01B0EA88(&tmp0);
            s->state18 = 20000;
        }
        break;
    }
    s->f5C = (s->f24 + s->f20) * 0.02f * 4.5f;
}
