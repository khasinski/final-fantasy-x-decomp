/* Shared 09285-family parabolic arc task (240 B, 5 containers). */

typedef unsigned char u8;
typedef struct {
    float src[4];
    float dst[4];
    float t;
    int delay;
    int idx;
} OvlArc;

typedef struct {
    u8 pad00[0xD0];
    float fD0;
    float fD4;
    u8 padD8[0x58];
} OvlCtx;

extern OvlArc g_ovl_arc;
extern OvlCtx g_ovl_ctx[];
extern u8 g_ovl_mgr[];

extern void fn_ovl_0d98(int, void *);
extern void func_002DD968(void *, void *, void *, float);
extern float fn_ovl_4588(float, float, float, float);
extern void fn_ovl_3f10(void *, void *);
extern void fn_ovl_37c0(void *);

void ovl_09285_0c88(void *task)
{
    OvlArc *arc = &g_ovl_arc;
    OvlCtx *ctx;

    if (arc->delay > 0) {
        arc->delay--;
        if (arc->delay > 0) {
            return;
        }
        fn_ovl_0d98(arc->idx, arc->dst);
    }
    ctx = g_ovl_ctx;
    func_002DD968(&ctx->fD0, arc->src, arc->dst, arc->t);
    ctx->fD4 -= fn_ovl_4588(0.0f, 30.0f, 0.0f, arc->t);
    arc->t += 0.05f;
    if (arc->t >= 1.0f) {
        fn_ovl_3f10(g_ovl_mgr, ctx);
        fn_ovl_37c0(task);
    }
}
