typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x76];
    u16 h76;
    u8 pad78[0x48];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x04];
    float pos[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} OvlSubObj;

typedef struct {
    u8 pad00[0x76];
    u16 h76;
    u8 pad78[0x48];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x04];
    float pos[4];
    u8 padE0[0x280];
    float v360[4];
    u8 pad370[0x28];
    int idx;
    u8 pad39C[0x04];
    OvlSubObj sub;
    u8 pad4D0[0x10];
    float f4E0;
    u8 pad4E4[0x0C];
} OvlObj;

typedef struct {
    float rot[4];
    float vel[4];
    OvlObj *obj;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    int w3C;
    int w40;
    u8 pad44[0x0C];
} OvlSlot50;

extern OvlObj *g_ptr_6128;
extern OvlSlot50 *g_ptr_612c;
extern u8 g_mgr_6540[];
extern u8 g_ovl_6500[];
extern u8 g_res_c3f0[];
extern u8 g_data_03a0[];
extern void fn_4940(void);

extern void func_01B043A0(void *, void *, int, int, int, void *, float);
extern void func_002DD0B0(void *, void *);
extern void func_01B03B28(void *, void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);
extern float func_01B01ED0(int);
extern void func_01B04810(void *, void *);

void ovl_09062_0fe0(OvlObj *obj)
{
    float mat[16];
    float vec[4];
    OvlObj *base;
    OvlSubObj *sub;
    OvlSlot50 *s;
    float ang;

    base = &g_ptr_6128[obj->idx];
    sub = &base->sub;
    {
        void *cb;
        if (obj->idx == 0) {
            cb = (void *)fn_4940;
        } else {
            cb = 0;
        }
        func_01B043A0(g_mgr_6540, sub, 7, 0, 0, cb, base->f4E0);
    }
    func_002DD0B0(sub->pos, obj->v360);
    ang = obj->fC4 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    sub->fC4 = ang;
    if (obj->idx == 0) {
        func_01B03B28(g_ovl_6500, g_res_c3f0, g_data_03a0);
        sub->p110 = g_ovl_6500;
    }

    s = &g_ptr_612c[obj->idx];
    s->rot[0] = func_002B3DB0(0.8f);
    s->rot[1] = func_002B3DB0(0.8f);
    s->rot[2] = func_002B3DB0(0.8f);
    s->rot[3] = 0.0f;

    func_002DD128(mat);
    func_002DD318(mat, mat, func_002B3DB0(3.1415927f));
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = func_002B3DF8(1.5f) + 0.5f;
    vec[3] = 1.0f;
    func_002DCE08(vec, mat, vec);

    s->vel[0] = vec[0];
    s->vel[1] = -func_002B3DF8(1.8f);
    s->vel[2] = vec[2];
    s->vel[3] = 0.0f;

    s->obj = obj;
    s->f24 = 0.0f;
    s->f28 = 0.15f;
    s->f2C = func_01B01ED0(0) - 1.0f;
    s->f30 = 0.95f;
    s->f34 = 0.6f;
    s->f38 = func_002B3DF8(1.0f);
    s->w3C = 20;
    s->w40 = 0;
}
