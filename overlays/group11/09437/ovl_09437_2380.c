#include "vu0.h"

typedef struct {
    u8 pad00[0xC0];
    float rot[3];
    u8 padCC[4];
    float pos[4];
    u8 padE0[0x50];
} Ctx21B0;

extern u8 *D_01B0A310;
extern u8 D_01B0A228[];
extern u8 D_01B066A8[];
extern int D_01B00748[];

extern float func_002B3DB0(float);
extern void func_01B03AC8(int, void *, int);
extern int func_01B063E8(void *, void *, float, int, int, int, void *);

static inline void copy_vec(float *dst, float *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B02380(void)
{
    float pos[4];
    u8 *base = D_01B0A310;
    Ctx21B0 *ctx;
    int i;

    func_01B03AC8(0, pos, 4);
    ctx = (Ctx21B0 *)(base + 0x11D0);
    for (i = 0; i < 8; i++, ctx++) {
        func_01B063E8(D_01B0A228, ctx, (func_002B3DB0(0.2f) + 1.0f) * 0.02f, 6, D_01B00748[i] - 0xC3, 0, D_01B066A8);
        copy_vec(ctx->pos, pos);
        ctx->rot[0] = func_002B3DB0(3.1415927410125732f);
        ctx->rot[1] = func_002B3DB0(3.1415927410125732f);
        ctx->rot[2] = func_002B3DB0(3.1415927410125732f);
        ctx->pos[0] += func_002B3DB0(2.0f);
        ctx->pos[1] += func_002B3DB0(2.0f);
        ctx->pos[2] += func_002B3DB0(2.0f);
    }
}
