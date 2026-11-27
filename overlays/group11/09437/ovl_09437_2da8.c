#include "vu0.h"

extern u8 *D_01B0A5F0;
extern u8 D_01B0A508[];
extern u8 D_01B02D88[];

extern void func_01B06858(void *, void *);
extern s32 func_01B04408(s32);
extern void func_01B03AC8(s32, float *, s32);
extern void func_01B07220(float *, float *, float *);
extern void func_01B052B8(s32, void *, void *);
extern void func_01B04D38(s32, void *);
extern void func_01B063E8(void *, void *, float, s32, s32, s32, s32);
extern void func_01B07118(float *, void *, void *);

#define copy_vec(dst, src) do { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); } while (0)

void func_01B02DA8(void)
{
    float sp0[4];
    float sp10[4];
    float sp20[4];
    register u8 *s4 __asm__("$20") = D_01B0A5F0;
    register u8 *s3 __asm__("$19");
    register u8 *s2 __asm__("$18");
    register u8 *s0 __asm__("$16");

    func_01B06858(D_01B0A508, s4 + 0x5F0);
    if (func_01B04408(0) == 0) {
        func_01B03AC8(0, sp0, 6);
        sp0[1] -= 0.5f;
    } else {
        func_01B03AC8(0, sp0, 4);
    }

    s3 = s4 + 0x1C40;
    copy_vec(s3, sp0);
    __asm__ volatile("");
    sp0[1] = *(float *)(s4 + 0x1BA4);
    sp10[0] = 0.0f;
    sp10[1] = *(float *)(s4 + 0x1F10);
    sp10[2] = 0.0f;
    sp10[3] = 0.0f;
    sp20[0] = 0.0f;
    sp20[1] = -25.0f;
    sp20[2] = 80.0f;
    sp20[3] = 1.0f;
    func_01B07220(sp10, sp0, sp20);

    s2 = s4 + 0x1C30;
    copy_vec(s2, sp0);
    __asm__ volatile("");
    {
        float f = *(float *)(s4 + 0x1F10);
        s0 = s4 + 0x1BB0;
        *(u32 *)(s4 + 0x1BF0) = 0;
        *(u32 *)(s4 + 0x1BF8) = 0;
        *(u32 *)(s4 + 0x1BFC) = 0;
        *(float *)(s4 + 0x1BF4) = f;
        func_01B052B8(1, s0, s4 + 0x1BF0);
    }

    copy_vec(s4 + 0x1BE0, sp0);
    copy_vec(s4 + 0x1C00, sp0);
    {
        register u8 *a1 __asm__("$5") = s0;
        __asm__("" : "+r"(a1));
        func_01B04D38(1, a1);
    }

    s0 = s4 + 0x130;
    func_01B063E8(D_01B0A508, s0, 0.04f, 1, 0, 0, 0);
    func_01B07118(sp10, s2, s3);

    {
        register void *a0 __asm__("$4") = s4 + 0x1C50;
        *(float *)(s0 + 0xC0) = sp10[0];
        *(void **)(s0 + 0x104) = D_01B02D88;
        *(float *)(s0 + 0xC4) = sp10[1];
        copy_vec(a0, sp10);
    }

    {
        register s32 v1 __asm__("$3") = 12;
        register s32 v0 __asm__("$2") = 1;
        __asm__("" : "+r"(v1), "+r"(v0));
        *(volatile s32 *)(s4 + 0x1F28) = v0;
        *(volatile s32 *)(s4 + 0x1F24) = v1;
        __asm__ volatile("" : : : "memory");
    }
}
