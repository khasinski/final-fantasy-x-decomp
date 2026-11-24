#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0x4];
    s32 w04;
    u8 pad08[0xD];
    u8 b15;
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
    u8 pad1A[0x2A];
    s32 arr44[0x20];
    void *pC4;
    void *pC8;
    void *pCC;
} ObjF98;

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} MgrA0E8;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task;

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
    s32 w88;
    u8 pad8C[0x8];
    s32 w94;
    u8 b98;
    u8 b99;
    u8 pad9A[0x6];
} ObjA;

typedef struct {
    u8 pad00[0x17C0];
    u8 m17C0[0x30];
    float v17F0[4];
    u8 m1800[0x30];
    float v1830[4];
    u8 m1840[0x30];
    float v1870[4];
    u8 m1880[0x30];
    float v18B0[4];
    u8 m18C0[0x30];
    float v18F0[4];
    u8 m1900[0x30];
    float v1930[4];
    float v1940[4];
    float v1950[4];
    float v1960[4];
    float v1970[4];
    float v1980[4];
    float v1990[4];
    float v19A0[4];
    float v19B0[4];
    float v19C0[4];
    float v19D0[4];
    float v19E0[4];
    float v19F0[4];
    float v1A00[4];
    u8 pad1A10[0x60];
    ObjA objA[2];
    u8 b1BB0[0x40];
    u8 pad1BF0[0x680];
    float f2270;
    u8 pad2274[0x18];
    s32 w228C;
} Work9633;

typedef struct {
    u8 pad00[0x30];
    float v30[4];
    u8 pad40[0x106];
    u8 b146;
} MatObj;

extern u8 D_01BEB920[];
extern u8 D_01C501C0[];
extern u8 D_01B00040[];
extern u8 D_01B007D0[];
extern u8 D_01B00C20[];
extern ObjF98 D_01B00F98;
extern u8 *D_01B011A4;
extern s32 D_01B0A0E0;
extern MgrA0E8 D_01B0A0E8;
extern s32 D_01B0A128;
extern u8 *D_01B0A12C;
extern u8 D_01B0A130[];
extern u8 D_01B0A190[];
extern u8 D_01B0A1F0[];
extern s32 D_01B0A204;
extern u8 D_01B0A210[];
extern s32 D_01B0A224;
extern u8 D_01B0A230[];
extern s32 D_01B0A244;
extern u8 D_01B0A250[];
extern s32 D_01B0A264;
extern Work9633 *D_01B0A270;
extern u8 *D_01B0A274;
extern u8 D_01B0F9E0[];

extern void func_002B4980(void *);
extern s32 func_01B03098(s32);
extern s32 func_001B4E58(s32);
extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B05B30(void *, void *, void *, s32);
extern void func_01B09198(void *, void *);
extern void func_01B05118(s32);
extern Task *func_01B058A8(void *);
extern void func_01B05A70(Task *);
extern void func_01B096A8(void *, s32);
extern void func_01B06F90(void);
extern s32 func_01B091B8(void *);
extern void func_01B04D88(void *);
extern void func_01B077B8(void);
extern void func_01B05928(void *);
extern s32 func_01B05CE8(void *, void *);
extern void func_001CDDD8(s32);
extern void func_01B032E8(s32, void *, s32);
extern float func_01B031C0(s32);
extern void func_01B04558(s32, void *);
extern void func_01B04AD8(s32, void *, void *);
extern void func_01B04050(s32, s32);
extern void func_01B03FB0(s32, s32);
extern void func_01B07640(s32);
extern MatObj *func_01B07970(s32);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern s32 func_01B03130(s32);
extern void func_00103208(s32);
extern void func_01B04930(s32);
extern void func_01B05138(s32);
extern void func_01B07780(void);
extern void func_01B04880(s32);
extern void *func_01B048F0(s32);
extern void func_00110648(void *, s32);
extern void func_01B06BB8(void *, float);
extern void func_01B04AA8(s32, float);
extern void func_01B09470(void *, s32, s32, float, float);
extern void func_01B092B8(void *, s32);
extern void func_00173650(void *);

void ovl_09633_1638(void *a0);
void ovl_09633_1760(void);
void ovl_09633_17c8(void);
void ovl_09633_1980(void);
void ovl_09633_19f0(void);

