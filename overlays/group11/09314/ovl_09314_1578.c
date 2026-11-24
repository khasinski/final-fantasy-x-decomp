#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
} Task1578;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    s32 vx, vy, vz;
    float rot;
    float f30;
    u8 pad34[0x4];
    s32 w38;
    s32 w3C;
    u8 pad40[0xB];
    u8 b4B;
} Part7C40;

extern u8 D_01B0E110[];

extern void func_01B04218(void *);
extern void func_01B01BD8(s32, void *, s32);
extern Part7C40 *func_01B07C40(void);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B058C0(void *, void *);
extern float func_002B3DB0(float);
extern void func_01B05330(void *, void *, void *);
extern float func_002B3DF8(float);

void ovl_09314_1578(Task1578 *a0)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    s32 i;

    a0->w14--;
    if (a0->w14 <= 0) {
        func_01B04218(a0);
        return;
    }

    func_01B01BD8(-1, &v00, 3);
    v00.y -= 1.0f;
    v20.x = 0.0f;
    v20.z = 0.0f;
    v20.w = 0.0f;
    v10.x = 0.0f;
    v10.y = 0.0f;
    v10.w = 1.0f;

    for (i = 0; i < 6; i++) {
        Part7C40 *s1 = func_01B07C40();
        if (s1 == 0) {
            return;
        }
        func_01B058C0(s1, func_002B49A0(D_01B0E110, 9, 0));
        MMI_COPY_LQ_A3(&s1->pos, &v00);
        MMI_COPY_SQ_A3(&s1->pos);
        v20.y = func_002B3DB0(6.2831855f);
        v10.z = func_002B3DB0(10.0f) + 20.0f;
        func_01B05330(&v20, &s1->pos, &v10);
        s1->vx = 0;
        s1->vy = 0;
        s1->vz = 0;
        s1->rot = func_002B3DB0(6.2831855f);
        {
            float sz = (func_002B3DF8(0.5f) + 1.0f) * 0.3f;
            s1->w38 = -1;
            s1->w3C = 0;
            s1->f30 = sz;
            s1->b4B = 16;
        }
    }
}
