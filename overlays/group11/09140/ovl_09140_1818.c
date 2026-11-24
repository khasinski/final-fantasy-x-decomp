#include "common.h"

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x100];
    u8 sub120[0x20];
    float f140;
    float f144;
    u8 pad148[0x08];
    u8 sub150[0x20];
    float f170;
    float f174;
    float f178;
    float f17c;
    u8 sub180[0x150];
    int unk2d0;
    short unk2d4;
} Arg09140;

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
    u8 pad3c[0x24];
    float f60;
    float f64;
    float f68;
    float f6c;
} Obj09140;

typedef struct { void *a; void *b; void *c; } Args3;
typedef struct { void *a; void *b; } Args2;
typedef struct { void *a; void *b; int c; u8 d; } Args3B;
typedef struct { void *a; void *b; void *c; void *d; void *e; void *f; } Args6P;
typedef struct { void *a; void *b; int c; } Args2I;
typedef struct { void *a; void *b; void *c; int d; void *e; int f; } ArgsB590;
typedef struct { void *a; void *b; void *c; void *d; int e; int f; } ArgsAD20;
typedef struct { void *a; int b; } ArgsPI;
typedef struct { void *a; int b; float c; } ArgsPIF;

extern u8 D_01B01708[];
extern u8 D_01B00940[];
extern u8 D_01B00958[];
extern u8 D_01B00978[];
extern u8 D_01B009E0[];
extern u8 D_01B00730[];
extern u8 D_01B006A0[];
extern u8 D_01B00BC0[];
extern u8 D_01B00C30[];
extern Obj09140 D_01B00CD0;
extern u8 D_01B00590;
extern int D_01B00578;
extern u8 D_01B0D930[];
extern int D_01B0D95C;

extern void fn_ovl_c540(void *);
extern void fn_ovl_c948(void *);
extern void fn_ovl_3268(void *);
extern void fn_ovl_6cc0(void *);
extern void fn_ovl_9430(void *);
extern int fn_ovl_13b8(int);
extern void fn_ovl_2fc8(void *);
extern void fn_ovl_b590(void *);
extern void fn_ovl_ad20(void *);
extern void fn_ovl_ace8(void *);
extern void fn_ovl_6008(void *);
extern void fn_ovl_6138(void *);

void ovl_09140_1818(Arg09140 *arg0)
{
    union {
        void *m0[10];
        Args3 c540;
        Args2 c948;
        Args3B c3268;
        Args2 c6cc0;
        Args2I c2fc8;
        ArgsB590 cb590;
        ArgsAD20 cad20;
        ArgsPI cace8;
        Args2 c6008;
        ArgsPIF c6138;
    } a;

    a.c540.a = arg0;
    a.c540.b = D_01B01708;
    a.c540.c = arg0;
    fn_ovl_c540(&a.c540);

    a.c948.a = D_01B00940;
    a.c948.b = arg0;
    fn_ovl_c948(&a.c948);

    arg0->unk2d0 = 0;
    arg0->unk2d4 = 0;

    a.c3268.a = D_01B00C30;
    a.c3268.b = D_01B00958;
    a.c3268.c = D_01B00590;
    a.c3268.d = 0;
    fn_ovl_3268(&a.c3268);

    a.c6cc0.a = arg0->sub120;
    a.c6cc0.b = D_01B00958;
    fn_ovl_6cc0(&a.c6cc0);

    a.c6cc0.a = arg0->sub150;
    a.c6cc0.b = D_01B00958;
    fn_ovl_6cc0(&a.c6cc0);

    {
        float one = 1.0f;
        register void *c730 __asm__("$3") = D_01B00730;
        register void *c9e0 __asm__("$5") = D_01B009E0;
        *(void * volatile *)&a.m0[4] = arg0->sub180;
        {
            void **v0 = a.m0 + 4;
            *(volatile float *)&arg0->f17c = one;
            v0[1] = D_01B00958;
            v0[2] = c730;
            *(void * volatile *)&a.m0[7] = arg0->sub120;
            v0[4] = c9e0;
            a.m0[9] = arg0->sub150;
            arg0->f174 = one;
            arg0->f178 = one;
            arg0->f170 = one;
            fn_ovl_9430(v0);
        }
    }

    if (fn_ovl_13b8(D_01B00590) != 0) {
        a.c2fc8.a = D_01B00C30;
        a.c2fc8.b = &arg0->f140;
        a.c2fc8.c = 0;
        fn_ovl_2fc8(&a.c2fc8);

        a.cb590.a = arg0->sub20;
        a.cb590.b = D_01B00978;
        a.cb590.c = arg0->sub180;
        a.cb590.d = D_01B0D95C;
        a.cb590.e = D_01B0D930;
        a.cb590.f = 1;
        fn_ovl_b590(&a.cb590);
    } else {
        a.c2fc8.a = D_01B00C30;
        a.c2fc8.b = &arg0->f140;
        a.c2fc8.c = 1;
        fn_ovl_2fc8(&a.c2fc8);

        arg0->f144 -= 0.2f;

        a.cb590.a = arg0->sub20;
        a.cb590.b = D_01B00978;
        a.cb590.c = arg0->sub180;
        a.cb590.d = D_01B0D95C;
        a.cb590.e = D_01B0D930;
        a.cb590.f = 0;
        fn_ovl_b590(&a.cb590);
    }

    a.cad20.a = D_01B00BC0;
    a.cad20.b = D_01B00958;
    a.cad20.c = arg0->sub180;
    a.cad20.d = D_01B006A0;
    a.cad20.e = D_01B00578;
    a.cad20.f = 0;
    fn_ovl_ad20(&a.cad20);

    a.cace8.a = D_01B00BC0;
    a.cace8.b = 0;
    fn_ovl_ace8(&a.cace8);

    a.cad20.a = D_01B00BC0 + 0x38;
    a.cad20.b = D_01B00958;
    a.cad20.c = arg0->sub180;
    a.cad20.d = D_01B006A0;
    a.cad20.e = D_01B00578;
    a.cad20.f = 1;
    fn_ovl_ad20(&a.cad20);

    a.cace8.a = D_01B00BC0 + 0x38;
    a.cace8.b = 0;
    fn_ovl_ace8(&a.cace8);

    a.c6008.a = &D_01B00CD0;
    a.c6008.b = D_01B00978;
    fn_ovl_6008(&a.c6008);

    D_01B00CD0.f6c = 1.0f / 3.0f;
    D_01B00CD0.f68 = 1.0f / 3.0f;
    D_01B00CD0.f64 = 1.0f / 3.0f;
    D_01B00CD0.f60 = 1.0f / 3.0f;
    D_01B00CD0.f38 = 1.0f / 3.0f;
    D_01B00CD0.f34 = 1.0f / 3.0f;
    D_01B00CD0.f30 = 1.0f / 3.0f;

    a.c6138.a = &D_01B00CD0;
    a.c6138.b = 0;
    a.c6138.c = 0.1f;
    fn_ovl_6138(&a.c6138);
}
