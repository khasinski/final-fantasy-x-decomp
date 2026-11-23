/* 09457 effect init + main update (924 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0;
    float fD4;
    u8 padD8[0x30];
    void *w108;
    int pad10C;
    void *w110;
    u8 pad114[0x0C];
    void *w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    u8 pad00[0x28];
    void *w28;
    u8 pad2C[0x08];
    void *w34;
} OvlCb;

typedef struct {
    u8 pad00[0x1E4];
    int count;
} OvlTargetInfo;

typedef struct {
    u8 pad00[0x10];
    int w10;
} OvlSubTask;

typedef struct {
    u8 pad00[0x08];
    OvlSubTask *p08;
    u8 pad0C[0x08];
    int w14;
} OvlTask;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern OvlCb g_ovl_dat_0428;
extern OvlCb g_ovl_dat_0470;
extern u8 g_ovl_dat_04c0[];
extern int g_ovl_dat_04d8[];
extern OvlTargetInfo g_ovl_dat_0528;
extern u8 g_ovl_dat_4050[];
extern u8 g_ovl_50a8[];
extern u8 g_ovl_50d0[];
extern int g_ovl_513c;
extern void *g_ovl_ptr_5150;
extern OvlMgr g_ovl_mgr;
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_64a0;
extern void *g_ovl_ptr_64a4;

extern void *func_002B49A0(void *, int, int);
extern float func_002B3DF8(float);
extern void fn_ovl_0900(void);
extern void fn_ovl_0cc0(void);
extern void fn_ovl_0d38(void);
extern void *fn_ovl_0f20(int);
extern float fn_ovl_1048(int);
extern void fn_ovl_1170(int, void *, int);
extern int fn_ovl_1ab0(int);
extern void fn_ovl_2560(signed char *);
extern void fn_ovl_2b58(int, void *, void *);
extern int fn_ovl_2c10(void *);
extern void fn_ovl_2fa0(int);
extern void fn_ovl_3218(void *, void *, void *);
extern void *fn_ovl_3730(void *);
extern void fn_ovl_38f8(void *);
extern void fn_ovl_39b8(void *, void *, void *, int);
extern void fn_ovl_3a90(void *, void *, int, int, float, int, void *);
extern int fn_ovl_3b70(void *, void *);
extern void fn_ovl_4578(void *);
extern void fn_ovl_4590(float, float);
extern void fn_ovl_45b0(float, float);
extern void fn_ovl_4e60(void *, float, float, int, int);

void ovl_09457_0c10(OvlTask *task);

int ovl_09457_0920(void)
{
    signed char buf[16];
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlCtx *ctx;
    int i;
    int delay;
    float f21;

    g_ovl_ptr_64a0 = p;
    g_ovl_ptr_64a4 = p + 0x40000;
    g_ovl_ptr_5150 = p + 0x140000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_39b8(mgr, g_ovl_dat_0040, g_ovl_ptr_64a0, 0x40000);
    fn_ovl_2560(buf);
    ctx = g_ovl_ctx;
    f21 = fn_ovl_1048(-1);
    g_ovl_dat_0428.w28 = (void *)fn_ovl_0cc0;
    g_ovl_dat_0470.w34 = (void *)fn_ovl_0d38;

    delay = 0;
    for (i = 0; i < g_ovl_dat_0528.count; i++, ctx++) {
        int id = buf[i];
        float f20 = 0.2f;
        void *sub;

        f20 = func_002B3DF8(f20) * f20 + f20;
        if (fn_ovl_1ab0(id) == 0) {
            fn_ovl_3a90(mgr, ctx, 0, delay, f20, 20, g_ovl_dat_4050);
            fn_ovl_1170(id, &ctx->fD0, 7);
            ctx->w108 = &g_ovl_dat_0428;
            ctx->fD4 -= 0.5f;
        } else {
            fn_ovl_3a90(mgr, ctx, 1, delay, f20, 20, g_ovl_dat_4050);
            fn_ovl_1170(id, &ctx->fD0, 5);
            ctx->w108 = &g_ovl_dat_0470;
        }
        ctx->fC4 = f21;
        ctx->w120 = fn_ovl_0f20(id);
        delay += 20;
        sub = p + ((i << 6) + 0x1c0000);
        fn_ovl_3218(sub, g_ovl_res, g_ovl_dat_04c0);
        ctx->w110 = sub;
    }

    {
        int t = delay - 20;
        g_ovl_dat_04d8[1] = t;
        fn_ovl_2b58(-1, g_ovl_50a8, (t > 0) ? &g_ovl_dat_04d8[0] : &g_ovl_dat_04d8[2]);
    }
    fn_ovl_4590(-0.2f, 0.0f);
    fn_ovl_4e60(g_ovl_50d0, 1.0f, 0.5f, 8, 0);
    fn_ovl_4e60(g_ovl_50d0 + 0x40, 0.5f, 1.0f, 16, delay + 20);
    fn_ovl_2fa0(1);
    fn_ovl_38f8(fn_ovl_3730((void *)ovl_09457_0c10));
    return 0;
}

void ovl_09457_0c10(OvlTask *task)
{
    int r = fn_ovl_2c10(g_ovl_50a8);

    fn_ovl_45b0(0.0f, 0.3141592741012573f);
    fn_ovl_4578(g_ovl_ptr_5150);
    if (fn_ovl_3b70(&g_ovl_mgr, g_ovl_ptr_64a4) == 1 && r == 1 && g_ovl_513c <= 0) {
        task->w14 = 3;
        task->p08->w10 = (int)fn_ovl_0900;
    }
}
