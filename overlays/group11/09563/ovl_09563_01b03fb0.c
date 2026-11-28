#include "common.h"

extern void func_01B03C20(int, int, int);
extern void func_01B03D10(int, int, int);
extern void func_01B03EE0(float, float, int);
extern void func_01B03C90(int, int, int, int);
extern void func_01B03D80(int, int, int, int);
extern void func_01B03E68(void *, int, int, int);
extern void func_01B03F48(float, float, int);

void func_01B03FB0(u8 *s0)
{
    if (*(int *)(s0 + 0x10) == 0) {
        func_01B03C20(*(int *)(s0 + 0x0), *(int *)(s0 + 0x4), *(int *)(s0 + 0x28));
        func_01B03D10(*(int *)(s0 + 0x8), *(int *)(s0 + 0xC), *(int *)(s0 + 0x28));
        func_01B03EE0(*(float *)(s0 + 0x14), *(float *)(s0 + 0x18), *(int *)(s0 + 0x28));
    } else {
        func_01B03C90(*(int *)(s0 + 0x0), *(int *)(s0 + 0x10), *(int *)(s0 + 0x4), *(int *)(s0 + 0x28));
        func_01B03D80(*(int *)(s0 + 0x8), *(int *)(s0 + 0x10), *(int *)(s0 + 0xC), *(int *)(s0 + 0x28));
        func_01B03E68(s0 + 0x14, *(int *)(s0 + 0x10), 2, *(int *)(s0 + 0x28));
    }
    func_01B03F48(*(float *)(s0 + 0x1C), *(float *)(s0 + 0x20), *(int *)(s0 + 0x28));
}
