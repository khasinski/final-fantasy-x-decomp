#include "common.h"

extern void func_002DD0B0(void *, void *);
extern void func_01B02F20(void *, void *);

void func_01B00FE8(u8 *dst, u8 *src) {
    float v[4];

    func_002DD0B0(v, src + 32);
    v[1] = 0.0f;
    func_01B02F20(dst, v);
    func_002DD0B0(dst + 48, src + 48);
}
