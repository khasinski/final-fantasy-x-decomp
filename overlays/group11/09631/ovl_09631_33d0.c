#include "common.h"
#include "vu0.h"

extern u8 *D_01B0A1E0;
extern u8 D_01B0A0B8[];

void func_00118098(int a0, int a1);
void func_01B066D8(void *a0, void *a1);
void func_01B05138(int a0, void *a1, void *a2);
void func_01B06268(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B09A88(void *a0, int a1);
void func_01B09B90(void *a0, int a1);
void func_01B057B8(int a0);

void func_01B033D0(void)
{
    u8 *s0;
    u8 *s2;
    u8 *s3;
    u8 *v0;
    u8 *q;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    s0 = D_01B0A1E0;
    s2 = s0 + 0x260;
    s3 = s0 + 0xA60;
    func_01B066D8(D_01B0A0B8, s0 + 0x720);
    func_01B066D8(D_01B0A0B8, s0 + 0x850);
    *(float *)(s0 + 0xA44) = *(float *)(s0 + 0x3148);
    *(float *)(s0 + 0xA54) = *(float *)(s0 + 0xA64);
    func_01B05138(-1, s0 + 0x980, s0 + 0xA40);
    func_01B06268(D_01B0A0B8, s2, 2, 0x15, 0, 0, 0.15f);
    {
        register u8 *dst __asm__("$3") = s0 + 0x330;
        MMI_COPY_LQ_A3(dst, s3);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s2 + 0xC4) = *(float *)(s0 + 0x3148);
    *(float *)(s2 + 0xD4) = *(float *)(s0 + 0xA54) - 120.0f;
    func_01B06268(D_01B0A0B8, s0, 0, 0x3A, 0, 0, 0.22500001f);
    {
        register u8 *dst __asm__("$3") = s0 + 0xD0;
        MMI_COPY_LQ_A3(dst, s3);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s0 + 0xC4) = *(float *)(s0 + 0x3148);
    *(float *)(s0 + 0xD4) -= 1.0f;
    v0 = s0 + 0xBFC;
    *(int *)(v0 + 0x00) = 0;
    *(int *)(v0 + 0x04) = 0x28;
    *(int *)(v0 + 0x0C) = 0x28;
    *(int *)(v0 + 0x08) = 0;
    func_01B09A88(v0, 0x96);
    q = s0 + 0xC18;
    func_01B09B90(q, 0x1E);
    *(float *)(q + 0x04) = 1.0f;
    *(float *)(q + 0x08) = 1.0f;
    *(float *)(q + 0x10) = 4.0f;
    *(float *)(q + 0x14) = 2.0f;
    *(int *)(q + 0x24) = 0x3A;
    *(float *)(q + 0x0C) = 0.0f;
    *(float *)(q + 0x18) = 0.0f;
    *(u16 *)(q + 0x2C) |= 3;
    func_01B057B8(1);
}
