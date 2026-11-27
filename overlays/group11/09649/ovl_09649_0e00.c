#include "common.h"

typedef union {
    u_long128 q;
    float f[4];
} Vec4Q;

extern void func_001B8670(void *, int, float);
extern void *func_01B03E48(int);
extern void func_01B04098(int, void *, int);
extern void func_01B05458(void *);
extern void func_01B076E8(void *, void *, void *);

void func_01B00E00(void)
{
    Vec4Q v0;
    Vec4Q v1;
    Vec4Q v2;
    float ang;

    func_01B04098(-1, &v0, 0);
    func_01B05458(&v1);
    func_01B076E8(&v2, &v0, &v1);
    ang = -v2.f[1] + 1.5707964f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    v2.f[1] = ang;
    func_001B8670(func_01B03E48(-1), 1, v2.f[1]);
}
