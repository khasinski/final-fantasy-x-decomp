/* Shared init routine (136 B, 09109 @ 0x01B00328). */

#include "common.h"

extern void *g_52d0;
extern int g_52d4;
extern u8 g_b410[];

extern void fn_0a58(void);
extern void fn_2bc0(void);
extern void fn_32a8(void);
extern void fn_3660(void);
extern void func_002B22F8(int, int);
extern void fn_0528(void);
extern void func_002B4980(void *);
extern void fn_2490(void *, int, int);
extern void fn_2d58(void *, int, int);

int ovl_09109_0328(void *a0)
{
    g_52d0 = a0;
    fn_0a58();
    fn_2bc0();
    fn_32a8();
    fn_3660();
    func_002B22F8(0x3400, 0x800);
    fn_0528();
    func_002B4980(g_b410);
    fn_2490(g_b410, 0, 1000);
    fn_2d58(g_b410, 0, 1000);
    g_52d4 = 0;
    return 0;
}
