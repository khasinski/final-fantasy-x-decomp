#include "common.h"
#include "vu0.h"

#define VEC_COPY(dst, src) do { MMI_COPY_LQ_A3((dst), (src)); MMI_COPY_SQ_A3((dst)); } while (0)

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
} Eff260;

typedef struct {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
} Sub48C;

typedef struct {
    u8 pad00[0x04];
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x08];
    s32 w24;
    u8 pad28[0x04];
    u16 h2C;
} Sub4D8;

typedef struct {
    u8 pad00[0xF0];
    u8 bF0;
    u8 bF1;
    u8 bF2;
    u8 bF3;
    u8 padF4[0x04];
    s32 wF8;
    float fFC;
    s32 w100;
    u8 pad104[0x0C];
    s32 w110;
    u8 pad114[0x08];
    s32 w11C;
    s32 w120;
    s16 h124;
} Sub5C0;

typedef struct {
    u8 pad00[0x260];
    Eff260 eff260;
    u8 pad340[0x80];
    Vec4 v3C0;
    u8 pad3D0[0x50];
    Vec4 v420;
    u8 pad430[0x10];
    Vec4 v440;
    Vec4 v450;
    u8 pad460[0x2C];
    Sub48C sub48C;
    u8 pad49C[0x3C];
    Sub4D8 sub4D8;
    u8 pad508[0x08];
    u8 sub510[0x40];
    u8 sub550[0x70];
    Sub5C0 sub5C0;
    u8 pad6E8[0x58];
    float f740;
} Work09640;

extern u8 D_01B087F8[];
extern Work09640 *D_01B08940;

extern void Sg_SetFocus(int, int);
extern void func_01B040E8(void *, void *, int, float, int, int, int);
extern void func_01B07798(void *, int, int);
extern void func_01B078A0(void *, int);
extern void func_01B07B80(void *, int, int, float, float);
extern void func_01B08350(void *, int);

void ovl_09640_11f8(void)
{
    Work09640 *s0 = D_01B08940;

    Sg_SetFocus(0, 0x10000);
    Sg_SetFocus(1, 0x20000);
    func_01B07B80(s0->sub510, 20, 0, 1.0f, 0.5f);
}

void ovl_09640_1250(void)
{
    Work09640 *s1 = D_01B08940;
    Eff260 *s2 = &s1->eff260;
    register Sub48C *a48c __asm__("$2");
    Sub4D8 *s0;
    Sub5C0 *v0;
    float y;
    register s32 n50 __asm__("$6");

    func_01B040E8(D_01B087F8, s2, 2, 0.3f, 21, 0, 0);
    VEC_COPY(&s1->eff260.vD0, &s1->v450);
    {
        register float f0 __asm__("$f0") = s2->vD0.y;
        register float f2 __asm__("$f2");
        register s32 n40 __asm__("$3");
        register float f3 __asm__("$f3");
        register float f9 __asm__("$f1");
        a48c = &s1->sub48C;
        __asm__ volatile("");
        f2 = 2.0f;
        n40 = 40;
        f3 = s1->f740;
        n50 = 50;
        __asm__("" : "+f"(f0), "+r"(a48c), "+f"(f2));
        __asm__("" : "+r"(n40), "+f"(f3), "+r"(n50));
        f0 = f0 - f2;
        __asm__ volatile("");
        f9 = 9.0f;
        __asm__ volatile("" : "+f"(f9));
        s0 = &s1->sub4D8;
        *(volatile float *)&s2->fC4 = f3;
        *(s32 volatile *)&s1->sub48C.w00 = 0;
        *(volatile float *)&s2->vD0.y = f0;
        *(s32 volatile *)&a48c->w04 = n40;
        y = s1->v450.y;
        *(s32 volatile *)&a48c->w0C = n50;
        *(volatile float *)&s1->v440.y = y;
        *(s32 volatile *)&a48c->w08 = 0;
        s1->v420.y = y - f9;
        s1->v3C0.y = y - f9;
        func_01B07798(a48c, 1, n50);
    }
    func_01B078A0(s0, 25);
    s0->h2C |= 3;
    s0->w24 = 22;
    s0->f04 = 1.0f;
    s0->f08 = 1.0f;
    s0->f10 = 4.0f;
    s0->f18 = 0.0f;
    s0->f14 = 4.0f;
    s0->f0C = 0.0f;
    v0 = &s1->sub5C0;
    v0->bF0 = 128;
    v0->bF1 = 128;
    v0->bF2 = 128;
    v0->bF3 = 64;
    v0->h124 = 2;
    v0->w11C = -1;
    v0->w120 = 92;
    v0->w110 = 118;
    v0->fFC = 0.05f;
    v0->wF8 = 0;
    v0->w100 = 0;
    func_01B08350(v0, 48);
    func_01B07B80(s1->sub550, 16, 180, 0.5f, 1.0f);
}

void ovl_09640_13f0(void)
{
    Work09640 *v1 = D_01B08940;
    float y = v1->v450.y;

    v1->v420.y = y;
    v1->v3C0.y = y;
}
