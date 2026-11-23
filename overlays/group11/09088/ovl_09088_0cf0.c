#include "common.h"

extern int D_01B0062C;
extern void *func_01B00BE0(int);
extern int func_01B00C08(int);
extern void func_00110220(int, float *, float *, float *);
extern void func_00108910(int, int, float *);
extern float func_001109B0(int);
extern float func_00110180(int);
extern void func_001B6BB0(void *, float *);
extern int func_00110818(int);
extern void func_001101D0(int, float, float, float);
extern void func_00110188(int, float, float);

void func_01B00CF0(int a0, float *out, int mode)
{
    float tmp[4];
    int id = func_01B00C08(a0);

    func_00110220(id, &out[0], &out[1], &out[2]);
    switch (mode) {
    case 0:
        break;
    case 1:
        func_00108910(id, 6, tmp);
        out[1] = tmp[1];
        break;
    case 2:
        {
            float h = func_001109B0(id);
            func_00108910(id, 6, tmp);
            out[1] = tmp[1] - h * 0.5f;
        }
        break;
    case 3:
        out[1] = func_00110180(id);
        break;
    }
    out[3] = 1.0f;
}

void func_01B00DD8(int a0, float *v)
{
    if (D_01B0062C == 0) {
        func_001B6BB0(func_01B00BE0(a0), v);
    } else {
        int id = func_01B00C08(a0);
        if (func_00110818(id) == 0) {
            func_001101D0(id, v[0], v[1], v[2]);
        } else {
            func_00110188(id, v[0], v[2]);
        }
    }
}
