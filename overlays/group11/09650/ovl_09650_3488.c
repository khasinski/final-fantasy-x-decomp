#include "common.h"

extern float D_01B007FC[3];
extern float D_01B00814[3];

extern void func_01B03430(float *);

void func_01B03488(void) {
    float v[4];
    float *p;

    func_01B03430(v);
    p = D_01B007FC;
    p[0] = v[0] + 15.0f;
    p[1] = v[1] - 14.0f;
    p[2] = v[2] + 151.0f;
    p = D_01B00814;
    p[0] = v[0] - 0.0f;
    p[1] = v[1] - 28.0f;
    p[2] = v[2] - 0.0f;
}
