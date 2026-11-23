#include "common.h"

typedef struct S60A0Entry {
    s16 s00;
    u16 u02;
    s8 b04;
    u8 pad05[3];
} S60A0Entry;

typedef struct S60A0Item {
    u8 *p00;
    s32 s04;
    s16 s08;
    s16 s0A;
    u8 pad0C[4];
    float pos[4];
    void (*cb)(struct S60A0Item *);
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    float f44;
    float f48;
    float f4C;
    s32 s50;
    s32 s54;
    s32 s58;
    u8 c0[4];
    u8 c1[4];
    s32 s64;
    u16 u68;
    u8 pad6A[6];
} S60A0Item; /* size 0x70 */

typedef struct S60A0Draw {
    u8 pad00[4];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8 pad08[8];
    void *p10;
    s32 v14;
    u8 pad18[4];
    s32 v1C;
} S60A0Draw;

extern S60A0Item *D_01B0CC60;
extern s32 D_01B0CC68;
extern S60A0Draw D_01B006D0;

extern void func_01B02EA8(float (*m1)[4], float (*m2)[4]);
extern void func_002DD128(float (*m)[4]);
extern void func_002DD1C8(float (*dst)[4], float (*src)[4], float ang);
extern void func_002DCE08(float *dst, float (*m)[4], float *v);
extern void func_002DCE38(float (*dst)[4], float (*m1)[4], float (*m2)[4]);
extern s32 func_002CD590(void *a0, S60A0Draw *a1);

static inline double my_fabs(double x)
{
    if (x < 0.0) {
        x = -x;
    }
    return x;
}

static inline void wrap_angle(float *ang, float delta)
{
    float a = *ang + delta;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *ang = a;
}

void func_01B060A0(void)
{
    float m00[4][4];
    float m40[4][4];
    float m80[4][4];
    float mC0[4][4];
    S60A0Item *p;
    S60A0Draw *draw_ctx;
    s32 i;

    p = D_01B0CC60;
    func_01B02EA8(m40, m80);
    draw_ctx = &D_01B006D0;
    draw_ctx->p10 = mC0;
    draw_ctx->v1C = 0;

    for (i = 0; i < D_01B0CC68; i++, p++) {
        if (p->s64 != 0) {
            float vy;
            float vx;
            float vz;
            S60A0Entry *ent;

            p->f30 += p->f34;
            vy = p->f28 + p->f30;
            vx = p->f24;
            vz = p->f2C;
            p->pos[0] += vx;
            p->pos[1] += vy;
            p->pos[2] += vz;
            if (p->cb != 0) {
                p->cb(p);
            }
            if (!(p->u68 & 1) && p->pos[1] >= p->f40) {
                float f38;
                if (p->f28 != 0.0f && vy != 0.0f) {
                    float t = 1.0f - (-(p->pos[1] - vy) / vy);
                    p->pos[0] -= p->f24 * t;
                    p->pos[2] -= p->f2C * t;
                }
                vx = p->f24;
                vz = p->f2C;
                p->pos[1] = p->f40;
                f38 = p->f38;
                p->f34 *= f38;
                if (my_fabs(p->f28) < my_fabs(p->f34)) {
                    p->f34 = f38;
                    p->f28 = 0.0f;
                }
                p->f30 = 0.0f;
                p->f24 = vx * p->f3C;
                p->f2C = vz * p->f3C;
            }

            func_002DD128(m00);
            {
                float sc = p->f4C;
                m00[2][2] = sc;
                m00[1][1] = sc;
                m00[0][0] = sc;
            }
            wrap_angle(&p->f44, p->f48);
            func_002DD1C8(mC0, m00, p->f44);
            func_002DCE08(mC0[3], m80, p->pos);
            func_002DCE38(mC0, m40, mC0);

            if (p->s54 > 0) {
                s32 cur = p->s58;
                if (cur < 0) {
                    cur = -cur;
                }
                draw_ctx->r = (p->c1[0] * cur + p->c0[0] * (p->s54 - cur)) / p->s54;
                draw_ctx->g = (p->c1[1] * cur + p->c0[1] * (p->s54 - cur)) / p->s54;
                draw_ctx->b = (p->c1[2] * cur + p->c0[2] * (p->s54 - cur)) / p->s54;
                draw_ctx->a = (p->c1[3] * cur + p->c0[3] * (p->s54 - cur)) / p->s54;
                if (++p->s58 > p->s54) {
                    p->s54 = 0;
                }
            } else {
                draw_ctx->a = 0x80;
                draw_ctx->b = 0x80;
                draw_ctx->g = 0x80;
                draw_ctx->r = 0x80;
            }

            ent = (S60A0Entry *)(p->p00 + 0x10 + p->s08 * 8);
            if (p->s04 != 0) {
                p->s0A -= 0x200;
                if (p->s0A <= 0) {
                    p->s08++;
                    if (p->s08 >= *(s16 *)(p->p00 + 6)) {
                        if (ent->b04 & 0x80) {
                            p->s08 = 0;
                        } else {
                            p->s08--;
                            p->s04 = 0;
                            goto skip_timer;
                        }
                    }
                    ent = (S60A0Entry *)(p->p00 + 0x10 + p->s08 * 8);
                    p->s0A = ent->u02;
                }
            }
        skip_timer:

            {
                s32 draw = 1;
                if (p->s50 < 0) {
                    draw = p->s04;
                }
                if (draw == 1) {
                    draw_ctx->v14 = func_002CD590(p->p00 + ent->s00, draw_ctx);
                } else {
                    p->s50 = 1;
                }
            }
            if (p->s50 > 0) {
                if (--p->s50 == 0) {
                    p->s64 = 0;
                }
            }
        }
    }
}
