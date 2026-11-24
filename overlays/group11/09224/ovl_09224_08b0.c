#include "common.h"
#include "vu0.h"

#define LQ_A3(src) __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory")
#define SQ_A3(dst) __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory")

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} Ctx6078;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    Vec4 vecD0;
    u8 padE0[0x30];
    void *p110;
} Obj60C0;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    u32 w20;
    float f24;
    u8 pad28[0x8];
    u8 sub30[0x213];
    u8 b243;
    u8 pad244[0x8];
    float f24C;
    float f250;
    u8 pad254[0x4];
    s32 w258;
    u8 pad25C[0x4];
    Vec4 pos260;
    u8 pad270[0x10];
    void *cb280;
    void *cb284;
    u8 pad288[0x4];
    float f28C;
    s32 w290;
    s32 w294;
    u16 h298;
} Work5D50;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Node3820;

extern u8 D_01B82540[];
extern u8 *D_01B06320;
extern u8 *D_01B06324;
extern u8 *D_01B06070;
extern u8 D_01B0B910[];
extern Ctx6078 D_01B06078;
extern u8 D_01B00040[];
extern Obj60C0 D_01B060C0;
extern u8 D_01B05FF0[];
extern u8 D_01B003D8[];
extern Work5D50 D_01B05D50;
extern u8 D_01B00C48[];
extern u8 D_01B00DA0[];
extern s32 D_01B06074;
extern u8 D_01B05D28[];
extern u8 D_01B00418[];
extern u8 D_01B00B88[];
extern u8 D_01B00BB8[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_01B03AA8(void *, void *, void *, s32);
extern void func_01B03B80(void *, void *, s32, s32, s32, s32, float);
extern void func_01B01260(s32, void *, s32);
extern float func_01B01138(s32);
extern void func_01B03308(void *, void *, void *);
extern void func_01B048B0(void *, void *, void *);
extern void func_01B049B8(void *, void *, void *);
extern void **func_01B04110(void *, s32);
extern void func_01B04F48(void *, void *);
extern void func_01B05128(void *, void *, void *);
extern void func_01B05A10(void *, float);
extern void func_01B02C48(s32, void *, void *);
extern Node3820 *func_01B03820(void *);
extern void func_01B039E8(void *);
extern void func_01B055B8(void *, s32);

s32 ovl_09224_08b0(void)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    u8 *s6 = D_01B82540;
    u8 *s2;
    Ctx6078 *s4;
    Obj60C0 *s0;
    Work5D50 *w;
    void *tex;
    Node3820 *n;

    D_01B06324 = s6 + 0x40000;
    D_01B06070 = s6 + 0x140000;
    D_01B06320 = s6;
    s2 = D_01B0B910;
    s4 = &D_01B06078;
    s4->w2C = func_002B49A0(s2, 8, 0);
    func_01B03AA8(s4, D_01B00040, D_01B06320, 0x40000);

    s0 = &D_01B060C0;
    func_01B03B80(s4, s0, 0, 24, 0, 0, 0.03f);
    func_01B01260(-1, &s0->vecD0, 0);
    s0->fC4 = func_01B01138(-1);
    s0->vecD0.y -= 8.0f;
    func_01B03308(D_01B05FF0, s2, D_01B003D8);
    s0->p110 = D_01B05FF0;

    func_01B01260(0, &v10, 1);
    func_01B048B0(&v00, &s0->vecD0, &v10);
    v00.x = 0.0f;
    v20.x = -0.5f;
    v20.y = 0.0f;
    v20.z = -10.5f;
    func_01B049B8(&v00, &s0->vecD0, &v20);

    w = &D_01B05D50;
    {
        register Vec4 *pos __asm__("$21") = &w->pos;
        MMI_COPY_LQ_A3(pos, &s0->vecD0);
        MMI_COPY_SQ_A3(pos);
        MMI_COPY_LQ_A3(&w->pos260, &v10);
        MMI_COPY_SQ_A3(&w->pos260);
        w->h298 = 1;
        w->cb280 = D_01B00C48;
        w->cb284 = D_01B00DA0;
        w->w290 = 28;
        w->w294 = 0;
        tex = *func_01B04110(s4, 0);
        func_01B04F48(w, tex);
        w->h298 = 1;
        w->w20 = 0x80808080;
        w->f24 = 0.05f;
        w->f28C = 0.05f;
        func_01B05128(w->sub30, tex, pos);
    }
    w->w258 = 64;
    w->f250 = 0.8f;
    w->b243 = 96;
    w->f24C = 0.1f;
    func_01B05A10(w, 8.0f);

    D_01B06074 = 0;
    func_01B02C48(-1, D_01B05D28, D_01B00418);
    n = func_01B03820(D_01B00B88);
    n->b18 = 1;
    func_01B039E8(n);
    func_01B055B8(s6 + 0x160000, 128);
    n = func_01B03820(D_01B00BB8);
    n->b18 = 2;
    func_01B039E8(n);
    return 0;
}
