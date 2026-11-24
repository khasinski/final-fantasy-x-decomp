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

typedef struct Ovl09555Task {
    u8 pad00[0x18];
    u8 b18;
} Ovl09555Task;

typedef struct Ovl09555Mgr {
    u8 pad00[0x2C];
    s32 w2C;
} Ovl09555Mgr;

typedef struct Ovl09555D1258 {
    u8 pad00[0x4];
    s32 w4;
    u8 pad08[0xD];
    u8 b15;
    u8 b16;
    u8 pad17[0x2D];
    s32 w44[16];
} Ovl09555D1258;

typedef struct Ovl09555Obj {
    u8 pad00[0x30];
    u_long128 q30;
    u8 pad40[0x106];
    u8 b146;
} Ovl09555Obj;

typedef struct Ovl09555Work {
    u8 pad00[0x17C0];
    u8 f17C0[0x30];
    u_long128 q17F0;
    u8 f1800[0x30];
    u_long128 q1830;
    u8 f1840[0x30];
    u_long128 q1870;
    u8 f1880[0x30];
    u_long128 q18B0;
    u8 f18C0[0x30];
    u_long128 q18F0;
    u8 f1900[0x30];
    u_long128 q1930;
    u8 f1940[0x30];
    u_long128 q1970;
    u_long128 q1980;
    u_long128 q1990;
    u_long128 q19A0;
    u_long128 q19B0;
    u_long128 q19C0;
    u_long128 q19D0;
    u_long128 q19E0;
    u_long128 q19F0;
    u_long128 q1A00;
    u_long128 q1A10;
    u_long128 q1A20;
    u_long128 q1A30;
    u_long128 q1A40;
    u_long128 q1A50;
    u_long128 q1A60;
    u8 pad1A70[0x880];
    float f22F0;
    u8 pad22F4[0x18];
    s32 w230C;
} Ovl09555Work;

extern u8 D_01B00040[];
extern u8 D_01B007D0[];
extern u8 D_01B00D80[];
extern Ovl09555D1258 D_01B01258;
extern void *D_01B01464;
extern s32 D_01B0AA58;
extern Ovl09555Mgr D_01B0AA60;
extern s32 D_01B0AAA0;
extern void *D_01B0AAA4;
extern u8 D_01B0AAA8[];
extern u8 D_01B0AB08[];
extern u8 D_01B0AB68[];
extern s32 D_01B0AB7C;
extern u8 D_01B0AB88[];
extern s32 D_01B0AB9C;
extern u8 D_01B0ABA8[];
extern s32 D_01B0ABBC;
extern u8 D_01B0ABC8[];
extern s32 D_01B0ABDC;
extern Ovl09555Work *D_01B0ABE8;
extern void *D_01B0ABEC;
extern u8 D_01B10320[];
extern u8 D_01BEC260[];
extern u8 D_01C510C0[];

void *memcpy(void *, const void *, u32);
void func_002B4980(void *);
s32 func_002B49A0(void *, s32, s32);
s32 func_001B4E58(s32);
void func_001CDDD8(s32);
void func_002DD128(void *);
void func_002DD318(void *, void *, float);

void func_01B01D08(void);
s32 func_01B03A10(s32);
float func_01B03B38(s32);
void func_01B03C60(s32, void *, s32);
void func_01B04928(s32, s32);
void func_01B049C8(s32, s32);
void func_01B04ED0(s32, void *);
void func_01B05450(s32, void *, void *);
void func_01B05700(void *);
void func_01B05A90(s32);
Ovl09555Task *func_01B06220(void *);
void func_01B062A0(void *);
void func_01B063E8(Ovl09555Task *);
void func_01B064A8(void *, void *, void *, s32);
s32 func_01B06660(void *, void *);
void func_01B07908(void);
void func_01B07FB8(s32);
void func_01B08130(void);
Ovl09555Obj *func_01B082E8(s32);
void func_01B09B10(void *, void *);
s32 func_01B09B30(void *);
void func_01B0A020(void *, s32);

void func_01B018F8(void *a0);
void func_01B01A30(void);
void func_01B01A98(void);
void func_01B01C98(void);

