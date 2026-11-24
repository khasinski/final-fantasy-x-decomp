typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x3C];
    int w3C;
    u8 pad40[0x10];
} OvlSlot50;

typedef struct {
    u8 pad00[0x14];
    int w14;
    u8 b18;
} OvlTask;

extern u8 g_work_1b7d5c0[];
extern OvlMgr g_mgr_6540;
extern void *g_ptr_6580;
extern void *g_ptr_6584;
extern void *g_ptr_6128;
extern OvlSlot50 *g_ptr_612c;
extern u8 g_res_c3f0[];
extern u8 g_data_0040[];
extern u8 g_ovl_6108[];
extern u8 g_data_03b8[];
extern int g_tbl_2e8[];

extern int func_002B49A0(void *, int, int);
extern void func_01B042C8(void *, void *, void *, int);
extern void func_01B03468(int, void *, void *);
extern void func_01B03520(void *);
extern OvlTask *func_01B04040(void *);
extern void func_01B04208(OvlTask *);
extern int func_01B016A0(void);
extern void fn_1250(void);
extern void fn_0978(void);

int ovl_09062_0830(void)
{
    u8 *p;
    OvlMgr *mgr;
    OvlSlot50 *s;
    int i;
    int idx;
    OvlTask *t;

    p = g_work_1b7d5c0;
    g_ptr_6580 = p;
    g_ptr_612c = (OvlSlot50 *)(p + 0x147680);
    g_ptr_6584 = p + 0x40000;
    g_ptr_6128 = p + 0x140000;
    mgr = &g_mgr_6540;
    mgr->w2C = func_002B49A0(g_res_c3f0, 8, 0);
    func_01B042C8(mgr, g_data_0040, g_ptr_6580, 0x40000);
    s = g_ptr_612c;
    for (i = 0; i < 24; i++, s++) {
        s->w3C = 0;
    }
    func_01B03468(-1, g_ovl_6108, g_data_03b8);
    func_01B03520(g_ovl_6108);
    func_01B04208(func_01B04040(fn_1250));
    idx = func_01B016A0();
    t = func_01B04040(fn_0978);
    t->w14 = g_tbl_2e8[idx];
    t->b18 = 2;
    func_01B04208(t);
    return 0;
}
