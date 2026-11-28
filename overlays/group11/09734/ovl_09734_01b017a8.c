#include "common.h"

extern float D_01B009C0[4];
extern float D_01B00798;
extern float D_01B007A4;
extern float D_01B007A0;
extern float D_01B00A40[4];
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern void *D_006A3924;
extern u8 D_01B00800[];

extern void func_002DD0B0(void *, void *);
extern void func_002DD128(void *);
extern void func_01B02518(void *, float);
extern void func_002DD038(void *, void *, void *);
extern void func_01B025A8(void *, void *);
extern void func_002DD080(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern int _pppRunPart(void *, int);

int func_01B017A8(void *a0)
{
    float m0[4][4];
    float m1[4][4];
    float v0[4];
    float v1[4];

    func_002DD0B0(v0, D_01B009C0);
    v0[1] = D_01B009C0[1] + D_01B007A4 * D_01B00798;
    func_002DD128(m0);
    func_01B02518(m1, D_01B007A0 * D_01B00798);
    func_002DD038(v1, D_01B00A40, D_01B009C0);
    v1[1] = 0.0f;
    func_01B025A8(m0, v1);
    func_002DD080(m0, m0, v0);
    func_002DCE38(D_006A3930, m0, m1);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00800;
    return _pppRunPart(a0, 0x30) == 0;
}
