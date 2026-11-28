#include "common.h"

extern u8 *D_01B0A988;
extern u32 D_01B0A97C;

extern void func_01B037C8(s32, void *, s32);
extern s32 func_01B03EF8(void *);
extern float func_01B03C18(s32);
extern void func_01B06E18(void *, void *, void *);
extern void func_01B04A38(s32, void *);
extern void func_01B04FB8(s32, void *, void *);
extern void func_01B06F20(void *, void *, void *);
extern void func_01B013D8(void);
extern void func_01B01628(void);

#define COPY_VEC(dst, src) do { \
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory"); \
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory"); \
} while (0)

void func_01B012B8(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    register u8 *base __asm__("$17") = D_01B0A988;
    u8 *p2b20 = base + 0x2B20;
    u8 *p2b30;

    func_01B037C8(-1, v0, 0);
    COPY_VEC(p2b20, v0);

    p2b30 = base + 0x2B30;
    *(float *)(base + 0x2B34) = func_01B03C18(func_01B03EF8(p2b30));

    func_01B06E18(v1, v0, p2b30);
    v1[0] = 0.0f;
    COPY_VEC(base + 0x2B00, v1);
    {
        register u8 *dst1 __asm__("$3") = base + 0x2B10;
        COPY_VEC(dst1, v0);
    }

    {
        register u8 *p2ac0 __asm__("$16") = base + 0x2AC0;
        register s32 neg1 __asm__("$4") = -1;
        __asm__("" : "+r"(p2ac0), "+r"(neg1));
        func_01B04A38(neg1, p2ac0);
        func_01B04FB8(-1, p2ac0, v1);
    }

    *(float *)(base + 0x3BF4) = v1[1];
    {
        register u8 *p2b50 __asm__("$5") = base + 0x2B50;
        register float f_neg60 __asm__("$f0") = -60.0f;
        register float f_one __asm__("$f1") = 1.0f;
        __asm__("" : "+r"(p2b50), "+f"(f_neg60), "+f"(f_one));
        v2[2] = f_neg60;
        v2[3] = f_one;
        v2[0] = 0.0f;
        v2[1] = 0.0f;
        COPY_VEC(p2b50, p2b20);
        func_01B06F20(v1, p2b50, v2);
    }

    *(float *)(base + 0x3BF0) = 0.0f;
    *(float *)(base + 0x3BF8) = 0.0f;
    D_01B0A97C = 1;
    func_01B013D8();
    func_01B01628();
}
