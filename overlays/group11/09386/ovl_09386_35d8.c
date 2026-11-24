#include "common.h"

typedef struct {
    void *p00;
    void *p04;
} Task09386;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0x10];
    int timer;
    u8 pad30[0x50];
    u8 s80[0x20];
    float fA0;
    float fA4;
    float fA8;
    float fAC;
    u8 sB0[0x150];
    u8 s200[0x100];
} St09386;

typedef struct {
    u8 pad00[0x58];
    void *p58;
} Obj07A0;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} Args24;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    u8 b0C;
} Args0D;

typedef struct {
    void *p00;
    float f04;
    float f08;
    float f0C;
    int w10;
} ArgsColor;

extern void *D_01B00370;
extern void *D_01B00378;
extern u8 D_01B00500[];
extern u8 D_01B00530[];
extern u8 D_01B00758[];
extern u8 D_01B00778[];
extern Obj07A0 D_01B007A0;
extern u8 D_01B00840[];
extern u8 D_01B02C60[];
extern u8 D_01B0DB50[];
extern void *D_01B0DB7C;

extern void func_01B04A08(void *);
extern void func_01B05178(void *);
extern void func_01B05218(void *);
extern void func_01B05320(void *);
extern void func_01B07F18(void *);
extern void func_01B083E8(void *);
extern void func_01B09650(void *);
extern void func_01B0AF08(void *);
extern void func_01B0AF40(void *);
extern void func_01B0B7B0(void *);
extern void func_01B0C808(void *);

void func_01B035D8(Task09386 *a0) {
    union {
        Args24 a24;
        Args0D a0d;
        ArgsColor ac;
        struct {
            u8 pad[0x10];
            Args24 a10;
        } s10;
    } args;
    void *arg30;
    void *arg34;
    void *arg38;
    St09386 *st = (St09386 *)a0->p04;

again:
    switch (st->state) {
    case 0: {
        void *p840 = D_01B00840;
        args.a0d.p00 = &D_01B007A0;
        args.a0d.p04 = D_01B00758;
        args.a0d.p08 = D_01B00378;
        args.a0d.b0C = 0;
        func_01B05178(&args);

        args.a24.p00 = p840;
        args.a24.p04 = D_01B00758;
        args.a24.p08 = D_01B007A0.p58;
        args.a24.p0C = (void *)1;
        func_01B083E8(&args);
        st->state = 10;
    }
    case 10: {
        Args24 *a10;
        args.a24.p00 = st->s80;
        args.a24.p04 = D_01B00758;
        func_01B07F18(&args);

        {
            /* DEBT(FAKE): pin f0/f1/v0/v1/a0 for 9650 message at 16(sp) */
            /* DEBT(ORDER): volatile stores and empty asm barriers preserve 9650 sw/swc1 schedule */
            register float f0 __asm__("$f0") = 1.0f;
            register float f1 __asm__("$f1") = 0.2f;
            register Args24 *v1 __asm__("$3");
            register Args24 *a0r __asm__("$4");
            register void *p500 __asm__("$2");
            __asm__("" : "+f"(f1) : "f"(f0));
            v1 = &args.s10.a10;
            args.s10.a10.p00 = st->sB0;
            p500 = D_01B00500;
            __asm__("" : "+f"(f0) : "r"(p500));
            *(void * volatile *)&v1->p0C = D_01B00840;
            *(volatile float *)&st->fA8 = f0;
            *(volatile float *)&st->fAC = f1;
            __asm__("" : "+r"(v1) : "m"(st->fAC));
            a0r = v1;
            __asm__("" : "+r"(p500) : "r"(a0r));
            v1->p10 = p500;
            args.s10.a10.p14 = st->s80;
            st->fA4 = f0;
            st->fA0 = f0;
            v1->p04 = D_01B00758;
            v1->p08 = D_01B00530;
            a10 = a0r;
        }
        func_01B09650(a10);

        args.a24.p00 = st->s200;
        args.a24.p04 = D_01B00778;
        args.a24.p08 = st->sB0;
        args.a24.p0C = D_01B0DB7C;
        args.a24.p10 = D_01B0DB50;
        args.a24.p14 = 0;
        func_01B0B7B0(&args);

        args.a24.p00 = D_01B02C60;
        args.a24.p04 = D_01B00758;
        args.a24.p08 = D_01B00530;
        args.a24.p0C = D_01B00840;
        args.a24.p10 = D_01B00370;
        args.a24.p14 = 0;
        func_01B0AF40(&args);

        args.a24.p00 = D_01B02C60;
        args.a24.p04 = 0;
        func_01B0AF08(&args);
        st->state = 30;
        goto again;
    }
    case 30:
        args.ac.p00 = &D_01B007A0;
        args.ac.f04 = 1.0f;
        args.ac.f08 = 0.4f;
        args.ac.f0C = 0.4f;
        args.ac.w10 = 15;
        func_01B04A08(&args);
        st->timer = 0;
        st->state++;
        break;
    case 31:
        if (st->timer >= 15) {
            args.ac.p00 = &D_01B007A0;
            args.ac.f04 = 1.0f;
            args.ac.f08 = 1.0f;
            args.ac.f0C = 0.4f;
            args.ac.w10 = 15;
            func_01B04A08(&args);
            st->timer = 0;
            st->state++;
        }
        break;
    case 32:
        if (st->timer >= 15) {
            args.ac.p00 = &D_01B007A0;
            args.ac.f04 = 0.4f;
            args.ac.f08 = 1.0f;
            args.ac.f0C = 0.4f;
            args.ac.w10 = 15;
            func_01B04A08(&args);
            st->timer = 0;
            st->state++;
        }
        break;
    case 33:
        if (st->timer >= 15) {
            args.ac.p00 = &D_01B007A0;
            args.ac.f04 = 0.4f;
            args.ac.f08 = 1.0f;
            args.ac.f0C = 1.0f;
            args.ac.w10 = 15;
            func_01B04A08(&args);
            st->timer = 0;
            st->state++;
        }
        break;
    case 34:
        if (st->timer >= 15) {
            args.ac.p00 = &D_01B007A0;
            args.ac.f04 = 0.4f;
            args.ac.f08 = 0.4f;
            args.ac.f0C = 1.0f;
            args.ac.w10 = 15;
            func_01B04A08(&args);
            st->timer = 0;
            st->state++;
        }
        break;
    case 35:
        if (st->timer >= 15) {
            args.ac.p00 = &D_01B007A0;
            args.ac.f04 = 1.0f;
            args.ac.f08 = 0.4f;
            args.ac.f0C = 1.0f;
            args.ac.w10 = 15;
            func_01B04A08(&args);
            st->timer = 0;
            st->state++;
        }
        break;
    case 36:
        if (st->timer >= 15) {
            args.ac.p00 = &D_01B007A0;
            args.ac.f04 = 1.0f;
            args.ac.f08 = 1.0f;
            args.ac.f0C = 1.0f;
            args.ac.w10 = 15;
            func_01B04A08(&args);
            st->state = 10000;
        }
        break;
    case 60:
        if (st->timer >= 0) {
            st->state = 61;
            st->timer = 0;
        }
        break;
    case 61:
        if (st->timer >= 200) {
            st->state = 10000;
        }
        break;
    case 10000:
        arg30 = &D_01B007A0;
        func_01B05320(&arg30);
        arg34 = &D_01B007A0;
        func_01B05218(&arg34);
        arg38 = a0->p00;
        func_01B0C808(&arg38);
        break;
    }

    st->timer++;
}
