#include "common.h"

typedef struct {
    u8 pad00[0x80];
    float mat80[16];
    u8 padc0[0x4];
    float fc4;
    u8 padc8[0x8];
    float posd0[4];
    u8 pade0[0x24];
    void *f104;
    u8 pad108[0x8];
    void *f110;
    u8 pad114[0x12];
    u8 f126;
    u8 pad127[0x9];
} SubObj9434;

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
} SubAD0;

typedef struct {
    SubObj9434 objs[9];
    float posab0[4];
    float posac0[4];
    SubAD0 subad0;
    u8 subb70[0x40];
    u8 subbb0[0x40];
    u8 subbf0[0x60];
    u8 subc50[0x40];
    float fc90;
    float fc94;
    int fc98;
    int fc9c;
    int fca0;
    int fca4;
    int done;
} Work9434;

extern Work9434 *g_work;
extern u8 g_mgr[];
extern u8 g_res_data[];
extern u8 g_6a8[];
extern u8 g_6c0[];
extern u8 g_4778[];
extern double g_dbl_7730;

extern int ovl_get_se(int);
extern int func_00297C28(int, int, int, int, int, int, int);
extern void ovl_1d58(int, int, int, void *);
extern void ovl_1e78(int, int, void *);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DCE38(void *, void *, void *);
extern void ovl_get_pos(int, void *, int);
extern float ovl_get_scale(int);
extern float ovl_get_dist(int);
extern void ovl_cam_set(void *, void *, void *);
extern float func_002B3DB0(float);
extern void ovl_spawn(void *, void *, int, int, int, void *, float);
extern int ovl_23b0(int, int);
extern float ovl_50f0(void *, void *);
extern void ovl_fade(void *, int, int, float, float);
extern float ovl_bezier(float, float, float, float, float, float);
extern float ovl_bezier3(float, float, float, float);
extern void ovl_set_pos(int, void *);
extern int func_001AF358(void);
extern void ovl_init_c50(void *, void *, void *);
extern void ovl_71d8(void *, int);
extern void func_00297CE8(int);

void ovl_09434_0ed8(void)
{
    Work9434 *w = g_work;

    w->fc9c = func_00297C28(ovl_get_se(-1), 0, 0, 0, 0, 0, 0);
}

void ovl_09434_0f28(SubObj9434 *obj)
{
    float mat[16];

    ovl_1d58(-1, 3, 0, obj->posd0);
    ovl_1e78(-1, 3, obj->mat80);
    func_002DD128(mat);
    func_002DD1C8(mat, mat, 1.5707964f);
    func_002DCE38(obj->mat80, obj->mat80, mat);
    obj->f104 = 0;
}

void ovl_09434_0fb0(void)
{
    float tmp[4];
    float v0[4];
    float v1[4];
    Work9434 *w = g_work;
    int i;
    float d;

    ovl_get_pos(0, w->posac0, 3);
    v0[0] = 0.0f;
    v0[1] = ovl_get_scale(-1);
    v0[2] = 0.0f;
    v1[0] = 0.0f;
    v1[1] = 0.0f;
    v1[2] = ovl_get_dist(0) + 10.0f;
    ovl_cam_set(v0, w->posac0, v1);

    w->fc98 = 50;
    {
        SubObj9434 *obj = &w->objs[5];
        int k = 28;
        for (i = 0; i < 4; i++, obj++, k += 2) {
            float spd = (func_002B3DB0(0.2f) + 1.0f) * 0.075f;
            ovl_spawn(g_mgr, obj, 2, k, 0, 0, spd);
            obj->f104 = (void *)ovl_09434_0f28;
            obj->f126 = 2;
        }
    }

    w->fca0 = ovl_23b0(-1, 0);
    ovl_get_pos(-1, tmp, 3);
    d = ovl_50f0(tmp, w->posac0);
    if (d > 100.0f) {
        if (d < 200.0f) {
            float t = (d - 100.0f) / 100.0f;
            w->fc90 = (1.0f - t) * 0.0f + t * 30.0f;
        } else {
            w->fc90 = 30.0f;
        }
    } else {
        w->fc90 = 0.0f;
    }

    ovl_fade(w->subb70, 20, 0, 1.0f, 0.5f);
}

void ovl_09434_11c8(void)
{
    float pos[4];
    Work9434 *w = g_work;
    float t;
    int i;

    if (w->fc98 > 0) {
        w->fc98--;
    }
    t = (float)w->fc98 / 50.0f;
    for (i = 0; i < 3; i++) {
        float d = w->posac0[i] - w->posab0[i];
        pos[i] = w->posab0[i] + ovl_bezier(d, d * 0.9f, d * 0.65f, d * 0.3, 0.0f, t);
    }
    pos[1] = w->posab0[1];
    if (w->fc98 < 23) {
        pos[1] += ovl_bezier3(0.0f, w->fc90, 0.0f, (float)w->fc98 / 23.0f);
    }
    ovl_set_pos(-1, pos);
}

void ovl_09434_1360(void)
{
    Work9434 *w = g_work;
    int idx;
    void *tbl;
    SubObj9434 *obj;
    SubAD0 *p;

    if (w->fca4 != 0) {
        idx = 0;
        tbl = g_6a8;
    } else {
        idx = 4;
        tbl = g_6c0;
    }
    obj = &w->objs[idx];
    ovl_spawn(g_mgr, obj, idx, 0, 2, g_4778, 0.15f);
    ovl_get_pos(0, obj->posd0, 6);
    obj->fc4 = w->fc94;
    if (func_001AF358() == 0x018B0046) {
        obj->posd0[1] = w->posab0[1] - 0.5f;
    } else {
        obj->posd0[1] -= 0.5f;
    }
    ovl_init_c50(w->subc50, g_res_data, tbl);
    obj->f110 = w->subc50;

    p = &w->subad0;
    p->b80 = p->b81 = p->b82 = p->b83 = 0x80;
    p->b86 = p->b85 = p->b84 = 0x80;
    p->b87 = 0;
    p->w88 = 0;
    p->b98 = 0x48;
    p->b99 = 0;
    ovl_71d8(p, 20);
    ovl_23b0(-1, w->fca0);
    ovl_fade(w->subbb0, 30, 35, 0.5f, 1.0f);
}

void ovl_09434_14c0(void)
{
    Work9434 *w = g_work;

    func_00297CE8(w->fc9c);
    w->fc9c = -1;
}
