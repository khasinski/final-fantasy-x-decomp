#include "common.h"

extern void g_fn_7c70(void *, void *);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern float g_fn_4a18(void);

void func_01B04EB0(u8 *a0)
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
    s = g_fn_4a18() * 0.0018f;
    *(float *)(a0 + 0x6C) = s;
    *(float *)(a0 + 0x68) = s;
    *(float *)(a0 + 0x64) = s;
    *(float *)(a0 + 0x60) = s;
}
