#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S27A0Item {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    float vD0[4];
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x18];
    s32 s120;
    u8 pad124[0xC];
} S27A0Item; /* size 0x130 */

typedef struct S27A0Beam {
    u8 pad00[0xD0];
    float vD0[4];
    u8 padE0[0x50];
    float v130[4];
    float v140[4];
    float v150[4];
    float v160[4];
    float v170[4];
    float f180;
    float f184;
    s32 s188;
    u8 pad18C[4];
} S27A0Beam; /* size 0x190 */

typedef struct S27A0Part {
    float v00[4];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 s30[0xC];
    float f3C;
    s32 s40;
    u8 pad44[8];
    s32 s4C;
    s32 s50;
    u8 pad54[4];
    s32 s58;
    s32 s5C;
    s32 s60;
} S27A0Part;

typedef struct S27A0Sub2280 {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    s32 s88;
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
    u8 pad9A[0xA6];
} S27A0Sub2280; /* size 0x140 -> 0x2280..0x23C0 */

typedef struct S27A0Anim {
    s32 s00;
    s32 s04;
    s32 s08;
    s32 s0C;
} S27A0Anim; /* size 0x10 */

typedef struct S27A0Sub2414 {
    u8 pad00[4];
    float f04;
    float f08;
    s32 s0C;
    float f10;
    float f14;
    s32 s18;
    u8 pad1C[0x10];
    u16 u2C;
    u8 pad2E[2];
} S27A0Sub2414; /* size 0x30 */

typedef struct S27A0Global {
    S27A0Item items[10]; /* 0x0000..0x0BE0 */
    u8 padBE0[0x60];
    float vC40[4];       /* 0x0C40 */
    float vC50[4];       /* 0x0C50 */
    u8 padC60[0x80];
    S27A0Beam beams[2];  /* 0x0CE0..0x1000 */
    u8 pad1000[0x1280];
    S27A0Sub2280 s2280;  /* 0x2280..0x23C0 */
    S27A0Anim s23C0;     /* 0x23C0..0x23D0 */
    u8 pad23D0[0xC];
    S27A0Anim s23DC;     /* 0x23DC..0x23EC */
    u8 pad23EC[0x28];
    S27A0Sub2414 s2414;  /* 0x2414..0x2444 */
    u8 pad2444[0x4F4];
    float f2938;         /* 0x2938 */
} S27A0Global;

extern S27A0Global *D_01B0E828;
extern u8 D_01B0D6B8[];
extern S27A0Item D_01B0DE20[];
extern void D_01B02788(void);

extern void func_01B08B18(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, float f0);
extern float func_01B09638(float a0, float a1, float a2, float a3, float a4);
extern void func_01B08F88(void *a0, void *a1);
extern S27A0Part *func_01B0CD08(void);
extern void **func_01B090A8(void *a0, s32 a1);
extern void func_01B09EE0(void *a0, void *a1);
extern float func_002B3DB0(float a0);
extern void func_01B08838(void *a0);
extern void func_01B09848(float *a0);
extern void func_002DD128(float (*m)[4]);
extern void func_002DD270(float (*m)[4], float (*m2)[4], float a0);
extern void func_002DD318(float (*m)[4], float (*m2)[4], float a0);
extern void func_002DCE08(float *dst, float (*m)[4], float *src);
extern void func_01B06698(s32 a0, s32 a1, s32 a2, float *a3);
extern void *func_01B087B8(void (*fn)(void *));
extern void func_01B08980(void *a0);
extern void func_01B0C650(S27A0Anim *a0, s32 a1);
extern void func_01B0C4E0(S27A0Sub2280 *a0, s32 a1, s32 a2);
extern void func_01B0C758(S27A0Sub2414 *a0, s32 a1);

void func_01B027A0(void)
{
    S27A0Global *g = D_01B0E828;
    S27A0Item *it = &g->items[8];

    func_01B08B18(D_01B0D6B8, it, 11, 0, 0, 0, 0.05f);
    it->s120 = 0x11;
    it->p104 = D_01B02788;

    it = &g->items[9];
    func_01B08B18(D_01B0D6B8, it, 11, 0, 0, 0, 0.05f);
    {
        register s32 v __asm__("$3") = 0x37;
        it->p104 = D_01B02788;
        it->s120 = v;
    }
}

void func_01B02860(void *a0)
{
    float v00[4];
    S27A0Beam *beam = D_01B0E828->beams;
    s32 done = 0;
    s32 i;

    for (i = 0; i < 2; i++, beam++) {
        s32 j;
        beam->f180 += beam->f184;
        if (beam->f180 > 1.0f) {
            beam->f180 = 1.0f;
        }
        v00[0] = func_01B09638(beam->v130[0], beam->v140[0], beam->v150[0], beam->v160[0], beam->f180);
        v00[1] = func_01B09638(beam->v130[1], beam->v140[1], beam->v150[1], beam->v160[1], beam->f180);
        v00[2] = func_01B09638(beam->v130[2], beam->v140[2], beam->v150[2], beam->v160[2], beam->f180);
        v00[3] = 1.0f;
        COPY_VEC(beam->vD0, v00);
        if (beam->s188 == 0) {
            func_01B08F88(D_01B0D6B8, beam);
            done = 1;
        } else {
            beam->s188--;
        }

        for (j = 0; j < 4; j++) {
            S27A0Part *p = func_01B0CD08();
            if (p == 0) {
                break;
            }
            func_01B09EE0(p->s30, *func_01B090A8(D_01B0D6B8, 0));
            COPY_VEC(p->v00, v00);
            p->v00[0] += func_002B3DB0(8.0f);
            p->v00[1] += func_002B3DB0(8.0f);
            p->v00[2] += func_002B3DB0(8.0f);
            p->f10 = func_002B3DB0(1.0f);
            p->f14 = func_002B3DB0(1.0f);
            p->f18 = func_002B3DB0(1.0f);
            p->f1C = func_002B3DB0(3.1415927f);
            p->f20 = 0.0f;
            p->f24 = -0.1f;
            p->f28 = 0.0f;
            p->f2C = 1.0f;
            p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.08f;
            p->s40 = 0;
            p->s58 = 0x10;
            p->s5C = 0;
            p->s4C = 0x10;
            p->s50 = 0;
            p->s60 = 0;
        }
    }

    if (done == 1) {
        func_01B08838(a0);
    }
}
