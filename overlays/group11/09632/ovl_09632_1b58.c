#include "common.h"

static inline void copy_vec(float *src, float *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xAD0];
    float vecAD0[4];
    u8 padAE0[0x20];
    float vecB00[4];
    u8 padB10[0xC0];
    float vecBD0[4];
    float vecBE0[4];
    u8 padBF0[0x20];
    float vecC10[4];
    u8 padC20[0x1E0];
    float fE00;
    float fE04;
    float fE08;
    u8 padE0C[0x10];
    int wE1C;
} OvlState;

extern OvlState *D_01B096A0;
extern int D_01B09694;
extern int D_01B09674;

extern void func_01B02A10(int, float *, int);
extern float func_01B028E8(int);
extern void func_01B03C80(int, float *);
extern void func_01B04200(int, float *, float *);
extern void func_01B03778(int, int);
extern void func_01B036D8(int, int);

void func_01B01B58(void)
{
    float v0[4];
    float v1[4];
    register OvlState *s __asm__("$17") = D_01B096A0;

    func_01B02A10(-1, v0, 0);
    copy_vec(v0, s->vecC10);

    v1[0] = 0.0f;
    v1[1] = func_01B028E8(-1);
    __asm__("" : : "m"(v1[1]));
    {
        float *dst = s->vecBD0;
        float *p;
        __asm__("" : "+r"(dst));
        v1[2] = 0.0f;
        p = v1;
        __asm__("" : "+r"(p) : "m"(v1[2]));
        v1[3] = 0.0f;
        copy_vec(p, dst);
        copy_vec(v0, s->vecBE0);

        func_01B03C80(-1, s->vecAD0);
        func_01B04200(-1, s->vecAD0, p);
    }

    copy_vec(s->vecBE0, s->vecB00);

    func_01B03778(-1, 1);
    func_01B036D8(-1, 0);

    s->wE1C = 0;
    s->fE08 = v1[1];
    s->fE04 = 0.0f;
    s->fE00 = 0.0f;
    D_01B09674 = 1;
    D_01B09694 = 1;
}
