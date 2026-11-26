#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Timer9716;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    u_long128 qD0;
    float fE0;
    float fE4;
    float fE8;
} Part9716;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
} Sub280_9716;

typedef struct {
    u8 pad000[0x264];
    float f264;
    u8 pad268[0x8];
    u_long128 q270;
    Sub280_9716 sub280;
    u8 pad31C[0x2AC];
    int w5C8;
} Obj9716_2;

extern u8 D_01B07E08[];
extern Obj9716_2 *D_01B07ED0;
extern void *D_01B07ED8;

extern int func_002EFD78(void);
extern Part9716 *func_01B07D70(void);
extern float func_002B3DB0(float);
extern void func_01B04BB0(void *, void *, int, int, int, int, float);
extern int func_01B020D8(int);
extern void func_002A3CA0(int, void *, int, int, int, int);
extern void func_01B048D0(void *);
extern void func_01B07BB0(void *, int);
extern void func_00117D58(int, int);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

static inline int lerp_int(int x, int t, int d)
{
    return (t * x) / d;
}

void func_01B01AD8(Timer9716 *a0)
{
    Obj9716_2 *s1 = D_01B07ED0;

    if (--a0->w2C <= 0) {
        Part9716 *p;

        a0->w2C = func_002EFD78() % 6 + 5;
        p = func_01B07D70();
        if (p != 0) {
            float f = func_002B3DB0(0.2f);
            func_01B04BB0(D_01B07E08, p, 1, 0, 0, 0, (f + 1.0f) * 0.3f);
            copy_vec(&p->qD0, &s1->q270);
            p->fC4 = s1->f264;
            p->fE0 = func_002B3DB0(30.0f) + 30.0f;
            p->fE4 = func_002B3DB0(40.0f) + -60.0f;
            p->fE8 = func_002B3DB0(30.0f) + 30.0f;
        }
    }
}

void func_01B01C00(Timer9716 *a0)
{
    Obj9716_2 *s1 = D_01B07ED0;

    if (--a0->w2C <= 0) {
        Part9716 *p;

        a0->w2C = func_002EFD78() % 6 + 5;
        p = func_01B07D70();
        if (p != 0) {
            float f = func_002B3DB0(0.2f);
            func_01B04BB0(D_01B07E08, p, 0, 0, 0, 0, (f + 1.0f) * 0.3f);
            copy_vec(&p->qD0, &s1->q270);
            p->fC4 = s1->f264;
            p->fE0 = func_002B3DB0(30.0f) + 30.0f;
            p->fE4 = func_002B3DB0(50.0f) + -60.0f;
            p->fE8 = func_002B3DB0(30.0f) + 30.0f;
        }
    }
}

void func_01B01D28(void *a0)
{
    Obj9716_2 *s3 = D_01B07ED0;
    int rem;
    int t;
    int s0;
    int s1;
    int s2;

    rem = s3->w5C8;
    if (rem > 0) {
        rem--;
        s3->w5C8 = rem;
    }

    {
        int d = 80;
        t = d - rem;
        s0 = (t * 256) / d;
        s2 = lerp_int(-64, t, 80);
        s1 = lerp_int(-40, t, 80);
    }

    func_002A3CA0(func_01B020D8(-1), D_01B07ED8, s0, s2, s1, 0);
    if (s3->w5C8 <= 0) {
        func_01B048D0(a0);
    }
}

void func_01B01E18(void)
{
    Sub280_9716 *v0 = &D_01B07ED0->sub280;

    v0->b82 = 0xFF;
    v0->b81 = 0xFF;
    v0->b80 = 0xFF;
    v0->b83 = 0x80;
    v0->b86 = 0xFF;
    v0->b85 = 0xFF;
    v0->b84 = 0xFF;
    v0->b87 = 0;
    v0->w88 = 0;
    v0->b98 = 0x48;
    v0->b99 = 0;
    func_01B07BB0(v0, 0x1E);
    func_00117D58(func_01B020D8(-1), 0);
}
