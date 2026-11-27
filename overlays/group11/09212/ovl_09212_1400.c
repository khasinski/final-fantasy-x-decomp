#include "common.h"

extern int D_01B0A798;
extern int D_01B0A79C;
extern u8 D_01B0FE70[];
extern u8 D_01BEC690[];

extern void func_01B037D8(void);
extern void func_01B05940(void);
extern void func_01B06028(void);
extern void func_01B06AA8(void);
extern void func_002B22F8(int a0, int a1);
extern void op_oef2_set2(void *a0);
extern void func_01B05210(void *a0, int a1, int a2);
extern void func_01B05AD8(void *a0, int a1, int a2);
extern void func_01B05AE8(void *a0, int a1, int a2);

int func_01B01400(int a0)
{
    D_01B0A798 = a0;
    func_01B037D8();
    func_01B05940();
    func_01B06028();
    func_01B06AA8();
    func_002B22F8(0x3400, 0x800);
    op_oef2_set2(D_01B0FE70);
    func_01B05210(D_01B0FE70, 0, 4);
    func_01B05AD8(D_01B0FE70, 0, 1000);
    op_oef2_set2(D_01BEC690);
    func_01B05AE8(D_01BEC690, 0, 0);
    func_01B05AE8(D_01BEC690, 1, 1);
    D_01B0A79C = 0;
    return 0;
}
