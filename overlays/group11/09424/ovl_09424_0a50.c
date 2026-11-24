#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Mgr8300;

typedef struct {
    u8 pad00[0x104];
    void *p104;
    u8 pad108[0x28];
} Entry130;

typedef struct {
    u8 pad00[0x4D0];
    s32 w4D0;
    u8 pad4D4[0xC];
} Entry4E0;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} Entry0C;

typedef struct {
    u8 pad00[0xC];
    s32 w0C;
    u8 pad10[0xC];
    s16 h1C;
} Obj6378;

typedef struct {
    float f00;
    s32 w04;
    s32 w08;
    s32 w0C;
    u8 pad10[0x8];
    u16 h18;
} Obj8250;

typedef struct {
    u8 pad00[0x4];
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    u8 pad1C[0xC];
    float f28;
    u16 h2C;
} Obj8270;

typedef struct {
    u8 pad00[0x14];
    void *p14;
    u8 b18;
} Task;

extern u8 D_01B99D80[];
extern u8 *D_01B08800;
extern u8 *D_01B08804;
extern u8 D_01B0D9B0[];
extern u8 D_01B00040[];
extern Mgr8300 D_01B08300;
extern Entry130 D_01B08340;
extern Entry130 D_01B063A0[];
extern Entry4E0 D_01B06990[];
extern s32 D_01B00568[];
extern s32 D_01B00628[];
extern Entry0C D_01B081F0[];
extern u8 D_01B082A0[];
extern u8 D_01B00580[];
extern u8 D_01B06358[];
extern u8 D_01B005B0[];
extern Obj6378 D_01B06378;
extern u8 D_01B005C8[];
extern Obj8250 D_01B08250;
extern Obj8270 D_01B08270;

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B04010(void *, void *, void *, s32);
extern void func_01B040E8(void *, void *, s32, s32, s32, void *, float);
extern Task *func_01B03D88(void *);
extern void func_01B03F50(Task *);
extern void func_01B061D8(void *, void *, void *, s32);
extern s32 func_01B031B0(s32, void *, void *);
extern s32 func_01B01330(void);
extern void func_01B05E38(void *, s32);
extern void func_01B05F40(void *, s32);
extern void func_01B00D10(void);
extern void func_01B00DD8(void);
extern void func_01B010D0(void);
extern void func_01B012A8(void);
extern void func_01B012B0(void);

s32 ovl_09424_0a50(void)
{
    u8 *p = D_01B99D80;
    Mgr8300 *mgr;
    s32 i;
    s32 n;
    Entry130 *e;
    Entry4E0 *p6990;
    s32 *p568;
    Entry0C *p1f0;
    Task *t;

    D_01B08804 = p + 0x40000;
    D_01B08800 = p;
    mgr = &D_01B08300;
    mgr->w2C = func_002B49A0(D_01B0D9B0, 8, 0);
    func_01B04010(mgr, D_01B00040, D_01B08800, 0x40000);
    e = &D_01B08340;
    func_01B040E8(mgr, e, 0, 0, 0, 0, 0.05f);
    {
        register void (*fn)(void) __asm__("$3") = func_01B012A8;
        e->p104 = (void *)fn;
    }

    e = D_01B063A0;
    p6990 = D_01B06990;
    p568 = D_01B00568;
    for (i = 0; i < 5; i++, p6990++) {
        s32 val = *p568;
        func_01B040E8(mgr, e, 2, val, 0, (void *)func_01B012B0, 0.08f);
        e++;
        p6990->w4D0 = val;
        t = func_01B03D88((void *)func_01B00DD8);
        p568++;
        t->p14 = p6990;
        func_01B03F50(t);
    }

    n = D_01B00628[1];
    p1f0 = D_01B081F0;
    for (i = 0; i < n; i++, p1f0++) {
        p1f0->w0 = 0x45;
        p1f0->w4 = 0xC;
        p1f0->w8 = 0;
    }

    func_01B061D8(D_01B082A0, D_01B0D9B0, D_01B00580, 0);
    func_01B031B0(-1, D_01B06358, D_01B005B0);
    func_01B031B0(-1, &D_01B06378, D_01B005C8);
    D_01B06378.w0C = func_01B01330();
    D_01B06378.h1C = 2;

    D_01B08250.f00 = 0.0f;
    D_01B08250.w04 = 0;
    D_01B08250.w08 = 0;
    D_01B08250.w0C = 0;
    func_01B05E38(&D_01B08250, 1);
    D_01B08250.h18 |= 1;

    {
        Obj8270 *o = &D_01B08270;
        func_01B05F40(o, 1);
        o->h2C |= 7;
        o->f04 = 1.0f;
        o->f08 = 1.0f;
        o->f0C = 0.0f;
        o->f10 = 4.0f;
        o->f14 = 4.0f;
        __asm__("" : "+r"(o));
        o->f18 = 0.0f;
        __asm__("" : "+r"(o));
        o->f28 = 0.0f;
    }

    t = func_01B03D88((void *)func_01B010D0);
    func_01B03F50(t);
    t = func_01B03D88((void *)func_01B00D10);
    t->b18 = 2;
    func_01B03F50(t);

    return 0;
}
