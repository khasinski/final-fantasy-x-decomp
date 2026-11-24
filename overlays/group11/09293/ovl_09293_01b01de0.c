#include "common.h"

typedef struct Ovl09293Cb {
    u8 pad00[0x10];
    int p10;
} Ovl09293Cb;

typedef struct Ovl09293Task {
    u8 pad00[0x8];
    Ovl09293Cb *p08;
    u8 pad0C[0x8];
    int w14;
} Ovl09293Task;

typedef struct Ovl09293Sub {
    u8 pad00[0x14];
    s16 h14;
    s16 h16;
} Ovl09293Sub;

typedef struct Ovl09293Part {
    u8 pad00[0x10];
    float pos[4];
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    u8 pad34[4];
    int w38;
    int w3C;
    u8 pad40[0xB];
    u8 b4B;
} Ovl09293Part;

typedef struct Ovl09293Node {
    u_long128 q00;
    u8 pad10[0x10];
    float f20;
    float f24;
    int w28;
    int w2C;
    int w30;
    u8 pad34[0xC];
} Ovl09293Node;

extern u_long128 D_01B00690[];
extern u8 D_01B00B38[];
extern u8 D_01B074D8[];
extern Ovl09293Node D_01B07E80[];
extern int D_01B08180;
extern int D_01B08188;
extern int D_01B0818C;
extern u8 D_01B08190[];
extern int D_01B081D4;
extern u8 D_01B0D520[];

void *func_002B49A0(void *a0, int a1, int a2);
float func_002B3DB0(float a0);
float func_002B3DF8(float a0);
int func_002EFD78(void);
void func_002A7308(int a0, void *a1, int a2, int a3);

void func_01B00CF8(void *a0, int a1, void *a2, void *a3, void *a4, void *a5, int a6);
void *func_01B02608(int a0);
void func_01B02C60(int a0, int a1, float *a2, float *a3);
void func_01B02D10(int a0, void *a1);
void func_01B02D80(int a0, int a1, void *a2);
void func_01B03488(int a0, int a1);
void func_01B03858(int a0, int a1);
void func_01B04010(int a0, void *a1);
void func_01B04070(void *a0);
void func_01B04150(int a0, int a1, int a2);
int func_01B04260(void *a0);
void func_01B04E00(void);
int func_01B051C0(void *a0, int a1);
float func_01B05BC8(float a0, float a1, float a2, float a3);
void func_01B064A8(Ovl09293Part *a0, void *a1);
Ovl09293Part *func_01B06BB0(void);

int func_01B02210(void);
int func_01B022A8(void);
void func_01B02168(void);

void func_01B01DE0(Ovl09293Task *a0)
{
    int s0;
    int s1;
    int v1;

    s0 = func_01B04260(D_01B074D8);
    s1 = func_01B02210();
    v1 = func_01B051C0(D_01B08190, D_01B081D4);
    if (v1 == 1 && s0 == 1 && s1 == 1) {
        func_01B03858(-1, 0);
        func_01B04150(-1, -1, -1);
        func_01B03488(-1, 0);
        a0->w14 = 3;
        a0->p08->p10 = (int)D_01B00B38;
    }
}

