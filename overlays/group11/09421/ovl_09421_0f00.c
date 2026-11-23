/* 09421 particle spawner task (596 B). */

#include "vu0.h"

typedef struct {
    u8 pad00[0x130];
    float pos2[4];
    s32 w140;
    s32 w144;
} OvlCtx;

typedef struct {
    u8 pad00[0x14];
    OvlCtx *w14;
} OvlTaskObj;

typedef struct {
    float pos[4];
    float vel[3];
    float rot;
    float acc[4];
    u8 sub30[0x0C];
    float scale;
    u8 pad40[0x0C];
    s32 w4C;
    s32 w50;
    u8 pad54[0x0C];
    s32 w60;
    u8 b64;
    u8 b65;
    u8 b66;
    u8 b67;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
} OvlPart;

typedef struct {
    void *w00;
} OvlTex;

extern u8 g_ovl_mgr[];

extern void fn_ovl_3b58(OvlTaskObj *);
extern OvlTex *fn_ovl_43c8(void *, s32);
extern void fn_ovl_4960(void *, void *);
extern OvlPart *fn_ovl_5068(void);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern s32 func_002EFD78(void);

void ovl_09421_0f00(OvlTaskObj *task)
{
    OvlCtx *ctx = task->w14;
    float *pos2;
    register s32 i __asm__("$17");
    register s32 c50 __asm__("$19");
    OvlPart *p;

    if (ctx->w140 > 0) {
        ctx->w140--;
        return;
    }
    ctx->w144--;
    if (ctx->w144 <= 0) {
        fn_ovl_3b58(task);
        return;
    }
    pos2 = ctx->pos2;
    i = 0;
    c50 = 0x50;
    {
        register u8 *m __asm__("$21") = g_ovl_mgr;
        __asm__("" : "+r"(m) : "r"(c50));
    }
    for (; i < 1 && (p = fn_ovl_5068()) != 0; i++) {
        fn_ovl_4960(p->sub30, fn_ovl_43c8(g_ovl_mgr, 0)->w00);
        MMI_COPY_LQ_A3(p->pos, pos2);
        MMI_COPY_SQ_A3(p->pos);
        p->pos[0] += func_002B3DB0(20.0f);
        p->pos[1] += func_002B3DB0(5.0f);
        p->pos[2] += func_002B3DB0(20.0f);
        p->vel[0] = func_002B3DB0(0.1f);
        p->vel[1] = func_002B3DF8(0.5f) + 0.5f;
        p->vel[2] = func_002B3DB0(0.1f);
        p->rot = func_002B3DB0(3.1415927f);
        p->acc[0] = 0.0f;
        p->acc[1] = -0.0005f;
        p->acc[2] = 0.0f;
        p->acc[3] = 1.0f;
        p->scale = (func_002B3DB0(0.2f) + 1.0f) * 0.7f;
        p->w4C = c50;
        p->w50 = c50;
        p->b64 = 0xB0;
        p->b65 = 0xB0;
        p->b66 = (func_002EFD78() % 16) + 0x38;
        p->b67 = 0x60;
        p->b68 = p->b64;
        p->b69 = p->b65;
        p->b6A = p->b66;
        p->b6B = 0;
        p->w60 = 0;
    }
}
