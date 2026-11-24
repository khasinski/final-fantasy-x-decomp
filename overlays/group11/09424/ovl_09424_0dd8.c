#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x8];
    Vec4 vecD0;
    u8 padE0[0x280];
    Vec4 vec360;
    u8 pad370[0x10];
    void *p380;
    s32 w384;
    s32 w388;
    u8 pad38C[0x8];
    s32 w394;
    u8 pad398[0x4];
    u16 h39C;
    u8 pad39E[0x2];
    u8 sub3A0[0xC0];
    float f460;
    float f464;
    u8 pad468[0x8];
    Vec4 vec470;
    u8 pad480[0x50];
    s32 w4D0;
} Work4E0;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x8];
    Vec4 vecD0;
} Obj3A0;

typedef struct {
    u8 pad00[0x14];
    Work4E0 *p14;
} TaskDD8;

extern u8 D_01B08300[];
extern u8 D_01B012E8[];

extern void func_01B040E8(void *, void *, s32, s32, s32, void *, float);
extern void func_01B01350(void *);
extern void func_01B017C8(s32, void *, s32);
extern float func_01B04FC0(void *, void *);
extern float func_002B3DB0(float);
extern void func_01B01C68(s32, s32, void *, void *);
extern float func_01B01C18(s32);
extern void func_01B05B20(void *, s32, float);
extern float func_002B3DF8(float);
extern void func_01B03E08(void *);

void ovl_09424_0dd8(TaskDD8 *a0)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Work4E0 *s5 = a0->p14;
    u8 *s2;
    Work4E0 *s4;
    Vec4 *pD0;
    Vec4 *p360;
    s32 s0;
    float ang;

    if (s5->w4D0 > 0) {
        s5->w4D0--;
        return;
    }

    s2 = D_01B08300;
    s4 = s5;
    func_01B040E8(s2, s4, 1, 0, 0, 0, 0.1f);
    pD0 = &s4->vecD0;
    func_01B01350(pD0);
    {
        register Vec4 *p10 __asm__("$17") = &v10;
        MMI_COPY_LQ_A3(p10, pD0);
        MMI_COPY_SQ_A3(p10);
        func_01B017C8(0, &v20, 0);
        v10.y = 0.0f;
        v20.y = 0.0f;
        p360 = &s4->vec360;
        v00.x = func_01B04FC0(p10, &v20) * 1000.0f + 1000.0f;
    }
    v00.x += func_002B3DB0(500.0f);
    v00.y = 0.0f;
    v00.z = 0.0f;
    v00.w = 1.0f;
    func_01B01C68(-1, 6, &v00, p360);
    s4->vec360.y = func_01B01C18(-1) - 15.0f;
    s4->vec360.y += func_002B3DB0(2.0f);
    s4->vec360.w = 1.0f;
    s4->p380 = s2;
    s4->w384 = 0;
    s4->w388 = 0;
    s4->w394 = 0;
    s4->h39C = 0;
    func_01B05B20(s4, 1, 6.0f);

    s4 = (Work4E0 *)((u8 *)s4 + 0x3A0);
    s0 = (s32)(func_01B04FC0(pD0, p360) / 6.0f);
    {
        float rate = (func_002B3DF8(0.25f) + 0.75f) * 0.1f;
        func_01B040E8(s2, s4, 3, s0, 0, D_01B012E8, rate);
    }
    MMI_COPY_LQ_A3(&s4->vecD0, &s5->vec360);
    MMI_COPY_SQ_A3(&s4->vecD0);

    ang = s5->fC0 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s4->fC0 = ang;

    ang = s5->fC4 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s4->fC4 = ang;

    func_01B03E08(a0);
}
