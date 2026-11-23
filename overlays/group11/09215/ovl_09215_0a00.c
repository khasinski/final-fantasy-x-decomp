/* 09215 effect init (296 B). */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x14];
    int w14;
    u8 pad18[0x08];
    int w20;
    int w24;
    int w28;
    short h2C;
} OvlState;

typedef struct {
    u8 pad00[0x18];
    unsigned char b18;
} OvlTaskObj;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern u8 g_ovl_dat_0040[];
extern int g_ovl_6100;
extern OvlState g_ovl_6108;
extern void *g_ovl_ptr_9340;
extern OvlMgr g_ovl_mgr;
extern void *g_ovl_ptr_9388;
extern void *g_ovl_ptr_938c;

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_0b28(void);
extern void fn_ovl_0b58(void);
extern void fn_ovl_0fa0(void);
extern void fn_ovl_1390(int, int);
extern OvlTaskObj *fn_ovl_3be8(void *);
extern void fn_ovl_3db0(OvlTaskObj *);
extern void fn_ovl_3e70(void *, void *, void *, int);
extern void fn_ovl_5c98(void *, int);

int ovl_09215_0a00(void)
{
    u8 *p = g_ovl_buf;
    OvlMgr *mgr;
    OvlTaskObj *t;

    g_ovl_ptr_9388 = p;
    g_ovl_ptr_938c = p + 0x40000;
    g_ovl_ptr_9340 = p + 0x140000;
    fn_ovl_1390(g_ovl_6100, 0);
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3e70(mgr, g_ovl_dat_0040, g_ovl_ptr_9388, 0x40000);
    g_ovl_6108.w14 = 1;
    g_ovl_6108.w28 = 0;
    g_ovl_6108.w20 = 0;
    g_ovl_6108.w24 = 0;
    g_ovl_6108.h2C = 0;
    t = fn_ovl_3be8((void *)fn_ovl_0b28);
    t->b18 = 1;
    fn_ovl_3db0(t);
    fn_ovl_3db0(fn_ovl_3be8((void *)fn_ovl_0b58));
    fn_ovl_5c98(p + 0x160000, 256);
    t = fn_ovl_3be8((void *)fn_ovl_0fa0);
    t->b18 = 2;
    fn_ovl_3db0(t);
    return 0;
}
