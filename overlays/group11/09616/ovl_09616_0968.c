/* 09616 effect initializer (464 B). */

typedef unsigned char u8;
typedef struct { u8 pad00[0x2C]; void *w2C; } OvlMgr;
typedef struct { int w0; int count; } OvlHdr;
typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x10];
    float fE8;
    u8 padEC[0x18];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_3e68[];
extern u8 g_ovl_dat_0518[];
extern OvlHdr g_ovl_hdr;
extern void *g_ovl_ptr_4d70;
extern void *g_ovl_ptr_4d74;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_37d0(void *, void *, void *, int);
extern void fn_ovl_38a8(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0f88(int, void *, int);
extern float fn_ovl_0e60(int);
extern int fn_ovl_0d38(int);
extern int fn_ovl_1988(int);
extern void fn_ovl_3030(void *, void *, void *);
extern void *fn_ovl_3548(void *);
extern void fn_ovl_3710(void *);
extern void fn_ovl_0b38(void);
extern void fn_ovl_0b90(void);

int ovl_09616_0968(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    int i;
    int delay = 0;

    g_ovl_ptr_4d74 = p + 0x40000;
    g_ovl_ptr_4d70 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_37d0(mgr, g_ovl_dat_0040, g_ovl_ptr_4d70, 0x40000);
    for (i = 0; i < g_ovl_hdr.count; i++) {
        OvlCtx *ctx = &g_ovl_ctx[i];
        u8 *q;
        fn_ovl_38a8(mgr, ctx, 0, delay, 0.1f, 20, g_ovl_dat_3e68);
        fn_ovl_0f88(i, &ctx->fD0, 0);
        ctx->fC4 = fn_ovl_0e60(i);
        ctx->fE8 = -6.0f;
        ctx->fD4 -= 13.0f;
        ctx->w120 = fn_ovl_0d38(i);
        if (fn_ovl_1988(-1) == 1) {
            ctx->w104 = (void *)fn_ovl_0b90;
        }
        q = p + ((i << 6) + 0x140000);
        fn_ovl_3030(q, g_ovl_res, g_ovl_dat_0518);
        ctx->w110 = q;
        delay += 15;
    }
    fn_ovl_3710(fn_ovl_3548((void *)fn_ovl_0b38));
    return 0;
}
