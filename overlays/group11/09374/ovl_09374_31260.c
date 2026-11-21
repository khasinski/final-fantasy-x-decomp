typedef unsigned char u8;

extern void fn_ovl_30ad0(void);
extern void fn_ovl_39eb8(void *msg);
extern void fn_ovl_31d00(void *msg);
extern void fn_sys_2b4980(void *a0);
extern void *fn_sys_2b49a0(void *a0, int a1, int a2);
extern void fn_sys_2678e0(void *a0, void *a1);
extern void fn_sys_267a68(void *a0, void *a1, void *a2, int a3);
extern void fn_sys_2d02e8(void *a0, int a1, int a2, int a3);
extern void fn_sys_2944b0(void *a0, int a1, int a2, int a3);
extern void fn_ovl_311f8(void *a0);

extern void *g_ovl_ptr_4c;
extern u8 g_ovl_dat_50[];
extern void *g_ovl_ptr_370;
extern u8 g_ovl_dat_750[];
extern u8 g_ovl_dat_768[];
extern u8 g_ovl_dat_788[];
extern void *g_ovl_ptr_3af7c;
extern u8 g_ovl_dat_3af50[];
extern u8 g_ovl_dat_80070[];
extern u8 g_ovl_dat_180070[];
extern u8 g_ovl_dat_305f0[];

static __inline__ void call_39eb8(void *a0) {
    void *m[1];
    m[0] = a0;
    fn_ovl_39eb8(m);
}

int ovl_09374_31260(void) {
    void *m0[2];
    void *p;

    fn_ovl_30ad0();
    g_ovl_ptr_4c = g_ovl_dat_180070;

    call_39eb8(g_ovl_dat_750);

    m0[0] = g_ovl_dat_768;
    m0[1] = 0;
    fn_ovl_31d00(m0);
    g_ovl_dat_768[27] = 1;

    m0[0] = g_ovl_dat_788;
    m0[1] = 0;
    fn_ovl_31d00(m0);

    fn_sys_2b4980(g_ovl_ptr_370);
    p = fn_sys_2b49a0(g_ovl_ptr_370, 8, 2);
    g_ovl_ptr_3af7c = p;
    fn_sys_2678e0(p, g_ovl_dat_50);
    fn_sys_267a68(g_ovl_dat_3af50, g_ovl_ptr_3af7c, g_ovl_dat_80070, 0x100000);
    fn_sys_2d02e8(g_ovl_ptr_370, 0, 1000, 2);
    fn_sys_2944b0(g_ovl_ptr_370, 0, 1000, 2);
    fn_ovl_311f8(g_ovl_dat_305f0);
    return 0;
}
