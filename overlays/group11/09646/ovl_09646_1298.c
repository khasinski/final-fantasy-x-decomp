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
} ObjD78;

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Mgr9718;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x50];
} Sub130;

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
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
    u8 pad9A[0x6];
} ObjA;

typedef struct {
    u8 pad00[0xF0];
    u8 bF0;
    u8 bF1;
    u8 bF2;
    u8 bF3;
    u8 padF4[0x4];
    float fF8;
    float fFC;
    s32 w100;
    u8 pad104[0xC];
    s32 w110;
    u8 pad114[0xC];
    s32 w120;
    s16 h124;
    u8 pad126[0x1A];
} ObjB;

typedef struct {
    Sub130 sub[12];       /* 0x000..0xE40 */
    u8 padE40[0x5F0];
    Sub130 sub2[2];       /* 0x1430..0x1690 */
    u8 pad1690[0x130];
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
    u8 m1940[0x30];
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
    float v1A10[4];
    float v1A20[4];
    float v1A30[4];
    float v1A40[4];
    float v1A50[4];
    float v1A60[4];
    float v1A70[3][4];
    float v1AA0[3][4];
    ObjA objA[2];         /* 0x1AD0, 0x1B70 */
    u8 b1C10[0x40];
    u8 b1C50[0xB0];
    ObjB objB[3];         /* 0x1D00, 0x1E40, 0x1F80 */
    u8 pad20C0[0x230];
    float f22F0;          /* 0x22F0 */
    u8 pad22F4[0xC];
    s32 timer[3];         /* 0x2300 */
    s32 w230C;            /* 0x230C */
} Work9646;

typedef struct {
    u8 pad00[0x30];
    float v30[4];
    u8 pad40[0x106];
    u8 b146;
} MatObj;

extern u8 D_01BC3630[];
extern u8 D_01BDE680[];
extern u8 D_01B00040[];
extern float D_01B007C0[];
extern u8 D_01B007D0[];
extern u8 D_01B00AE8[];
extern ObjD78 D_01B00D78;
extern u8 *D_01B00F84;
extern s32 D_01B09710;
extern Mgr9718 D_01B09718;
extern s32 D_01B09758;
extern u8 *D_01B0975C;
extern u8 D_01B09760[];
extern u8 D_01B097C0[];
extern u8 D_01B09820[];
extern s32 D_01B09834;
extern u8 D_01B09840[];
extern s32 D_01B09854;
extern u8 D_01B09860[];
extern s32 D_01B09874;
extern u8 D_01B09880[];
extern s32 D_01B09894;
extern Work9646 *D_01B098A0;
extern u8 *D_01B098A4;
extern u8 D_01B0EFE0[];

extern void func_01B03EB0(s32);
extern s32 func_01B03EE0(s32);
extern void func_002B4980(void *);
extern s32 func_01B026C8(s32);
extern s32 func_001B4E58(s32);
extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B05160(void *, void *, void *, s32);
extern void func_01B087C8(void *, void *);
extern void func_01B04748(s32);
extern Task *func_01B04ED8(void *);
extern void func_01B050A0(Task *);
extern void func_01B08CD8(void *, s32);
extern void func_01B065C0(void);
extern s32 func_01B087E8(void *);
extern void func_01B043B8(void *);
extern void func_01B06DE8(void);
extern void func_01B04F58(void *);
extern s32 func_01B05318(void *, void *);
extern void func_001CDDD8(s32);
extern void func_01B02918(s32, void *, s32);
extern float func_01B027F0(s32);
extern void func_01B03B88(s32, void *);
extern void func_01B04108(s32, void *, void *);
extern void func_01B03680(s32, s32);
extern void func_01B035E0(s32, s32);
extern void func_01B06C70(s32);
extern MatObj *func_01B06FA0(s32);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern s32 func_01B02760(s32);
extern void func_00103208(s32);
extern void func_01B03F60(s32);
extern void func_01B04768(s32);
extern void func_01B06DB0(void);
extern void *func_01B03F20(s32);
extern void func_00110648(void *, s32);
extern void func_01B06070(void *, void *, void *);
extern void func_01B061E8(void *, float);
extern void func_01B040D8(s32, float);
extern void func_00118098(s32, s32);
extern void func_01B08AA0(void *, s32, s32, float, float);
extern void func_01B056A8(void *, void *);
extern void func_01B05238(void *, void *, s32, s32, s32, s32, float);
extern void func_01B088E8(void *, s32);
extern void func_01B09270(void *, s32);

