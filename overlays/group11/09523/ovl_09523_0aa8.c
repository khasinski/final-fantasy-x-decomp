/* 09523 effect initializer (168 B). */

#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0540[];
extern u8 g_ovl_script[];
extern void *g_ovl_ptr_6ee0;
extern void *g_ovl_ptr_6ee4;
extern OvlMgr g_ovl_mgr;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_3888(void *, void *, void *, int);
extern void fn_ovl_6840(void *, void *);
extern void *fn_ovl_3600(void *);
extern void fn_ovl_37c8(void *);
extern void fn_ovl_0b50(void);

int ovl_09523_0aa8(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr = &g_ovl_mgr;

    g_ovl_ptr_6ee4 = p + 0x40000;
    g_ovl_ptr_6ee0 = p;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3888(mgr, g_ovl_dat_0040, g_ovl_ptr_6ee0, 0x40000);
    fn_ovl_6840(g_ovl_script, g_ovl_dat_0540);
    fn_ovl_37c8(fn_ovl_3600((void *)fn_ovl_0b50));
    return 0;
}
