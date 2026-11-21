/* 09634 trigger callback helper (20 B). */

typedef struct {
    unsigned char pad00[0xD0];
    float fD0;
} OvlCtx;

extern void fn_ovl_1498(int, int, int, void *);

void ovl_09634_0c20(OvlCtx *ctx)
{
    fn_ovl_1498(-1, 151, 0, &ctx->fD0);
}
