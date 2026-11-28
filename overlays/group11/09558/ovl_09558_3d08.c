#include "common.h"

typedef struct {
    void *task;
    u8 *work;
} TaskArg3D08;

typedef struct {
    u8 pad00[0x18];
    u32 state;
    s32 timer;
    u8 *chr;
} Work3D08;

extern s32 func_001CE050(void *, s32);
extern s32 func_001CE1A8(void *);
extern void func_001CE2F0(void *, s32);
extern void func_01B0FC98(void *);

void func_01B03D08(TaskArg3D08 *s2) {
    void *m0[1];
    Work3D08 *s0 = (Work3D08 *)s2->work;
    u8 *s1 = s0->chr;

loop:
    switch (s0->state) {
    case 0:
        func_001CE050(*(void **)(s1 + 0x54), 184);
        s0->state++;
        break;
    case 1:
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            func_001CE050(*(void **)(s1 + 0x54), 185);
            s0->state++;
        }
        break;
    case 10:
        func_001CE050(*(void **)(s1 + 0x54), 186);
        s0->timer = 96;
        s0->state++;
        break;
    case 11:
        if (s0->timer <= 0) {
            s0->state = 20;
            goto loop;
        }
        break;
    case 20:
        func_001CE050(*(void **)(s1 + 0x54), 187);
        s0->state++;
        break;
    case 21:
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            func_001CE2F0(*(void **)(s1 + 0x54), 0);
            m0[0] = s2->task;
            func_01B0FC98(m0);
            s0->state = 20000;
        }
        break;
    }
    s0->timer--;
}
