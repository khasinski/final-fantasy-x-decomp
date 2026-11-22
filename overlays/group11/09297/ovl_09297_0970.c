#include "common.h"

extern int g_7430;
extern int g_7434;
extern u8 g_res_data[];

extern void ovl_1188(void);
extern void ovl_32f0(void);
extern void ovl_39d8(void);
extern void ovl_4458(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void ovl_2bc0(void *, int, int);
extern void ovl_3488(void *, int, int);

int ovl_09297_0970(int arg0)
{
    g_7430 = arg0;
    ovl_1188();
    ovl_32f0();
    ovl_39d8();
    ovl_4458();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(g_res_data);
    ovl_2bc0(g_res_data, 0, 8);
    ovl_3488(g_res_data, 0, 1000);
    g_7434 = 0;
    return 0;
}
