#include "common.h"

extern void func_002DD0B0(void *, void *);
extern void func_002DD020(void *, void *, void *);
extern void func_002DD038(void *, void *, void *);

typedef struct {
    u8 *obj;
    void *p4;
    float f8;
    s32 flag;
} ArgAA80;

void func_01B0AA80(ArgAA80 *arg) {
    float sp[4];
    u8 *s0 = arg->obj;

    if (!(*(u32 *)(s0 + 0xE8) & 8)) {
        sp[0] = (float)*(s32 *)(s0 + 0xC0) * *(float *)(s0 + 0x20);
        sp[1] = (float)*(s32 *)(s0 + 0xC4) * *(float *)(s0 + 0x24);
        sp[2] = (float)*(s32 *)(s0 + 0xC8) * *(float *)(s0 + 0x28);
        sp[3] = (float)*(s32 *)(s0 + 0xCC) * *(float *)(s0 + 0x2C);
        func_002DD0B0(s0 + 0xB0, sp);
    } else {
        func_002DD020(sp, s0 + 0x90, s0 + 0xA0);
    }

    func_002DD0B0(s0 + 0x90, sp);

    if (arg->flag != 0) {
        func_002DD038(s0 + 0xA0, s0 + 0xB0, sp);
        *(u32 *)(s0 + 0xE8) |= 0x10;
    } else {
        func_002DD038(s0 + 0xA0, arg->p4, sp);
    }

    *(s32 *)(s0 + 0xE0) = 0;
    __asm__("" : : "r"(s0) : "memory");
    *(float *)(s0 + 0xE4) = arg->f8;
    *(u32 *)(s0 + 0xE8) |= 8;
}
