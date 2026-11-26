#include "common.h"

typedef struct {
    int w00;
    int count;
} Info968;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float vecD0[4];
} Sub720;

typedef struct {
    u8 pad00[0x720];
    Sub720 sub720;
    u8 pad800[0x5520];
    u8 sub5D20[0x40];
    u8 sub5D60[0x518];
    float f6278;
} OvlState;

extern Info968 D_01B00968;
extern u8 D_01B0A350[];
extern OvlState *D_01B0A478;

extern void func_00118098(int, int);
extern void func_01B03D80(int, int, int, void *);
extern void func_01B04308(int, int);
extern void func_01B04A60(int, float, float, float, int);
extern void func_01B06200(void *, void *, int, int, int, int, float);
extern void func_01B09B70(void *, int, int, float, float);

void func_01B026B0(void)
{
    OvlState *s = D_01B0A478;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B09B70(s->sub5D20, 0x14, 0, 1.0f, 0.5f);
}

void func_01B02708(void *a0)
{
    func_01B03D80(-1, 0x8A, 0, a0);
}

void func_01B02720(void)
{
    int i;

    for (i = 0; i < D_01B00968.count; i++) {
        func_01B04A60(i, 0.7f, 0.7f, 1.4f, 1);
    }
}

void func_01B027A8(void)
{
    OvlState *s = D_01B0A478;
    int i;

    for (i = 0; i < D_01B00968.count; i++) {
        func_01B04A60(i, 1.0f, 1.0f, 1.0f, 0x3C);
    }
    func_01B09B70(s->sub5D60, 0x1E, 0x32, 0.5f, 1.0f);
}

void func_01B02858(void)
{
    int i;

    for (i = 0; i < D_01B00968.count; i++) {
        func_01B04308(i, 0);
    }
}

void func_01B028B8(void)
{
    int i;

    for (i = 0; i < D_01B00968.count; i++) {
        func_01B04308(i, -1);
    }
}

void func_01B02918(void)
{
    OvlState *s = D_01B0A478;
    Sub720 *m = &s->sub720;
    float ang;

    func_01B06200(D_01B0A350, m, 6, 0, 0, 0, 0.015f);
    func_01B02708(m->vecD0);
    m->fC0 = 0.7853982f;
    ang = s->f6278 + 0.7853982f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    m->fC4 = ang;
    m->vecD0[1] -= 0.5f;
}