void ovl_09646_14c8(void *a0);
void ovl_09646_1600(void);
void ovl_09646_1668(void);
void ovl_09646_1868(void);
void ovl_09646_18d8(void);

void ovl_09646_1298(void)
{
    func_01B03EB0(0x301A);
    func_01B03EB0(0x301B);
    func_01B03EB0(0x301C);
}

s32 ovl_09646_12c0(void)
{
    s32 r1 = func_01B03EE0(0x301A);
    if (r1 != 1) {
        return 0;
    }
    {
        s32 r2 = func_01B03EE0(0x301B);
        if (r2 != 1) {
            return 0;
        }
        if (func_01B03EE0(0x301C) != 1) {
            r2 = 0;
        }
        return r2;
    }
}

s32 ovl_09646_1328(void)
{
    u8 *p;
    ObjD78 *d78;
    register s32 id __asm__("$16");
    Mgr9718 *mgr;
    Task *t;

    func_002B4980(D_01BC3630);
    p = D_01BDE680;
    D_01B09758 = 0;
    D_01B0975C = p + 0x40000;
    D_01B098A4 = p + 0x140000;
    D_01B098A0 = (Work9646 *)(p + 0x1A0000);

    d78 = &D_01B00D78;
    id = func_01B026C8(-1) + 1;
    d78->b15 = id;
    d78->arr44[id] = func_001B4E58(id);
    id++;
    d78->b16 = id;
    d78->arr44[id] = func_001B4E58(id);
    d78->w04 = 3;

    mgr = &D_01B09718;
    mgr->w2C = func_002B49A0(D_01B0EFE0, 8, 0);
    func_01B05160(mgr, D_01B00040, p, 0x40000);
    ovl_09646_1668();
    ovl_09646_1868();
    func_01B087C8(D_01B09760, D_01B007D0);
    func_01B087C8(D_01B097C0, D_01B00AE8);
    func_01B04748(1);

    t = func_01B04ED8((void *)ovl_09646_14c8);
    t->b18 = 1;
    func_01B050A0(t);

    func_01B08CD8(p + 0x180000, 0x400);

    t = func_01B04ED8((void *)ovl_09646_1600);
    t->b18 = 2;
    func_01B050A0(t);
    return 0;
}

void ovl_09646_14c8(void *a0)
{
    Work9646 *w = D_01B098A0;
    s32 r;

    func_01B065C0();
    D_01B00F84 = D_01B098A4;
    r = func_01B087E8(D_01B09760);
    func_01B087E8(D_01B097C0);
    if (r == 0) {
        copy_vec(w->v17F0, w->v1990);
        copy_vec(w->v1830, w->v19B0);
        copy_vec(w->v1870, w->v19D0);
        copy_vec(w->v18B0, w->v19F0);
        copy_vec(w->v18F0, w->v1A10);
        copy_vec(w->v1930, w->v1A30);
        copy_vec(w->v1970, w->v1A50);
        func_01B043B8(D_01B09820);
        func_01B043B8(D_01B09840);
        func_01B043B8(D_01B09860);
        func_01B043B8(D_01B09880);
        func_01B06DE8();
    } else {
        w->w230C = 1;
        ovl_09646_18d8();
        func_01B04F58(a0);
    }
}

void ovl_09646_1600(void)
{
    Work9646 *w = D_01B098A0;
    if (func_01B05318(&D_01B09718, D_01B0975C) == 1 && w->w230C == 1) {
        func_001CDDD8(D_01B09710);
    }
}

