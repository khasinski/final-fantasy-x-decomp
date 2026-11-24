typedef unsigned char u8;

extern int g_ovl_9880;
extern int g_ovl_9884;
extern u8 g_ovl_f140[];

extern void func_01B04710(void);
extern void func_01B04DF8(void);
extern void func_01B05878(void);
extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void func_01B03FE0(void *, int, int);
extern void func_01B048A8(void *, int, int);

int ovl_09717_1850(int a0)
{
    g_ovl_9880 = a0;
    func_01B04710();
    func_01B04DF8();
    func_01B05878();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(g_ovl_f140);
    func_01B03FE0(g_ovl_f140, 0, 14);
    func_01B048A8(g_ovl_f140, 0, 1000);
    g_ovl_9884 = 0;
    return 0;
}
