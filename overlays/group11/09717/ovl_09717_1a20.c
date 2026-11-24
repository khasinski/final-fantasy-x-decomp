#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 s30[0x0C];
    float f3C;
    u8 pad40[0x0C];
    int w4C;
    int w50;
} OvlPtcl;

typedef struct {
    u8 pad00[0x60];
    float f60;
    float f64;
    float f68;
    float f6C;
    u16 h70;
    u16 h72;
    u16 h74;
    u16 h76;
    u8 pad78[0x08];
    float m80[16];
    u8 padC0[0x04];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x04];
    float fE4;
    u8 padE8[0x1C];
    void *p104;
    u8 pad108[0x18];
    int w120;
    u16 h124;
    u8 b126;
    u8 pad127[0x09];
} OvlObj;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
    u8 pad9A[0x06];
} OvlFlash;

typedef struct {
    float w00;
    int w04;
    int w08;
    int w0C;
    u8 pad10[0x0C];
} OvlBlur;

typedef struct {
    u8 pad00[0x04];
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x08];
    int w24;
    u8 pad28[0x04];
    u16 h2C;
    u8 pad2E[0x02];
} OvlLight;

typedef struct {
    u8 pad00[0xF0];
    u8 bF0;
    u8 bF1;
    u8 bF2;
    u8 bF3;
    u8 padF4[0x04];
    int wF8;
    float fFC;
    float f100;
    u8 pad104[0x0C];
    int w110;
    int w114;
    int w118;
    u8 pad11C[0x08];
    u16 h124;
} OvlFadeObj;

typedef struct {
    OvlObj objs[0x2E];
    OvlObj objs2[0x1C];
    OvlFlash flashes[3];
    OvlBlur blur0;
    OvlBlur blur1;
    OvlLight lights[10];
    u8 pad5BD8[0x1A8];
    OvlFadeObj fade;
    u8 pad5EA8[0x18];
    float f5EC0;
    int w5EC4;
} OvlWork;

typedef struct {
    float pos[4];
    float f10;
    float f14;
    int w18;
    int w1C;
} OvlTbl660;

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    int w18;
    int w1C;
} OvlTblD00;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
    int w30;
    int w34;
    int w38;
} OvlEvt;

extern int g_ovl_9880;
extern OvlMgr g_ovl_9888;
extern void *g_ovl_98c8;
extern void *g_ovl_98cc;
extern u8 g_ovl_98d0[];
extern u8 g_ovl_9930[];
extern OvlWork *g_ovl_998c;
extern void *g_ovl_9990;
extern u8 g_ovl_f140[];
extern u8 g_work_1beb540[];
extern int g_ovl_1540[2];
extern void *g_ovl_1754;
extern u8 g_data_0040[];
extern u8 g_data_0f40[];
extern u8 g_data_0f90[];
extern OvlTbl660 g_tbl_0660[];
extern float g_tbl_0c20[][4];
extern OvlTblD00 g_tbl_0d00[];

