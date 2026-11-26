#include "common.h"

extern int D_01B08940;
extern int D_01B08944;
extern u8 D_01B0E1E0[];
extern u8 D_01BDC740[];

extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void func_01B00FD0(void);
extern void func_01B01A40(void);
extern void func_01B03478(void *, int, int);
extern void func_01B03BA8(void);
extern void func_01B03D40(void *, int, int);
extern void func_01B03D50(void *, int, int);
extern void func_01B04290(void);
extern void func_01B04D10(void);

int ovl_09644_0da0(int a0)
{
    D_01B08940 = a0;
    func_01B01A40();
    func_01B03BA8();
    func_01B04290();
    func_01B04D10();
    func_002B22F8(0x3400, 0x800);
    func_01B00FD0();
    func_002B4980(D_01B0E1E0);
    func_01B03478(D_01B0E1E0, 0, 0x12);
    func_01B03D40(D_01B0E1E0, 0, 1000);
    func_002B4980(D_01BDC740);
    func_01B03D40(D_01BDC740, 0, 1000);
    func_002B4980(D_01BDC740);
    func_01B03D50(D_01BDC740, 1, 0);
    D_01B08944 = 0;
    return 0;
}
