#include "common.h"

static inline void copy_vec(void *src, void *dst)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x30];
    float vec30[4];
    u8 pad40[0x106];
    u8 b146;
} ModelObj;

typedef struct {
    u8 pad00[0xBE0];
    float vecBE0[4];
    u8 padBF0[0x218];
    float fE08;
} OvlState;

extern u8 D_01B09558[];
extern u8 D_01B09660[];
extern OvlState *D_01B096A0;

extern void func_00103208(void *);
extern void func_00118098(int, int);
extern void func_001B57F0(int, int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);

extern int func_01B027C0(int);
extern void *func_01B02858(int);
extern void func_01B036D8(int, int);
extern void func_01B03818(int);
extern void func_01B038D0(int);
extern void func_01B03C80(int, void *);
extern void func_01B04058(int);
extern void func_01B04750(void *, int);
extern void func_01B05800(void *);
extern void func_01B06D68(int);
extern void func_01B06EA8(void);
extern ModelObj *func_01B07098(int);

void func_01B01C50(void)
{
    OvlState *s = D_01B096A0;
    ModelObj *m;

    func_01B06D68(0);
    m = func_01B07098(0);
    m->b146 = 1;
    func_002DD128(m);
    func_002DD318(m, m, s->fE08);
    copy_vec(s->vecBE0, m->vec30);
}

void func_01B01CC0(void)
{
    func_00103208(func_01B02858(1));
    func_01B04058(0x3016);
    func_01B03C80(-1, 0);
    func_01B04750(D_01B09660, 0);
    func_01B03818(1);
    func_01B038D0(1);
    func_01B036D8(-1, 1);
    func_001B57F0(func_01B027C0(-1) + 1, 1);
    func_00118098(0, 0);
    func_00118098(1, 0);
    func_01B06EA8();
    func_01B05800(D_01B09558);
}
