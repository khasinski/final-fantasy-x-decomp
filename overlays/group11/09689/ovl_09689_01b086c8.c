#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} OvlCtx;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    u8 pad1C[0x2B4];
} OvlSub2D0;

typedef struct {
    u8 pad00[0x28];
    u32 state28;
    int timer2C;
    int cnt30;
    void *p34;
    u8 pad38[0x08];
    OvlSub2D0 sub[2];
} OvlMid;

extern void func_01B08560(void *, void *, float);
extern void func_01B11980(void *);
extern void func_01B119A8(void *);

void func_01B086C8(OvlCtx *a0) {
    u8 pad[0x60];
    void *tmp60;
    void *tmp64;
    OvlMid *s = a0->p04;

    switch (s->state28) {
    case 0:
        s->state28 = 10;
        s->timer2C = 40;
        break;
    case 10:
        if (s->timer2C <= 0) {
            int idx = s->cnt30 % 2;
            if (s->sub[idx].state18 == 20000) {
                func_01B08560(&s->sub[idx], s, 1.0f);
                s->timer2C = 55;
                s->cnt30++;
            }
        }
        break;
    case 10000:
        tmp60 = a0->p00;
        func_01B119A8(&tmp60);
        tmp64 = a0->p00;
        func_01B11980(&tmp64);
        s->state28 = 20000;
        break;
    }
    s->timer2C--;
    (void)pad;
}
