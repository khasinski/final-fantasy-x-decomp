#include "common.h"
#include "vu0.h"

typedef struct Ovl09607Part {
    float pos[4];       /* 0x00 */
    float f10;          /* 0x10 */
    float f14;          /* 0x14 */
    float f18;          /* 0x18 */
    float f1C;          /* 0x1C */
    float f20;          /* 0x20 */
    float f24;          /* 0x24 */
    float f28;          /* 0x28 */
    float f2C;          /* 0x2C */
    u8 b30[0xC];        /* 0x30 */
    float f3C;          /* 0x3C */
    float f40;          /* 0x40 */
    u8 pad44[0x8];
    int w4C;            /* 0x4C */
    int w50;            /* 0x50 */
    u8 pad54[0x4];
    int w58;            /* 0x58 */
    int w5C;            /* 0x5C */
    int w60;            /* 0x60 */
    u8 pad64[0x7];
    u8 b6B;             /* 0x6B */
} Ovl09607Part;

typedef struct Ovl09607Task {
    u8 pad00[0x14];
    s16 h14;            /* 0x14 */
    s16 h16;            /* 0x16 */
} Ovl09607Task;

typedef struct Ovl09607Work {
    u8 pad00[0x2B40];
    float q2B40[4];     /* 0x2B40 */
} Ovl09607Work;

extern u8 D_01B0BB70[];
extern Ovl09607Work *D_01B0BC98;

float func_002B3DB0(float a0);
float func_002B3DF8(float a0);
void func_002DCE08(float *a0, float *a1, float *a2);
void func_002DD128(float *a0);
void func_002DD318(float *a0, float *a1, float a2);

float func_01B04E20(int a0);
void func_01B04E70(int a0, int a1, int a2, float *a3);
void func_01B07010(void *a0);
int *func_01B07880(void *a0, int a1);
void func_01B086B8(void *a0, int a1);
Ovl09607Part *func_01B0B1C8(void);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B02A90(void)
{
    float mat[16];
    float v40[4];
    float v50[4];
    Ovl09607Work *w = D_01B0BC98;
    int i;

    v50[0] = 0.0f;
    v50[1] = 0.0f;
    v50[3] = 1.0f;

    for (i = 0; i < 8; i++) {
        Ovl09607Part *p = func_01B0B1C8();
        if (p == 0) {
            break;
        }
        func_01B086B8(p->b30, *func_01B07880(D_01B0BB70, 5));
        copy_vec(p->pos, w->q2B40);
        func_002DD128(mat);
        func_002DD318(mat, mat, func_002B3DB0(3.1415927f));
        v50[2] = func_002B3DB0(80.0f);
        func_002DCE08(v40, mat, v50);
        p->pos[0] += v40[0];
        p->pos[1] += func_002B3DB0(40.0f);
        p->pos[2] += v40[2];
        p->f10 = v40[0] * (func_002B3DF8(0.01f) + 0.03f);
        p->f14 = -func_002B3DF8(5.0f);
        p->f18 = v40[2] * (func_002B3DF8(0.01f) + 0.03f);
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = p->f10 * -0.01f;
        p->f24 = 0.1f;
        p->f28 = p->f18 * -0.01f;
        p->f2C = 1.0f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.15f;
        p->f40 = 0.5f;
        p->w58 = 0x40;
        p->w5C = 0;
        p->w4C = 0x40;
        p->w50 = 0x40;
        p->b6B = 0;
        p->w60 = 0;
    }
}

void func_01B02CE0(Ovl09607Task *a0)
{
    float v[4][4];
    float (*vp)[4];
    float y;
    int i;

    if (a0->h14 > 0) {
        a0->h14--;
        return;
    }
    a0->h16--;
    if (a0->h16 <= 0) {
        func_01B07010(a0);
        return;
    }

    func_01B04E70(-1, 0x11, 0, v[0]);
    func_01B04E70(-1, 0x37, 0, v[1]);
    func_01B04E70(-1, 0x92, 0, v[2]);
    func_01B04E70(-1, 0xA3, 0, v[3]);

    y = func_01B04E20(-1) - 2.0f;
    vp = v;
    for (i = 0; i < 2; vp++, i++) {
        Ovl09607Part *p;
        if ((*vp)[1] < y) {
            continue;
        }
        p = func_01B0B1C8();
        if (p == 0) {
            break;
        }
        func_01B086B8(p->b30, *func_01B07880(D_01B0BB70, 9));
        copy_vec(p->pos, *vp);
        p->pos[0] += func_002B3DB0(1.0f);
        p->pos[1] = y - 1.0f;
        p->pos[2] += func_002B3DB0(1.0f);
        p->f10 = func_002B3DB0(0.15f);
        p->f14 = func_002B3DB0(0.04f) + -0.08f;
        p->f18 = func_002B3DB0(0.15f);
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = 0.0f;
        p->f24 = 0.0001f;
        p->f28 = 0.0f;
        p->f2C = 1.0f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.35f;
        p->w4C = 0x20;
        p->w50 = 0x20;
        p->b6B = 0;
        p->w60 = 0;
    }
}
