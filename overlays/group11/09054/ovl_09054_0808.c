/* Shared 09054/09058 effect initializer (452 B, 2 containers). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3c70[];
extern u8 g_ovl_dat_0360[];
extern int g_ovl_w41a0;
extern void *g_ovl_ptr_4b70;
extern void *g_ovl_ptr_4b74;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern u8 *func_001E5728(int, int *, int);
extern void fn_ovl_35d8(void *, void *, void *, int);
extern int fn_ovl_0b68(int);
extern void fn_ovl_36b0(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0d90(int, void *, int);
extern float fn_ovl_0c68(int);
extern int fn_ovl_0b40(int);
extern void fn_ovl_2e38(void *, void *, void *);
extern void *fn_ovl_3350(void *);
extern void fn_ovl_3518(void *);
extern void fn_ovl_07b0(void);

int ovl_09054_0808(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int n;
    u8 *list;
    int i;
    int delay = 0;

    g_ovl_ptr_4b74 = p + 0x40000;
    g_ovl_ptr_4b70 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_35d8(mgr, g_ovl_dat_0040, g_ovl_ptr_4b70, 0x40000);
    list = func_001E5728(g_ovl_w41a0, &n, 0);
    for (i = 0; i < n; i++) {
        int idx = fn_ovl_0b68(list[i]);
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_36b0(mgr, ctx, 0, delay, 20, g_ovl_dat_3c70, 0.12f);
        delay += 15;
        fn_ovl_0d90(idx, &ctx->fD0, 5);
        ctx->fD4 -= 3.0f;
        ctx->fC4 = fn_ovl_0c68(idx);
        ctx->w120 = fn_ovl_0b40(idx);
        q = p + ((i << 6) + 0x140000);
        fn_ovl_2e38(q, g_ovl_res, g_ovl_dat_0360);
        ctx->w110 = q;
    }
    fn_ovl_3518(fn_ovl_3350((void *)fn_ovl_07b0));
    return 0;
}
