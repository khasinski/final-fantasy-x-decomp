/* 09715/09757 init, script task, and flag setter (276 B span / 272 B code, 3 funcs). */

#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0310[];
extern u8 g_ovl_script[];
extern int g_ovl_arg0;
extern int g_ovl_w6a14;
extern int g_ovl_w6a18;
extern void *g_ovl_ptr_6b90;
extern void *g_ovl_ptr_6b94;
extern OvlMgr g_ovl_mgr;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_38d0(void *, void *, void *, int);
extern void fn_ovl_6888(void *, void *);
extern OvlTask *fn_ovl_3648(void *);
extern void fn_ovl_3810(void *);
extern int fn_ovl_68a8(void *);
extern void func_001CDDD8(int);

void ovl_09715_08d0(void);

int ovl_09715_0808(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlTask *task;

    g_ovl_ptr_6b94 = p + 0x40000;
    g_ovl_ptr_6b90 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_38d0(mgr, g_ovl_dat_0040, g_ovl_ptr_6b90, 0x40000);
    g_ovl_w6a14 = -1;
    g_ovl_w6a18 = 0;
    fn_ovl_6888(g_ovl_script, g_ovl_dat_0310);
    task = fn_ovl_3648((void *)ovl_09715_08d0);
    task->b18 = 2;
    fn_ovl_3810(task);
    return 0;
}

void ovl_09715_08d0(void)
{
    if (fn_ovl_68a8(g_ovl_script) == 1) {
        func_001CDDD8(g_ovl_arg0);
    }
}

int ovl_09715_0908(void)
{
    g_ovl_w6a18 = 1;
    return 0;
}
