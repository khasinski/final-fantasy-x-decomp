#include "common.h"

extern int D_01B00788;
extern int D_01B00978;
extern int D_01B009AC;
extern int D_01B01318;
extern int D_01B0131C;
extern int D_01B01320;
extern int D_01B01324;

extern int D_00303550;

extern void func_00107BE8(int, int);
extern void func_002A7120(int, int, int);
extern void func_002A7308(int, int, int, int);
extern int func_002DA610(int, int);

void func_01B01358(void)
{
    func_00107BE8(D_01B00788, 1);
    func_002A7120(D_01B00788, 2, 1);
    if (D_01B00978 == 0) {
        D_01B00978 = D_01B009AC;
    }
    func_002DA610(0, 0);
    func_002A7308(D_01B00978, D_01B00788, 2, D_00303550);
    D_01B0131C = D_01B01318 = 0;
    D_01B01324 = D_01B01320 = 0x1CCC8;
}
