#include "common.h"

extern s32 D_01B00958[];
extern float D_01B00968[];
extern u8 D_01B0B2D0[];

extern void func_01B07360(void *, void *, s32, s32, s32, void *, float);

void func_01B02170(void *arg0, s32 arg1) {
    func_01B07360(D_01B0B2D0, arg0, D_01B00958[arg1], 0, 0, 0, D_01B00968[arg1]);
}
