#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 pos;
    float f10;
    float f14;
    int w18;
    int w1C;
} SpawnTbl9732;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x50];
} OvlCtx9732;

typedef struct {
    u8 pad00[0x2C];
    int idx;
} OvlArg9732;

typedef struct {
    float pos[4];
    float vel[4];
    float acc[4];
    u8 sub30[0xC];
    float f3c;
    u8 pad40[0xC];
    int f4c;
    int f50;
} Particle9732;

extern OvlCtx9732 *g_78bc;
extern SpawnTbl9732 g_4f0[];
extern u8 g_7818[];
extern u8 g_res_data[];
extern int g_510[];

extern void ovl_3bc0(void *, void *, int, int, float, int, int);
extern Particle9732 *ovl_7308(void);
extern void *func_002B49A0(void *, int, int);
extern void ovl_4f88(void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern int func_002EFD78(void);
extern void ovl_1740(int, int, void *, void *);

OvlCtx9732 *ovl_09732_0c90(int idx)
{
    SpawnTbl9732 *e = &g_4f0[idx];
    OvlCtx9732 *ctx = &g_78bc[idx];
    register Vec4 *dst __asm__("$3");

    ovl_3bc0(g_7818, ctx, e->w18, 0, e->f10, 0, 0);
    dst = &ctx->vD0;
    MMI_COPY_LQ_A3(dst, &e->pos);
    MMI_COPY_SQ_A3(dst);
    ctx->fC4 = e->f14;
    return ctx;
}

void ovl_09732_0d18(OvlArg9732 *arg)
{
    ovl_09732_0c90(arg->idx);
}

void ovl_09732_0d20(void)
{
    float tmp[4];
    Particle9732 *p = ovl_7308();

    if (p == 0) {
        return;
    }
    ovl_4f88(p->sub30, func_002B49A0(g_res_data, 9, 0));
    tmp[0] = func_002B3DB0(2.0f) * 1000.0f;
    tmp[1] = func_002B3DB0(1.0f) * 1000.0f;
    tmp[2] = func_002B3DB0(1.0f) * 1000.0f;
    tmp[3] = 1.0f;
    ovl_1740(-1, g_510[func_002EFD78() % 5], tmp, p);
    p->vel[0] = func_002B3DB0(5.0f);
    p->vel[1] = -(func_002B3DF8(5.0f) + 3.0f);
    p->vel[2] = func_002B3DB0(5.0f);
    p->vel[3] = func_002B3DB0(3.1415927f);
    p->acc[0] = p->vel[0] * -func_002B3DB0(0.02f);
    p->acc[1] = 0.0f;
    p->acc[2] = p->vel[2] * -func_002B3DB0(0.02f);
    p->acc[3] = 1.0f;
    p->f3c = (func_002B3DB0(0.2f) + 1.0f) * 0.2f;
    p->f4c = -1;
    p->f50 = 0;
}
