#include "common.h"

extern void g_fn_7c70(void *, void *);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern float g_fn_4a18(void);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DCE38(void *, void *, void *);

void func_01B05028(u8 *a0)
{
    u8 m0[0x40];
    u8 m1[0x40];
    float v[4];
    u8 *p80 = a0 + 0x80;
    float s;

    g_fn_7c70(m0, m1);
    func_002DCF48(p80, m1);
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 5.0f;
    v[3] = 1.0f;
    func_002DCE08(a0 + 0xD0, p80, v);
    *(float *)(a0 + 0xDC) = 1.0f;
    func_002DD128(m1);
    func_002DD1C8(m1, m1, 0.8796459436416626f);
    func_002DCE38(p80, p80, m1);
    s = g_fn_4a18() * 0.0018f;
    *(float *)(a0 + 0x6C) = s;
    *(float *)(a0 + 0x68) = s;
    *(float *)(a0 + 0x64) = s;
    *(float *)(a0 + 0x60) = s;
}
