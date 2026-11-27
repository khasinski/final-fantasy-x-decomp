#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x1BB0];
    u8 f1BB0[0x40];
    float f1BF0;
    u8 pad1BF4[0xC];
    float f1C00[4];
    u8 pad1C10[0x20];
    float f1C30[4];
    float f1C40[4];
    u8 pad1C50[0x2D0];
    int w1F20;
} ObjA310;

extern ObjA310 *D_01B0A310;
extern void func_01B04FD8(int, void *, float *);

void func_01B02658(void)
{
    ObjA310 *t0 = D_01B0A310;
    float f1;
    float f2;
    float tmp[4];
    int i;
    float *p0;
    float *p1;
    float *dst;
    float ang;

    if (t0->w1F20 > 0) {
        t0->w1F20--;
        f1 = (float)t0->w1F20 / 45.0f;
    } else {
        f1 = 1.0f;
    }
    f2 = 1.0f - f1;
    {
        register float *c00 __asm__("$9") = t0->f1C00;
        float *pbf0 = &t0->f1BF0;
        for (i = 0; i < 3; i++) {
            tmp[i] = t0->f1C40[i] * f2 + t0->f1C30[i] * f1;
        }
        tmp[3] = 1.0f;
        copy_vec(c00, tmp);

        ang = t0->f1BF0 + 0.9424778819084167f;
        if (ang > 3.1415927410125732f) {
            ang -= 6.2831854820251465f;
        } else if (ang < -3.1415927410125732f) {
            ang += 6.2831854820251465f;
        }
        *pbf0 = ang;
        func_01B04FD8(1, t0->f1BB0, pbf0);
    }
}