void func_01B01EA0(Ovl09293Sub *a0)
{
    float pos[4];
    Ovl09293Part *p;
    int i;

    if (a0->h14 != 0) {
        a0->h14--;
        return;
    }
    {
        register int v __asm__("$2") = (u16)a0->h16 - 1;
        register int t __asm__("$3") = v << 16;
        a0->h16 = v;
        if (t == 0) {
            func_01B04E00();
            return;
        }
    }
    p = func_01B06BB0();
    if (p != 0) {
        func_01B064A8(p, func_002B49A0(D_01B0D520, 9, 0));
        pos[0] = 1200.0f;
        pos[1] = 0.0f;
        pos[2] = 0.0f;
        pos[3] = 1.0f;
        func_01B02C60(-1, 0x45, pos, p->pos);
        p->f20 = p->f24 = p->f28 = 0.0f;
        p->f2C = func_002B3DB0(3.1415927f);
        p->f30 = 0.5f;
        p->w38 = 0x20;
        p->w3C = 0;
        p->b4B = 0x40;

        i = 0;
        {
            register int c20 __asm__("$20") = 0x20;
            register int c40 __asm__("$19") = 0x40;
            do {
                p = func_01B06BB0();
                if (p == 0) {
                    break;
                }
                i++;
                func_01B064A8(p, func_002B49A0(D_01B0D520, 9, 1));
                pos[0] = 1200.0f;
                pos[1] = func_002B3DB0(500.0f);
                pos[2] = func_002B3DB0(500.0f);
                pos[3] = 1.0f;
                func_01B02C60(-1, 0x45, pos, p->pos);
                p->f20 = func_002B3DB0(0.3f);
                p->f24 = func_002B3DB0(0.3f);
                p->f28 = func_002B3DB0(0.3f);
                p->f2C = func_002B3DB0(3.1415927f);
                p->f30 = 0.1f;
                p->w38 = c20;
                p->w3C = 0;
                p->b4B = c40;
            } while (i < 3);
        }
    }
}

void func_01B020D0(u8 *a0)
{
    float pos[4];

    pos[0] = 600.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    pos[3] = 1.0f;
    func_01B02C60(-1, 0x45, pos, (float *)(a0 + 0xD0));
    func_01B02D80(-1, 0x45, a0 + 0x80);
    a0[0x126] = 2;
}

void func_01B02140(u8 *a0)
{
    D_01B08188 = 1;
    *(void (**)(void))(a0 + 0x100) = func_01B02168;
    *(int *)(a0 + 0x11C) = 0x50;
}

void func_01B02168(void)
{
    D_01B0818C = 1;
}

void func_01B02178(void)
{
    int i;
    Ovl09293Node *d = D_01B07E80;
    u_long128 *s = D_01B00690;

    for (i = 0; i < 6; i++) {
        register u_long128 q __asm__("$7") = *s;
        d->q00 = q;
        __asm__ volatile("" : "+r"(d));
        d->w28 = 1;
        s++;
        d->f20 = 0.0f;
        d->w30 = 0;
        d++;
    }
}

void func_01B021C0(void)
{
    void *s0 = func_01B02608(-1);

    func_01B04150(-1, 0x3C00, 0x2EE0);
    func_002A7308(D_01B08180, s0, 1, 0);
}

int func_01B02210(void)
{
    float m0[16];
    float m1[16];
    float m2[16];
    int ret;

    ret = func_01B022A8();
    func_01B02D10(-1, m0);
    func_01B04010(-1, m1);
    func_01B04070(m2);
    func_01B00CF8(func_01B02608(-1), D_01B08180, m0, m1, m2, D_01B07E80, 6);
    return ret;
}

int func_01B022A8(void)
{
    Ovl09293Node *p;
    int i;
    int ret;

    if (D_01B08188 == 0) {
        return 0;
    }
    ret = 1;
    p = D_01B07E80;
    for (i = 0; i < 6; i++, p++) {
        if (p->w30 == 0) {
            if (--p->w28 == 0) {
                p->f24 = func_002B3DF8(20.0f) + 20.0f;
                p->w28 = p->w2C = func_002EFD78() % 21 + 20;
                if (D_01B0818C == 1) {
                    p->w30 = 1;
                }
            }
            p->f20 = func_01B05BC8(0.0f, p->f24, 0.0f, (float)p->w28 / (float)p->w2C);
            ret = 0;
        } else {
            p->f20 += 0.75f;
            if (p->f20 > 100.0f) {
                p->f20 = 100.0f;
            } else {
                ret = 0;
            }
        }
    }
    return ret;
}
