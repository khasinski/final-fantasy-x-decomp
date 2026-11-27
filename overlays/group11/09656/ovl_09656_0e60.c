#include "common.h"

extern int D_01B0A858;
extern int D_01B0A85C;
extern u8 D_01B100E0[];
extern u8 D_01BABFD0[];

extern void func_01B03408(void);
extern void func_01B05570(void);
extern void func_01B05C58(void);
extern void func_01B066D8(void);
extern void func_002B22F8(int a0, int a1);
extern void op_oef2_set2(void *a0);
extern void func_01B04E40(void *a0, int a1, int a2);
extern void func_01B05708(void *a0, int a1, int a2);

int func_01B00E60(int a0)
{
    D_01B0A858 = a0;
    func_01B03408();
    func_01B05570();
    func_01B05C58();
    func_01B066D8();
    func_002B22F8(0x3400, 0x800);
    op_oef2_set2(D_01B100E0);
    func_01B04E40(D_01B100E0, 0, 1000);
    func_01B05708(D_01B100E0, 0, 1000);
    op_oef2_set2(D_01BABFD0);
    func_01B05708(D_01BABFD0, 0, 1000);
    D_01B0A85C = 0;
    return 0;
}
