/* Shared 09176/09391 impact burst (608 B). */

#include "vu0.h"

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    sceVu0FVECTOR pos;
    u8 padE0[0x40];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    float x;
    float y;
    float z;
    float w;
    float vx;
    float vy;
    float vz;
    float w1C;
    float w20;
    float f24;
    float w28;
    float f2C;
    u8 s30[0x0C];
    float f3C;
    u8 pad40[0x0C];
    int w4C;
    int w50;
    u8 pad54[0x0C];
    int w60;
} OvlPart;

extern u8 g_ovl_res[];
extern u8 g_ovl_dat_4680[];
extern u8 g_ovl_mgr[];

extern float func_001ACED8(void);
extern void *func_002B49A0(void *, int, int);
extern void func_002DCEC8(void *, void *);
extern int fn_ovl_0bd0(void);
extern int fn_ovl_1550(int);
extern float fn_ovl_1678(int);
extern void fn_ovl_17a0(int, void *, int);
extern int fn_ovl_40c0(void *, void *, int, int, int, void *, float);
extern void fn_ovl_5488(void *, void *);
extern OvlPart *fn_ovl_5e10(void);

void ovl_09177_0f20(OvlCtx *work)
{
    sceVu0FVECTOR vec;
    int type;
    int count;
    int i;
    int delay;
    OvlCtx *ctx;

    fn_ovl_17a0(-1, vec, 5);
    switch (fn_ovl_0bd0()) {
        case 1:
            type = 2;
            count = 32;
            break;
        case 2:
            type = 2;
            count = 64;
            break;
        default:
            type = 0;
            count = 24;
            break;
    }

    ctx = work + 1;
    fn_ovl_40c0(g_ovl_mgr, ctx, type, 0, 0, g_ovl_dat_4680, 0.06f);
    MMI_COPY_LQ_A3(ctx->pos, vec);
    MMI_COPY_SQ_A3(ctx->pos);
    ctx->fC4 = fn_ovl_1678(-1);
    ctx->w120 = fn_ovl_1550(-1);

    delay = 0;
    i = 0;
    if (count != 0) {
        do {
            OvlPart *part = fn_ovl_5e10();
            if (part == 0) {
                break;
            }
            fn_ovl_5488(part->s30, func_002B49A0(g_ovl_res, 9, 0));
            if ((i & 3) == 0) {
                delay++;
            }
            fn_ovl_17a0(-1, part, 5);
            vec[0] = func_001ACED8() - 1.5f;
            vec[1] = func_001ACED8() - 1.5f;
            vec[2] = func_001ACED8() - 1.5f;
            func_002DCEC8(vec, vec);
            part->w4C = -1;
            part->w60 = delay;
            part->x += vec[0] * 6.0f;
            part->y += vec[1] * 6.0f;
            part->z += vec[2] * 6.0f;
            part->w50 = 0;
            part->vx = vec[0] * 0.01f;
            part->vy = vec[1] * 0.01f;
            part->vz = vec[2] * 0.01f;
            part->f24 = -0.01f;
            part->f2C = 1.0f;
            part->f3C = 0.06f;
            part->w20 = 0.0f;
            part->w28 = 0.0f;
            part->w1C = 0.0f;
        } while (++i < count);
    }
}
