/* Shared 09128-family overlay setup (144 B). */

extern int g_ovl_arg;
extern int g_ovl_flag;
extern unsigned char g_ovl_res[];

extern void fn_ovl_0ce0(void);
extern void fn_ovl_2e48(void);
extern void fn_ovl_3530(void);
extern void fn_ovl_3fb0(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void fn_ovl_2718(void *, int, int);
extern void fn_ovl_2fe0(void *, int, int);
extern void fn_ovl_2ff0(void *, int, int);

int ovl_09128_0720(int arg)
{
    g_ovl_arg = arg;
    fn_ovl_0ce0();
    fn_ovl_2e48();
    fn_ovl_3530();
    fn_ovl_3fb0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(g_ovl_res);
    fn_ovl_2718(g_ovl_res, 0, 1000);
    fn_ovl_2fe0(g_ovl_res, 0, 1000);
    fn_ovl_2ff0(g_ovl_res, 1, 0);
    g_ovl_flag = 0;
    return 0;
}
