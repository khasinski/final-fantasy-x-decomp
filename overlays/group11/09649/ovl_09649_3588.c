#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0B1F8;
extern s32 D_01B008F4;
extern u8 D_01B0B130[];
extern u8 D_01B0B1D8[];

extern void func_01B04098(s32, float *, s32);
extern void func_01B05888(s32, void *, void *);
extern s32 func_01B069B8(void *, void *, s32, s32, s32, void *, float);
extern void func_01B034F0(void);
extern void func_01B0A1D8(void *, s32);
extern s32 func_002EFD78(void);
extern void func_01B05308(s32, s32);
extern void func_01B05DD8(void *, s32);
extern void func_01B04EA0(s32);

void func_01B03588(void) {
    float v[4];
    u8 *base = D_01B0B1F8;
    s32 count = D_01B008F4;
    u8 *p3 = base + 0x850;
    u8 *p2 = base + 0x2C64;
    u8 *p1 = base + 0x1850;
    s32 delay = 32;
    s32 i;

    for (i = 0; i < count; i++) {
        s32 d16;
        *(s32 *)(p1 + 0x14) = 1;
        func_01B04098(i, v, 3);
        d16 = delay + 16;

        *(float *)(p1 + 0x90) = v[0];
        *(float *)(p1 + 0x94) -= 200.0f;
        *(float *)(p1 + 0x98) = v[2];
        *(float *)(p1 + 0x80) = 0.0f;
        *(float *)(p1 + 0x84) = 0.0f;
        *(float *)(p1 + 0x88) = 0.0f;
        *(float *)(p1 + 0xA0) = 1.0f;
        *(float *)(p1 + 0xA4) = 1.0f;
        *(float *)(p1 + 0xA8) = 1.0f;
        func_01B05888(i, p1 + 0x20, p1 + 0x80);

        *(float *)(p1 + 0x50) = *(float *)(p1 + 0x90);
        *(float *)(p1 + 0x54) = *(float *)(p1 + 0x94);
        *(float *)(p1 + 0x58) = *(float *)(p1 + 0x98);
        *(float *)(p1 + 0xB8) = 0.0f;
        *(float *)(p1 + 0xBC) = 0.0f;
        *(float *)(p1 + 0x60) = 0.0f;
        *(float *)(p1 + 0x64) = -((*(float *)(p1 + 0x94) - v[1]) * 0.0625f);
        *(float *)(p1 + 0x68) = 0.0f;
        *(float *)(p1 + 0x6C) = 0.0f;
        *(float *)(p1 + 0x70) = 0.0f;
        *(float *)(p1 + 0x74) = 0.0f;
        *(float *)(p1 + 0x78) = 0.0f;
        *(float *)(p1 + 0x7C) = 0.0f;
        *(s32 *)(p1 + 0xC4) = delay;
        *(s32 *)(p1 + 0xCC) = 0;
        *(s32 *)(p1 + 0xD0) = 0;
        *(s32 *)(p1 + 0xC0) = 16;
        func_01B069B8(D_01B0B130, p3, 5, d16, 0, (void *)func_01B034F0, 0.1f);

        copy_vec(p3 + 0xD0, v);
        *(s32 *)(p3 + 0x120) = i;
        *(float *)(p3 + 0xD4) -= 2.0f;
        p1 += 0xE0;

        func_01B0A1D8(p2, 10);
        p3 += 0x130;
        *(float *)(p2 + 0x04) = 2.0f;
        *(float *)(p2 + 0x08) = 1.0f;
        *(s32 *)(p2 + 0x0C) = 0;
        *(float *)(p2 + 0x10) = 2.0f;
        *(float *)(p2 + 0x14) = 1.0f;
        *(s32 *)(p2 + 0x18) = 0;
        *(s32 *)(p2 + 0x24) = d16;
        *(u16 *)(p2 + 0x2C) |= 3;
        p2 += 0x30;
        delay += (func_002EFD78() % 10) + 1;
    }

    func_01B05308(-1, 0);
    func_01B05DD8(D_01B0B1D8, 0);
    func_01B04EA0(1);
}
