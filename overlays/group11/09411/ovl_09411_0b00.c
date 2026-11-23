/* 09411 main init (276 B, 09411 @ 0x01B00B00). */

#include "common.h"

typedef struct {
    int w00;
    int w04;
} StatePair;

typedef struct {
    u8 pad00[0x2C];
    void *p2C;
} EffMgr;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

extern u8 g_buf_bac0[];
extern int g_arg_7a20;
extern StatePair g_state_0608;
extern u8 *g_ptr_7f90;
extern u8 *g_ptr_7f94;
extern u8 *g_ptr_7f4c;
extern EffMgr g_mgr_7f50;
extern u8 g_buf_d740[];
extern u8 g_data_0040[];
extern u8 g_data_7ef0[];
extern u8 g_data_0590[];
extern u8 g_fn_0c18[];
extern u8 g_fn_0c48[];

extern void func_01B01298(int);
extern void *func_002B49A0(void *, int, int);
extern void func_01B03E30(void *, void *, void *, int);
extern void func_01B07498(void *, void *);
extern TaskObj *func_01B03BA8(void *);
extern void func_01B03D70(TaskObj *);
extern void func_01B075B8(void *, int);

int ovl_09411_0b00(void)
{
    u8 *p = g_buf_bac0;
    TaskObj *t;

    g_ptr_7f90 = p;
    g_ptr_7f94 = p + 0x40000;
    g_ptr_7f4c = p + 0x140000;
    g_state_0608.w00 = 0x14;
    g_state_0608.w04 = 0;
    func_01B01298(g_arg_7a20);
    {
        EffMgr *mgr = &g_mgr_7f50;
        mgr->p2C = func_002B49A0(g_buf_d740, 8, 0);
        func_01B03E30(mgr, g_data_0040, g_ptr_7f90, 0x40000);
    }
    func_01B07498(g_data_7ef0, g_data_0590);
    t = func_01B03BA8(g_fn_0c18);
    t->b18 = 1;
    func_01B03D70(t);
    func_01B075B8(p + 0x160000, 0x100);
    t = func_01B03BA8(g_fn_0c48);
    t->b18 = 2;
    func_01B03D70(t);
    return 0;
}
