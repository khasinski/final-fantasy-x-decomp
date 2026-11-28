#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

extern u8 D_01B0C700;
extern u8 *D_01B0C888;

extern void func_01B07E80(void *, void *, s32, s32, s32, s32, float);
extern void func_01B0B6A0(void *, s32);
extern void func_01B0B7A8(void *, s32);

void func_01B03E60(void) {
    u8 *s = D_01B0C888;
    u8 *obj = s + 0x390;
    u8 *p1;
    u8 *p2;

    func_01B07E80(&D_01B0C700, obj, 3, 0, 0, 0, 0.12f);
    copy_vec(s + 0x460, s + 0x9E0);
    *(float *)(obj + 0xC4) = *(float *)(s + 0x8608);
    *(float *)(obj + 0xD4) -= 1.0f;

    p1 = s + 0x8390;
    *(s32 *)(p1 + 0xC) = 20;
    *(s32 *)(p1 + 0x4) = 80;
    *(s32 *)(p1 + 0x0) = 0;
    *(s32 *)(p1 + 0x8) = 0;
    func_01B0B6A0(p1, 60);

    p2 = s + 0x83C8;
    func_01B0B7A8(p2, 40);
    *(float *)(p2 + 0x4) = 1.0f;
    *(float *)(p2 + 0x8) = 1.0f;
    *(s32 *)(p2 + 0xC) = 0;
    *(float *)(p2 + 0x10) = 4.0f;
    *(float *)(p2 + 0x14) = 4.0f;
    *(s32 *)(p2 + 0x18) = 0;
    *(s32 *)(p2 + 0x24) = 20;
    *(u16 *)(p2 + 0x2C) |= 3;
}
