#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xD0];
    Vec4 vecD0;
    u8 padE0[0x50];
} Obj130;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    u8 pad20[0x240];
    Vec4 pos260;
    float vx;
    float vy;
    float vz;
    float vw;
    void *cb280;
    void *cb284;
    u8 pad288[0xC];
    s32 idx294;
    u16 flags298;
    u8 pad29A[0x6];
} Work2A0;

extern u8 D_01B07358[];
extern Obj130 D_01B062E0[];

extern void func_01B03F88(void *, void *, s32, s32, s32, s32, float);
extern void func_01B010B8(void *);

void ovl_09329_0df0(Work2A0 *s2)
{
    if (s2->pos.x > -55.0f && s2->pos.x < 55.0f && s2->pos.z > -91.0f && s2->pos.y >= 0.0f) {
        Obj130 *obj;

        s2->flags298 |= 2;
        if (s2->vy != 0.0f) {
            float t = 1.0f - (-(s2->pos.y - s2->vy) / s2->vy);
            s2->pos.x -= s2->vx * t;
            s2->pos.z -= s2->vz * t;
        }
        s2->pos.y = 0.0f;
        MMI_COPY_LQ_A3(&s2->pos260, &s2->pos);
        MMI_COPY_SQ_A3(&s2->pos260);
        obj = &D_01B062E0[s2->idx294];
        func_01B03F88(D_01B07358, obj, 2, 0, 0, 0, 0.1f);
        MMI_COPY_LQ_A3(&obj->vecD0, &s2->pos260);
        MMI_COPY_SQ_A3(&obj->vecD0);
        s2->cb280 = 0;
        func_01B010B8(s2);
    }
}
