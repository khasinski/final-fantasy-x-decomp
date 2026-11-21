/* 09616 sound/callback helper (56 B). */

typedef struct {
    unsigned char pad00[0x104];
    void *w104;
} OvlCtx;

extern unsigned char g_ovl_res[];
extern void fn_ovl_3238(void *, int, int);

void ovl_09616_0b90(OvlCtx *ctx)
{
    fn_ovl_3238(g_ovl_res, 0, 0);
    ctx->w104 = 0;
}
