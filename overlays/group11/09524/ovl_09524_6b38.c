#include "common.h"
#include "vu0.h"

typedef struct {
    float cur[4];
    float start[4];
    float end[4];
    int timer;
    int duration;
    u8 pad38[0x8];
} LightSlot;

typedef struct {
    u8 pad00[0x14];
    void *user;
    u8 prio;
} LightTask;

typedef struct {
    LightSlot dir[3];
    LightSlot col[4];
    u8 pad1c0[0x30];
    float orig_dir[3][4];
    float orig_col[4][4];
    LightTask *task;
} LightMgr;

extern void func_00106508(int, void *);
extern void func_00106610(int, void *);
extern void ovl_36b0(LightTask *);
extern void func_002DD128(void *);
extern float ovl_4998(float, float);
extern void func_002DD270(void *, void *, float);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);

void ovl_09524_6b38(LightMgr *mgr)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_00106508(i, mgr->orig_dir[i]);
        func_00106610(i, mgr->orig_col[i]);
    }
    func_00106610(i, mgr->orig_col[i]);
    if (mgr->task != 0) {
        ovl_36b0(mgr->task);
        mgr->task = 0;
    }
}

void ovl_09524_6bc8(LightMgr *mgr, int idx, float *target, int duration)
{
    LightSlot *s = &mgr->dir[idx];

    MMI_COPY_LQ_A3(s->start, s->cur);
    MMI_COPY_SQ_A3(s->start);
    MMI_COPY_LQ_A3(s->end, target);
    MMI_COPY_SQ_A3(s->end);
    s->duration = duration;
    s->timer = duration;
}

void ovl_09524_6bf8(LightMgr *mgr, int idx, float *target, int duration)
{
    LightSlot *s = &mgr->col[idx];

    MMI_COPY_LQ_A3(s->start, s->cur);
    MMI_COPY_SQ_A3(s->start);
    MMI_COPY_LQ_A3(s->end, target);
    MMI_COPY_SQ_A3(s->end);
    s->duration = duration;
    s->timer = duration;
}

void ovl_09524_6c30(LightTask *task)
{
    float id[16];
    float rot[16];
    float base[4];
    float out[4];
    LightMgr *mgr = (LightMgr *)task->user;
    LightSlot *d = mgr->dir;
    LightSlot *c = mgr->col;
    int i;
    int j;
    float t;

    base[0] = 0.0f;
    base[1] = 0.0f;
    base[2] = 1.0f;
    base[3] = 1.0f;
    func_002DD128(id);

    for (i = 0; i < 3; i++) {
        if (d->timer > 0) {
            d->timer--;
        }
        t = (float)d->timer / (float)d->duration;
        for (j = 0; j < 2; j++) {
            float a = ovl_4998(d->start[j], d->end[j]) * (1.0f - t) + d->start[j] * t;
            if (a > 3.1415927f) {
                a -= 6.2831855f;
            } else if (a < -3.1415927f) {
                a += 6.2831855f;
            }
            d->cur[j] = a;
        }
        func_002DD270(rot, id, d->cur[0]);
        func_002DD318(rot, rot, d->cur[1]);
        d++;
        func_002DCE08(out, rot, base);
        func_00106508(i, out);

        if (c->timer > 0) {
            c->timer--;
        }
        t = (float)c->timer / (float)c->duration;
        for (j = 0; j < 3; j++) {
            c->cur[j] = c->end[j] * (1.0f - t) + c->start[j] * t;
        }
        c->cur[3] = 1.0f;
        func_00106610(i, c->cur);
        c++;
    }

    {
        if (c->timer > 0) {
            c->timer--;
        }
        t = (float)c->timer / (float)c->duration;
        for (j = 0; j < 3; j++) {
            c->cur[j] = c->end[j] * (1.0f - t) + c->start[j] * t;
        }
        c->cur[3] = 1.0f;
        func_00106610(i, c->cur);
    }
}
