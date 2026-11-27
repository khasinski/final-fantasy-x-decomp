#include "common.h"

extern u8 *D_01B0B1F8;
extern s32 D_01B008F0[];
extern u8 D_01B01D38[];

extern void func_01B04098(s32, float *, s32);
extern float func_01B044E8(s32);
extern float func_002B3DB0(float);
extern float func_01B07890(float *, float *);
extern void func_01B076E8(float *, float *, float *);
extern float func_01B03F70(s32);
extern void func_01B05308(s32, void *);
extern void func_01B051B8(s32, s32);
extern void *func_01B06658(void *);
extern void func_01B06820(void *);

void func_01B02198(void) {
    float sp0[4];
    float sp10[4];
    u8 *s4 = D_01B0B1F8;
    u8 *s0 = s4 + 0x1850;
    u8 *s7 = s0;
    s32 s6 = D_01B008F0[1];
    float fs0f = 0.0f;
    s32 i;
    void *obj;

    for (i = 0; i < s6; i++) {
        float dist;

        *(s32 *)(s0 + 0x14) = 1;
        func_01B04098(i, sp0, 0);
        func_01B044E8(i);
        *(float *)(s0 + 0x94) = sp0[1];
        func_002B3DB0(5.0f);
        *(float *)(s0 + 0x94) = func_002B3DB0(5.0f) + -130.0f + sp0[1];
        sp0[1] = *(float *)(s4 + 0x14A4);
        dist = func_01B07890(sp0, (float *)(s4 + 0x14A0));
        if (fs0f < dist) {
            fs0f = dist;
        }
        *(float *)(s0 + 0xB8) = dist;
        *(float *)(s0 + 0xBC) = dist;
        func_01B076E8(sp10, (float *)(s4 + 0x14A0), sp0);

        *(u32 *)(s0 + 0x60) = 0;
        *(u32 *)(s0 + 0x64) = 0;
        *(u32 *)(s0 + 0x68) = 0;
        *(u32 *)(s0 + 0x6C) = 0;
        *(u32 *)(s0 + 0x70) = 0;
        *(u32 *)(s0 + 0x74) = 0;
        *(u32 *)(s0 + 0x78) = 0;
        *(u32 *)(s0 + 0x7C) = 0;
        *(u32 *)(s0 + 0x80) = 0;
        *(float *)(s0 + 0xB0) = sp10[1];
        *(float *)(s0 + 0xB4) = 0.034906585f;

        {
            float f84 = func_01B03F70(i);
            float f75 = 0.75f;
            register s32 arg0 __asm__("$4") = i;
            register void *arg1 __asm__("$5");
            __asm__ volatile("" : "+f"(f75), "+r"(arg0));
            *(volatile s32 *)(s0 + 0xCC) = 1;
            arg1 = s0 + 0x20;
            __asm__ volatile("" : "+r"(arg1));
            *(volatile s32 *)(s0 + 0x88) = 0;
            *(volatile s32 *)(s0 + 0x8C) = 0;
            *(volatile s32 *)(s0 + 0xC0) = 0;
            *(volatile s32 *)(s0 + 0xC4) = 0;
            *(volatile s32 *)(s0 + 0xC8) = 1;
            *(s32 *)(s0 + 0xD0) = 0;
            *(float *)(s0 + 0x84) = f84;
            *(float *)(s0 + 0xA8) = *(float *)(s0 + 0xA4) = *(float *)(s0 + 0xA0) = f75;
            func_01B05308(arg0, arg1);
        }

        s0 += 0xE0;
        func_01B051B8(i, 0);
    }

    if (35.0f < fs0f) {
        s32 *p = D_01B008F0;
        s32 n;
        __asm__ volatile("" : "+r"(p));
        fs0f = 35.0f / fs0f;
        __asm__ volatile("" : "+f"(fs0f) : "r"(p));
        n = p[1];
        s0 = s7;
        for (i = 0; i < n; i++) {
            *(float *)(s0 + 0xBC) *= fs0f;
            s0 += 0xE0;
        }
    }

    obj = func_01B06658(D_01B01D38);
    func_01B06820(obj);
    *(void **)(s4 + 0x3170) = obj;
}
