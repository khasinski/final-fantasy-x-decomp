/* Shared 09513-family sound/effect trigger wrapper (20 B). */

typedef struct {
    unsigned char pad00[0xD0];
    float fD0;
} OvlCtx;

extern void fn_ovl_14f0(int, int, int, void *);

void ovl_09513_0c78(OvlCtx *ctx)
{
    fn_ovl_14f0(-1, 153, 0, &ctx->fD0);
}
