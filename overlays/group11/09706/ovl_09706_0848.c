#include "common.h"
typedef struct { u8 pad00[0x10]; int *w10; } TtCfg;
typedef struct {
    u8 pad00[0x40];
    float f40, f44, f48, f4C;
    int w50, w54, w58, w5C;
    float f60, f64, f68, f6C;
} TtPart;
extern TtCfg *D_01B0042C;
extern u8 D_01B00430[];
extern void *D_006A3924;
extern void func_00267658(TtPart *, int, int, int);

int func_01B00848(TtPart *p) {
    { int *w10 = D_01B0042C->w10; D_006A3924 = D_01B00430; func_00267658(p, 0x1000, w10[0], 1); }
    p->f40 = -16.0f;
    p->f44 = -13.0f;
    p->f48 = 259.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.091646008f;
    p->f64 = 0.091646008f;
    p->f68 = 0.091646008f;
    p->f6C = 1.0f;
    return 1;
}
