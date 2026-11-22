#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int f10;
} TaskSub9524;

typedef struct {
    u8 pad00[0x8];
    TaskSub9524 *f8;
    u8 pad0c[0x8];
    int f14;
} OvlTask9524;

typedef struct {
    u8 pad00[0x2C];
    void *w2c;
} OvlMgr9524;

typedef struct {
    u8 pad00[0x2C];
    int w2c;
} SeqArg9524;

typedef struct {
    u8 pad00[0xC4];
    float fc4;
    u8 padc8[0x8];
    float posd0[4];
    u8 pade0[0x8];
    float fe8;
    u8 padec[0x44];
} SubObj9524;

typedef struct {
    float cur[4];
    float start[4];
    float end[4];
    int timer;
    int duration;
    u8 pad38[0x8];
} LightSlot9524;

typedef struct {
    LightSlot9524 dir[3];
    LightSlot9524 col[4];
} Light9524;

static __inline__ void set_light_col(Light9524 *l, int idx, float r, float g, float b)
{
    LightSlot9524 *s = &l->col[idx];
    s->cur[0] = r;
    s->cur[1] = g;
    s->cur[2] = b;
}

extern int g_440[2];
extern int g_6f70;
extern u8 g_heap_buf[];
extern void *g_7880;
extern void *g_7884;
extern OvlMgr9524 g_7840;
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_7570[];
extern u8 g_3b0[];
extern Light9524 g_75d0;
extern SubObj9524 g_objs[];

extern void ovl_0d20(int);
extern void *func_002B49A0(void *, int, int);
extern void ovl_38b8(void *, void *, void *, int);
extern void ovl_6870(void *, void *);
extern void ovl_6990(void *);
extern void *ovl_3630(void (*)(OvlTask9524 *));
extern void ovl_37f8(void *);
extern int ovl_6890(void *);
extern int ovl_3a70(void *, void *);
extern void ovl_6b38(void *);
extern void ovl_08e8(void);
extern void ovl_3990(void *, void *, int, int, int, int, float);
extern void ovl_1070(int, void *, int);
extern float ovl_0f48(int);
extern void ovl_6bc8(void *, int, void *, int);
extern void ovl_6bf8(void *, int, void *, int);

void ovl_09524_09d8(OvlTask9524 *task);

int ovl_09524_0908(void)
{
    u8 *p = g_heap_buf;
    OvlMgr9524 *mgr;

    g_7880 = p;
    g_7884 = p + 0x40000;
    g_440[0] = 0;
    g_440[1] = 0;
    ovl_0d20(g_6f70);
    mgr = &g_7840;
    mgr->w2c = func_002B49A0(g_res_data, 8, 0);
    ovl_38b8(mgr, g_hdr_40, g_7880, 0x40000);
    ovl_6870(g_7570, g_3b0);
    ovl_6990(&g_75d0);
    ovl_37f8(ovl_3630(ovl_09524_09d8));
    return 0;
}

void ovl_09524_09d8(OvlTask9524 *task)
{
    int a = ovl_6890(g_7570);
    int b = ovl_3a70(&g_7840, g_7884);

    if (b == 1 && a == 1) {
        TaskSub9524 *sub;
        ovl_6b38(&g_75d0);
        sub = task->f8;
        task->f14 = 3;
        sub->f10 = (int)ovl_08e8;
    }
}

void ovl_09524_0a60(SeqArg9524 *arg)
{
    float v0[4];
    float v1[4];
    SubObj9524 *obj = &g_objs[arg->w2c];
    float zero = 0.0f;

    ovl_3990(&g_7840, obj, 0, 0, 0, 0, 0.025f);
    ovl_1070(-1, obj->posd0, 0);
    obj->posd0[1] -= 6.0f;
    obj->fe8 = -4.0f;
    obj->fc4 = ovl_0f48(-1);
    arg->w2c++;

    v0[0] = 1.3962631f;
    v0[1] = zero;
    ovl_6bc8(&g_75d0, 2, v0, 1);

    set_light_col(&g_75d0, 2, 0.8f, 0.7f, 0.7f);
    v1[0] = zero;
    v1[1] = zero;
    v1[2] = zero;
    ovl_6bf8(&g_75d0, 2, v1, 5);
}