void ovl_09646_1668(void)
{
    float v00[4];
    float v10[4];
    register Work9646 *w __asm__("$16") = D_01B098A0;
    register float *p10 __asm__("$18");

    func_01B02918(0, v00, 0);
    copy_vec(w->v1A60, v00);
    v10[0] = 0.0f;
    *(volatile float *)&v10[1] = func_01B027F0(0);
    {
        float *dst = w->v1980;
        *(volatile float *)&v10[2] = 0.0f;
        p10 = v10;
        *(volatile float *)&v10[3] = 0.0f;
        copy_vec(dst, p10);
    }
    copy_vec(w->v1990, v00);
    func_01B03B88(0, w->m17C0);
    func_01B04108(0, w->m17C0, p10);
    copy_vec(w->v17F0, w->v1990);

    copy_vec(w->v19A0, p10);
    copy_vec(w->v19B0, v00);
    func_01B03B88(-1, w->m1800);
    func_01B04108(-1, w->m1800, p10);
    copy_vec(w->v1830, w->v19B0);

    copy_vec(w->v19C0, p10);
    copy_vec(w->v19D0, v00);
    func_01B03B88(1, w->m1840);
    func_01B04108(1, w->m1840, p10);
    copy_vec(w->v1870, w->v19D0);

    copy_vec(w->v19E0, p10);
    copy_vec(w->v19F0, v00);
    func_01B03B88(2, w->m1880);
    func_01B04108(2, w->m1880, p10);
    copy_vec(w->v18B0, w->v19F0);

    func_01B03680(-1, 1);
    func_01B03680(1, 1);
    func_01B03680(2, 1);
    func_01B035E0(-1, 0);
    func_01B035E0(1, 0);
    func_01B035E0(2, 0);

    w->w230C = 0;
    w->f22F0 = v10[1];
    D_01B09834 = 1;
    D_01B09854 = 1;
    D_01B09874 = 1;
    D_01B09894 = 1;
}

void ovl_09646_1868(void)
{
    Work9646 *w = D_01B098A0;
    MatObj *m;

    func_01B06C70(0);
    m = func_01B06FA0(0);
    m->b146 = 1;
    func_002DD128(m);
    func_002DD318(m, m, w->f22F0);
    copy_vec(m->v30, w->v1990);
}

void ovl_09646_18d8(void)
{
    func_00103208(func_01B02760(3));
    func_00103208(func_01B02760(4));
    func_00103208(func_01B02760(5));
    func_01B03F60(0x301A);
    func_01B03F60(0x301B);
    func_01B03F60(0x301C);
    func_01B04768(1);
    func_01B06DB0();
}

void ovl_09646_1940(void)
{
    float v00[4];
    float v10[4];
    Work9646 *w = D_01B098A0;
    ObjD78 *d78 = &D_01B00D78;
    void *p;

    p = func_01B03F20(0x301A);
    d78->pC4 = p;
    d78->b17 = 0x20;
    func_00110648(p, 0);

    p = func_01B03F20(0x301B);
    d78->pC8 = p;
    d78->b18 = 0x21;
    func_00110648(p, 0);

    p = func_01B03F20(0x301C);
    d78->pCC = p;
    d78->b19 = 0x22;
    func_00110648(p, 0);

    d78->w04 += 3;

    v00[0] = 0.0f;
    v00[1] = w->f22F0;
    v00[2] = 0.0f;
    v00[3] = 0.0f;
    v10[1] = 0.0f;
    v10[3] = 1.0f;

    copy_vec(w->v19B0, w->v1A60);
    v10[0] = -16.5f;
    v10[2] = -0.8f;
    func_01B06070(v00, w->v19B0, v10);

    copy_vec(w->v19D0, w->v1A60);
    v10[0] = 0.0f;
    v10[2] = 15.5f;
    func_01B06070(v00, w->v19D0, v10);

    copy_vec(w->v19F0, w->v1A60);
    v10[0] = 16.5f;
    v10[2] = -0.8f;
    func_01B06070(v00, w->v19F0, v10);

    func_01B03B88(3, w->m18C0);
    copy_vec(w->v1A00, w->v19A0);
    {
        register float *d __asm__("$3") = w->v1A10;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v19B0);
    }
    w->v1A10[1] -= 1.0f;
    func_01B04108(3, w->m18C0, w->v1A00);
    func_01B061E8(w->m18C0, 2.2f);
    func_01B040D8(3, 2.2f);

    func_01B03B88(4, w->m1900);
    copy_vec(w->v1A20, w->v19C0);
    {
        register float *d __asm__("$3") = w->v1A30;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v19D0);
    }
    w->v1A30[1] -= 1.0f;
    func_01B04108(4, w->m1900, w->v1A20);
    func_01B061E8(w->m1900, 2.0f);
    func_01B040D8(4, 2.0f);

    func_01B03B88(5, w->m1940);
    copy_vec(w->v1A40, w->v19E0);
    {
        register float *d __asm__("$3") = w->v1A50;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v19F0);
    }
    w->v1A50[1] -= 1.0f;
    func_01B04108(5, w->m1940, w->v1A40);
    func_01B061E8(w->m1940, 2.0f);
    func_01B040D8(5, 2.0f);
}

