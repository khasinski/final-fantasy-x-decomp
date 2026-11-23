#include "common.h"

extern void func_00107428(s32, s32, s32, float *);
extern void func_00110718(s32, s32);
extern s32 func_01B03CD8(void);

void func_01B03E00(float *arg0) {
    func_00107428(func_01B03CD8(), 0, 0, arg0);
    arg0[3] = 1.0f;
}

void func_01B03E48(void) {
    func_00110718(func_01B03CD8(), 1);
}

void func_01B03E70(void) {
    func_00110718(func_01B03CD8(), 0);
}
