#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    int f10;
} TaskSub;

typedef struct {
    u8 pad00[0x8];
    TaskSub *f8;
    u8 pad0c[0x8];
    int f14;
} OvlTask9297;

typedef struct {
    u8 pad00[0x2C];
    void *f2c;
} OvlMgr9297;

typedef struct {
    u8 pad00[0x50];
    float f50;
    float f54;
    float f58;
    u8 pad5c[0x4];
    float f60;
    float f64;
    float f68;
} Cam9297;

typedef struct {
    u8 pad00[0x20];
    float v20[4];
    float v30[4];
    u8 pad40[0x10];
    float v50[4];
    float v60[4];
    float v70[4];
    float v80[4];
    u8 pad90[0x8];
    int f98;
    float f9c;
    int fa0;
    int fa4;
} Sub7440;

typedef struct {
    u8 pad00[0xC4];
    float fc4;
    u8 padc8[0x8];
    float posd0[4];
    float fe0;
    u8 pade4[0x4];
    float fe8;
    u8 padec[0x44];
} SubObj9297;

typedef struct {
    int f00;
    int f04;
    float f08;
    int f0c;
    int f10;
    int f14;
    int f18;
} Sub7500;

extern u8 g_heap_buf[];
extern void *g_7cf0;
extern void *g_7cf4;
extern OvlMgr9297 g_7590;
extern Sub7440 g_7440;
extern Sub7500 g_7500;
extern u8 g_7530[];
extern SubObj9297 g_objs[6];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_5e0[];
extern u8 g_568[];
extern u8 g_630[];
extern u8 g_648[];

extern void *func_002B49A0(void *, int, int);
extern void ovl_3d90(void *, void *, void *, int);
extern void ovl_6e68(void *, int, void *, int, float, float, float);
extern void ovl_2f30(int, void *, void *);
extern void ovl_20c0(int);
extern void ovl_51f0(int);
extern void ovl_54d8(int);
extern Cam9297 *ovl_5520(int);
extern void ovl_6d48(void *, void *);
extern void *ovl_3b08(void (*)(OvlTask9297 *));
extern void ovl_3cd0(void *);
extern int ovl_6d68(void *);
extern int ovl_3f48(void *, void *);
extern void ovl_3288(void *, int);
extern void ovl_22b0(int, int);
extern void ovl_5330(void);
extern void ovl_0b48(void);
extern void ovl_3e68(void *, void *, int, int, int, int, float);
extern void ovl_1548(int, void *, int);
extern float ovl_1420(int);
extern void func_001B6790(int, void *);
extern void ovl_2040(int, int);
extern int ovl_1390(int);
extern void func_00110570(int, int);
extern void ovl_5638(void *, int, void *, int, int);
extern void ovl_7190(void *, int);

void ovl_09297_0cf8(OvlTask9297 *task);

int ovl_09297_0b68(void)
{
    float pos[4];
    u8 *heap = g_heap_buf;
    OvlMgr9297 *mgr = &g_7590;
    Cam9297 *cam;

    g_7cf4 = heap + 0x40000;
    g_7cf0 = heap;
    mgr->f2c = func_002B49A0(g_res_data, 8, 0);
    ovl_3d90(mgr, g_hdr_40, g_7cf0, 0x40000);

    pos[0] = -194.0f;
    pos[1] = 0.0f;
    pos[2] = 60.0f;
    pos[3] = 1.0f;
    ovl_6e68(&g_7440, -1, pos, 28, 0.7f, 1.3f, 0.99f);
    ovl_2f30(-1, &g_7440, g_5e0);
    ovl_20c0(-1);
    ovl_51f0(1);
    ovl_54d8(0);

    cam = ovl_5520(-1);
    cam->f50 = -376.0f;
    cam->f54 = 65.0f;
    cam->f58 = 199.0f;
    cam->f60 = -199.0f;
    cam->f64 = -5.0f;
    cam->f68 = 64.0f;

    ovl_6d48(g_7530, g_568);
    ovl_3cd0(ovl_3b08(ovl_09297_0cf8));
    return 0;
}