s32 ovl_09633_1498(void)
{
    u8 *p;
    ObjF98 *f98;
    register s32 id __asm__("$16");
    MgrA0E8 *mgr;
    Task *t;

    func_002B4980(D_01BEB920);
    p = D_01C501C0;
    D_01B0A128 = 0;
    D_01B0A12C = p + 0x40000;
    D_01B0A274 = p + 0x140000;
    D_01B0A270 = (Work9633 *)(p + 0x1A0000);

    f98 = &D_01B00F98;
    id = func_01B03098(-1) - 1;
    f98->b15 = id;
    f98->arr44[id] = func_001B4E58(id);
    id--;
    f98->b16 = id;
    f98->arr44[id] = func_001B4E58(id);
    f98->w04 = 3;

    mgr = &D_01B0A0E8;
    mgr->w2C = func_002B49A0(D_01B0F9E0, 8, 0);
    func_01B05B30(mgr, D_01B00040, p, 0x40000);
    ovl_09633_17c8();
    ovl_09633_1980();
    func_01B09198(D_01B0A130, D_01B007D0);
    func_01B09198(D_01B0A190, D_01B00C20);
    func_01B05118(1);

    t = func_01B058A8((void *)ovl_09633_1638);
    t->b18 = 1;
    func_01B05A70(t);

    func_01B096A8(p + 0x180000, 0x400);

    t = func_01B058A8((void *)ovl_09633_1760);
    t->b18 = 2;
    func_01B05A70(t);
    return 0;
}

void ovl_09633_1638(void *a0)
{
    Work9633 *w = D_01B0A270;
    s32 r;

    func_01B06F90();
    D_01B011A4 = D_01B0A274;
    r = func_01B091B8(D_01B0A130);
    func_01B091B8(D_01B0A190);
    if (r == 0) {
        copy_vec(w->v17F0, w->v1950);
        copy_vec(w->v1830, w->v1970);
        copy_vec(w->v1870, w->v1990);
        copy_vec(w->v18B0, w->v19B0);
        copy_vec(w->v18F0, w->v19D0);
        copy_vec(w->v1930, w->v19F0);
        func_01B04D88(D_01B0A1F0);
        func_01B04D88(D_01B0A210);
        func_01B04D88(D_01B0A230);
        func_01B04D88(D_01B0A250);
        func_01B077B8();
    } else {
        w->w228C = 1;
        ovl_09633_19f0();
        func_01B05928(a0);
    }
}

void ovl_09633_1760(void)
{
    Work9633 *w = D_01B0A270;
    if (func_01B05CE8(&D_01B0A0E8, D_01B0A12C) == 1 && w->w228C == 1) {
        func_001CDDD8(D_01B0A0E0);
    }
}

void ovl_09633_17c8(void)
{
    float v00[4];
    float v10[4];
    register Work9633 *w __asm__("$16") = D_01B0A270;
    register float *p10 __asm__("$18");

    func_01B032E8(-1, v00, 0);
    copy_vec(w->v1A00, v00);
    v10[0] = 0.0f;
    *(volatile float *)&v10[1] = func_01B031C0(-1);
    {
        float *dst = w->v1940;
        *(volatile float *)&v10[2] = 0.0f;
        p10 = v10;
        *(volatile float *)&v10[3] = 0.0f;
        copy_vec(dst, p10);
    }
    copy_vec(w->v1950, v00);
    func_01B04558(-1, w->m17C0);
    func_01B04AD8(-1, w->m17C0, p10);
    copy_vec(w->v17F0, w->v1950);

    copy_vec(w->v1960, p10);
    copy_vec(w->v1970, v00);
    func_01B04558(1, w->m1800);
    func_01B04AD8(1, w->m1800, p10);
    copy_vec(w->v1830, w->v1970);

    copy_vec(w->v1980, p10);
    copy_vec(w->v1990, v00);
    func_01B04558(2, w->m1840);
    func_01B04AD8(2, w->m1840, p10);
    copy_vec(w->v1870, w->v1990);

    func_01B04050(-1, 1);
    func_01B04050(1, 1);
    func_01B04050(2, 1);
    func_01B03FB0(-1, 0);
    func_01B03FB0(1, 0);
    func_01B03FB0(2, 0);

    w->w228C = 0;
    w->f2270 = v10[1];
    D_01B0A204 = 1;
    D_01B0A224 = 1;
    D_01B0A244 = 1;
    D_01B0A264 = 1;
}

