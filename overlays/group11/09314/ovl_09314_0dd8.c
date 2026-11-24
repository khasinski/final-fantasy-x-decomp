#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Ctx85F8;

typedef struct {
    u8 pad00[0xD0];
    float x, y, z, w;
    float e0, e4, e8, ec;
    u8 padF0[0x14];
    void *fn104;
    u8 pad108[0x8];
    void *p110;
    u8 pad114[0x1C];
} Obj130;

typedef struct {
    u8 pad00[0x80];
    u8 b80, b81, b82, b83;
    u8 b84, b85, b86, b87;
    s32 w88;
    u8 pad8C[0xC];
    u8 b98, b99;
} Obj8490;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Node4198;

extern u8 D_01BF8B80[];
extern s32 D_01B08400;
extern u8 *D_01B085F0;
extern u8 *D_01B089D0;
extern u8 *D_01B089D4;
extern u8 D_01B0E110[];
extern Ctx85F8 D_01B085F8;
extern u8 D_01B00040[];
extern Obj130 D_01B08640[];
extern u8 D_01B01720[];
extern u8 D_01B00680[];
extern Obj8490 D_01B08490;
extern u8 D_01B08530[];
extern u8 D_01B08468[];
extern u8 D_01B00878[];
extern u8 D_01B01298[];
extern u8 D_01B012C8[];

extern void func_01B01940(s32, s32);
extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B04420(void *, void *, void *, s32);
extern void func_01B044F8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B01BD8(s32, void *, s32);
extern void func_01B03C80(void *, void *, void *);
extern void func_01B08000(void *, s32);
extern void func_01B081B8(void *, s32, s32, float, float);
extern void func_01B03A08(s32);
extern void func_01B02EE8(s32, s32, s32);
extern void func_01B035C0(s32, void *, void *);
extern void func_01B01140(void);
extern Node4198 *func_01B04198(void *);
extern void func_01B04360(void *);
extern void func_01B07BA8(void *, s32);

s32 ovl_09314_0dd8(void)
{
    u8 *s4 = D_01BF8B80;
    register u8 *s2 __asm__("$18");
    register Ctx85F8 *s1 __asm__("$17");
    Obj130 *s6;
    register u8 *s0 __asm__("$16");
    Obj8490 *v0;
    Node4198 *n;

    D_01B089D0 = s4;
    D_01B089D4 = s4 + 0x40000;
    D_01B085F0 = s4 + 0x140000;
    func_01B01940(D_01B08400, 0);

    s2 = D_01B0E110;
    s1 = &D_01B085F8;
    s1->w2C = func_002B49A0(s2, 8, 0);
    func_01B04420(s1, D_01B00040, D_01B089D0, 0x40000);

    {
        register u8 *s5 __asm__("$21");
        register void *s3 __asm__("$19");
        s6 = D_01B08640;
        func_01B044F8(s1, s6, 0, 16, 0, 0, 0.192f);
        s5 = (u8 *)&s6->x;
        func_01B01BD8(-1, s5, 0);
        s6->y -= 28.0f;
        s6->e8 -= 32.0f;
        s3 = D_01B01720;
        s6->fn104 = s3;
        s0 = s4 + 0x16C000;
        func_01B03C80(s0, s2, D_01B00680);
        __asm__("" : "+r"(s6), "+r"(s0));
        s6->p110 = s0;
        s6++;

        func_01B044F8(s1, s6, 1, 122, 0, 0, 0.216f);
        func_01B01BD8(-1, &s6->x, 0);
        s6->y -= 23.0f;
        s6->e8 -= 30.0f;
        s6->fn104 = s3;

        s6 = (Obj130 *)(s5 + 400);
        func_01B044F8(s1, s6, 2, 16, 0, 0, 1.08f);
        func_01B01BD8(-1, s5 + 608, 3);
        s6->y -= 0.1f;
        s6->e8 -= 30.0f;
        s6->fn104 = s3;
    }

    v0 = &D_01B08490;
    *(volatile u8 *)&v0->b80 = 255;
    *(volatile u8 *)&v0->b83 = 128;
    *(volatile s32 *)&v0->w88 = 121;
    *(volatile u8 *)&v0->b98 = 72;
    *(volatile u8 *)&v0->b82 = 255;
    *(volatile u8 *)&v0->b81 = 255;
    v0->b87 = 0;
    v0->b86 = 0;
    v0->b85 = 0;
    v0->b84 = 0;
    v0->b99 = 0;
    func_01B08000(v0, 16);

    s0 = D_01B08530;
    func_01B081B8(s0, 32, 32, 1.0f, 0.5f);
    func_01B081B8(s0 + 0x40, 16, 220, 0.5f, 1.0f);
    func_01B03A08(1);
    func_01B02EE8(0, 2, 12);
    func_01B035C0(-1, D_01B08468, D_01B00878);
    func_01B01140();
    n = func_01B04198(D_01B01298);
    n->b18 = 1;
    func_01B04360(n);
    func_01B07BA8(s4 + 0x160000, 512);
    n = func_01B04198(D_01B012C8);
    n->b18 = 2;
    func_01B04360(n);
    return 0;
}
