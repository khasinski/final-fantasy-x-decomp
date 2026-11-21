typedef unsigned char u8;
extern void fn_ovl_1130(void);
extern void fn_ovl_a010(void *);
extern void fn_ovl_1e58(void *);
extern void fn_sys_2b4980(void *);
extern void *fn_sys_2b49a0(void *, int, int);
extern void fn_sys_2678e0(void *, void *);
extern void fn_sys_267a68(void *, void *, void *, int);
extern void fn_sys_2d02e8(void *, int, int, int);
extern void fn_sys_2944b0(void *, int, int, int);
extern void fn_sys_294468(void *, int, int);
extern void fn_ovl_1338(void *);

extern void *g_ovl_ptr_4c;
extern u8 g_ovl_dat_50[];
extern void *g_ovl_ptr_488;
extern u8 g_ovl_dat_850[];
extern u8 g_ovl_dat_868[];
extern u8 g_ovl_dat_888[];
extern u8 g_ovl_dat_9c0[];
extern u8 g_ovl_dat_b0b0[];
extern void *g_ovl_ptr_b0dc;
extern u8 g_ovl_dat_1b90bb0[];
extern u8 g_ovl_dat_1d90bb0[];

int ovl_09124_15e0(void) {
    void *m0[2];
    void *m1;
    fn_ovl_1130();
    g_ovl_ptr_4c = g_ovl_dat_1d90bb0;
    m1 = g_ovl_dat_850;
    fn_ovl_a010(&m1);
    m0[0] = g_ovl_dat_868;
    m0[1] = 0;
    fn_ovl_1e58(m0);
    g_ovl_dat_868[27] = 1;
    m0[0] = g_ovl_dat_888;
    m0[1] = 0;
    fn_ovl_1e58(m0);
    fn_sys_2b4980(g_ovl_ptr_488);
    g_ovl_ptr_b0dc = fn_sys_2b49a0(g_ovl_ptr_488, 8, 0);
    fn_sys_2678e0(g_ovl_ptr_b0dc, g_ovl_dat_50);
    fn_sys_267a68(g_ovl_dat_b0b0, g_ovl_ptr_b0dc, g_ovl_dat_1b90bb0, 0x200000);
    fn_sys_2d02e8(g_ovl_ptr_488, 0, 1000, 2);
    fn_sys_2944b0(g_ovl_ptr_488, 0, 1000, 2);
    fn_sys_294468(fn_sys_2b49a0(g_ovl_ptr_488, 6, 1), 0, 2);
    fn_ovl_1338(g_ovl_dat_9c0);
    return 0;
}
