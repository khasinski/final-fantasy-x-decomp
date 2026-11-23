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
    int head;
    int steps;
} OvlTrail;

typedef struct {
    u8 pad00[4];
    u8 rgba[4];
    u8 pad08[8];
    void *mat;
    void *w14;
    u8 pad18[4];
    void *w1C;
} OvlDraw;

extern OvlDraw D_01B00F20;

extern s32 func_00116068(void);
extern void func_01B06120(void *, void *);
extern void func_002DD038(void *, void *, void *);
extern void func_002DD998(void *, void *, float);
extern void func_002DD020(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void *func_002CD590(void *, void *);

void func_01B08A00(OvlTrail *tr, Vec4 *basis, Vec4 *curPos) {
    Vec4 mat0[4];
    Vec4 mat1[4];
    Vec4 mat2[4];
    Vec4 p0;
    Vec4 diff;
    Vec4 interp;
    OvlDraw *draw;
    int remain;
    Vec4 *m1 = mat1;
    Vec4 *m2 = mat2;
    int i;
    int idx;
    float acc;
    float segLen;
    TrailRes *res;
    TrailFrame *fr;
    TrailFrame *cur;

    func_01B06120(m1, m2);
    res = tr->res;
    fr = &res->frames[tr->frame];
    if (func_00116068() == 0 && tr->frame <= 0) {
        cur = &res->frames[0];
    } else if (func_00116068() == 0) {
        cur = fr;
    } else if (tr->active == 0) {
        cur = fr;
    } else {
        tr->timer -= 512;
        if (tr->timer <= 0) {
            tr->frame++;
            if (tr->frame >= res->count) {
                if (fr->b04 & 0x80) {
                    tr->frame = 0;
                } else {
                    tr->frame--;
                    tr->active = 0;
                    cur = fr;
                    goto done_anim;
                }
            }
            fr = &res->frames[tr->frame];
            tr->timer = fr->h02;
        }
        cur = fr;
    }
done_anim:
    draw = &D_01B00F20;
    draw->mat = mat0;
    draw->w1C = 0;
    if (func_00116068() != 0) {
        int h = tr->head + 1;
        tr->head = h;
        if (h >= 32) {
            tr->head = 0;
        }
    }
    {
        Vec4 *dst = (Vec4 *)((u32)(tr->head << 4) + (u32)tr + 16);
        MMI_COPY_LQ_A3(dst, curPos);
        MMI_COPY_SQ_A3(dst);
    }

    remain = 32;
    acc = 0.0f;
    segLen = 0.0f;
    idx = tr->head;
    for (i = 0; i < tr->steps; i++) {
        if (acc >= segLen) {
            int prev = idx - 1;
            register u32 lenBits __asm__("$7");
            if (prev < 0) {
                prev = 31;
            }
            acc -= segLen;
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
            func_002DCE08(&mat0[3], m2, &interp);
            func_002DCE38(mat0, m1, mat0);
        }

        if (draw->rgba[3] != 0) {
            draw->w14 = func_002CD590((u8 *)tr->res + cur->h00, draw);
        }
    }
}
