#include "common.h"
#include "vu0.h"

typedef float Mtx44[4][4];

typedef struct AnimEntry {
    s16 off;
    u16 dur;
    s8 flags;
    u8 pad[3];
} AnimEntry;

typedef struct AnimState {
    u8 *data;
    s32 playing;
    s16 frame;
    s16 timer;
} AnimState;

typedef struct Particle {
    float pos[4];       /* 0x00 */
    float vel[3];       /* 0x10 */
    float rot;          /* 0x1C */
    float acc[3];       /* 0x20 */
    float accScale;     /* 0x2C */
    AnimState anim;     /* 0x30 */
    float scale0;       /* 0x3C */
    float scale1;       /* 0x40 */
    float zOffset;      /* 0x44 */
    float rotSpeed;     /* 0x48 */
    s32 life;           /* 0x4C */
    s32 colorDur;       /* 0x50 */
    s32 colorCur;       /* 0x54 */
    s32 scaleDur;       /* 0x58 */
    s32 scaleCur;       /* 0x5C */
    s32 delay;          /* 0x60 */
    u8 col0[4];         /* 0x64 */
    u8 col1[4];         /* 0x68 */
    s32 active;         /* 0x6C */
    u16 flags;          /* 0x70 */
    u8 pad72[0xE];
} Particle; /* size 0x80 */

typedef struct DrawCtx {
    u32 w00;
    u8 col[4];          /* 0x04 */
    u32 w08;
    u32 w0C;
    void *p10;          /* 0x10 */
    s32 w14;            /* 0x14 */
    u32 w18;
    void *p1C;          /* 0x1C */
} DrawCtx;

extern Particle *D_01B0A190;
extern s32 D_01B0A198;
extern s32 D_01B0A19C;
extern DrawCtx D_01B002F0;

s32 func_0011ABB8(void);
void func_01B02600(Mtx44 m1, Mtx44 m2);
void func_002DD128(Mtx44 m);
void func_002DD998(float *dst, float *src, float s);
void func_002DD1C8(Mtx44 dst, Mtx44 src, float ang);
void func_002DCE08(float *dst, Mtx44 m, float *v);
void func_002DD0C0(Mtx44 dst, Mtx44 src);
void func_002DCE38(Mtx44 dst, Mtx44 m1, Mtx44 m2);
s32 func_002CD590(u8 *p, DrawCtx *ctx);

static inline void add_rot(float *r, float d)
{
    float v = *r + d;
    if (v > 3.1415927f) {
        v -= 6.2831855f;
    } else if (v < -3.1415927f) {
        v += 6.2831855f;
    }
    *r = v;
}

void func_01B04D08(void)
{
    Mtx44 mtx0;
    Mtx44 mtx1;
    Mtx44 mtx2;
    Mtx44 mtx3;
    Mtx44 mtx4;
    Particle *p;
    DrawCtx *ctx;
    s32 i;
    s32 active;

    if (func_0011ABB8() != 0) {
        return;
    }

    p = D_01B0A190;
    func_01B02600(mtx1, mtx2);
    ctx = &D_01B002F0;
    ctx->p10 = mtx3;
    func_002DD128(mtx0);

    active = 0;
    for (i = 0; i < D_01B0A198; i++, p++) {
        float sc;
        float rot;
        AnimState *anim;
        u8 *data;
        AnimEntry *entry;
        s16 prevFrame;

        if (!p->active) {
            continue;
        }
        active++;
        if (p->delay > 0) {
            p->delay--;
            continue;
        }

        if (p->flags & 2) {
            func_002DD998(p->acc, p->acc, p->accScale);
        }

        VU0_LQC2(1, 0, p->vel);
        VU0_LQC2(2, 0, p->acc);
        VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, p->vel);

        VU0_LQC2(1, 0, p->pos);
        VU0_LQC2(2, 0, p->vel);
        VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, p->pos);

        sc = p->scale0;
        if (p->scaleDur > 0) {
            float s1 = p->scale1;
            float t = (float)p->scaleCur / (float)p->scaleDur;
            p->scaleCur++;
            sc *= (1.0f - t) + s1 * t;
            if (p->scaleCur > p->scaleDur) {
                p->scaleDur = 0;
            }
        } else {
            sc *= p->scale1;
        }
        mtx0[2][2] = sc;
        mtx0[1][1] = sc;
        mtx0[0][0] = sc;

        add_rot(&p->rot, p->rotSpeed);

        func_002DD1C8(mtx3, mtx0, p->rot);
        func_002DCE08(mtx3[3], mtx2, p->pos);

        ctx->p1C = 0;
        if (p->flags & 1) {
            func_002DD0C0(mtx4, mtx3);
            mtx4[3][2] += p->zOffset;
            func_002DCE38(mtx4, mtx1, mtx4);
            ctx->p1C = mtx4;
        }
        func_002DCE38(mtx3, mtx1, mtx3);

        if (p->colorDur > 0) {
            s32 cur = p->colorCur;
            if (cur < 0) {
                cur = -cur;
            }
            ctx->col[0] = (p->col1[0] * cur + p->col0[0] * (p->colorDur - cur)) / p->colorDur;
            ctx->col[1] = (p->col1[1] * cur + p->col0[1] * (p->colorDur - cur)) / p->colorDur;
            ctx->col[2] = (p->col1[2] * cur + p->col0[2] * (p->colorDur - cur)) / p->colorDur;
            ctx->col[3] = (p->col1[3] * cur + p->col0[3] * (p->colorDur - cur)) / p->colorDur;
            if (++p->colorCur > p->colorDur) {
                p->colorDur = 0;
            }
        } else {
            *(u32 *)ctx->col = *(u32 *)p->col1;
        }

        anim = &p->anim;
        data = anim->data;
        entry = (AnimEntry *)(data + ((anim->frame << 3) + 0x10));
        {
            u16 prev = anim->frame;
            if (anim->playing != 0) {
                anim->timer -= 0x200;
                if (anim->timer <= 0) {
                    anim->frame = prev + 1;
                    if (anim->frame >= *(s16 *)(data + 6)) {
                        if (entry->flags & 0x80) {
                            anim->frame = 0;
                        } else {
                            anim->frame = prev;
                            anim->playing = 0;
                            goto after_anim;
                        }
                    }
                    entry = (AnimEntry *)(data + ((anim->frame << 3) + 0x10));
                    anim->timer = entry->dur;
                }
            }
        }
after_anim:
        {
            s32 draw = 1;
            if (p->life < 0) {
                draw = p->anim.playing;
            }
            if (draw == 1) {
                ctx->w14 = func_002CD590(data + entry->off, ctx);
            } else {
                p->life = 1;
            }
        }
        if (p->life > 0) {
            if (--p->life == 0) {
                p->active = 0;
            }
        }
    }

    D_01B0A19C = active;
}
