#include "common.h"

extern s32 D_01B00A60[];
extern float D_01B00A70[];
extern u8 D_01B0B2D0[];

extern void func_01B07360(void *, s32, s32, s32, float, s32, s32);

void func_01B02658(s32 arg0, s32 arg1) {
    func_01B07360(D_01B0B2D0, arg0, D_01B00A60[arg1], 0, D_01B00A70[arg1], 0, 0);
}
