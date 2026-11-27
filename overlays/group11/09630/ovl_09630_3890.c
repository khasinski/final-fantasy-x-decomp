#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x30];
    Vec4 v30;
    u8 pad40[0x106];
    u8 b146;
} Obj9430;

typedef struct {
    u8 pad00[0x920];
    Vec4 v920;
    u8 pad930[0x7A00];
    int w8330;
    int w8334;
    int w8338;
    int w833C;
    u8 pad8340[0x90];
    u8 f83D0[0x1F8];
    float f85C8;
} Work9630;

typedef struct {
    u8 pad00[0x04];
    int w04;
    u8 pad08[0x0D];
    u8 b15;
    u8 b16;
    u8 pad17[0xAD];
    int wC4;
    int wC8;
} StateB48;

extern StateB48 D_01B00B48;
extern u8 D_01B0BF48[];
extern u8 D_01B0C050[];
extern Work9630 *D_01B0C0B0;

extern void func_00103208(int);
extern int func_00110648(int, int);
extern void func_00117E58(int);
extern void func_00118098(int, int);
extern void func_001CE9A8(int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);

extern void func_01B03688(void);
extern int func_01B04BF0(int);
extern void func_01B059E8(int, int);
extern void func_01B05A70(int, int);
extern void func_01B05BB0(int);
extern void func_01B05C68(int);
extern void func_01B05E98(int, int);
extern void func_01B06018(int, int);
extern void func_01B06340(int);
extern int func_01B063B0(int);
extern void func_01B063F0(int);
extern void func_01B06AE8(void *, int);
extern void func_01B07B98(void *);
extern void func_01B09100(int);
extern void func_01B09240(void);
extern Obj9430 *func_01B09430(int);
extern void func_01B0AEE8(void *, int);
extern void func_01B0B2D0(void *, int, int, float, float);

void func_01B03890(void)
{
    Work9630 *w = D_01B0C0B0;
    Obj9430 *o;

    func_01B09100(0);
    o = func_01B09430(0);
    o->b146 = 1;
    func_002DD128(o);
    func_002DD318(o, o, w->f85C8);
    copy_vec(&o->v30, &w->v920);
}

void func_01B03908(void)
{
    func_00103208(func_01B04BF0(1));
    func_00103208(func_01B04BF0(2));
    func_01B063F0(0x3011);
    func_01B063F0(0x3013);
    func_01B06018(-1, 0);
    func_01B06AE8(D_01B0C050, 0);
    func_01B05A70(-1, 1);
    func_01B05E98(-1, 0);
    func_01B059E8(-1, 1);
    func_01B05BB0(1);
    func_01B05C68(1);
    func_00118098(0, 0);
    func_00118098(1, 0);
    func_00117E58(0);
    func_01B07B98(D_01B0BF48);
    func_01B09240();
    func_001CE9A8(0);
}

void func_01B039D8(void)
{
    func_01B06340(0x3011);
    func_01B06340(0x3013);
}

void func_01B039F8(void)
{
    StateB48 *s = &D_01B00B48;
    int h;

    h = func_01B063B0(0x3011);
    s->wC4 = h;
    s->b15 = 0x20;
    func_00110648(h, 0);

    h = func_01B063B0(0x3013);
    s->wC8 = h;
    s->b16 = 0x21;
    func_00110648(h, 0);

    s->w04 = 3;
    func_01B03688();
}

void func_01B03A70(void)
{
    Work9630 *w = D_01B0C0B0;
    int *p;

    func_01B0B2D0(w->f83D0, 0x1E, 0, 1.0f, 0.5f);
    p = &w->w8330;
    p[1] = 0x64;
    p[0] = 0;
    p[2] = 0;
    p[3] = 0;
    func_01B0AEE8(p, 0x96);
    func_00118098(0, 0x10000);
    func_00118098(1, 0x8000);
}
