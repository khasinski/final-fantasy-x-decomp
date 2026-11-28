#include "common.h"

typedef struct {
    void *task;
    u8 *work;
} TaskArgBD88;

typedef struct {
    void *p0;
    float f4;
    float f8;
    float fC;
    s32 w10;
} MsgBD88;

extern void func_01B0E858(void *);
extern void func_01B0CEC8(void *);
extern void func_01B16D00(void *);

void func_01B0BD88(TaskArgBD88 *s1) {
    MsgBD88 m;
    void *m0[1];
    void *m1[1];
    u8 *s0 = s1->work;

loop:
    switch (*(u32 *)(s0 + 0x18)) {
    case 0:
        *(s32 *)(s0 + 0x30) = -0x9C40;
        *(s32 *)(s0 + 0x38) = 0x13880;
        *(s32 *)(s0 + 0x3C) = 0;
        *(s32 *)(s0 + 0x40) = 0;
        m.p0 = *(void **)(s0 + 0x44);
        m.f4 = 3.0f;
        m.f8 = 3.0f;
        m.fC = 3.0f;
        m.w10 = 0x3C;
        func_01B0E858(&m);
        *(s32 *)(s0 + 0x18) += 1;
    case 1:
        s0[0xCB] += 4;
        if (s0[0xCB] == 0x40) {
            *(s32 *)(s0 + 0x34) = 0x28;
            *(s32 *)(s0 + 0x18) += 1;
        }
        break;
    case 2:
        if (*(s32 *)(s0 + 0x34) <= 0) {
            m.p0 = *(void **)(s0 + 0x44);
            m.f4 = 1.0f;
            m.f8 = 1.0f;
            m.fC = 1.0f;
            m.w10 = 0x28;
            func_01B0E858(&m);
            *(s32 *)(s0 + 0x18) += 1;
        }
        break;
    case 3:
        s0[0xCB] -= 4;
        if (s0[0xCB] == 0) {
            *(s32 *)(s0 + 0x18) = 10;
            goto loop;
        }
        break;
    case 10:
        m0[0] = s0 + 0x50;
        func_01B0CEC8(m0);
        *(s32 *)(s0 + 0x34) = 2;
        *(s32 *)(s0 + 0x18) += 1;
    case 11:
        if (*(s32 *)(s0 + 0x34) <= 0) {
            m1[0] = s1->task;
            func_01B16D00(m1);
            *(s32 *)(s0 + 0x18) = 20000;
        }
        break;
    }

    *(s32 *)(s0 + 0xE8) += *(s32 *)(s0 + 0x30);
    *(s32 *)(s0 + 0xEC) += *(s32 *)(s0 + 0x38);
    *(s32 *)(s0 + 0x30) += *(s32 *)(s0 + 0x3C);
    *(s32 *)(s0 + 0x38) += *(s32 *)(s0 + 0x40);
    *(s32 *)(s0 + 0x34) -= 1;
}
