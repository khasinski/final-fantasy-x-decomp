#include "common.h"
#include "vu0.h"

typedef struct Ovl09194Node87D0 Ovl09194Node87D0;
typedef struct Ovl09194Ctx87D0 Ovl09194Ctx87D0;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(Ovl09194Ctx87D0 *);
} Ovl09194Vtbl87D0;

struct Ovl09194Node87D0 {
    Ovl09194Vtbl87D0 *vtbl;     /* 0x00 */
    u8 pad4[4];
    Ovl09194Node87D0 *next;     /* 0x08 */
    u8 padC[4];
    Ovl09194Node87D0 *child;    /* 0x10 */
    u8 *f14;                    /* 0x14 */
    u8 pad18[2];
    u8 tick;                    /* 0x1A */
    u8 pad1B[5];
    float vec20[4];             /* 0x20 */
    Ovl09194Node87D0 *src0;     /* 0x30 */
    Ovl09194Node87D0 *src1;     /* 0x34 */
    s32 ofs[3];                 /* 0x38..0x40 */
    float rate[3];              /* 0x44..0x4C */
};

struct Ovl09194Ctx87D0 {
    Ovl09194Node87D0 *node;     /* 0x00 */
    u8 dirty;                   /* 0x04 */
    u8 tick;                    /* 0x05 */
    u8 pad6[10];
};

extern void func_002DD038(float *dst, float *a, float *b);
extern float fn_01b17470(float *v);
extern float fn_01b16f08(float *v);

void ovl_09194_01b087d0(Ovl09194Ctx87D0 *ctx) {
    Ovl09194Node87D0 *node = ctx->node;

    if (node->tick == ctx->tick) {
        ctx->dirty = 0;
    } else {
        Ovl09194Node87D0 *child = node->child;
        while (child != node) {
            ctx->node = child;
            child = child->next;
            ctx->node->vtbl->update(ctx);
        }
        ctx->node = node;
        node->tick = ctx->tick;
        ctx->dirty = 1;
    }

    if (ctx->dirty & 1) {
        float vec[4];
        s32 ang[3];
        Ovl09194Ctx87D0 c0;
        Ovl09194Ctx87D0 c1;
        Ovl09194Node87D0 *cur = ctx->node;
        s32 *dst = (s32 *)(cur->f14 + 0x20);
        float len;
        s32 i;

        c0.node = cur->src0;
        c0.tick = ctx->tick;
        c0.node->vtbl->update(&c0);

        c1.node = cur->src1;
        c1.tick = ctx->tick;
        c1.node->vtbl->update(&c1);

        func_002DD038(vec, cur->src0->vec20, cur->src1->vec20);

        VU0_LQC2(31, 0, vec);
        VU0_OP("vmul.xz $vf31, $vf31, $vf31");
        VU0_OP("vaddz.x $vf31, $vf31, $vf31");
        VU0_OP("vsqrt Q, $vf31x");
        VU0_OP("vwaitq");
        VU0_OP("vaddq.x $vf31, $vf0, Q");
        VU0_QMFC2(len, 31);
        {
            register float f32k __asm__("$f21") = 32768.0f;
            __asm__ volatile("" : : "f"(len), "f"(f32k));
            {
                register float *p __asm__("$4") = vec;
                __asm__ volatile("" : : "r"(p));
                vec[3] = len;
                ang[0] = (s32)(fn_01b17470(p) * f32k / 3.1415927410125732421875f);
            }
            ang[1] = (s32)((4.7123889923095703125f - fn_01b16f08(vec)) * f32k / 3.1415927410125732421875f);
        }
        ang[2] = 0;

        for (i = 2; i >= 0; i--) {
            ang[i] += cur->ofs[i];
            dst[i] += (s32)((float)((s16)ang[i] - (s16)dst[i]) * cur->rate[i]);
        }
    }
}
