#include "vu0.h"

typedef struct Ovl09053BeamSub30 {
    u8 pad00[0x210];
    u8 b210;
    u8 b211;
    u8 b212;
    u8 b213;
    u8 b214;
    u8 b215;
    u8 b216;
    u8 b217;
    u8 pad218[0x08];
    float f220;
    u8 pad224[0x04];
    int w228;
    u8 pad22C[0x04];
    float f230;
    u8 pad234[0x0C];
} Ovl09053BeamSub30;

typedef struct Ovl09053BeamSub {
    u8 pad00[0x10];
    float pos10[4];
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    float f24;
    u8 pad28[0x08];
    Ovl09053BeamSub30 s30;
} Ovl09053BeamSub;

typedef struct Ovl09053Beam {
    u8 pad00[0x40];
    float f40;
    float f44;
    float f48;
    float f4C;
    float f50;
    float f54;
    float f58;
    float f5C;
    float pos60[4];
    Ovl09053BeamSub sub[4];
    int wA30;
    int wA34;
    int wA38;
} Ovl09053Beam;

extern float D_01B00558[];
extern Ovl09053Beam *D_01B05B58;
extern u8 D_01B0B670[];

void *func_002B49A0(void *a0, int a1, int a2);
void func_002DD128(void *a0);
float func_01B04FE0(void *a0, void *a1);
void func_01B05060(void *a0, void *a1);
void func_01B054D0(void *a0, void *a1);
void func_01B056B0(void *a0, void *a1, void *a2);

void func_01B00D40(float *a0, void *a1, void *a2)
{
    Ovl09053Beam *s1 = D_01B05B58;
    Ovl09053BeamSub *sub;
    void *t0 = func_002B49A0(D_01B0B670, 9, 0);
    void *t1 = func_002B49A0(D_01B0B670, 9, 1);
    int i;

    sub = s1->sub;
    for (i = 0; i < 4; sub++, i++) {
        Ovl09053BeamSub30 *s30 = &sub->s30;
        func_01B054D0(sub, t0);
        MMI_COPY_LQ_A3((u8 *)s30 - 0x20, a0);
        MMI_COPY_SQ_A3((u8 *)s30 - 0x20);
        sub->b20 = 0x80;
        sub->b21 = 0x80;
        sub->b22 = 0x80;
        sub->b23 = 0x80;
        sub->f24 = 0.2f;
        func_01B056B0(s30, t1, a0);
        s30->b210 = 0x96;
        s30->b211 = 0x78;
        s30->b212 = 0x50;
        s30->b213 = 0x30;
        s30->b214 = 0x78;
        s30->b215 = 0x3C;
        s30->b216 = 0x64;
        s30->b217 = 0x08;
        s30->f220 = 0.55f;
        s30->w228 = 0x46;
        s30->f230 = D_01B00558[i];
    }

    func_002DD128(s1);
    func_01B05060(s1, a2);
    MMI_COPY_LQ_A3(s1->pos60, a0);
    MMI_COPY_SQ_A3(s1->pos60);
    s1->f40 = 0.0f;
    s1->f44 = 0.0f;
    s1->f48 = 0.0f;
    s1->f4C = 1.0f;
    s1->f50 = 0.0f;
    s1->f54 = 0.0f;
    s1->f58 = func_01B04FE0(a0, a1);
    s1->f5C = 1.0f;
    s1->wA30 = 0;
    s1->wA34 = 0;
    s1->wA38 = 0x14;
}
