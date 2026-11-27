#include "common.h"

extern void (*D_01B19C80)(void *, void *);
extern float D_01B00738;

extern void func_002DD0B0(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DCE08(void *, void *, void *);

typedef struct {
    u8 *obj;
    float *out;
} ArgF1C0;

void func_01B1F1C0(ArgF1C0 *a0)
{
    float m[16];
    float v[4];
    u8 *s0 = a0->obj;

    v[1] = 10.0f;
    v[0] = 5.0f;
    v[3] = 1.0f;
    v[2] = 0.0f;
    D_01B19C80(m, s0 + 0x50);
    func_002DD0B0(&m[12], s0 + 0x30);
    func_002DCE38(m, *(u8 **)(s0 + 0x70) + 0xA0, m);
    func_002DCE08(a0->out, m, v);
    a0->out[1] = D_01B00738;
}
