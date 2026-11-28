#include "common.h"

extern u8 *D_01B0AB88;
extern void func_01B02A60(void);
extern void func_01B02A90(void);
extern void func_01B02AC0(void);
extern void func_01B02D98(void);
extern void func_01B09960(void *, s32);
extern void func_01B09A68(void *, s32);

void func_01B031A0(void) {
    u8 *base = D_01B0AB88;
    void **arr1 = (void **)(base + 0x980);
    u8 *p1 = base + 0xAC0;
    u8 *s390 = base + 0x390;
    void **arr2 = (void **)(base + 0xA40);
    u8 *p2 = base + 0xFA0;
    u8 *s5f0 = base + 0x5F0;
    s32 *s2 = (s32 *)(base + 0x1590);
    u8 *s1 = base + 0x15C8;
    u8 *p;
    s32 i;

    for (i = 0x2F; i >= 0; i--) {
        arr1[i] = 0;
    }
    for (i = 0x16; i < 0x30; i++) {
        arr1[i] = func_01B02A60;
    }
    p = p1;
    for (i = 0; i < 0x1A; i++, p += 0x30) {
        *(s32 *)(p + 0x28) = 0;
    }
    *(void **)(s390 + 0x10C) = arr1;

    for (i = 0x1E; i >= 0; i--) {
        arr2[i] = 0;
    }
    for (i = 4; i < 0x1F; i++) {
        arr2[i] = func_01B02A90;
    }
    p = p2;
    for (i = 0; i < 0x1B; i++, p += 0x30) {
        *(s32 *)(p + 0x28) = 0;
    }
    *(void **)(s5f0 + 0x10C) = arr2;

    func_01B02AC0();
    func_01B02D98();

    *(s32 *)(base + 0x1590) = 0;
    s2[1] = 0x64;
    s2[2] = 0x28;
    s2[3] = 0;
    func_01B09960(s2, 0x50);

    func_01B09A68(s1, 0x28);
    {
        register float f4 __asm__("$f0") = 4.0f;
        register float f2 __asm__("$f1") = 2.0f;
        register u32 fl __asm__("$2") = *(volatile u16 *)(s1 + 0x2C);
        __asm__("" : "+f"(f4), "+f"(f2), "+r"(fl));
        *(volatile u16 *)(s1 + 0x2C) = fl | 3;
        *(volatile float *)(s1 + 0x10) = f4;
        *(volatile float *)(s1 + 0x14) = f2;
        *(volatile float *)(s1 + 4) = f4;
        *(volatile float *)(s1 + 8) = f2;
    }
    *(volatile float *)(s1 + 0xC) = 0.0f;
    *(volatile float *)(s1 + 0x18) = 0.0f;
    __asm__ volatile("" : : : "memory");
}
