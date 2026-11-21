/* 09318 context callback (96 B). */

typedef struct {
    char pad00[0xD0];
    float fD0;
    char padD4[0x30];
    void *w104;
} OvlCtx;

extern void fn_ovl_1658(int, int, float *, float *);

void ovl_09318_0d98(OvlCtx *ctx)
{
    float v[4];

    v[0] = 300.0f;
    v[1] = 400.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    fn_ovl_1658(-1, 14, v, &ctx->fD0);
    ctx->w104 = 0;
}
