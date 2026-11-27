#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 *D_01B0A1E0;
extern u8 D_01B0A0B8[];

int func_01B066D8(void *a0, void *a1);
void func_01B06268(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B04B28(int a0, int a1, float f0);

void func_01B02A78(u8 *a0)
{
    u8 *s1 = D_01B0A1E0;
    int cnt = *(int *)(a0 + 0x2C);

    cnt--;
    if (cnt == 0) {
        func_01B066D8(D_01B0A0B8, s1 + 0x390);
        func_01B066D8(D_01B0A0B8, s1 + 0x4C0);
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

void func_01B02B28(void)
{
    u8 *s1 = D_01B0A1E0;
    u8 *s0 = s1 + 0x130;
    float ang;

    func_01B06268(D_01B0A0B8, s0, 1, 0, 0, 0, 0.25f);
    {
        register u8 *dst __asm__("$3") = s1 + 0x200;
        register u8 *src __asm__("$2") = s1 + 0xA60;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
        *(float *)(s0 + 0xC4) = *(float *)(s1 + 0x3148);
        *(float *)(s0 + 0xD4) -= 200.0f;
        {
            register u8 *dst2 __asm__("$2") = s1 + 0xA50;
            MMI_COPY_LQ_A3_V0(dst, dst2);
            MMI_COPY_SQ_A3_V1(dst2);
        }
    }
    *(float *)(s1 + 0xA54) -= 260.0f;
    func_01B04B28(-1, 1, 0.0f);
    ang = *(float *)(s1 + 0x3148) + 0.62831855f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s1 + 0xA44) = ang;
    *(float *)(s1 + 0xA84) = 0.15707964f;
    *(float *)(s1 + 0xA94) = 0.0031415927f;
    *(int *)(s1 + 0x3154) = 1;
}
