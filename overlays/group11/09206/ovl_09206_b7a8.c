#include "common.h"

typedef struct OscObj OscObj;
struct OscObj {
    void (*fn00)(OscObj *);
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    s32 w24;
    s32 w28;
    u16 h2C;
};

typedef struct TaskObj {
    u8 pad00[0x14];
    OscObj *p14;
    u8 b18;
} TaskObj;

extern float D_01B00F6C;
extern float D_01B00F70;

TaskObj *func_01B07B20(void (*fn)(TaskObj *));
void func_01B07CE8(TaskObj *t);
void func_01B07BA0(TaskObj *t);
float func_01B08968(float a0, float a1, float a2, float a3);
float func_002B3DB0(float a0);

void func_01B0B818(TaskObj *t);

void func_01B0B7A8(OscObj *a0, s32 a1)
{
    float step = 1.0f / (float)a1;
    TaskObj *t;

    a0->fn00 = 0;
    a0->f1C = 0.0f;
    a0->w24 = 0;
    a0->h2C = 0;
    a0->w28 = a1;
    a0->f20 = step;
    t = func_01B07B20(func_01B0B818);
    t->p14 = a0;
    t->b18 = 1;
    func_01B07CE8(t);
}

double fabs(double x);

void func_01B0B818(TaskObj *t)
{
    OscObj *s0 = t->p14;
    float f20;
    float f21;

    if (s0->w24 > 0) {
        s0->w24--;
        return;
    }

    if (s0->w28 > 0 && --s0->w28 > 0) {
        s0->f1C += s0->f20;
        f20 = func_01B08968(s0->f04, s0->f08, s0->f0C, s0->f1C);
        f21 = func_01B08968(s0->f10, s0->f14, s0->f18, s0->f1C);
        if (s0->h2C & 1) {
            f20 = func_002B3DB0(f20);
        }
        if (s0->h2C & 2) {
            f21 = func_002B3DB0(f21);
        }
    } else {
        f21 = 0.0f;
        f20 = f21;
        if (s0->fn00 != 0) {
            s0->fn00(s0);
        }
        if (!(s0->h2C & 4)) {
            s0->h2C |= 0x8000;
            func_01B07BA0(t);
        }
    }

    if (s0->w28 & 1) {
        f20 = -f20;
        f21 = -f21;
    }

    if (fabs(D_01B00F6C) < fabs(f20)) {
        D_01B00F6C = f20;
    }
    if (fabs(D_01B00F70) < fabs(f21)) {
        D_01B00F70 = f21;
    }
}
