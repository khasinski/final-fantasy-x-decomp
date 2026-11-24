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
    float v370[4];
    u8 pad380[0x18];
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
    int w2C;
    int w30;
    u8 pad34[0x0C];
} OvlSlot40;

extern OvlObj *g_ptr_6008;
extern OvlSlot40 *g_ptr_600c;
extern u8 g_mgr_6420[];
extern u8 g_ovl_63e0[];
extern u8 g_res_c2b0[];
extern u8 g_data_03a0[];
extern const double g_dbl_5fc0;
extern const double g_dbl_5fc8;
extern const double g_dbl_5fd0;
extern void fn_4808(void);

extern void func_01B04268(void *, void *, int, int, int, void *, float);
extern void func_002DD0B0(void *, void *);
extern void func_01B039F0(void *, void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_01B046D8(void *, void *);

void ovl_09063_0fe8(OvlObj *obj)
{
    float mat[16];
    float vec[4];
    OvlObj *base;
    OvlSubObj *sub;
    OvlSlot40 *s;
    float ang;

    base = &g_ptr_6008[obj->idx];
    sub = &base->sub;
    {
        void *cb;
        if (obj->idx == 0) {
            cb = (void *)fn_4808;
        } else {
            cb = 0;
        }
        func_01B04268(g_mgr_6420, sub, 7, 0, 0, cb, base->f4E0);
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
        func_01B039F0(g_ovl_63e0, g_res_c2b0, g_data_03a0);
        sub->p110 = g_ovl_63e0;
    }

    s = &g_ptr_600c[obj->idx];
    s->rot[0] = func_002B3DB0(0.4f);
    s->rot[1] = func_002B3DB0(0.4f);
    s->rot[2] = func_002B3DB0(0.4f);
    s->rot[3] = 0.0f;

    func_002DD128(mat);
    func_002DD318(mat, mat, func_002B3DB0(3.1415927f));
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = func_002B3DF8(0.5f);
    vec[3] = 1.0f;
    func_002DCE08(vec, mat, vec);

    s->vel[0] = vec[0];
    s->vel[1] = -func_002B3DF8(0.5f);
    s->vel[2] = vec[2];
    s->vel[3] = 0.0f;

    s->vel[0] = obj->v370[0] * 0.1f + vec[0];
    s->vel[1] = -func_002B3DF8(0.5f);
    s->vel[2] = obj->v370[2] * 0.1f + vec[2];
    s->vel[3] = 0.0f;

    s->obj = obj;
    s->f24 = 0.2f;
    s->f28 = 0.92f;
    s->w2C = 20;
    s->w30 = 30;
}

void ovl_09063_1268(void)
{
    OvlSlot40 *s;
    OvlObj *obj;
    int i;
    float *p;
    float a;
    double d;

    s = g_ptr_600c;
    for (i = 0; i < 24; i++, s++) {
        u16 h;
        if (s->w2C == 0) {
            continue;
        }
        obj = s->obj;
        if (s->w30 == 0) {
            if (--s->w2C == 0) {
                func_01B046D8(g_mgr_6420, obj);
                continue;
            }
            h = (u16)((s->w2C << 12) / 20);
        } else {
            s->w30--;
            h = 0x1000;
        }
        obj->h76 = h;

        {
            float d0 = s->rot[0];
            p = &obj->fC0;
            a = *p + d0;
            if (a > 3.1415927f) {
                a -= 6.2831855f;
            } else if (a < -3.1415927f) {
                a += 6.2831855f;
            }
            *p = a;
        }

        {
            float d1 = s->rot[1];
            p = &obj->fC4;
            a = *p + d1;
            if (a > 3.1415927f) {
                a -= 6.2831855f;
            } else if (a < -3.1415927f) {
                a += 6.2831855f;
            }
            *p = a;
        }

        {
            float d2 = s->rot[2];
            p = &obj->fC8;
            a = *p + d2;
            if (a > 3.1415927f) {
                a -= 6.2831855f;
            } else if (a < -3.1415927f) {
                a += 6.2831855f;
            }
            *p = a;
        }

        {
            float vy = s->vel[1] + s->f24;
            obj->pos[0] += s->vel[0];
            obj->pos[1] += vy;
            obj->pos[2] += s->vel[2];
        }

        s->vel[0] *= s->f28;
        s->vel[1] *= s->f28;
        s->vel[2] *= s->f28;

        d = s->rot[0];
        if (d < 0.0) d = -d;
        if (d > (double)0.1f) {
            s->rot[0] *= 0.9f;
        }
        d = s->rot[1];
        if (d < 0.0) d = -d;
        if (d > (double)0.1f) {
            s->rot[1] *= 0.9f;
        }
        d = s->rot[2];
        if (d < 0.0) d = -d;
        if (d > (double)0.1f) {
            s->rot[2] *= 0.9f;
        }
    }
}
