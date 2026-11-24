#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state18;
    s32 timer1C;
    u8 f20[0x150];
    u8 f170[0x20];
    float f190;
    float f194;
    float f198;
    float f19C;
    u8 f1A0[0x20];
    float f1C0;
    float f1C4;
    float f1C8;
    float f1CC;
    u8 f1D0[0x20];
    s32 w1F0;
    s32 w1F4;
    s32 w1F8;
    s32 w1FC;
    u8 f200[0xE8];
} Ovl09557Work;

typedef struct {
    u8 pad00[0x20];
    s32 w20;
    s32 w24;
    s32 w28;
} Ovl09557Src;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
    void *p18;
    void *p1C;
} Args20;

typedef struct {
    void *p00;
    u8 b04;
    u8 b05;
    u8 pad06[2];
    void *p08;
    void *p0C;
} ArgsB;

extern u8 D_01B00800[];
extern u8 D_01B00A10[];
extern u8 D_01B00A24;
extern u8 D_01B00A28[];
extern u8 D_01B00A48[];
extern u8 D_01B10530[];
extern s32 D_01B1055C;
extern void func_01B03250(void);

extern void func_01B0F148(void *);
extern void func_01B0F550(void *);
extern void func_01B096A0(void *);
extern void func_01B09718(void *);
extern void func_002DD0B0(void *, void *);
extern void func_01B0B380(void *);
extern void func_01B0B408(void *);
extern void func_01B0C038(void *);
extern void func_01B0E198(void *);

void func_01B032C8(Ovl09557Work *a0, Ovl09557Src *a1, Ovl09557Src *a2) {
    ArgsB a00;
    Args20 a10;

    {
        void **p = (void **)&a00;
        p[0] = a0;
        p[1] = func_01B03250;
        p[2] = a0;
        func_01B0F148(p);
    }
    {
        void **p = (void **)&a00;
        p[0] = D_01B00A10;
        p[1] = a0;
        func_01B0F550(p);
    }
    {
        void **p = (void **)&a00;
        p[0] = a0->f170;
        p[1] = D_01B00A28;
        func_01B096A0(p);
    }
    a00.p00 = a1;
    a00.b05 = D_01B00A24;
    func_01B09718(&a00);

    func_002DD0B0(&a0->f190, &a1->w20);
    a0->f194 -= 0.02f;

    {
        void **p = (void **)&a00;
        p[0] = a0->f1D0;
        p[1] = D_01B00A28;
        func_01B0B380(p);
    }
    a00.p00 = a2;
    a00.b05 = D_01B00A24;
    func_01B0B408(&a00);

    a0->w1F0 = a2->w20;
    a0->w1F4 = a2->w24;
    a0->w1F8 = a2->w28;

    {
        void **p = (void **)&a00;
        p[0] = a0->f1A0;
        p[1] = D_01B00A28;
        func_01B096A0(p);
    }
    a0->f1C0 = 1.0f;
    a0->f1C4 = 1.0f;
    a0->f1C8 = 1.0f;
    *(volatile float *)&a0->f1CC = 1.0f;

    {
        Args20 *p = &a10;
        a10.p00 = a0->f20;
        *(volatile void **)&p->p04 = D_01B00A28;
        p->p08 = D_01B00800;
        a10.p0C = a0->f170;
        a10.p10 = a0->f1D0;
        a10.p14 = a0->f1A0;
        func_01B0C038(p);
    }
    {
        Args20 *p = (Args20 *)&a00;
        p->p00 = a0->f200;
        p->p04 = D_01B00A48;
        p->p08 = a0->f20;
        p->p0C = (void *)D_01B1055C;
        p->p10 = D_01B10530;
        p->p14 = (void *)2;
        func_01B0E198(p);
    }
    a0->state18 = 0;
}
