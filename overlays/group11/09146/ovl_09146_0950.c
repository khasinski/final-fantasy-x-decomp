/* Shared 09146-family overlay setup (144 B). */

extern int g_ovl_arg;
extern int g_ovl_flag;
extern unsigned char g_ovl_res[];

extern void fn_ovl_0e90(void);
extern void fn_ovl_2ff8(void);
extern void fn_ovl_36e0(void);
extern void fn_ovl_4160(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void fn_ovl_28c8(void *, int, int);
extern void fn_ovl_3190(void *, int, int);
extern void fn_ovl_31a0(void *, int, int);

int ovl_09146_0950(int arg)
{
    g_ovl_arg = arg;
    fn_ovl_0e90();
    fn_ovl_2ff8();
    fn_ovl_36e0();
    fn_ovl_4160();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(g_ovl_res);
    fn_ovl_28c8(g_ovl_res, 0, 1000);
    fn_ovl_3190(g_ovl_res, 0, 1000);
    fn_ovl_31a0(g_ovl_res, 2, 0);
    g_ovl_flag = 0;
    return 0;
}
