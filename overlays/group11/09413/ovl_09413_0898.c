/* 09413 init (200 B). */

#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    s32 unk2C;
} OvlMgr;

extern u32 g_ovl_6750;
extern u8 *g_ovl_ptr_6930;
extern u8 *g_ovl_ptr_6934;
extern s32 g_ovl_3d0[2];
extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern u8 g_ovl_dat_0388[];
extern u8 g_ovl_6890[];
extern OvlMgr g_ovl_mgr;

extern void fn_ovl_0ad0(u32);
extern s32 func_002B49A0(void *, s32, s32);
extern void fn_ovl_3668(void *, void *, void *, s32);
extern void fn_ovl_6620(void *, void *);
extern s32 fn_ovl_33e0(void *);
extern void fn_ovl_35a8(s32);
extern void fn_ovl_0960(void);

s32 ovl_09413_0898(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;

    g_ovl_ptr_6930 = p;
    g_ovl_ptr_6934 = p + 0x40000;
    g_ovl_3d0[0] = 0x14;
    g_ovl_3d0[1] = 0;
    fn_ovl_0ad0(g_ovl_6750);
    mgr = &g_ovl_mgr;
    mgr->unk2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3668(mgr, g_ovl_dat_0040, g_ovl_ptr_6930, 0x40000);
    fn_ovl_6620(g_ovl_6890, g_ovl_dat_0388);
    fn_ovl_35a8(fn_ovl_33e0((void *)fn_ovl_0960));
    return 0;
}
