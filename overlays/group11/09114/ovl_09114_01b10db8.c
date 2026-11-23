#include "common.h"

typedef struct S10DB8Obj {
    u8 pad00[0x20];
    float v20[4];
    u8 pad30[0x10];
    float v40[4];
    u8 pad50[0x20];
    float v70[3];
    float f7C;
    float v80[3];
    float f8C;
    s16 h90[3];
    u8 pad96[0xA];
    float vA0[4];
    u8 padB0[0x80];
    u32 u130;
    u8 pad134[4];
    u8 b138;
} S10DB8Obj;

typedef struct S10DB8Arg {
    S10DB8Obj *p00;
    s32 *p04;
    float *p08;
    s32 s0C;
} S10DB8Arg;

typedef struct S10F48Arg {
    S10DB8Obj *p00;
    s32 s04;
} S10F48Arg;

extern void func_002DD038(float *dst, float *a1, float *a2);

void func_01B10DB8(S10DB8Arg *a0)
{
    float tmp[4];
    S10DB8Obj *obj = a0->p00;
    s32 i;

    switch (a0->s0C) {
    case 0:
        obj->f8C = obj->f7C;
        for (i = 0; i < 3; i++) {
            obj->v80[i] = a0->p08[i];
            obj->h90[i] = a0->p04[i];
            if (a0->p04[i] < 0) {
                obj->h90[i] = -obj->h90[i];
                obj->v70[i] = -1.0f;
            } else {
                obj->v70[i] = 1.0f;
            }
        }
        break;
    case 1:
        obj->f8C = obj->f7C;
        for (i = 0; i < 3; i++) {
            obj->v80[i] = a0->p08[i];
            obj->h90[i] = a0->p04[i];
            if (a0->p04[i] < 0) {
                obj->h90[i] = -obj->h90[i];
                obj->v80[i] = -obj->v80[i];
                obj->v70[i] = -1.0f;
            } else {
                obj->v70[i] = 1.0f;
            }
        }
        break;
    default:
        return;
    }

    obj->u130 |= 9;
    obj->b138 = a0->s0C;
    func_002DD038(tmp, obj->v20, obj->v40);
    obj->vA0[0] = tmp[0];
    obj->vA0[1] = tmp[1];
    obj->vA0[2] = tmp[2];
}

void func_01B10F48(S10F48Arg *a0)
{
    S10DB8Obj *obj = a0->p00;
    float ang = (float)a0->s04 * 3.1415927f * (1.0f / 32768.0f);
    obj->f8C = ang;
    obj->f7C = ang;
    obj->h90[2] = a0->s04;
    obj->v70[2] = 0.0f;
}