s32 func_01B01758(void)
{
    u8 *base;
    Ovl09555D1258 *d1258;
    Ovl09555Mgr *mgr;
    s32 idx;
    Ovl09555Task *t;

    func_002B4980(D_01BEC260);
    base = D_01C510C0;
    D_01B0AAA0 = 0;
    D_01B0AAA4 = base + 0x40000;
    D_01B0ABEC = base + 0x140000;
    D_01B0ABE8 = (Ovl09555Work *)(base + 0x1A0000);

    d1258 = &D_01B01258;
    idx = func_01B03A10(-1);
    d1258->b15 = ++idx;
    d1258->w44[idx] = func_001B4E58(idx);
    d1258->b16 = ++idx;
    d1258->w44[idx] = func_001B4E58(idx);
    d1258->w4 = 3;

    mgr = &D_01B0AA60;
    mgr->w2C = func_002B49A0(D_01B10320, 8, 0);
    func_01B064A8(mgr, D_01B00040, base, 0x40000);
    func_01B01A98();
    func_01B01C98();
    func_01B09B10(D_01B0AAA8, D_01B007D0);
    func_01B09B10(D_01B0AB08, D_01B00D80);
    func_01B05A90(1);
    t = func_01B06220(func_01B018F8);
    t->b18 = 1;
    func_01B063E8(t);
    func_01B0A020(base + 0x180000, 0x400);
    t = func_01B06220(func_01B01A30);
    t->b18 = 2;
    func_01B063E8(t);
    return 0;
}

void func_01B018F8(void *a0)
{
    Ovl09555Work *w = D_01B0ABE8;
    s32 ret;

    func_01B07908();
    D_01B01464 = D_01B0ABEC;
    ret = func_01B09B30(D_01B0AAA8);
    func_01B09B30(D_01B0AB08);
    if (ret == 0) {
        copy_q(&w->q17F0, &w->q1990);
        copy_q(&w->q1830, &w->q19B0);
        copy_q(&w->q1870, &w->q19D0);
        copy_q(&w->q18B0, &w->q19F0);
        copy_q(&w->q18F0, &w->q1A10);
        copy_q(&w->q1930, &w->q1A30);
        copy_q2(&w->q1970, &w->q1A50);
        func_01B05700(D_01B0AB68);
        func_01B05700(D_01B0AB88);
        func_01B05700(D_01B0ABA8);
        func_01B05700(D_01B0ABC8);
        func_01B08130();
    } else {
        w->w230C = 1;
        func_01B01D08();
        func_01B062A0(a0);
    }
}

void func_01B01A30(void)
{
    Ovl09555Work *w = D_01B0ABE8;

    if (func_01B06660(&D_01B0AA60, D_01B0AAA4) == 1 && w->w230C == 1) {
        func_001CDDD8(D_01B0AA58);
    }
}

void func_01B01A98(void)
{
    register Ovl09555Work *w __asm__("$16") = D_01B0ABE8;
    float pos[4];
    float rot[4];

    func_01B03C60(0, pos, 0);
    copy_q(&w->q1A60, pos);
    rot[0] = 0.0f;
    rot[1] = func_01B03B38(0);
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    copy_q2(&w->q1980, rot);
    copy_q(&w->q1990, pos);
    func_01B04ED0(0, w->f17C0);
    func_01B05450(0, w->f17C0, rot);
    copy_q(&w->q17F0, &w->q1990);

    copy_q(&w->q19A0, rot);
    copy_q(&w->q19B0, pos);
    func_01B04ED0(-1, w->f1800);
    func_01B05450(-1, w->f1800, rot);
    copy_q(&w->q1830, &w->q19B0);

    copy_q(&w->q19C0, rot);
    copy_q(&w->q19D0, pos);
    func_01B04ED0(1, w->f1840);
    func_01B05450(1, w->f1840, rot);
    copy_q(&w->q1870, &w->q19D0);

    copy_q(&w->q19E0, rot);
    copy_q(&w->q19F0, pos);
    func_01B04ED0(2, w->f1880);
    func_01B05450(2, w->f1880, rot);
    copy_q(&w->q18B0, &w->q19F0);

    func_01B049C8(-1, 1);
    func_01B049C8(1, 1);
    func_01B049C8(2, 1);
    func_01B04928(-1, 0);
    func_01B04928(1, 0);
    func_01B04928(2, 0);

    w->w230C = 0;
    w->f22F0 = rot[1];
    D_01B0AB7C = 1;
    D_01B0AB9C = 1;
    D_01B0ABBC = 1;
    D_01B0ABDC = 1;
}

void func_01B01C98(void)
{
    Ovl09555Work *w = D_01B0ABE8;
    Ovl09555Obj *obj;

    func_01B07FB8(0);
    obj = func_01B082E8(0);
    obj->b146 = 1;
    func_002DD128(obj);
    func_002DD318(obj, obj, w->f22F0);
    copy_q(&obj->q30, &w->q1990);
}
