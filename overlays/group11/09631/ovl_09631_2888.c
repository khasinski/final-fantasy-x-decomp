#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 *D_01B0A1E0;
extern u8 D_01B0A0B8[];

void func_01B066D8(void *a0, void *a1);
void func_01B06268(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B05138(int a0, void *a1, void *a2);
void **func_01B067F8(void *a0, int a1);
void func_01B01CA8(void *a0, void *a1);
void func_01B04AC8(int a0, int a1, float f0, float f1, float f2);
void func_01B09A88(void *a0, int a1);

void func_01B02888(void)
{
    u8 *s3 = D_01B0A1E0;
    u8 *s1 = s3 + 0x390;
    u8 *s2 = s3 + 0xA60;
    void *tex;
    u8 *s0;
    u8 *s4;
    int i;

    func_01B066D8(D_01B0A0B8, s3 + 0x5F0);
    func_01B06268(D_01B0A0B8, s1, 3, 0, 0, 0, 0.8f);
    {
        register u8 *dst __asm__("$3") = s3 + 0x460;
        MMI_COPY_LQ_A3(dst, s2);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s1 + 0xC4) = *(float *)(s3 + 0x3148);
    *(float *)(s3 + 0xA40) = 0.0f;
    *(float *)(s3 + 0xA48) = 0.0f;
    *(float *)(s3 + 0xA84) = 15.0f;
    *(float *)(s3 + 0xA94) = 0.75f;
    *(float *)(s3 + 0xA44) = *(float *)(s3 + 0x3148);
    func_01B05138(-1, s3 + 0x980, s3 + 0xA40);
    {
        register u8 *dst __asm__("$2") = s3 + 0xA50;
        MMI_COPY_LQ_A3_V0(s2, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    *(float *)(s3 + 0xA54) += 100.0f;
    tex = *func_01B067F8(D_01B0A0B8, 8);
    s0 = s3 + 0xE80;
    for (i = 0; i < 4; i++) {
        func_01B01CA8(s0, tex);
        *(int *)(s0 + 0x828) = 0x96;
        *(float *)(s0 + 0x820) = 4.0f;
        s0[0x813] = 0x18;
        s0 += 0x8B0;
    }
    s4 = s3 + 0xBE0;
    func_01B04AC8(-1, 1, 1.0f, 1.0f, 1.0f);
    *(float *)(s3 + 0xBE0) = 0.0f;
    *(int *)(s4 + 0x04) = 0x50;
    *(int *)(s4 + 0x08) = 0;
    *(int *)(s4 + 0x0C) = 0;
    func_01B09A88(s4, 0x2D);
}
