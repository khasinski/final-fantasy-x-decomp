#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Mgr84D8;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x50];
} Entry130;

typedef struct {
    u8 pad00[0x90];
    void *p90;
    u8 pad94[0x14];
    s32 wA8;
    u8 padAC[0x4];
    u16 hB0;
} Obj6D10;

typedef struct {
    u8 pad00[0x20];
    float v20[12];
    float v50[4];
    float v60[4];
    float v70[4];
    float v80[4];
    float v90[4];
    float vA0[4];
    float vB0[4];
    float fC0;
    float fC4;
    float fC8;
    s32 wCC;
    s32 wD0;
    s32 wD4;
    s32 wD8;
    u8 padDC[0x4];
} EntryE0;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj8470;

typedef struct {
    float f00;
    s32 w04;
    s32 w08;
    s32 w0C;
} Obj8450;

typedef struct {
    u8 pad00[0x14];
    void *p14;
    u8 b18;
} Task;

extern u8 D_01B90BC0[];
extern void *D_01B088B0;
extern u8 *D_01B088B4;
extern u8 *D_01B084D0;
extern Mgr84D8 D_01B084D8;
extern u8 D_01B0DC20[];
extern u8 D_01B00040[];
extern Entry130 D_01B08520;
extern Obj6D10 D_01B06D10;
extern s32 D_01B00510[];
extern Entry130 D_01B07AD0[];
extern EntryE0 D_01B073D0[];
extern Obj8470 D_01B08470;
extern Obj8450 D_01B08450;
extern u8 D_01B00450[];
extern u8 D_01B00490[];
extern u8 D_01B004A0[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B04208(void *, void *, void *, s32);
extern void func_01B02008(void *);
extern void func_01B042E0(void *, void *, s32, s32, s32, void *, float);
extern float func_01B01898(s32);
extern void func_01B06768(void *, s32, void *, s32, float, float, float);
extern void func_01B033A8(s32, void *, void *);
extern void func_01B019C0(s32, void *, s32);
extern void func_01B02C30(s32, void *);
extern void func_01B031B0(s32, void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B05118(void *, void *, void *);
extern Task *func_01B03F80(void *);
extern void func_01B04148(Task *);
extern void func_01B06B98(void *, void *, void *, s32);
extern void func_01B05D18(void *, s32);
extern void func_01B06170(void *, s32);
extern void func_01B06A90(void *, s32);
extern void func_01B00E20(void);
extern void func_01B00E50(void);
extern void func_01B00F88(void);
extern void func_01B01130(void);
extern void func_01B04890(void);

s32 ovl_09295_0940(void)
{
    float v00[4];
    u8 *p = D_01B90BC0;
    s32 i;
    Entry130 *e;
    EntryE0 *s3;
    Task *t;
    Mgr84D8 *mgr;

    D_01B088B0 = p;
    D_01B088B4 = p + 0x40000;
    D_01B084D0 = p + 0x140000;
    mgr = &D_01B084D8;
    mgr->w2C = func_002B49A0(D_01B0DC20, 8, 0);
    func_01B04208(mgr, D_01B00040, D_01B088B0, 0x40000);

    func_01B02008(v00);
    {
        Entry130 *e0 = &D_01B08520;
        register float *dst __asm__("$3");
        func_01B042E0(mgr, e0, 1, 0x1D, 0, 0, 0.5f);
        dst = e0->pos;
        MMI_COPY_LQ_A3(dst, v00);
        MMI_COPY_SQ_A3(dst);
        e0->pos[1] -= 4.0f;
        e0->fC4 = func_01B01898(-1);
    }

    {
        Obj6D10 *o = &D_01B06D10;
        func_01B06768(o, -1, v00, 0x1E, 0.02f, 0.03f, 0.99f);
        func_01B033A8(-1, o, D_01B004A0);
        o->wA8 = 0xE;
        o->p90 = (void *)func_01B01130;
        o->hB0 |= 1;
    }

    e = D_01B07AD0;
    s3 = D_01B073D0;
    for (i = 0; i < D_01B00510[1]; i++, s3++) {
        func_01B042E0(mgr, e, 0, 0x25, 0, (void *)func_01B04890, 0.3f);
        func_01B019C0(i, e->pos, 1);
        e->fC4 = func_01B01898(i);
        func_01B02C30(i, s3->v20);
        e++;
        s3->v60[0] = 0.0f;
        s3->v60[1] = func_01B01898(i);
        s3->v60[2] = 0.0f;
        s3->v60[3] = 0.0f;
        func_01B031B0(i, s3->v20, s3->v60);
        func_01B019C0(i, s3->v50, 0);
        copy_vec(s3->v70, s3->v50);
        s3->v80[0] = s3->v80[1] = s3->v80[2] = 0.0f;
        v00[0] = func_002B3DB0(20.0f);
        v00[1] = 0.0f;
        v00[2] = func_002B3DF8(30.0f) + 60.0f;
        copy_vec(s3->v90, s3->v80);
        func_01B05118(s3->v60, s3->v90, v00);
        s3->v90[1] -= func_002B3DB0(20.0f) + 90.0f;
        v00[2] += v00[2] * 0.6f;
        copy_vec(s3->vA0, s3->v80);
        func_01B05118(s3->v60, s3->vA0, v00);
        copy_vec(s3->vB0, s3->v80);
        func_01B05118(s3->v60, s3->vB0, v00);
        s3->vB0[1] += 400.0f;
        s3->wD0 = 0x25;
        s3->wCC = 0x32;
        s3->fC0 = 0.0f;
        s3->fC4 = 0.02f;
        s3->fC8 = func_002B3DF8(1.0f) * -0.17453294f + -0.10471976f;
        s3->wD4 = i;
        s3->wD8 = 0;
        func_01B033A8(i, s3, D_01B00490);
        t = func_01B03F80((void *)func_01B00F88);
        t->p14 = s3;
        t->b18 = 1;
        func_01B04148(t);
    }

    {
        Obj8470 *o = &D_01B08470;
        func_01B06B98(o, D_01B0DC20, D_01B00450, 1);
        o->w54 = -1;
    }

    t = func_01B03F80((void *)func_01B00E20);
    t->b18 = 1;
    func_01B04148(t);

    func_01B05D18(p + 0x160000, 0x100);
    func_01B06170(p + 0x166000, 0x80);

    {
        register Obj8450 *o __asm__("$3") = &D_01B08450;
        o->f00 = 0.0f;
        o->w04 = 0x3C;
        o->w08 = 0;
        o->w0C = 0x25;
        func_01B06A90(o, 0x3C);
    }

    t = func_01B03F80((void *)func_01B00E50);
    t->b18 = 2;
    func_01B04148(t);

    return 0;
}
