#include "common.h"

typedef struct {
    u8 pad00[0x10];
    void **p10;
} Res1548;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5C;
    float f60;
    float f64;
    float f68;
    float f6C;
} Obj1548;

extern void *D_006A3924;
extern float D_01B007AC;
extern Res1548 *D_01B007FC;
extern u8 D_01B00800[];
extern void *D_01B00A3C;

extern void func_00267658(void *, s32, void *, s32);
extern void func_00108910(void *, s32, void *);

s32 func_01B01548(Obj1548 *s0) {
    float f;

    D_006A3924 = D_01B00800;
    func_00267658(s0, 0x1000, D_01B007FC->p10[1], 1);
    func_00108910(D_01B00A3C, 0x10, s0->pos);
    f = D_01B007AC;
    s0->w50 = 0;
    s0->w54 = 0;
    s0->w58 = 0;
    s0->w5C = 1;
    s0->f60 = f;
    s0->f64 = f;
    s0->f68 = f;
    s0->f6C = 1.0f;
    return 1;
}
