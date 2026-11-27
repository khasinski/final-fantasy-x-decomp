#include "common.h"

typedef float sceVu0FMATRIX[4][4];
typedef float sceVu0FVECTOR[4];

typedef struct {
    u8 pad00[0xD0];
    sceVu0FVECTOR vD0;
} OvlCtx;

extern void func_001072F8(void *, int, void *);
extern float func_00110AF0(void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD998(void *, void *, float);
extern void *func_01B02AA8(int, int);

void func_01B018C8(OvlCtx *ctx)
{
    sceVu0FMATRIX m;
    sceVu0FVECTOR v;
    void *s0;
    float s;

    s0 = func_01B02AA8(-1, 0);
    func_001072F8(s0, 0, m);
    s = 1000.0f / func_00110AF0(s0);
    func_002DD998(m[0], m[0], s);
    func_002DD998(m[1], m[1], s);
    func_002DD998(m[2], m[2], s);
    v[0] = 0.0f;
    v[1] = 7.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    func_002DCE08(ctx->vD0, m, v);
}
