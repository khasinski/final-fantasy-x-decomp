#include "common.h"

typedef struct {
    void *task;
    u8 *work;
} TaskArg29E8;

typedef struct {
    u8 pad00[0x18];
    u32 state;
    s32 timer;
    float cur;
    float total;
    u8 pad28[8];
    float base[4];
    float delta[4];
    u8 *chr;
    u8 *posNode;
} Work29E8;

extern s32 func_001CE050(void *, s32);
extern s32 func_001CE1A8(void *);
extern void func_001CE2F0(void *, s32);
extern void func_002DD038(void *, void *, void *);
extern void func_002DD068(void *, void *, float);
extern void func_002DD020(void *, void *, void *);
extern void func_01B057B0(void *);
extern void func_01B0F1F0(void *);

void func_01B029E8(TaskArg29E8 *s2) {
    float sp0[4];
    void *m10[1];
    void *m14[1];
    Work29E8 *s0 = (Work29E8 *)s2->work;
    u8 *s1 = s0->chr;

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
    case 2:
        break;
    case 10:
        func_001CE050(*(void **)(s1 + 0x54), 186);
        s0->state++;
        break;
    case 11:
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            func_001CE050(*(void **)(s1 + 0x54), 187);
            s0->state++;
        }
        break;
    case 12:
        break;
    case 30:
        func_001CE050(*(void **)(s1 + 0x54), 188);
        s0->state++;
        break;
    case 31:
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            func_001CE050(*(void **)(s1 + 0x54), 189);
            s0->state++;
        }
        break;
    case 32:
        break;
    case 10000:
        func_001CE050(*(void **)(s1 + 0x54), 181);
        s0->state++;
        break;
    case 10001:
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            float t = (float)func_001CE050(*(void **)(s1 + 0x54), 182);
            s0->cur = t;
            s0->total = t;
            func_002DD038(s0->delta, s0->posNode + 0x20, s0->base);
            s0->state++;
        }
        break;
    case 10002:
        s0->cur -= 1.0f;
        func_002DD068(sp0, s0->delta, s0->cur / s0->total);
        func_002DD020(s0->posNode + 0x20, s0->base, sp0);
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            func_001CE050(*(void **)(s1 + 0x54), 183);
            s0->state++;
        }
        break;
    case 10003:
        if (func_001CE1A8(*(void **)(s1 + 0x54)) != 0) {
            func_001CE2F0(*(void **)(s1 + 0x54), 0);
            m10[0] = s1;
            func_01B057B0(m10);
            m14[0] = s2->task;
            func_01B0F1F0(m14);
            s0->state = 20000;
        }
        break;
    }
    s0->timer--;
}