void ovl_09297_0cf8(OvlTask9297 *task)
{
    int a = ovl_6d68(g_7530);
    int b = ovl_3f48(&g_7590, g_7cf4);

    if (b == 1 && a == 1) {
        TaskSub *sub;
        ovl_3288(&g_7440, 1);
        ovl_22b0(-1, 0);
        ovl_5330();
        sub = task->f8;
        task->f14 = 3;
        sub->f10 = (int)ovl_0b48;
    }
}

void ovl_09297_0d98(void)
{
    SubObj9297 *obj;

    obj = &g_objs[2];
    ovl_3e68(&g_7590, obj, 2, 0, 0, 0, 0.48f);
    ovl_1548(-1, obj->posd0, 2);
    obj->fc4 = ovl_1420(-1);
    obj->posd0[1] -= 8.0f;
    obj->fe0 = -20.0f;
    obj->fe8 = 20.0f;

    obj = &g_objs[0];
    ovl_3e68(&g_7590, obj, 0, 0x30, 0, 0, 0.8f);
    ovl_1548(-1, obj->posd0, 1);
    obj->fc4 = ovl_1420(-1);
    obj->posd0[1] += 5.0f;
    obj->fe8 = 20.0f;

    obj = &g_objs[4];
    ovl_3e68(&g_7590, obj, 4, 0x30, 0, 0, 0.6f);
    ovl_1548(-1, obj->posd0, 1);
    obj->fc4 = ovl_1420(-1);

    obj = &g_objs[1];
    ovl_3e68(&g_7590, obj, 1, 0x64, 0, 0, 0.6f);
    obj->posd0[0] = -194.0f;
    obj->posd0[1] = 50.0f;
    obj->posd0[2] = 60.0f;

    obj = &g_objs[5];
    ovl_3e68(&g_7590, obj, 5, 0x8A, 0, 0, 0.5f);
    obj->posd0[0] = -224.0f;
    obj->posd0[1] = 30.0f;
    obj->posd0[2] = 60.0f;
}

void ovl_09297_0f98(void)
{
    float pos[4];
    Sub7440 *s = &g_7440;

    func_001B6790(s->fa0, pos);
    pos[3] = 1.0f;
    MMI_COPY_LQ_A3(s->v20, pos);
    MMI_COPY_SQ_A3(s->v20);

    pos[1] += 300.0f;
    MMI_COPY_LQ_A3(s->v30, pos);
    MMI_COPY_SQ_A3(s->v30);

    s->v80[0] = 0.0f;
    s->v80[1] = 300.0f;
    s->v80[2] = 0.0f;
    s->v80[3] = 1.0f;
    MMI_COPY_LQ_A3(s->v50, s->v80);
    MMI_COPY_SQ_A3(s->v50);
    MMI_COPY_LQ_A3(s->v60, s->v80);
    MMI_COPY_SQ_A3(s->v60);
    MMI_COPY_LQ_A3(s->v70, s->v80);
    MMI_COPY_SQ_A3(s->v70);

    s->fa4 = 50;
    s->f9c = 0.02f;
    s->f98 = 0;
    ovl_2040(-1, 0);
    func_00110570(ovl_1390(-1), 0);
}

void ovl_09297_1078(void)
{
    Cam9297 *cam = ovl_5520(-1);

    cam->f50 = 128.0f;
    cam->f54 = -16.0f;
    cam->f58 = 62.0f;
    cam->f60 = -270.0f;
    cam->f64 = -13.0f;
    cam->f68 = 62.0f;
}

void ovl_09297_10d8(void)
{
    Cam9297 *cam = ovl_5520(-1);

    ovl_5638(cam, 0, g_630, 2, 40);
    ovl_5638(cam, 1, g_648, 2, 40);
}

void ovl_09297_1138(void)
{
    Sub7500 *s = &g_7500;

    ovl_7190(s, 0x30);
    s->f04 = 0;
    s->f08 = 2.0f;
    s->f0c = 0;
    s->f10 = 0;
    s->f14 = 0;
    s->f18 = 0;
}
