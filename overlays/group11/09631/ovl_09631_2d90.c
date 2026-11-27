#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_M(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_M(dst) __asm__ volatile("sq $7, 0($3)" : "=m"(*(dst)) : : "memory")

extern u8 *D_01B0A1E0;
extern u8 D_01B0A0B8[];

void **func_01B067F8(void *a0, int a1);
void func_01B01CA8(void *a0, void *a1);
void func_01B066D8(void *a0, void *a1);
void func_01B06268(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B05138(int a0, void *a1, void *a2);
void *func_01B05F08(void *a0);
void func_01B060D0(void *a0);
void func_01B02D70(void);

void func_01B02D90(void)
{
    u8 *s1 = D_01B0A1E0;
    void *s4;
    u8 *s0;
    u8 *s3;
    u8 *s5;
    float ang;
    void *t;
    int i;

    s4 = *func_01B067F8(D_01B0A0B8, 8);
    s0 = s1 + 0xE80;
    for (i = 0; i < 4; i++) {
        func_01B01CA8(s0, s4);
        *(int *)(s0 + 0x828) = 0x96;
        *(float *)(s0 + 0x820) = 2.0f;
        s0[0x813] = 0x18;
        s0 += 0x8B0;
    }
    *(int *)(s1 + 0x3154) = 1;
    func_01B066D8(D_01B0A0B8, s1 + 0x130);
    s3 = s1 + 0x720;
    func_01B06268(D_01B0A0B8, s3, 6, 0, 0, 0, 0.3f);
    {
        u8 *dst = s1 + 0x7F0;
        u8 *src = s1 + 0xA60;
        MMI_COPY_LQ_A3_M(src, dst);
        MMI_COPY_SQ_A3_M(dst);
    }
    *(float *)(s3 + 0xD4) += -850.0f;
    *(float *)(s3 + 0xC4) = *(float *)(s1 + 0x3148);
    *(float *)(s3 + 0x64) *= 1.5f;
    s5 = s1 + 0x850;
    func_01B06268(D_01B0A0B8, s5, 7, 0, 0, 0, 0.075f);
    {
        u8 *dst = s1 + 0x920;
        u8 *src = s1 + 0xA60;
        MMI_COPY_LQ_A3_M(src, dst);
        MMI_COPY_SQ_A3_M(dst);
    }
    *(float *)(s5 + 0xD4) += -1070.0f;
    *(float *)(s5 + 0xC4) = *(float *)(s1 + 0x3148);
    *(float *)(s1 + 0xA54) = *(float *)(s1 + 0xA64) - 1100.0f;
    ang = *(float *)(s1 + 0x3148) + 2.8274333f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s1 + 0xA44) = ang;
    func_01B05138(-1, s1 + 0x980, s1 + 0xA40);
    *(float *)(s1 + 0x9C0) = 2.0f;
    *(float *)(s1 + 0x9C4) = 2.0f;
    *(float *)(s1 + 0x9C8) = 2.0f;
    *(float *)(s1 + 0x9CC) = 1.0f;
    *(float *)(s1 + 0x9D0) = 0.0f;
    *(float *)(s1 + 0x9D4) = 0.0f;
    *(float *)(s1 + 0x9D8) = 0.0f;
    *(float *)(s1 + 0x9DC) = 1.0f;
    *(float *)(s1 + 0x9E0) = 0.0f;
    *(float *)(s1 + 0x9E4) = 0.0f;
    *(float *)(s1 + 0x9E8) = 0.0f;
    *(float *)(s1 + 0x9EC) = 1.0f;
    *(float *)(s1 + 0x9F0) = 0.0f;
    *(float *)(s1 + 0x9F4) = 0.0f;
    *(float *)(s1 + 0x9F8) = 0.0f;
    *(float *)(s1 + 0x9FC) = 1.0f;
    *(float *)(s1 + 0xA00) = 0.0f;
    *(float *)(s1 + 0xA04) = 0.0f;
    *(float *)(s1 + 0xA08) = -20.0f;
    *(float *)(s1 + 0xA0C) = 20.0f;
    *(float *)(s1 + 0xA10) = 0.0f;
    *(float *)(s1 + 0xA14) = 0.0f;
    *(float *)(s1 + 0xA18) = 0.0f;
    *(float *)(s1 + 0xA1C) = 1.0f;
    *(float *)(s1 + 0xA20) = 0.0f;
    *(float *)(s1 + 0xA24) = 0.0f;
    *(float *)(s1 + 0xA28) = 0.0f;
    *(float *)(s1 + 0xA2C) = 1.0f;
    *(float *)(s1 + 0xA30) = 0.0f;
    *(float *)(s1 + 0xA34) = 0.0f;
    *(float *)(s1 + 0xA38) = 0.0f;
    *(float *)(s1 + 0xA3C) = 1.0f;
    *(int *)(s1 + 0x314C) = 1;
    *(int *)(s1 + 0x3150) = 100;
    t = func_01B05F08((void *)func_01B02D70);
    *(void **)(s1 + 0x3144) = t;
    func_01B060D0(t);
}
