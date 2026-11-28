#include "common.h"

typedef struct {
    u8 pad00[0x60];
    float f60;
    float f64;
    float f68;
    float f6C;
} Obj1D58;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern float D_01B00970;
extern void *D_01B009C4;
extern u8 D_01B009D8;
extern s32 D_01B00F58;
extern s32 D_01B00F60[];
extern s32 D_01B00F6C;
extern float D_01B011D0[];
extern s32 D_01B011EC;
extern s32 D_01B011F0;

extern void func_00294B70(void *, s32, s32);
extern void func_00117F58(s32, s32, s32, s32);
extern void func_002675B0(void *);
extern void func_002DCE38(void *, void *, void *);
extern s32 func_00267FA0(void *, s32);

s32 func_01B01D58(Obj1D58 *s1) {
    s32 i;
    float f;

    if (D_01B00F6C != 0) {
        return 0;
    }
    f = D_01B00970;
    s1->f60 = f;
    s1->f64 = f;
    s1->f68 = f;
    s1->f6C = 1.0f;
    for (i = 0; i < 3; i++) {
        if (i > D_01B00F58 - 1) {
            break;
        }
        if (D_01B00F60[i] != 0) {
            if (D_01B011D0[i] < 0.9f) {
                return 1;
            }
        }
    }
    if (D_01B011EC == 0) {
        func_00294B70(D_01B009C4, 0x40, 0x100);
    }
    D_01B011EC++;
    if (D_01B011EC >= 41) {
        D_01B011F0 -= 12;
        D_01B011F0 = D_01B011F0 < 0 ? 0 : (D_01B011F0 > 128 ? 128 : D_01B011F0);
        func_00117F58(96, 96, 96, D_01B011F0);
    }
    func_002675B0(s1);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    {
        register void *v0 __asm__("$2") = &D_01B009D8;
        D_006A3924 = v0;
    }
    return func_00267FA0(s1, 0x30) == 0;
}
