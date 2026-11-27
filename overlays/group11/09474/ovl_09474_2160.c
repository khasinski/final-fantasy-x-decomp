#include "common.h"

extern u8 D_01B0A400[];
extern u8 D_01B0A420[];
extern u8 D_01B0A2F8[];

void *func_01B035F8(int a0);
void func_00103208(void *a0);
void func_01B04DF8(int a0);
void func_01B04A20(int a0, int a1);
void func_01B054F0(void *a0, int a1);
void func_01B04478(int a0, int a1);
void func_01B04670(int a0);
void func_00118098(int a0, int a1);
void func_01B07C48(void);
void func_01B065A0(void *a0);
void func_0029A890(void);

void func_01B02160(void)
{
    func_00103208(func_01B035F8(2));
    func_01B04DF8(0x3016);
    func_01B04A20(0, 0);
    func_01B04A20(-1, 0);
    func_01B04A20(1, 0);
    func_01B054F0(D_01B0A400, 0);
    func_01B054F0(D_01B0A420, 0);
    func_01B04478(0, 1);
    func_01B04670(1);
    func_01B04478(-1, 1);
    func_00118098(0, 0);
    func_00118098(1, 0);
    func_01B07C48();
    func_01B065A0(D_01B0A2F8);
    func_0029A890();
}
