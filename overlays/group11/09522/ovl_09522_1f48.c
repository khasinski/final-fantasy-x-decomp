/* 09522 state machine 1 (808 B). */
#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    u32 substate;
    int timer;
    int cnt24;
    int parity;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    u8 *p40;
    u8 pad44[0x60];
    float fa4;
} OvlObj;

typedef struct {
    u32 w00;
    OvlObj *obj;
} OvlCtx;

extern int g_ovl_760;
extern void fn_ovl_be88(void *);
extern int func_001CE050(int, int);
extern int func_001CE1A8(int);
extern int func_001C5E90(int, int, int);

void ovl_09522_1f48(OvlCtx *a0)
{
    OvlObj *s0 = a0->obj;
    u32 pad00[4];
    u32 arg10;

    again:
    switch (s0->state) {
    case 0:
        s0->state++;
        s0->f30 = 1.0f;
        s0->timer = 6;
        s0->cnt24 = 0;
        s0->parity = 0;
        /* fallthrough */

    case 1:
        s0->f30 += (float)(1 - ((s0->parity & 1) << 1)) * 0.05f;
        if (++s0->cnt24 > 0) {
            s0->cnt24 = 0;
            s0->parity++;
        }
        if (s0->timer > 0) {
            break;
        }
        s0->state = 20;
        goto again;

    case 20:
        s0->timer = 25;
        s0->f3c = 0.15f;
        s0->state = 21;
        /* fallthrough */

    case 21:
        s0->f3c -= 0.02f;
        if (s0->f3c <= 0.0f) {
            s0->state = 10;
            goto again;
        }
        s0->f30 -= s0->f3c;
        break;

    case 10:
        s0->cnt24 = 0;
        s0->state = 11;
        s0->parity = 0;
        /* fallthrough */

    case 11:
        s0->f30 += (float)(1 - ((s0->parity & 1) << 1)) * 0.03f;
        if (++s0->cnt24 > 0) {
            s0->cnt24 = 0;
            s0->parity++;
        }
        if (s0->timer > 0) {
            break;
        }
        s0->state = 30;
        goto again;

    case 30:
        s0->substate = 10;
        s0->state = 31;
        /* fallthrough */

    case 31:
        s0->f30 += 0.05f;
        if (s0->f30 >= 1.0f) {
            s0->f30 = 1.0f;
            s0->state = 10000;
            goto again;
        }
        break;

    case 10000:
        arg10 = a0->w00;
        fn_ovl_be88(&arg10);
        s0->state = 20000;
        break;
    }

    switch (s0->substate) {
    case 0:
        func_001CE050(*(int *)(s0->p40 + 0x54), 24);
        s0->substate++;
        break;

    case 1:
        if (func_001CE1A8(*(int *)(s0->p40 + 0x54)) != 0) {
            func_001CE050(*(int *)(s0->p40 + 0x54), 25);
            s0->substate++;
        }
        break;

    case 10:
        func_001C5E90(g_ovl_760, *(int *)(s0->p40 + 0x54), 0);
        s0->substate++;
        break;
    }

    s0->timer--;
    s0->fa4 = s0->f34 - s0->f2c * (1.0f - s0->f30);
}
