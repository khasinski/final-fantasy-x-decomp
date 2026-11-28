#include "common.h"
#include "vu0.h"

extern u8 D_01B0BB70[];
extern u8 *D_01B0BC98;

extern void func_01B061C0(s32, void *, void *);
extern s32 func_01B072F0(void *, void *, s32, s32, s32, s32, float);
extern void func_01B0AC18(void *, s32);
extern void func_01B0B6C8(void *, s32);
extern u8 *func_01B06F90(void *);
extern void func_01B07158(void *);
extern void func_01B02CE0(void);

void func_01B02F28(void) {
    u8 *s2 = D_01B0BC98;
    u8 *s0;
    u8 *s1;
    u8 *v0;
    float ang;

    *(s32 *)(s2 + 0x2B00) = 0;
    ang = *(float *)(s2 + 0x3BF4) - 0.5235988f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s2 + 0x2B04) = ang;
    *(s32 *)(s2 + 0x2B08) = 0;

    func_01B061C0(-1, s2 + 0x2AC0, s2 + 0x2B00);
    MMI_COPY_LQ_A3(s2 + 0x2B10, s2 + 0x2B50);
    MMI_COPY_SQ_A3(s2 + 0x2B10);

    s0 = s2 + 0x720;
    func_01B072F0(D_01B0BB70, s0, 6, 17, 0, 0, 0.12f);
    MMI_COPY_LQ_A3(s2 + 0x7F0, s2 + 0x2B50);
    MMI_COPY_SQ_A3(s2 + 0x7F0);
    *(float *)(s0 + 0xC4) = *(float *)(s2 + 0x2B04);
    *(float *)(s0 + 0xD4) -= 1.0f;
    *(float *)(s0 + 0xE0) = 10.0f;
    *(float *)(s0 + 0xE8) = 30.0f;

    s1 = s2 + 0x3804;
    func_01B0AC18(s1, 0x10);
    *(float *)(s1 + 0x4) = 2.0f;
    *(float *)(s1 + 0x8) = 1.0f;
    *(s32 *)(s1 + 0xC) = 0;
    *(volatile u16 *)(s1 + 0x2C) |= 3;
    *(float *)(s1 + 0x10) = 2.0f;
    *(float *)(s1 + 0x14) = 1.0f;
    *(s32 *)(s1 + 0x18) = 0;
    *(s32 *)(s1 + 0x24) = 15;

    s1 += 0x30;
    func_01B0AC18(s1, 0x65);
    {
        register u16 t __asm__("$3") = *(u16 *)(s1 + 0x2C);
        u8 *v0 = s2 + 0x3900;
        *(volatile u16 *)(s1 + 0x2C) = t | 3;
        *(volatile float *)(s1 + 0x18) = 1.0f;
        *(volatile float *)(s1 + 0xC) = 1.0f;
        *(volatile float *)(s1 + 0x10) = 1.5f;
        *(volatile float *)(s1 + 0x4) = 1.5f;
        *(volatile s32 *)(s1 + 0x8) = 0;
        *(volatile s32 *)(s1 + 0x14) = 0;
        *(volatile s32 *)(s1 + 0x24) = 0x7C;
        {
            register u8 a2 __asm__("$6") = 0x80;
            register u8 a3 __asm__("$7") = 0x40;
            register u16 v1 __asm__("$3") = 4;
            v0[0xF0] = a2;
            v0[0xF1] = a2;
            v0[0xF2] = a2;
            v0[0xF3] = a3;
            *(u16 *)(v0 + 0x124) = v1;
            *(s32 *)(v0 + 0x110) = 0x7C;
            *(float *)(v0 + 0xFC) = 0.05f;
            *(s32 *)(v0 + 0x120) = 0;
            *(s32 *)(v0 + 0xF8) = 0;
            *(s32 *)(v0 + 0x100) = 0;
            func_01B0B6C8(v0, 0x50);
        }
    }

    v0 = func_01B06F90((void *)func_01B02CE0);
    *(u16 *)(v0 + 0x14) = 10;
    *(u16 *)(v0 + 0x16) = 46;
    func_01B07158(v0);
}
