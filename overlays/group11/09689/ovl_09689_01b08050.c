#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} OvlCtx;

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    int timer1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 buf30[0x20];
    float f50;
    float f54;
    float f58;
    float f5C;
    u8 buf60[0x20];
    u8 buf80[0x08];
    int f88;
    u8 pad8C[0xFD0];
    int f105C;
    u8 pad1060[0x10];
    void *p1070;
} OvlSubB;

extern float func_001ACED8(void);
extern void func_01B0A350(void *);
extern void func_01B11980(void *);
extern void func_01B119A8(void *);

void func_01B08050(OvlCtx *a0) {
    struct {
        void *p00;
        int p04;
        int p08;
        int pad0C;
    } arg0;
    void *tmp10;
    void *tmp14;
    OvlSubB *s = a0->p04;

    s->f50 = s->f28 + (0.5f - (func_001ACED8() - 0.99f)) * 3.0f;
    s->f58 = s->f2C + (0.5f - (func_001ACED8() - 0.99f)) * 3.0f;

retry:
    switch (s->state18) {
    case 0:
        s->timer1C = 30;
        s->state18 = 1;
        break;
    case 1:
        if (s->timer1C <= 0) {
            s->state18 = 20;
            goto retry;
        }
        break;
    case 20:
        s->f24 = 0.005f;
        s->f20 = 0.05f;
        s->timer1C = 180;
        s->state18 = 21;
        /* fallthrough */
    case 21:
        if (s->timer1C <= 0) {
            arg0.p00 = s->p1070;
            arg0.p04 = 0;
            arg0.p08 = 64;
            func_01B0A350(&arg0);
            s->f105C = 1;
            s->timer1C = 64;
            s->state18++;
        }
        /* fallthrough */
    case 22:
        s->f20 += s->f24;
        s->f54 += s->f20;
        s->f88 += 0x20;
        if (s->timer1C <= 0) {
            s->state18 = 10000;
            goto retry;
        }
        break;
    case 10000:
        tmp10 = a0->p00;
        func_01B119A8(&tmp10);
        tmp14 = a0->p00;
        func_01B11980(&tmp14);
        s->state18 = 20000;
        break;
    }
    s->timer1C--;
}
