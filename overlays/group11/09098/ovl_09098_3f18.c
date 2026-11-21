/* Shared 09098-family tail-call helpers (76 B, 5 functions). */

typedef struct {
    unsigned char pad00[0x120];
    int w120;
} OvlCtx;

extern void fn_ovl_23b8(int, int);

void ovl_09098_3f18(void)
{
    fn_ovl_23b8(-5, 0);
}

void ovl_09098_3f28(void)
{
    fn_ovl_23b8(-5, 2);
}

void ovl_09098_3f38(OvlCtx *ctx)
{
    fn_ovl_23b8(ctx->w120, 0);
}

void ovl_09098_3f48(OvlCtx *ctx)
{
    fn_ovl_23b8(ctx->w120, 8);
}

void ovl_09098_3f58(OvlCtx *ctx)
{
    fn_ovl_23b8(ctx->w120, 2);
}
