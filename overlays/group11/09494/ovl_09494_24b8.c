#include "common.h"

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void copy_vec_sp(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, %0" : "=m"(*(u_long128 *)dst) : : "memory");
}

typedef struct {
    u8 pad00[0x1BB0];
    u8 f1BB0[0x30];
    float f1BE0[4];
    float f1BF0[4];
    float f1C00[4];
    float f1C10[4];
    u8 pad1C20[0x10];
    float f1C30[4];
    float f1C40[4];
    u8 pad1C50[0x2C0];
    float f1F10;
    u8 pad1F14[0xC];
    int w1F20;
} ObjA310;

extern ObjA310 *D_01B0A310;
extern void func_01B06F40(float *, float *, float *);
extern void func_01B04FD8(int, void *, float *);
extern void func_01B04A58(int, void *);

void func_01B024B8(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    ObjA310 *s2 = D_01B0A310;
    float ang;

    copy_vec_sp(v0, s2->f1C10);
    v1[0] = 0.0f;
    ang = s2->f1F10 + 2.356194496154785f;
    if (ang > 3.1415927410125732f) {
        ang -= 6.2831854820251465f;
    } else if (ang < -3.1415927410125732f) {
        ang += 6.2831854820251465f;
    }
    v1[1] = ang;
    v1[2] = 0.0f;
    v1[3] = 0.0f;
    v2[0] = 0.0f;
    v2[1] = 20.0f;
    v2[2] = 100.0f;
    v2[3] = 1.0f;
    func_01B06F40(v1, v0, v2);
    copy_vec(s2->f1C30, v0);
    copy_vec(s2->f1C40, s2->f1C10);
    v2[0] = 0.0f;
    v2[1] = -20.0f;
    v2[2] = -10.0f;
    v2[3] = 1.0f;
    func_01B06F40(v1, s2->f1C40, v2);
    s2->w1F20 = 45;
    s2->f1BF0[0] = 0.0f;
    s2->f1BF0[1] = v1[1];
    s2->f1BF0[2] = 0.0f;
    s2->f1BF0[3] = 0.0f;
    func_01B04FD8(1, s2->f1BB0, s2->f1BF0);
    copy_vec(s2->f1BE0, v0);
    copy_vec(s2->f1C00, v0);
    func_01B04A58(1, s2->f1BB0);
}
