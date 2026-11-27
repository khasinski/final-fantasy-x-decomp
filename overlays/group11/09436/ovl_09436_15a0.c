#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 D_01B09290[];
extern u8 D_01B09338[];
extern u8 D_01B00898[];
extern u8 *D_01B09358;

int func_01B02A70(int a0);
int func_00297C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_01B05548(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B04418(int a0, void *a1, void *a2);
void func_01B03E98(int a0, void *a1);
void func_01B04610(int a0, void *a1, void *a2);

void func_01B015A0(void)
{
    u8 *s0 = D_01B09358;

    *(int *)(s0 + 0x54BC) = func_00297C28(func_01B02A70(-1), 0, 0, 0, 0, 0, 0);
}

void func_01B015F0(void)
{
    u8 *s0 = D_01B09358;
    u8 *s1 = s0 + 0x850;
    u8 *s2 = s0 + 0xF70;
    u8 *s3;

    func_01B05548(D_01B09290, s1, 7, 0, 0, 0, 0.15f);
    {
        register u8 *dst __asm__("$3") = s0 + 0x920;
        MMI_COPY_LQ_A3_V0(s2, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    s3 = s0 + 0xD10;
    *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x54A0);
    *(float *)(s1 + 0xD4) -= 0.5f;
    *(float *)(s0 + 0xF50) = 0.0f;
    *(float *)(s0 + 0xF54) = *(float *)(s0 + 0x54A0);
    *(float *)(s0 + 0xF58) = 0.0f;
    *(float *)(s0 + 0xF5C) = 0.0f;
    func_01B04418(-1, s3, s0 + 0xF50);
    {
        register u8 *dst __asm__("$2") = s0 + 0xD40;
        MMI_COPY_LQ_A3_V0(s2, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    {
        u8 *dst = s0 + 0xF60;
        MMI_COPY_LQ_A3_V0(s2, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    func_01B03E98(-1, s3);
}

void func_01B016D0(u8 *a0)
{
    u8 *s0 = D_01B09358;
    float t;
    float omt;

    if (*(int *)(s0 + 0x54A8) > 0) {
        *(int *)(s0 + 0x54A8) -= 1;
    }
    t = (float)*(int *)(s0 + 0x54A8) / (float)*(int *)(s0 + 0x54AC);
    omt = 1.0f - t;
    *(float *)(s0 + 0xF60) = *(float *)(s0 + 0xF80) * omt + *(float *)(s0 + 0xF70) * t;
    *(float *)(s0 + 0xF68) = *(float *)(s0 + 0xF88) * omt + *(float *)(s0 + 0xF78) * t;
    if (*(int *)(s0 + 0x54A8) == 8) {
        func_01B04610(-1, D_01B09338, D_01B00898);
    }
    if (*(int *)(s0 + 0x54A8) <= 0) {
        a0[0x56] = 1;
    }
}
