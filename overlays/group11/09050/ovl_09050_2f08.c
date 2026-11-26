#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    float f1C;
    float f20;
    int w24;
    int w28;
} State2F08;

typedef struct {
    void *p00;
    State2F08 *p04;
} Task2F08;

typedef struct {
    u8 raw[0xA0];
} ElemA0;

typedef struct {
    u8 pad00[0x34];
    float f34;
    u8 pad38[0x0C];
    u8 b44;
    u8 pad45[0x0B];
} Elem50;

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x0C];
    float f2C;
} Elem30;

typedef struct {
    u8 pad00[0x14C];
    u8 b14C;
    u8 pad14D[0x03];
} Elem150;

typedef struct {
    u8 pad00[0x100];
} Elem100;

typedef struct {
    u8 pad00[0x38];
} Elem38;

typedef struct {
    ElemA0 items[8];
    u8 pad500[0x20];
    int count;
} Table980;

typedef union {
    struct {
        void *p0;
        void *p4;
        void *p8;
        void *pC;
        u8 b10;
    } a5;
    struct {
        void *p0;
        void *p4;
        float f8;
        float fC;
    } a4f;
    struct {
        void *p0;
        void *p4;
        void *p8;
        void *pC;
        void *p10;
        void *p14;
    } a6;
    struct {
        void *p0;
        void *p4;
        void *p8;
        void *pC;
        void *p10;
        int w14;
    } a6i;
} Arg2F08;

extern void *D_01B00550;
extern void *D_01B00554;
extern u8 D_01B00680[];
extern u8 D_01B00710[];
extern u8 D_01B00938[];
extern u8 D_01B00958[];
extern Table980 D_01B00980;
extern Elem30 D_01B00EC0[];
extern Elem30 D_01B01040[];
extern Elem50 D_01B011C0[];
extern Elem150 D_01B01440[];
extern Elem100 D_01B01EC0[];
extern Elem38 D_01B026C0[];
extern u8 D_01B0DA60[];
extern void *D_01B0DA8C;

extern void func_01B03618(void *);
extern void func_01B07E38(void *);
extern void func_01B088A8(void *);
extern void func_01B04B58(void *);
extern void func_01B07968(void *);
extern void func_01B04308(void *);
extern void func_01B09560(void *);
extern void func_01B0B6C0(void *);
extern void func_01B0AE50(void *);
extern void func_01B0AE18(void *);
extern void func_01B0C718(void *);

void ovl_09050_2f08(Task2F08 *a0)
{
    Arg2F08 arg;
    void *p20;
    State2F08 *st = a0->p04;

    st->f1C += 1.0f / 30.0f;
    st->f20 += 1.0f / 30.0f;
    st->w28++;

    switch (st->state) {
    case 0:
        arg.a5.p0 = &D_01B00980;
        arg.a5.p4 = D_01B00938;
        arg.a5.p8 = D_01B00554;
        arg.a5.pC = 0;
        arg.a5.b10 = 0;
        func_01B03618(&arg);
        st->state = 10;
    case 10:
        st->w28 = 100;
        st->state++;
        st->w24 = 0;
    case 11:
        if (st->w28 >= 16) {
            int idx = st->w24;
            u8 *tbl = (u8 *)&D_01B00980;
            Elem50 *e50 = &D_01B011C0[idx];
            u8 *item = tbl + idx * 0xA0;
            Elem150 *e150 = &D_01B01440[idx];
            Elem30 *e30a = &D_01B00EC0[idx];
            Elem30 *e30b = &D_01B01040[idx];
            u8 *b100 = (u8 *)D_01B01EC0;
            u8 *e100 = b100 + (idx << 8);

            arg.a6.p0 = e50;
            arg.a6.p4 = D_01B00938;
            arg.a6.p8 = item + 0x20;
            func_01B07E38(&arg);

            e50->b44 = 3;
            e50->f34 = -5.0f;

            arg.a6.p0 = e30b;
            arg.a6.p4 = D_01B00938;
            func_01B088A8(&arg);

            arg.a6.p0 = (tbl + st->w24 * 0xA0) + 0x20;
            arg.a6.p4 = e30b->sub20;
            func_01B04B58(&arg);

            arg.a6.p0 = e30a;
            arg.a6.p4 = D_01B00938;
            func_01B07968(&arg);

            arg.a4f.p0 = (tbl + st->w24 * 0xA0) + 0x20;
            arg.a4f.p4 = e30a->sub20;
            arg.a4f.f8 = 1.0f;
            arg.a4f.fC = 18.0f;
            func_01B04308(&arg);

            e30a->f2C *= 0.008f;

            arg.a6.p0 = e150;
            arg.a6.p4 = D_01B00938;
            arg.a6.p8 = D_01B00710;
            arg.a6.pC = e50;
            arg.a6.p10 = e30b;
            arg.a6.p14 = e30a;
            func_01B09560(&arg);

            e150->b14C = 1;

            arg.a6i.p0 = e100;
            arg.a6i.p4 = D_01B00958;
            arg.a6i.p8 = e150;
            arg.a6i.pC = D_01B0DA8C;
            arg.a6i.p10 = D_01B0DA60;
            arg.a6i.w14 = 0;
            func_01B0B6C0(&arg);

            arg.a6i.p0 = &D_01B026C0[st->w24];
            arg.a6i.p4 = D_01B00938;
            arg.a6i.p8 = e150;
            arg.a6i.pC = D_01B00680;
            arg.a6i.p10 = D_01B00550;
            arg.a6i.w14 = 0;
            func_01B0AE50(&arg);

            arg.a6i.p0 = &D_01B026C0[st->w24];
            arg.a6i.p4 = 0;
            func_01B0AE18(&arg);

            st->w24++;
            if (st->w24 >= D_01B00980.count) {
                st->state = 10000;
            }
            st->w28 = 0;
        }
        break;
    case 10000:
        p20 = a0->p00;
        func_01B0C718(&p20);
        break;
    }

    st->w28++;
}
