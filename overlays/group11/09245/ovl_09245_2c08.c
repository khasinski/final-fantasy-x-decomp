#include "common.h"

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0x24];
    int timer;
} Sub2C08;

typedef struct {
    void *p00;
    Sub2C08 *sub;
} Arg2C08;

void func_01B0D028(void *);

void func_01B02C08(Arg2C08 *a0)
{
    void *arg[1];
    Sub2C08 *s0 = a0->sub;

retry:
    switch (s0->state) {
    case 0:
        s0->timer = 0x5A;
        s0->state++;
        break;
    case 1:
        if (s0->timer <= 0) {
            s0->state = 10000;
            goto retry;
        }
        break;
    case 10000:
        arg[0] = a0->p00;
        func_01B0D028(arg);
        break;
    }
    s0->timer--;
}
