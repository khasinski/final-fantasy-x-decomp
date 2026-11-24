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
} Mgr7BA8;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x50];
} Entry130;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    u8 pad18[0x78];
    void *p90;
    void *p94;
    u8 pad98[0x10];
    s32 wA8;
    u8 padAC[0x14];
} EntryC0;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj7B40;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task;

extern u8 D_01B6F3C0[];
extern void *D_01B07F80;
extern s32 *D_01B07F84;
extern u8 *D_01B07BA0;
extern Mgr7BA8 D_01B07BA8;
extern u8 D_01B0D2E0[];
extern u8 D_01B00040[];
extern Entry130 D_01B07BF0;
extern Entry130 D_01B071C0[];
extern EntryC0 D_01B06A40[];
extern s32 D_01B004D8[];
extern Obj7B40 D_01B07B40;
extern u8 D_01B00450[];
extern u8 D_01B00468[];
extern u8 D_01B00478[];
extern u8 D_01B06A18[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B04020(void *, void *, void *, s32);
extern void func_01B01E20(void *);
extern void func_01B040F8(void *, void *, s32, s32, s32, void *, float);
extern float func_01B016B0(s32);
extern void func_01B06580(void *, s32, void *, s32, float, float, float);
extern s32 func_001B5258(s32);
extern void func_001B5298(s32, s32);
extern void func_01B017D8(s32, void *, s32);
extern void func_01B019B0(s32, void *);
extern void func_01B031C0(s32, void *, void *);
extern void func_01B068A8(void *, void *, void *, s32);
extern Task *func_01B03D98(void *);
extern void func_01B03F60(Task *);
extern void func_01B05B30(void *, s32);
extern void func_01B05F88(void *, s32);
extern void func_01B00C48(void);
extern void func_01B00C78(void);
extern void func_01B00DA0(void);
extern void func_01B00EC8(void);
extern void func_01B013A8(void);
extern void func_01B046A8(void);

s32 ovl_09294_0900(void)
{
    float v00[4];
    u8 *p = D_01B6F3C0;
    Mgr7BA8 *mgr;
    Entry130 *e;
    EntryC0 *c;
    s32 i;
    Task *t;

    D_01B07F84 = (s32 *)(p + 0x40000);
    D_01B07BA0 = p + 0x140000;
    D_01B07F80 = p;
    mgr = &D_01B07BA8;
    mgr->w2C = func_002B49A0(D_01B0D2E0, 8, 0);
    func_01B04020(mgr, D_01B00040, D_01B07F80, 0x40000);

    func_01B01E20(v00);
    {
        Entry130 *e0 = &D_01B07BF0;
        register float *dst __asm__("$3");
        func_01B040F8(mgr, e0, 1, 0x1D, 0, 0, 0.5f);
        dst = e0->pos;
        MMI_COPY_LQ_A3(dst, v00);
        MMI_COPY_SQ_A3(dst);
        e0->pos[1] -= 4.0f;
        e0->fC4 = func_01B016B0(-1);
    }

    c = D_01B06A40;
    func_01B06580(c, -1, v00, 0x1E, 0.02f, 0.03f, 0.99f);
    c->w14 = 1;
    c->wA8 = 0xE;
    c->p90 = (void *)func_01B00EC8;
    c->p94 = (void *)func_01B013A8;
    c++;

    for (i = 0; i < 18; i++) {
        func_001B5298(i, func_001B5258(i) - 1);
    }

    e = D_01B071C0;
    for (i = 0; i < D_01B004D8[1]; i++, c++) {
        func_01B040F8(mgr, e, 0, 0x25, 0, (void *)func_01B046A8, 0.3f);
        func_01B017D8(i, e->pos, 1);
        e->fC4 = func_01B016B0(i);
        func_01B019B0(i, v00);
        e++;
        func_01B06580(c, i, v00, 0x10, 0.6f, 1.2f, 1.0f);
        func_01B031C0(i, c, D_01B00468);
        c->wA8 = 0x25;
        c->p90 = (void *)func_01B00DA0;
    }

    {
        Obj7B40 *o = &D_01B07B40;
        func_01B068A8(o, D_01B0D2E0, D_01B00450, 1);
        o->w54 = -1;
    }
    func_01B031C0(-1, D_01B06A18, D_01B00478);

    t = func_01B03D98((void *)func_01B00C48);
    t->b18 = 1;
    func_01B03F60(t);

    func_01B05B30(p + 0x160000, 0x80);
    func_01B05F88(p + 0x163000, 0x80);

    t = func_01B03D98((void *)func_01B00C78);
    t->b18 = 2;
    func_01B03F60(t);

    return 0;
}
