#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    s32 w00;
    s32 w04;
} Pair8;

typedef struct {
    u8 pad00[0x14];
    Pair8 *p14;
} Task1368;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    float vx, vy, vz;
    float rot;
    float f30;
    u8 pad34[0x4];
    s32 w38;
    s32 w3C;
} Part7C40;

extern u8 D_01B0E110[];

extern void func_01B04218(void *);
extern void func_01B01BD8(s32, void *, s32);
extern float func_01B01AB0(s32);
extern void func_01B05330(void *, void *, void *);
extern Part7C40 *func_01B07C40(void);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B058C0(void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);

void ovl_09314_1368(Task1368 *a0)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    Pair8 *p = a0->p14;
    Part7C40 *s0;

    p->w04--;
    if (p->w04 <= 0) {
        func_01B04218(a0);
        return;
    }

    func_01B01BD8(p->w00, &v00, 1);
    v10.x = 0.0f;
    v10.y = func_01B01AB0(-1);
    v10.z = 0.0f;
    v10.w = 0.0f;
    v30.x = 0.0f;
    v30.y = 0.0f;
    v30.z = 2.0f;
    v30.w = 1.0f;
    func_01B05330(&v10, &v00, &v30);

    v20.x = v20.y = v20.z = 0.0f;
    v20.w = 1.0f;
    v30.x = 0.0f;
    v30.y = 0.0f;
    v30.z = -0.2f;
    v30.w = 1.0f;
    func_01B05330(&v10, &v20, &v30);

    s0 = func_01B07C40();
    if (s0 != 0) {
        func_01B058C0(s0, func_002B49A0(D_01B0E110, 9, 1));
        s0->pos.x = v00.x + func_002B3DB0(3.0f);
        s0->pos.y = v00.y + func_002B3DB0(6.0f);
        s0->pos.z = v00.z + func_002B3DB0(3.0f);
        s0->pos.w = 1.0f;
        s0->vx = v20.x * (func_002B3DF8(0.5f) + 1.0f);
        s0->vy = func_002B3DB0(0.1f);
        s0->vz = v20.z * (func_002B3DF8(0.5f) + 1.0f);
        s0->rot = func_002B3DB0(6.2831855f);
        {
            float sz = (func_002B3DF8(1.0f) + 1.0f) * 0.12f;
            s0->w3C = 0;
            s0->w38 = -1;
            s0->f30 = sz;
        }
    }
}
