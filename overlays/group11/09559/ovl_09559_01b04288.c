/* Overlay 09559: rank 88 ramp/curve update helpers (0x01B04288..0x01B045B0). */
#include "common.h"

typedef struct Sub14C {
    float *unk00;
    float *unk04;
    float unk08;
    float unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} Sub14C;

typedef struct Ramp {
    float a;
    float b;
    int c;
    int d;
} Ramp;

typedef struct Control {
    u8 pad0[0x90];
    float unk90[4];
    float unkA0[4];
    u8 padB0[0xBC];
    Ramp ramp;
} Control;

extern char D_01B0B4D0[];
extern char D_01B0B6F0[];
extern double D_01B0B718;

void func_002EF240(const char *, ...);
void func_01B01768(int, const char *, int);
float func_01B01A98(float, float, float, float, float, float);
float func_01B01B00(float, float *, int, int);
float func_002B3DB0(float);

void func_01B04338(Sub14C *a0, float *a1);
void func_01B043B8(Sub14C *a0, float *a1);

void func_01B04288(Sub14C *a0, float *a1) {
    switch (a0->unk1C) {
        case 0:
            break;
        case 1:
            *a1 = a0->unk08;
            a0->unk08 += a0->unk0C;
            break;
        case 2:
            func_01B04338(a0, a1);
            break;
        case 3:
            func_01B043B8(a0, a1);
            break;
        default:
            func_002EF240(D_01B0B6F0, a0->unk1C);
            func_01B01768(14, D_01B0B4D0, 0x723);
            break;
    }
}

void func_01B04338(Sub14C *a0, float *a1) {
    float *p = a0->unk00;
    if (--a0->unk14 != 0) {
        a0->unk08 += a0->unk0C;
        *a1 = func_01B01B00(a0->unk08, p, a0->unk18, 1);
    } else {
        a0->unk1C = 0;
        p += a0->unk18 - 1;
        *a1 = *p;
    }
}

void func_01B043B8(Sub14C *a0, float *a1) {
    float *p = a0->unk00;
    if (--a0->unk14 != 0) {
        float *q;
        float t;
        a0->unk08 += a0->unk0C;
        q = a0->unk04;
        t = func_01B01A98(q[0], q[1], q[2], q[3], q[4], a0->unk08);
        if (t >= (float)a0->unk18) {
            t = (float)a0->unk18 - 1e-6;
        }
        *a1 = func_01B01B00(t, p, a0->unk18, 1);
    } else {
        a0->unk1C = 0;
        p += a0->unk18 - 1;
        *a1 = *p;
    }
}

void func_01B044A0(Control *a0) {
    Ramp *r = &a0->ramp;
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < r->c; j++) {
            a0->unk90[i] += func_002B3DB0(r->a);
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < r->d; j++) {
            a0->unkA0[i] += func_002B3DB0(r->b);
        }
    }
}
