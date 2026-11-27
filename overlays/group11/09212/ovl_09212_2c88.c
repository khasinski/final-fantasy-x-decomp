#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 *D_01B0A8E8;
extern u8 D_01B0A7A0[];

int func_01B06928(void *a0, void *a1);
void func_01B064B8(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B04D78(int a0, int a1, float f0);
void func_01B05388(int a0, void *a1, void *a2);

void func_01B02C88(u8 *a0)
{
    u8 *s1 = D_01B0A8E8;
    int cnt = *(int *)(a0 + 0x2C);

    cnt--;
    if (cnt == 0) {
        func_01B06928(D_01B0A7A0, s1 + 0x390);
        func_01B06928(D_01B0A7A0, s1 + 0x4C0);
        a0[0x56] = 1;
    } else {
        int d = 10;
        int val;
        u8 *v1;

        *(int *)(a0 + 0x2C) = cnt;
        val = (cnt << 12) / d;
        v1 = s1 + 0x390;
        *(u16 *)(v1 + 0x74) = val;
        *(u16 *)(v1 + 0x72) = val;
        *(u16 *)(v1 + 0x70) = val;
        v1 = s1 + 0x4C0;
        *(u16 *)(v1 + 0x74) = val;
        *(u16 *)(v1 + 0x72) = val;
        *(u16 *)(v1 + 0x70) = val;
    }
}

void func_01B02D38(void)
{
    u8 *s1 = D_01B0A8E8;
    u8 *s0 = s1 + 0x130;
    float ang;

    func_01B064B8(D_01B0A7A0, s0, 1, 0, 0, 0, 0.25f);
    {
        register u8 *dst __asm__("$3") = s1 + 0x200;
        register u8 *src __asm__("$2") = s1 + 0xAC0;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
        *(float *)(s0 + 0xC4) = *(float *)(s1 + 0x31C8);
        *(float *)(s0 + 0xD4) -= 200.0f;
        {
            register u8 *dst2 __asm__("$2") = s1 + 0xAB0;
            MMI_COPY_LQ_A3_V0(dst, dst2);
            MMI_COPY_SQ_A3_V1(dst2);
        }
    }
    *(float *)(s1 + 0xAB4) -= 260.0f;
    func_01B04D78(-1, 1, 0.0f);
    ang = *(float *)(s1 + 0x31C8) + 0.62831855f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s1 + 0xAA4) = ang;
    *(float *)(s1 + 0xAE4) = 0.15707964f;
    *(float *)(s1 + 0xAF4) = 0.0031415927f;
    *(int *)(s1 + 0x31D4) = 1;
}

void func_01B02E80(void)
{
    func_01B04D78(-1, 10, 1.0f);
}

void func_01B02E98(void)
{
    u8 *s0 = D_01B0A8E8;
    float *p;
    float vel;
    float ang;
    u8 *v1;
    int i;

    p = (float *)(s0 + 0xAA4);
    vel = *(float *)(s0 + 0xAE4) - *(float *)(s0 + 0xAF4);
    *(float *)(s0 + 0xAE4) = vel;
    ang = *p + vel;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *p = ang;
    func_01B05388(-1, s0 + 0x9C0, s0 + 0xAA0);
    *(float *)(s0 + 0xAB4) += 15.0f;
    v1 = s0 + 0xF00;
    for (i = 3; i >= 0; i--) {
        if (v1[0x813] < 0x18) {
            v1[0x813]++;
        }
        v1 += 0x8B0;
    }
}
