/* Shared 09241-family overlay setup (120 B, 4+ containers). */

extern int g_ovl_arg;
extern int g_ovl_flag;
extern unsigned char g_ovl_res[];

extern void fn_ovl_2aa8(void);
extern void fn_ovl_3190(void);
extern void fn_ovl_3c10(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void fn_ovl_2378(void *, int, int);
extern void fn_ovl_2c40(void *, int, int);

int ovl_09241_05c0(int arg)
{
    g_ovl_arg = arg;
    fn_ovl_2aa8();
    fn_ovl_3190();
    fn_ovl_3c10();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(g_ovl_res);
    fn_ovl_2378(g_ovl_res, 0, 1000);
    fn_ovl_2c40(g_ovl_res, 0, 1000);
    g_ovl_flag = 0;
    return 0;
}
