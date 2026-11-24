#include "common.h"

extern int D_01B006B8;
extern u8 D_01B00C80;
extern void *D_01B00CB4;
extern int D_01B00DA4;
extern float D_01B00DC0[2][4];

extern void func_01B01850(void *, void *, float *, float *);
extern int func_01B02B00(float *);
extern void func_01B031C8(void *);
extern int func_01B03360(void *, void *, int, float);
extern void func_00107428(int, int, int, float *);
extern int func_0014AA50(int);
extern void func_002DD998(float *, float *, float);

int func_01B01B08(void *pool)
{
    float pos[4];
    float dir[4];

    func_00107428(D_01B00DA4, 0, 0, pos);
    dir[0] = D_01B00DC0[0][0] - D_01B00DC0[1][0];
    dir[1] = D_01B00DC0[0][1] - D_01B00DC0[1][1];
    dir[2] = D_01B00DC0[0][2] - D_01B00DC0[1][2];
    func_01B02B00(dir);
    if (func_0014AA50(2) == 0) {
        pos[0] += dir[0] * 18.0f;
        pos[1] += dir[1] * 18.0f;
        pos[2] += dir[2] * 18.0f;
    }
    func_002DD998(dir, dir, -1.0f);
    if (func_0014AA50(2) != 0) {
        func_01B01850(pool, D_01B00CB4, pos, dir);
        func_01B01850(pool, D_01B00CB4, pos, dir);
    }
    func_01B01850(pool, D_01B00CB4, pos, dir);
    func_01B031C8(pool);
    {
        int prev = D_01B006B8;
        D_01B006B8 = func_01B03360(pool, &D_01B00C80, prev, 0.0f);
    }
    return 1;
}
