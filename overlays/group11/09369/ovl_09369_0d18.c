typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;

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
    unsigned char padDC[0x04];
    float fE0;
    float fE4;
    float fE8;
    unsigned char padEC[0x44];
} OvlObj;

typedef struct {
    unsigned char pad0[0x80];
    unsigned char r0;
    unsigned char g0;
    unsigned char b0;
    unsigned char a0;
    unsigned char r1;
    unsigned char g1;
    unsigned char b1;
    unsigned char a1;
    int delay;
    unsigned char pad8C[0x0C];
    unsigned char b98;
    unsigned char b99;
} OvlColor;

typedef struct {
    unsigned char pad0[0x54];
    int w54;
} OvlCam;

extern int g_ovl_delays[];
extern float g_ovl_fx[];
extern float g_ovl_fy[];
extern float g_ovl_fz[];
extern float g_ovl_fr[];
extern unsigned char g_ovl_dat_0720[];
extern unsigned char g_ovl_dat_0738[];
extern unsigned char g_ovl_dat_5628[];
extern OvlObj g_ovl_objs[];
extern OvlColor g_ovl_color;
extern OvlCam g_ovl_cam;
extern int g_ovl_t0;
extern unsigned char g_ovl_mgr[];
extern OvlObj g_ovl_obj0;
extern OvlObj g_ovl_obj2;
extern unsigned char g_ovl_res[];

extern void fn_ovl_0fb0(void);
extern float fn_ovl_12f0(int);
extern void fn_ovl_1418(int, OvlVec3 *, int);
extern void fn_ovl_2e00(int, void *, void *);
extern void fn_ovl_3d38(void *, OvlObj *, int, float, int, int, void *);
extern void fn_ovl_50c0(OvlColor *, int);
extern void fn_ovl_54b0(OvlCam *, void *, void *, int);

void ovl_09369_0d18(OvlTask *t) {
    unsigned char *mgr;
    OvlObj *obj;
    OvlColor *c;
    OvlCam *cam;
    float rot;
    int i;

    t->timer--;
    if (t->timer > 0) {
        return;
    }

    mgr = g_ovl_mgr;
    rot = fn_ovl_12f0(-1);

    obj = &g_ovl_obj0;
    fn_ovl_3d38(mgr, obj, 0, 0.18f, 0, 0, 0);
    fn_ovl_1418(-1, &obj->pos, 1);
    obj->fC4 = rot;
    obj->fE8 = 5.0f;

    obj = g_ovl_objs;
    for (i = 0; i < 6; i++, obj++) {
        fn_ovl_3d38(mgr, obj, 1, 0.2f, g_ovl_delays[i], 0, 0);
        fn_ovl_1418(-1, &obj->pos, 1);
        obj->fE0 = g_ovl_fx[i];
        obj->fE4 = g_ovl_fy[i];
        obj->fE8 = g_ovl_fz[i] + 5.0f;
        obj->fC4 = g_ovl_fr[i];
    }

    obj = &g_ovl_obj2;
    fn_ovl_3d38(mgr, obj, 2, 0.32f, 180, 0, 0);
    fn_ovl_1418(-1, &obj->pos, 1);
    obj->fC4 = rot;
    obj->fE8 = 5.0f;

    c = &g_ovl_color;
    c->b0 = 255;
    c->g0 = 255;
    c->r0 = 255;
    c->a0 = 128;
    c->a1 = 0;
    c->b1 = 0;
    c->g1 = 0;
    c->r1 = 0;
    c->delay = 180;
    c->b98 = 72;
    c->b99 = 0;
    fn_ovl_50c0(c, 96);

    g_ovl_t0 = 180;
    cam = &g_ovl_cam;
    fn_ovl_54b0(cam, g_ovl_res, g_ovl_dat_0720, 1);
    cam->w54 = -1;
    fn_ovl_2e00(-1, g_ovl_dat_5628, g_ovl_dat_0738);
    t->node->cb = (int)fn_ovl_0fb0;
}
