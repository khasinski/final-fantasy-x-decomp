#include "common.h"

typedef struct S3C28Part {
    float x;
    float y;
    float z;
    float w;
    float vx;
    float vy;
    float vz;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 pad30[0xC];
    float f3C;
    u8 pad40[0xC];
    s32 s4C;
    s32 s50;
    u8 pad54[0x13];
    u8 b67;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
} S3C28Part;

extern u8 D_01B0DBE0[];
extern u32 D_00307F2C;

extern void **func_01B0A1D8(void *a0, s32 a1);
extern S3C28Part *func_01B0D678(void);
extern void func_01B0B188(void *a0, void *a1);
extern float func_002B3DB0(float a0);
extern float func_002B3DF8(float a0);

void func_01B03C28(float *a0)
{
    void *tex = *func_01B0A1D8(D_01B0DBE0, 1);
    S3C28Part *p = func_01B0D678();

    if (p != 0) {
        func_01B0B188((u8 *)p + 0x30, tex);
        p->x = a0[0] + func_002B3DB0(2.0f);
        p->y = a0[1];
        p->z = a0[2] + func_002B3DB0(2.0f);
        p->w = 1.0f;
        p->vx = func_002B3DB0(0.1f);
        p->vy = -(func_002B3DF8(0.1f) + 0.2f);
        p->vz = func_002B3DB0(0.1f);
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = 0.0f;
        p->f28 = 0.0f;
        p->f2C = 1.0f;
        p->f24 = 0.01f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.2f;
        {
            u8 r = 0x8C, g = 0x96, b = 0xB4, a = 0x18;
            p->b68 = r;
            p->b6B = a;
            p->b69 = g;
            p->b6A = b;
        }
        p->s50 = 0;
        p->s4C = -1;

        if ((D_00307F2C & 7) == 0) {
            p = func_01B0D678();
            if (p != 0) {
                tex = *func_01B0A1D8(D_01B0DBE0, 13);
                func_01B0B188((u8 *)p + 0x30, tex);
                p->x = a0[0] + func_002B3DB0(2.0f);
                p->y = a0[1];
                p->z = a0[2] + func_002B3DB0(2.0f);
                p->w = 1.0f;
                p->vx = func_002B3DB0(0.25f);
                p->vy = -func_002B3DF8(0.5f);
                p->vz = func_002B3DB0(0.25f);
                p->f1C = func_002B3DB0(3.1415927f);
                p->f20 = 0.0f;
                p->f28 = 0.0f;
                p->f2C = 1.0f;
                p->f24 = 0.025f;
                p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.02f;
                p->s4C = -1;
                p->s50 = 0;
            }
        }
    }
}

void func_01B03EA8(float *a0)
{
    S3C28Part *p;
    void *tex;

    if ((D_00307F2C & 3) == 0) {
        p = func_01B0D678();
        if (p != 0) {
            tex = *func_01B0A1D8(D_01B0DBE0, 10);
            func_01B0B188((u8 *)p + 0x30, tex);
            p->x = a0[0] + func_002B3DB0(2.0f);
            p->y = a0[1];
            p->z = a0[2] + func_002B3DB0(2.0f);
            p->w = 1.0f;
            p->vx = func_002B3DB0(0.1f);
            p->vy = func_002B3DF8(0.05f) + 0.1f;
            p->vz = func_002B3DB0(0.1f);
            p->f1C = func_002B3DB0(3.1415927f);
            p->f20 = 0.0f;
            p->f28 = 0.0f;
            p->f2C = 1.0f;
            p->f24 = -0.01f;
            p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.02f;
            p->b67 = 0xA0;
            p->b6B = 0;
            p->s4C = 0x20;
            p->s50 = 0x20;
        }
    }
}
