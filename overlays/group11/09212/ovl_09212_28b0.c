#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 *D_01B0A8E8;
extern u8 D_01B0A7A0[];

float func_002B3DB0(float a0);
void func_01B05388(int a0, void *a1, void *a2);
void func_002DD128(void *a0);
void func_002DD318(void *a0, void *a1, float a2);
void func_002DCE38(void *a0, void *a1, void *a2);
void func_01B064B8(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B06928(void *a0, void *a1);
void **func_01B06A48(void *a0, int a1);
void func_01B01DC8(void *a0, void *a1);
void func_01B04D18(int a0, int a1, float f0, float f1, float f2);
void func_01B09CD8(void *a0, int a1);

void func_01B028B0(void)
{
    float m[4][4];
    u8 *s0 = D_01B0A8E8;
    u8 *s1 = s0 + 0x9C0;
    u8 *v0;
    float *p;
    float ang;
    int h;

    *(float *)(s0 + 0xAF0) -= *(float *)(s0 + 0xAE0);
    *(float *)(s0 + 0xAF8) -= *(float *)(s0 + 0xAE8);
    *(float *)(s0 + 0xAB0) = *(float *)(s0 + 0xAF0) + func_002B3DB0(0.1f);
    *(float *)(s0 + 0xAB8) = *(float *)(s0 + 0xAF8) + func_002B3DB0(0.1f);
    func_01B05388(-1, s1, s0 + 0xAA0);
    p = (float *)(s0 + 0xAE4);
    {
        float step = 0.062831856f;
        ang = *(float *)(s0 + 0xAE4) + step;
    }
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *p = ang;
    func_002DD128(m);
    func_002DD318(m, m, *(float *)(s0 + 0xAE4));
    func_002DCE38(s1, s1, m);
    v0 = s0 + 0x5F0;
    *(float *)(v0 + 0xD0) -= *(float *)(s0 + 0xAF4);
    *(float *)(v0 + 0xD8) -= *(float *)(s0 + 0xAFC);
    h = *(u16 *)(v0 + 0x74) - 0x11;
    *(u16 *)(v0 + 0x74) = h;
    *(u16 *)(v0 + 0x72) = h;
    *(u16 *)(v0 + 0x70) = h;
}

void func_01B02A20(void)
{
    u8 *s0 = D_01B0A8E8;
    u8 *s1 = s0 + 0x4C0;

    func_01B064B8(D_01B0A7A0, s1, 4, 0, 0, 0, 0.8f);
    {
        register u8 *dst __asm__("$3") = s0 + 0x590;
        register u8 *src __asm__("$2") = s0 + 0xAC0;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x31C8);
}

void func_01B02A98(void)
{
    u8 *s3 = D_01B0A8E8;
    u8 *s1 = s3 + 0x390;
    u8 *s2 = s3 + 0xAC0;
    void *tex;
    u8 *s0;
    u8 *s4;
    int i;

    func_01B06928(D_01B0A7A0, s3 + 0x5F0);
    func_01B064B8(D_01B0A7A0, s1, 3, 0, 0, 0, 0.8f);
    {
        register u8 *dst __asm__("$3") = s3 + 0x460;
        MMI_COPY_LQ_A3(dst, s2);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s1 + 0xC4) = *(float *)(s3 + 0x31C8);
    *(float *)(s3 + 0xAA0) = 0.0f;
    *(float *)(s3 + 0xAA8) = 0.0f;
    *(float *)(s3 + 0xAE4) = 15.0f;
    *(float *)(s3 + 0xAF4) = 0.75f;
    *(float *)(s3 + 0xAA4) = *(float *)(s3 + 0x31C8);
    func_01B05388(-1, s3 + 0x9C0, s3 + 0xAA0);
    {
        register u8 *dst __asm__("$2") = s3 + 0xAB0;
        MMI_COPY_LQ_A3_V0(s2, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    *(float *)(s3 + 0xAB4) += 100.0f;
    tex = *func_01B06A48(D_01B0A7A0, 8);
    s0 = s3 + 0xF00;
    for (i = 0; i < 4; i++) {
        func_01B01DC8(s0, tex);
        *(int *)(s0 + 0x828) = 0x96;
        *(float *)(s0 + 0x820) = 4.0f;
        s0[0x813] = 0x18;
        s0 += 0x8B0;
    }
    s4 = s3 + 0xC40;
    func_01B04D18(-1, 1, 1.0f, 1.0f, 1.0f);
    *(float *)(s3 + 0xC40) = 0.0f;
    *(int *)(s4 + 0x04) = 0x50;
    *(int *)(s4 + 0x08) = 0;
    *(int *)(s4 + 0x0C) = 0;
    func_01B09CD8(s4, 0x2D);
}

void func_01B02C30(void)
{
    u8 *v1 = D_01B0A8E8;
    *(float *)(v1 + 0xAB4) -= 15.0f;
}

void func_01B02C50(void)
{
    u8 *v1 = D_01B0A8E8;
    float f = *(float *)(v1 + 0xAE4) - *(float *)(v1 + 0xAF4);

    *(float *)(v1 + 0xAE4) = f;
    *(float *)(v1 + 0xAB4) -= f;
}
