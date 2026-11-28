#include "common.h"

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern float D_01B00950;
extern float D_01B00968;
extern float D_01B0096C;
extern u8 D_01B009D8;
extern float D_01B00F70[4];

extern void func_002DD0B0(void *, void *);
extern void func_002DD128(void *);
extern void func_01B038B8(void *, float);
extern void func_002DD080(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern s32 func_00267FA0(void *, s32);

s32 func_01B02BB0(void *s3) {
    float m0[16];
    float m1[16];
    float v[4];

    func_002DD0B0(v, D_01B00F70);
    v[1] = D_01B00F70[1] + D_01B0096C * D_01B00950;
    func_002DD128(m0);
    func_01B038B8(m1, D_01B00968 * D_01B00950);
    func_002DD080(m0, m0, v);
    func_002DCE38(D_006A3930, m0, m1);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    {
        void *h = &D_01B009D8;
        *(volatile void **)&D_006A3924 = h;
    }
    return func_00267FA0(s3, 0x30) == 0;
}
