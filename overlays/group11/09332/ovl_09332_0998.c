/* 09332 task update & completion check (616 B). */

typedef unsigned char u8;
typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;
typedef struct { u8 pad00[0x14]; int w14; u8 pad18[0x08]; } OvlSnd;
typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x58];
} OvlCtx;

extern OvlSnd g_ovl_snd[];
extern u8 g_ovl_dat_4420[];
extern int g_ovl_w4460;
extern int g_ovl_w4464;
extern int g_ovl_w4468;
extern float g_ovl_f446c;
extern float g_ovl_f4470;
extern u8 g_ovl_mgr[];
extern OvlCtx g_ovl_ctx[];
extern void *g_ovl_ptr_4724;

extern void fn_ovl_38e0(void *, void *, int, int, float, int, void *);
extern void fn_ovl_0fc0(int, void *, int);
extern void func_001AAC18(float, float);
extern int fn_ovl_39c0(void *, void *);
extern void fn_ovl_2a60(void *);
extern void fn_ovl_3260(void *, float *);
extern int fn_ovl_30c0(void *);
extern void fn_ovl_1fe8(int, int, int);
extern void fn_ovl_0860(void);

void ovl_09332_0998(OvlTask *t)
{
    OvlCtx *ctx;
    float pos[4];
    int r0;
    int r1;
    int i;

    if (g_ovl_w4460 > 0) {
        if (--g_ovl_w4460 == 0) {
            ctx = &g_ovl_ctx[0];
            fn_ovl_38e0(g_ovl_mgr, ctx, 0, 0, 0.8f, 0, 0);
            fn_ovl_0fc0(0, &ctx->fD0, 0);
            ctx->fD4 -= 65.0f;
        }
    }
    if (g_ovl_w4464 > 0) {
        if (--g_ovl_w4464 == 0) {
            ctx = &g_ovl_ctx[1];
            fn_ovl_38e0(g_ovl_mgr, ctx, 1, 0, 0.8f, 0, 0);
            fn_ovl_0fc0(0, &ctx->fD0, 3);
            ctx->fD4 -= 10.0f;
        }
    }
    if (g_ovl_w4468 > 0) {
        g_ovl_w4468--;
    } else {
        if (g_ovl_w4468 >= -15) {
            if (g_ovl_w4468 & 1) {
                g_ovl_f446c = -2.0f;
            } else {
                g_ovl_f446c = 2.0f;
            }
            func_001AAC18(g_ovl_f446c, g_ovl_f4470);
        }
        g_ovl_w4468--;
    }
    r0 = fn_ovl_39c0(g_ovl_mgr, g_ovl_ptr_4724);
    for (i = 0; i < 2; i++) {
        fn_ovl_2a60(&g_ovl_snd[i]);
    }
    fn_ovl_0fc0(-1, pos, 0);
    fn_ovl_3260(g_ovl_dat_4420, pos);
    r1 = fn_ovl_30c0(g_ovl_dat_4420);
    if (r0 == 1 && r1 == 1 && g_ovl_snd[0].w14 == 1 && g_ovl_snd[1].w14 == 1) {
        fn_ovl_1fe8(0, 0, 1);
        fn_ovl_1fe8(0, 1, 1);
        fn_ovl_1fe8(0, 2, 1);
        func_001AAC18(0.0f, 0.0f);
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0860;
    }
}
