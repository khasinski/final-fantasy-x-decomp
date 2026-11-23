#include "common.h"

typedef struct S10F88Obj {
    u8 pad00[0x20];
    float v20[4];
    u8 pad30[0x80];
    float vB0[4];
    float vC0[4];
    float vD0[4];
    float vE0[4];
    float vF0[4];
    float v100[4];
    float v110[4];
    float f120;
    float f124;
    u8 pad128[0x12];
    u8 b13A;
    u8 b13B;
} S10F88Obj;

typedef struct S10F88Arg {
    S10F88Obj *p00;
    float *p04;
} S10F88Arg;

typedef struct S10FB8Arg {
    S10F88Obj *p00;
    float *p04;
    float *p08;
    s32 s0C;
} S10FB8Arg;

typedef struct S11078Arg {
    S10F88Obj *p00;
    float *p04;
    float f08;
} S11078Arg;

extern void func_002DD0B0(float *dst, float *src);
extern void func_002DD038(float *dst, float *a1, float *a2);

void func_01B10F88(S10F88Arg *a0)
{
    S10F88Obj *obj = a0->p00;
    float *src = a0->p04;
    obj->vB0[0] = obj->vC0[0] = src[0];
    obj->vB0[1] = obj->vC0[1] = src[1];
    obj->vB0[2] = obj->vC0[2] = src[2];
}

void func_01B10FB8(S10FB8Arg *a0)
{
    S10F88Obj *obj = a0->p00;
    s32 mode = a0->s0C;
    s32 i;

    if (mode != 0) {
        if (mode != 1) {
            return;
        }
    } else {
        for (i = 0; i < 3; i++) {
            obj->vE0[i] = 1.0f;
            obj->vF0[i] = a0->p08[i];
        }
    }

    for (i = 0; i < 3; i++) {
        float v = a0->p04[i];
        obj->vC0[i] = v;
        obj->vD0[i] = obj->vB0[i] - v;
    }
    obj->b13B = a0->s0C;
}

void func_01B11078(S11078Arg *a0)
{
    S10F88Obj *obj = a0->p00;
    float f = a0->f08;

    obj->b13A = 1;
    obj->f124 = f;
    obj->f120 = f;
    func_002DD0B0(obj->v100, a0->p04);
    func_002DD038(obj->v110, obj->v100, obj->v20);
    __asm__("");
}
