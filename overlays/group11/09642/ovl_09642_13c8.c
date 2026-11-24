#include "common.h"

extern u8 D_01B090E8[];
extern u8 D_01B09108[];

extern void func_00103208(int);
extern void func_00110718(int, int);
extern void func_00117E58(int);
extern void func_00118098(int, int);
extern int func_01B01F20(int);
extern int func_01B01F58(int, int);
extern void func_01B02D18(int, int);
extern void func_01B02DA0(int, int);
extern void func_01B02F98(int);
extern void func_01B031C8(int, int);
extern void func_01B03348(int, int);
extern void func_01B03720(int);
extern void func_01B03E18(void *, int);
extern void func_01B06570(void);

void func_01B013C8(void)
{
    int p;

    func_00103208(func_01B01F20(1));
    func_01B03720(0x3013);
    func_01B03348(0, 0);
    func_01B03348(-1, 0);
    func_01B03E18(D_01B090E8, 0);
    func_01B03E18(D_01B09108, 0);
    func_01B02DA0(0, 1);
    func_01B02DA0(-1, 1);
    func_01B031C8(-1, 0);
    func_01B02D18(-1, 1);
    func_01B02F98(1);
    func_00118098(0, 0);
    func_00118098(1, 0);
    func_00117E58(0);
    p = func_01B01F58(0, 1);
    if (p != 0) {
        func_00110718(p, 0);
    }
    func_01B06570();
}

int func_01B014A0(void)
{
    func_01B013C8();
    return 0;
}
