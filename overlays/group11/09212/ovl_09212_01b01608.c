#include "common.h"

#define LQ_A3(src) __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory")
#define LQ_A3_2(dst, src) __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory")
#define SQ_A3(dst) __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory")

static inline void copy_q(void *dst, const void *src)
{
    LQ_A3(src);
    SQ_A3(dst);
}

static inline void copy_q2(void *dst, const void *src)
{
    LQ_A3_2(dst, src);
    SQ_A3(dst);
}

typedef struct Ovl09212Task {
    u8 pad00[0x18];
    u8 b18;
} Ovl09212Task;

typedef struct Ovl09212Mgr {
    u8 pad00[0x2C];
    s32 w2C;
} Ovl09212Mgr;

typedef struct Ovl09212Obj {
    u8 pad00[0x30];
    u_long128 q30;
    u8 pad40[0x106];
    u8 b146;
} Ovl09212Obj;

typedef struct Ovl09212Work {
    u8 pad00[0x980];
    u8 f980[0x30];
    u_long128 q9B0;
    u8 f9C0[0x30];
    u_long128 q9F0;
    u8 padA00[0x80];
    u_long128 qA80;
    u_long128 qA90;
    u_long128 qAA0;
    u_long128 qAB0;
    u_long128 qAC0;
    u8 padAD0[0x3F0];
    union {
        struct {
            s32 w0;
            s32 w4;
            s32 w8;
            s32 wC;
        } s;
        u_long128 q;
    } vEC0;
    u_long128 qED0;
    u_long128 qEE0;
    s32 wEF0;
    s32 wEF4;
    u8 padEF8[0x22C8];
    s32 w31C0;
    s32 w31C4;
    float f31C8;
    u8 pad31CC[0xC];
    s32 w31D8;
} Ovl09212Work;

extern u8 D_01B00040[];
extern u8 D_01B00848[];
extern u8 D_01B00CF0[];
extern void *D_01B01304;
extern s32 D_01B0A798;
extern Ovl09212Mgr D_01B0A7A0;
extern s32 D_01B0A7E0;
extern void *D_01B0A7E4;
extern u8 D_01B0A7E8[];
extern u8 D_01B0A848[];
extern u8 D_01B0A8A8[];
extern s32 D_01B0A8BC;
extern u8 D_01B0A8C8[];
extern s32 D_01B0A8DC;
extern Ovl09212Work *D_01B0A8E8;
extern void *D_01B0A8EC;
extern void *D_01B0A8F0;
extern u8 D_01B0FE70[];
extern u8 D_01BEC690[];
extern u8 D_01CD60C0[];

void *memcpy(void *, const void *, u32);
void func_002B4980(void *);
s32 func_002B49A0(void *, s32, s32);
void func_001CDDD8(s32);
void func_002DD128(void *);
void func_002DD318(void *, void *, float);
void func_00293F10(s32);
void func_001CF840(s32);
void func_0029A890(void);

void func_01B01AF8(void *);
void func_01B01B90(void);
float func_01B03A70(s32);
void func_01B03B98(s32, void *, s32);
void func_01B046F0(s32);
void func_01B04860(s32, s32);
void func_01B04900(s32, s32);
void func_01B04C00(s32, s32);
void func_01B04C30(s32, s32);
void func_01B04D78(s32, s32, float);
void func_01B04E08(s32, void *);
void func_01B05388(s32, void *, void *);
void func_01B05638(void *);
void func_01B059C8(s32);
void func_01B059E8(s32);
Ovl09212Task *func_01B06158(void *);
void func_01B061D8(void *);
void func_01B06320(Ovl09212Task *);
void func_01B063E0(void *, void *, void *, s32);
s32 func_01B06598(void *, void *);
void func_01B07840(void);
void func_01B07EF0(s32);
void func_01B08030(void);
void func_01B08068(void);
Ovl09212Obj *func_01B08220(s32);
void func_01B09A48(void *, void *);
s32 func_01B09A68(void *);

void func_01B01748(void *a0);
void func_01B01820(void);
void func_01B01888(void);
void func_01B019E8(void);
void func_01B01A58(void);
void func_01B01AC8(void *a0, s32 a1);

