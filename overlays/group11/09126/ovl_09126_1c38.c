#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x24];
    float f60;
    float f64;
    float f68;
    float f6C;
} ObjC30;

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x100];
    u8 sub120[0x100];
    u8 sub220[0x20];
    Vec4 pos240;
    u8 sub250[0x20];
    Vec4 pos270;
    u8 sub280[0x20];
    Vec4 scale2A0;
    u8 sub2B0[0x20];
    Vec4 scale2D0;
    u8 sub2E0[0x150];
    u8 sub430[0x150];
    float f580;
    u16 state;
} Work9126;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} Args6P;

extern s32 D_01B004D8;
extern u8 D_01B004F0;
extern u8 D_01B00600[];
extern u8 D_01B00690[];
extern u8 D_01B008A0[];
extern u8 D_01B008B8[];
extern u8 D_01B008D8[];
extern u8 D_01B00940[];
extern u8 D_01B009D0[];
extern u8 D_01B00B20[];
extern u8 D_01B00B90[];
extern ObjC30 D_01B00C30;
extern u8 D_01B0DDF0[];
extern s32 D_01B0DE1C;

extern void ovl_09126_1918(void);
extern void ovl_09126_1a20(void);
extern int func_01B015C8(u32);
extern void func_01B03490(void *);
extern void func_01B03730(void *);
extern void func_01B064D0(void *);
extern void func_01B06600(void *);
extern void func_01B07188(void *);
extern void func_01B098F8(void *);
extern void func_01B0B1B0(void *);
extern void func_01B0B1E8(void *);
extern void func_01B0BA58(void *);
extern void func_01B0CA08(void *);
extern void func_01B0CE10(void *);

void ovl_09126_1c38(Work9126 *w)
{
    union {
        void *m0[10];
        struct { void *a, *b; u32 c; u8 d; } c3730;
        struct { void *a, *b, *c; } c3p;
        struct { void *a, *b; } c2p;
        struct { void *a, *b, *c; s32 d; void *e; int f; } cba58;
        struct { void *a, *b, *c, *d; s32 e; int f; } cb1e8;
        struct { void *a; int b; float c; } c6600;
        Args6P c98f8;
    } a;
    ObjC30 *o = &D_01B00C30;

    a.c3730.a = D_01B00B90;
    a.c3730.b = D_01B008B8;
    a.c3730.c = D_01B004F0;
    a.c3730.d = 0;
    func_01B03730(&a.c3730);

    if (func_01B015C8(D_01B004F0) != 0) {
        a.c3p.a = w;
        a.c3p.b = (void *)ovl_09126_1918;
        a.c3p.c = w;
        func_01B0CA08(&a.c3p);

        a.c2p.a = D_01B008A0;
        a.c2p.b = w;
        func_01B0CE10(&a.c2p);

        w->f580 = 0.0f;
        w->state = 0;

        a.c2p.a = w->sub220;
        a.c2p.b = D_01B008B8;
        func_01B07188(&a.c2p);

        a.c3p.a = D_01B00B90;
        a.c3p.b = &w->pos240;
        a.c3p.c = 0;
        func_01B03490(&a.c3p);

        a.c2p.a = w->sub280;
        a.c2p.b = D_01B008B8;
        func_01B07188(&a.c2p);

        {
            float one = 1.0f;
            register void *c690 __asm__("$3") = D_01B00690;
            register void *c940 __asm__("$5") = D_01B00940;
            *(void * volatile *)&a.m0[4] = w->sub2E0;
            {
                void **v0 = a.m0 + 4;
                *(volatile float *)&w->scale2A0.w = one;
                v0[1] = D_01B008B8;
                v0[2] = c690;
                *(void * volatile *)&a.m0[7] = w->sub220;
                v0[4] = c940;
                a.m0[9] = w->sub280;
                w->scale2A0.y = one;
                w->scale2A0.z = one;
                w->scale2A0.x = one;
                func_01B098F8(v0);
            }
        }

        a.cba58.a = w->sub20;
        a.cba58.b = D_01B008D8;
        a.cba58.c = w->sub2E0;
        a.cba58.d = D_01B0DE1C;
        a.cba58.e = D_01B0DDF0;
        a.cba58.f = 2;
        func_01B0BA58(&a.cba58);
    } else {
        a.c3p.a = w;
        a.c3p.b = (void *)ovl_09126_1a20;
        a.c3p.c = w;
        func_01B0CA08(&a.c3p);

        a.c2p.a = D_01B008A0;
        a.c2p.b = w;
        func_01B0CE10(&a.c2p);

        w->f580 = 0.0f;
        w->state = 0;

        a.c2p.a = w->sub220;
        a.c2p.b = D_01B008B8;
        func_01B07188(&a.c2p);

        a.c3p.a = D_01B00B90;
        a.c3p.b = &w->pos240;
        a.c3p.c = 0;
        func_01B03490(&a.c3p);

        a.c2p.a = w->sub280;
        a.c2p.b = D_01B008B8;
        func_01B07188(&a.c2p);

        {
            float one = 1.0f;
            register void *c690 __asm__("$2") = D_01B00690;
            register void *c940 __asm__("$3") = D_01B00940;
            *(volatile float *)&w->scale2A0.w = one;
            *(void * volatile *)&a.c98f8.p04 = D_01B008B8;
            a.c98f8.p08 = c690;
            a.c98f8.p0C = w->sub220;
            a.c98f8.p10 = c940;
            a.c98f8.p14 = w->sub280;
            w->scale2A0.y = one;
            w->scale2A0.z = one;
            w->scale2A0.x = one;
            a.c98f8.p00 = w->sub2E0;
            func_01B098F8(&a.c98f8);
        }

        a.cba58.a = w->sub20;
        a.cba58.b = D_01B008D8;
        a.cba58.c = w->sub2E0;
        a.cba58.d = D_01B0DE1C;
        a.cba58.e = D_01B0DDF0;
        a.cba58.f = 1;
        func_01B0BA58(&a.cba58);
    }

    a.cb1e8.a = D_01B00B20;
    a.cb1e8.b = D_01B008B8;
    a.cb1e8.c = D_01B009D0;
    a.cb1e8.d = D_01B00600;
    a.cb1e8.e = D_01B004D8;
    a.cb1e8.f = 0;
    func_01B0B1E8(&a.cb1e8);

    a.c2p.a = D_01B00B20;
    a.c2p.b = 0;
    func_01B0B1B0(&a.c2p);

    a.cb1e8.a = D_01B00B20 + 0x38;
    a.cb1e8.b = D_01B008B8;
    a.cb1e8.c = D_01B009D0;
    a.cb1e8.d = D_01B00600;
    a.cb1e8.e = D_01B004D8;
    a.cb1e8.f = 1;
    func_01B0B1E8(&a.cb1e8);

    a.c2p.a = D_01B00B20 + 0x38;
    a.c2p.b = 0;
    func_01B0B1B0(&a.c2p);

    a.c2p.a = o;
    a.c2p.b = D_01B008D8;
    func_01B064D0(&a.c2p);

    o->f6C = 0.5f;
    o->f68 = 0.5f;
    o->f64 = 0.5f;
    o->f60 = 0.5f;
    o->f38 = 0.5f;
    o->f34 = 0.5f;
    o->f30 = 0.5f;

    a.c6600.a = o;
    a.c6600.b = 0;
    a.c6600.c = 0.1f;
    func_01B06600(&a.c6600);
}
