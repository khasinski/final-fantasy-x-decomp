/* 09427 effect initializer (176 B). */

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
extern u8 g_ovl_dat_04c8[];
extern u8 g_ovl_script[];
extern void *g_ovl_ptr_6a40;
extern void *g_ovl_ptr_6a44;
extern OvlMgr g_ovl_mgr;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3778(void *, void *, void *, int);
extern void fn_ovl_6730(void *, void *);
extern OvlTask *fn_ovl_34f0(void *);
extern void fn_ovl_36b8(void *);
extern void fn_ovl_0a88(void);

int ovl_09427_09d8(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;
    OvlTask *task;

    g_ovl_ptr_6a44 = p + 0x40000;
    g_ovl_ptr_6a40 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3778(mgr, g_ovl_dat_0040, g_ovl_ptr_6a40, 0x40000);
    fn_ovl_6730(g_ovl_script, g_ovl_dat_04c8);
    task = fn_ovl_34f0((void *)fn_ovl_0a88);
    task->b18 = 2;
    fn_ovl_36b8(task);
    return 0;
}
