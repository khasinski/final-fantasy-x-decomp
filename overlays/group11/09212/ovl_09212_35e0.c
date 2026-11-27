#include "common.h"
#include "vu0.h"

extern u8 *D_01B0A8E8;
extern u8 D_01B0A7A0[];

void func_00118098(int a0, int a1);
void func_01B06928(void *a0, void *a1);
void func_01B072F0(void *a0, void *a1, void *a2);
void func_01B05388(int a0, void *a1, void *a2);
void func_01B064B8(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B09CD8(void *a0, int a1);
void func_01B09DE0(void *a0, int a1);
void func_01B05A08(int a0);

void func_01B035E0(void)
{
    float rot[4];
    float ofs[4];
    u8 *s0;
    u8 *s2;
    u8 *s3;
    u8 *v0;
    u8 *q;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    s0 = D_01B0A8E8;
    s2 = s0 + 0x260;
    s3 = s0 + 0xAC0;
    func_01B06928(D_01B0A7A0, s0 + 0x720);
    func_01B06928(D_01B0A7A0, s0 + 0x850);
    rot[0] = 0.0f;
    rot[1] = *(float *)(s0 + 0x31C8);
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    ofs[0] = 0.0f;
    ofs[1] = 0.0f;
    ofs[2] = -50.0f;
    ofs[3] = 1.0f;
    func_01B072F0(rot, s0 + 0xA90, ofs);
    *(float *)(s0 + 0xAA4) = *(float *)(s0 + 0x31C8);
    *(float *)(s0 + 0xAB4) = *(float *)(s0 + 0xAC4);
    func_01B05388(-1, s0 + 0x9C0, s0 + 0xAA0);
    func_01B064B8(D_01B0A7A0, s2, 2, 0x15, 0, 0, 0.15f);
    {
        register u8 *dst __asm__("$3") = s0 + 0x330;
        MMI_COPY_LQ_A3(dst, s3);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s2 + 0xC4) = *(float *)(s0 + 0x31C8);
    *(float *)(s2 + 0xD4) = *(float *)(s0 + 0xAB4) - 120.0f;
    func_01B064B8(D_01B0A7A0, s0, 0, 0x3A, 0, 0, 0.22500001f);
    {
        register u8 *dst __asm__("$3") = s0 + 0xD0;
        MMI_COPY_LQ_A3(dst, s3);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s0 + 0xC4) = *(float *)(s0 + 0x31C8);
    *(float *)(s0 + 0xD4) -= 1.0f;
    v0 = s0 + 0xC5C;
    *(int *)(v0 + 0x00) = 0;
    *(int *)(v0 + 0x04) = 0x28;
    *(int *)(v0 + 0x0C) = 0x28;
    *(int *)(v0 + 0x08) = 0;
    func_01B09CD8(v0, 0x96);
    q = s0 + 0xC78;
    func_01B09DE0(q, 0x1E);
    *(float *)(q + 0x04) = 1.0f;
    *(float *)(q + 0x08) = 1.0f;
    *(float *)(q + 0x10) = 4.0f;
    *(float *)(q + 0x14) = 2.0f;
    *(int *)(q + 0x24) = 0x3A;
    *(float *)(q + 0x0C) = 0.0f;
    *(float *)(q + 0x18) = 0.0f;
    *(u16 *)(q + 0x2C) |= 3;
    func_01B05A08(1);
}
