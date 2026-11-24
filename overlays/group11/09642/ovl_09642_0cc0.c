typedef unsigned char u8;

extern int g_ovl_8fd8;
extern int g_ovl_8fdc;
extern u8 g_ovl_e8a0[];
extern u8 g_ovl_1bc6ba0[];

extern void func_01B01D18(void);
extern void func_01B03E80(void);
extern void func_01B04568(void);
extern void func_01B04FE8(void);
extern void func_002B22F8(int, int);
extern void func_01B00F00(void);
extern void func_002B4980(void *);
extern void func_01B03750(void *, int, int);
extern void func_01B04018(void *, int, int);
extern void func_01B04028(void *, int, int);

int ovl_09642_0cc0(int a0)
{
    g_ovl_8fd8 = a0;
    func_01B01D18();
    func_01B03E80();
    func_01B04568();
    func_01B04FE8();
    func_002B22F8(0x3400, 0x800);
    func_01B00F00();
    func_002B4980(g_ovl_e8a0);
    func_01B03750(g_ovl_e8a0, 0, 1000);
    func_01B04018(g_ovl_e8a0, 0, 1000);
    func_002B4980(g_ovl_1bc6ba0);
    func_01B04018(g_ovl_1bc6ba0, 0, 1000);
    func_002B4980(g_ovl_1bc6ba0);
    func_01B04028(g_ovl_1bc6ba0, 2, 0);
    func_01B04028(g_ovl_1bc6ba0, 3, 1);
    g_ovl_8fdc = 0;
    return 0;
}
