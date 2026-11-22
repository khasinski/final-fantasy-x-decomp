/* 09733 init, script task, update task, and reset (456 B span / 448 B code, 4 funcs). */

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
    u8 pad00[0x390];
    int done;
} OvlWork;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_06c0[];
extern u8 g_ovl_script[];
extern int g_ovl_arg0;
extern void *g_ovl_ptr_6bd8;
extern void *g_ovl_ptr_6bdc;
extern OvlWork *g_ovl_work;
extern OvlMgr g_ovl_mgr;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3ab0(void *, void *, void *, int);
extern void fn_ovl_6a68(void *, void *);
extern OvlTask *fn_ovl_3828(void *);
extern void fn_ovl_39f0(void *);
extern int fn_ovl_6a88(void *);
extern void fn_ovl_0d78(void);
extern void fn_ovl_38a8(void *);
extern int fn_ovl_3c68(void *, void *);
extern void func_001CDDD8(int);

void ovl_09733_0c98(void *task);
void ovl_09733_0d00(void);
void ovl_09733_0d68(void);

int ovl_09733_0bb0(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlTask *task;

    g_ovl_ptr_6bdc = p + 0x40000;
    g_ovl_ptr_6bd8 = p;
    g_ovl_work = (OvlWork *)(p + 0x140000);
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3ab0(mgr, g_ovl_dat_0040, g_ovl_ptr_6bd8, 0x40000);
    ovl_09733_0d68();
    fn_ovl_6a68(g_ovl_script, g_ovl_dat_06c0);
    task = fn_ovl_3828((void *)ovl_09733_0c98);
    task->b18 = 1;
    fn_ovl_39f0(task);
    task = fn_ovl_3828((void *)ovl_09733_0d00);
    task->b18 = 2;
    fn_ovl_39f0(task);
    return 0;
}

void ovl_09733_0c98(void *task)
{
    OvlWork *w = g_ovl_work;

    if (fn_ovl_6a88(g_ovl_script) == 1) {
        w->done = 1;
        fn_ovl_0d78();
        fn_ovl_38a8(task);
    }
}

void ovl_09733_0d00(void)
{
    OvlWork *w = g_ovl_work;

    if (fn_ovl_3c68(&g_ovl_mgr, g_ovl_ptr_6bdc) == 1 && w->done == 1) {
        func_001CDDD8(g_ovl_arg0);
    }
}

void ovl_09733_0d68(void)
{
    g_ovl_work->done = 0;
}
