#include "common.h"

typedef struct {
    u8 pad00[0x76];
    u16 h76;
    u8 pad78[0x48];
    float rot[3];
    u8 padCC[0x4];
    float pos[3];
} Obj20;

typedef struct {
    float drot[3];
    u8 pad0C[0x4];
    float vx;
    float vy;
    float vz;
    u8 pad1C[0x4];
    Obj20 *p20;
    float accY;
    float grav;
    float floorY;
    float drag;
    float bounce;
    float jitter;
    s32 timer;
    s32 state;
    u8 pad44[0xC];
} Coin50;

extern Coin50 *D_01B0612C;
extern u8 D_01B06540[];

extern void func_01B04810(void *, void *);
extern float func_002B3DB0(float);

static inline double my_fabs(double x)
{
    return (x < 0.0) ? -x : x;
}

static inline void wrap_add(float *p, float d)
{
    float a = *p + d;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *p = a;
}

void ovl_09062_1250(void)
{
    Coin50 *c = D_01B0612C;
    s32 i;
    register s32 div20 __asm__("$21") = 20;

    for (i = 0; i < 24; i++, c++) {
        Obj20 *o;
        u16 alpha;
        float vy;

        if (c->timer == 0) {
            continue;
        }
        o = c->p20;
        if (c->state == 1) {
            if (--c->timer == 0) {
                func_01B04810(D_01B06540, o);
                continue;
            }
            alpha = (u16)((c->timer << 12) / div20);
        } else {
            alpha = 0x1000;
        }
        o->h76 = alpha;

        wrap_add(&o->rot[0], c->drot[0]);
        wrap_add(&o->rot[1], c->drot[1]);
        wrap_add(&o->rot[2], c->drot[2]);

        c->accY += c->grav;
        vy = c->vy + c->accY;
        o->pos[0] += c->vx;
        o->pos[1] += vy;
        o->pos[2] += c->vz;
        c->vx *= c->drag;
        c->vz *= c->drag;

        if (o->pos[1] >= c->floorY) {
            if (c->vy != 0.0f && vy != 0.0f) {
                float t = (float)(1.0 - my_fabs((double)(o->pos[1] - c->floorY)) / my_fabs((double)vy));
                o->pos[0] -= c->vx * t;
                o->pos[2] -= c->vz * t;
            }
            o->pos[1] = c->floorY;
            if (my_fabs((double)c->jitter) > 0.01) {
                c->vx += func_002B3DB0(c->jitter);
                c->vz += func_002B3DB0(c->jitter);
                c->jitter *= 0.5f;
            }
            c->drot[0] = func_002B3DB0(0.47123894f);
            c->drot[1] = func_002B3DB0(0.47123894f);
            c->drot[2] = func_002B3DB0(0.47123894f);
            c->vy = -vy * c->bounce;
            if (my_fabs((double)c->vy) < (double)c->grav) {
                c->vx *= 0.5f;
                c->vz *= 0.5f;
                c->vy = 0.0f;
                c->grav = 0.0f;
            }
            c->accY = 0.0f;
            c->state = 1;
        }
    }
}
