#include "common.h"
#include "vu0.h"

extern u8 D_01B0BF48[];
extern u8 *D_01B0C0B0;

extern void func_01B076C8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B0AEE8(void *, s32);
extern void func_01B0AFF0(void *, s32);

void func_01B03AF8(void) {
    u8 *s0 = D_01B0C0B0;
    u8 *s1 = s0 + 0x390;
    u8 *v1;
    u8 *p;

    func_01B076C8(D_01B0BF48, s1, 3, 0, 0, 0, 0.12f);
    MMI_COPY_LQ_A3(s0 + 0x460, s0 + 0x980);
    MMI_COPY_SQ_A3(s0 + 0x460);
    *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x85C8);
    *(float *)(s1 + 0xD4) -= 1.0f;

    v1 = s0 + 0x8330;
    *(s32 *)(v1 + 0x0) = 0;
    *(s32 *)(v1 + 0x4) = 0x50;
    *(s32 *)(v1 + 0x8) = 0;
    *(s32 *)(v1 + 0xC) = 0x14;
    func_01B0AEE8(v1, 0x3C);

    p = s0 + 0x8368;
    func_01B0AFF0(p, 0x28);
    *(float *)(p + 0x4) = 1.0f;
    *(float *)(p + 0x8) = 1.0f;
    *(s32 *)(p + 0xC) = 0;
    *(float *)(p + 0x10) = 4.0f;
    *(float *)(p + 0x14) = 4.0f;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x24) = 0x14;
    *(u16 *)(p + 0x2C) |= 3;
}
