#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    void *p10;
} OvlSubTask;

typedef struct {
    u8 pad00[0x08];
    OvlSubTask *p08;
    u8 pad0C[0x08];
    int w14;
} OvlTask;

typedef struct {
    u8 pad00[0x20];
    float v20[12];
    float pos[4];
    float rot[4];
    float base[4];
    float p0[4];
    float p1[4];
    float p2[4];
    float p3[4];
    float t;
    float dt;
    float drot;
    int timer;
    int delay;
    int wD4;
    int done;
    u8 padDC[0x04];
} OvlEntryE0;

typedef struct {
    u8 pad00[0x14];
    OvlEntryE0 *entry;
} OvlTaskE0;

extern int g_0514;
extern OvlEntryE0 g_73d0[];
extern int g_88b4;
extern u8 g_84d8[];
extern u16 g_6dc0;
extern void fn_0920(void);

extern int func_01B043C0(void *, int);
extern void func_01B02C30(int, int);
extern void func_01B02688(int, int);
extern float func_01B04E00(float, float, float, float, float);
extern void func_002DD020(void *, void *, void *);
extern void func_01B031B0(int, void *, void *);
extern int func_01B03460(void *);
extern void func_01B04000(void *);

void ovl_09295_0e50(OvlTask *task)
{
    int n;
    int ok;
    int i;
    int r;

    ok = 1;
    n = g_0514;
    for (i = 0; i < n; i++) {
        if (((OvlEntryE0 *)(i * sizeof(OvlEntryE0) + (u8 *)g_73d0))->done == 0) {
            ok = 0;
            break;
        }
    }
    r = func_01B043C0(g_84d8, g_88b4);
    if (r == 1 && (g_6dc0 & 0x8000) && ok == 1) {
        for (i = 0; i < n; i++) {
            func_01B02C30(i, 0);
            func_01B02688(i, 0);
        }
        *(volatile int *)&task->w14 = 3;
        *(void * volatile *)&task->p08->p10 = (void *)fn_0920;
    }
}

void ovl_09295_0f88(OvlTaskE0 *task)
{
    float pos[4];
    OvlEntryE0 *e;
    float t;
    float *angp;
    float ang;

    e = task->entry;
    if (e->delay > 0) {
        e->delay--;
        return;
    }
    if (e->timer > 0 && --e->timer > 0) {
        e->t += e->dt;
        t = e->t;
    } else {
        t = 1.0f;
    }

    pos[0] = func_01B04E00(e->p0[0], e->p1[0], e->p2[0], e->p3[0], t);
    pos[1] = func_01B04E00(e->p0[1], e->p1[1], e->p2[1], e->p3[1], t);
    pos[2] = func_01B04E00(e->p0[2], e->p1[2], e->p2[2], e->p3[2], t);
    func_002DD020(pos, e->base, pos);
    pos[3] = 1.0f;

    {
        float d = e->drot;
        angp = &e->rot[0];
        ang = *angp + d;
        if (ang > 3.1415927f) {
            ang -= 6.2831855f;
        } else if (ang < -3.1415927f) {
            ang += 6.2831855f;
        }
        *angp = ang;
    }

    func_01B031B0(e->wD4, e->v20, angp);
    MMI_COPY_LQ_A3(e->pos, pos);
    MMI_COPY_SQ_A3(e->pos);

    if (func_01B03460(e) == 1 && e->timer <= 0) {
        e->done = 1;
        func_01B04000(task);
    }
}
