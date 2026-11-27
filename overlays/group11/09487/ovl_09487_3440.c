#include "common.h"

extern int D_01B00658;
extern int D_01B00768;
extern int D_01B0079C;
extern int D_01B033E8;
extern int D_01B033EC;
extern int D_01B033F0;
extern int D_01B033F4;

extern int D_00303550;

extern void func_00107BE8(int, int);
extern void func_002A7120(int, int, int);
extern void func_002A7308(int, int, int, int);
extern int func_002DA610(int, int);

void func_01B03410(void)
{
    func_00107BE8(D_01B00658, 1);
    func_002A7120(D_01B00658, 2, 1);
    if (D_01B00768 == 0) {
        D_01B00768 = D_01B0079C;
    }
    func_002DA610(0, 0);
    func_002A7308(D_01B00768, D_01B00658, 2, D_00303550);
    D_01B033EC = D_01B033E8 = 0;
    D_01B033F4 = D_01B033F0 = 0x1CCC8;
}
