#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 w18;
    s32 w1C;
    u8 sub20[0x14];
    s32 w34;
    u8 pad38[0xA8];
    u8 subE0[0x20];
    u8 sub100[0x0C];
    float f10C;
    u8 sub110[0x20];
    u8 sub130[0x10];
    u8 sub140[0x10];
} Obj34E8;

typedef struct {
    void *p00;
    Obj34E8 *p04;
} Arg34E8;

typedef struct {
    void *p00;
} Call1;

typedef struct {
    void *p00;
    void *p04;
} Call2;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
} Call3;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
} Call4;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} Call6;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    s32 w0C;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
} Call8;

extern void func_1B04860(Call1 *);
extern void func_1B0B078(Call1 *);
extern void func_1B0AFD0(Call1 *);
extern void func_1B0A500(Call1 *);
extern void func_1B0A458(Call1 *);
extern void func_1B0A080(Call1 *);
extern void func_1B09F88(Call1 *);
extern void func_1B0EE50(Call1 *);

extern void func_1B0EDA8(Call3 *);
extern void func_1B0F1B0(Call2 *);
extern void func_1B09F38(Call2 *);
extern void func_1B06128(Call2 *);
extern void func_1B0A408(Call2 *);
extern void func_1B06470(Call2 *);
extern void func_1B0AF80(Call6 *);
extern void func_1B04AA8(Call4 *);
extern void func_1B048E0(Call8 *);
extern void func_1B04A90(Call1 *);

extern u8 D_01B00880;
extern u8 D_01B00898;
extern u8 D_01B00670;
extern u8 D_01B00610;
extern u8 D_01B008B8;

void ovl_09470_34e8(Arg34E8 *s4)
{
    Obj34E8 *s3 = s4->p04;

retry:
    switch (s3->w18) {
    case 0:
        s3->w1C = 30;
        s3->w18++;
    case 1:
        if (s3->w1C <= 0) {
            s3->w18 = 10000;
            goto retry;
        }
        break;
    case 10000:
        {
            Call1 c;
            c.p00 = s3->sub20;
            func_1B04860(&c);
        }
        s3->w18++;
    case 10001:
        if (s3->w34 != 0) {
            {
                Call1 c;
                c.p00 = s3->sub140;
                func_1B0B078(&c);
            }
            {
                Call1 c;
                c.p00 = s3->sub140;
                func_1B0AFD0(&c);
            }
            {
                Call1 c;
                c.p00 = s3->sub110;
                func_1B0A500(&c);
            }
            {
                Call1 c;
                c.p00 = s3->sub110;
                func_1B0A458(&c);
            }
            {
                Call1 c;
                c.p00 = s3->subE0;
                func_1B0A080(&c);
            }
            {
                Call1 c;
                c.p00 = s3->subE0;
                func_1B09F88(&c);
            }
            {
                Call1 c;
                c.p00 = s4->p00;
                func_1B0EE50(&c);
            }
            s3->w18 = 20000;
        }
        break;
    }
    s3->w1C--;
}

void ovl_09470_3628(Obj34E8 *s0, void *s2, void *s7, void *fp)
{
    register u8 *s1 __asm__("$17");
    register u8 *s6 __asm__("$22") = s0->sub140;
    register u8 *s5 __asm__("$21") = s0->sub110;
    register u8 *s4 __asm__("$20") = s0->subE0;
    register u8 *s3 __asm__("$19") = s0->sub20;
    union {
        Call3 c3;
        Call2 c2;
        Call4 c4;
        Call8 c8;
        struct {
            u8 pad[0x10];
            Call6 c6;
        } s6;
    } u;
    Call1 c1;

    u.c3.p00 = s0;
    u.c3.p08 = s0;
    u.c3.p04 = ovl_09470_34e8;
    func_1B0EDA8(&u.c3);

    u.c2.p00 = &D_01B00880;
    u.c2.p04 = s0;
    func_1B0F1B0(&u.c2);

    s1 = &D_01B00898;
    u.c2.p00 = s4;
    u.c2.p04 = s1;
    func_1B09F38(&u.c2);

    u.c2.p00 = s2;
    u.c2.p04 = s0->sub100;
    func_1B06128(&u.c2);

    s0->f10C = 1.0f;

    u.c2.p00 = s5;
    u.c2.p04 = s1;
    func_1B0A408(&u.c2);

    u.c2.p00 = s2;
    u.c2.p04 = s0->sub130;
    func_1B06470(&u.c2);

    {
        register Call6 *p __asm__("$2");
        register void *r8 __asm__("$3") = &D_01B00670;
        register void *r14 __asm__("$5");
        u.s6.c6.p0C = s4;
        p = &u.s6.c6;
        p->p04 = s1;
        p->p08 = r8;
        r14 = &D_01B00610;
        u.s6.c6.p10 = s5;
        p->p14 = r14;
        u.s6.c6.p00 = s6;
        func_1B0AF80(p);
    }

    u.c4.p00 = s3;
    u.c4.p04 = &D_01B008B8;
    u.c4.p08 = s2;
    u.c4.p0C = s6;
    func_1B04AA8(&u.c4);

    u.c8.p00 = s3;
    u.c8.p04 = s7;
    u.c8.p08 = fp;
    u.c8.w0C = 0xF0000;
    u.c8.w10 = 0xBB800;
    u.c8.w14 = 1;
    u.c8.w18 = 0;
    u.c8.w1C = 1;
    func_1B048E0(&u.c8);

    c1.p00 = s3;
    func_1B04A90(&c1);

    s0->w18 = 0;
}
