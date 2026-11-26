#include "common.h"

typedef struct {
    u8 pad00[0xD0];
    float fD0[4];
} OvlCtx;

extern void func_01B02310(int, int, void *, void *);

void ovl_09476_1448(OvlCtx *ctx)
{
    float v[4];

    v[0] = -30.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    func_01B02310(-1, 0xE2, v, ctx->fD0);
}
