#include "common.h"

extern float D_01B0079C;
extern float D_01B007A8;
extern float D_01B007B4;
extern float D_01B009C0[4];
extern float D_01B009E0[4];
extern s32 D_01B00A30;
extern s32 D_01B00A38;
extern float D_01B00A70[4];

extern void func_00107378(void *, void *);
extern void func_002DD0B0(void *, void *);
extern s32 func_01B00F48(s32);
extern void func_002DCEC8(void *, void *);
extern void func_002DD998(void *, void *, float);
extern void func_001B6790(s32, void *);
extern void func_002DD038(void *, void *, void *);
extern float func_01B00E10(s32);
extern float func_001109B0(void *);
extern void func_00108910(void *, s32, void *);
extern void func_002DD020(void *, void *, void *);
extern void func_001AF2E8(void *);
extern void func_001E4C30(s32, float);
extern void func_002DD128(void *);
extern void func_01B026A0(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD080(void *, void *, void *);

void func_01B00FF0(float *s3, void *s4) {
    float m[16];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    float v80[4];
    float v90[4];
    float vA0[4];
    s32 r[2];
    float f20;

    func_00107378(s4, m);
    func_002DD0B0(v40, &m[12]);
    r[0] = func_01B00F48(D_01B00A30);
    r[1] = func_01B00F48(D_01B00A38);
    if (r[0] == 1 && r[1] == 1) {
        func_002DD0B0(v50, &m[8]);
        func_002DCEC8(v50, v50);
        func_002DD998(v50, v50, -1.0f);
    } else if (r[0] == 0 && r[1] == 0) {
        func_002DD0B0(v50, &m[8]);
        func_002DCEC8(v50, v50);
        func_002DD998(v50, v50, -1.0f);
    } else {
        func_001B6790(D_01B00A38, v90);
        func_001B6790(D_01B00A30, vA0);
        func_002DD038(v50, vA0, v90);
        func_002DCEC8(v50, v50);
    }
    f20 = func_01B00E10(D_01B00A38) + D_01B007B4;
    func_001109B0(s4);
    func_00108910(s4, 16, v60);
    func_002DD998(v70, v50, f20 + D_01B0079C);
    func_002DD020(s3, v40, v70);
    func_001AF2E8(v80);
    s3[1] += D_01B007A8;
    func_001E4C30(0, D_01B0079C);
    func_001E4C30(1, f20);
    func_001E4C30(2, s3[0]);
    func_001E4C30(3, s3[1]);
    func_001E4C30(4, s3[2]);
}

void func_01B011D8(void *s3) {
    float m0[16];
    float m1[16];
    float v80[4];
    float v90[4];
    s32 r[2];
    float vB0[4];
    float vC0[4];

    func_002DD128(s3);
    func_002DD128(m1);
    func_002DD128(m0);
    r[0] = func_01B00F48(D_01B00A30);
    r[1] = func_01B00F48(D_01B00A38);
    if (r[0] == 1 && r[1] == 1) {
        func_002DD0B0(vB0, D_01B00A70);
        vB0[1] = D_01B009C0[1];
        func_01B026A0(m1, vB0, D_01B009C0);
    } else if (r[0] == 0 && r[1] == 0) {
        func_002DD0B0(vC0, D_01B00A70);
        vC0[1] = D_01B009C0[1];
        func_01B026A0(m1, vC0, D_01B009C0);
    } else {
        func_001B6790(D_01B00A38, v80);
        func_001B6790(D_01B00A30, v90);
        func_01B026A0(m1, v80, v90);
    }
    func_002DCE38(s3, m1, s3);
    func_002DD080(s3, s3, D_01B009C0);
    m0[0] = D_01B009E0[0] * 0.001f;
    m0[5] = D_01B009E0[1] * 0.001f;
    m0[10] = D_01B009E0[2] * 0.001f;
    func_002DCE38(s3, s3, m0);
}
