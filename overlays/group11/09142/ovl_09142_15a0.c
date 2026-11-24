#include "common.h"

extern u8 D_01B00AC0[];
extern u8 D_01B00B70[];

extern void func_002DD128(void *);
extern void func_01B03018(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD080(void *, void *, void *);

void func_01B015A0(float *a0, float *a1) {
    float scale[4][4];
    float rot[4][4];

    func_002DD128(a0);
    func_002DD128(rot);
    func_002DD128(scale);
    func_01B03018(rot, D_01B00B70, D_01B00AC0);
    func_002DCE38(a0, rot, a0);
    func_002DD080(a0, a0, D_01B00AC0);
    scale[0][0] = a1[0];
    scale[1][1] = a1[1];
    scale[2][2] = a1[2];
    func_002DCE38(a0, a0, scale);
}
