#include "common.h"
#include "vu0.h"

struct Ovl09114Ctx1280;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct Ovl09114Ctx1280 *);
} Ovl09114Vtbl1280;

typedef struct Ovl09114VecNode1280 {
    Ovl09114Vtbl1280 *vtbl;
    u8 pad4[0x1C];
    float vec20[4];
} Ovl09114VecNode1280;

typedef struct Ovl09114CamNode1280 {
    Ovl09114Vtbl1280 *vtbl;            /* 0x00 */
    u8 pad4[4];
    struct Ovl09114CamNode1280 *next;  /* 0x08 */
    u8 padC[4];
    struct Ovl09114CamNode1280 *child; /* 0x10 */
    u8 pad14[6];
    u8 tick;                           /* 0x1A */
    u8 pad1B[5];
    float vec20[4];                    /* 0x20 (base + 0x00) */
    float vec30[4];                    /* 0x30 (base + 0x10) */
    float vec40[4];                    /* 0x40 (base + 0x20) */
    float vec50[4];                    /* 0x50 (base + 0x30) */
    float vec60[2];                    /* 0x60 (base + 0x40) */
    float unk68;                       /* 0x68 */
    float unk6C;                       /* 0x6C */
    float unk70[3];                    /* 0x70 */
    float unk7C;                       /* 0x7C */
    float unk80[3];                    /* 0x80 */
    float unk8C;                       /* 0x8C */
    s16 unk90[6];                      /* 0x90 */
    s16 unk9C;                         /* 0x9C */
    u8 pad9E[2];
    float unkA0[4];                    /* 0xA0 (base + 0x80) */
    float unkB0;                       /* 0xB0 (base + 0x90) */
    float unkB4;                       /* 0xB4 */
    u8 padB8[0x14];
    float unkCC;                       /* 0xCC */
    u8 padD0[0xC];
    float unkDC;                       /* 0xDC */
    u8 padE0[0xC];
    float unkEC;                       /* 0xEC */
    u8 padF0[0xC];
    float unkFC;                       /* 0xFC */
    float unk100[4];                   /* 0x100 */
    float unk110[4];                   /* 0x110 */
    float unk120;                      /* 0x120 */
    float unk124;                      /* 0x124 */
    Ovl09114VecNode1280 *unk128;       /* 0x128 */
    Ovl09114VecNode1280 *unk12C;       /* 0x12C */
    u32 unk130;                        /* 0x130 */
    void *unk134;                      /* 0x134 */
    u8 unk138;                         /* 0x138 */
    u8 unk139;                         /* 0x139 */
    u8 unk13A;                         /* 0x13A */
    u8 unk13B;                         /* 0x13B */
} Ovl09114CamNode1280;

typedef struct Ovl09114Ctx1280 {
    void *node;
    u8 dirty;
    u8 tick;
    u8 pad6[10];
} Ovl09114Ctx1280;

extern float D_004F4610[];

extern void func_002DD038(float *dst, float *a, float *b);
extern void func_002DD068(float *dst, float *src, float s);
extern void func_01B118E0(void *dst, void *m1, void *m2);
extern void func_001A7840(void *cam, s32 idx, float *v);
extern void func_001A8128(void *cam, float v);
extern void func_001AAC30(void *cam, float a, float b);
extern void func_001A81E8(void *cam, float v);

static inline void make_rot_zxy(void *dst, s32 *rot) {
    float m0[4][4];
    float m1[4][4];
    float s;
    float c;

    s = D_004F4610[(s32)(rot[2] & 0xFFFF) >> 4];
    c = D_004F4610[(s32)((rot[2] + 0x4000) & 0xFFFF) >> 4];

    m0[0][0] = c;
    m0[0][1] = s;
    m0[0][2] = 0.0f;
    m0[0][3] = 0.0f;
    m0[1][0] = -s;
    m0[1][1] = c;
    m0[1][2] = 0.0f;
    m0[1][3] = 0.0f;
    m0[2][0] = 0.0f;
    m0[2][1] = 0.0f;
    m0[2][2] = 1.0f;
    m0[2][3] = 0.0f;
    m0[3][0] = 0.0f;
    m0[3][1] = 0.0f;
    m0[3][2] = 0.0f;
    m0[3][3] = 1.0f;

    s = D_004F4610[(s32)(rot[0] & 0xFFFF) >> 4];
    c = D_004F4610[(s32)((rot[0] + 0x4000) & 0xFFFF) >> 4];

    m1[0][0] = 1.0f;
    m1[0][1] = 0.0f;
    m1[0][2] = 0.0f;
    m1[0][3] = 0.0f;
    m1[1][0] = 0.0f;
    m1[1][1] = c;
    m1[1][2] = s;
    m1[1][3] = 0.0f;
    m1[2][0] = 0.0f;
    m1[2][1] = -s;
    m1[2][2] = c;
    m1[2][3] = 0.0f;
    m1[3][0] = 0.0f;
    m1[3][1] = 0.0f;
    m1[3][2] = 0.0f;
    m1[3][3] = 1.0f;

    {
        register void *r_s1 __asm__("$17") = m0;
        func_01B118E0(m1, m1, r_s1);
    }

    s = D_004F4610[(s32)(rot[1] & 0xFFFF) >> 4];
    c = D_004F4610[(s32)((rot[1] + 0x4000) & 0xFFFF) >> 4];

    m0[0][0] = c;
    m0[0][1] = 0.0f;
    m0[0][2] = -s;
    m0[0][3] = 0.0f;
    m0[1][0] = 0.0f;
    m0[1][1] = 1.0f;
    m0[1][2] = 0.0f;
    m0[1][3] = 0.0f;
    m0[2][0] = s;
    m0[2][1] = 0.0f;
    m0[2][2] = c;
    m0[2][3] = 0.0f;

    {
        register void *r_s1 __asm__("$17") = m0;
        func_01B118E0(dst, r_s1, m1);
    }
}

