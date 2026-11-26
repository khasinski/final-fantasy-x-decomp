#include "common.h"

extern int D_01B00630;
extern int D_01B00634;
extern int D_01B00638;
extern int D_01B012C0;

extern int D_01D01400;
extern int D_01D01404;
extern int D_01D01408;
extern int D_01D01410;
extern int D_01D0141C;
extern s16 D_01D01420;
extern s16 D_01D01422;
extern float D_01D01440[4];
extern float D_01D01490[4][4];
extern float D_01D014D0[4][4];
extern float D_01D01510;
extern float D_01D01514;
extern float D_01D01530[4];

extern int func_0029B830(int);
extern void func_001CDC58(int, int);
extern int func_001CDAF8(int);
extern void func_001CE050(int, int);
extern void func_0026BEB0(float (*)[4], int);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DCE08(float *, float (*)[4], float *);
extern void func_002DD068(float *, float *, float);
extern void func_01B00938(float *, float);
extern void func_002DCFF8(float *, float *, float *, float);
extern void MsSetChrVisible(int, int);
extern int func_001108B8(int, int);
extern void Ch_SetOrgMatrix(int, float (*)[4]);

int ovl_09227_09a8(void)
{
    float rotMtx[4][4];
    float vec40[4];
    float vec50[4];
    float vec60[4];
    float pad70[16];
    int t;
    float *p0;
    register float *p1 __asm__("$5");
    float *p2;
    float f;

    if (D_01B00630 == 0) {
        if (func_0029B830(D_01B012C0) != 0) {
            return 0;
        }
        D_01B00630++;
    }
    if (D_01B00634 == 0) {
        D_01B00634 = 1;
        func_001CDC58(D_01B012C0, 0);
    }
    if (D_01B00638 == 0) {
        if (func_001CDAF8(D_01B012C0) <= 0) {
            goto ret;
        }
        D_01B00638++;
    }

    if (D_01D01400 == 0x83) {
        func_001CE050(D_01D01404, 0xB2);
    }

    t = D_01D01400 - 0xBF;
    if ((u32)t >= 0x47) {
        return 0;
    }

    if (t == 0) {
        func_001CE050(D_01D01408, 0x80);
    } else if (t == 0x1E) {
        func_001CE050(D_01D01408, 0x81);
    }

    func_0026BEB0(rotMtx, D_01D01420);
    func_002DCE38(D_01D01490, D_01D014D0, rotMtx);
    vec40[0] = vec40[2] = 0.0f;
    vec40[1] = D_01D01510;
    vec40[3] = 1.0f;
    func_002DCE08(vec40, D_01D01490, vec40);
    vec40[1] -= D_01D01510;
    func_002DD068(D_01D01490[0], D_01D01490[0], 0.01f);
    func_002DD068(D_01D01490[1], D_01D01490[1], 0.01f);
    func_002DD068(D_01D01490[2], D_01D01490[2], 0.01f);

    if (t < 0x1E) {
        f = (float)t;
        f /= 30.0f;
        func_01B00938(vec60, D_01D01514);
        p0 = vec50;
        p1 = vec60;
        p2 = D_01D01440;
        goto do_lerp;
    } else if (t < 0x32) {
        func_01B00938(vec50, D_01D01514);
    } else if (t >= 0x46) {
        if (t == 0x46) {
            MsSetChrVisible(D_01D01408, 0);
            return 0;
        }
    } else {
        f = (float)(t - 0x32);
        f /= 20.0f;
        func_01B00938(vec60, D_01D01514);
        f *= f;
        p1 = D_01D01530;
        p2 = vec60;
        p0 = vec50;
    do_lerp:
        func_002DCFF8(p0, p1, p2, f);
    }

    if (vec50[1] > D_01D01440[1]) {
        vec50[1] = D_01D01440[1];
    } else if (D_01D0141C == -1) {
        D_01D0141C = func_001108B8(D_01D01410, 0);
    }

    D_01D01490[3][0] = vec50[0] + vec40[0];
    D_01D01490[3][1] = vec50[1] + vec40[1];
    D_01D01490[3][2] = vec50[2] + vec40[2];
    Ch_SetOrgMatrix(D_01D01410, D_01D01490);
    D_01D01422 += 0x80;
    D_01D01420 += D_01D01422;
ret:
    return 0;
}
