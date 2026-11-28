#include "common.h"

typedef struct {
    u8 pad00[0x10];
    void **p10;
} Res2B18;

typedef struct {
    u8 pad00[0x50];
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5C;
    float f60;
    float f64;
    float f68;
    float f6C;
} Obj2B18;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern float D_01B00950;
extern float D_01B00968;
extern float D_01B0096C;
extern void *D_01B009CC;
extern Res2B18 *D_01B009D0;
extern u8 D_01B009D8;
extern float D_01B00F70[4];

extern void func_00267658(void *, s32, void *, s32);
extern void func_00294B70(void *, s32, s32);
extern void func_002DD0B0(void *, void *);
extern void func_002DD128(void *);
extern void func_01B038B8(void *, float);
extern void func_002DD080(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern s32 func_00267FA0(void *, s32);

s32 func_01B02B18(Obj2B18 *s0) {
    float f;
    register Res2B18 *a2 __asm__("$6") = D_01B009D0;
    register void *v1 __asm__("$3") = &D_01B009D8;
    void **p10 = a2->p10;

    D_006A3924 = v1;
    func_00267658(s0, 0x1000, p10[0], 1);
    s0->w50 = 0;
    f = D_01B00968;
    s0->w54 = 0;
    s0->w58 = 0;
    s0->w5C = 1;
    s0->f60 = f;
    s0->f64 = f;
    s0->f68 = f;
    s0->f6C = 1.0f;
    func_00294B70(D_01B009CC, 0x40, 0x100);
    return 1;
}
