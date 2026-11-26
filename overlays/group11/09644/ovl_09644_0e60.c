#include "common.h"

extern void func_01B00FC8(int);
extern void func_01B03B80(void);
extern void func_01B03BE0(void);
extern void func_01B03C30(int);

void ovl_09644_0e60(int a0)
{
    func_01B03BE0();
    func_01B03C30(0);
    func_01B03B80();
    func_01B00FC8(a0);
    __asm__("" : : : "memory");
}
