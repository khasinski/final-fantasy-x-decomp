typedef struct {
    int pad0[11];
    int w2C;
} OvlMgr;

typedef struct {
    float x;
    float y;
    float z;
    float w;
} OvlVec4;

typedef struct {
    unsigned char pad0[0xC0];
    OvlVec4 rot;
    OvlVec4 pos;
    float fE0;
    float fE4;
    float fE8;
    unsigned char padEC[0x24];
    void *p110;
    unsigned char pad114[0x1C];
} OvlObj;

typedef struct {
    unsigned char pad0[0x54];
    int w54;
} OvlCam;

extern unsigned char g_ovl_buf[];
extern unsigned char g_ovl_dat_0040[];
extern unsigned char g_ovl_dat_0568[];
extern unsigned char g_ovl_dat_0590[];
extern unsigned char g_ovl_dat_05a8[];
extern unsigned char g_ovl_dat_40f0[];
extern unsigned char g_ovl_dat_5048[];
extern OvlObj g_ovl_obj_5070;
extern OvlCam g_ovl_cam;
extern int g_ovl_t0;
extern int g_ovl_t1;
extern OvlMgr g_ovl_mgr;
extern OvlObj g_ovl_objs[];
extern unsigned char *g_ovl_ptr_5970;
extern unsigned char *g_ovl_ptr_5974;
extern unsigned char g_ovl_res[];

extern int func_002B49A0(void *, int, int);
extern void func_002DD968(OvlVec4 *, OvlVec4 *, OvlVec4 *, float);
extern void fn_ovl_0d98(void);
extern void fn_ovl_1230(int, OvlVec4 *, int);
extern void fn_ovl_2c18(int, void *, void *);
extern void fn_ovl_32d8(void *, void *, void *);
extern void *fn_ovl_37f0(void (*)(void));
extern void fn_ovl_39b8(void *);
extern void fn_ovl_3a78(OvlMgr *, void *, void *, int);
extern void fn_ovl_3b50(OvlMgr *, OvlObj *, int, float, int, int, void *);
extern void fn_ovl_4880(OvlVec4 *, OvlVec4 *, OvlVec4 *);
extern void fn_ovl_4ed8(OvlCam *, void *, void *, int);

int ovl_09193_09e8(void) {
    OvlVec4 ang;
    OvlVec4 pos2;
    unsigned char *p;
    OvlMgr *mgr;
    OvlObj *obj;
    OvlCam *cam;
    void *slot;
    float a;

    p = g_ovl_buf;
    g_ovl_ptr_5970 = p;
    g_ovl_ptr_5974 = p + 0x80000;
    mgr = &g_ovl_mgr;
    mgr->w2C = func_002B49A0(g_ovl_res, 8, 0);
    fn_ovl_3a78(mgr, g_ovl_dat_0040, g_ovl_ptr_5970, 0x80000);

    obj = &g_ovl_objs[3];
    fn_ovl_3b50(mgr, obj, 3, 0.06f, 38, 0, 0);
    fn_ovl_1230(-1, &obj->pos, 1);
    fn_ovl_1230(0, &pos2, 1);
    fn_ovl_4880(&ang, &obj->pos, &pos2);
    obj->rot.x = ang.x;
    obj->rot.y = ang.y;
    obj->fE8 = -8.0f;

    cam = &g_ovl_cam;
    fn_ovl_4ed8(cam, g_ovl_res, g_ovl_dat_0568, 1);
    cam->w54 = -1;

    obj--;
    fn_ovl_3b50(mgr, obj, 2, 0.06f, 48, 2, g_ovl_dat_40f0);
    fn_ovl_1230(0, &obj->pos, 1);
    {
        float a1 = ang.x + 3.1415927f;
        if (a1 > 3.1415927f) {
            a1 -= 6.2831855f;
        } else if (a1 < -3.1415927f) {
            a1 += 6.2831855f;
        }
        obj->rot.x = a1;
    }
    obj->rot.y = ang.y;
    obj->fE8 = -10.0f;
    slot = p + 0x180040;
    fn_ovl_32d8(slot, g_ovl_res, g_ovl_dat_0590);
    obj->p110 = slot;

    obj = &g_ovl_objs[0];
    fn_ovl_3b50(mgr, obj, 0, 0.04f, 48, 0, 0);
    fn_ovl_1230(0, &obj->pos, 3);
    obj->rot.x = 1.5707964f;
    a = ang.y + 3.1415927f;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    obj->rot.y = a;
    obj->pos.y -= 12.0f;
    obj->fE4 = -15.0f;

    obj = &g_ovl_obj_5070;
    fn_ovl_3b50(mgr, obj, 1, 0.04f, 43, 0, 0);
    obj->rot.x = ang.x;
    obj->rot.y = ang.y;
    func_002DD968(&obj->pos, &g_ovl_objs[3].pos, &g_ovl_objs[2].pos, 0.5f);

    g_ovl_t0 = 25;
    g_ovl_t1 = 48;
    fn_ovl_2c18(-1, g_ovl_dat_5048, g_ovl_dat_05a8);
    fn_ovl_39b8(fn_ovl_37f0(fn_ovl_0d98));
    return 0;
}
