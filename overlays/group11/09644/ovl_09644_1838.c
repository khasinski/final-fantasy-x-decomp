#include "common.h"

extern void func_0010D380(void *, int, int);
extern void func_0010D3A8(void *, int, int);
extern void func_0010D4A0(void *, int);
extern void func_0010D4D8(void *, int);
extern void *func_01B01C48(int);

void ovl_09644_1838(void)
{
    void *s0 = func_01B01C48(2);

    func_0010D380(s0, -1, 0x3540);
    func_0010D3A8(s0, -1, 0x3BD0);
    func_0010D4A0(s0, -1);
    func_0010D4D8(s0, -1);
}
