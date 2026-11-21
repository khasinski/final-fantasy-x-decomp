typedef struct {
    int pad0[11];
    int w2C;
} OvlMgr;

typedef struct {
    unsigned char pad0[0x20];
    unsigned char r0;
    unsigned char g0;
    unsigned char b0;
    unsigned char a0;
    unsigned char r1;
    unsigned char g1;
    unsigned char b1;
    unsigned char a1;
    unsigned char pad28[0x0C];
    int w34;
    unsigned char pad38[0x08];
} OvlFade;

typedef struct {
    unsigned char pad0[0x14];
    int w14;
    unsigned char b18;
} OvlTask;

extern unsigned char g_ovl_buf[];
extern unsigned char g_ovl_dat_0040[];
extern int g_ovl_cfg[];
extern int g_ovl_5620;
extern OvlFade g_ovl_fades[];
extern OvlMgr g_ovl_mgr;
extern unsigned char *g_ovl_ptr_62d0;
extern unsigned char *g_ovl_ptr_62d4;
extern unsigned char g_ovl_res[];

extern int func_002B49A0(void *, int, int);
extern void fn_ovl_0d18(void);
extern void fn_ovl_10c8(int);
extern void fn_ovl_3248(int);
extern OvlTask *fn_ovl_39d8(void (*)(void));
extern void fn_ovl_3ba0(OvlTask *);
extern void fn_ovl_3c60(OvlMgr *, void *, void *, int);
extern void fn_ovl_5278(OvlFade *, float, float, int, int);

int ovl_09369_0b80(void) {
    unsigned char *p;
    OvlMgr *mgr;
    OvlFade *f;
    OvlTask *t;

    p = g_ovl_buf;
    g_ovl_ptr_62d0 = p;
    g_ovl_ptr_62d4 = p + 0x80000;
    g_ovl_cfg[0] = 20;
    g_ovl_cfg[1] = 0;
    fn_ovl_10c8(g_ovl_5620);

    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3c60(mgr, g_ovl_dat_0040, g_ovl_ptr_62d0, 0x80000);

    f = g_ovl_fades;
    fn_ovl_5278(f, 1.0f, 0.5f, 64, 0);
    f->a0 = 128;
    f->b0 = 128;
    f->g0 = 128;
    f->r0 = 128;
    f->r1 = 144;
    f->a1 = 128;
    f->b1 = 128;
    f->g1 = 128;
    f->w34 = 1;

    f++;
    fn_ovl_5278(f, 0.5f, 1.0f, 64, 300);
    f->r0 = 144;
    f->a0 = 128;
    f->b0 = 128;
    f->g0 = 128;
    f->a1 = 128;
    f->b1 = 128;
    f->g1 = 128;
    f->r1 = 128;
    f->w34 = 1;

    fn_ovl_3248(1);
    t = fn_ovl_39d8(fn_ovl_0d18);
    t->w14 = 64;
    t->b18 = 2;
    fn_ovl_3ba0(t);
    return 0;
}
