#include "common.h"
typedef struct { u8 pad00[0x10]; int *w10; } TtCfg;
typedef struct { u8 pad00[0x40]; float f40[4]; u8 pad50[0x10]; float f60; } TtPart;
extern u8 D_01B004F0[];
extern u8 D_006A3930[], D_006A3970[], D_006A39B0[], D_006A3A70[], D_006A3AB0[];
extern int D_01B00538;
extern u8 D_01B00430[];
extern void *D_006A3924;
extern int D_006A3BC4;
extern TtCfg *D_01B0042C;
extern void func_001A9EE0(float *);
extern void func_002DCF48(float *, float *);
extern void func_002DD0C0(void *, void *);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DD0B0(void *, float *);
extern void func_01B00F50(float *, float);
extern void func_002DCE38(void *, void *, void *);
extern int func_00267FA0(TtPart *, int);
extern void func_00267530(TtPart *);
extern void func_00267658(TtPart *, int, int, int);

int func_01B00900(TtPart *p) {
    float m0[16], m1[16], m2[16], m3[16];
    float v[4];
    func_001A9EE0(m0);
    func_002DCF48(m1, m0);
    func_002DD0C0(D_01B004F0, m1);
    func_002DCE08(v, m1, p->f40);
    func_002DD0B0(D_01B004F0 + 0x30, v);
    func_01B00F50(m3, p->f60);
    func_002DCE38(D_01B004F0, D_01B004F0, m3);
    func_002DD0C0(D_006A3930, D_01B004F0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    if (D_01B00538 >= 801) {
        D_006A3BC4 = 1;
    }
    { void *h = D_01B00430;
    D_006A3924 = h;
    if (func_00267FA0(p, 0x30)) {
        D_006A3924 = h;
        func_00267530(p);
        D_006A3924 = h;
        func_00267658(p, 0x1000, D_01B0042C->w10[0], 1);
    }
    } return 1;
}
