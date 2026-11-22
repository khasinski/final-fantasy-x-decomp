/* 09682 init, script task, update task, and reset (456 B span / 448 B code, 4 funcs). */

#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

typedef struct {
    u8 pad00[0x130];
    int done;
} OvlWork;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0510[];
extern u8 g_ovl_script[];
extern int g_ovl_arg0;
extern void *g_ovl_ptr_69a0;
extern void *g_ovl_ptr_69a4;
extern OvlWork *g_ovl_work;
extern OvlMgr g_ovl_mgr;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3878(void *, void *, void *, int);
extern void fn_ovl_6830(void *, void *);
extern OvlTask *fn_ovl_35f0(void *);
extern void fn_ovl_37b8(void *);
extern int fn_ovl_6850(void *);
extern void fn_ovl_0bd8(void);
extern void fn_ovl_3670(void *);
extern int fn_ovl_3a30(void *, void *);
extern void func_001CDDD8(int);

void ovl_09682_0af8(void *task);
void ovl_09682_0b60(void);
void ovl_09682_0bc8(void);

int ovl_09682_0a10(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlTask *task;

    g_ovl_ptr_69a4 = p + 0x40000;
    g_ovl_ptr_69a0 = p;
    g_ovl_work = (OvlWork *)(p + 0x140000);
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3878(mgr, g_ovl_dat_0040, g_ovl_ptr_69a0, 0x40000);
    ovl_09682_0bc8();
    fn_ovl_6830(g_ovl_script, g_ovl_dat_0510);
    task = fn_ovl_35f0((void *)ovl_09682_0af8);
    task->b18 = 1;
    fn_ovl_37b8(task);
    task = fn_ovl_35f0((void *)ovl_09682_0b60);
    task->b18 = 2;
    fn_ovl_37b8(task);
    return 0;
}

void ovl_09682_0af8(void *task)
{
    OvlWork *w = g_ovl_work;

    if (fn_ovl_6850(g_ovl_script) == 1) {
        w->done = 1;
        fn_ovl_0bd8();
        fn_ovl_3670(task);
    }
}

void ovl_09682_0b60(void)
{
    OvlWork *w = g_ovl_work;

    if (fn_ovl_3a30(&g_ovl_mgr, g_ovl_ptr_69a4) == 1 && w->done == 1) {
        func_001CDDD8(g_ovl_arg0);
    }
}

void ovl_09682_0bc8(void)
{
    g_ovl_work->done = 0;
}