void func_01B0C380(Ovl09114Ctx1280 *ctx) {
    float m0[4][4];
    s32 ang[4];
    Ovl09114Ctx1280 sub0;
    Ovl09114Ctx1280 sub1;
    register Ovl09114CamNode1280 *node __asm__("$18") = (Ovl09114CamNode1280 *)ctx->node;

    if (node->tick == ctx->tick) {
        ctx->dirty = 0;
    } else {
        Ovl09114CamNode1280 *child = node->child;

        while (child != node) {
            ctx->node = child;
            child = child->next;
            ((Ovl09114CamNode1280 *)ctx->node)->vtbl->update(ctx);
        }
        ctx->node = node;
        node->tick = ctx->tick;
        ctx->dirty = 1;
    }

    if (ctx->dirty & 1) {
        register float *base __asm__("$19");
        s32 i;

        node = (Ovl09114CamNode1280 *)ctx->node;

        if (node->unk128 != 0) {
            sub0.node = node->unk128;
            sub0.tick = ctx->tick;
            ((Ovl09114VecNode1280 *)sub0.node)->vtbl->update(&sub0);
            {
                float *src = ((Ovl09114VecNode1280 *)sub0.node)->vec20;
                float *dst = node->vec30;
                VU0_LQC2(31, 0, src);
                VU0_SQC2(31, 0, dst);
            }
        }

        if (node->unk12C != 0) {
            sub1.node = node->unk12C;
            sub1.tick = ctx->tick;
            ((Ovl09114VecNode1280 *)sub1.node)->vtbl->update(&sub1);
            {
                float *src = ((Ovl09114VecNode1280 *)sub1.node)->vec20;
                float *dst = node->vec50;
                VU0_LQC2(31, 0, src);
                VU0_SQC2(31, 0, dst);
            }
        }

        switch (node->unk13A) {
        case 0:
            base = node->vec20;
            VU0_LQC2(31, 0, base);
            VU0_LQC2(30, 16, base);
            VU0_LQC2(29, 64, base);
            VU0_OP("vsub.xyz $vf31, $vf31, $vf30");
            VU0_OP("vmulx.xyz $vf31, $vf31, $vf29x");
            VU0_OP("vadd.xyz $vf30, $vf30, $vf31");
            VU0_SQC2(30, 0, base);
            break;
        case 1:
            node->unk120 -= (1.0f / 30.0f);
            if (node->unk120 < 0.0f) {
                node->unk120 = 0.0f;
            }
            func_002DD068(m0[0], node->unk110, node->unk120 / node->unk124);
            base = node->vec20;
            func_002DD038(base, node->unk100, m0[0]);
            node->vec20[3] = 1.0f;
            break;
        default:
            base = node->vec20;
            break;
        }

        if (node->unk139 == 0) {
            VU0_LQC2(31, 32, base);
            VU0_LQC2(30, 48, base);
            VU0_LQC2(29, 64, base);
            VU0_OP("vsub.xyz $vf31, $vf31, $vf30");
            VU0_OP("vmuly.xyz $vf31, $vf31, $vf29y");
            VU0_OP("vadd.xyz $vf30, $vf30, $vf31");
            VU0_SQC2(30, 32, base);
        }

        if (node->unk9C == 0) {
            node->unkEC *= node->unkFC;
            node->unk68 = node->unkCC + node->unkDC * node->unkEC;
        }

        switch (node->unk138) {
        case 0:
            node->unk70[0] *= node->unk80[0];
            node->unk70[1] *= node->unk80[1];
            node->unk70[2] *= node->unk80[2];
            break;
        case 1:
            for (i = 0; i < 3; i++) {
                if (node->unk80[i] > 0.0f) {
                    node->unk70[i] -= node->unk80[i];
                    if (node->unk70[i] <= 0.0f) {
                        node->unk70[i] = 0.0f;
                    }
                } else {
                    node->unk70[i] -= node->unk80[i];
                    if (node->unk70[i] > 0.0f) {
                        node->unk70[i] = 0.0f;
                    }
                }
            }
            break;
        }

        for (i = 0; i < 3; i++) {
            if (node->unk70[i] < 0.0f) {
                ang[i] = -node->unk90[i];
            } else {
                ang[i] = node->unk90[i];
            }
            ang[i] -= (s32)((float)node->unk90[i] * node->unk70[i]);
        }

        node->unk7C = node->unk8C + (float)ang[2] * 3.1415927f * (1.0f / 32768.0f);
        ang[2] = 0;

        make_rot_zxy(m0, ang);

        if ((node->unk130 & 8) != 0) {
            if ((node->unk130 & 1) != 0) {
                VU0_LQC2(28, 128, base);
                VU0_LQC2(27, 0, base);
                VU0_LQC2(31, 0, m0);
                VU0_LQC2(30, 16, m0);
                VU0_LQC2(29, 32, m0);
                VU0_OP("vmulax.xyz ACC, $vf31, $vf28x");
                VU0_OP("vmadday.xyz ACC, $vf30, $vf28y");
                VU0_OP("vmaddz.xyz $vf28, $vf29, $vf28z");
                VU0_OP("vsub.xyz $vf28, $vf27, $vf28");
                VU0_SQC2(28, 48, base);
            }
        }

        func_001A7840(node->unk134, 1, node->vec40);
        func_001A7840(node->unk134, 0, base);
        func_001A8128(node->unk134, node->unk7C);
        func_001A81E8(node->unk134, node->unk68);
    }
}
