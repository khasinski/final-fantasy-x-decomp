typedef struct {
    int pad0[11];
    int w2C;
} OvlMgr;

typedef struct {
    float x;
    float y;
    float z;
} OvlVec3;

typedef struct {
    unsigned char pad0[0xC4];
    float fC4;
    unsigned char padC8[0x08];
    OvlVec3 pos;
    unsigned char padDC[0x30];
    void *p10C;
    void *p110;
    unsigned char pad114[0x1C];
} OvlObj;

typedef struct {
    int pad0[2];
    void (*cb)(void *);
} OvlCbCfg;

extern unsigned char g_ovl_buf[];
extern unsigned char *g_ovl_ptr_49f0;
extern unsigned char *g_ovl_ptr_49f4;
extern unsigned char g_ovl_dat_0040[];
extern OvlCbCfg g_ovl_cb_cfg;
extern unsigned char g_ovl_dat_0578[];
extern unsigned char g_ovl_dat_3fe8[];
extern float g_ovl_floor_y;
extern OvlMgr g_ovl_mgr;
extern OvlObj g_ovl_objs[];
extern unsigned char g_ovl_dat_9fc0[];

extern int func_002B49A0(void *, int, int);
extern int fn_ovl_09c8(void);
extern void fn_ovl_0bf0(void *);
extern float fn_ovl_1000(int);
extern void fn_ovl_1128(int, OvlVec3 *, int);
extern float fn_ovl_1578(int);
extern void fn_ovl_31d0(void *, void *, void *);
extern void *fn_ovl_36e8(int (*)(void));
extern void fn_ovl_38b0(void *);
extern void fn_ovl_3970(OvlMgr *, void *, void *, int);
extern void fn_ovl_3a48(OvlMgr *, OvlObj *, int, int, int, void *, float);
extern void fn_ovl_4530(void *, int);

int ovl_09382_0a20(void) {
    unsigned char *p;
    OvlMgr *mgr;
    OvlObj *obj;
    void *slot;
    void *t;

    p = g_ovl_buf;
    g_ovl_ptr_49f0 = p;
    g_ovl_ptr_49f4 = p + 0x40000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_dat_9fc0, 8, 0);
    fn_ovl_3970(mgr, g_ovl_dat_0040, g_ovl_ptr_49f0, 0x40000);

    obj = &g_ovl_objs[1];
    fn_ovl_3a48(mgr, obj, 1, 0, 40, g_ovl_dat_3fe8, 0.07f);
    fn_ovl_1128(0, &obj->pos, 2);
    obj->fC4 = fn_ovl_1000(0);
    obj->pos.y += 6.0f;
    slot = p + 0x102800;
    fn_ovl_31d0(slot, g_ovl_dat_9fc0, g_ovl_dat_0578);
    obj->p110 = slot;

    obj--;
    fn_ovl_3a48(mgr, obj, 0, 20, 0, 0, 0.03f);
    fn_ovl_1128(0, &obj->pos, 2);
    obj->fC4 = fn_ovl_1000(0);
    obj->pos.y += 6.0f;
    g_ovl_cb_cfg.cb = fn_ovl_0bf0;
    obj->p10C = &g_ovl_cb_cfg;

    g_ovl_floor_y = fn_ovl_1578(0);
    fn_ovl_4530(p + 0x100000, 32);
    t = fn_ovl_36e8(fn_ovl_09c8);
    fn_ovl_38b0(t);
    return 0;
}