extern void func_01B02618(int);
extern int func_002B49A0(void *, int, int);
extern void func_01B051B0(void *, void *, void *, int);
extern void func_01B08818(void *, void *);
extern OvlTask *func_01B04F28(void *);
extern void func_01B050F0(OvlTask *);
extern void func_01B08E48(void *, int);
extern void func_01B06610(void);
extern int func_01B08838(void *);
extern void func_01B04FA8(void *);
extern int func_01B05368(void *, void *);
extern void func_001CDDD8(int);
extern void func_01B05758(void *);
extern OvlPtcl *func_01B08EE0(void);
extern void func_01B06650(void *, int);
extern void func_01B02E08(int, int, int, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern int func_01B05288(void *, void *, int, int, int, int, float);
extern void func_01B056F8(void *, void *);
extern void func_01B04038(void *, void *);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern float func_01B074A0(void);
extern void func_01B08938(void *, int);
extern void func_01B08BB0(void *, int);
extern void func_01B093E0(void *, int);
extern void func_01B08AA8(void *, int);

void ovl_09717_1b60(void *a0);
void ovl_09717_1be8(void);
void ovl_09717_1c50(void);
void ovl_09717_1c60(void);

int ovl_09717_1a20(void)
{
    u8 *p;
    OvlMgr *mgr;
    OvlTask *t;

    p = g_work_1beb540;
    g_ovl_98c8 = p;
    g_ovl_98cc = p + 0x100000;
    g_ovl_9990 = p + 0x200000;
    g_ovl_998c = (OvlWork *)(p + 0x230000);
    g_ovl_1540[0] = 20;
    g_ovl_1540[1] = 0;
    func_01B02618(g_ovl_9880);
    mgr = &g_ovl_9888;
    mgr->w2C = func_002B49A0(g_ovl_f140, 8, 0);
    func_01B051B0(mgr, g_data_0040, g_ovl_98c8, 0x100000);
    ovl_09717_1c50();
    func_01B08818(g_ovl_98d0, g_data_0f40);
    func_01B08818(g_ovl_9930, g_data_0f90);
    t = func_01B04F28(ovl_09717_1b60);
    t->b18 = 1;
    func_01B050F0(t);
    func_01B08E48(p + 0x220000, 0x200);
    t = func_01B04F28(ovl_09717_1be8);
    t->b18 = 2;
    func_01B050F0(t);
    return 0;
}

void ovl_09717_1b60(void *a0)
{
    OvlWork *w;

    w = g_ovl_998c;
    func_01B06610();
    g_ovl_1754 = g_ovl_9990;
    func_01B08838(g_ovl_98d0);
    if (func_01B08838(g_ovl_9930)) {
        w->w5EC4 = 1;
        ovl_09717_1c60();
        func_01B04FA8(a0);
    }
}

void ovl_09717_1be8(void)
{
    OvlWork *w;

    w = g_ovl_998c;
    if (func_01B05368(&g_ovl_9888, g_ovl_98cc) == 1 && w->w5EC4 == 1) {
        func_001CDDD8(g_ovl_9880);
    }
}

void ovl_09717_1c50(void)
{
    g_ovl_998c->w5EC4 = 0;
}

void ovl_09717_1c60(void)
{
    func_01B05758(&g_ovl_9888);
}

void ovl_09717_1c70(void)
{
    OvlPtcl *p;

    p = func_01B08EE0();
    if (p != 0) {
        func_01B06650(p->s30, func_002B49A0(g_ovl_f140, 9, 0));
        func_01B02E08(-1, 10, 0, p);
        p->f00 += func_002B3DB0(2.0f);
        p->f08 += func_002B3DB0(2.0f);
        p->f10 = func_002B3DB0(0.1f);
        p->f14 = func_002B3DB0(0.2f);
        p->f18 = func_002B3DB0(0.1f);
        p->f1C = func_002B3DB0(3.1415927f);
        p->f20 = 0.0f;
        p->f24 = -0.005f;
        p->f28 = 0.0f;
        p->f2C = 1.0f;
        p->f3C = (func_002B3DB0(0.5f) + 1.0f) * 0.5f;
        p->w4C = -1;
        p->w50 = 0;
    }
}

OvlObj *ovl_09717_1db8(int idx)
{
    OvlTbl660 *t;
    OvlObj *obj;

    t = &g_tbl_0660[idx];
    obj = &g_ovl_998c->objs[idx];
    func_01B05288(&g_ovl_9888, obj, t->w18, 0, 0, 0, t->f10);
    MMI_COPY_LQ_A3(obj->pos, t->pos);
    MMI_COPY_SQ_A3(obj->pos);
    obj->fC4 = t->f14;
    return obj;
}

void ovl_09717_1e40(OvlEvt *e)
{
    ovl_09717_1db8(e->w2C);
}

void ovl_09717_1e48(OvlEvt *e)
{
    func_01B056F8(&g_ovl_9888, &g_ovl_998c->objs[e->w30]);
}

void ovl_09717_1e70(OvlObj *obj)
{
    float m0[16];
    float m1[16];
    float v[4];
    float f;

    func_01B04038(m0, m1);
    func_002DCF48(obj->m80, m1);
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 5.0f;
    v[3] = 1.0f;
    func_002DCE08(obj->pos, obj->m80, v);
    obj->pos[3] = 1.0f;
    f = func_01B074A0() * 0.01f;
    obj->f6C = f;
    obj->f68 = f;
    obj->f64 = f;
    obj->f60 = f;
}

void ovl_09717_1f20(void)
{
    OvlWork *w;
    OvlFlash *fl;

    w = g_ovl_998c;
    w->objs[0].p104 = ovl_09717_1e70;
    w->objs[0].b126 = 2;

    fl = &w->flashes[0];
    fl->b80 = fl->b81 = fl->b82 = 0xFF;
    fl->b83 = 0;
    fl->b84 = 0xFF;
    fl->b85 = 0xFF;
    fl->b86 = 0xFF;
    fl->b87 = 0x80;
    fl->w88 = 4;
    fl->b98 = 0x48;
    fl->b99 = 0;
    func_01B08938(fl, 6);

    fl = &w->flashes[1];
    fl->b80 = fl->b81 = fl->b82 = 0xFF;
    fl->b83 = 0x80;
    fl->b84 = 0xFF;
    fl->b85 = 0xFF;
    fl->b86 = 0xFF;
    fl->b87 = 0;
    fl->w88 = 10;
    fl->b98 = 0x48;
    fl->b99 = 0;
    func_01B08938(fl, 15);
}

void ovl_09717_1ff8(void)
{
    OvlFlash *fl;

    fl = &g_ovl_998c->flashes[2];
    fl->b80 = fl->b81 = fl->b82 = 0x80;
    fl->b83 = 0x80;
    fl->b84 = 0x80;
    fl->b85 = 0x80;
    fl->b86 = 0x80;
    fl->b87 = 0;
    fl->w88 = 0;
    fl->b98 = 0x48;
    fl->b99 = 0;
    func_01B08938(fl, 45);
}

void ovl_09717_2048(OvlObj *obj, int n)
{
    int t;
    int v;

    t = --obj->w120;
    if (t < n) {
        if (t > 0) {
            v = (t << 12) / n;
            obj->h76 = v;
            obj->h74 = v;
            obj->h72 = v;
            obj->h70 = v;
        } else {
            obj->h124 |= 0x4000;
        }
    }
}

void ovl_09717_20a0(OvlObj *obj)
{
    ovl_09717_2048(obj, 64);
}

void ovl_09717_20a8(int idx)
{
    OvlObj *obj;

    obj = ovl_09717_1db8(idx);
    obj->p104 = ovl_09717_20a0;
    obj->w120 = 0x90;
}

void ovl_09717_20d8(int idx)
{
    OvlObj *obj;
    float f;

    obj = ovl_09717_1db8(idx);
    f = (func_002B3DF8(0.5f) + 1.0f) * 0.6f;
    obj->f6C = f;
    obj->f68 = f;
    obj->f64 = f;
    obj->f60 = f;
    obj->p104 = ovl_09717_20a0;
    obj->w120 = 0x90;
}

void ovl_09717_2150(void)
{
    ovl_09717_20a8(3);
    ovl_09717_20a8(4);
    ovl_09717_20a8(5);
    ovl_09717_20a8(6);
    ovl_09717_20d8(7);
    ovl_09717_20d8(8);
    ovl_09717_20d8(9);
}

void ovl_09717_2198(void)
{
    ovl_09717_20a8(11);
    ovl_09717_20a8(12);
}

void ovl_09717_21b8(OvlObj *obj)
{
    obj->fE4 = g_ovl_998c->f5EC0;
}

void ovl_09717_21d0(int idx)
{
    OvlObj *obj;

    obj = ovl_09717_1db8(idx);
    obj->p104 = ovl_09717_21b8;
}

void ovl_09717_21f8(int idx)
{
    OvlObj *obj;

    obj = ovl_09717_1db8(idx);
    obj->p104 = ovl_09717_20a0;
    obj->w120 = 0xC2;
}

void ovl_09717_2228(void)
{
    ovl_09717_21f8(15);
    ovl_09717_21f8(16);
    ovl_09717_21d0(19);
    ovl_09717_21d0(20);
    ovl_09717_21d0(21);
    ovl_09717_21d0(22);
    ovl_09717_21d0(23);
    ovl_09717_21d0(24);
    ovl_09717_21d0(25);
    ovl_09717_21d0(26);
    ovl_09717_21d0(27);
    ovl_09717_21d0(28);
}

void ovl_09717_2298(OvlObj *obj)
{
    obj->fE4 = g_ovl_998c->f5EC0;
    ovl_09717_2048(obj, 16);
}

void ovl_09717_22b8(OvlEvt *e)
{
    OvlObj *obj;
    float *pos;
    int idx;
    int k;
    float f;

    idx = e->w34;
    k = idx * 2;
    obj = &g_ovl_998c->objs2[k];
    pos = g_tbl_0c20[idx];
    f = (func_002B3DB0(0.1f) + 1.0f) * 0.3f;
    func_01B05288(&g_ovl_9888, obj, 5, 0, 0, 0, f);
    MMI_COPY_LQ_A3(obj->pos, pos);
    MMI_COPY_SQ_A3(obj->pos);
    obj++;
    f = (func_002B3DB0(0.1f) + 1.0f) * 0.3f;
    func_01B05288(&g_ovl_9888, obj, 7, 30, 0, 0, f);
    MMI_COPY_LQ_A3(obj->pos, pos);
    MMI_COPY_SQ_A3(obj->pos);
    obj->p104 = ovl_09717_2298;
    obj->w120 = 36;
}

void ovl_09717_23e0(OvlEvt *e)
{
    OvlLight *lt;
    OvlTblD00 *t;
    int idx;

    idx = e->w38;
    lt = &g_ovl_998c->lights[idx];
    t = &g_tbl_0d00[idx];
    func_01B08BB0(lt, t->w18);
    lt->f04 = t->f00;
    lt->w24 = t->w1C;
    lt->f08 = t->f04;
    lt->h2C |= 3;
    lt->f0C = t->f08;
    lt->f10 = t->f0C;
    lt->f14 = t->f10;
    lt->f18 = t->f14;
}

void ovl_09717_2480(void)
{
    OvlFadeObj *f;

    f = &g_ovl_998c->fade;
    f->bF0 = 0x80;
    f->bF1 = 0x80;
    f->bF2 = 0x80;
    f->bF3 = 0x30;
    f->w114 = 0x100;
    f->w118 = 0xD0;
    f->h124 = 0;
    f->w110 = 0;
    f->wF8 = 0;
    f->f100 = f->fFC = 0.06f;
    func_01B093E0(f, 0x82);
}

void ovl_09717_24e0(void)
{
    OvlBlur *b = &g_ovl_998c->blur0;
    b->w00 = 0.0f;
    b->w04 = 80;
    b->w08 = 0;
    b->w0C = 0;
    func_01B08AA8(b, 60);
}

void ovl_09717_2510(void)
{
    OvlBlur *b = &g_ovl_998c->blur1;
    b->w00 = 0.0f;
    b->w04 = 0;
    b->w08 = 60;
    b->w0C = 0;
    func_01B08AA8(b, 45);
}

void ovl_09717_2540(void)
{
    g_ovl_998c->f5EC0 = 0.0f;
}

void ovl_09717_2550(void)
{
    g_ovl_998c->f5EC0 += 0.2f;
}

void ovl_09717_2578(void)
{
    g_ovl_998c->f5EC0 = 60.0f;
}

void ovl_09717_2590(void)
{
    g_ovl_998c->f5EC0 = 78.0f;
}
