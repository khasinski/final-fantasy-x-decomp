#include "common.h"
#include "vu0.h"

typedef struct {
    float v[4];
} Vec4;

typedef struct {
    u8 pad0[0xC4];
    float fC4;
    u8 padC8[0x8];
    Vec4 vD0;
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0xC];
    int w120;
    u8 pad124[0xC];
} Entry130;

typedef struct {
    Entry130 entries[6]; /* 0x000..0x720 */
    Vec4 v720;           /* 0x720 */
    Vec4 v730;           /* 0x730 */
    Vec4 v740;           /* 0x740 */
    Vec4 v750;           /* 0x750 */
    Vec4 v760;           /* 0x760 */
    Vec4 v770;           /* 0x770 */
    u8 pad780[0x20];
    Vec4 v7A0;           /* 0x7A0 */
    Vec4 v7B0;           /* 0x7B0 */
    Vec4 v7C0;           /* 0x7C0 */
    u8 arr7D0[6][0x40];  /* 0x7D0..0x950 */
    int w950;            /* 0x950 */
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
    u8 targets[0x10];    /* 0x980 */
} Sub9492;

typedef struct {
    u8 pad0[0x280];
    Sub9492 sub;         /* 0x280 */
    u8 padC10[0x124];
    int wD34;            /* 0xD34 */
} Work9492;

typedef struct {
    Vec4 pos;            /* 0x00 */
    Vec4 vel;            /* 0x10 */
    Vec4 acc;            /* 0x20 */
    u8 pad30[0xC];
    float f3C;           /* 0x3C */
    u8 pad40[0xC];
    int w4C;             /* 0x4C */
    int w50;             /* 0x50 */
    u8 pad54[0x17];
    u8 b6B;              /* 0x6B */
} Part9492;

typedef struct {
    u8 pad0[0x56];
    u8 b56;
} TaskArg9492;

extern u8 D_01B00540[];
extern u8 D_01B005A0[];
extern u8 D_01B005C0[];
extern u8 D_01B005E0[];
extern u8 D_01B00600[];
extern u8 D_01B00620[];
extern u8 D_01B00630[];
extern u8 D_01B08FD0[];
extern u8 D_01B09078[];
extern Work9492 *D_01B09098;
extern u8 D_01B0EA20[];

extern void func_001B60A8(int);
extern void func_001CE540(int);
extern void func_00297CE8(int);
extern float func_002B3DB0(float);

extern void func_01B01610(Sub9492 *);
extern void func_01B01B70(Sub9492 *);
extern int func_01B027E0(int);
extern void func_01B029C0(int, float);
extern void func_01B02A30(int, Vec4 *, int);
extern void func_01B02B60(int, Vec4 *);
extern void func_01B03558(int, int);
extern void func_01B03DF0(Vec4 *);
extern int func_01B03E20(u8 *);
extern void func_01B04418(int, void *, void *);
extern void func_01B04770(void *, int);
extern void func_01B04A40(void *, int, Vec4 *, int);
extern void func_01B04AD8(void *, void *, void *);
extern void func_01B04CE0(void *, int, int);
extern void func_01B05350(void *, Entry130 *, int, int, int, void *, float);
extern void **func_01B058E0(void *, int);
extern void func_01B05910(void);
extern float func_01B05EC8(float, float, float, float, float, float);
extern void func_01B06080(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B06188(Vec4 *, Vec4 *, Vec4 *);
extern float func_01B06228(Vec4 *, Vec4 *);
extern float func_01B06268(Vec4 *, Vec4 *);
extern float func_01B06358(float, float);
extern void func_01B06718(void *, void *);
extern Part9492 *func_01B08A98(void);

static inline void copy_vec(Vec4 *dst, const Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int func_01B01C88(Sub9492 *sub)
{
    Vec4 pos;

    func_01B02A30(-1, &pos, 0);
    return func_01B06228(&pos, &sub->v770) < 30.0f;
}

int func_01B01CE0(Sub9492 *sub)
{
    Vec4 pos;

    func_01B02A30(-1, &pos, 0);
    return func_01B06228(&pos, &sub->v750) < 30.0f;
}

void func_01B01D38(void)
{
    Work9492 *w = D_01B09098;
    Sub9492 *sub = &w->sub;

    sub->w958 = func_01B03E20(sub->targets);
    sub->w954 = 0;
    sub->w968 = 0;
    sub->w97C = 0;
    if (sub->w96C != -1) {
        sub->w968 = 3;
    } else {
        func_001B60A8(1);
    }
    func_001CE540(0);
    func_01B03558(-1, 1);
}

void func_01B01DA8(Vec4 *pos)
{
    Work9492 *w = D_01B09098;

    if (w->sub.w974 == 1) {
        Vec4 center;
        func_01B03DF0(&center);
        if (func_01B06268(&center, pos) >= 98.0f) {
            return;
        }
    }
    func_01B02B60(-1, pos);
}

int func_01B01E18(Sub9492 *sub)
{
    Vec4 pos;
    Vec4 rot;
    Vec4 ofs;

    if (sub->w960 == 0 || sub->w95C <= 0) {
        return 1;
    }
    func_01B02A30(-1, &pos, 0);
    func_01B06080(&rot, &pos, &sub->v7A0);
    rot.v[2] = 0.0f;
    ofs.v[0] = 0.0f;
    ofs.v[1] = 0.0f;
    ofs.v[2] = -3.5f;
    ofs.v[3] = 1.0f;
    func_01B06188(&rot, &pos, &ofs);
    func_01B01DA8(&pos);
    sub->w95C--;
    return sub->w95C <= 0;
}

void func_01B01ED0(void)
{
    Vec4 pos;
    void *tex;
    int i;

    tex = *func_01B058E0(D_01B08FD0, 3);
    func_01B02A30(-1, &pos, 0);
    for (i = 0; i < 1; i++) {
        Part9492 *p = func_01B08A98();
        if (p == 0) {
            break;
        }
        func_01B06718(&p->pad30, tex);
        p->pos.v[0] = pos.v[0] + func_002B3DB0(5.0f);
        p->pos.v[1] = pos.v[1];
        p->pos.v[2] = pos.v[2] + func_002B3DB0(5.0f);
        p->pos.v[3] = 1.0f;
        p->vel.v[0] = func_002B3DB0(0.25f);
        p->vel.v[1] = -(func_002B3DB0(0.5f) + 0.2f);
        p->vel.v[2] = func_002B3DB0(0.25f);
        p->vel.v[3] = func_002B3DB0(3.1415927f);
        p->acc.v[0] = 0.0f;
        p->acc.v[1] = -0.02f;
        p->acc.v[2] = 0.0f;
        p->acc.v[3] = 1.0f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.02f;
        p->w4C = 0x18;
        p->w50 = 0x18;
        p->b6B = 0;
    }
}

int func_01B02078(Sub9492 *sub)
{
    Vec4 pos;
    float t;
    int i;

    if (sub->w95C > 0) {
        sub->w95C--;
    }
    t = (float)sub->w95C / (float)sub->w960;
    for (i = 0; i < 3; i++) {
        float d = sub->v7C0.v[i] - sub->v7B0.v[i];
        pos.v[i] = sub->v7B0.v[i] + func_01B05EC8(d, d * 1.1f, d * 0.8f, d * 0.4f, 0.0f, t);
    }
    func_01B01DA8(&pos);
    if (sub->w95C < 20) {
        func_01B01ED0();
    }
    return sub->w95C <= 0;
}
