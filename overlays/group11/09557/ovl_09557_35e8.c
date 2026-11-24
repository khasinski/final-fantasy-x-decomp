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
} Ovl09557Work;

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

extern u8 D_01B00800[];
extern u8 D_01B00A10[];
extern u8 D_01B00A28[];
extern void func_01B034A0(void);

extern void func_01B0F148(void *);
extern void func_01B0F550(void *);
extern void func_01B096A0(void *);
extern void func_01B05970(void *);
extern void func_01B0B380(void *);
extern void func_01B05BD8(void *);
extern void func_01B05388(void *);
extern void func_01B0C038(void *);

void func_01B035E8(Ovl09557Work *a0, void *a1, void *a2) {
    struct {
        void *p00;
        void *p04;
        float f08;
        float f0C;
    } a00;
    Args20 a10;

    {
        void **p = (void **)&a00;
        p[0] = a0;
        p[1] = func_01B034A0;
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
    {
        void **p = (void **)&a00;
        p[0] = a1;
        p[1] = &a0->f190;
        func_01B05970(p);
    }
    a0->f19C = 1.0f;

    {
        void **p = (void **)&a00;
        p[0] = a0->f1D0;
        p[1] = D_01B00A28;
        func_01B0B380(p);
    }
    {
        void **p = (void **)&a00;
        p[0] = a2;
        p[1] = &a0->w1F0;
        func_01B05BD8(p);
    }
    {
        void **p = (void **)&a00;
        p[0] = a0->f1A0;
        p[1] = D_01B00A28;
        func_01B096A0(p);
    }
    a00.p00 = a1;
    a00.p04 = &a0->f1C0;
    a00.f08 = 10.0f;
    a00.f0C = 20.0f;
    func_01B05388(&a00);

    a0->f1CC *= 0.25f;

    {
        Args20 *p = &a10;
        a10.p00 = a0->f20;
        p->p04 = D_01B00A28;
        p->p08 = D_01B00800;
        a10.p0C = a0->f170;
        a10.p10 = a0->f1D0;
        a10.p14 = a0->f1A0;
        func_01B0C038(p);
    }
    a0->state18 = 0;
}
