#include "iopsound.h"

extern void func_00EFBC(s32, s32);

extern volatile s32 D_05A148;
extern volatile s32 D_05A14C;

s32 func_00F038(s32 bit) {
    D_05A148 |= 1 << bit;
    func_00EFBC(0, D_05A148);
    return D_05A148;
}

s32 func_00F084(s32 bit) {
    D_05A148 &= ~(1 << bit);
    func_00EFBC(0, D_05A148);
    return D_05A148;
}

s32 func_00F0D4(s32 bit) {
    D_05A14C |= 1 << bit;
    func_00EFBC(1, D_05A14C);
    return D_05A14C;
}

s32 func_00F120(s32 bit) {
    D_05A14C &= ~(1 << bit);
    func_00EFBC(1, D_05A14C);
    return D_05A14C;
}

s32 func_00F170(s32 bit) {
    return D_05A14C & (1 << bit);
}
