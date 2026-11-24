#include "common.h"

extern s32 D_01B00CE0[];
extern float D_01B00CF0[];
extern u8 D_01B0DEB0[];

extern void func_01B09F18(void *, void *, s32, s32, s32, void *, float);

void func_01B04CB0(void *arg0, s32 arg1) {
    func_01B09F18(D_01B0DEB0, arg0, D_01B00CE0[arg1], 0, 0, 0, D_01B00CF0[arg1]);
}
