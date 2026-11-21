typedef struct {
    int pad0[11];
    int w2C;
} OvlMgr;

typedef struct {
    int pad0[121];
    int count;
} OvlCtx;

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
    unsigned char padDC[0x34];
    void *p110;
    unsigned char pad114[0x0C];
    int w120;
    unsigned char pad124[0x0C];
} OvlObj;

typedef struct {
    float r0;
    float g0;
    float b0;
    float r1;
    float g1;
    float b1;
    int t0;
    int d0;
    int t1;
    int d1;
    int id;
    int d2;
    unsigned short flags;
} OvlColorFade;

typedef struct {
    unsigned char pad0[0x04];
    float f04;
    unsigned char pad08[0x0C];
    float f14;
    unsigned char pad18[0x28];
} OvlFade;

typedef struct {
    unsigned char pad0[0x18];
    unsigned char b18;
} OvlTask;

extern unsigned char g_ovl_buf[];
extern unsigned char *g_ovl_ptr_5c00;
extern unsigned char *g_ovl_ptr_5c04;
extern unsigned char g_ovl_dat_0040[];
extern unsigned char g_ovl_dat_0450[];
extern int g_ovl_cam_cfg[];
extern OvlCtx g_ovl_ctx;
extern unsigned char g_ovl_dat_3f20[];
extern unsigned char g_ovl_dat_4808[];
extern OvlFade g_ovl_fades[];
extern OvlColorFade *g_ovl_cfade_p;
extern OvlMgr g_ovl_mgr;
extern OvlObj g_ovl_objs[];
extern unsigned char g_ovl_dat_c870[];

extern int func_002B49A0(void *, int, int);
extern float func_002B3DF8(float);
extern int fn_ovl_0be0(void);
extern int fn_ovl_0df0(int);
extern float fn_ovl_0f18(int);
extern void fn_ovl_1040(int, OvlVec3 *, int);
extern int fn_ovl_1980(int);
extern int fn_ovl_2430(signed char *);
extern void fn_ovl_2a28(int, void *, int *);
extern void fn_ovl_2e70(int);
extern void fn_ovl_30e8(void *, void *, void *);
extern OvlTask *fn_ovl_3600(int (*)(void));
extern void fn_ovl_37c8(OvlTask *);
extern void fn_ovl_3888(OvlMgr *, void *, void *, int);
extern void fn_ovl_3960(OvlMgr *, OvlObj *, int, int, int, void *, float);
extern void fn_ovl_4490(OvlFade *, float, float, int, int);
extern void fn_ovl_46c8(OvlColorFade *);

int ovl_09536_08b0(void) {
    signed char targets[16];
    int i;
    int delay;
    int end_delay;
    unsigned char *p;
    OvlMgr *mgr;
    OvlObj *obj;
    OvlColorFade *cf;
    OvlFade *f;
    OvlTask *t;
    float base_f;

    p = g_ovl_buf;
    mgr = &g_ovl_mgr;
    g_ovl_ptr_5c04 = p + 0x40000;
    g_ovl_ptr_5c00 = p;
    mgr->w2C = func_002B49A0(g_ovl_dat_c870, 8, 0);
    fn_ovl_3888(mgr, g_ovl_dat_0040, g_ovl_ptr_5c00, 0x40000);
    fn_ovl_2430(targets);

    obj = g_ovl_objs;
    cf = (OvlColorFade *)(p + 0x140400);
    delay = 0;
    base_f = fn_ovl_0f18(-1);

    for (i = 0; i < g_ovl_ctx.count; i++) {
        int id = targets[i];
        float scale = (func_002B3DF8(0.2f) + 1.0f) * 0.12f;
        void *slot;

        if (fn_ovl_1980(id) == 0) {
            fn_ovl_3960(mgr, obj, 0, delay, 30, g_ovl_dat_3f20, scale);
            fn_ovl_1040(id, &obj->pos, 7);
            obj->pos.y -= 0.5f;
        } else {
            fn_ovl_3960(mgr, obj, 1, delay, 30, g_ovl_dat_3f20, scale);
            fn_ovl_1040(id, &obj->pos, 5);
        }

        obj->fC4 = base_f;
        obj->w120 = fn_ovl_0df0(id);
        slot = p + ((i << 6) + 0x140000);
        fn_ovl_30e8(slot, g_ovl_dat_c870, g_ovl_dat_0450);
        obj->p110 = slot;

        cf->r0 = 0.5f;
        cf->g0 = 1.3f;
        cf->b0 = 0.5f;
        cf->t0 = 32;
        cf->d0 = delay + 12;
        cf->t1 = 16;
        cf->d1 = 58;
        cf->id = id;
        fn_ovl_46c8(cf);
        g_ovl_cfade_p = cf;

        obj++;
        delay += 60;
        cf++;
    }

    end_delay = delay - 60;
    g_ovl_cam_cfg[1] = end_delay;
    fn_ovl_2a28(-1, g_ovl_dat_4808, (end_delay > 0) ? &g_ovl_cam_cfg[0] : &g_ovl_cam_cfg[2]);

    f = g_ovl_fades;
    fn_ovl_4490(&f[0], 1.0f, 0.5f, 8, 0);
    f[0].f14 = 0.7f;
    fn_ovl_4490(&f[1], 0.5f, 1.0f, 16, delay + 20);
    f[1].f04 = 0.7f;

    fn_ovl_2e70(1);
    t = fn_ovl_3600(fn_ovl_0be0);
    t->b18 = 2;
    fn_ovl_37c8(t);
    return 0;
}
