#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 D_01B092E0[];
extern u8 *D_01B093A8;

float func_01B06C50(float a0, float a1);
void func_01B032B8(int a0, float a1);
void func_01B037C8(int a0, int a1, int a2, void *a3);
void func_01B06A80(void *a0, void *a1, void *a2);
void func_01B05C48(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B09098(void *a0, int a1, int a2, float f0, float f1);

void func_01B01B10(void)
{
    u8 *s0 = D_01B093A8;
    float f0;
    float t;
    float ang;

    if (*(int *)(s0 + 0x248C) > 0) {
        *(int *)(s0 + 0x248C) -= 1;
    }
    f0 = func_01B06C50(*(float *)(s0 + 0x2484), *(float *)(s0 + 0x2488));
    t = (float)*(int *)(s0 + 0x248C) * 0.0625f;
    ang = f0 * (1.0f - t) + *(float *)(s0 + 0x2484) * t;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    func_01B032B8(-1, ang);
}

void func_01B01BE0(u8 *a0)
{
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *v = D_01B093A8;

    if (*(int *)(a0 + 0x118) < 0xC0) {
        func_01B037C8(-1, 1, 0, v0);
        *(float *)(a0 + 0xD0) = v0[0];
        *(float *)(a0 + 0xD8) = v0[2];
    } else {
        v1[0] = 0.0f;
        v1[1] = *(float *)(v + 0x2488);
        v1[2] = 0.0f;
        v1[3] = 0.0f;
        v2[0] = 0.0f;
        v2[1] = 0.0f;
        v2[2] = -1.5f;
        v2[3] = 1.0f;
        func_01B06A80(v1, a0 + 0xD0, v2);
    }
}

void func_01B01C80(void)
{
    u8 *s0 = D_01B093A8;

    func_01B05C48(D_01B092E0, s0, 0, 0, 0, 0, 0.04f);
    {
        register u8 *dst __asm__("$3") = s0 + 0xD0;
        register u8 *src __asm__("$2") = s0 + 0x18F0;
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
    }
    *(void **)(s0 + 0x104) = (void *)func_01B01BE0;
    *(float *)(s0 + 0xC4) = *(float *)(s0 + 0x2488);
    *(float *)(s0 + 0xD4) -= 0.5f;
    func_01B09098(s0 + 0x1C80, 0x28, 0, 1.0f, 0.5f);
}
