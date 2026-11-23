#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    s16 h00;
    s16 h02;
    s8 b04;
    u8 pad05[3];
} TrailFrame;

typedef struct {
    u8 pad00[6];
    s16 count;
    u8 pad08[8];
    TrailFrame frames[1];
} TrailRes;

typedef struct {
    TrailRes *res;
    int active;
    s16 frame;
    s16 timer;
    u8 pad0C[4];
    Vec4 pos[32];
    u8 c0[4];
    u8 c1[4];
    float f218;
    float f21C;
    float f220;
    int seed;
    int head;
    int steps;
    s8 flags[32];
} OvlTrail67B8;

typedef struct {
    u8 pad00[4];
    u8 rgba[4];
    u8 pad08[8];
    void *mat;
    void *w14;
    u8 pad18[4];
    void *w1C;
} OvlDraw;

extern OvlDraw D_01B01200;

extern void func_01B089F8(void *, void *);
extern void func_002DD038(void *, void *, void *);
extern void func_002DD998(void *, void *, float);
extern void func_002DD020(void *, void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void *func_002CD590(void *, void *);

void func_01B067B8(OvlTrail67B8 *tr, Vec4 *basis, Vec4 *curPos) {
    Vec4 mat0[4];
    Vec4 mat1[4];
    Vec4 mat2[4];
    Vec4 mat3[4];
    Vec4 p0;
    Vec4 diff;
    Vec4 interp;
    OvlDraw *draw;
    int remain;
    Vec4 *m1 = mat1;
    Vec4 *m2 = mat2;
    int i;
    int idx;
    int seed;
    float segLen;
    float acc;
    TrailRes *res;
    TrailFrame *fr;

    func_01B089F8(m1, m2);
    draw = &D_01B01200;
    draw->mat = mat0;
    draw->w1C = mat3;

    {
        Vec4 *dst = (Vec4 *)((u32)(tr->head << 4) + (u32)tr + 16);
        MMI_COPY_LQ_A3(dst, curPos);
        MMI_COPY_SQ_A3(dst);
    }
    tr->flags[tr->head] = 1;
    idx = tr->head;
    {
        int h = idx + 1;
        tr->head = h;
        if (h >= 32) {
            tr->head = 0;
        }
    }

    remain = 32;
    segLen = 0.0f;
    acc = segLen;
    seed = tr->seed;
    res = tr->res;
    fr = &res->frames[tr->frame];
    if (tr->active != 0) {
        tr->timer -= 512;
        if (tr->timer <= 0) {
            tr->frame++;
            if (tr->frame >= res->count) {
                if (fr->b04 & 0x80) {
                    tr->frame = 0;
                } else {
                    tr->frame--;
                    tr->active = 0;
                    goto done_anim;
                }
            }
            fr = &res->frames[tr->frame];
            tr->timer = fr->h02;
        }
    }
done_anim:
    for (i = 0; i < tr->steps; i++) {
        if (acc >= segLen) {
            int prev = idx - 1;
            register u32 lenBits __asm__("$7");
            if (prev < 0) {
                prev = 31;
            }
            acc -= segLen;
            if (tr->flags[prev] != 1) {
                break;
            }
            MMI_COPY_LQ_A3(&p0, (Vec4 *)((u32)(idx << 4) + (u32)tr + 16));
            MMI_COPY_SQ_A3(&p0);
            func_002DD038(&diff, &tr->pos[prev], &p0);
            VU0_LQC2(1, 0, &diff);
            VU0_OP("vmul.xyz $vf1, $vf1, $vf1");
            VU0_OP("vaddy.x $vf1, $vf1, $vf1");
            VU0_OP("vaddz.x $vf1, $vf1, $vf1");
            VU0_OP("vsqrt Q, $vf1x");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf1, $vf0, Q");
            VU0_QMFC2(lenBits, 1);
            __asm__ volatile("mtc1 %1, %0" : "=f"(segLen) : "r"(lenBits));
            idx--;
            if (idx < 0) {
                idx = 31;
            }
            if (--remain <= 0) {
                break;
            }
            if (segLen == 0.0f) {
                continue;
            }
        }

        seed = (seed * 0x80D + 7) & 0xFFFF;
        draw->rgba[0] = (tr->c1[0] * i + tr->c0[0] * (tr->steps - i)) / tr->steps;
        draw->rgba[1] = (tr->c1[1] * i + tr->c0[1] * (tr->steps - i)) / tr->steps;
        draw->rgba[2] = (tr->c1[2] * i + tr->c0[2] * (tr->steps - i)) / tr->steps;
        draw->rgba[3] = (tr->c1[3] * i + tr->c0[3] * (tr->steps - i)) / tr->steps;

        if (acc >= segLen) {
            MMI_COPY_LQ_A3(&interp, &p0);
            MMI_COPY_SQ_A3(&interp);
        } else {
            func_002DD998(&interp, &diff, acc / segLen);
            func_002DD020(&interp, &p0, &interp);
            acc += tr->f220;
        }

        {
            float t = (float)(i + 1) / (float)tr->steps;
            float scale = tr->f218 * (1.0f - t) + tr->f21C * t;
            interp.w = 1.0f;
            func_002DD128(mat0);
            func_002DD998(&mat0[0], &basis[0], scale);
            func_002DD998(&mat0[1], &basis[1], scale);
            func_002DD998(&mat0[2], &basis[2], scale);
            func_002DD1C8(mat0, mat0, ((float)(seed - 0x7FFF) * (1.0f / 32768.0f)) * 3.1415927f);
            func_002DCE08(&mat0[3], m2, &interp);
            func_002DD0C0(mat3, mat0);
            mat3[3].z += -3.0f;
            func_002DCE38(mat3, m1, mat3);
            func_002DCE38(mat0, m1, mat0);
        }

        if (draw->rgba[3] != 0) {
            int f = (seed % tr->res->count) + tr->frame;
            if (f >= tr->res->count) {
                f -= tr->res->count;
            }
            draw->w14 = func_002CD590((u8 *)tr->res + ((TrailFrame *)((u32)(f << 3) + (u32)tr->res + 16))->h00, draw);
        }
    }
}