void ovl_09646_1c00(void)
{
    Work9646 *w = D_01B098A0;
    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B08AA0(w->b1C10, 1, 0, 1.0f, 0.34f);
}

void ovl_09646_1c60(void)
{
    Work9646 *w = D_01B098A0;
    Mgr9718 *mgr = &D_01B09718;
    Sub130 *s;
    ObjA *a;
    ObjB *b;

    func_01B056A8(mgr, &w->sub[5]);
    func_01B056A8(mgr, &w->sub[8]);
    func_01B056A8(mgr, &w->sub[7]);
    func_01B056A8(mgr, &w->sub[6]);

    s = &w->sub[1];
    func_01B05238(mgr, s, 1, 6, 0, 0, 0.01f);
    copy_vec(s->pos, w->v19D0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 12.0f;

    a = &w->objA[0];
    a->w88 = 10;
    a->b82 = 0x80;
    a->b81 = 0x80;
    a->b80 = 0x80;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    func_01B088E8(a, 10);

    b = &w->objB[0];
    b->bF0 = 0x80;
    b->bF1 = 0x80;
    b->bF2 = 0x80;
    b->bF3 = 0x40;
    b->h124 = 4;
    b->fF8 = 0.02f;
    b->fFC = 0.01f;
    b->w120 = 0;
    b->w110 = 0;
    b->w100 = 0;
    func_01B09270(b, 50);

    func_01B08AA0(w->b1C50, 20, 10, 0.34f, 1.0f);
}

void ovl_09646_1de8(void)
{
    register Work9646 *w __asm__("$18") = D_01B098A0;
    Sub130 *s = &w->sub[2];
    ObjA *a;
    ObjB *b;

    func_01B05238(&D_01B09718, s, 2, 6, 0, 0, 0.012f);
    copy_vec(s->pos, w->v19B0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 10.0f;

    a = &w->objA[0];
    a->w88 = 10;
    a->b82 = 0x80;
    a->b81 = 0x80;
    a->b80 = 0x80;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    func_01B088E8(a, 10);

    b = &w->objB[1];
    b->bF0 = 0x80;
    b->bF1 = 0x80;
    b->bF2 = 0x80;
    b->bF3 = 0x40;
    b->h124 = 4;
    b->fF8 = 0.02f;
    b->fFC = 0.01f;
    b->w120 = 0;
    b->w110 = 0;
    b->w100 = 0;
    func_01B09270(b, 50);

    func_01B08AA0(w->b1C10, 1, 0, 1.0f, 0.34f);
    func_01B08AA0(w->b1C50, 20, 10, 0.34f, 1.0f);
}

void ovl_09646_1f68(void)
{
    register Work9646 *w __asm__("$18") = D_01B098A0;
    Sub130 *s = &w->sub[3];
    ObjA *a;
    ObjB *b;

    func_01B05238(&D_01B09718, s, 3, 6, 0, 0, 0.008f);
    copy_vec(s->pos, w->v19F0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 6.0f;

    a = &w->objA[0];
    a->w88 = 10;
    a->b82 = 0x80;
    a->b81 = 0x80;
    a->b80 = 0x80;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    func_01B088E8(a, 10);

    b = &w->objB[2];
    b->bF0 = 0x80;
    b->bF1 = 0x80;
    b->bF2 = 0x80;
    b->bF3 = 0x40;
    b->h124 = 4;
    b->fF8 = 0.02f;
    b->fFC = 0.01f;
    b->w120 = 0;
    b->w110 = 0;
    b->w100 = 0;
    func_01B09270(b, 50);

    func_01B08AA0(w->b1C10, 1, 0, 1.0f, 0.34f);
    func_01B08AA0(w->b1C50, 20, 10, 0.34f, 1.0f);
}

void ovl_09646_20e8(void)
{
    float v00[4];
    float v10[4];
    Work9646 *w = D_01B098A0;
    ObjA *a;

    func_01B05238(&D_01B09718, &w->sub[0], 0, 0, 0, 0, 0.01f);
    copy_vec(w->sub[0].pos, w->v1A60);
    w->sub[0].fC4 = w->f22F0;
    w->sub[0].pos[1] -= 0.5f;

    a = &w->objA[1];
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
    func_01B088E8(a, 0x2D);

    v00[0] = 0.0f;
    v00[1] = w->f22F0;
    v00[2] = 0.0f;
    v00[3] = 0.0f;
    v10[1] = 0.0f;
    v10[3] = 1.0f;

    copy_vec(w->v19B0, w->v1A60);
    v10[0] = -8.5f;
    v10[2] = -0.8f;
    func_01B06070(v00, w->v19B0, v10);

    copy_vec(w->v19D0, w->v1A60);
    v10[0] = 0.0f;
    v10[2] = 13.0f;
    func_01B06070(v00, w->v19D0, v10);

    copy_vec(w->v19F0, w->v1A60);
    v10[0] = 8.5f;
    v10[2] = -0.8f;
    func_01B06070(v00, w->v19F0, v10);
}

void ovl_09646_2278(void)
{
    float v00[4];
    float v10[4];
    Work9646 *w = D_01B098A0;
    Sub130 *s;

    v00[0] = 0.0f;
    v00[1] = w->f22F0;
    v00[2] = 0.0f;
    v00[3] = 0.0f;
    v10[1] = 0.0f;
    v10[3] = 1.0f;

    copy_vec(w->v1A70[0], w->v19B0);
    copy_vec(w->v1AA0[0], w->v1A60);
    v10[0] = -16.5f;
    v10[2] = -20.0f;
    func_01B06070(v00, w->v1AA0[0], v10);

    copy_vec(w->v1A70[1], w->v19D0);
    copy_vec(w->v1AA0[1], w->v1A60);
    v10[0] = 0.0f;
    v10[2] = -25.0f;
    func_01B06070(v00, w->v1AA0[1], v10);

    copy_vec(w->v1A70[2], w->v19F0);
    copy_vec(w->v1AA0[2], w->v1A60);
    v10[0] = 16.5f;
    v10[2] = -20.0f;
    func_01B06070(v00, w->v1AA0[2], v10);

    w->timer[0] = 0x43;
    w->timer[1] = 0x1C;
    w->timer[2] = 0x23;

    s = &w->sub2[0];
    func_01B05238(&D_01B09718, s, 0xD, 0x13, 0, 0, 0.015f);
    {
        register float *d __asm__("$3") = s->pos;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v1AA0[0]);
    }
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;

    s = &w->sub2[1];
    func_01B05238(&D_01B09718, s, 0xD, 0x1B, 0, 0, 0.015f);
    {
        register float *d __asm__("$3") = s->pos;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v1AA0[1]);
    }
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;
}

void ovl_09646_2470(void)
{
    float v[3][4];
    register Work9646 *w __asm__("$3") = D_01B098A0;
    register float *dp __asm__("$4") = D_01B007C0;
    register float *v1 __asm__("$12") = v[1];
    register float *p19B0 __asm__("$10") = w->v19B0;
    register float *p19D0 __asm__("$11") = w->v19D0;
    register float *p19F0 __asm__("$9") = w->v19F0;
    register float *v2 __asm__("$8") = v[2];
    float (*vp)[4] = v;
    s32 *tp = w->timer;
    s32 i;

    for (i = 0; i < 3; i++) {
        float t;
        float u;
        if (*tp > 0) {
            (*tp)--;
        }
        t = (float)*tp / *dp;
        u = 1.0f - t;
        (*vp)[0] = w->v1AA0[0][0] * u + w->v1A70[0][0] * t;
        (*vp)[1] = w->v1AA0[0][1];
        (*vp)[2] = w->v1AA0[0][2] * u + w->v1A70[0][2] * t;
        (*vp)[3] = 1.0f;
        dp++;
        tp++;
        w = (Work9646 *)((u8 *)w + 0x10);
        vp++;
    }

    copy_vec(p19B0, v[0]);
    copy_vec(p19D0, v1);
    copy_vec(p19F0, v2);
}
