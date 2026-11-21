/* Shared 09486-family overlay setup (128 B). */

extern int g_ovl_arg;
extern int g_ovl_flag;
extern unsigned char g_ovl_res[];

extern void fn_ovl_0f00(void);
extern void fn_ovl_3068(void);
extern void fn_ovl_3750(void);
extern void fn_ovl_41d0(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void fn_ovl_2938(void *, int, int);
extern void fn_ovl_3200(void *, int, int);

int ovl_09486_0920(int arg)
{
    g_ovl_arg = arg;
    fn_ovl_0f00();
    fn_ovl_3068();
    fn_ovl_3750();
    fn_ovl_41d0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(g_ovl_res);
    fn_ovl_2938(g_ovl_res, 0, 1000);
    fn_ovl_3200(g_ovl_res, 0, 1000);
    g_ovl_flag = 0;
    return 0;
}
