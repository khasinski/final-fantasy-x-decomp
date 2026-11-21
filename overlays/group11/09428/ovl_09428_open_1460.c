#include "rcef_overlay.h"

#define VEC3_COPY(d, a) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(a) : "memory")

extern int D_01B01B28;
extern float D_01B01B30[16][4];
extern int D_01B01C30[16];

extern void func_01B01360(W3Task *);
extern float func_0018F118(float *);

void func_01B01460(W3Task *t)
{
    float pos[4];
    float diff[4];
    int i;

    VEC3_COPY(pos, ((RcefObj *)t)->pos);
    pos[1] = 0.0f;
    for (i = 0; i < D_01B01B28; i++) {
        VEC3_SUB(diff, D_01B01B30[i], pos);
        if (func_0018F118(diff) < 5.0f) {
            D_01B01C30[i] = 1;
        }
    }
    func_01B01360(t);
}
