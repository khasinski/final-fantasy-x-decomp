#include "common.h"

typedef struct {
    float v[4];
} Vec4;

typedef struct {
    u8 pad0[0x750];
    Vec4 v750;           /* 0x750 */
    Vec4 v760;           /* 0x760 */
    Vec4 v770;           /* 0x770 */
    Vec4 v780;           /* 0x780 */
    u8 pad790[0x20];
    Vec4 v7B0;           /* 0x7B0 */
    Vec4 v7C0;           /* 0x7C0 */
    u8 pad7D0[0x180];
    float f950;          /* 0x950 */
    int w954;            /* 0x954 */
    int w958;            /* 0x958 */
    int w95C;            /* 0x95C */
    int w960;            /* 0x960 */
    int w964;            /* 0x964 */
    int w968;            /* 0x968 */
    int w96C;            /* 0x96C */
    int w970;            /* 0x970 */
    int w974;            /* 0x974 */
    int w978;            /* 0x978 */
    int w97C;            /* 0x97C */
    int w980;            /* 0x980 */
    u8 targets[0x10];    /* 0x984 */
} Sub9435;

typedef struct {
    u8 pad0[0x280];
    Sub9435 sub;         /* 0x280 */
} Work9435;

typedef struct {
    Vec4 pos;            /* 0x00 */
    Vec4 vel;            /* 0x10 */
    Vec4 acc;            /* 0x20 */
    u8 pad30[0xC];
    float f3C;           /* 0x3C */
    u8 pad40[0xC];
    int w4C;             /* 0x4C */
    int w50;             /* 0x50 */
} Part9435;

extern Work9435 *D_01B09248;
extern u8 D_01B0ED00[];

extern void func_001B60A8(int);
extern void func_001CE540(int);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void *func_002B49A0(void *, int, int);

extern void func_01B02BD8(int, Vec4 *, int);
extern void func_01B02D08(int, Vec4 *);
extern void func_01B03700(int, int);
extern void func_01B03F98(Vec4 *);
extern int func_01B03FC8(u8 *);
extern float func_01B06070(float, float, float, float, float, float);
extern float func_01B06410(Vec4 *, Vec4 *);
extern void func_01B068C0(void *, void *);
extern Part9435 *func_01B08C40(void);

int func_01B01E48(Sub9435 *sub)
{
    Vec4 pos;

    func_01B02BD8(-1, &pos, 0);
    return func_01B06410(&pos, &sub->v770) < 30.0f;
}

int func_01B01EA0(Sub9435 *sub)
{
    Vec4 pos;

    func_01B02BD8(-1, &pos, 0);
    return func_01B06410(&pos, &sub->v750) < 30.0f;
}

void func_01B01EF8(void)
{
    Work9435 *w = D_01B09248;
    Sub9435 *sub = &w->sub;

    sub->w95C = func_01B03FC8(sub->targets);
    sub->w958 = 0;
    sub->w96C = 0;
    sub->w980 = 0;
    if (sub->w970 != -1) {
        sub->w96C = 3;
    } else {
        func_001B60A8(1);
    }
    func_001CE540(0);
    func_01B03700(-1, 1);
}

void func_01B01F68(Vec4 *pos)
{
    Sub9435 *sub = &D_01B09248->sub;

    if (sub->w978 == 1) {
        Vec4 center;
        func_01B03F98(&center);
        if (func_01B06410(&center, pos) >= sub->f950 - 2.0f) {
            return;
        }
    }
    func_01B02D08(-1, pos);
}

int func_01B01FF0(Sub9435 *sub)
{
    Vec4 pos;

    if (sub->w964 == 0 || sub->w960 <= 0) {
        return 1;
    }
    func_01B02BD8(-1, &pos, 0);
    pos.v[0] += sub->v780.v[0];
    pos.v[2] += sub->v780.v[2];
    func_01B01F68(&pos);
    sub->w960--;
    return sub->w960 <= 0;
}

void func_01B02078(void)
{
    Vec4 pos;
    void *tex;
    int i;

    tex = func_002B49A0(D_01B0ED00, 9, 0);
    func_01B02BD8(-1, &pos, 3);
    pos.v[1] -= 2.0f;
    for (i = 0; i < 1; i++) {
        Part9435 *p = func_01B08C40();
        if (p == 0) {
            break;
        }
        func_01B068C0(&p->pad30, tex);
        p->pos.v[0] = pos.v[0] + func_002B3DB0(5.0f);
        p->pos.v[1] = pos.v[1];
        p->pos.v[2] = pos.v[2] + func_002B3DB0(5.0f);
        p->pos.v[3] = 1.0f;
        p->vel.v[0] = func_002B3DB0(0.25f);
        p->vel.v[1] = -func_002B3DF8(0.25f);
        p->vel.v[2] = func_002B3DB0(0.25f);
        p->vel.v[3] = func_002B3DB0(3.1415927f);
        p->acc.v[0] = 0.0f;
        p->acc.v[1] = 0.01f;
        p->acc.v[2] = 0.0f;
        p->acc.v[3] = 1.0f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.4f;
        p->w4C = 0x20;
        p->w50 = 0;
    }
}

int func_01B02220(Sub9435 *sub)
{
    Vec4 pos;
    float t;
    int i;

    if (sub->w960 > 0) {
        sub->w960--;
    }
    t = (float)sub->w960 / (float)sub->w964;
    for (i = 0; i < 3; i++) {
        float d = sub->v7C0.v[i] - sub->v7B0.v[i];
        pos.v[i] = sub->v7B0.v[i] + func_01B06070(d, d * 1.1f, d * 0.8f, d * 0.4f, 0.0f, t);
    }
    func_01B01F68(&pos);
    if (sub->w960 < 20) {
        func_01B02078();
    }
    return sub->w960 <= 0;
}
