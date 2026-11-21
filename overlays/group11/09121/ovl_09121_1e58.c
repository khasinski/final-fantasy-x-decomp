typedef unsigned char u8;

extern void fn_ovl_1870(void);
extern void fn_ovl_a868(void *msg);
extern void fn_ovl_26b0(void *msg);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00294468(void *, int, int);
extern void fn_ovl_1ce8(void *);

extern void *g_ovl_ptr_004c;
extern u8 g_ovl_buf_end[];
extern u8 g_ovl_dat_0750[];
extern u8 g_ovl_dat_0768[];
extern u8 g_ovl_dat_0788[];
extern void *g_ovl_p370;
extern void *g_ovl_res;
extern u8 g_ovl_dat_0050[];
extern u8 g_ovl_mgr[];
extern u8 g_ovl_buf[];
extern u8 g_ovl_eff[];

int ovl_09121_1e58(void) {
    void *m0[4];
    void *m16;
    void *p;

    fn_ovl_1870();

    g_ovl_ptr_004c = g_ovl_buf_end;
    m16 = g_ovl_dat_0750;
    fn_ovl_a868(&m16);

    m0[0] = g_ovl_dat_0768;
    m0[1] = 0;
    fn_ovl_26b0(m0);
    g_ovl_dat_0768[27] = 1;

    m0[0] = g_ovl_dat_0788;
    m0[1] = 0;
    fn_ovl_26b0(m0);

    func_002B4980(g_ovl_p370);
    p = func_002B49A0(g_ovl_p370, 8, 1);
    g_ovl_res = p;
    func_002678E0(p, g_ovl_dat_0050);
    func_00267A68(g_ovl_mgr, g_ovl_res, g_ovl_buf, 0x200000);
    func_002D02E8(g_ovl_p370, 0, 1000, 2);
    func_002944B0(g_ovl_p370, 0, 1000, 2);
    func_00294468(func_002B49A0(g_ovl_p370, 6, 1), 0, 2);
    fn_ovl_1ce8(g_ovl_eff);
    return 0;
}
