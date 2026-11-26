#include "common.h"

typedef struct {
    int w00;
    int count;
} Info510;

typedef struct {
    u8 pad00[0x30];
    float pos[4];
    float rot[4];
    float base[4];
    float ang[4];
    float off[4];
    float speed;
    int timer;
    u8 pad88[0x08];
} Elem90;

extern Info510 D_01B00510;
extern Elem90 D_01B06C70[];
extern int D_01B0715C;
extern int D_01B07160;

extern void func_002DCE08(float *, float *, float *);
extern void func_002DD128(float *);
extern void func_002DD1C8(float *, float *, float);
extern void func_002DD270(float *, float *, float);
extern void func_002DD318(float *, float *, float);
extern void func_01B03B68(int, void *, float *);

static inline void wrap_angle(float *p, float d)
{
    float v = *p + d;
    if (v > 3.1415927f) {
        v -= 6.2831855f;
    } else if (v < -3.1415927f) {
        v += 6.2831855f;
    }
    *p = v;
}

int func_01B01858(void)
{
    float m0[16];
    float m1[16];
    float tmp[4];
    Elem90 *e;
    int i;

    if (D_01B0715C > 0) {
        D_01B0715C--;
        return 0;
    }

    if (D_01B07160 > 0) {
        D_01B07160--;
    }
    if (D_01B07160 == 0) {
        return 1;
    }

    e = D_01B06C70;
    func_002DD128(m1);

    for (i = 0; i < D_01B00510.count; i++, e++) {
        if (e->timer > 0) {
            e->timer--;
            e->speed += 0.012566372f;
        }

        wrap_angle(&e->rot[2], e->speed);
        wrap_angle(&e->ang[2], e->speed);

        if (D_01B07160 >= 31) {
            e->off[2] += 1.5f;
        } else {
            e->off[2] += ((float)D_01B07160 / 30.0f) * 1.5f;
        }

        func_002DD1C8(m0, m1, e->ang[2]);
        func_002DD270(m0, m0, e->ang[0]);
        func_002DD318(m0, m0, e->ang[1]);
        func_002DCE08(tmp, m0, e->off);
        func_01B03B68(i, e, e->rot);
        e->pos[0] = e->base[0] + tmp[0];
        e->pos[1] = e->base[1] + tmp[1];
        e->pos[2] = e->base[2] + tmp[2];
    }

    return 0;
}
