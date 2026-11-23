/* Shared 09391/09535 effect init (564 B). */

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
extern int g_ovl_dat_04e0[];
extern int g_ovl_6430;
extern u8 g_ovl_6438[];
extern u8 g_ovl_6460[];
extern void *g_ovl_ptr_64e0;
extern OvlMgr g_ovl_mgr;
extern void *g_ovl_ptr_6528;
extern void *g_ovl_ptr_652c;

extern void *func_002B49A0(void *, int, int);
extern u8 *func_001E58F8(int, int *);
extern void fn_ovl_0b98(void);
extern void fn_ovl_0bc8(void);
extern int fn_ovl_0c60(int);
extern void fn_ovl_1290(void);
extern void fn_ovl_3298(int, void *, void *);
extern void fn_ovl_36e0(int);
extern OvlTaskObj *fn_ovl_3e70(void *);
extern void fn_ovl_4038(OvlTaskObj *);
extern void fn_ovl_40f8(void *, void *, void *, int);
extern void fn_ovl_5c50(void *, float, float, int, int);
extern void fn_ovl_5e88(void *, int);

int ovl_09391_0960(void)
{
    int count;
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    u8 *list;
    OvlWork *work;
    OvlTaskObj *t;
    int i;
    int delay;

    g_ovl_ptr_6528 = p;
    g_ovl_ptr_652c = p + 0x40000;
    g_ovl_ptr_64e0 = p + 0x140000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_40f8(mgr, g_ovl_dat_0040, g_ovl_ptr_6528, 0x40000);

    list = func_001E58F8(g_ovl_6430, &count);
    work = (OvlWork *)(p + 0x190000);
    delay = 1;
    for (i = 0; i < count; i++, work++) {
        work->w518 = fn_ovl_0c60(list[i]);
        work->w51C = 12;
        work->w520 = delay;
        delay += 25;
        t = fn_ovl_3e70((void *)fn_ovl_1290);
        t->w14 = work;
        fn_ovl_4038(t);
    }

    {
        int d = delay - 25;
        g_ovl_dat_04e0[1] = d;
        fn_ovl_3298(-1, g_ovl_6438, (d > 0) ? &g_ovl_dat_04e0[0] : &g_ovl_dat_04e0[2]);
    }
    fn_ovl_5c50(g_ovl_6460, 1.0f, 0.5f, 8, 0);
    fn_ovl_5c50(g_ovl_6460 + 0x40, 0.5f, 1.0f, 16, delay + 20);
    fn_ovl_36e0(1);
    t = fn_ovl_3e70((void *)fn_ovl_0b98);
    t->b18 = 1;
    fn_ovl_4038(t);
    fn_ovl_5e88(p + 0x180000, 512);
    t = fn_ovl_3e70((void *)fn_ovl_0bc8);
    t->b18 = 2;
    fn_ovl_4038(t);
    return 0;
}
