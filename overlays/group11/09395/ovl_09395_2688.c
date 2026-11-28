#include "common.h"

typedef struct {
    u8 raw[0x80];
} Slot2688;

extern void *D_006A3924;
extern void *D_01B00788;
extern u8 D_01B00910[];
extern float D_01B00950;
extern u8 D_01B009D8[];
extern Slot2688 D_01B00B10[];
extern s32 D_01B00F58;
extern s32 D_01B00F60[];
extern float D_01B00F70[4];
extern float D_01B00F80[4];
extern float D_01B00F90[4];
extern s32 D_01B01004;
extern float D_01B01010[4];
extern void *D_01B011F4;
extern u8 D_01B01308[];

extern void func_00267530(void *);
extern void *func_00102B98(s32);
extern void func_00105050(s32, s32);
extern void func_00110550(void *, s32);
extern void func_00110558(void *, s32);
extern void func_00110810(void *, s32);
extern void *func_001B4E58(s32);
extern void func_01B05788(void *, void *, void *);
extern void func_002DD0B0(void *, void *);

s32 func_01B02688(Slot2688 *a0) {
    s32 idx = a0 - D_01B00B10;

    if (idx > D_01B00F58 - 1) {
        return 1;
    }
    if (D_01B00F60[idx] == 0) {
        return 1;
    }
    D_006A3924 = D_01B009D8;
    func_00267530(a0);
    return 1;
}

s32 func_01B026F0(void) {
    float f;

    D_01B01004 = 0;
    if (D_01B00788 == 0) {
        D_01B00788 = func_00102B98(0x3015);
        func_00105050(0x3015, 1);
        func_00110550(D_01B00788, 1);
        func_00110558(D_01B00788, 1);
        func_00110810(D_01B00788, 0);
    }
    f = D_01B00950;
    D_01B00F90[0] = f;
    D_01B00F90[1] = f;
    D_01B00F90[2] = f;
    D_01B00F90[3] = 1.0f;
    D_01B00F80[0] = 0.0f;
    D_01B00F80[1] = 0.0f;
    D_01B00F80[2] = 0.0f;
    D_01B00F80[3] = 0.0f;
    D_01B011F4 = func_001B4E58(20);
    func_01B05788(D_01B01308, D_01B00910, D_01B00788);
    func_002DD0B0(D_01B01010, D_01B00F70);
    D_01B01010[1] -= 10.0f;
    D_01B01010[2] -= 10.0f;
    return 1;
}
