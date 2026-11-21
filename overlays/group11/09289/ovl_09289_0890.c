typedef unsigned char u8;

typedef struct {
    int w00;
    int count;
} OvlHdr;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x64];
    float f64;
} OvlNode;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    float fD8;
} OvlCtx;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_4dc8[];
extern u8 g_ovl_dat_0440[];
extern u8 g_ovl_dat_0428[];
extern u8 g_ovl_dat_0ac8[];
extern int g_ovl_obj_4df0[];
extern int g_ovl_arr_4e50[];
extern void *g_ovl_ptr_4fe0;
extern void *g_ovl_ptr_4fe4;
extern OvlHdr g_ovl_hdr;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_37f0(void *, void *, void *, int);
extern OvlNode *fn_ovl_38c8(void *, void *, int, int, float, int, int);
extern void fn_ovl_0fa8(int, void *, int);
extern float fn_ovl_0e80(int);
extern void fn_ovl_2990(int, void *, void *);
extern double sqrt(double);
extern void fn_ovl_4c50(void *, void *, void *, int);
extern void *fn_ovl_3568(void *);
extern void fn_ovl_3730(void *);

int ovl_09289_0890(void) {
    float vec[4];
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlCtx *ctx;
    OvlNode *node;
    int i;

    g_ovl_ptr_4fe4 = p + 0x50000;
    g_ovl_ptr_4fe0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_37f0(mgr, g_ovl_dat_0040, g_ovl_ptr_4fe0, 0x50000);

    ctx = &g_ovl_ctx;
    node = fn_ovl_38c8(mgr, ctx, 0, 34, 1.0f, 0, 0);
    fn_ovl_0fa8(-1, &ctx->fD0, 0);
    ctx->fC4 = fn_ovl_0e80(-1);
    ctx->fD4 -= 0.2f;
    node->f64 = 0.8f;
    fn_ovl_2990(-1, g_ovl_dat_4dc8, g_ovl_dat_0440);

    for (i = 0; i < g_ovl_hdr.count; i++) {
        float d;
        fn_ovl_0fa8(i, vec, 0);
        vec[0] -= ctx->fD0;
        vec[2] -= ctx->fD8;
        d = (float)sqrt((double)(vec[0] * vec[0] + vec[2] * vec[2]));
        g_ovl_arr_4e50[i] = (int)(d * 0.2f) + 34;
    }

    fn_ovl_4c50(g_ovl_obj_4df0, g_ovl_res, g_ovl_dat_0428, 1);
    g_ovl_obj_4df0[21] = -1;
    fn_ovl_3730(fn_ovl_3568(g_ovl_dat_0ac8));
    return 0;
}
