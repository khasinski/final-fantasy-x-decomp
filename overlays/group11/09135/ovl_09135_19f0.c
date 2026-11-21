typedef unsigned char u8;

extern void fn_ovl_14e0(void);
extern void fn_ovl_c768(void *);
extern void fn_ovl_2310(void *);
extern void fn_ovl_7068(void *);
extern void fn_ovl_83a0(void *);
extern void fn_ovl_7710(void *);
extern void fn_ovl_9308(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00294468(void *, int, int);
extern void fn_ovl_1778(void *);

extern void *g_ovl_p4c;
extern u8 g_ovl_dat_0050[];
extern void *g_ovl_p4d8;
extern u8 g_ovl_b4f0;
extern u8 g_ovl_dat_0690[];
extern u8 g_ovl_dat_08a0[];
extern u8 g_ovl_obj_8b8[];
extern u8 g_ovl_dat_08d8[];
extern u8 g_ovl_obj_900[];
extern u8 g_ovl_obj_940[];
extern u8 g_ovl_obj_980[];
extern u8 g_ovl_dat_09d0[];
extern u8 g_ovl_dat_0cf0[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_res;
extern u8 g_ovl_buf_ba[];
extern u8 g_ovl_buf_ca[];

int ovl_09135_19f0(void) {
    void *m0[10];
    void *m1;
    void **m16;
    u8 b;

    fn_ovl_14e0();
    g_ovl_p4c = g_ovl_buf_ca;
    m1 = g_ovl_dat_08a0;
    fn_ovl_c768(&m1);

    m0[0] = g_ovl_obj_8b8;
    m0[1] = 0;
    fn_ovl_2310(m0);
    g_ovl_obj_8b8[27] = 1;

    m0[0] = g_ovl_dat_08d8;
    m0[1] = 0;
    fn_ovl_2310(m0);

    m0[0] = g_ovl_obj_900;
    m0[1] = g_ovl_obj_8b8;
    fn_ovl_7068(m0);

    m0[0] = g_ovl_obj_940;
    m0[1] = g_ovl_obj_8b8;
    fn_ovl_83a0(m0);

    m0[0] = g_ovl_obj_980;
    m0[1] = g_ovl_obj_8b8;
    fn_ovl_7710(m0);

    b = g_ovl_b4f0;
    g_ovl_obj_900[48] = b;
    g_ovl_obj_940[52] = b;
    g_ovl_obj_980[64] = b;
    m16 = m0 + 4;
    m16[0] = g_ovl_dat_09d0;
    m16[1] = g_ovl_obj_8b8;
    m16[2] = g_ovl_dat_0690;
    m16[3] = g_ovl_obj_900;
    m16[4] = g_ovl_obj_940;
    m16[5] = g_ovl_obj_980;
    fn_ovl_9308(m16);

    func_002B4980(g_ovl_p4d8);
    g_ovl_res = func_002B49A0(g_ovl_p4d8, 8, 1);
    func_002678E0(g_ovl_res, g_ovl_dat_0050);
    func_00267A68(g_ovl_mgr, g_ovl_res, g_ovl_buf_ba, 0x100000);
    func_002D02E8(g_ovl_p4d8, 0, 1000, 2);
    func_002944B0(g_ovl_p4d8, 0, 1000, 2);
    func_00294468(func_002B49A0(g_ovl_p4d8, 6, 1), 0, 2);
    fn_ovl_1778(g_ovl_dat_0cf0);
    return 0;
}
