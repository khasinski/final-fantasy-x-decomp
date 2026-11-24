typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
    u8 pad30[0x10];
} OvlSlot40;

typedef struct {
    u8 pad00[0x14];
    int w14;
    u8 b18;
} OvlTask;

extern u8 g_work_1b8d480[];
extern OvlMgr g_mgr_6420;
extern void *g_ptr_6460;
extern void *g_ptr_6464;
extern void *g_ptr_6008;
extern OvlSlot40 *g_ptr_600c;
extern u8 g_res_c2b0[];
extern u8 g_data_0040[];
extern u8 g_ovl_5fe8[];
extern u8 g_data_03b8[];
extern int g_tbl_2e8[];

extern int func_002B49A0(void *, int, int);
extern void func_01B04190(void *, void *, void *, int);
extern void func_01B03330(int, void *, void *);
extern void func_01B033E8(void *);
extern OvlTask *func_01B03F08(void *);
extern void func_01B040D0(OvlTask *);
extern int func_01B01568(void);
extern void fn_1268(void);
extern void fn_0978(void);

int ovl_09063_0830(void)
{
    u8 *p;
    OvlMgr *mgr;
    OvlSlot40 *s;
    int i;
    int idx;
    OvlTask *t;

    p = g_work_1b8d480;
    g_ptr_6460 = p;
    g_ptr_600c = (OvlSlot40 *)(p + 0x147680);
    g_ptr_6464 = p + 0x40000;
    g_ptr_6008 = p + 0x140000;
    mgr = &g_mgr_6420;
    mgr->w2C = func_002B49A0(g_res_c2b0, 8, 0);
    func_01B04190(mgr, g_data_0040, g_ptr_6460, 0x40000);
    s = g_ptr_600c;
    for (i = 0; i < 24; i++, s++) {
        s->w2C = 0;
    }
    func_01B03330(-1, g_ovl_5fe8, g_data_03b8);
    func_01B033E8(g_ovl_5fe8);
    func_01B040D0(func_01B03F08(fn_1268));
    idx = func_01B01568();
    t = func_01B03F08(fn_0978);
    t->w14 = g_tbl_2e8[idx];
    t->b18 = 2;
    func_01B040D0(t);
    return 0;
}
