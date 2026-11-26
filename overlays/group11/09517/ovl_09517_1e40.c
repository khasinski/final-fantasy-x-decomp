#include "common.h"

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
} Sub130_9517;

typedef struct {
    u8 pad000[0xC4];
    float fC4;
    u8 pad0C8[0x8];
    float fD0;
    u8 pad0D4[0x14];
    float fE8;
    u8 pad0EC[0x44];
    Sub130_9517 sub130;
    u8 pad1CC[0x144];
    u8 sub310[0x80];
    u8 sub390[0x10];
} Obj9517_2;

extern u8 D_01B086E8[];
extern Obj9517_2 *D_01B087B0;
extern void func_01B01920(void);

extern void func_01B04D10(void *, void *, int, int, int, int, float);
extern void func_01B023F0(int, void *, int);
extern float func_01B022C8(int);
extern void func_01B08368(void *, int, float *, int);
extern void func_01B08338(void *, int, float *, int);
extern void func_01B07EC8(void *, int, int, float, float);
extern void *func_01B049B0(void *);
extern void func_01B04B78(void *);
extern void func_01B07D10(void *, int);
extern void func_00117E08(int);
extern void func_01B03750(int, int);
extern void func_01B051E0(void *);

static inline void set_vec3(float *v, float x, float y, float z)
{
    v[2] = z;
    v[1] = y;
    v[0] = x;
}

static inline void set_vec2(float *v, float x, float y)
{
    v[1] = y;
    v[0] = x;
}

void func_01B01E40(void)
{
    float v3[4];
    float v2[2];
    float zero;
    Obj9517_2 *s1 = D_01B087B0;
    void *s0 = s1->sub390;

    func_01B04D10(D_01B086E8, s1, 0, 0, 0, 0, 0.15f);
    zero = 0.0f;
    __asm__ volatile("" : "+f"(zero));
    func_01B023F0(-1, &s1->fD0, 0);
    s1->fC4 = func_01B022C8(-1);
    s1->fE8 = -50.0f;

    v3[2] = zero;
    v3[1] = zero;
    v3[0] = zero;
    func_01B08368(s0, 3, v3, 30);

    v2[1] = zero;
    v2[0] = 2.268928050994873f;
    func_01B08338(s0, 2, v2, 100);

    v3[0] = zero;
    v3[1] = zero;
    v3[2] = zero;
    func_01B08368(s0, 0, v3, 100);
    func_01B08368(s0, 1, v3, 100);

    v3[0] = 1.3f;
    v3[1] = 1.3f;
    v3[2] = 1.3f;
    func_01B08368(s0, 2, v3, 100);

    func_01B07EC8(s1->sub310, 60, 0, 1.0f, 0.5f);
    func_01B04B78(func_01B049B0(func_01B01920));
}

void func_01B01FB0(void)
{
    Sub130_9517 *v0 = &D_01B087B0->sub130;

    v0->b82 = 0xFF;
    v0->b81 = 0xFF;
    v0->b80 = 0xFF;
    v0->b83 = 0x80;
    v0->b84 = 0xFF;
    v0->b85 = 0xFF;
    v0->b86 = 0xFF;
    v0->b87 = 0;
    v0->w88 = 0;
    v0->b98 = 0x48;
    v0->b99 = 0;
    func_01B07D10(v0, 0x14);
}

void func_01B02000(void)
{
    func_00117E08(100);
}

void func_01B02008(void)
{
    func_01B03750(-5, 0);
    func_01B051E0(D_01B086E8);
}
