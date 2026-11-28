#include "common.h"

extern int D_01B0BF40;
extern int D_01B0BF44;
extern u8 D_01B11810[];
extern u8 D_01BCD340[];

extern void func_01B049E8(void);
extern void func_01B06B50(void);
extern void func_01B07238(void);
extern void func_01B07CB8(void);
extern void func_002B22F8(int, int);
extern void op_oef2_set2(void *);
extern void func_01B06420(void *, int, int);
extern void func_01B06CE8(void *, int, int);
extern void func_01B06CF8(void *, int, int);

int func_01B00E50(int a0)
{
    D_01B0BF40 = a0;
    func_01B049E8();
    func_01B06B50();
    func_01B07238();
    func_01B07CB8();
    func_002B22F8(0x3400, 0x800);
    op_oef2_set2(D_01B11810);
    func_01B06420(D_01B11810, 0, 1000);
    func_01B06CE8(D_01B11810, 0, 1000);
    op_oef2_set2(D_01BCD340);
    func_01B06CE8(D_01BCD340, 0, 1000);
    op_oef2_set2(D_01BCD340);
    func_01B06CF8(D_01BCD340, 3, 0);
    D_01B0BF44 = 0;
    return 0;
}
