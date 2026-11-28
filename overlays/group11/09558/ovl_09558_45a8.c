#include "common.h"

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Msg45A8;

extern void *D_01B007A8;
extern void *D_01B007BC;
extern u8 D_01B007C8;
extern u8 D_01B00970[];
extern u8 D_01B00B80[];
extern u8 D_01B00B98[];
extern u8 D_01B00BB8[];
extern u8 D_01B110D0[];
extern void *D_01B110FC;

extern float func_001B6410(u32);
extern void func_01B04488(void *);
extern void func_01B0FBF0(void *);
extern void func_01B0FFF8(void *);
extern void func_01B0B2C0(void *);
extern void func_01B07590(void *);
extern float func_001ACED8(void);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD020(void *, void *, void *);
extern void func_01B0CAE0(void *);
extern void func_01B0EC40(void *);
extern s32 func_001C5E90(void *, u32, s32);
extern void *func_002B49A0(void *, s32, s32);
extern void func_0014D3F0(s32, s32, void *);

void func_01B045A8(u8 *s6, u8 *s8, void *s7, void *a3) {
    float vec[4];
    void *a10[4];
    Msg45A8 a20;
    float f24;

    f24 = func_001B6410(D_01B007C8);
    if (f24 > 20.0f) {
        f24 = 20.0f;
    }
    f24 *= 0.1f;

    {
        void **p = a10;
        *(volatile void **)&p[1] = (void *)func_01B04488;
        a10[0] = s6;
        a10[2] = s6;
        func_01B0FBF0(p);
    }
    {
        void **p = a10;
        a10[1] = s6;
        a10[0] = D_01B00B80;
        func_01B0FFF8(p);
    }
    {
        void **p = a10;
        a10[0] = s6 + 0x180;
        *(volatile void **)&p[1] = D_01B00B98;
        func_01B0B2C0(p);
    }
    {
        void **p = a10;
        a10[0] = s7;
        a10[1] = s6 + 0x1A0;
        func_01B07590(p);
    }

    vec[0] = f24 * ((func_001ACED8() - 0.99f) * 14.0f + -7.0f);
    vec[1] = f24 * ((func_001ACED8() - 0.99f) * 14.0f + -7.0f);
    vec[2] = f24 * ((func_001ACED8() - 0.99f) * 5.0f + 4.0f);
    vec[3] = 0.0f;
    func_002DCE08(vec, s8 + 0xE0, vec);
    func_002DD020(s6 + 0x1A0, s6 + 0x1A0, vec);
    *(float *)(s6 + 0x1AC) = 1.0f;

    {
        void **p = a10;
        a10[0] = s6 + 0x1B0;
        *(volatile void **)&p[1] = D_01B00B98;
        func_01B0B2C0(p);
    }

    *(float *)(s6 + 0x1D0) = 1.0f;
    *(float *)(s6 + 0x1D4) = 1.0f;
    *(float *)(s6 + 0x1D8) = 1.0f;
    {
        float f0 = (func_001ACED8() - 0.99f) + 0.5f;
        Msg45A8 *p = &a20;
        *(volatile void **)&a20.p0 = s6 + 0x20;
        *(volatile void **)&p->p4 = D_01B00B98;
        *(volatile void **)&p->p8 = D_01B00970;
        a20.pC = s6 + 0x180;
        *(volatile float *)(s6 + 0x1DC) = f0;
        a20.p14 = s6 + 0x1B0;
        a20.p10 = a3;
        func_01B0CAE0(p);
    }

    {
        void **p = a10;
        a10[0] = s6 + 0x1E0;
        *(volatile void **)&p[1] = D_01B00BB8;
        a10[2] = s6 + 0x20;
        a10[3] = D_01B110FC;
        *(volatile void **)&p[4] = D_01B110D0;
        *(volatile void **)&p[5] = (void *)2;
        func_01B0EC40(p);
    }

    func_001C5E90(D_01B007BC, D_01B007C8, 0);
    func_0014D3F0(7, 1, func_002B49A0(D_01B007A8, 5, 0));

    *(void **)(s6 + 0x170) = s8;
    *(s32 *)(s6 + 0x18) = 0;
}
