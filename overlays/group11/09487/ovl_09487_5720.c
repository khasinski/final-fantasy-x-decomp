#include "common.h"

extern u8 D_01B05D00[];

extern void func_002DD0B0(float *, float *);
extern void func_002DCE08(float *, void *, float *);
extern void func_002DCFD8(float *, float *, float);
extern void func_002DD038(float *, float *, float *);
extern void func_002DD068(float *, float *, float);
extern void func_002DD020(float *, float *, float *);
extern void func_002DD0E8(int *, float *);
extern void func_01B055D8(int, int, int, int, int, int, unsigned long);

int func_01B05720(float *a0, float *a1, unsigned long a2)
{
    float v0[4];
    float v1[4];
    float p0[4];
    float p1[4];
    float s0[4];
    float s1[4];
    int i0[4];
    int i1[4];
    float d0_vec[4];
    float d1_vec[4];
    int c1 = 0;
    int c0 = 0;

    func_002DD0B0(v0, a0);
    func_002DD0B0(v1, a1);
    v0[3] = 1.0f;
    v1[3] = 1.0f;
    func_002DCE08(p0, D_01B05D00, v0);
    func_002DCE08(p1, D_01B05D00, v1);
    func_002DCFD8(s0, p0, p0[3]);
    func_002DCFD8(s1, p1, p1[3]);
    if (s0[2] > 1048562.5f) {
        c0 = 1;
    }
    if (s1[2] > 1048562.5f) {
        c1 = 1;
    }
    if (s0[3] < 0.0f) {
        c0 = 1;
    }
    if (s1[3] < 0.0f) {
        c1 = 1;
    }
    if (c0 == 0 && c1 == 0) {
    } else if (c0 != 0 && c1 != 0) {
        return 0;
    } else if (c0 == 0 && c1 != 0) {
        float d1 = p1[2] - p1[3];
        float d0 = p0[2] - p0[3];
        double t = (double)(d0 / (d1 - d0));
        float ft;
        if (t < 0.0) {
            t = 0.0 - t;
        }
        ft = (float)t;
        func_002DD038(d0_vec, p1, p0);
        func_002DD068(d0_vec, d0_vec, ft);
        func_002DD020(p1, d0_vec, p0);
    } else {
        float d0 = p0[2] - p0[3];
        float d1 = p1[2] - p1[3];
        double t = (double)(d1 / (d0 - d1));
        float ft;
        if (t < 0.0) {
            t = 0.0 - t;
        }
        ft = (float)t;
        func_002DD038(d1_vec, p0, p1);
        func_002DD068(d1_vec, d1_vec, ft);
        func_002DD020(p0, d1_vec, p1);
    }
    func_002DCFD8(s0, p0, p0[3]);
    func_002DCFD8(s1, p1, p1[3]);
    func_002DD0E8(i0, s0);
    func_002DD0E8(i1, s1);
    func_01B055D8(i1[0], i1[1], i1[2], i0[0], i0[1], i0[2], a2);
    return 1;
}
