#include "common.h"

extern int D_01B0A348;
extern int D_01B0A34C;
extern u8 D_01B0FB90[];
extern u8 D_01BEC6E0[];

extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void func_01B03520(void);
extern void func_01B04F58(void *, int, int);
extern void func_01B05688(void);
extern void func_01B05820(void *, int, int);
extern void func_01B05830(void *, int, int);
extern void func_01B05D70(void);
extern void func_01B067F0(void);

int func_01B00C70(int a0)
{
    D_01B0A348 = a0;
    func_01B03520();
    func_01B05688();
    func_01B05D70();
    func_01B067F0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B0FB90);
    func_01B04F58(D_01B0FB90, 0, 1000);
    func_01B05820(D_01B0FB90, 0, 1000);
    func_002B4980(D_01BEC6E0);
    func_01B05820(D_01BEC6E0, 0, 1000);
    func_002B4980(D_01BEC6E0);
    func_01B05830(D_01BEC6E0, 1, 0);
    D_01B0A34C = 0;
    return 0;
}
