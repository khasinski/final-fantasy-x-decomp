#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Mgr69F8;

typedef struct {
    u8 pad00[0xD0];
    u8 subD0[0x34];
    void *p104;
    u8 pad108[0x18];
    s32 w120;
    u8 pad124[0xC];
} Entry130;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj6990;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task;

typedef struct {
    u8 d[0x10];
} Vec10;

extern u8 D_01B938C0[];
extern void *D_01B06DD0;
extern s32 *D_01B06DD4;
extern u8 *D_01B069F0;
extern s32 D_01B069F4;
extern Mgr69F8 D_01B069F8;
extern u8 D_01B0C120[];
extern u8 D_01B00040[];
extern Entry130 D_01B06CA0;
extern Entry130 D_01B06010[];
extern s32 D_01B00618[];
extern Vec10 D_01B00500[];
extern Obj6990 D_01B06990;
extern u8 D_01B004C8[];
extern u8 D_01B05FE8[];
extern u8 D_01B004E0[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B03F08(void *, void *, void *, s32);
extern void func_01B03FE0(void *, void *, s32, s32, s32, void *, float);
extern void func_01B016C0(s32, void *, s32);
extern s32 func_01B01470(s32);
extern void func_001D43A8(s32);
extern void func_001D43D0(s32, s32, s32, void *);
extern void func_001D4490(s32, s32, s32, s32, float);
extern void func_01B05E70(void *, void *, void *, s32);
extern void func_01B030A8(s32, void *, void *);
extern Task *func_01B03C80(void *);
extern void func_01B03E48(Task *);
extern void func_01B05A18(void *, s32);
extern void func_01B00D40(void);
extern void func_01B00D70(void);
extern void func_01B00DF0(void);
extern void func_01B011D0(void);
extern void func_01B012A8(void);
extern void func_01B045A0(void);

s32 ovl_09287_0a40(void)
{
    u8 *p = D_01B938C0;
    Mgr69F8 *mgr;
    s32 i;
    s32 s2;
    Entry130 *e;
    Task *t;

    D_01B06DD4 = (s32 *)(p + 0x100000);
    D_01B069F0 = p + 0x200000;
    D_01B06DD0 = p;
    mgr = &D_01B069F8;
    mgr->w2C = func_002B49A0(D_01B0C120, 8, 0);
    func_01B03F08(mgr, D_01B00040, D_01B06DD0, 0x100000);
    e = &D_01B06CA0;
    func_01B03FE0(mgr, e, 2, 0x30, 0xA, (void *)func_01B011D0, 0.4f);
    func_01B016C0(0, e->subD0, 0);
    e->p104 = (void *)func_01B012A8;

    e = D_01B06010;
    for (i = 0; i < D_01B00618[1]; i++, e++) {
        func_01B03FE0(mgr, e, 1, 0x3A, 0, (void *)func_01B045A0, 0.4f);
        func_01B016C0(i, e->subD0, 1);
        e->w120 = func_01B01470(i);
    }

    s2 = func_01B01470(-1);
    func_001D43A8(0);
    func_001D43D0(0, s2, 6, 0);
    func_001D43D0(0, s2, 6, 0);
    for (i = 0; i < 14; i++) {
        func_001D43D0(0, s2, 0, &D_01B00500[i]);
    }
    func_001D43D0(0, s2, 1, 0);
    func_001D43D0(0, s2, 1, 0);
    func_001D4490(0, s2, 0x80, 0, 0.5f);

    {
        Obj6990 *o = &D_01B06990;
        func_01B05E70(o, D_01B0C120, D_01B004C8, 1);
        o->w54 = -1;
    }
    {
        register void *a2_4e0 __asm__("$6") = D_01B004E0;
        func_01B030A8(-1, D_01B05FE8, a2_4e0);
    }

    t = func_01B03C80((void *)func_01B00D40);
    t->b18 = 1;
    func_01B03E48(t);

    t = func_01B03C80((void *)func_01B00DF0);
    func_01B03E48(t);

    func_01B05A18(p + 0x220000, 0x200);

    t = func_01B03C80((void *)func_01B00D70);
    t->b18 = 2;
    func_01B03E48(t);

    D_01B069F4 = 0x5A;
    return 0;
}
