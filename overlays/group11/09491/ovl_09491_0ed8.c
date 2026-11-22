#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0xC4];
    float fc4;
    u8 padc8[0x8];
    float posd0[4];
    u8 pade0[0x30];
    void *f110;
    u8 pad114[0x1C];
} SubObj9491;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8c[0xC];
    u8 b98;
    u8 b99;
    u8 pad9a[0x6];
} Sub630;

typedef struct {
    SubObj9491 objs[5];
    u_long128 pos5f0;
    u_long128 pos600;
    u_long128 pos610;
    u_long128 pos620;
    Sub630 sub630;
    u8 sub6d0[0x40];
    u8 sub710[0x40];
    u8 sub750[0x60];
    u8 sub7b0[0x40];
    float f7f0;
    int f7f4;
    int f7f8;
    int f7fc;
    int f800;
    int done;
} Work9491;

extern Work9491 *g_work;
extern u8 g_mgr[];
extern u8 g_res_data[];
extern u8 g_698[];
extern u8 g_6b0[];
extern u8 g_4508[];

extern void ovl_get_pos(int, void *, int);
extern float ovl_get_scale(int);
extern float ovl_get_dist(int);
extern void ovl_cam_set(void *, void *, void *);
extern int ovl_get_se(int);
extern int func_00297C28(int, int, int, int, int, int, int);
extern void ovl_fade(void *, int, int, float, float);
extern float ovl_bezier(float, float, float, float, float, float);
extern void ovl_set_pos(int, void *);
extern void ovl_spawn(void *, void *, int, int, int, void *, float);
extern void ovl_init_7b0(void *, void *, void *);
extern void ovl_6f68(void *, int);
extern void func_00297CE8(int);

void ovl_09491_0ed8(void)
{
    float v0[4];
    float v1[4];
    Work9491 *w = g_work;

    ovl_get_pos(0, &w->pos600, 0);
    v0[0] = 0.0f;
    v0[1] = ovl_get_scale(-1);
    v0[2] = 0.0f;
    v1[0] = 0.0f;
    v1[1] = 0.0f;
    v1[2] = ovl_get_dist(0) + 3.0f;
    ovl_cam_set(v0, &w->pos600, v1);

    {
        register void *d1 __asm__("$4") = &w->pos610;
        MMI_COPY_LQ_A3(d1, &w->pos5f0);
        MMI_COPY_SQ_A3(d1);
    }
    {
        register void *d2 __asm__("$3") = &w->pos620;
        MMI_COPY_LQ_A3(d2, &w->pos600);
        MMI_COPY_SQ_A3(d2);
    }
    w->f7f8 = 30;
    w->f7f4 = 30;
    w->f7fc = func_00297C28(ovl_get_se(-1), 0, 0, 0, 0, 0, 0);
    ovl_fade(w->sub6d0, 20, 0, 1.0f, 0.5f);
}

void ovl_09491_0fd0(void)
{
    float pos[4];
    Work9491 *w = g_work;
    float t;
    float *p610;
    float *p620;
    int i;

    if (w->f7f4 > 0) {
        w->f7f4--;
    }
    t = (float)w->f7f4 / (float)w->f7f8;
    p610 = (float *)&w->pos610;
    p620 = (float *)&w->pos620;
    for (i = 0; i < 3; i++) {
        float d = p620[i] - p610[i];
        pos[i] = p610[i] + ovl_bezier(d, d * 0.9f, d * 0.2f, d * 0.05f, 0.0f, t);
    }
    ovl_set_pos(-1, pos);
}

void ovl_09491_10e8(void)
{
    Work9491 *w = g_work;
    int idx;
    void *tbl;
    SubObj9491 *obj;
    Sub630 *p;

    if (w->f800 != 0) {
        idx = 1;
        tbl = g_698;
    } else {
        idx = 3;
        tbl = g_6b0;
    }
    obj = &w->objs[idx];
    ovl_spawn(g_mgr, obj, idx, 0, 2, g_4508, 0.15f);
    ovl_get_pos(0, obj->posd0, 4);
    obj->fc4 = w->f7f0;
    ovl_init_7b0(w->sub7b0, g_res_data, tbl);
    obj->f110 = w->sub7b0;

    p = &w->sub630;
    p->b80 = p->b81 = p->b82 = p->b83 = 0x80;
    p->b86 = p->b85 = p->b84 = 0x80;
    p->b87 = 0;
    p->w88 = 0;
    p->b98 = 0x48;
    p->b99 = 0;
    ovl_6f68(p, 20);
    ovl_fade(w->sub710, 30, 35, 0.5f, 1.0f);
}

void ovl_09491_1218(void)
{
    register Work9491 *w __asm__("$3") = g_work;

    {
        register void *d1 __asm__("$4") = &w->pos610;
        MMI_COPY_LQ_A3(d1, &w->pos600);
        MMI_COPY_SQ_A3(d1);
    }
    {
        register void *d2 __asm__("$5") = &w->pos620;
        MMI_COPY_LQ_A3(d2, &w->pos5f0);
        MMI_COPY_SQ_A3(d2);
    }
    {
        register int c __asm__("$4") = 30;
        w->f7f8 = c;
        w->f7f4 = c;
    }
}

void ovl_09491_1250(void)
{
    Work9491 *w = g_work;

    func_00297CE8(w->f7fc);
    w->f7fc = -1;
}
