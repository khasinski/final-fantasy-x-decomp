/* 09358 trigger callback helper (36 B). */

typedef struct {
    unsigned char pad00[0xD0];
    float fD0;
    unsigned char padD4[0x4C];
    int w120;
} OvlCtx;

typedef struct {
    unsigned char b[0x10];
} OvlTblEntry;

extern OvlTblEntry g_ovl_tbl[];
extern void fn_ovl_1680(int, int, void *, void *);

void ovl_09358_0df8(OvlCtx *ctx)
{
    fn_ovl_1680(-1, 11, &g_ovl_tbl[ctx->w120], &ctx->fD0);
}
