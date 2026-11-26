#include "common.h"

extern int D_01B0A3B8;
extern int D_01B0A3BC;
extern u8 D_01B0FC10[];
extern u8 D_01C00070[];

extern void func_002B22F8(int, int);
extern void func_002B4980(void *);
extern void func_01B02FD0(void);
extern void func_01B04A08(void *, int, int);
extern void func_01B05138(void);
extern void func_01B052D0(void *, int, int);
extern void func_01B052E0(void *, int, int);
extern void func_01B05820(void);
extern void func_01B062A0(void);

int func_01B01970(int a0)
{
    D_01B0A3B8 = a0;
    func_01B02FD0();
    func_01B05138();
    func_01B05820();
    func_01B062A0();
    func_002B22F8(0x3400, 0x800);
    func_002B4980(D_01B0FC10);
    func_01B04A08(D_01B0FC10, 0, 1000);
    func_01B052D0(D_01B0FC10, 0, 1000);
    func_002B4980(D_01C00070);
    func_01B052D0(D_01C00070, 0, 1000);
    func_002B4980(D_01C00070);
    func_01B052E0(D_01C00070, 0, 1);
    D_01B0A3BC = 0;
    return 0;
}
