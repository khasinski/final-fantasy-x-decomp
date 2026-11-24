#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float x, y, z, w;
    float vx, vy, vz;
    s32 w2C;
    float f30;
    u8 pad34[0x4];
    s32 w38;
    s32 w3C;
    u8 pad40[0xB];
    u8 b4B;
} Part0C48;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float vecD0[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} Obj60C0;

extern u8 D_01B06078[];
extern Obj60C0 D_01B060C0[];
extern u8 D_01B04120[];
extern u8 D_01B06030[];
extern u8 D_01B0B910[];
extern u8 D_01B00400[];
extern s32 D_01B06074;

extern Part0C48 *func_01B05650(void);
extern void **func_01B04110(void *, s32);
extern void func_01B04F48(void *, void *);
extern void func_002DD0B0(void *, void *);
extern float func_002B3DB0(float);
extern float func_001ACED8(void);
extern float func_002B3DF8(float);
extern void func_01B03B80(void *, void *, s32, s32, s32, void *, float);
extern void func_01B03308(void *, void *, void *);

void ovl_09224_0c48(u8 *s3)
{
    s32 i = 0;

    do {
        Part0C48 *p = func_01B05650();
        if (p == 0) {
            break;
        }
        func_01B04F48(p, *func_01B04110(D_01B06078, 1));
        func_002DD0B0(&p->x, s3 + 0x10);
        p->x += func_002B3DB0(1.0f);
        p->y += func_002B3DB0(1.0f);
        p->z += func_002B3DB0(1.0f);
        p->vx = (func_001ACED8() - 1.5f) * 0.5f;
        p->vy = (func_001ACED8() - 1.5f) * 0.5f;
        p->vz = (func_001ACED8() - 1.5f) * 0.5f;
        p->w2C = 0;
        {
            float sz = (func_002B3DF8(0.5f) + 1.0f) * 0.05f;
            p->b4B = 0;
            p->w38 = 16;
            p->w3C = 16;
            p->f30 = sz;
        }
        i++;
    } while (i < 4);
}

void ovl_09224_0da0(u8 *s0)
{
    Obj60C0 *s1 = &D_01B060C0[1];
    float ang;

    func_01B03B80(D_01B06078, s1, 1, 0, 0, D_01B04120, 0.03f);
    func_002DD0B0(s1->vecD0, s0 + 0x260);
    ang = D_01B060C0[0].fC4 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s1->fC4 = ang;
    func_01B03308(D_01B06030, D_01B0B910, D_01B00400);
    s1->p110 = D_01B06030;
    D_01B06074 = 1;
}
