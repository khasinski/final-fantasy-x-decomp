typedef unsigned char u8;
typedef struct { void *a; } Msg1;
typedef struct { void *a; void *b; } Msg2;
extern void fn_ovl_1cb0(void);
extern void fn_ovl_dcb8(void *);
extern void fn_ovl_2ed8(void *);
extern void fn_ovl_23e0(void *);
extern void fn_sys_2b4980(void *);
extern void *fn_sys_2b49a0(void *, int, int);
extern void fn_sys_2678e0(void *, void *);
extern void fn_sys_267a68(void *, void *, void *, int);
extern void fn_sys_2d02e8(void *, int, int, int);
extern void fn_sys_2944b0(void *, int, int, int);

extern void *g_ovl_ptr_4c;
extern void *g_ovl_ptr_668;
extern void *g_ovl_ptr_ed7c;
extern u8 g_ovl_dat_a30[];
extern u8 g_ovl_dat_a48[];
extern u8 g_ovl_dat_a68[];
extern u8 g_ovl_dat_50[];
extern u8 g_ovl_dat_ed50[];
extern u8 g_ovl_dat_1730[];
extern u8 g_ovl_buf_db23f0[];
extern u8 g_ovl_buf_bb23f0[];

static __inline__ void call_dcb8(void *a) { void *pad[4]; Msg1 m; m.a = a; fn_ovl_dcb8(&m); }
static __inline__ void call_2ed8(void *a, void *b) { Msg2 m; m.a = a; m.b = b; fn_ovl_2ed8(&m); }

int ovl_09386_3b00(void) {
    void *p;
    fn_ovl_1cb0();
    g_ovl_ptr_4c = g_ovl_buf_db23f0;
    call_dcb8(g_ovl_dat_a30);
    call_2ed8(g_ovl_dat_a48, 0);
    g_ovl_dat_a48[27] = 1;
    call_2ed8(g_ovl_dat_a68, 0);
    fn_sys_2b4980(g_ovl_ptr_668);
    p = fn_sys_2b49a0(g_ovl_ptr_668, 8, 0);
    g_ovl_ptr_ed7c = p;
    fn_sys_2678e0(p, g_ovl_dat_50);
    fn_sys_267a68(g_ovl_dat_ed50, g_ovl_ptr_ed7c, g_ovl_buf_bb23f0, 0x80000);
    fn_sys_2d02e8(g_ovl_ptr_668, 0, 1000, 2);
    fn_sys_2944b0(g_ovl_ptr_668, 0, 1000, 2);
    fn_ovl_23e0(g_ovl_dat_1730);
    return 0;
}
