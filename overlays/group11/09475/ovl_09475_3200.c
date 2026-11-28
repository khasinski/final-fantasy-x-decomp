#include "common.h"
#include "vu0.h"

extern u8 *D_01B0A068;
extern u8 D_01B09F20[];
extern u8 D_01B0FCB0[];
extern u8 D_01B004F0[];

extern void func_01B05FE8(void *);
extern void func_01B046E0(s32, s32);
extern void func_01B03EF8(s32, float (*)[4]);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern float func_002B3DF8(float);
extern void func_01B062C8(void *, void *, s32, s32, s32, void *, float);
extern void func_002DCE08(void *, float (*)[4], float *);
extern void func_01B05A50(void *, void *, void *);
extern s32 func_002EFD78(void);
extern void func_01B04D08(s32, s32);
extern void *func_01B05F68(void (*)(void));
extern void func_01B06130(void *);
extern void func_01B03110(void);
extern void func_01B02C60(void);

typedef struct {
    u8 pad00[0x20];
    float (*unk20)[4];
    float *unk24;
    float *unk28;
    float *unk2C;
} Item3200;

void func_01B03200(void) {
    float m0[4][4];
    float m1[4][4];
    float v[4];
    u8 *s3 = D_01B0A068;
    u8 *s0;
    Item3200 *s1;
    s32 s5;
    s32 i;
    void *t;

    if (*(void **)(s3 + 0xCC0) != 0) {
        func_01B05FE8(*(void **)(s3 + 0xCC0));
        *(void **)(s3 + 0xCC0) = 0;
    }
    func_01B046E0(1, 1);
    {
        register float f08 __asm__("$f22") = 0.8f;
        func_01B03EF8(0, m0);
        {
            register float f001 __asm__("$f21") = 0.01f;
            register float f5 __asm__("$f20") = 5.0f;
    s0 = s3 + 0x390;
    s1 = (Item3200 *)(s3 + 0xCD0);
    {
        s32 delay = 0;
        i = 0;
        {
        register u8 *pC80 __asm__("$22") = s3 + 0xC80;
        for (; i < 3; i++, s0 += 0x130, s1++) {
            func_002DCE38(m1, m0, s1->unk20);
            {
                register float *p0 __asm__("$4") = s1->unk24;
                register float *p1 __asm__("$2") = s1->unk28;
                __asm__ volatile("lqc2 $vf1, 0(%0)" : : "r"(p0) : "memory");
                __asm__ volatile("lqc2 $vf2, 0(%0)" : : "r"(p1) : "memory");
                VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
                VU0_SQC2(1, 0, v);
            }
            {
                register float *p2 __asm__("$3") = s1->unk2C;
                VU0_LQC2(1, 0, v);
                VU0_LQC2(2, 0, p2);
                VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
                VU0_SQC2(1, 0, v);
            }
            {
                s32 sc = 0x40400000;
                __asm__ volatile("lqc2 $vf1, 0(%0)" : : "r"(v), "r"(sc) : "memory");
                VU0_QMTC2(2, sc);
                VU0_OP("vdiv Q, $vf0w, $vf2x");
                VU0_OP("vwaitq");
                VU0_OP("vmulq.xyz $vf1, $vf1, Q");
                VU0_SQC2(1, 0, v);
            }

            func_01B062C8(D_01B09F20, s0, 2, delay, 0, 0, (func_002B3DF8(0.5f) + f08) * f001);
            *(float *)(s0 + 0xC4) = *(float *)(s3 + 0xD64);
            *(float *)(s0 + 0xE8) = f5;
            func_002DCE08(s0 + 0xD0, m1, v);
            *(float *)(s0 + 0xDC) = 1.0f;
            *(s32 *)(s0 + 0x120) = i;
            *(void **)(s0 + 0x104) = (void *)func_01B03110;
            if (i == 0) {
                func_01B05A50(pC80, D_01B0FCB0, D_01B004F0);
                *(void **)(s0 + 0x110) = pC80;
            }
            delay = func_002EFD78() % 5;
        }
        }
    }
        }
    }

    func_01B04D08(-5, 0);
    {
        register s32 c40 __asm__("$3") = 40;
        register s32 c20 __asm__("$2") = 20;
        *(s32 *)(s3 + 0xD6C) = c40;
        *(s32 *)(s3 + 0xD70) = c20;
    }
    t = func_01B05F68(func_01B02C60);
    *(void **)(s3 + 0xCC4) = t;
    func_01B06130(t);
}
