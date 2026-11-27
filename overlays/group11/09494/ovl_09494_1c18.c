#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x1B80];
    Vec4 v1B80;     /* 0x1B80 */
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 pad1BB0[0x30];
    Vec4 v1BE0;     /* 0x1BE0 */
    u8 pad1BF0[0x10];
    Vec4 v1C00;     /* 0x1C00 */
    Vec4 v1C10;     /* 0x1C10 */
    u8 pad1C20[0x2F0];
    float f1F10;    /* 0x1F10 */
    int w1F14;      /* 0x1F14 */
    int w1F18;      /* 0x1F18 */
    int w1F1C;      /* 0x1F1C */
    u8 pad1F20[0x0C];
    int w1F2C;      /* 0x1F2C */
} Ovl09494Work;

extern void *D_01B00CF4;
extern int D_01B0A220;
extern u8 D_01B0A228[];
extern void *D_01B0A26C;
extern u8 D_01B0A270[];
extern u8 D_01B0A2D0[];
extern int D_01B0A2E4;
extern u8 D_01B0A2F0[];
extern int D_01B0A304;
extern Ovl09494Work *D_01B0A310;
extern void *D_01B0A318;

extern void func_00103208(int);
extern void func_0011ABA8(int);
extern int func_0011ABB8(void);
extern void func_001CDDD8(int);

extern void func_01B00FD0(void);
extern int func_01B03630(int);
extern float func_01B036C0(int);
extern void func_01B037E8(int, void *, int);
extern void func_01B04A58(int, void *);
extern void func_01B04D80(int);
extern int func_01B05288(void *);
extern void func_01B05E28(void *);
extern int func_01B061E8(void *, void *);
extern void func_01B07490(void);
extern int func_01B096B8(void *);

void func_01B01DE8(void);

void func_01B01C18(void *a0)
{
    Ovl09494Work *w = D_01B0A310;
    int r;

    func_01B07490();
    D_01B00CF4 = D_01B0A318;
    r = func_01B096B8(D_01B0A270);
    if (func_0011ABB8() == 0) {
        int r1 = func_01B05288(D_01B0A2D0);
        func_01B05288(D_01B0A2F0);
        if (r == 0 || r1 == 0) {
            copy_vec(&w->v1B80, &w->v1BA0);
            copy_vec(&w->v1BE0, &w->v1C00);
        } else {
            w->w1F2C = 1;
            func_01B01DE8();
            func_01B05E28(a0);
        }
    }
}

void func_01B01D00(void)
{
    Ovl09494Work *w = D_01B0A310;
    int r;

    if (func_0011ABB8() == 0) {
        r = func_01B061E8(D_01B0A228, D_01B0A26C);
    } else {
        r = 0;
    }
    if (r == 1 && w->w1F2C == 1) {
        func_01B04A58(-1, 0);
        func_001CDDD8(D_01B0A220);
    }
}

void func_01B01D80(void)
{
    Ovl09494Work *w = D_01B0A310;

    func_01B037E8(-1, &w->v1C10, 0);
    w->f1F10 = func_01B036C0(-1);
    w->w1F2C = 0;
    w->w1F1C = -1;
    w->w1F14 = -1;
    D_01B0A2E4 = 1;
    D_01B0A304 = 1;
    func_01B00FD0();
}

void func_01B01DE8(void)
{
    Ovl09494Work *w = D_01B0A310;

    func_0011ABA8(0);
    func_00103208(func_01B03630(1));
    if (w->w1F1C != -1) {
        func_00103208(func_01B03630(2));
    }
}

void func_01B01E50(void)
{
    Ovl09494Work *w = D_01B0A310;

    func_01B04D80(0x4029);
    if (w->w1F1C != -1) {
        func_01B04D80(w->w1F1C);
    }
}
