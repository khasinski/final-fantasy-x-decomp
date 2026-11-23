/* Shared 09176/09178/09177/09179 effect init (476 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x518];
    int w518;
    int w51C;
    int w520;
    u8 pad524[0x0C];
} OvlWork;

typedef struct {
    u8 pad00[0x14];
    void *w14;
    unsigned char b18;
} OvlTaskObj;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern int g_ovl_6320;
extern int g_ovl_6328[4];
extern u8 g_ovl_6350[];
extern void *g_ovl_ptr_63d0;
extern OvlMgr g_ovl_mgr;
extern void *g_ovl_ptr_6418;
extern void *g_ovl_ptr_641c;

extern void *func_002B49A0(void *, int, int);
extern int func_001BB3F0(int, int, int *, int *, int *);
extern void fn_ovl_0b28(void);
extern void fn_ovl_0b58(void);
extern void fn_ovl_1180(void);
extern int fn_ovl_1550(int);
extern void fn_ovl_35d0(int);
extern OvlTaskObj *fn_ovl_3d60(void *);
extern void fn_ovl_3f28(OvlTaskObj *);
extern void fn_ovl_3fe8(void *, void *, void *, int);
extern void fn_ovl_5b40(void *, float, float, int, int);
extern void fn_ovl_5d78(void *, int);

int ovl_09176_0948(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlWork *work;
    OvlTaskObj *t;
    int i;
    int delay;

    g_ovl_ptr_6418 = p;
    g_ovl_ptr_641c = p + 0x40000;
    g_ovl_ptr_63d0 = p + 0x140000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3fe8(mgr, g_ovl_dat_0040, g_ovl_ptr_6418, 0x40000);
    {
        int *info = g_ovl_6328;
        info[3] = func_001BB3F0(g_ovl_6320, fn_ovl_1550(-1), &info[0], &info[1], &info[2]);
    }

    work = (OvlWork *)(p + 0x190000);
    delay = 1;
    for (i = 0; i < 1; i++, work++) {
        work->w518 = 0;
        work->w51C = 12;
        work->w520 = delay;
        delay += 30;
        t = fn_ovl_3d60((void *)fn_ovl_1180);
        t->w14 = work;
        fn_ovl_3f28(t);
    }

    fn_ovl_5b40(g_ovl_6350, 1.0f, 0.5f, 8, 0);
    fn_ovl_5b40(g_ovl_6350 + 0x40, 0.5f, 1.0f, 16, 54);
    fn_ovl_35d0(1);
    t = fn_ovl_3d60((void *)fn_ovl_0b28);
    t->b18 = 1;
    fn_ovl_3f28(t);
    fn_ovl_5d78(p + 0x180000, 512);
    t = fn_ovl_3d60((void *)fn_ovl_0b58);
    t->b18 = 2;
    fn_ovl_3f28(t);
    return 0;
}