void ovl_09633_1980(void)
{
    Work9633 *w = D_01B0A270;
    MatObj *m;

    func_01B07640(0);
    m = func_01B07970(0);
    m->b146 = 1;
    func_002DD128(m);
    func_002DD318(m, m, w->f2270);
    copy_vec(m->v30, w->v1950);
}

void ovl_09633_19f0(void)
{
    func_00103208(func_01B03130(3));
    func_00103208(func_01B03130(4));
    func_00103208(func_01B03130(5));
    func_01B04930(0x301A);
    func_01B04930(0x301B);
    func_01B04930(0x301C);
    func_01B05138(1);
    func_01B07780();
}

void ovl_09633_1a58(void)
{
    func_01B04880(0x301A);
    func_01B04880(0x301B);
    func_01B04880(0x301C);
}

void ovl_09633_1a80(void)
{
    Work9633 *w = D_01B0A270;
    ObjF98 *f98 = &D_01B00F98;
    void *p;

    p = func_01B048F0(0x301A);
    f98->pC4 = p;
    f98->b17 = 0x20;
    func_00110648(p, 0);

    p = func_01B048F0(0x301B);
    f98->pC8 = p;
    f98->b18 = 0x21;
    func_00110648(p, 0);

    p = func_01B048F0(0x301C);
    f98->pCC = p;
    f98->b19 = 0x22;
    func_00110648(p, 0);

    {
        register s32 tmp __asm__("$3") = f98->w04;
        f98->w04 = tmp + 3;
    }

    func_01B04558(3, w->m1880);
    copy_vec(w->v19A0, w->v1940);
    copy_vec(w->v19B0, w->v1950);
    w->v19B0[1] -= 1.0f;
    func_01B04AD8(3, w->m1880, w->v19A0);
    func_01B06BB8(w->m1880, 0.0f);
    func_01B04AA8(3, 0.0001f);

    func_01B04558(4, w->m18C0);
    copy_vec(w->v19C0, w->v1960);
    copy_vec(w->v19D0, w->v1970);
    w->v19D0[1] -= 1.0f;
    func_01B04AD8(4, w->m18C0, w->v19C0);
    func_01B06BB8(w->m18C0, 0.0f);
    func_01B04AA8(4, 0.0001f);

    func_01B04558(5, w->m1900);
    copy_vec(w->v19E0, w->v1980);
    copy_vec(w->v19F0, w->v1990);
    w->v19F0[1] -= 1.0f;
    func_01B04AD8(5, w->m1900, w->v19E0);
    func_01B06BB8(w->m1900, 0.0f);
    func_01B04AA8(5, 0.0001f);
}

void ovl_09633_1c88(void)
{
    Work9633 *w = D_01B0A270;
    ObjA *a;

    func_01B09470(w->b1BB0, 1, 0, 1.0f, 1.2f);
    a = &w->objA[0];
    a->b82 = 0xFF;
    a->b81 = 0xFF;
    a->b80 = 0xFF;
    a->b83 = 0x80;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->w88 = 0;
    a->b98 = 0x48;
    a->b99 = 0;
    func_01B092B8(a, 0x4B);
}

void ovl_09633_1d18(void)
{
    Work9633 *w = D_01B0A270;
    ObjA *a = &w->objA[0];

    a->b86 = 0xFF;
    a->b85 = 0xFF;
    a->b84 = 0xFF;
    a->b87 = 0x80;
    a->b98 = 0x48;
    a->b83 = 0;
    a->b82 = 0;
    a->b81 = 0;
    a->b80 = 0;
    a->w88 = 0;
    a->b99 = 0;
    func_01B092B8(a, 0x14);
    a->w94 = 1;

    a = &w->objA[1];
    *(volatile u8 *)&a->b80 = 0xFF;
    *(volatile u8 *)&a->b83 = 0x80;
    *(volatile u8 *)&a->b98 = 0x48;
    *(volatile u8 *)&a->b82 = 0xFF;
    *(volatile u8 *)&a->b81 = 0xFF;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    a->w88 = 0x15;
    func_01B092B8(a, 0x1E);
}

void ovl_09633_1de8(s32 a0, s32 a1, s32 a2)
{
    s32 buf[4];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = 0x80;
    func_00173650(buf);
}