s32 func_01B01608(void)
{
    u8 *base;
    Ovl09212Mgr *mgr;
    Ovl09212Task *t;

    func_002B4980(D_01BEC690);
    base = D_01CD60C0;
    D_01B0A7E0 = 0;
    D_01B0A7E4 = base + 0x40000;
    D_01B0A8F0 = base + 0x140000;
    D_01B0A8EC = base + 0x180000;
    D_01B0A8E8 = (Ovl09212Work *)(base + 0x1C0000);
    mgr = &D_01B0A7A0;
    mgr->w2C = func_002B49A0(D_01B0FE70, 8, 0);
    func_01B063E0(mgr, D_01B00040, base, 0x40000);
    func_01B01888();
    func_01B01B90();
    func_01B019E8();
    func_01B09A48(D_01B0A7E8, D_01B00848);
    func_01B09A48(D_01B0A848, D_01B00CF0);
    func_01B059C8(1);
    t = func_01B06158(func_01B01748);
    t->b18 = 1;
    func_01B06320(t);
    t = func_01B06158(func_01B01820);
    t->b18 = 2;
    func_01B06320(t);
    return 0;
}

void func_01B01748(void *a0)
{
    Ovl09212Work *w = D_01B0A8E8;
    s32 ret;

    func_01B07840();
    D_01B01304 = D_01B0A8F0;
    ret = func_01B09A68(D_01B0A7E8);
    func_01B09A68(D_01B0A848);
    if (ret == 0) {
        copy_q(&w->q9B0, &w->qA90);
        copy_q(&w->q9F0, &w->qAB0);
        func_01B05638(D_01B0A8A8);
        func_01B05638(D_01B0A8C8);
        func_01B01AF8(&w->vEC0);
        func_01B08068();
    } else {
        w->w31D8 = 1;
        func_01B01A58();
        func_01B061D8(a0);
    }
}

void func_01B01820(void)
{
    Ovl09212Work *w = D_01B0A8E8;

    if (func_01B06598(&D_01B0A7A0, D_01B0A7E4) == 1 && w->w31D8 == 1) {
        func_001CDDD8(D_01B0A798);
    }
}

void func_01B01888(void)
{
    Ovl09212Work *w = D_01B0A8E8;
    float pos[4];
    float rot[4];

    func_01B03B98(0, pos, 0);
    copy_q(&w->qAC0, pos);
    rot[0] = 0.0f;
    rot[1] = func_01B03A70(0);
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    copy_q2(&w->qA80, rot);
    copy_q(&w->qA90, pos);
    func_01B04E08(0, w->f980);
    func_01B05388(0, w->f980, rot);
    copy_q(&w->q9B0, &w->qA90);
    copy_q(&w->qAA0, rot);
    copy_q(&w->qAB0, pos);
    func_01B04E08(-1, w->f9C0);
    func_01B05388(-1, w->f9C0, rot);
    copy_q(&w->q9F0, &w->qAB0);
    func_01B04900(-1, 1);
    func_01B04860(-1, 0);
    w->f31C8 = rot[1];
    {
        s32 *ec0 = &w->vEC0.s.w0;
        w->vEC0.s.w0 = 0;
        ec0[1] = 0;
        ec0[2] = 0;
        ec0[3] = 0x80;
        func_01B01AC8(ec0, 1);
    }
    w->w31C0 = 0;
    w->w31C4 = 0;
    w->w31D8 = 0;
    D_01B0A8BC = 1;
    D_01B0A8DC = 1;
}

void func_01B019E8(void)
{
    Ovl09212Work *w = D_01B0A8E8;
    Ovl09212Obj *obj;

    func_01B07EF0(0);
    obj = func_01B08220(0);
    obj->b146 = 1;
    func_002DD128(obj);
    func_002DD318(obj, obj, w->f31C8);
    copy_q(&obj->q30, &w->qA90);
}

void func_01B01A58(void)
{
    func_01B04C30(-1, 0);
    func_01B04C00(-1, -1);
    func_01B04D78(-1, 1, 1.0f);
    func_01B08030();
    func_00293F10(1);
    func_001CF840(1);
    func_0029A890();
    func_01B046F0(-1);
    func_01B059E8(1);
}

void func_01B01AC8(void *a0, s32 a1)
{
    Ovl09212Work *w = D_01B0A8E8;
    s32 *f = &w->vEC0.s.w0;

    copy_q2(&w->qED0, f);
    copy_q2(&w->qEE0, a0);
    f[0x34 / 4] = a1;
    f[0x30 / 4] = a1;
}
